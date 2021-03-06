#pragma once

#include <string>
#include "Player.h"
#include "date.h"

class Account
{
public:
	Account(const std::string&, const std::string&, const std::string&);
	~Account();
	List<User*> users;
	const std::string& GetEmail() const;
	const std::string& GetPassword() const;
	const std::string& GetCreated() const;

private:
	std::string email;
	std::string password;
	Date m;
	std::string created = m.SplitDate(created);
};
