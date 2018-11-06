/*
**EPITECH PROJECT, 2018
**CPP_babel_2021
**File description: CreateWindow
**Created by Augustin Lopacinski
*/

#include <zconf.h>
#include "../include/CreateWindow.hpp"

MainWindow::MainWindow(Client *client, QWidget *parent)
	: QMainWindow(parent)
{
	int state = 0;

	QPalette pal = palette();
	pal.setColor(QPalette::Background, QColor(90, 90 , 90 , 90));
	setAutoFillBackground(true);
	setPalette(pal);
	setFixedSize(1300, 900);
	setWindowTitle("BABEL");
	newPseudo = connect.EnterInformation();
	customWidget = new CustomWidget(this);
	call = new Caller(950, 150, this);
	listUser = new CreateListUser(newPseudo, customWidget);
	addUserButton = new AddUserButton(1100, 150, this);
	state = addUserButton->getState();
	std::cout << state << std::endl;
	quitButton = new QuitButton(600, 600, client, this);
	setCentralWidget(customWidget);
	std::string pseudo = newPseudo.toUtf8().constData();
	std::string preco = "LOGIN ";
	std::string commandLogin = preco + pseudo + "\n\r";
	client->writeData((void*)commandLogin.c_str(), strlen(commandLogin.c_str()));
	client->writeData((void*)"PORT 4242\n\r", strlen("PORT 4242\n\r"));
}

MainWindow::~MainWindow()
{
}
