/*
** EPITECH PROJECT, 2020
** B-CPP-500-STG-5-1-babel-leo.seichepine
** File description:
** MainWindow
*/

#ifndef MAINWINDOW_HPP_
#define MAINWINDOW_HPP_

#include <QMainWindow>
#include "./login/ConnectionWidget.hpp"
#include "./contactList/ContactList.hpp"
#include "./network/TCPClient.hpp"
#include "./../common/commandParser/CommandParser.hpp"

/** @file
 * @brief Defines the class of the window of the QT application.
 *
 * Defines its properties and methods.
 */

/**
 * @brief Class of the window of the QT application.
 *
 * Inherited from QMainWindow.
 *
 */
class MainWindow : public QMainWindow {
    Q_OBJECT
    public:
        /**
         * @brief Constructor of MainWindow.
         *
         * @param ios Boost asio service.
         * @param parent The widget of the user interface.
         */
        MainWindow(QObject *parent = nullptr);

        /**
        * @brief Destructor of MainWindow.
        *
        * Removes components of the window.
        */
        ~MainWindow();

        // StateMachine *getStateMachine(void);

        /**
         * @brief Public function to get the TCP client.
         *
         * Public getter method.
         *
         * @return the TCP client
         */
        TCPClient *getTCPClient(void);
    private slots:
        /**
         * @brief Private function to listen to the event when the user presses the login button.
         */
        void onLoginPressed(void);

        /**
         * @brief Private function to listen to the event when the user presses the register button.
         */
        void onRegisterPressed(void);
    protected:
    private:
        /**
         * @brief The TCP socket of the client.
         *
         * Private property.
         */
        TCPClient *_tcp;

        CommandParser _cmdParser;

        /**
         * @brief The connection widget.
         *
         * Private property.
         */
        ConnectionWidget *_connection;

        /**
         * The login widget.
         *
         * Private property.
         */
        LoginWidget *_login;

        /**
         * The register widget.
         *
         * Private property.
         */
        RegisterWidget *_register;
};

#endif /* !MAINWINDOW_HPP_ */