/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** Created by Anselin Mackendy-Pierre,
*/

#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include "server.hpp"

int main(int ac, char **av)
{
	(void)ac;
	(void)av;

	Server s;
	s.runService();
	return 0;
}
