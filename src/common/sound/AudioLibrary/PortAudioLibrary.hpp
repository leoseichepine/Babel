/*
** EPITECH PROJECT, 2020
** B-CPP-500-STG-5-1-babel-leo.seichepine
** File description:
** PortAudioLibrary
*/

#ifndef PORTAUDIOLIBRARY_HPP_
#define PORTAUDIOLIBRARY_HPP_

#include "IAudioLibrary.hpp"
#include "portaudio.h"
#include <vector>
#include <list>
#include <iostream>
#include "../../threads/Mutex.hpp"
#include "../../threads/ScopedLock.hpp"

/** @file
 * @brief Defines the class of the Port Audio Library.
 *
 * Defines its properties and methods.
 */

/**
 * @brief Sample rate constant.
 */
#define SAMPLE_RATE 48000

/**
 * @brief Number of channel constant.
 */
#define NB_CHANNELS 2

/**
 * @brief Frames per buffer constant.
 */
#define FRAMES_PER_BUFFER 480

/**
 * @brief Struct which holds the audio port encoder requirements.
 */
struct Encoded {
    std::vector<unsigned char> buffer;
    int	size;
};

/**
 * @brief Struct which holds the audio port decoder requirements.
 */
struct Decoded {
    std::vector<float> buffer;
    int	size;
};

/**
 * @brief Class of the Port Audio Library.
 *
 * Compliant with IAudioLibrary.
 */
class PortAudioLibrary : public IAudioLibrary{
    public:
        /**
         * @brief Constructor of PortAudioLibrary.
         */
        PortAudioLibrary();

        /**
         * @brief Destructor of PortAudioLibrary.
         */
        ~PortAudioLibrary();

        /**
         * @brief Public function to get the record callback.
         *
         * This routine will be called by the PortAudio engine when audio is available.
         * It may be called at interrupt level on some machines so
         * don't do anything that could mess up the system like calling malloc() or free().
         *
         * @param inputBuffer Pointer of the buffer input.
         * @param outputBuffer Pointer of the buffer output.
         * @param framesPerBuffer The number of frames per buffer.
         * @param timeInfo Timing information for the buffers passed to the stream callback.
         * @param statusFlags Flag bit constants for the statusFlags to PaStreamCallback.
         * @param userData Pointer of the data structure.
         * @return the status of the callback.
         */
        static int recordCallback( const void *inputBuffer, void *outputBuffer,
                           unsigned long framesPerBuffer,
                           const PaStreamCallbackTimeInfo* timeInfo,
                           PaStreamCallbackFlags statusFlags,
                           void *userData);

        /**
         *
         * @brief Public function to get the listening callback.
         *
         * This routine will be called by the PortAudio engine when audio is needed.
         * It may be called at interrupt level on some machines so don't do anything
         * that could mess up the system like calling malloc() or free().
         *
         * @param inputBuffer Pointer of the buffer input.
         * @param outputBuffer Pointer of the buffer output.
         * @param framesPerBuffer The number of frames per buffer.
         * @param timeInfo Timing information for the buffers passed to the stream callback.
         * @param statusFlags Flag bit constants for the statusFlags to PaStreamCallback.
         * @param userData Pointer of the data structure.
         * @return the status of the callback.
         */
        static int playCallback( const void *inputBuffer, void *outputBuffer,
                           unsigned long framesPerBuffer,
                           const PaStreamCallbackTimeInfo* timeInfo,
                           PaStreamCallbackFlags statusFlags,
                           void *userData);

        /**
         * @brief Public function to start the record.
         */
        void startRecord(void);

        /**
         * @brief Public function to stop the record.
         */
        void stopRecord(void);

        /**
         * @brief Public function to start listening.
         */
        void startPlay(void);

        /**
         * @brief Public function to stop listening.
         */
        void stopPlay(void);

        /**
         * @brief Public function to get the record buffer.
         *
         * Getter method.
         *
         * @return a list of decoder.
         */
        std::list<Decoded> getRecBuffer(void) const;

        /**
         * @brief Public function to set the listening buffer.
         *
         * @param buff The list of decoder.
         */
        void setPlayBuffer(const std::list<Decoded> buff);

        /**
         * @brief Public function to listen again the buffer.
         */
        void playBack(void) {_playBuf = _recBuf;}

        /**
         * @brief Public function to link the default device.
         */
        void linkDefaultDivice();
    protected:
    private:
        /**
         * @brief Input of the stream.
         *
         * Private property.
         */
        PaStreamParameters _input;

        /**
         * @brief Provide multiple channels of real-time streaming audio input and output to a client application.
         *
         * Private property.
         */
        PaStream *_recordStream;

        /**
         * @brief Check if the recording is running.
         *
         * Private property.
         */
        bool _recRunning;

        /**
         * @brief The recording buffer.
         *
         * Private property.
         */
        std::list<Decoded> _recBuf;

        /**
         * @brief The recording mutex.
         *
         * Private property.
         */
        Babel::Threads::Mutex _recMutex;

        /**
         * @brief The output of the stream.
         *
         * Private property.
         */
        PaStreamParameters _output;

        /**
         * @brief The pointer of the stream being played.
         *
         * Private property.
         */
        PaStream *_playStream;

        /**
         * @brief Check if the listening is running.
         *
         * Private property.
         */
        bool _playRunning;

        /**
         * @brief The listening buffer.
         *
         * Private property.
         */
        std::list<Decoded> _playBuf;

        /**
         * @brief The listening mutex.
         *
         * Private property.
         */
        Babel::Threads::Mutex _playMutex;

};

#endif /* !PORTAUDIOLIBRARY_HPP_ */