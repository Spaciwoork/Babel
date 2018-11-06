/*
**EPITECH PROJECT, 2018
**CPP_babel_2021
**File description:
**Created by Augustin Lopacinski
*/
#ifndef CPP_BABEL_2021_CLIENTSERVER_HPP
#define CPP_BABEL_2021_CLIENTSERVER_HPP

#include <QtWidgets/QWidget>
#include <QtWidgets/QLabel>
#include <QtNetwork>
#include <QPushButton>
#include <QtNetwork/QTcpServer>
#include <QVBoxLayout>
#include <iostream>

class ClientServer : public QWidget
{
	Q_OBJECT

	public:
	ClientServer(QWidget *parent = nullptr);


	private slots:
	void nouvelleConnexion();


	private:
	QLabel *etatServer;
	QPushButton *buttonQuitter;

	QTcpServer *serveur;

	QList<QTcpSocket *> clients;

	quint16 tailleMessage;
};

#endif //CPP_BABEL_2021_CLIENTSERVER_HPP
