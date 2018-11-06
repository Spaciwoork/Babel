/*
**EPITECH PROJECT, 2018
**CPP_babel_2021
**File description:
**Created by Augustin Lopacinski
*/
#ifndef CPP_BABEL_2021_CONNECTION_HPP
#define CPP_BABEL_2021_CONNECTION_HPP

#include <QApplication>
#include <QTranslator>
#include <QLocale>
#include <QLibraryInfo>
#include <QMessageBox>
#include <QInputDialog>
#include <QFile>
#include <iostream>

class ConnectionCode : public QWidget
{
	Q_OBJECT

	public:
	ConnectionCode(QWidget *parent = nullptr);
	~ConnectionCode();
	QString EnterInformation();

	protected:
};

#endif //CPP_BABEL_2021_CONNECTION_HPP
