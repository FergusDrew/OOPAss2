#pragma once
#include "Menu.h"
#include "GameMenu.h"
#include "Application.h"
#include "Store.h"
#include <string>
#include <vector>

class StoreMenu : public Menu
{
public:
	StoreMenu(const std::string& title, Application* app);
	void OutputOptions() final;
	bool HandleChoice(char choice) final;
private:
	int page = 0;
	//std::string games[9] = {};
	//std::vector<std::string> games = { "Factorio", "The Witness", "INSIDE", "Brothers" };
};