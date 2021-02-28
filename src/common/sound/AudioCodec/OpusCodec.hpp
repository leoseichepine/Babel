/*
** EPITECH PROJECT, 2020
** B-CPP-500-STG-5-1-babel-leo.seichepine
** File description:
** OpusCodec
*/

#ifndef OPUSCODEC_HPP_
#define OPUSCODEC_HPP_

#include "IAudioCodec.hpp"
#include <exception>
#include <opus/opus.h>
#include <iostream>

/** @file
 * @brief Defines the class of the Opus codec.
 *
 * Defines its properties and methods.
 */

/**
 * @brief Class of the Opus codec.
 *
 * Compliant with IAudioCodec.
 */
class OpusCodec : public IAudioCodec{
    public:
        /**
         * @brief Constructor of OpusCodec.
         *
         * @param sampleRate The sample rate.
         * @param channelNb The channel number.
         */
        OpusCodec(int sampleRate, int channelNb);

        /**
         * @brief Default destructor of OpusCodec.
         */
        ~OpusCodec();

        /**
         * @brief Public function overridden from IAudioCodec to encode an Opus frame.
         *
         * @param in Input of the signal.
         * @param frame_size Number of samples per frame of input signal.
         * @param out Output payload.
         * @param max_bytes Allocated memory for payload; don't use for controlling bitrate.
         */
        void encode(int *in, int frame_size, unsigned char *out, int max_bytes) override;

        /**
         * @brief Public function overridden from IAudioCodec to encode an Opus frame from floating point input.
         *
         * @param in Input of the signal.
         * @param frame_size Number of samples per frame of input signal.
         * @param out Output payload.
         * @param max_bytes Allocated memory for payload; don't use for controlling bitrate.
         */
        void encode(float *in, int frame_size, unsigned char *out, int max_bytes) override;

        /**
         * @brief Public function overridden from IAudioCodec to decode an opus frame.
         *
         * @param in Input payload. Use a NULL pointer to indicate packet loss.
         * @param len Number of bytes in payload
         * @param out Output signal (interleaved if 2 channels). length is frame_size*channels*sizeof(float).
         * @param frame_size Number of samples per channel of available space in *pcm.
         */
        void decode(const unsigned char *in, int len, int *out, int frame_size) override;

        /**
         * @brief Public function overridden from IAudioCodec to decode an opus frame with floating point output.
         *
         * @param in Input payload. Use a NULL pointer to indicate packet loss.
         * @param len Number of bytes in payload
         * @param out Output signal (interleaved if 2 channels). length is frame_size*channels*sizeof(float).
         * @param frame_size Number of samples per channel of available space in *pcm.
         */
        void decode(const unsigned char *in, int len, float *out, int frame_size) override;
    protected:
    private:
        /**
         * @brief Opus encoder.
         *
         * Private property.
         */
        OpusEncoder *_encoder;

        /**
         * @brief Opus decoder.
         *
         * Private property.
         */
        OpusDecoder *_decoder;
};

#endif /* !OPUSCODEC_HPP_ */