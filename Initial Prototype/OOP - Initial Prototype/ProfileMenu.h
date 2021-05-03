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
	int IncreaseCredits(int ammount);
private:
	int credits = 0;
};
