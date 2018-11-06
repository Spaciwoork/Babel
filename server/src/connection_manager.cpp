/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** Created by Anselin Mackendy-Pierre,
*/

#include <algorithm>
#include <boost/bind.hpp>
#include "connection_manager.hpp"

Connection_manager::Connection_manager() : _Repertory()
{}

void Connection_manager::start(_Connection_ptr c)
{
	_Connections.insert(c);
	c->start(&_Repertory);
	std::cout << "NEW CLIENT" << std::endl;
}

void Connection_manager::stop(_Connection_ptr c)
{
	_Connections.erase(c);
	c->stop();
	std::cout << "CLIENT HAS LEFT" << std::endl;
}

void Connection_manager::stop_all()
{
	std::cout << "connection_manager stop_all" << std::endl;
	std::for_each(_Connections.begin(), _Connections.end(),
		      boost::bind(&Connection::stop, _1));
	_Connections.clear();
}