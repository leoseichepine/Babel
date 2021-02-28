/*
** EPITECH PROJECT, 2020
** bootstrap_plazza
** File description:
** ScopedLock
*/

#ifndef SCOPEDLOCK_HPP_
#define SCOPEDLOCK_HPP_

#include "Mutex.hpp"

/** @file
 * @brief Defines the class of the scoped lock.
 *
 * Defines its properties and methods.
 */

/**
 * @brief The project namespace.
 */
namespace Babel {
    /**
     * @brief The Threads namespace.
     */
    namespace Threads {
        /**
         * @brief Class of the scoped lock.
         *
         * Takes care to check the execution of the threads.
         */
        class ScopedLock {
        public:
            /**
             * @brief The constructor of ScopedLock.
             *
             * @param mutex The mutex thread.
             */
            ScopedLock(IMutex *mutex);

            /**
             * @brief The destructor of ScopedLock.
             */
            ~ScopedLock();

        protected:
        private:
            /**
             * @brief Holds the mutex.
             *
             * Private property.
             */
            IMutex *_mutex;
        };
    };
};

#endif /* !SCOPEDLOCK_HPP_ */