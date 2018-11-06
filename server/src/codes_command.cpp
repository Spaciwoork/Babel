/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** Created by Anselin Mackendy-Pierre,
*/

#include "codes_command.hpp"

namespace answer_code {

	const std::string ok = "200 OK\r\n";

	const std::string created = "201 Created\r\n";

	const std::string accepted = "202 Accepted\r\n";

	const std::string no_content = "204 No Content\r\n";

	const std::string bad_request = "400 Bad Request\r\n";

	const std::string unauthorized = "401 Unauthorized\r\n";

	const std::string not_found = "404 Not Found\r\n";

	const std::string internal_server_error = "500 Internal Server Error\r\n";

	const std::string service_unavailable = "503 Service Unavailable\r\n";
}

Command::~Command()
{
}

std::string Command::get_answer_code(Code status)
{
	switch (status) {
	case Command::Code::OK:
		return answer_code::ok;
	case Command::Code::CREATED:
		return answer_code::created;
	case Command::Code::ACCEPTED:
		return answer_code::accepted;
	case Command::Code::NO_CONTENT:
		return answer_code::no_content;
	case Command::Code::BAD_REQUEST:
		return answer_code::bad_request;
	case Command::Code::UNAUTHORIZED:
		return answer_code::unauthorized;
	case Command::Code::NOT_FOUND:
		return answer_code::not_found;
	case Command::Code::INTERNAL_SERVER_ERROR:
		return answer_code::internal_server_error;
	case Command::Code::SERVICE_UNVAIBLE:
		return answer_code::service_unavailable;
	default:
		return answer_code::internal_server_error;
	}
}