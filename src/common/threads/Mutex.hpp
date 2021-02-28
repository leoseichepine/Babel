/*
** EPITECH PROJECT, 2020
** bootstrap_plazza
** File description:
** IMutex
*/

#ifndef IMUTEX_HPP_
#define IMUTEX_HPP_

#include <iostream>
#include <mutex>

/** @file
 * @brief Defines Mutex thread interface and class.
 *
 * Defines its properties and methods.
 */

/**
 * @brief Interface of the mutex thread.
 */
class IMutex {
    public:
        /**
         * @brief Virtual constructor of IMutex.
         */
        virtual ~IMutex() = default;

        /**
         * @brief Pure virtual function to lock a thread.
         */
        virtual void lock() = 0;

        /**
         * @brief Pure virtual function to unlock a thread.
         */
        virtual void unlock() = 0;

        /**
         * @brief Pure virtual function to try to lock a thread.
         */
        virtual void trylock() = 0;
};

/**
 * @brief The project namespace.
 */
namespace Babel {
    /**
     * @brief The Threads namespace.
     */
    namespace Threads {
        /**
         * @brief Class of the mutex thread.
         */
        class Mutex : public IMutex {
            public:
                /**
                 * @brief Public function overridden from IMutex to lock a thread.
                 */
                void lock() override;

                /**
                 * @brief Public function overridden from IMutex to unlock a thread.
                 */
                void unlock() override;

                /**
                 * @brief Public function overridden from IMutex to try to lock a thread.
                 */
                void trylock() override;

                /**
                 * @brief Public function to get the mutex.
                 *
                 * Getter method.
                 *
                 * @return the mutex.
                 */
                std::mutex &getMutex();
            private:
                /**
                 * @brief Holds the mutex.
                 *
                 * Private property.
                 */
                std::mutex _mutex;
        };
    };
};

#endif /* !IMUTEX_HPP_ */