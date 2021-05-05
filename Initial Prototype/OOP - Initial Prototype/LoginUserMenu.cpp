#include "LoginUserMenu.h"

LoginUserMenu::LoginUserMenu(const std::string& title, Application* app) : Menu(title, app)
{
	Paint(); // required in constructor
}

void LoginUserMenu::OutputOptions()
{
	for (int i = 0; i < 3; i++) // TODO: Hardcoded, change when using List<T>
	{
		Option(i + 1, app->GetCurrentAccount()->users.getAt(i)->GetUsername());
	}
}

bool LoginUserMenu::HandleChoice(char choice)
{

	int index = choice - '1';

	if (index >= 0 && index < 3)
	{
		username = app->GetCurrentAccount()->users.getAt(index)->GetUsername();
		std::string answer = Question("Enter password for " + username + ": ");
		if (app->LoginUser(username, answer) == true)
		{
			return true;
		}
		else BlockingMessage("Incorrect Password...Try Again");
	}
	return false;
}
