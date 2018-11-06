/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** Created by Anselin Mackendy-Pierre,
*/

#include <boost/bind.hpp>
#include <signal.h>

#include "server.hpp"

Server::Server () : _Io_service(),
		    _Signals(_Io_service),
		    _Acceptor(_Io_service),
		    _Connection_manager(),
		    _New_connection()
{
	_Addr = "127.0.0.1";
	_Port = "4343";
	runSignals();
	runResolver();
	start_accept();
}

void Server::runSignals ()
{
	_Signals.add(SIGINT);
	_Signals.add(SIGTERM);
#if defined(SIGQUIT)
	_Signals.add(SIGQUIT);
#endif
	_Signals.async_wait(boost::bind(&Server::handle_stop, this));
}

void Server::runService ()
{
	std::cout << "address = " << _Addr << std::endl;
	std::cout << "port = " << _Port << std::endl;
	std::cout << std::endl;
	_Io_service.run();
}


void Server::runResolver ()
{
	boost::asio::ip::tcp::resolver resolver(_Io_service);
	boost::asio::ip::tcp::resolver::query query(_Addr, _Port);
	boost::asio::ip::tcp::endpoint endpoint = *resolver.resolve(query);
	_Acceptor.open(endpoint.protocol());
	_Acceptor.set_option(
		boost::asio::ip::tcp::acceptor::reuse_address(true));
	_Acceptor.bind(endpoint);
	_Acceptor.listen();
}

void Server::start_accept ()
{
	_New_connection.reset(new Connection(_Io_service, _Connection_manager));
	_Acceptor.async_accept(_New_connection->socket(),
			       boost::bind(
				       &Server::handle_accept, this,
				       boost::asio::placeholders::error));
}

void Server::handle_accept (const boost::system::error_code &e)
{
	if (!_Acceptor.is_open())
		return;
	if (!e) {
		_Connection_manager.start(_New_connection);
	}
	start_accept();
}

void Server::handle_stop ()
{
	_Acceptor.close();
	_Connection_manager.stop_all();
	std::cout << "SERVER HAS LEFT" << std::endl;
}