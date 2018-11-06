/*
**EPITECH PROJECT, 2018
**CPP_babel_2021
**File description:
**Created by Augustin Lopacinski
*/
#ifndef CPP_BABEL_2021_ADDUSERBUTTON_H
#define CPP_BABEL_2021_ADDUSERBUTTON_H

#include <QtWidgets/QMessageBox>
#include <QtWidgets/QInputDialog>
#include <QtWidgets/QPushButton>
#include <QApplication>
#include "serverconnect.hpp"
#include <iostream>

class AddUserButton : public QPushButton
{
	Q_OBJECT
	public:
	AddUserButton(int, int, QWidget *);
	~AddUserButton();

	public slots:
	void EnterPseudo();

	protected:
	ServerConnect *serverConnect;
	int state;
	public:
	int getState() const;

	void setState(int state);
};

#endif //CPP_BABEL_2021_ADDUSERBUTTON_H
