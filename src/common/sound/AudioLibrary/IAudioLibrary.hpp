/*
** EPITECH PROJECT, 2020
** B-CPP-500-STG-5-1-babel-leo.seichepine
** File description:
** IAudioLibrary
*/

#ifndef IAUDIOLIBRARY_HPP_
#define IAUDIOLIBRARY_HPP_

/** @file
 * @brief Defines the interface for Port Audio.
 *
 * Defines its properties and methods.
 */

/**
 * @brief Interface of the audio library.
 *
 * Interface for Port Audio.
 */
class IAudioLibrary {
    public:
        /**
         * @brief Virtual destructor.
         */
        virtual ~IAudioLibrary() {};

        //To fill

    protected:
    private:
};

/**
 * @brief Interface of the audio stream.
 *
 * Interface for Port Audio.
 */
class IAudioStream
{
    public:
        /**
         * @brief Pure virtual constructor of IAudioStream.
         */
        virtual ~IAudioStream() = 0;

        /**
         * @brief Pure virtual function to open the audio stream.
         */
        virtual void open(void) = 0;

        /**
         * @brief Pure virtual function to start the audio stream.
         */
        virtual void start(void) = 0;

        /**
         * @brief Pure virtual function to close the audio stream.
         */
        virtual void close(void) = 0;

        /**
         * @brief Pure virtual function check if the audio stream is active.
         * @return the status of the audio stream's activity.
         */
        virtual bool isActive(void) = 0;
    private:
};

#endif /* !IAUDIOLIBRARY_HPP_ */