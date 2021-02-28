/*
** EPITECH PROJECT, 2020
** B-CPP-500-STG-5-1-babel-leo.seichepine
** File description:
** ContactList
*/

#ifndef CONTACTLIST_HPP_
#define CONTACTLIST_HPP_

#include "./../stateMachine/StateMachine.hpp"
#include <QListWidget>
#include <QStatusBar>
#include <QLabel>
#include <iostream>

/** @file
 * @brief Defines the class of the contact list.
 *
 * Defines its properties and methods.
 */

/**
 * @brief Class of the contact list.
 *
 * Inherited from AState.
 *
 */
class ContactList : public AState {
    Q_OBJECT
    public:
        /**
         * @brief Constructor of ContactList.
         *
         * @param parent The widget of the user interface.
         */
        ContactList(QWidget *parent = nullptr);
        /**
         * @brief Destructor of ContactList.
         *
         * Deletes the list.
         */
        ~ContactList();

    private slots:
        /**
         * Private function which handles the event of a click on an item in the contact list.
         *
         * @param current Takes a QListWidgetItem which represents a single item in a QListWidget.
         */
        void onContactListClicked(QListWidgetItem *current);
    protected:
    private:
        /**
         * @brief Contact list title label.
         *
         * Private property.
         */
        QLabel *_listTitle;
        /**
         * @brief Contact list widget.
         *
         * Private property.
         */
        QListWidget *_list;
};

#endif /* !CONTACTLIST_HPP_ */