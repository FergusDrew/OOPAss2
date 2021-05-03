#include "LibraryItem.h"

LibraryItem::LibraryItem(const std::string& date, Game* game) : purchased(date), game(game)
{
}

LibraryItem::~LibraryItem()
{
}

Game* LibraryItem::GetGame() 
{
	return game;
}

const std::string& LibraryItem::GetPurchaseDate() const
{
	return purchased;
}

const int& LibraryItem::GetPlaytime() const
{
	return playtime;
}