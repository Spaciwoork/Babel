/*
**EPITECH PROJECT, 2018
**CPP_babel_2021
**File description:
**Created by Augustin Lopacinski
*/

#ifndef CPP_BABEL_2021_CREATEWINDOW_HPP
#define CPP_BABEL_2021_CREATEWINDOW_HPP

#include <QApplication>
#include <QPushButton>
#include <QWidget>
#include <QFont>
#include <QIcon>
#include <QMainWindow>
#include "QuitButton.hpp"
#include "CustomWidget.hpp"
#include "Connection.hpp"
#include "ListeUsers.hpp"
#include "AddUserButton.hpp"
#include "clientconnect.hpp"
#include "serverconnect.hpp"
#include "Caller.hpp"
#include <QObject>

class MainWindow : public QMainWindow
{
	public:
	MainWindow(Client *, QWidget *parent = 0);
	~MainWindow();

	private:
	AddUserButton *addUserButton;
	CustomWidget *customWidget;
	QuitButton *quitButton;
	QString newPseudo;
	Caller *call;
	ConnectionCode connect;
	CreateListUser *listUser;
};

#endif //CPP_BABEL_2021_CREATEWINDOW_HPP

