#pragma once
#include "Menu.h"
#include "Utils.h"

class GameMenu : public Menu
{
public:
	GameMenu(const std::string& title, Application* app);
	void OutputOptions() final;
	bool HandleChoice(char choice) final;

private:

};

