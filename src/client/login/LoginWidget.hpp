/*
** EPITECH PROJECT, 2020
** B-CPP-500-STG-5-1-babel-leo.seichepine
** File description:
** LoginWidget
*/

#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QFormLayout>
#include <QRegExpValidator>
#include <iostream>
#include <map>
#include "./../stateMachine/StateMachine.hpp"

/** @file
 * @brief Defines the class of the login widget.
 *
 * Defines its properties and methods.
 */

/**
 * QT Macro
 */
QT_BEGIN_NAMESPACE

/**
 * QT Macro
 */
QT_END_NAMESPACE

/**
 * @brief Class of the login widget.
 *
 * Inherited from AState.
 *
 */
class LoginWidget final : public AState
{
    Q_OBJECT
    public:
        /**
         * @brief Constructor of LoginWidget.
         *
         * @param parent The widget of the user interface.
         */
        explicit LoginWidget(QWidget *parent = nullptr);

        /**
         * @brief Destructor of LoginWidget.
         *
         * Removes components of the login widget.
         */
        ~LoginWidget();

        /**
         * @brief Get the login button.
         *
         * Public getter method.
         *
         * @return the login button.
         */
        QPushButton *getLoginButton(void);

        /**
         * @brief Get the data entered by the user in the forms.
         *
         * Public getter method.
         *
         * @return map of data from the forms.
         */
        std::map<std::string, QLineEdit *> &getFormData(void);
    private slots:
    private:
        /**
         * @brief Form layout.
         *
         * Private property.
         */
        QFormLayout *_formLayout;

        /**
         * @brief Map of the user inputs.
         *
         * KEY: Textual representation.
         * VALUE: User input.
         *
         * Private property.
         */
        std::map<std::string, QLineEdit *> _formLines;

        /**
         * @brief The login button
         *
         * Private property.
         */
        QPushButton *_logButton;
};

#endif // LOGINWIDGET_H
