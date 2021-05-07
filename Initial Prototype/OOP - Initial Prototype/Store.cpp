#include "Store.h"

Store::Store()
{

}

Store::~Store()
{
	for (int i = 0; i < 12; ++i)
	{
		games;
	}
}

void Store::SearchName(std::string& searchdata)
{
	std::string search = Utils::toLower(searchdata);
	for (int i = 0; i < games.length(); i++)
	{
		std::string name = Utils::toLower(games.getAt(i)->GetName());
		if (Utils::contains(name, search)) 
		{
			matches.addAtEnd(games.getAt(i));
		}
	}
}

List<Game*> Store::SearchPrice(std::string& searchdata)
{
	return matches;
}
