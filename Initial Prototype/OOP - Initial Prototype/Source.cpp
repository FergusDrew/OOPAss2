#include <iostream>
#include <string>
#include "Application.h"
#include "Account.h"
#include "User.h"
#include "Player.h"
#include "Admin.h"
#include "Utils.h"
#include "MainMenu.h"
#include <fstream>
#include <sstream>

using namespace std;

void main()
{
	Application app;
	app.Load();
	MainMenu("Main Menu", &app);
	app.Save();
}