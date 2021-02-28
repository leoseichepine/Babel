/*
** EPITECH PROJECT, 2020
** B-CPP-500-STG-5-1-babel-leo.seichepine
** File description:
** ConnectionInfos
*/

#include "ConnectionInfos.hpp"

/** @file
 * @brief Defines the connection information.
 *
 * Sets the connection information methods.
 */

Babel::ConnectionInfos::ConnectionInfos(const std::string &ip, std::size_t port) : _ip(ip), _port(port)
{
}

Babel::ConnectionInfos::~ConnectionInfos()
{
}

const std::string &Babel::ConnectionInfos::getIp(void) const
{
    return this->_ip;
}

std::size_t Babel::ConnectionInfos::getPort(void) const
{
    return this->_port;
}

void Babel::ConnectionInfos::setIp(const std::string &ip)
{
    this->_ip = ip;
}

void Babel::ConnectionInfos::setPort(std::size_t port)
{
    this->_port = port;
}

bool Babel::ConnectionInfos::operator==(const ConnectionInfos &b) const
{
    return ((this->_ip == b.getIp()) && (this->_port == b.getPort()));
}