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

void Player::DecreaseCredit(int& val)
{
	credit = credit - val;
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

void Player::sortByDate()
{
	std::sort(library.begin(), library.end(), [](const LibraryItem* first, const LibraryItem* last)
		{
			return first->GetPurchaseDate() < last->GetPurchaseDate();
		});
}

void Player::sortByName()
{
	std::vector <Game*> names;
	for (int i = 0; i < library.size(); i++)
	{
		names.push_back(library.at(i)->GetGame()); //Populate names vector with games in player library 
	}

	std::sort(names.begin(), names.end(), [](const Game* first, const Game* last)
		{
			return first->GetName() < last->GetName();
		});

	std::vector <LibraryItem*> librarycopy;
	for (int i = 0; i < names.size(); i++)
	{
		if (library.at(i)->GetGame() == names.at(i))
			librarycopy.push_back(library.at(i));
	}

	std::copy(librarycopy.begin(), librarycopy.end(), back_inserter(library));
}
