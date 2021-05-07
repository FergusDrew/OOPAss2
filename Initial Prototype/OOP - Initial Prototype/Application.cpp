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

void Application::Save()
{

	std::ofstream saveData;
	saveData.open("data1.txt");
	int numOfGames = (GetStore().games.length());
	for (int i = 0; i < numOfGames; ++i)
	{
		saveData << "GAME" << "\n";
		saveData << GetStore().games.getAt(i)->GetId() << "\n";
		saveData << GetStore().games.getAt(i)->GetName() << "\n";
		saveData << GetStore().games.getAt(i)->GetDescription() << "\n";
		saveData << GetStore().games.getAt(i)->GetCost() << "\n";
		saveData << GetStore().games.getAt(i)->GetRating() << "\n";
		saveData << GetStore().games.getAt(i)->GetLikes() << "\n";
		saveData << GetStore().games.getAt(i)->GetDislikes() << "\n";
	}
	//Number of Accounts -> first acc data
	for (int i = 0; i < accounts.size(); i++)
	{
		saveData << "ACCOUNT" << "\n";
		saveData << accounts.at(i)->GetCreated() << "\n";
		saveData << accounts.at(i)->GetEmail() << "\n";
		saveData << accounts.at(i)->GetPassword() << "\n";

		int numOfUsers = (GetCurrentAccount()->users.length());
		for (int i = 0; i < numOfUsers; ++i)
		{
			if (GetCurrentAccount()->users.getAt(i)->GetRole() == "Player")
			{
				int test = i;
				saveData << "ACCOUNT-PLAYER" << "\n";
				saveData << GetCurrentAccount()->users.getAt(test)->GetCreated() << "\n";
				saveData << GetCurrentAccount()->users.getAt(test)->GetUsername() << "\n";
				saveData << GetCurrentAccount()->users.getAt(test)->GetPassword() << "\n";
				saveData << GetCurrentAccount()->users.getAt(test)->GetCredit() << "\n";
				//Add this accounts Library Items
				Player* thisUser = dynamic_cast<Player*>(accounts.at(0)->users.getAt(i));
				for (int i = 0; i < thisUser->getLibrary().size(); i++)
				{
					saveData << "LIBRARY-ITEM" << "\n";
					saveData << thisUser->getLibrary().at(i)->GetGame()->GetId() << "\n";
					saveData << thisUser->getLibrary().at(i)->GetPurchaseDate() << "\n";
					saveData << thisUser->getLibrary().at(i)->GetPlaytime() << "\n";
					saveData << thisUser->getLibrary().at(i)->GetRating() << "\n";
				}
			}
			if (GetCurrentAccount()->users.getAt(i)->GetRole() == "Admin")
			{
				int test = i;
				saveData << "ACCOUNT-ADMIN" << "\n";
				saveData << GetCurrentAccount()->users.getAt(test)->GetCreated() << "\n";
				saveData << GetCurrentAccount()->users.getAt(test)->GetUsername() << "\n";
				saveData << GetCurrentAccount()->users.getAt(test)->GetPassword() << "\n";
				saveData << GetCurrentAccount()->users.getAt(test)->GetCredit() << "\n";
				Player* thisUser = dynamic_cast<Player*>(accounts.at(0)->users.getAt(i));
				for (int i = 0; i < thisUser->getLibrary().size(); i++)
				{
					saveData << "LIBRARY-ITEM" << "\n";
					saveData << thisUser->getLibrary().at(i)->GetGame()->GetId() << "\n";
					saveData << thisUser->getLibrary().at(i)->GetPurchaseDate() << "\n";
					saveData << thisUser->getLibrary().at(i)->GetPlaytime() << "\n";
					saveData << thisUser->getLibrary().at(i)->GetRating() << "\n";
				}
			}
		}
	}
	saveData << "EOF";
	saveData.close();
}

