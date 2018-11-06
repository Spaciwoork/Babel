/*
**EPITECH PROJECT, 2018
**CPP_babel_2021
**File description:
**Created by Augustin Lopacinski
*/

#ifndef CPP_BABEL_2021_CREATEBUTTON_HPP
#define CPP_BABEL_2021_CREATEBUTTON_HPP

#include <vector>
#include <iostream>
#include <QApplication>
#include <QPushButton>
#include <QWidget>
#include <QFont>
#include <QIcon>
#include <QObject>
#include "clientconnect.hpp"

class QuitButton : public QPushButton
{
	Q_OBJECT

	public:
	QuitButton(int, int, Client *, QWidget *parent = 0);
	~QuitButton();

	protected:
	Client *_client;

	public slots:
	void logout();
};

#endif //CPP_BABEL_2021_CREATEBUTTON_HPP
