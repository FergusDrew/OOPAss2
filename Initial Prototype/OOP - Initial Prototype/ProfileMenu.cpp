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
		Utils m;
		int num = player->getLibrary().at(i)->GetPlaytime();

		string str;
		m.fullplayTime(num, str);

		

		Option2(i + 1, player->getLibrary().at(i)->GetGame()->GetName(), str);

	
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
	int index = choice - '1';
	// since we are using numbers here we shift the char down by '1'
	// this puts '1' as 0, '2' as 1, '3' as 2, '4' as 3, etc.
	// this reverses the + 1 above and lets us do the range check below

	//if (choice >= '1' || choice <= '5')
	if (index >= 0 && index < player->getLibrary().size())
	{
		int temp = 0;  
		Utils m;
		player->getLibrary().at(index)->GetPlaytime() += m.randomrangeNum(temp);
	}
	return false;
}

const int ProfileMenu::IncreaseCredits(int ammount) 
{
	player->AddCredit(ammount);
	return player->GetCredit();
}