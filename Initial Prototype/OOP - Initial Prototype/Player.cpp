#include "Player.h"
Player::Player(const std::string& username, const std::string& password, const std::string& created, int credit, std::string role) : User(username, password, created)
{

}

Player::~Player()
{
	for (int i = 0; i < 2; ++i)
	{
		library;
	}
}

/*const int& Player::GetCredit() const
{
	return credit;
}

const std::string& Player::GetRole() const
{
	return role;
}*/

List<LibraryItem*> Player::getLibrary() const
{
	return library;
}