#include "stdafx.h"
#include "InstantMenu.h"


InstantMenu::InstantMenu()
{
}


InstantMenu::~InstantMenu()
{
}

InstantMenu::InstantMenu(SubMenu* _menu)
{
	menu = _menu;
}

int InstantMenu::run()
{
	int choise = 0;
	bool validInput = false;
	bool firstTry = true;

	menu->show();
	cout << "\nPlease choose an option.\n";
	while (!validInput)
	{
		if (!firstTry)
		{
			cout << "Invalid input, the program expects a number between 1 to " << menu->getMenuItems().size() << ".\n";
		}

		cin >> choise;
		firstTry = false;
		validInput = choise <= menu->getMenuItems().size() && choise >= 1;
	}
	
	return choise;
}
