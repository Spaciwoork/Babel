/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** Created by Anselin Mackendy-Pierre,
*/

#include "connection_manager.hpp"
#include "repertory.hpp"
#include "user.hpp"

repertory::repertory()
{}

repertory::~repertory()
{}

std::vector<user> repertory::getUserList(void)
{
	return (_UserList);
}

void repertory::addUser(user usr)
{
	if (userExists(usr.getName()) == false)
		_UserList.push_back(usr);
}

void repertory::removeUser(std::string name)
{
	int i = 0;

	for (auto it = _UserList.begin(); it != _UserList.end(); it++) {
		if (it->getName().compare(name) == 0)
			break;
		i++;
	}
	_UserList.erase(_UserList.begin() + i);
}

bool repertory::userExists(std::string name)
{
	for (auto it = _UserList.begin(); it != _UserList.end(); it++) {
		if (it->getName().compare(name) == 0)
			return (true);
	}
	return (false);
}

user repertory::getUser(std::string name)
{
	for (auto it = _UserList.begin(); it != _UserList.end(); it++) {
		if (it->getName().compare(name) == 0)
			return (*it);
	}
	return (user("", "", ""));
}

void repertory::editUser(user usr)
{
	for (auto it = _UserList.begin(); it != _UserList.end(); it++) {
		if (it->getName().compare(usr.getName()) == 0) {
			it->setName(usr.getName());
			it->setIp(usr.getIp());
			it->setPort(usr.getPort());
		}
	}
}

/*user newUsr;
newUsr.setName("Test");
newUsr.setIp("123");
newUsr.setPort("1337");
addUser(newUsr);
//Debug
for (auto it = _UserList.begin(); it != _UserList.end(); it++) {
	std::cout << it->getName() << std::endl;
}
//Debug

*/