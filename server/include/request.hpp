/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** Created by Anselin Mackendy-Pierre,
*/

#ifndef RESQUEST_HPP
#define RESQUEST_HPP

#include <string>
#include <vector>
#include <iostream>

#include "codes_command.hpp"

class Request
{
public:
	std::string analyse();
	std::string connect();
	~Request();
	Command		_Cmd;
};

#endif /* !RESQUEST_HPP */
