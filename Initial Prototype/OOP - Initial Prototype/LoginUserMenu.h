#pragma once
#include "Menu.h"
#include "MainMenu.h"
#include "Application.h"

class LoginUserMenu : public Menu
{
public: 
	LoginUserMenu(const std::string& title, Application* app);
	void OutputOptions() final;
	bool HandleChoice(char choice) final;
	
private:
	std::string username;
};

