/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** Created by Anselin Mackendy-Pierre,
*/

#ifndef CONNECTION_MANAGER_HPP
#define CONNECTION_MANAGER_HPP

#include <set>
#include <boost/noncopyable.hpp>

#include "connection.hpp"
#include "repertory.hpp"

class Connection_manager : private boost::noncopyable {
	public:
		Connection_manager();
		void start(_Connection_ptr);
		void stop(_Connection_ptr);
		void stop_all();

	private:
		std::set<_Connection_ptr> _Connections;
		repertory _Repertory;
};

#endif /* !CONNECTION_MANAGER_HPP */
