#include "Application.h"

Application::Application() : currentAccount(nullptr), currentUser(nullptr)
{
}

Application::~Application()
{
	for (int i = 0; i < 1; ++i)
	{
		delete accounts[i];
	}
}

bool Application::IsUserLoggedIn() const
{
	return currentUser != nullptr;
}

bool Application::IsAccountLoggedIn() const
{
	return currentAccount != nullptr;
}

Account* Application::GetCurrentAccount() const
{
	return currentAccount;
}

User* Application::GetCurrentUser() const
{
	return currentUser;
}

Player* Application::GetPlayerLibrary()
{
	return playerLibrary;
}

Store& Application::GetStore()
{
	return store;
}

Game* Application::GetSelectedGame() const
{
	return selectedGame;
}

bool Application::SelectGame(const std::string& name)
{
	for (int i = 0; i < 14; i++) 
	{
		if (GetStore().games[i]->GetName() == name)
		{
			selectedGame = GetStore().games[i];
			return true;
		}
	}
	return nullptr;
}

bool Application::LoginAccount(const std::string& email, const std::string& password)
{
	// TODO: This currently always logs you in as the first account
	currentAccount = accounts[0];

	return true;
}

bool Application::LoginUser(const std::string& username, const std::string& password)
{
	std::string curUsername = username;
	std::string curUserPass = password;

	for (int i = 0; i < 3; i++) // TODO: Hardcoded, change when using List<T>
	{
		if (GetCurrentAccount()->users[i]->GetUsername() == username && GetCurrentAccount()->users[i]->GetPassword() == password)
		{
			currentUser = GetCurrentAccount()->users[i];
			return true;
		}
	}
	currentUser = nullptr;
	return false;
}

void Application::LogoutUser()
{
	currentUser = nullptr;
}