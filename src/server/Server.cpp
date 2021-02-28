/*
** EPITECH PROJECT, 2020
** server
** File description:
** Server
*/

#include "Server.hpp"

/** @file
 * @brief Defines the server.
 *
 * Sets the server methods.
 */

Babel::Server::Server(boost::asio::io_service &ios, int port): _db("./data/", "db.json"), _ios(ios), _acceptor(ios, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port))
{
    _cmdHandlers.emplace(ClientCode::CREATE, &Babel::Server::createUser);
    _cmdHandlers.emplace(ClientCode::DELETE, &Babel::Server::deleteUser);
    _cmdHandlers.emplace(ClientCode::LOGIN, &Babel::Server::loginUser);
    _cmdHandlers.emplace(ClientCode::LOGOUT, &Babel::Server::logoutUser);
    _cmdHandlers.emplace(ClientCode::START_CALL, &Babel::Server::startCall);
    _cmdHandlers.emplace(ClientCode::ANSWER_CALL, &Babel::Server::answerCall);
    _cmdHandlers.emplace(ClientCode::END_CALL, &Babel::Server::endCall);
    _cmdHandlers.emplace(ClientCode::ADD_CONTACT, &Babel::Server::addContact);
    _cmdHandlers.emplace(ClientCode::REMOVE_CONTACT, &Babel::Server::removeContact);

    std::cout << "Server Created! Runing on port " << _acceptor.local_endpoint().port() << "..." << std::endl;
    _running = true;
    startAccept();
    startHandlingCommand();
}

Babel::Server::~Server()
{
    std::cout << "Server dtor!" << std::endl;
}

std::vector<Babel::BoostTCPSocket::ptr> &Babel::Server::getSockets(void)
{
    return this->_sock;
}

void Babel::Server::startAccept(void)
{
    Babel::ConnectionInfos infos;
    Babel::BoostTCPSocket::ptr newConn = Babel::BoostTCPSocket::create(infos, _acceptor.get_io_service());

    _acceptor.async_accept(newConn->getSock(),
        boost::bind(&Babel::Server::handleAccept, this, newConn, boost::asio::placeholders::error));
}

void Babel::Server::handleAccept(BoostTCPSocket::ptr newConn, const boost::system::error_code &err)
{
    if (!err) {
        std::cout << "New client!" << std::endl;
        _sock.push_back(newConn);
        newConn->setConnected(true);
        newConn->read();
        startAccept();
    } else {
        std::cerr << "Failed to accept new client" << std::endl;
    }
}

void Babel::Server::disconnectClient(BoostTCPSocket::ptr client)
{
    if (client->isConnected()) {
        auto pos = std::find(_sock.begin(), _sock.end(), client);
        if (pos != _sock.end()) {
            client->send("555|Deconnection\r\n");
            _sock.erase(pos);
        }
    }
}

void Babel::Server::startHandlingCommand(void)
{
    boost::thread cmdThread(boost::bind(&boost::asio::io_service::run, &_ios));

    while (_running) {
        for (auto it : this->_sock) {
            if (it->isConnected()) {
                handleClient(it);
            } else {
                disconnectClient(it);
            }
        }
    }
}

void Babel::Server::handleClient(BoostTCPSocket::ptr client)
{
    if (client->hasCmd()) {
        Data tmp = client->popCmd();
        int code = tmp.getCode();
        std::vector<std::string> args = tmp.getData();
        (this->*_cmdHandlers[static_cast<ClientCode::cmdCode_t>(code)])(client, args);
    }
}

int Babel::Server::createUser(BoostTCPSocket::ptr socket, std::vector<std::string> &args)
{
    std::cout << "Creating user..." << std::endl;
    if (args.size() != 2) {
        socket->send("403|Account creation failed.\r\n");
        return -1;
    }
    std::string username = args[0];
    std::string password = args[1];
    if (_db.getUser(username) != 0) {
        socket->send("403|Account creation failed.\r\n");
        return -1;
    }
    User tmp(username, password);
    _db.createUser(tmp);
    socket->send("203|Account created.\r\n");
    return 0;
}

int Babel::Server::deleteUser(BoostTCPSocket::ptr socket, std::vector<std::string> &args)
{
    //TODO dans la db!
}

int Babel::Server::loginUser(BoostTCPSocket::ptr socket, std::vector<std::string> &args)
{
    if (args.size() != 2) {
        socket->send("401|Wrong number of arguments\r\n");
        return -1;
    }
    std::string username = args[0];
    std::string password = args[1];
    User tmp(username, password);
    if (!_db.checkUser(tmp)) {
        socket->send("401|Unauthorized\r\n");
        return -1;
    }
    socket->send("201|Connection enabled.\r\n");
    return 0;
}

int Babel::Server::logoutUser(BoostTCPSocket::ptr socket, std::vector<std::string> &args)
{
    // TODO!
}

int Babel::Server::startCall(BoostTCPSocket::ptr socket, std::vector<std::string> &args)
{
    //TODO
}

int Babel::Server::answerCall(BoostTCPSocket::ptr socket, std::vector<std::string> &args)
{
    //TODO
}

int Babel::Server::endCall(BoostTCPSocket::ptr socket, std::vector<std::string> &args)
{
    //TODO
}

int Babel::Server::addContact(BoostTCPSocket::ptr socket, std::vector<std::string> &args)
{
    if (args.size() != 2) {
        socket->send("420|Adding contact failed.\r\n");
        return -1;
    }
    std::string user = args[0];
    std::string contact = args[1];
    uint id1 = _db.getUser(user);
    uint idContact = _db.getUser(contact);
    if (!id1 || !idContact) {
        socket->send("420|Adding contact failed.\r\n");
        return -1;
    }
    _db.addFriends(id1, idContact);
    socket->send("420|Contact added.\r\n");
    return 0;
}

int Babel::Server::removeContact(BoostTCPSocket::ptr socket, std::vector<std::string> &args)
{
    if (args.size() != 2) {
        socket->send("420|Removing contact failed.\r\n");
        return -1;
    }
    std::string user = args[0];
    std::string contact = args[1];
    uint id1 = _db.getUser(user);
    uint idContact = _db.getUser(contact);
    if (!id1 || !idContact) {
        socket->send("420|Removing contact failed.\r\n");
        return -1;
    }
    _db.removeFriends(id1, idContact);
    socket->send("420|Contact removed\r\n");
    return 0;
}