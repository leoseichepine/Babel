/*
** EPITECH PROJECT, 2020
** B-CPP-500-STG-5-1-babel-leo.seichepine
** File description:
** QtTCPSocket
*/

#include "QtTCPSocket.hpp"

/** @file
 * @brief Defines the QT TCP socket.
 *
 * Sets TCP socket methods such as disconnect, connect, send and receive messages.
 */

Babel::QtTCPSocket::QtTCPSocket(ConnectionInfos &infos, QObject *parent) : QObject(parent), ATCPSocket(infos)
{
	QObject::connect(&_sock, &QTcpSocket::connected, this, &QtTCPSocket::onConnectionEnabled);
	QObject::connect(&_sock, &QTcpSocket::disconnected, this, &QtTCPSocket::disconnect);
}

Babel::QtTCPSocket::~QtTCPSocket()
{
}

bool Babel::QtTCPSocket::connect(void)
{
    if (this->isConnected())
        return false;
    _sock.connectToHost(QString(_infos.getIp().c_str()), (quint16)_infos.getPort());
    read();
    return true;
}

void Babel::QtTCPSocket::onConnectionEnabled(void)
{
    std::cout << "Connection enabled!" << std::endl;
    this->setConnected(true);
}

bool Babel::QtTCPSocket::disconnect(void)
{
    if (!this->isConnected())
        return false;
    if (this->_sock.isOpen())
        _sock.disconnectFromHost();
    this->setConnected(false);
    return true;
}

void Babel::QtTCPSocket::read(void)
{
    QDialog::connect(&_sock, &QIODevice::readyRead, this, &Babel::QtTCPSocket::handleRead);
}

void Babel::QtTCPSocket::handleRead(void)
{
    std::string tmp = _sock.readAll().toStdString();
    _packets.push_back(tmp);
}

// convert int to QByteArray
QByteArray QIntToByteArray(int src)
{
    QByteArray tmp;
    QDataStream data(&tmp, QIODevice::ReadWrite);
    data << src;
    return tmp;
}

bool Babel::QtTCPSocket::send(const std::string &data)
{
    if(_sock.isOpen()) {
        std::cout << "sending " << data << std::endl;
        _sock.write(data.c_str());
        return _sock.waitForBytesWritten();
    } else
        return false;
}

std::string Babel::QtTCPSocket::receive(void)
{
}

void Babel::QtTCPSocket::displayError(QWidget *parent, const QAbstractSocket::SocketError &err)
{
    switch (err) {
        case QAbstractSocket::RemoteHostClosedError:
            break;
        default:
            QMessageBox::information(parent, tr("Client"), tr("Error occured: %1.").arg(_sock.errorString()));
    }
}