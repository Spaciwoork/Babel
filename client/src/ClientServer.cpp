/*
**EPITECH PROJECT, 2018
**CPP_babel_2021
**File description:
**Created by Augustin Lopacinski
*/

#include "client/include/ClientServer.hpp"

ClientServer::ClientServer(QWidget *parent) : QWidget(parent)
{
	etatServer = new QLabel;
	buttonQuitter = new QPushButton(tr("Quitter"));
	connect(buttonQuitter, SIGNAL(clicked()), qApp, SLOT(quit()));
	QVBoxLayout *layout = new QVBoxLayout;

	layout->addWidget(etatServer);

	layout->addWidget(buttonQuitter);
	serveur = new QTcpServer(this);
	std::cout << "test" << std::endl;
	if (!serveur->listen(QHostAddress::Any, 50885)) {
		std::cout << "Nop" << std::endl;
		etatServer->setText(
			tr("Le serveur n'a pas pu être démarré. Raison :<br />") +
				serveur->errorString());
	}
	else {
		etatServer->setText(
			tr("Le serveur a été démarré sur le port <strong>") +
				QString::number(serveur->serverPort()) +
				tr("</strong>.<br />Des clients peuvent maintenant se connecter."));
		connect(serveur, SIGNAL(newConnection()), this,
			SLOT(nouvelleConnexion()));
	}
	tailleMessage = 0;
	std::cout << "Gros" << std::endl;
}

void ClientServer::nouvelleConnexion()
{
	QTcpSocket *nouveauClient = serveur->nextPendingConnection();
	clients << nouveauClient;

	//connect(nouveauClient, SIGNAL(readyRead()), this, SLOT(donneesRecues()));
	//connect(nouveauClient, SIGNAL(disconnected()), this, SLOT(deconnexionClient()));
}