/*
** EPITECH PROJECT, 2020
** db
** File description:
** CommandParser
*/

#include "CommandParser.hpp"

/** @file
 * @brief Defines the command parser.
 *
 * Parses commands and queries.
 */

CommandParser::CommandParser()
{
}

CommandParser::~CommandParser()
{
}

Data CommandParser::parseCmd(std::string &cmd, char cmdSeparator) {
    Data nCmd;
    nCmd.setCode(std::atoi(cmd.substr(0, cmd.find(cmdSeparator)).c_str()));
    cmd.erase(cmd.begin(), cmd.begin() + cmd.find(cmdSeparator) + 1);
    std::size_t current = cmd.find(",");
    std::size_t previous = 0;
    while (current != std::string::npos) {
        nCmd.pushBack(cmd.substr(previous, current - previous));
        previous = current + 1;
        current = cmd.find(",", previous);
    }
    nCmd.pushBack(cmd.substr(previous, current - previous));
    return nCmd;
}

std::string CommandParser::createReq(uint code, const std::string &data) {
    Data cmd(code, data);
    return cmd.getReq();
}

std::string CommandParser::createReq(Data data) {
    return data.getReq();
}