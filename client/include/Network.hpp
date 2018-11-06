/*
**EPITECH PROJECT, 2018
**CPP_babel_2021
**File description:
**Created by Augustin Lopacinski
*/
#ifndef CPP_BABEL_2021_NETWORK_HPP
#define CPP_BABEL_2021_NETWORK_HPP

#include <QObject>
#include <QtNetwork>
#include <QTcpSocket>
#include <QHostAddress>
#include <QWidget>

class TCPClient : public QWidget
{
	Q_OBJECT
	public:
	TCPClient();

	private:

	signals:
	private slots:


};

#endif //CPP_BABEL_2021_NETWORK_HPP
