#include "LibraryItem.h"

LibraryItem::LibraryItem(const std::string& date, Game* game, int playtime, int rating) : purchased(date), game(game), playtime(playtime), rating(rating)
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
int& LibraryItem::GetRating()
{
	return rating;
}
void LibraryItem::ChangeRating(int& val)
{
	rating = rating + val;
}
