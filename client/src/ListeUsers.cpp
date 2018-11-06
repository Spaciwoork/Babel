/*
**EPITECH PROJECT, 2018
**CPP_babel_2021
**File description:
**Created by Augustin Lopacinski
*/

#include <QDebug>
#include "client/include/ListeUsers.hpp"

CreateListUser::CreateListUser(QString Pseudo, QWidget *parent) :
		QLabel(parent)
{
	QFont f( "Arial", 30, QFont::Bold);
	setFont( f);
	qDebug() << Pseudo;
	setText("Welcome " + Pseudo);

}

void CreateListUser::Adduser()
{

}

CreateListUser::~CreateListUser()
{

}