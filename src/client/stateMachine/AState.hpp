/*
** EPITECH PROJECT, 2020
** B-CPP-500-STG-5-1-babel-leo.seichepine
** File description:
** AState
*/

#ifndef ASTATE_HPP_
#define ASTATE_HPP_

#include <QWidget>
#include <QGridLayout>
#include <QMessageBox>

/** @file
 * @brief Defines the abstract class of the application.
 *
 * Defines its properties and methods.
 */

/**
 * @brief Abstract class of the application.
 *
 * Inherited from QWidget.
 *
 */
class AState : public QWidget {
    Q_OBJECT
    public:
        /**
         * @brief Constructor of AState.
         *
         * @param parent The widget of the user interface.
         */
        AState(QWidget *parent = nullptr);

        /**
        * @brief Destructor of AState.
        *
        * Removes components of the application.
        */
        ~AState();

        /**
         * @brief Get the layout of the view.
         *
         * Public getter method.
         *
         * @return A QGridLayout which takes the space made available to it.
         */
        QGridLayout *getLayout(void) const;

        /**
         * @brief Show a message box.
         *
         * Public method.
         *
         * @param txt Text to display.
         */
        void showMessageBox(const std::string &txt);
    protected:
    private:
        /**
         * @brief Layout of the view.
         *
         * Private property.
         */
        QGridLayout *_layout;

        /**
         * @brief Message box component.
         *
         * Private property.
         */
        QMessageBox *_msgBox;
};

#endif /* !ASTATE_HPP_ */