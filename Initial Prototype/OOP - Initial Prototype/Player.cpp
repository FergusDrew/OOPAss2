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

List<LibraryItem*> Player::getLibrary() const
{
	return library;
}

void Player::addLibraryItem(LibraryItem* item)
{
	library.addAtEnd(item);
}