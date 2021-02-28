/*
** EPITECH PROJECT, 2020
** B-CPP-500-STG-5-1-babel-leo.seichepine
** File description:
** QtTCPSocket
*/

#ifndef QTTCPSOCKET_HPP_
#define QTTCPSOCKET_HPP_

#include "./../../common/network/ATCPSocket.hpp"
#include <QTcpSocket>
#include <QtNetwork>
#include <QObject>
#include <QMessageBox>
#include <QDataStream>
#include <QWidget>
#include <QDialog>

/** @file
 * @brief Defines the class of the QT TCP socket.
 *
 * Defines its properties and methods.
 */

/**
 * Project Namespace.
 */
namespace Babel {

    /**
     * @brief Class of the QT TCP socket.
     *
     * Inherited from QObject and ATCPSocket.
     *
     */
    class QtTCPSocket : public QObject, public ATCPSocket {
        Q_OBJECT
        public:
            /**
             * @brief Constructor of QtTCPSocket.
             *
             * @param infos Infos about the connection.
             * @param parent The widget of the user interface.
             */
            QtTCPSocket(ConnectionInfos &infos, QObject *parent = nullptr);

            /**
             * @brief Destructor of QtTCPSocket.
             *
             * Deletes the QT socket.
             */
            ~QtTCPSocket();

            /**
             * @brief Connect the client to the server.
             *
             * Public virtual function overridden from ATCPSocket.
             *
             * @return connection status.
             */
            virtual bool connect(void);

            /**
             * @brief Disconnect the client from the server.
             *
             * Public virtual function overridden from ATCPSocket.
             *
             * @return disconnection status.
             */
            virtual bool disconnect(void);

            /**
             * @brief Send a message to the server.
             *
             * Public virtual function overridden from ATCPSocket.
             *
             * @param data The data to send.
             *
             * @return sending status.
             */
            virtual bool send(const std::string &data);

            /**
             * @brief Receive a message from the server.
             *
             * Public virtual function overridden from ATCPSocket.
             *
             * @return receiving the data.
             */
            virtual std::string receive(void);
        private slots:
            /**
             * @brief Display an error on the user interface.
             *
             * Display a message box.
             *
             * @param parent The widget of the user interface.
             * @param err The exception.
             */
            void displayError(QWidget *parent, const QAbstractSocket::SocketError &err);
        protected:
        private:
            void read(void);
            void handleRead(void);
            void handleData(void);
            void onConnectionEnabled(void);
            /**
             * @brief The QT socket.
             *
             * Private property.
             */
            QTcpSocket _sock;

            /**
             * @brief Binary stream of encoded information.
             *
             * Private property.
             */
            QDataStream _in;
    };
};

#endif /* !QTTCPSOCKET_HPP_ */