/*
** EPITECH PROJECT, 2020
** B-CPP-500-STG-5-1-babel-leo.seichepine
** File description:
** RegisterWidget
*/

#include "RegisterWidget.hpp"

/** @file
 * @brief Defines the register view.
 *
 * Sets the layout of the register view and its events.
 */

RegisterWidget::RegisterWidget(QWidget *parent) : AState(parent)
{
    this->_formLines = {
        {"ip", new QLineEdit},
        {"port", new QLineEdit},
        {"username", new QLineEdit},
        {"password", new QLineEdit},
    };
    this->_formLayout = new QFormLayout;

    _formLines["password"]->setEchoMode(QLineEdit::Password);

    _formLines["ip"]->setValidator(new QRegExpValidator(QRegExp("^(?:[0-9]{1,3}\\x2E){3}[0-9]{1,3}$")));
    _formLines["port"]->setValidator(new QIntValidator(0, 65000));

    _formLayout->addRow(tr("&Server ip:"), _formLines["ip"]);
    _formLayout->addRow(tr("&Port:"), _formLines["port"]);
    _formLayout->addRow(tr("&Username:"), _formLines["username"]);
    _formLayout->addRow(tr("&Password:"), _formLines["password"]);
    this->getLayout()->addLayout(_formLayout, 0, 0);

    _regButton = new QPushButton(tr("Register"), parent);
    this->getLayout()->addWidget(_regButton, 1, 0);
    _regButton->show();
    this->setLayout(this->getLayout());
}

RegisterWidget::~RegisterWidget()
{
    for (auto it : this->_formLines) {
        if (it.second)
            delete it.second;
    }
    delete this->_formLayout;
    delete this->_regButton;
}

QPushButton *RegisterWidget::getRegisterButton(void)
{
    return this->_regButton;
}

std::map<std::string, QLineEdit *> &RegisterWidget::getFormData(void)
{
    return this->_formLines;
}