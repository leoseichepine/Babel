/*
** EPITECH PROJECT, 2020
** B-CPP-500-STG-5-1-babel-leo.seichepine
** File description:
** StateMachine
*/

#ifndef STATEMACHINE_HPP_
#define STATEMACHINE_HPP_

#include "AState.hpp"
#include <QStackedWidget>
#include <map>

/** @file
 * @brief Defines the class of the state of the machine.
 *
 * Defines its properties and methods.
 */

/**
 * @brief Class of the state of the machine.
 *
 * Inherited from QStackedWidget.
 *
 */
class StateMachine : public QStackedWidget {
    Q_OBJECT
    public:
        /**
         * @brief Constructor of StateMachine.
         *
         * @param parent The widget of the user interface.
         */
        StateMachine(QWidget *parent = nullptr);

        /**
         * @brief Destructor of StateMachine.
         *
         */
        ~StateMachine();

        /**
         * @brief Public function to add a state to the machine.
         *
         * @param s The application state to add.
         * @param name The name of the state.
         * @return The adding status.
         */
        bool addState(AState *s, const std::string &name);

        /**
         * @brief Public function to set a state.
         *
         * @param name The name of the state.
         */
        void setState(const std::string &name);

        /**
         * Public function to get a state.
         *
         * @param name The name of the state.
         * @return The application state.
         */
        AState *getState(const std::string &name) const;

        /**
         * Public function to get all the states of the machine.
         *
         * @return A map of application states.
         */
        std::map<std::string, AState *> &getAllStates(void);
    protected:
    private:
        /**
         * @brief Holds the states of the machine in a map.
         *
         * KEY: Name of the state
         * VALUE: Application state
         *
         * Private property.
         *
         */
        std::map<std::string, AState *> _states;
};

#endif /* !STATEMACHINE_HPP_ */