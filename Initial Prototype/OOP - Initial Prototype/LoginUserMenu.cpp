#include "LoginUserMenu.h"

LoginUserMenu::LoginUserMenu(const std::string& title, Application* app) : Menu(title, app)
{
	Paint(); // required in constructor
}

void LoginUserMenu::OutputOptions()
{
	Option(' ', "Enter Username");
}

bool LoginUserMenu::HandleChoice(char choice)
{
	LoginUserMenu::username == Utils::GetLineFromUser();
	if (CheckPassword(username) == true)
	{
		std::string answer = Question("Enter Password");
		LoginUserMenu::password == answer;
		if (CheckPassword(password) == true)
		{
			app->LoginUser(username, password);
			MainMenu("Main Menu", app);
		}
		else BlockingMessage("Incorrect Password");
	}
	else BlockingMessage("Incorrect Username");

	return false;
}

bool LoginUserMenu::CheckUsername(std::string& username)
{
	//Run a check of the username against a list of usernames stored in the user class
	return true;
}

bool LoginUserMenu::CheckPassword(std::string& password)
{
	//Run a check of the password against a list of passwords stored in the user class
	return true;
}