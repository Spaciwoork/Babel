/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** Created by Anselin Mackendy-Pierre,
*/

#ifndef SERVER_HPP
#define SERVER_HPP

#include <iostream>
#include <boost/asio.hpp>
#include <string>
#include <boost/noncopyable.hpp>

#include "connection.hpp"
#include "connection_manager.hpp"

class Server : private boost::noncopyable
{
public:
	Server();
	void	runService();

protected:
	std::string	_Port;
	std::string	_Addr;

	boost::asio::io_service		_Io_service;
	boost::asio::signal_set		_Signals;
	boost::asio::ip::tcp::acceptor	_Acceptor;

	Connection_manager	_Connection_manager;
	_Connection_ptr		_New_connection;

	void		start_accept();
	void		handle_accept(const boost::system::error_code& e);
	void 		handle_stop();
	void		runSignals();
	void		runResolver();
};

#endif /* !SERVER_HPP */
