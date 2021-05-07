#pragma once
#include "Menu.h"
#include "Store.h"
class ResultsMenu : public Menu
{
public:
	ResultsMenu(const std::string& title, Application* app);
	void OutputOptions() final;
	bool HandleChoice(char choice) final;
private:
	
};

