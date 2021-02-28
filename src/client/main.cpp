/*
** EPITECH PROJECT, 2020
** server
** File description:
** main
*/

#include <QtWidgets/QApplication>
#include "MainWindow.hpp"

/** @file
 * @brief Entry point of the client.
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
    std::cout << "Babel_client:" << std::endl;
    std::cout << "\tClient for VOIP Application Babel" << std::endl;
    std::cout << "Usage:\tbabel_client" << std::endl;
}

/**
 * @brief Entry point of the client.
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
    QApplication a(ac, av);
    MainWindow mainWindow;

    mainWindow.show();
    return a.exec();
}