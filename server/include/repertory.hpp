/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** Created by Anselin Mackendy-Pierre,
*/

#ifndef REPERTORY_HPP_
#define REPERTORY_HPP_

#include "user.hpp"
#include <vector>

class repertory {
	protected:
		std::vector<user> _UserList;
	public:
		repertory();
		~repertory();
		std::vector<user> getUserList(void);
		void addUser(user);
		void removeUser(std::string);
		bool userExists(std::string);
		user getUser(std::string);
		void editUser(user);
};

#endif /* !REPERTORY_HPP_ */
