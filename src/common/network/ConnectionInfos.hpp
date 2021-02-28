/*
** EPITECH PROJECT, 2020
** B-CPP-500-STG-5-1-babel-leo.seichepine
** File description:
** ConnectionInfos
*/

#ifndef CONNECTIONINFOS_HPP_
#define CONNECTIONINFOS_HPP_

#include <string>

/**
 * Project namespace.
 */
namespace Babel {
    /**
     * @brief Class of connection information.
     *
     * Gives some information about the connection about its port, IP, etc.
     */
    class ConnectionInfos {
        public:
            /**
             * @brief Constructor of ConnectionInfos.
             *
             * @param ip
             * @param port
             */
            ConnectionInfos(const std::string &ip = "0.0.0.0", std::size_t port = 0);

            /**
             * @brief Default destructor of ConnectionInfos.
             */
            ~ConnectionInfos();

            /**
             * @brief Public function to get the IP.
             *
             * Getter method.
             *
             * @return the IP.
             */
            const std::string &getIp(void) const;

            /**
             * @brief Public function to get the port.
             *
             * Getter method.
             *
             * @return the port.
             */
            std::size_t getPort(void) const;

            /**
             * @brief Public function to set the IP.
             *
             * Setter method.
             *
             * @param ip The IP.
             */
            void setIp(const std::string &ip);

            /**
             * @brief Public function to set the port.
             *
             * Setter method.
             *
             * @param port The port.
             */
            void setPort(std::size_t port);

            /**
             * @brief The equality operator between two connection information.
             *
             * @param b The connection information.
             * @return the status of equality.
             */
            bool operator==(const ConnectionInfos &b) const;
        protected:
        private:
            /**
             * @brief The IP of the connexion.
             *
             * Private property.
             */
            std::string _ip;

            /**
             * @brief The port of the connexion.
             *
             * Private property.
             */
            std::size_t _port;
    };
}

#endif /* !CONNECTIONINFOS_HPP_ */