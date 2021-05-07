#pragma once
#include "List.h"
#include "Game.h"
#include "Utils.h"

class Store
{
	public:
		Store();
		~Store();
		List<Game*> games;
		void SearchName(std::string& searchdata);
		List<Game*> SearchPrice(std::string& searchdata);
		List<Game*> matches;
	private:

};