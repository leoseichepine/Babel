/*
** EPITECH PROJECT, 2020
** db
** File description:
** User
*/

#include "User.hpp"

/** @file
 * @brief Defines the user.
 *
 * Sets user methods.
 */

User::User(const std::string &name, const std::string &password) :
_name(name), _password(password)
{}

User::~User()
{}

std::string User::getName(void) const {return _name;}
std::string User::getPass(void) const {return _password;}

bool User::operator==(User &user) {
    return _name == user.getName() && _password == user.getPass();
}