#include "stdafx.h"
#include "InstantMenu.h"


InstantMenu::InstantMenu()
{
}


InstantMenu::~InstantMenu()
{
}

InstantMenu::InstantMenu(SubMenu* i_Menu)
{
	m_Menu = i_Menu;
}

int InstantMenu::Run()
{
	int choise = 0;
	bool validInput = false;
	bool firstTry = true;

	m_Menu->Show();
	cout << "\nPlease choose an option.\n";
	while (!validInput)
	{
		if (!firstTry)
		{
			cout << "Invalid input, the program expects a number between 1 to " << m_Menu->GetMenuItems().size() << ".\n";
		}

		cin >> choise;
		firstTry = false;
		validInput = choise <= m_Menu->GetMenuItems().size() && choise >= 1;
	}
	
	return choise;
}
