/*
**EPITECH PROJECT, 2018
**CPP_babel_2021
**File description:
**Created by Augustin Lopacinski
*/

#include "../include/QuitButton.hpp"

QuitButton::QuitButton(int pos_x, int pos_y, Client *client, QWidget *parent)
	: QPushButton(parent)
{
	_client = client;
	setText("Quit");
	move(pos_x, pos_y);
	setFont(QFont("Comic Sans MS", 14));
	setStyleSheet("background-color: dimgrey; color : white;");
	connect(this, SIGNAL(clicked()), this, SLOT(logout()));
}

void QuitButton::logout()
{
	std::cout << "Quit" << std::endl;
	_client->writeData((void*)"LOGOUT", strlen("LOGOUT"));
	QCoreApplication::quit();
}

QuitButton::~QuitButton()
{

}