#include "Account.h"

Account::Account(const std::string& email, const std::string& password, const std::string& created)
	: email(email), password(password), created(created)
{
}

Account::~Account()
{
	users;
}

const std::string& Account::GetEmail() const
{
	return email;
}

const std::string& Account::GetPassword() const
{
	return password;
}


const std::string& Account::GetCreated() const
{


	return created;
}