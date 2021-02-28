/*
** EPITECH PROJECT, 2020
** B-CPP-500-STG-5-1-babel-leo.seichepine
** File description:
** TCPClient
*/

#include "TCPClient.hpp"

/** @file
 * @brief Defines the TCP socket of the client.
 *
 * Sets TCP socket of the client methods such as connect, set his username and his password.
 */

TCPClient::TCPClient(Babel::ConnectionInfos &infos)
{
    std::cout << "Ctor TCPclient!" << std::endl;
    this->_sock = new Babel::QtTCPSocket(infos);
}

TCPClient::~TCPClient()
{
    delete this->_sock;
}

Babel::QtTCPSocket *TCPClient::getSocket(void)
{
    return this->_sock;
}

void TCPClient::setUsername(const std::string &username)
{
    this->_username = username;
}

void TCPClient::setPassword(const std::string &password)
{
    this->_password = password;
}