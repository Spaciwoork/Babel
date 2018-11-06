/*
**EPITECH PROJECT, 2018
**CPP_babel_2021
**File description:
**Created by Augustin Lopacinski
*/

#include "client/include/Connection.hpp"


ConnectionCode::ConnectionCode(QWidget *parent) : QWidget(parent)
{

}

QString ConnectionCode::EnterInformation()
{
	bool ok = false;
	QString pseudo = QInputDialog::getText(this, "Pseudo", "Quel est votre pseudo ?", QLineEdit::Normal, QString(), &ok);
	if (ok && !pseudo.isEmpty())
	{
		QMessageBox::information(this, "Pseudo ", "Bienvenue !");
	}
	else
	{
		QMessageBox::critical(this, "Pseudo", "Anonymous user ...");
	}
	return pseudo;
}

ConnectionCode::~ConnectionCode()
{
	
}