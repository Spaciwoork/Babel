/*
**EPITECH PROJECT, 2018
**CPP_babel_2021
**File description:
**Created by Augustin Lopacinski
*/
#ifndef CPP_BABEL_2021_LISTEUSERS_HPP
#define CPP_BABEL_2021_LISTEUSERS_HPP

#include <QLabel>
#include <QMainWindow>
#include <QApplication>
#include <QPushButton>
#include <QWidget>
#include <QFont>
#include <QIcon>
#include <QObject>
#include "CustomWidget.hpp"

class CreateListUser : public QLabel
{
	public:
	CreateListUser(QString, QWidget *parent);
	~CreateListUser();
	void Adduser();

	private:


};

#endif //CPP_BABEL_2021_LISTEUSERS_HPP
