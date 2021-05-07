#include "LibraryItem.h"

LibraryItem::LibraryItem(const std::string& date, Game* game, int playtime) : purchased(date), game(game), playtime(playtime)
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

int& LibraryItem::GetPlaytime()
{
	return playtime;
}