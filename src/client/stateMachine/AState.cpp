/*
** EPITECH PROJECT, 2020
** B-CPP-500-STG-5-1-babel-leo.seichepine
** File description:
** AState
*/

#include "AState.hpp"

/** @file
 * @brief Defines the abstract state class.
 *
 * Sets generic functions for the layout of the application.
 */

AState::AState(QWidget *parent) : QWidget(parent)
{
    this->_layout = new QGridLayout;
    this->_layout->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    this->_msgBox = new QMessageBox;
}

AState::~AState()
{
    delete this->_layout;
    delete this->_msgBox;
}

QGridLayout *AState::getLayout(void) const
{
    return this->_layout;
}

void AState::showMessageBox(const std::string &txt)
{
    this->_msgBox->setText(txt.c_str());
    this->_msgBox->show();
}