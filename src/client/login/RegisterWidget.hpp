/*
** EPITECH PROJECT, 2020
** B-CPP-500-STG-5-1-babel-leo.seichepine
** File description:
** RegisterWidget
*/

#ifndef REGISTERWIDGET_HPP_
#define REGISTERWIDGET_HPP_

#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QRegExpValidator>
#include "./../stateMachine/StateMachine.hpp"
#include <map>
#include <iostream>

/** @file
 * @brief Defines the class of the register widget.
 *
 * Defines its properties and methods.
 */

/**
 * @brief Class of the register widget.
 *
 * Inherited from AState.
 *
 */
class RegisterWidget final : public AState
{
    Q_OBJECT
    public:
        /**
         * @brief Constructor of RegisterWidget.
         *
         * @param parent The widget of the user interface.
         */
        explicit RegisterWidget(QWidget *parent = nullptr);

        /**
         * @brief Destructor of RegisterWidget.
         *
         * Removes components of the register widget.
         */
        ~RegisterWidget();

        /**
         * @brief Get the register button.
         *
         * Public getter method.
         *
         * @return the register button.
         */
        QPushButton *getRegisterButton(void);

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
         * @brief The register button.
         *
         * Private property.
         */
        QPushButton *_regButton;
};

#endif /* !REGISTERWIDGET_HPP_ */