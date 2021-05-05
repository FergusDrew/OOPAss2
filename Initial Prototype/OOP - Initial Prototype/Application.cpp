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

void Application::Load()
{
	int i;
	ifstream data("data.txt");
	string line;

	while (getline(data, line))
	{
		if (line == "GAME")
		{
			int id;
			string name;
			string desc;
			int price;
			int ageRating;

			for (i = 0; i < 5; i++)
			{
				getline(data, line);
				switch (i)
				{
				case 0:
					id = stoi(line);
					break;
				case 1:
					name = line;
					break;
				case 2:
					desc = line;
					break;
				case 3:
					price = stoi(line);
					break;
				case 4:
					ageRating = stoi(line);
					break;
				default:
					break;
				}
			}
			GetStore().games.addAtEnd(new Game(id, name, desc, price, ageRating));
		}
		else if (line == "ACCOUNT")
		{
			string date;
			string email;
			string password;
			for (i = 0; i < 3; i++)
			{
				getline(data, line);
				switch (i)
				{
				case 0:
					date = line;
					break;
				case 1:
					email = line;
					break;
				case 2:
					password = line;
					break;
				default:
					break;
				}
			}
			accounts.push_back(new Account(email, password, date));
			LoginAccount(email, password);
		}
		else if (line == "ACCOUNT-PLAYER")
		{
			string date;
			string username;
			string password;
			int credit = 0;
			string role = "Player";

			int user;

			for (i = 0; i < 4; i++)
			{
				getline(data, line);
				switch (i)
				{
				case 0:
					date = line;
					break;
				case 1:
					username = line;
					break;
				case 2:
					password = line;
					break;
				case 3:
					credit = stoi(line);
					break;
				default:
					break;
				}
			}

			if (accounts.at(0)->users.isEmpty() == true)
			{
				Player* u1 = new Player(username, password, date, credit, role);
				accounts.at(0)->users.addInFront(u1);
				user = 0;
			}
			else if (accounts.at(0)->users.getAt(0) == nullptr)
			{
				Player* u2 = new Player(username, password, date, credit, role);
				accounts.at(0)->users.addAtPos(1, u2);
				user = 1;
			}
			else
			{
				Player* u3 = new Player(username, password, date, credit, role);
				accounts.at(0)->users.addAtEnd(u3);
				user = 2;
			}


			if (line == "LIBRARY-ITEM")
			{
				while (line != "ACCOUNT-PLAYER" || line != "ACCOUNT-ADMIN")
				{
					int id;
					string date;
					int playTime;

					for (i = 0; i < 3; i++)
					{
						getline(data, line);
						switch (i)
						{
						case 0:
							id = stoi(line);
							break;
						case 1:
							date = line;
							break;
						case 2:
							playTime = stoi(line);
							break;
						default:
							break;
						}
					}
					//GetStore().games.addAtPos(id, (new Game(id, name, desc, price, ageRating)));
					Player* thisUser = dynamic_cast<Player*>(accounts.at(0)->users.getAt(user));
					Game* game = GetStore().games.getAt(id);
					LibraryItem* item = new LibraryItem(date, game);
					//thisUser->getLibrary().addInFront();
				}
			}
		}
		else if (line == "ACCOUNT-ADMIN")
		{
			string date;
			string username;
			string password;
			int credit = 0;
			string role = "Admin";

			int user;

			for (i = 0; i < 4; i++)
			{
				getline(data, line);
				switch (i)
				{
				case 0:
					date = line;
					break;
				case 1:
					username = line;
					break;
				case 2:
					password = line;
					break;
				case 3:
					credit = stoi(line);
					break;
				default:
					break;
				}
			}

			if (accounts.at(0)->users.isEmpty() == true)
			{
				Player* u1 = new Player(username, password, date, credit, role);
				accounts.at(0)->users.addInFront(u1);
				user = 0;
			}
			else if (accounts.at(0)->users.getAt(0) == nullptr)
			{
				Player* u2 = new Player(username, password, date, credit, role);
				accounts.at(0)->users.addAtPos(1, u2);
				user = 1;
			}
			else
			{
				Player* u3 = new Player(username, password, date, credit, role);
				accounts.at(0)->users.addAtEnd(u3);
				user = 2;
			}

			if (line == "LIBRARY-ITEM")
			{
				while (line != "ACCOUNT-PLAYER" || line != "ACCOUNT-ADMIN")
				{
					int id;
					string date;
					int playTime;

					for (i = 0; i < 3; i++)
					{
						getline(data, line);
						switch (i)
						{
						case 0:
							id = stoi(line);
							break;
						case 1:
							date = line;
							break;
						case 2:
							playTime = stoi(line);
							break;
						default:
							break;
						}
					}
				}
			}

		}
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
		if (GetStore().games.getAt(i)->GetName() == name)
		{
			selectedGame = GetStore().games.getAt(i);
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
		if (GetCurrentAccount()->users.getAt(i)->GetUsername() == username && GetCurrentAccount()->users.getAt(i)->GetPassword() == password)
		{
			currentUser = GetCurrentAccount()->users.getAt(i);
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