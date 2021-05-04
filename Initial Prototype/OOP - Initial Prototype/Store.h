#pragma once
#include "List.h"
#include "Game.h"

class Store
{
	public:
		Store();
		~Store();
		List<Game*> games;
		//Game* games[14] = { }; // TODO: should be a dynamic collection
	private:

};