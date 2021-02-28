/*
** EPITECH PROJECT, 2020
** server
** File description:
** Server
*/

#ifndef SERVER_HPP_
#define SERVER_HPP_

#include "./../common/exception/BabelException.hpp"
#include "./../common/network/BoostTCPSocket.hpp"
#include "./../common/commandParser/CommandParser.hpp"
#include "./db/Database.hpp"
#include <boost/thread/thread.hpp>

/**
 * @brief The project namespace
 */
namespace Babel {
    /**
     * @brief Class of the server.
     */
    class Server {
        public:
            /**
             * @brief Constructor of Server.
             *
             * @param ios Boost asio service.
             * @param port The port of the server.
             */
            Server(boost::asio::io_service &ios, int port = 42042);

            /**
             * @brief Destructor of Server.
             */
            ~Server();

            /**
             * @brief A typedef for the sequence container of the commands.
             */
            typedef int (Babel::Server::*cmdHandler_t)(BoostTCPSocket::ptr socket, std::vector<std::string> &args);

            /**
             * @brief Public function to get sockets of the server.
             *
             * @return a sequence container of the server's sockets.
             */
            std::vector<BoostTCPSocket::ptr> &getSockets(void);
        protected:
        private:
            /**
             * @brief Private function to
             */
            void startAccept(void);

            /**
             * @brief Private function to accept a socket.
             *
             * @param newConn The pointer of the new connection.
             * @param err The error code.
             */
            void handleAccept(BoostTCPSocket::ptr newConn, const boost::system::error_code &err);

            /**
             * @brief Private function to handle the command.
             */
            void startHandlingCommand(void);

            /**
             * @brief Private function to create the user.
             *
             * @param args A sequence container of the arguments.
             * @return the creation status.
             */
            int createUser(BoostTCPSocket::ptr, std::vector<std::string> &args);

            /**
             * @brief Private function to delete the user.
             *
             * @param args A sequence container of the arguments.
             * @return the deletion status.
             */
            int deleteUser(BoostTCPSocket::ptr, std::vector<std::string> &args);

            /**
             * @brief Private function to login the user.
             *
             * @param args A sequence container of the arguments.
             * @return the login status.
             */
            int loginUser(BoostTCPSocket::ptr, std::vector<std::string> &args);

            /**
             * @brief Private function to logout the user.
             *
             * @param args A sequence container of the arguments.
             * @return the logout status.
             */
            int logoutUser(BoostTCPSocket::ptr, std::vector<std::string> &args);

            /**
             * @brief Private function to start a call.
             *
             * @param args A sequence container of the arguments.
             * @return the call start status.
             */
            int startCall(BoostTCPSocket::ptr, std::vector<std::string> &args);

            /**
             * @brief Private function to answer a call.
             *
             * @param args A sequence container of the arguments.
             * @return the call answer status.
             */
            int answerCall(BoostTCPSocket::ptr, std::vector<std::string> &args);

            /**
             * @brief Private function to end a call.
             *
             * @param args A sequence container of the arguments.
             * @return the status of the call end.
             */
            int endCall(BoostTCPSocket::ptr, std::vector<std::string> &args);

            /**
             * @brief Private function to add a contact.
             *
             * @param args A sequence container of the arguments.
             * @return the status of adding a contact.
             */
            int addContact(BoostTCPSocket::ptr, std::vector<std::string> &args);

            /**
             * @brief Private function to remove a contact.
             *
             * @param args A sequence container of the arguments.
             * @return the status of removing a contact.
             */
            int removeContact(BoostTCPSocket::ptr, std::vector<std::string> &args);
            
            /**
             * @brief Private function to handle the client.
             *
             * @param client The pointer of the client's socket.
             */
            void handleClient(BoostTCPSocket::ptr client);

            /**
             * @brief Private function to disconnect the client.
             *
             * @param client The pointer of the client's socket.
             */
            void disconnectClient(BoostTCPSocket::ptr client);

            /**
             * @brief Holds the database.
             *
             * Private property.
             */
            Database _db;

            /**
             * @brief Holds the operating status of the server.
             *
             * Private property.
             */
            bool _running;

            /**
             * @brief Holds the Boost asio service.
             *
             * Private property.
             */
            boost::asio::io_service &_ios;

            /**
             * @brief Holds the acceptor.
             *
             * Private property.
             */
            boost::asio::ip::tcp::acceptor _acceptor;

            /**
             * @brief Holds the sequence container of sockets.
             *
             * Private property.
             */
            std::vector<BoostTCPSocket::ptr> _sock;

            /**
             * @brief Holds the command parser.
             *
             * Private property.
             */
            CommandParser _cmdParser;

            /**
             * @brief Holds the commands.
             *
             * KEY: client code.
             * VALUE: commands.
             *
             * Private property.
             */
            std::map<ClientCode::cmdCode_t, cmdHandler_t> _cmdHandlers;
    };
}

#endif /* !SERVER_HPP_ */