/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** Created by Anselin Mackendy-Pierre,
*/

#include "user.hpp"

user::user(): _Name(""), _Ip(""), _Port("")
{}

user::user(std::string name, std::string ip, std::string port): _Name(name), _Ip(ip), _Port(port)
{}

user::~user()
{}

void user::setName(const std::string name)
{
	_Name = name;
}

void user::setIp(const std::string ip)
{
	_Ip = ip;
}

void user::setPort(const std::string port)
{
	_Port = port;
}

std::string user::getName(void)
{
	return (_Name);
}

std::string user::getIp(void)
{
	return (_Ip);
}

std::string user::getPort(void)
{
	return (_Port);
}

bool user::isEmpty(void)
{
	if (_Name.compare("") == 0 && _Ip.compare("") == 0 && _Port.compare("") == 0)
		return (true);
	return (false);
}