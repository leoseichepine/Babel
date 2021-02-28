/*
** EPITECH PROJECT, 2020
** B-CPP-500-STG-5-1-babel-leo.seichepine
** File description:
** ATcpSocket
*/

#ifndef ATCPSOCKET_HPP_
#define ATCPSOCKET_HPP_

#include <iostream>
#include <list>
#include "ConnectionInfos.hpp"
#include "./../commandParser/CommandParser.hpp"

/** @file
 * @brief Defines the abstract class of the TCP socket.
 *
 * Defines its properties and methods.
 */

/**
 * @brief Namespace of the project.
 */
namespace Babel {
    /**
     * @brief Abstract class
     */
    class ATCPSocket {
        public:
            /**
             * @brief Constructor of ATCPSocket.
             *
             * @param infos Infos about the connection.
             */
            ATCPSocket(ConnectionInfos &infos);

            /**
             * @brief Destructor of ATCPSocket.
             */
            virtual ~ATCPSocket();

            /**
             * @brief Pure virtual function to connect the socket.
             *
             * @return the connection status.
             */
            virtual bool connect(void) = 0;

            /**
             * @brief Pure virtual function to disconnect the socket.
             *
             * @return the disconnection status.
             */
            virtual bool disconnect(void) = 0;

            /**
             * @brief Pure virtual function to send a message.
             *
             * @param data Data to send.
             * @return the sending status.
             */
            virtual bool send(const std::string &data) = 0;

            /**
             * @brief Pure virtual function to receive a message.
             *
             * @return the string message.
             */
            virtual std::string receive(void) = 0;

            /**
             * @brief Public function to know if the socket is connected.
             *
             * Getter method.
             *
             * @return the connection status.
             */
            bool isConnected(void) const;

            /**
             * @brief Public function to set the connection status.
             *
             * Setter method.
             */
            void setConnected(bool);

            /**
             * @brief Public function to get the connection information.
             *
             * Getter method.
             *
             * @return the connection information.
             */
            ConnectionInfos getConnectionInfos(void) const;

            /**
             * @brief Public function to set the connection information.
             *
             * Setter method.
             *
             * @param infos Infos about the connection.
             */
            void setConnectionInfos(ConnectionInfos &infos);

            /**
             * @brief The equality operator between connection information.
             *
             * @param infos Infos about the connection.
             * @return the status of equality.
             */
            bool operator==(ConnectionInfos &infos);

             /**
             * @brief Public function to pop a command.
             *
             * @return the data.
             */
            Data popCmd(void);

             /**
             * @brief Public function to check if the socket has the command.
             *
             * @return the status of holding the command.
             */
            bool hasCmd(void);
            
        protected:
            /**
             * @brief The connection status.
             *
             * Protected property.
             */
            bool _connected;

            /**
             * @brief The connection information.
             *
             * Protected property.
             */
            ConnectionInfos _infos;

            /**
             * @brief The queue of commands.
             *
             * Protected property.
             */
            std::vector<std::string> _queue;

            /**
             * @brief The data request.
             *
             * Protected property.
             */
            std::string _data;

            /**
             * @brief The command parser.
             *
             * Protected property.
             */
            CommandParser _cmdParser;

            /**
             * @brief The socket's packets.
             *
             * Protected property.
             */
            std::list<Data> _packets;

            /**
             * @brief The socket's message.
             *
             * Protected property.
             */
            std::string _msg;
        private:
    };
}

#endif /* !ATCPSOCKET_HPP_ */