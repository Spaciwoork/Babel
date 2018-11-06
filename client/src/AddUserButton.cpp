/*
**EPITECH PROJECT, 2018
**CPP_babel_2021
**File description:
**Created by Augustin Lopacinski
*/


#include "../include/AddUserButton.hpp"

AddUserButton::AddUserButton(int pos_x, int pos_y, QWidget *parent) : QPushButton(parent)
{
	state = 0;
	setText("+");
	move(pos_x, pos_y);
	setFont(QFont("Comic Sans MS", 30));
	setStyleSheet("background-color: grey; color : white;");
	connect(this, SIGNAL(pressed()), this, SLOT (EnterPseudo()));
}

void AddUserButton::EnterPseudo()
{
	serverConnect = new ServerConnect(4242);

	serverConnect->Connection();
	std::cout << "Server created" << std::endl;
}

AddUserButton::~AddUserButton()
{
}

int AddUserButton::getState() const
{
	std::cout << state << std::endl;
	return state;
}

void AddUserButton::setState(int state)
{
	AddUserButton::state = state;
}
