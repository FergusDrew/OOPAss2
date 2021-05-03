#pragma once

#include "Game.h"

class Store
{
	public:
		Store();
		~Store();

		Game* games[14] = { }; // TODO: should be a dynamic collection
	private:

};