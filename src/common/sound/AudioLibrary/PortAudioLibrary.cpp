/*
** EPITECH PROJECT, 2020
** B-CPP-500-STG-5-1-babel-leo.seichepine
** File description:
** PortAudioLibrary
*/

#include "PortAudioLibrary.hpp"

/** @file
 * @brief Defines the Port Audio Library.
 *
 * Sets the Port Audio methods.
 */

PortAudioLibrary::PortAudioLibrary() : _recRunning(false), _playRunning(false)
{
    Pa_Initialize();
    linkDefaultDivice();
}

PortAudioLibrary::~PortAudioLibrary()
{
    stopRecord();
    stopPlay();
    Pa_Terminate();
}

int PortAudioLibrary::recordCallback( const void *inputBuffer, void *outputBuffer,
unsigned long framesPerBuffer, const PaStreamCallbackTimeInfo* timeInfo,
PaStreamCallbackFlags statusFlags, void *userData)
{
    PortAudioLibrary * obj  = reinterpret_cast<PortAudioLibrary *>(userData);
    {
        Babel::Threads::ScopedLock sl(&obj->_recMutex);
        Decoded sound;
        sound.size = framesPerBuffer * NB_CHANNELS;
        sound.buffer.assign(reinterpret_cast<const float *>(inputBuffer), reinterpret_cast<const float *>(inputBuffer) + framesPerBuffer * NB_CHANNELS);
        obj->_recBuf.push_back(sound);
    }
    return paContinue;

}

int PortAudioLibrary::playCallback( const void *inputBuffer, void *outputBuffer,
unsigned long framesPerBuffer, const PaStreamCallbackTimeInfo* timeInfo,
PaStreamCallbackFlags statusFlags, void *userData)
{
    PortAudioLibrary * obj  = reinterpret_cast<PortAudioLibrary *>(userData);
    Babel::Threads::ScopedLock sl(&obj->_playMutex);

    if (obj->_playBuf.size() == 0)
        return paContinue;
    
    Decoded sound = obj->_playBuf.front();
    float *ptr = static_cast<float *> (outputBuffer);

    for (int i = 0; i < sound.size; ++i)
        *ptr++ = sound.buffer[i];
    obj->_playBuf.pop_front();
    return paContinue;
}

void PortAudioLibrary::linkDefaultDivice()
{
    _input.device = Pa_GetDefaultInputDevice();
    _input.channelCount = NB_CHANNELS;
	_input.sampleFormat = paFloat32;
	_input.suggestedLatency = Pa_GetDeviceInfo(_input.device)->defaultLowInputLatency;
	_input.hostApiSpecificStreamInfo = NULL;

    _output.device = Pa_GetDefaultOutputDevice();
	_output.channelCount = NB_CHANNELS;
	_output.sampleFormat = paFloat32;
	_output.suggestedLatency = Pa_GetDeviceInfo(_output.device)->defaultLowOutputLatency;
	_output.hostApiSpecificStreamInfo = NULL;
}


void PortAudioLibrary::startRecord(void) {
    if (!_recRunning) {
        Pa_OpenStream(&_recordStream, &_input, NULL, SAMPLE_RATE, FRAMES_PER_BUFFER, paClipOff, PortAudioLibrary::recordCallback, this);
        Pa_StartStream(_recordStream);
        _recRunning = true;
    }

}
void PortAudioLibrary::stopRecord(void) {
    if (_recRunning) {
        Pa_CloseStream(_recordStream);
        _recRunning = false;
    }
}

void PortAudioLibrary::startPlay(void) {
    if (!_playRunning) {
        Pa_OpenStream(&_playStream, NULL, &_output, SAMPLE_RATE, FRAMES_PER_BUFFER, paClipOff, PortAudioLibrary::playCallback, this);
        Pa_StartStream(_playStream);
        _playRunning = true;
    }

}
void PortAudioLibrary::stopPlay(void) {
    if (_playRunning) {
        Pa_CloseStream(_playStream);
        _playRunning = false;
    }
}

std::list<Decoded> PortAudioLibrary::getRecBuffer(void) const {
    return _recBuf;
}
void PortAudioLibrary::setPlayBuffer(const std::list<Decoded> buff) {
    _playBuf = buff;
}