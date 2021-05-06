#include "GameMenu.h"

GameMenu::GameMenu(const std::string& title, Application* app) : Menu(title, app)
{
	Paint(); // required in constructor
}

void GameMenu::OutputOptions()
{
	Line(app->GetSelectedGame()->GetDescription());
	Line("Costs: \x9C" + Utils::CastToPrice(app->GetSelectedGame()->GetCost()));
	Line();
	Line("Age Rating: " + std::to_string(app->GetSelectedGame()->GetRating()));

	if (app->IsUserLoggedIn())
	{
		Line();
		Line("Account Balance: ");
		Line();
		Option('P', "Purchase Game");
	}
}

bool GameMenu::HandleChoice(char choice)
{
	int index = choice - '1';

	if (index >= 0 && index < 3)
	{

	}
	return false;
}
