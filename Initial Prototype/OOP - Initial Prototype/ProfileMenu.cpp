#include "ProfileMenu.h"

ProfileMenu::ProfileMenu(const std::string& title, Application* app) : Menu(title, app)
{
	Paint(); // Required in constructor
}

void ProfileMenu::OutputOptions()
{
	Player* player = dynamic_cast<Player*>(app->GetCurrentUser());
	int length = player->library.length();
	Line("Credits: " + Utils::CastToCredit(credits));
	Option('I', "Purchase 1 credit");
	Option('O', "Purchase 10 credits");
	Option('P', "Purchase 100 credits");
	Line();
	Line("GAMES");
	for (int i = 0; i < length; i++)
	{
		Option(i + 1, player->library.getAt(i)->GetGame()->GetName());
		
		//Option(i + 1, player->library->->GetGame()->GetName());
	}
}

bool ProfileMenu::HandleChoice(char choice)
{
	switch (choice)
	{
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

int ProfileMenu::IncreaseCredits(int ammount) 
{
	credits = credits + ammount;
	return credits;
}