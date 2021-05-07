/*
#include "SearchMenu.h"

SearchMenu::SearchMenu(const std::string& title, Application* app) : Menu(title, app)
{
	Paint();
}

void SearchMenu::OutputOptions()
{
	Line("SEARCHING: " + std::to_string(app->GetStore().games.length()) + "-GAMES");
	Option('N', "By Name");
	Option('P', "By Price");
}

bool SearchMenu::HandleChoice(char choice)
{
	switch (choice)
	{
	case 'N':
	{
		std::string answer = Question("Enter the game name");
		app->GetStore().SearchName(answer);
		ResultsMenu("FOUND GAMES", app);
	} break;
	case 'P':
	{
		std::string answer = Question("Enter the game price");
	} break;
	}

	return false;
}*/