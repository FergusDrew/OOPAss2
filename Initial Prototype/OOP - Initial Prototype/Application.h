#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Admin.h"
#include "Utils.h"
#include "Account.h"
#include "User.h"
#include "Player.h"
#include "Store.h"


class Application
{
	public:
		Application();
		~Application();

		void Load();
		bool IsAccountLoggedIn() const;
		bool IsUserLoggedIn() const;
		Account* GetCurrentAccount() const;
		User* GetCurrentUser() const;
		Game* GetSelectedGame() const;
		Store& GetStore();
		
		bool SelectGame(const std::string& name);
		bool LoginAccount(const std::string& email, const std::string& password);
		bool LoginUser(const std::string& username, const std::string& password);
		void LogoutUser();
		std::vector <Account*> accounts;
	private:
		Store store;
		Account* currentAccount;
		User* currentUser;
		Game* selectedGame;
};