void Application::Load()
{
	int i;
	std::ifstream data("data.txt");
	std::string line;
	std::getline(data, line);
	bool contLoop = true;

	while (contLoop)
	{
		if (line == "GAME")
		{
			int id;
			std::string name;
			std::string desc;
			int price;
			int ageRating;
			int likes;
			int dislikes;

			for (i = 0; i < 7; i++)
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
				case 5:
					likes = stoi(line);
					break;
				case 6:
					dislikes = stoi(line);
					break;
				default:
					break;
				}
			}
			GetStore().games.addAtEnd(new Game(id, name, desc, price, ageRating, likes, dislikes));
			getline(data, line);
		}

		if (line == "ACCOUNT")
		{
			std::string date;
			std::string email;
			std::string password;
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
			getline(data, line);
		}

		if (line == "ACCOUNT-PLAYER")
		{
			std::string date;
			std::string username;
			std::string password;
			int credit = 0;
			std::string role = "Player";

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
					credit = std::stoi(line);
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
			else if (accounts.at(0)->users.getNext(0) == nullptr)
			{
				Player* u2 = new Player(username, password, date, credit, role);
				accounts.at(0)->users.addAtEnd(u2);
				user = 1;
			}
			else
			{
				Player* u3 = new Player(username, password, date, credit, role);
				accounts.at(0)->users.addAtEnd(u3);
				user = 2;
			}
			getline(data, line);

			if (line == "LIBRARY-ITEM")
			{
				while (line != "ACCOUNT-PLAYER" && line != "ACCOUNT-ADMIN" && line != "EOF")
				{
					int id;
					std::string date;
					int playTime;
					int rating;

					for (i = 0; i < 4; i++)
					{
						getline(data, line);
						switch (i)
						{
						case 0:
							id = std::stoi(line);
							break;
						case 1:
							date = line;
							break;
						case 2:
							playTime = std::stoi(line);
							break;
						case 3:
							rating = std::stoi(line);
							break;
						default:
							break;
						}
					}

					Player* thisUser = dynamic_cast<Player*>(accounts.at(0)->users.getAt(user));
					Game* game = GetStore().games.getAt(id);
					thisUser->addLibraryItem((new LibraryItem(date, game, playTime, rating)));

					getline(data, line);
				}
			}
		}

		if (line == "ACCOUNT-ADMIN")
		{
			std::string date;
			std::string username;
			std::string password;
			int credit = 0;
			std::string role = "Admin";

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
					credit = std::stoi(line);
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
			else if (accounts.at(0)->users.getNext(0) == nullptr)
			{
				Player* u2 = new Player(username, password, date, credit, role);
				accounts.at(0)->users.addAtEnd(u2);
				user = 1;
			}
			else
			{
				Player* u3 = new Player(username, password, date, credit, role);
				accounts.at(0)->users.addAtEnd(u3);
				user = 2;
			}

			getline(data, line);

			if (line == "LIBRARY-ITEM")
			{
				while (line != "ACCOUNT-PLAYER" && line != "ACCOUNT-ADMIN" && line != "EOF")
				{
					int id;
					std::string date;
					int playTime;
					int rating;

					for (i = 0; i < 4; i++)
					{
						getline(data, line);
						switch (i)
						{
						case 0:
							id = std::stoi(line);
							break;
						case 1:
							date = line;
							break;
						case 2:
							playTime = std::stoi(line);
							break;
						case 3:
							rating = std::stoi(line);
							break;
						default:
							break;
						}
					}

					Player* thisUser = dynamic_cast<Player*>(accounts.at(0)->users.getAt(user));
					Game* game = GetStore().games.getAt(id);
					thisUser->addLibraryItem((new LibraryItem(date, game, playTime, rating)));

					getline(data, line);
				}
			}
		}
		if (line == "EOF") contLoop = false;
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

	for (int i = 0; i < GetCurrentAccount()->users.length(); i++) 
	{
		if (GetCurrentAccount()->users.getAt(i)->GetUsername() == username && GetCurrentAccount()->users.getAt(i)->GetPassword() == password)
		{
			currentUser = GetCurrentAccount()->users.getAt(i);
			return true;
		}
	}
	currentUser = nullptr;
	return false;

	accounts.at(0)->users.getAt(0)->GetRole();
}

void Application::LogoutUser()
{
	currentUser = nullptr;
}