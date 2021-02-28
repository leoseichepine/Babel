/*
** EPITECH PROJECT, 2020
** B-CPP-500-STG-5-1-babel-leo.seichepine
** File description:
** StateMachine
*/

#include "StateMachine.hpp"

/** @file
 * @brief Defines the state of the machine.
 *
 * Sets generic functions for the widget states.
 */

StateMachine::StateMachine(QWidget *parent) : QStackedWidget(parent)
{
}

StateMachine::~StateMachine()
{
}

bool StateMachine::addState(AState *s, const std::string &name)
{
    if (!s)
        return false;
    _states[name] = s;
    this->addWidget(s);
    return true;
}

void StateMachine::setState(const std::string &name)
{
    this->setCurrentWidget(this->getState(name));
}

AState *StateMachine::getState(const std::string &name) const
{
    for (auto it : this->_states) {
        if (it.first == name)
            return it.second;
    }
    return nullptr;
}

std::map<std::string, AState *> &StateMachine::getAllStates(void)
{
    return this->_states;
}