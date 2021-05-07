#include "Menu.h"

Menu::Menu(const std::string& title, Application* app) : title(title), app(app)
{
}

void Menu::Paint()
{
	bool readyToGoBack = false;

	while (!readyToGoBack)
	{
		Header();
		OutputOptions();
		Line();
		//MainMenu wont display 'back'
		if (title != "Main Menu")
		{ 
		Option('B', "Back");
		Footer();
		}
		else
		{
			Footer();
		}
		char choice = Utils::GetCharFromUser();

		//MainMenu cant execute back method
		if (choice == 'B' && title != "Main Menu")
		{
			readyToGoBack = true;
		}
		else
		{
			readyToGoBack = HandleChoice(choice);
		}
	}
}

void Menu::Line()
{
	std::cout << '\n';
}

void Menu::Line(const std::string& text)
{
	std::cout << "  " << text << "\n";
}

void Menu::Option(char id, const std::string& option)
{
	std::cout << "  " << id << ") " << option << '\n';
}


void Menu::Option(int id, const std::string& option)
{
	// shift the integer value up to the correct position in the ascii table
	char ascii = id + '0';
	Option(ascii, option);
}

void Menu::Option2(char id, const std::string& option2, const std::string& text)
{
	std::cout << "  " << id << ") " << option2 << " " <<text <<'\n';
}


void Menu::Option2(int id, const std::string& option2, const std::string& text)
{
	// shift the integer value up to the correct position in the ascii table
	char ascii = id + '0';
	Option2(ascii, option2, text);
}



std::string Menu::Question(const std::string& question)
{
	std::cout << "  " << question << ": ";
	return Utils::GetLineFromUser();
}

void Menu::BlockingMessage(const std::string& message)
{
	std::cout << "  " << message;
	Utils::GetLineFromUser();
}

void Menu::Header()
{

#if defined _WIN32 || defined _WIN64
	// we are running on windows so use CLS to clear the screen
	system("CLS");
#else
	// we are running on mac or linux so use CLEAR to clear the screen
	system("CLEAR");
#endif

	std::cout << '\n';
	std::cout << "  -= " << title << " =-  \n";
	std::cout << '\n';
}

void Menu::Footer()
{
	std::cout << '\n';
	std::cout << '\n';
	std::cout << "  >>> ";
}