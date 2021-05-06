#include "Player.h"

Player::Player(const std::string& username, const std::string& password, const std::string& created, int credit, const std::string&role) : User(username, password, created), credit(credit), role(role)
{

}

Player::~Player()
{
	library;
}

const int& Player::GetCredit() const
{
	return credit;
}

const std::string& Player::GetRole() const
{
	return role;
}

void Player::AddCredit(int& val)
{
	credit = credit + val;
}

const std::vector <LibraryItem*> Player::getPlayersLibrary() const
{
	return library;
}

std::vector <LibraryItem*> Player::getLibrary() const
{
	return library;
}

void Player::addLibraryItem(LibraryItem* item)
{
	library.push_back(item);
}
//
//bool Player::compareNames(std::string a, std::string b)
//{
//
//}
//
//std::vector <LibraryItem*> Player::sortByDate() const
//{
//
//}
//std::vector <LibraryItem*> Player::sortByName() const
//{
//	for (int i = 0; i < library.size(); i++)
//	{
//		//populate vector of names with each game name
//		std::vector<std::string> nameOrdered;
//		nameOrdered.push_back(library.at(i)->GetGame()->GetName());
//	}
//}