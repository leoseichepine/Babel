/*
** EPITECH PROJECT, 2020
** db
** File description:
** Data
*/

#ifndef DATA_HPP_
#define DATA_HPP_

#include <iostream>
#include <vector>
#include <string>
#include "ClientCmdCode.hpp"

/** @file
 * @brief Defines the class of data request.
 *
 * Defines its properties and methods.
 */

/**
 * @brief Class of the data request.
 */
class Data {
    public:
        /**
         * @brief Overloaded constructor of Data.
         *
         * @param code The code of the request.
         * @param data The data request.
         */
        Data(uint code, const std::string &data);

        /**
         * @brief Overloaded constructor of Data.
         *
         * @param code The code of the request.
         * @param data The sequence container of the data request.
         */
        Data(uint code, const std::vector<std::string> &data);

        /**
         * @brief Overloaded constructor of Data.
         *
         * @param code The code of the request.
         */
        Data(uint code);

        /**
         * @brief Overloaded constructor of Data.
         *
         * @param data The data request.
         */
        Data(const std::string &data);

        /**
         * @brief Default constructor of Data.
         */
        Data();

        /**
         * @brief Destructor of Data.
         */
        ~Data();

        /**
         * @brief Public function to push back a data request.
         *
         * @param data The data request.
         */
        void pushBack(const std::string& data);

        /**
         * @brief Public function to get the request code.
         *
         * Getter method.
         *
         * @return the request code.
         */
        uint getCode()const;

        /**
         * @brief Public function to get the request.
         *
         * Getter method.
         *
         * @return the request.
         */
        const std::string getReq();

        /**
         * @brief Public function to convert data.
         */
        void convertData();

        /**
         * @brief Public function to get the data.
         *
         * Getter method.
         *
         * @return the data.
         */
        const std::vector<std::string> getData()const;

        /**
         * @brief Public function to set the request code.
         *
         * Setter method.
         *
         * @param code the request code.
         */
        void setCode(uint code);
    private:
        /**
         * @brief The request code.
         *
         * Private property.
         */
        uint _code;

        /**
         * @brief The sequence container of the data.
         *
         * Private property.
         */
        std::vector<std::string> _data;

        /**
         * @brief The sequence container of the request.
         *
         * Private property.
         */
        std::string _req;
};
#endif /* !DATA_HPP_ */
