/*
** EPITECH PROJECT, 2020
** B-CPP-500-STG-5-1-babel-leo.seichepine
** File description:
** ConnectionWidget
*/

#include "ConnectionWidget.hpp"

/** @file
 * @brief Defines the connection view.
 *
 * Sets the layout of the connection view and its events.
 */

ConnectionWidget::ConnectionWidget(QWidget *parent) : AState(parent)
{
    this->_bar = new QTabWidget(this);
    this->_widgets = {
        {"login", new LoginWidget(this)},
        {"register", new RegisterWidget(this)}
    };
    _bar->insertTab(0, _widgets["login"], "Login");
    _bar->insertTab(1, _widgets["register"], "Register");
    this->getLayout()->addWidget(_bar, 0, 0);
}

ConnectionWidget::~ConnectionWidget()
{
    for (auto it : this->_widgets) {
        if (it.second)
            delete it.second;
    }
    delete _bar;
}

std::map<std::string, AState *> &ConnectionWidget::getWidgets(void)
{
    return this->_widgets;
}

AState *ConnectionWidget::getLoginWidget(void)
{
    return this->_widgets["login"];
}

AState *ConnectionWidget::getRegisterWidget(void)
{
    return this->_widgets["register"];
}