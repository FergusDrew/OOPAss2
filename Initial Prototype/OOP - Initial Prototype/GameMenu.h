#pragma once
#include "Menu.h"
#include "Utils.h"
#include "Date.h"
#include "Application.h"

class GameMenu : public Menu
{
public:
	GameMenu(const std::string& title, Application* app);
	void OutputOptions() final;
	bool HandleChoice(char choice) final;

	
private:
	Player* player = dynamic_cast<Player*>(app->GetCurrentUser());
	bool isOwned;
};

