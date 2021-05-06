#include "ProfileMenu.h"

ProfileMenu::ProfileMenu(const std::string& title, Application* app) : Menu(title, app)
{
	Paint(); // Required in constructor
}

void ProfileMenu::OutputOptions()
{
	if (player->GetRole() == "Admin")
	{
		Line("-=ADMIN OPTIONS=-");
		Option('A', "Add User");
		Option('D', "Delete User");
		Line();
	}
	Line("Credits: " + Utils::CastToCredit(player->GetCredit()));
	Option('I', "Purchase 1 credit");
	Option('O', "Purchase 10 credits");
	Option('P', "Purchase 100 credits");
	Line();
	Line("GAMES");

	for (int i = 0; i < player->getLibrary().size(); i++)
	{
		Option(i + 1, player->getLibrary().at(i)->GetGame()->GetName());
	}
	Line();
	Option('N', "Sort By Name");
	Option('D', "Sort By Date");
}

bool ProfileMenu::HandleChoice(char choice)
{
	//Player* player = dynamic_cast<Player*>(app->GetCurrentUser());
	switch (choice)
	{
	case 'A':
	{
		Line("Needs to be implemented");
	} break;
	case 'D':
	{
		Line("Needs to be implemented");
	} break;
	case 'I':
	{
		IncreaseCredits(1);
	} break;
	case 'O':
	{
		IncreaseCredits(10);
	} break;
	case 'P':
	{
		IncreaseCredits(100);
	} break;
	}

	return false;
}

const int ProfileMenu::IncreaseCredits(int ammount) 
{
	player->AddCredit(ammount);
	return player->GetCredit();
}