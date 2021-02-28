/*
** EPITECH PROJECT, 2020
** db
** File description:
** User
*/

#ifndef USER_HPP_
#define USER_HPP_

#include <iostream>

/** @file
 * @brief Defines the class of the user.
 *
 * Defines its properties and methods.
 */

/**
 * @brief Class of the user.
 */
class User {
    public:
        /**
         * @brief Constructor of User.
         *
         * @param name The User's name.
         * @param password The User's password.
         */
        User(const std::string &name, const std::string &password);

        /**
         * @brief Destructor of User.
         */
        ~User();

        /**
         * @brief Public function to get user's name.
         *
         * Getter method.
         *
         * @return the user's name.
         */
        std::string getName(void) const;

        /**
         * @brief Public function to get user's password.
         *
         * Getter method.
         *
         * @return the user's password.
         */
        std::string getPass(void) const;

        /**
         * @brief The equality operator between two users.
         *
         * @param user The user.
         * @return the status of equality.
         */
        bool operator==(User &user);
    protected:
    private:
        /**
         * @brief Holds the user's name.
         *
         * Private property.
         */
        std::string _name;

        /**
         * @brief Holds the user's password.
         *
         * Private property.
         */
        std::string _password;

};

#endif /* !USER_HPP_ */
