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
		for (int i = 0; i < player->getLibrary().size(); i++)
		{
			if (app->GetSelectedGame()->GetId() == player->getLibrary().at(i)->GetGame()->GetId())
			{
				isOwned = true;
			}
			else isOwned = false;
		}
		if (tooExpensive == true)
		{
			Line();
			Line("Insufficient funds");
			Line();
		}
		if (isOwned == true)
		{
			Line();
			Line("Game Already Owned");
			Line();
		}

		Line();
		Line("Account Balance: " + Utils::CastToCredit(player->GetCredit()));
		Line();
		Option('P', "Purchase Game");
	}
}

bool GameMenu::HandleChoice(char choice)
{
	switch (choice)
	{
	case 'P':
	{
		if (!isOwned)
		{
			Date* date = new Date;
			std::string currDate = date->currentDate();

			int i = app->GetSelectedGame()->GetId();
			Game* game = app->GetStore().games.getAt(i);
			LibraryItem* item = new LibraryItem(currDate, game, 0);
			int price = app->GetSelectedGame()->GetCost();
			if (player->GetCredit() < price)
			{
				tooExpensive = true;
			}
			else
			{
				player->DecreaseCredit(price);
				player->addLibraryItem(item);
				tooExpensive = false;
			}
			
		}
	} break;
	}

	return false;
}