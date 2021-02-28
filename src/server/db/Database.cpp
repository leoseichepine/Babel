/*
** EPITECH PROJECT, 2020
** db
** File description:
** Database
*/

#include "Database.hpp"

/** @file
 * @brief Defines the database.
 *
 * Sets the database methods.
 */

Database::Database(const std::string &path, const std::string &name) :
_path(path), _name(name)
{
    std::ifstream file(_path + _name);
    if (file) {
        boost::property_tree::read_json(_path + _name, _tree);
        boost::property_tree::ptree backup = _tree;
        boost::property_tree::write_json(_path + "backup.json", backup);
    } else
        setupDB();
}

Database::~Database()
{
    boost::property_tree::write_json(_path + _name, _tree);
    std::string backup = _path + "backup.json";
    std::remove(backup.c_str());
}

void Database::setupDB() {
    _tree.put(fieldName[NEXT_ID], 1);
    boost::property_tree::write_json(_path + _name, _tree);
}

uint Database::getNextId(void) {
    uint val = _tree.get<uint>(fieldName[NEXT_ID]);
    _tree.get_child(fieldName[NEXT_ID]).put_value(val + 1);
    return val;
}

uint Database::getId() {
    return _tree.get<uint>(fieldName[NEXT_ID]);
}

bool Database::addFriends(uint id, uint add) {
    for (std::size_t i = 0; i < getId(); i++) {
        std::string search = fieldName[USER] + std::to_string(i);
        try {
            if (_tree.get<uint>(search + "." + fieldName[ID]) == id) {
                auto fl = _tree.get<std::string>(search + "." + fieldName[FRIENDS]);
                if (fl.find("[" + std::to_string(add) + "]") != std::string::npos)
                    return false && addFriends(add, id);
                std::string val = _tree.get<std::string>(search + "." + fieldName[FRIENDS]);
                _tree.get_child(search + "." + fieldName[FRIENDS]).put_value(val + "[" + std::to_string(add) + "]" );
                return true && addFriends(add, id);
            }
        }
        catch(const boost::exception &e) {}
    }
    return false;
}

bool Database::removeFriends(uint id, uint remove) {
    for (std::size_t i = 0; i < getId(); i++) {
        std::string search = fieldName[USER] + std::to_string(i);
        try {
            if (_tree.get<uint>(search + "." + fieldName[ID]) == id) {
                auto fl = _tree.get<std::string>(search + "." + fieldName[FRIENDS]);
                std::string match = "[" + std::to_string(remove) + "]";
                auto pos = fl.find(match);
                if (pos == std::string::npos)
                    return false && removeFriends(remove, id);
                std::string val = _tree.get<std::string>(search + "." + fieldName[FRIENDS]);
                val.erase(pos, match.size());
                _tree.get_child(search + "." + fieldName[FRIENDS]).put_value(val);
                return true && removeFriends(remove, id);
            }
        }
        catch(const boost::exception &e) {}
    }
    return false;
}

void Database::createUser(User &user) {
    boost::property_tree::ptree nuser;
    uint id = getNextId();
    nuser.put(fieldName[ID], id);
    nuser.put(fieldName[NAME], user.getName());
    nuser.put(fieldName[PASSWORD], user.getPass());

    boost::property_tree::ptree friends;
    friends.put("", "");
    nuser.add_child(fieldName[FRIENDS], friends);

    std::string name = fieldName[USER] + std::to_string(id);
    _tree.push_back(std::make_pair(name, nuser));
}

uint Database::getUser(const std::string &name) {
    for (std::size_t i = 0; i < getId(); i++) {
        std::string match = fieldName[USER] + std::to_string(i) + ".";
        try {
            if (_tree.get<std::string>(match + fieldName[NAME]) == name)
                return _tree.get<uint>(match + fieldName[ID]);
        }
        catch(const boost::exception &e) {}
    }
    return 0;
}

std::string Database::getUser(uint id) {
    for (std::size_t i = 0; i < getId(); i++) {
        std::string match = fieldName[USER] + std::to_string(i) + ".";
        try {
            if (_tree.get<uint>(match + fieldName[ID]) == id)
                return _tree.get<std::string>(match + fieldName[NAME]);
        }
        catch(const boost::exception &e) {}
    }
    return "";
}

bool Database::checkUser(User &user) {
    for (std::size_t i = 0; i < getId(); i++) {

        try {
            if (User(_tree.get<std::string>(fieldName[USER] + std::to_string(i) + "." + fieldName[NAME]),
                _tree.get<std::string>(fieldName[USER] + std::to_string(i) + "." + fieldName[PASSWORD])) == user)
                return true;
        }
        catch(const boost::exception &e) {}
    }
    return false;
}

bool Database::checkUserName(const std::string &name) {
    for (std::size_t i = 0; i < getId(); i++) {

        try {
            if (_tree.get<std::string>(fieldName[USER] + std::to_string(i) + "." + fieldName[NAME]) == name)
                return true;
        }
        catch(const boost::exception &e) {}
    }
    return false;
}