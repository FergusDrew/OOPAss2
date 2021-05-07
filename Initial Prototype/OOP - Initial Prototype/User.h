#pragma once

#include <string>
#include "date.h"

class User
{
	public:
		User();
		User(const std::string&, const std::string&, const std::string&);
		virtual ~User();
		const std::string& GetUsername() const;
		const std::string& GetPassword() const;
		const std::string& GetCreated() const;
		virtual const int& GetCredit() const = 0;
		virtual const std::string& GetRole() const = 0
			;
		
	private:
		Date m;
		std::string username;
		std::string password;
		std::string created = m.SplitDate(created);
			
};