#pragma once

#include "Game.h"

class LibraryItem
{
	public:
		LibraryItem(const std::string&, Game*);
		~LibraryItem();
		Game* GetGame();
		const std::string& GetPurchaseDate() const;
		const int& GetPlaytime() const;
	private:
		Game *game;
		const std::string purchased;  // TODO: replace with custom Date class, currently YYYY-MM-DD
		int playtime = 0;
};