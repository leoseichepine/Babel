/*
** EPITECH PROJECT, 2020
** B-CPP-500-STG-5-1-babel-leo.seichepine
** File description:
** BabelException
*/

#ifndef BABELEXCEPTION_HPP_
#define BABELEXCEPTION_HPP_

#include <exception>
#include <string>

/** @file
 * @brief File that declares the exception class of the project.
 */

/**
 * @brief Namespace of the project.
 *
 * Babel namespace.
 */
namespace Babel {
    /**
     * @brief Exception class of the project.
     *
     * Error handling of the project.
     */
    class BabelException : public std::exception {
        public:
            /**
             * @brief Constructor of BabelException.
             *
             * @param msg Message to raise.
             */
            BabelException(const std::string &msg = "Babel Error");

            /**
             * @brief Destructor of BabelException.
             */
            ~BabelException();

        protected:
        private:
    };
}

#endif /* !BABELEXCEPTION_HPP_ */
