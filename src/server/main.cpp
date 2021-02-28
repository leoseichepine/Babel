/*
** EPITECH PROJECT, 2020
** server
** File description:
** main
*/

#include "Server.hpp"

/** @file
 * @brief Entry point of the server.
 *
 * Declares the main function.
 */

/**
 * Function to display the usage message.
 *
 * @param ret The return status.
 * @return the displaying status.
 */
int usage(int ret)
{
    std::cout << "Babel Server:" << std::endl;
    std::cout << "\tServer for VOIP Application Babel" << std::endl;
    std::cout << "Usage:\tbabel_server [port]" << std::endl;
    std::cout << "[port] : Optionnal. Listening port for the server, if none, default is 42042" << std::endl;
    return ret;
}

/**
 * @brief Entry point of the server.
 *
 * Main function.
 *
 * @param ac Number of arguments.
 * @param av List of arguments.
 * @return the entry point status.
 */
int main(int ac, char **av)
{
    if (ac == 2 && (std::string(av[1]) == "-h" || std::string(av[1]) == "--help"))
        return usage(0);
    else if (ac > 2)
        return (usage(84));
    else {
        try {
            boost::asio::io_service ios;
            Babel::Server serv(ios);
            ios.run();
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
            return 84;
        }
    }
    return 0;
}