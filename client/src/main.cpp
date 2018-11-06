/*
** EPITECH PROJECT, 2021
** CPP_babel_2021
** File description:
** 
*/

#include "../include/audio.hpp"
#include "../include/CreateWindow.hpp"
#include "../include/clientconnect.hpp"
#include "../include/server.hpp"
#include <QApplication>
#include <iostream>
#include <QPushButton>
#include <stdio.h>
#include <stdlib.h>
#include "portaudio.h"
#include "../include/CreateWindow.hpp"

int main(int argc, char **argv)
{

	QApplication app(argc, argv);

	Client client(CLIENT_SERVER, "127.0.0.1", 4343);
	client.Connection();
	MainWindow Window(&client);
	Window.show();
	return app.exec();
}
