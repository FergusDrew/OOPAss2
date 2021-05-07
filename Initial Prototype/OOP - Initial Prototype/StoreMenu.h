#pragma once
#include "Menu.h"
#include "GameMenu.h"
#include "Application.h"
#include "Store.h"
#include <string>
#include <vector>
//#include "SearchMenu.h"

class StoreMenu : public Menu
{
public:
	StoreMenu(const std::string& title, Application* app);
	void OutputOptions() final;
	bool HandleChoice(char choice) final;
private:
	int numOfPages = 0;
	int page = 1;
	//List<std::string> games;
};