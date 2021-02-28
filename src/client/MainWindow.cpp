/*
** EPITECH PROJECT, 2020
** B-CPP-500-STG-5-1-babel-leo.seichepine
** File description:
** MainWindow
*/

#include "MainWindow.hpp"

/** @file
 * @brief Defines the window of the QT application.
 *
 * Sets functions related to the window.
 */

MainWindow::MainWindow(QObject *parent)
{
    this->setFixedSize(800, 600);
    this->_connection = new ConnectionWidget;
    this->setCentralWidget(_connection);

    // initLoginEvent
    _login = static_cast<LoginWidget *>(this->_connection->getWidgets()["login"]);
    QPushButton *logButton = _login->getLoginButton();
    QObject::connect(logButton, SIGNAL(released()), this, SLOT(onLoginPressed()));

    // initRegisterEvent
    _register = static_cast<RegisterWidget *>(this->_connection->getWidgets()["register"]);
    QPushButton *regButton = _register->getRegisterButton();
    QObject::connect(regButton, SIGNAL(released()), this, SLOT(onRegisterPressed()));

    Babel::ConnectionInfos infos;
    this->_tcp = new TCPClient(infos);
}

MainWindow::~MainWindow()
{
    delete this->_tcp;
}

TCPClient *MainWindow::getTCPClient(void)
{
    return this->_tcp;
}

void MainWindow::onLoginPressed(void)
{
    std::map<std::string, QLineEdit *>data = _login->getFormData();

    QString ip = data["ip"]->text();
    int p = 0;
    QRegExpValidator::State sIp = data["ip"]->validator()->validate(ip, p);

    QString port = data["port"]->text();
    int p1 = 1;
    QRegExpValidator::State sPort = data["port"]->validator()->validate(port, p1);

    if (sIp == QValidator::Acceptable && sPort == QValidator::Acceptable) {
        Babel::ConnectionInfos i(data["ip"]->text().toStdString(), data["port"]->text().toInt());
        this->_tcp->getSocket()->setConnectionInfos(i);
        this->_tcp->setUsername(data["username"]->text().toStdString());
        this->_tcp->setPassword(data["password"]->text().toStdString());
        !this->_tcp->getSocket()->connect();
    } else {
        this->_login->showMessageBox("Invalid field value.");
    }
}
void MainWindow::onRegisterPressed(void)
{
    std::map<std::string, QLineEdit *>data = _register->getFormData();

    QString ip = data["ip"]->text();
    int p = 0;
    QRegExpValidator::State sIp = data["ip"]->validator()->validate(ip, p);

    QString port = data["port"]->text();
    int p1 = 1;
    QRegExpValidator::State sPort = data["port"]->validator()->validate(port, p1);

    if (sIp == QValidator::Acceptable && sPort == QValidator::Acceptable) {
        Babel::ConnectionInfos i(data["ip"]->text().toStdString(), data["port"]->text().toInt());
        this->_tcp->getSocket()->setConnectionInfos(i);
        this->_tcp->getSocket()->connect();

        Data request(ClientCode::CREATE);
        request.pushBack(data["username"]->text().toStdString());
        request.pushBack(data["password"]->text().toStdString());
        this->_tcp->getSocket()->send(request.getReq());

        std::string answer = this->_tcp->getSocket()->receive();
        std::cout << "answer is " << answer << std::endl;
        // int c = std::atoi(answer.substr(0, answer.find('|')).c_str());
        // if (c == 203)
        //     this->_register->showMessageBox("Account successfully created.");
        // else
        //     this->_register->showMessageBox("Error during account creation.");
    } else {
        this->_register->showMessageBox("Invalid field value.");
    }
}