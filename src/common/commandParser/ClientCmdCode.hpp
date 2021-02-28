/*
** EPITECH PROJECT, 2020
** B-CPP-500-STG-5-1-babel-leo.seichepine
** File description:
** ClientCmdCode
*/

#ifndef CLIENTCMDCODE_HPP_
#define CLIENTCMDCODE_HPP_

/** @file
 * @brief Defines the client code.
 *
 * Defines its associated enum.
 */

/**
 * @brief Namespace of the client code.
 */
namespace ClientCode {
    /**
     * @brief Enum which defines the client code.
     *
     * Client's action.
     */
    typedef enum {
        CREATE = 0,
        DELETE = 1,
        LOGIN = 2,
        LOGOUT = 3,
        START_CALL = 4,
        ANSWER_CALL = 5,
        END_CALL = 6,
        ADD_CONTACT = 7,
        REMOVE_CONTACT = 8,
        MESSAGE = 9,
        PING = 10,
        PONG = 11,
    } cmdCode_t;
};

#endif /* !CLIENTCMDCODE_HPP_ */
