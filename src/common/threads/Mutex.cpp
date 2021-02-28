/*
** EPITECH PROJECT, 2020
** bootstrap_plazza
** File description:
** IMutex
*/

#include "Mutex.hpp"

/** @file
 * @brief Defines threads methods for the project.
 *
 * Sets threads methods.
 */

void Babel::Threads::Mutex::lock()
{
    this->_mutex.lock();
}

void Babel::Threads::Mutex::unlock()
{
    this->_mutex.unlock();
}

void Babel::Threads::Mutex::trylock()
{
    if (!this->_mutex.try_lock()) {
        std::cerr << "The mutex is busy" << std::endl;
    }
}

std::mutex &Babel::Threads::Mutex::getMutex() {
    return this->_mutex;
}