/*
** EPITECH PROJECT, 2020
** B-CPP-500-STG-5-1-babel-leo.seichepine
** File description:
** TCPClient
*/

#ifndef TCPCLIENT_HPP_
#define TCPCLIENT_HPP_

#include "./../../client/network/QtTCPSocket.hpp"
#include "./../../common/network/ConnectionInfos.hpp"

/** @file
 * @brief Defines the class of the TCP socket of the client.
 *
 * Defines its properties and methods.
 */

/**
 * @brief Class of the TCP socket of the client.
 *
 */
class TCPClient {
    public:
        /**
         * @brief Constructor of TCPClient.
         *
         * @param ios Boost asio service.
         * @param infos Infos about the connection.
         */
        TCPClient(Babel::ConnectionInfos &infos);

        /**
         * @brief Destructor of QtTCPSocket.
         *
         * Deletes the QT socket.
         */
        ~TCPClient();

        /**
         * @brief Get the client's socket.
         *
         * Public method.
         *
         * @return the pointer of the socket.
         */
        Babel::QtTCPSocket *getSocket(void);

        /**
         * @brief Set the client's username.
         *
         * Public method.
         *
         * @param input The string of the client's username.
         */
        void setUsername(const std::string &);

        /**
         * @brief Set the client's password.
         *
         * Public method.
         *
         * @param input The string of the client's password.
         */
        void setPassword(const std::string &);
    protected:
    private:
        /**
         * @brief The pointer of the TCP socket.
         *
         * Private property.
         */
        Babel::QtTCPSocket *_sock;

        /**
         * @brief The client's username.
         *
         * Private property.
         */
        std::string _username;

        /**
         * @brief The client's password.
         *
         * Private property.
         */
        std::string _password;
};

#endif /* !TCPCLIENT_HPP_ */