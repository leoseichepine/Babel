/*
** EPITECH PROJECT, 2020
** bootstrap_plazza
** File description:
** ScopedLock
*/

#include "ScopedLock.hpp"

/** @file
 * @brief Defines the Scoped Lock.
 *
 * Sets the Scoped Lock methods.
 */

Babel::Threads::ScopedLock::ScopedLock(IMutex *mutex)
{
    _mutex = mutex;
    _mutex->lock();
}

Babel::Threads::ScopedLock::~ScopedLock()
{
    _mutex->unlock();
}