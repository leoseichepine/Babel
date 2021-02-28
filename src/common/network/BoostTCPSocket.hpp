/*
** EPITECH PROJECT, 2020
** server
** File description:
** Connection
*/

#ifndef TCPSOCKET_HPP
#define TCPSOCKET_HPP

#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/array.hpp>
#include "./ATCPSocket.hpp"
#include <list>
#include "./../commandParser/CommandParser.hpp"

/** @file
 * @brief Defines the class of the Boost TCP socket.
 *
 * Defines its properties and methods.
 */

/**
 * @brief Project namespace.
 */
namespace Babel {
    /**
     * @brief Class of Boost TCP socket.
     *
     * Inherited from ATCPSocket.
     */
    class BoostTCPSocket : public ATCPSocket, public boost::enable_shared_from_this<BoostTCPSocket> {
        public:
            /**
             * @brief Constructor of BoostTCPSocket.
             *
             * @param infos Infos about the connection.
             * @param io_service Boost asio service.
             */
            BoostTCPSocket(ConnectionInfos &infos, boost::asio::io_service &io_service);

            /**
             * @brief Destructor of BoostTCPSocket.
             */
            ~BoostTCPSocket();

            /**
             * @brief Typedef of the BoostTCPSocket shared pointer.
             */
            typedef boost::shared_ptr<BoostTCPSocket> ptr;

            /**
             * @brief Public function to get the boost socket.
             *
             * Getter method.
             *
             * @return the boost socket.
             */
            boost::asio::ip::tcp::socket &getSock(void);

            /**
             * @brief Public function to create the pointer of the boost socket.
             *
             * @param infos Infos about the connection.
             * @param io_service Boost asio service.
             * @return the pointer of the boost socket.
             */
            static ptr create(ConnectionInfos infos, boost::asio::io_service &io_service);

            /**
             * @brief Public function overridden from ATCPSocket to connect the socket.
             *
             * @return the connection status.
             */
            bool connect(void) override;

            /**
             * @brief Public function overridden from ATCPSocket to disconnect the socket.
             *
             * @return the disconnection status.
             */
            bool disconnect(void) override;

            /**
             * @brief Public function overridden from ATCPSocket to send a message.
             *
             * @param data Data to send.
             * @return the sending status.
             */
            bool send(const std::string &data) override;

            /**
             * @brief Public function overridden from ATCPSocket to receive a message.
             *
             * @return the string message.
             */
            std::string receive(void) override;

            /**
             * @brief Public function to read the buffer.
             */
            void read(void);
<<<<<<< HEAD

            /**
             * @brief Public function to pop a command.
             *
             * @return the popped command.
             */
            Data popCmd(void);

            /**
             * @brief Public function to check the packet size.
             *
             * @return the status of the packet size.
             */
            bool hasCmd();
=======
>>>>>>> f7d087374b11970ea2666ad36b6f0c29e52124b7
        protected:
        private:
            /**
             * @brief Private function to handle writing message.
             *
             * @param err The error code.
             */
            void handleWrite(const boost::system::error_code &err);

            /**
             * @brief Private function to handle reading message.
             *
             * @param err The error code.
             * @param bytesRead The number of bytes to read.
             */
            void handleRead(const boost::system::error_code &err, size_t bytesRead);

            /**
             * @brief The boost socket.
             *
             * Private property.
             */
            boost::asio::ip::tcp::socket _sock;

            /**
             * @brief The buffer.
             *
             * Private property.
             */
            boost::asio::streambuf _buff;
<<<<<<< HEAD

            /**
             * @brief The command parser.
             *
             * Private property.
             */
            CommandParser _cmdParser;

            /**
             * @brief The packets.
             *
             * Private property.
             */
            std::list<Data> _packets;

            /**
             * @brief The client's message to be received.
             *
             * Private property.
             */
            std::string _msgFromClient;

            /**
             * @brief The client's message to be sent send.
             *
             * Private property.
             */
            std::string _msgToClient;
=======
>>>>>>> f7d087374b11970ea2666ad36b6f0c29e52124b7
    };
}

#endif /* !TCPSOCKET_HPP */