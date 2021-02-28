/*
** EPITECH PROJECT, 2020
** B-CPP-500-STG-5-1-babel-leo.seichepine
** File description:
** ContactList
*/

#include "ContactList.hpp"

/** @file
 * @brief Defines the contact list view.
 *
 * Sets the layout of the contact list and its events.
 */

ContactList::ContactList(QWidget *parent) : AState(parent)
{
    _listTitle = new QLabel;
    _listTitle->setText("Contact List:");
    _list = new QListWidget(parent);
    _list->setSortingEnabled(true);
    _list->setCurrentRow(0);

    this->getLayout()->addWidget(_listTitle, 0, 0, Qt::AlignLeft);
    this->getLayout()->addWidget(_list, 1, 0, Qt::AlignLeft);
    this->setLayout(this->getLayout());
    connect(this->_list, SIGNAL(itemClicked(QListWidgetItem *)),
    this, SLOT(onContactListClicked(QListWidgetItem *)));
}

ContactList::~ContactList()
{
    delete this->_list;
}

void ContactList::onContactListClicked(QListWidgetItem *current)
{
    for (std::size_t i = 0; i < _list->count(); i++) {
        QListWidgetItem *item = _list->item(i);
        if (item == current) {
            std::cout << item->text().toStdString() << " clicked!" << std::endl;
        }
    }
}