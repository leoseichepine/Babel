/*
** EPITECH PROJECT, 2020
** B-CPP-500-STG-5-1-babel-leo.seichepine
** File description:
** LoginWidget
*/

#include "LoginWidget.hpp"

/** @file
 * @brief Defines the login view.
 *
 * Sets the layout of the login view and its events.
 */

LoginWidget::LoginWidget(QWidget *parent) : AState(parent)
{
    this->_formLines = {
        {"ip", new QLineEdit},
        {"port", new QLineEdit},
        {"username", new QLineEdit},
        {"password", new QLineEdit}
    };
    this->_formLayout = new QFormLayout;
    _formLines["password"]->setEchoMode(QLineEdit::Password);

    _formLines["ip"]->setValidator(new QRegExpValidator(QRegExp("^(?:[0-9]{1,3}\\x2E){3}[0-9]{1,3}$")));
    _formLines["port"]->setValidator(new QIntValidator(0, 65000));

    _formLayout->addRow(tr("&Server ip:"), _formLines["ip"]);
    _formLayout->addRow(tr("&Server port:"), _formLines["port"]);
    _formLayout->addRow(tr("&Username:"), _formLines["username"]);
    _formLayout->addRow(tr("&Password:"), _formLines["password"]);
    this->getLayout()->addLayout(_formLayout, 0, 0);

    _logButton = new QPushButton(tr("Login"), parent);
    this->getLayout()->addWidget(_logButton, 1, 0);
    _logButton->show();
    this->setLayout(this->getLayout());
}

LoginWidget::~LoginWidget()
{
    for (auto it : this->_formLines) {
        if (it.second)
            delete it.second;
    }
    delete this->_formLayout;
    delete this->_logButton;
}

QPushButton *LoginWidget::getLoginButton(void)
{
    return this->_logButton;
}

std::map<std::string, QLineEdit *> &LoginWidget::getFormData(void)
{
    return this->_formLines;
}