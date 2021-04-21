#include "MainMenu.h"
#include "LoginUserMenu.h"

MainMenu::MainMenu(const std::string& title, Application* app) : Menu(title, app)
{
	Paint(); // required in constructor
}

void MainMenu::OutputOptions()
{
	Option('S', "Browse Store");

	if (app->IsUserLoggedIn())
	{

		Option('P', "View Profile for " + app->GetCurrentUser()->GetUsername());
		Option('L', "Logout of " + app->GetCurrentUser()->GetUsername());
	}
	else
	{
		Option('L', "Login");
	}

	Option('X', "Exit");
}

bool MainMenu::HandleChoice(char choice)
{
	bool wantsToExit = false;
	while (!wantsToExit)
	{
		switch (choice)
		{
		case 'S':
		{
			StoreMenu("STORE", app);
		} break;
		case 'L':
		{
			if (app->IsUserLoggedIn())
			{
				std::string answer = Question("Are you sure?");
				if (answer == "y" || answer == "Y")
				{
					app->LogoutUser();
				}
			}
			else
			{
				// this would need to go to a LoginMenu - similar to StoreMenu
				// instead we just set logged in to true on the main app object
				//LoginUserMenu("Login", app);
				LoginUserMenu("Login", app);
			}
		} break;
		case 'P':
		{
			if (app->IsUserLoggedIn())
			{
				BlockingMessage("Not implemented, press return to continue");
				// this needs to go to a profile page - similar to StoreMenu
				// notice the if - this only works if somebody is logged in
			}
		} break;
		case 'X':
		{
			wantsToExit = true;
			return true;
		} break;

		
		}
		return false;
	}
	
}