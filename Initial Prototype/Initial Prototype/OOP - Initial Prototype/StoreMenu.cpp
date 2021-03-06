#include "StoreMenu.h"
#include <math.h> //ceil

StoreMenu::StoreMenu(const std::string& title, Application* app) : Menu(title, app)
{
	Paint(); // required in constructor
}

void StoreMenu::OutputOptions()
{
	if (sizeof(app->GetStore().games) / sizeof(app->GetStore().games[0]) >= 6)
	{
		//Calculate number of pages needed
		int numOfGames = (sizeof(app->GetStore().games) / sizeof(app->GetStore().games[0]));
		double i = (numOfGames % 5);
		int numOfPages = ceil(i) - 1;
		//set current page at 1
		//array items to be displayed
		int x = page * 5;
		for (int i = 0; i < 5; i++)
		{
			if (x >= numOfGames)
			{
				Line();
			}
			else
			{
				Option(i + 1, app->GetStore().games[x]->GetName());
				x++;
			}
		}
		Line();
		Line("PAGE " + std::to_string(page + 1) + " OF " + std::to_string(numOfPages));
		Option('S', "Search");
		if (page < numOfPages - 1) Option('N', "Next Page");
		if (page >= 1) Option('P', "Previous Page");
	}
	else
	{
		for (int i = 0; i < sizeof(app->GetStore().games) / sizeof(app->GetStore().games[0]); i++)
		{
			// adding 1 so the display is nicer for the user
			Option(i + 1, app->GetStore().games[i]->GetName());
		}
	}
}

bool StoreMenu::HandleChoice(char choice)
{
	// since we are using numbers here we shift the char down by '1'
	// this puts '1' as 0, '2' as 1, '3' as 2, '4' as 3, etc.
	// this reverses the + 1 above and lets us do the range check below
	int index = choice - '1';
	if (index >= 0 && index < sizeof(app->GetStore().games) / sizeof(app->GetStore().games[0]))
	{
		index = index + (5 * page);
		app->SelectGame(app->GetStore().games[index]->GetName());
		GameMenu(app->GetStore().games[index]->GetName(), app);
	}

	switch (choice)
	{
	case 'S':
	{
		BlockingMessage("Not implemented, press return to continue");
		//SearchGames
	} break;
	case 'N':
	{
		page++;
	} break;
	case 'P':
	{
		page--;
	} break;
	}


	return false;
}