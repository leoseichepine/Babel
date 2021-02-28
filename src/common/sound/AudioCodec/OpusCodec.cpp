/*
** EPITECH PROJECT, 2020
** B-CPP-500-STG-5-1-babel-leo.seichepine
** File description:
** OpusCodec
*/

#include "OpusCodec.hpp"

/** @file
 * @brief Defines the Opus codec.
 *
 * Sets the Opus codec methods.
 */

OpusCodec::OpusCodec(int sampleRate, int channelNb)
{
    int err = 0;

    _encoder = opus_encoder_create(sampleRate, channelNb, OPUS_APPLICATION_VOIP, &err);
    if (err != OPUS_OK)
        throw std::exception();
    err = 0;
    _decoder = opus_decoder_create(sampleRate, channelNb, &err);
    if (err != OPUS_OK) {
        opus_encoder_destroy(_encoder);
        throw std::exception();
    }
}

OpusCodec::~OpusCodec()
{
    opus_encoder_destroy(_encoder);
    opus_decoder_destroy(_decoder);
}

void OpusCodec::encode(int *in, int frame_size, unsigned char *out, int max_bytes)
{
    int err = 0;

    err = opus_encode(_encoder, (const opus_int16 *)in, frame_size, out, max_bytes);
    if (err < OPUS_OK) {
        std::cerr << opus_strerror(err) << std::endl;
        throw std::exception();
    }
}

void OpusCodec::encode(float *in, int frame_size, unsigned char *out, int max_bytes)
{
    int err = 0;

    err = opus_encode_float(_encoder, in, frame_size, out, max_bytes);
    if (err < OPUS_OK) {
        std::cerr << opus_strerror(err) << std::endl;
        throw std::exception();
    }
}

void OpusCodec::decode(const unsigned char *in, int len, int *out, int frame_size)
{
    int err = 0;

    err = opus_decode(_decoder, in, len, (opus_int16 *)out, frame_size, 0);
    if (err < 0) {
        std::cerr << opus_strerror(err) << std::endl;
        throw std::exception();
    }
}

void OpusCodec::decode(const unsigned char *in, int len, float *out, int frame_size)
{
    int err = 0;

    err = opus_decode_float(_decoder, in, len, out, frame_size, 0);
    if (err < 0) {
        std::cerr << opus_strerror(err) << std::endl;
        throw std::exception();
    }
}