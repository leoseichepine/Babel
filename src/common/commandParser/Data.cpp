/*
** EPITECH PROJECT, 2020
** db
** File description:
** Data
*/

#include "Data.hpp"

/** @file
 * @brief Defines the data request.
 *
 * Sets its methods.
 */

Data::Data(uint code, const std::string &data) : _code(code), _req(data)
{}

Data::Data(uint code, const std::vector<std::string> &data) : _code(code), _data(data)
{}

Data::Data(uint code) : _code(code)
{}

Data::Data(const std::string &data): _req(data)
{
}

Data::Data()
{}

Data::~Data()
{}

void Data::setCode(uint code) {
    _code = code;
}

void Data::pushBack(const std::string &data) {
    _data.push_back(data);
}

uint Data::getCode()const {
    return _code;
}
const std::vector<std::string> Data::getData()const {
    return _data;
}

const std::string Data::getReq() {
    convertData();
    return std::to_string(_code) + "|" + _req;
}

void Data::convertData() {
    if (_data.size() == 0)
        return;
    for (std::size_t i = 0; i < _data.size(); i++) {
        _req += _data[i];
        if (i < _data.size() - 1)
            _req += ",";
    }
    _req += "\r\n";
}