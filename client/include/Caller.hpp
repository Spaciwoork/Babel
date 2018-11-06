/*
**EPITECH PROJECT, 2018
**CPP_babel_2021
**File description:
**Created by Augustin Lopacinski
*/
#ifndef CPP_BABEL_2021_CALL_HPP
#define CPP_BABEL_2021_CALL_HPP

#include <client/include/clientconnect.hpp>
#include <QtWidgets/QPushButton>
#include <iostream>

class Caller : public QPushButton
{
	Q_OBJECT
	public:
	Caller(int, int, QWidget *);
	~Caller();


	public slots:
	void StartCall();

	protected:
	Client *client;
	Client *request_call;
};

#endif //CPP_BABEL_2021_CALL_HPP
