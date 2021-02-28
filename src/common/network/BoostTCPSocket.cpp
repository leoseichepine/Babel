/*
** EPITECH PROJECT, 2020
** server
** File description:
** BoostTCPSocket
*/

#include "BoostTCPSocket.hpp"

/** @file
 * @brief Defines the Boost TCP Socket.
 *
 * Sets Boost TCP socket methods.
 */

Babel::BoostTCPSocket::BoostTCPSocket(ConnectionInfos &infos, boost::asio::io_service &io_service): ATCPSocket(infos), _sock(io_service)
{
}

Babel::BoostTCPSocket::~BoostTCPSocket()
{
}

Babel::BoostTCPSocket::ptr Babel::BoostTCPSocket::create(ConnectionInfos infos, boost::asio::io_service &io_service)
{
    return ptr(new BoostTCPSocket(infos, io_service));
}

boost::asio::ip::tcp::socket &Babel::BoostTCPSocket::getSock(void)
{
    return this->_sock;
}

bool Babel::BoostTCPSocket::connect(void)
{
    if (this->isConnected()) {
        std::cout << "Cannot connect socket : already connected!" << std::endl;
        return false;
    }
    boost::asio::ip::tcp::endpoint endpoint(
        boost::asio::ip::address::from_string(this->getConnectionInfos().getIp().c_str()),
        this->getConnectionInfos().getPort());

    try {
        this->getSock().connect(endpoint);
    } catch (const boost::system::system_error &e) {
        std::cerr << "Connection failed: " << e.what() << std::endl;
        return false;
    }
    std::cout << "Connection enabled!" << std::endl;
    this->_connected = true;
    read();
    return true;
}

bool Babel::BoostTCPSocket::disconnect(void)
{
    if (!this->isConnected()) {
        std::cout << "Cannot disconnect socket : already disconnected!" << std::endl;
        return false;
    }
    std::cout << "Disconnecting socket..." << std::endl;
    if (this->getSock().is_open())
        this->getSock().close();
    this->_connected = false;
    return true;
}

bool Babel::BoostTCPSocket::send(const std::string &data)
{
    if (!this->isConnected()) {
        std::cout << "Cannot send data : socket not connected" << std::endl;
        return false;
    }
    boost::asio::async_write(
        this->getSock(),
        boost::asio::buffer(data, data.size()),
        boost::bind(&BoostTCPSocket::handleWrite, shared_from_this(), boost::asio::placeholders::error));
    return true;
}

std::string Babel::BoostTCPSocket::receive(void)
{
}

void Babel::BoostTCPSocket::handleWrite(const boost::system::error_code &err)
{
    if (!this->isConnected())
        return;
    if (!err) {
    } else {
        std::cout << "Error writing..." << std::endl;
    }
}

void Babel::BoostTCPSocket::read(void)
{
    if (!this->isConnected()) {
        std::cout << "Cannot read data : socket not connected!" << std::endl;
        return;
    }
    boost::asio::async_read_until(
        this->getSock(),
        _buff,
        '\n',
        boost::bind(&BoostTCPSocket::handleRead, shared_from_this(),
                    boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
}

void Babel::BoostTCPSocket::handleRead(const boost::system::error_code &err, size_t bytesRead)
{
    if (!this->isConnected()) {
        std::cout << "Cannot read : socket not connected" << std::endl;
        return;
    }
    _msg = "";
    if (!err) {
        std::string line;
        std::istream is(&_buff);
        std::getline(is, line);
        if (!line.empty()) {
            _msg = line;
            std::cout << "Received : " << line << std::endl;
            this->_packets.push_back(_cmdParser.parseCmd(line, '|'));
            line.clear();
        }
        read();
    } else {
        std::cerr << err.message() << std::endl;
        this->disconnect();
    }
}