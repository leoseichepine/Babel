/*
** EPITECH PROJECT, 2020
** B-CPP-500-STG-5-1-babel-leo.seichepine
** File description:
** IAudioCodec
*/

#ifndef IAUDIOCODEC_HPP_
#define IAUDIOCODEC_HPP_

/** @file
 * @brief Defines the interface for Opus.
 *
 * Defines its properties and methods.
 */

/**
 * @brief Interface of the audio codec.
 *
 * Interface for Opus.
 */
class IAudioCodec {
    public:
        /**
         * @brief Virtual destructor.
         */
        virtual ~IAudioCodec() {};

        /**
         * @brief Pure virtual function to encode an Opus frame.
         *
         * @param in Input of the signal.
         * @param frame_size Number of samples per frame of input signal.
         * @param out Output payload.
         * @param max_bytes Allocated memory for payload; don't use for controlling bitrate.
         */
        virtual void encode(int *in, int frame_size, unsigned char *out, int max_bytes) = 0;

        /**
         * @brief Pure virtual function to encode an Opus frame from floating point input.
         *
         * @param in Input of the signal.
         * @param frame_size Number of samples per frame of input signal.
         * @param out Output payload.
         * @param max_bytes Allocated memory for payload; don't use for controlling bitrate.
         */
        virtual void encode(float *in, int frame_size, unsigned char *out, int max_bytes) = 0;

        /**
         * @brief Pure virtual function to decode an opus frame.
         *
         * @param in Input payload. Use a NULL pointer to indicate packet loss.
         * @param len Number of bytes in payload.
         * @param out Output signal (interleaved if 2 channels). length is frame_size*channels*sizeof(float).
         * @param frame_size Number of samples per channel of available space in *pcm.
         */
        virtual void decode(const unsigned char *in, int len, int *out, int frame_size) = 0;

        /**
         * @brief Pure virtual function to decode an opus frame with floating point output.
         *
         * @param in Input payload. Use a NULL pointer to indicate packet loss.
         * @param len Number of bytes in payload.
         * @param out Output signal (interleaved if 2 channels). length is frame_size*channels*sizeof(float).
         * @param frame_size Number of samples per channel of available space in *pcm.
         */
        virtual void decode(const unsigned char *in, int len, float *out, int frame_size) = 0;
    protected:
    private:
};

#endif /* !IAUDIOCODEC_HPP_ */