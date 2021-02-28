/*
** EPITECH PROJECT, 2020
** db
** File description:
** CommandParser
*/

#ifndef COMMANDPARSER_HPP_
#define COMMANDPARSER_HPP_

#include "Data.hpp"

/** @file
 * @brief Defines the class of the command parser.
 *
 * Defines its properties and methods.
 */

/**
 * @brief Class of the command parser.
 *
 * Format queries and parse commands.
 */
class CommandParser {
    public:
        /**
         * @brief Constructor of CommandParser.
         */
        CommandParser();

        /**
         * @brief Destructor of CommandParser.
         */
        ~CommandParser();

        /**
         * @brief Public function to parser a command.
         *
         * @param cmd The command to parse.
         * @param cmdSeparator The command delimiter.
         * @return the request data.
         */
        Data parseCmd(std::string &cmd, char cmdSeparator);

        /**
         * @brief  Public function to create the request.
         *
         * @param code The action code.
         * @param data Data.
         * @return the request.
         */
        std::string createReq(uint code, const std::string &data);

        /**
         *
         * @brief Public function to create the request.
         *
         * @param data Data.
         * @return the request.
         */
        std::string createReq(Data data);
};

#endif /* !COMMANDPARSER_HPP_ */
