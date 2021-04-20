#pragma once
#include "Menu.h"
#include "Utils.h"
#include "MainMenu.h"

class LoginUserMenu : public Menu
{
public: 
	LoginUserMenu(const std::string& title, Application* app);
	void OutputOptions() final;
	bool HandleChoice(char choice) final;
	
private:
	bool CheckUsername(std::string& username);
	bool CheckPassword(std::string& password);
	std::string username;
	std::string password;
};

