/*
** EPITECH PROJECT, 2020
** B-CPP-500-STG-5-1-babel-leo.seichepine
** File description:
** ConnectionWidget
*/

#ifndef CONNECTIONWIDGET_HPP_
#define CONNECTIONWIDGET_HPP_

#include "LoginWidget.hpp"
#include "RegisterWidget.hpp"
#include <QtWidgets/QTabWidget>

/** @file
 * @brief Defines the class of the connection widget.
 *
 * Defines its properties and methods.
 */

/**
 * @brief Class of the connection widget.
 *
 * Inherited from AState.
 */
class ConnectionWidget final : public AState
{
    Q_OBJECT
    public:
        /**
         * @brief Constructor of ConnectionWidget.
         *
         * @param parent The widget of the user interface.
         */
        explicit ConnectionWidget(QWidget *parent = nullptr);

        /**
         * @brief Destructor of ConnectionWidget.
         *
         * Removes widgets from the connection widget.
         */
        ~ConnectionWidget();

        /**
         * @brief Function to get widgets of the connection view.
         *
         * Public getter method.
         *
         * @return map of the widgets.
         */
        std::map<std::string, AState *> &getWidgets(void);

        /**
         * @brief Function to get the login widget.
         *
         * Public getter method.
         *
         * @return login widget.
         */
        AState *getLoginWidget(void);

        /**
         * @brief Function to get the register widget.
         *
         * Public getter method.
         *
         * @return register widget.
         */
        AState *getRegisterWidget(void);
    private slots:
    private:
        /**
         * @brief Tab bar widget.
         *
         * Private property.
         */
        QTabWidget *_bar;

        /**
         * @brief Map of the widgets.
         *
         * KEY: textual representation (string)
         * VALUE: widget (AState)
         *
         * Private property.
         */
        std::map<std::string, AState *> _widgets;
};

#endif /* !CONNECTIONWIDGET_HPP_ */