#pragma once

#include "Game.h"

class LibraryItem
{
	public:
		LibraryItem(const std::string&, Game*, int playtime, int rating);
		~LibraryItem();
		Game* GetGame();
		const std::string& GetPurchaseDate() const;
		int& GetPlaytime();
		int& GetRating();
		void LibraryItem::ChangeRating(int& val);
	private:
		Game *game;
		const std::string purchased;  // TODO: replace with custom Date class, currently YYYY-MM-DD
		int playtime = 0;
		int rating = 0;
};