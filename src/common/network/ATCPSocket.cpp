/*
** EPITECH PROJECT, 2020
** B-CPP-500-STG-5-1-babel-leo.seichepine
** File description:
** ATCPSocket
*/

#include "ATCPSocket.hpp"

/** @file
 * @brief Defines the abstract class of TCP socket.
 *
 * Sets TCP socket methods.
 */

Babel::ATCPSocket::ATCPSocket(ConnectionInfos &infos) : _connected(false), _infos(infos)
{
}

Babel::ATCPSocket::~ATCPSocket()
{
}

bool Babel::ATCPSocket::isConnected(void) const
{
    return this->_connected;
}

Babel::ConnectionInfos Babel::ATCPSocket::getConnectionInfos(void) const
{
    return this->_infos;
}

void Babel::ATCPSocket::setConnectionInfos(ConnectionInfos &infos)
{
    this->_infos = infos;
}

bool Babel::ATCPSocket::operator==(ConnectionInfos &infos)
{
    return (this->getConnectionInfos() == infos);
}

void Babel::ATCPSocket::setConnected(bool val)
{
    this->_connected = val;
}

Data Babel::ATCPSocket::popCmd(void)
{
    Data tmp = _packets.front();
    _packets.pop_front();
    return tmp;
}

bool Babel::ATCPSocket::hasCmd(void)
{
    if (this->_packets.size() == 0)
        return false;
    return true;
}