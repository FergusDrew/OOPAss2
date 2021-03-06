#pragma once
#include "Menu.h"
#include "Application.h"
#include "MainMenu.h"
#include "Utils.h"
#include "LibraryItem.h"


class ProfileMenu : public Menu
{
public:
	ProfileMenu(const std::string& title, Application* app);
	void OutputOptions() final;
	bool HandleChoice(char choice) final;
	const int IncreaseCredits(int ammount);
	const int ChangeRating(int val, int tempindex);
private:
	//Player* player = dynamic_cast<Player*>(app->GetCurrentUser());
	Player* player = dynamic_cast<Player*>(app->GetCurrentUser());
	//List<LibraryItem*> items = player->getPlayersLibrary();
	//const int credit = 0;
};
