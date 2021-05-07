/*
#include "ResultMenu.h"
ResultMenu::ResultMenu(const std::string& title, Application* app) : Menu(title, app)
{
	Paint();
}

void ResultMenu::OutputOptions()
{
	Line("SEARCH RESULTS");

	for (int i = 0; i < app->GetStore().matches.length(); i++)
	{
		Option(i + 1, app->GetStore().matches.getAt(i)->GetName());
	}
}

bool ResultMenu::HandleChoice(char choice)
{
	switch (choice)
	{
	case 'S':
	{
		//ResultMenu("SEARCH GAMES", app);
	} break;
	case 'N':
	{
		
	} break;
	case 'P':
	{
		
	} break;
	}

	int index = choice - '1';
	//if (choice >= '1' || choice <= '5')
	if (choice >= 0 && index < app->GetStore().games.length())
	{
		app->SelectGame(app->GetStore().games.getAt(index)->GetName());
		GameMenu(app->GetStore().games.getAt(index)->GetName(), app);
	}

	return false;
}*/