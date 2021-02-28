/*
** EPITECH PROJECT, 2020
** db
** File description:
** Database
*/

#ifndef DATABASE_HPP_
#define DATABASE_HPP_


#include "User.hpp"
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <iostream>
#include <fstream>
#include <map>
#include <vector>

/** @file
 * @brief Defines the class of the database.
 *
 * Defines its properties and methods.
 */

/**
 * @brief Class of the database.
 */
class Database {
    public:
        /**
         * @brief Constructor of Database.
         *
         * @param path Path of the database.
         * @param name Name of the database.
         */
        Database(const std::string &path, const std::string &name);

        /**
         * @brief Destructor of Database.
         */
        ~Database();

        /**
         * @brief Enum which holds field types in the database.
         */
        enum fieldType {
            CONFIG,
            NEXT_ID,
            USER,
            ID,
            NAME,
            PASSWORD,
            FRIENDS
        };

        /**
         * @brief Map that contains the name of the field types in the database.
         */
        std::map<fieldType, std::string> fieldName = {
            {CONFIG, "config"},
            {NEXT_ID, "config.next_id"},
            {USER, "user"},
            {ID, "id"},
            {NAME, "name"},
            {PASSWORD, "password"},
            {FRIENDS, "friends"}};

        /**
         * @brief Public function to setup the database.
         */
        void setupDB();

        /**
         * @brief Public function to get the database ID.
         *
         * @return the database ID.
         */
        uint getId(void);

        /**
         * @brief Public function to create the user.
         *
         * @param user The user to create.
         */
        void createUser(User &user);

        /**
         * @brief Public function to check if the user exists.
         *
         * @param user The user to check.
         * @return the status of the user's existence.
         */
        bool checkUser(User &user);

        /**
         * @brief Public function to get the user's ID with his name.
         *
         * @param name The name of the user.
         * @return the user ID.
         */
        uint getUser(const std::string &name);

        /**
         * @brief Public function to get the user's name with his ID.
         *
         * @param id The user ID.
         * @return the user's name.
         */
        std::string getUser(uint id);

        /**
         * @brief Public function to check if the user's name exist.
         *
         * @param name The user's name to check.
         * @return the status of the user's name existence.
         */
        bool checkUserName(const std::string &name);

        /**
         * @brief Public function to add friends to the user.
         *
         * @param id The ID in the database.
         * @param add The number of friends to add.
         * @return the adding status.
         */
        bool addFriends(uint id, uint add);

        /**
         * @brief Public function to remove a user's friend.
         *
         * @param id The ID in the database.
         * @param remove The number of friends to remove.
         * @return the removing status.
         */
        bool removeFriends(uint id, uint remove);
    protected:
    private:
        /**
         * @brief Private function to get the next ID in the database.
         *
         * @return the next ID in the database.
         */
        uint getNextId(void);

        /**
         * @brief Holds the database path.
         *
         * Private property.
         */
        std::string _path;

        /**
         * Holds the database name.
         *
         * Private property.
         */
        std::string _name;

        /**
         * Holds the tree structure to store key/value pairs.
         *
         * Private property.
         */
        boost::property_tree::ptree _tree;
};

#endif /* !DATABASE_HPP_ */
