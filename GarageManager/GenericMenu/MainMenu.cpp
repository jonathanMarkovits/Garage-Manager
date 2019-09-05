#include "stdafx.h"
#include "MainMenu.h"


MainMenu::MainMenu()
{
}

MainMenu::~MainMenu()
{
}

MainMenu::MainMenu(SubMenu* main)
{
	stack.push(main);
}


void MainMenu::run()
{
	SubMenu* subMenuPtr;
	MenuItem* menuItemPtr;
	string tmp;
	bool mainMenu;
	bool validInput;
	int choise;

	while (true)
	{
		mainMenu = stack.size() == 1;
		validInput = false;
		stack.top()->show(mainMenu);
		cout << "\nPlease choose an option.\n";
		while (!validInput)
		{
			try
			{
				cin >> tmp;
				choise = stoi(tmp);
				if (choise < 0 || choise > stack.top()->getMenuItems().size()) throw "Invalid input";
				validInput = true;
			}
			catch (...)
			{
				cout << "Invalid input, the program expects a number between 0 to " << getCurrentMenu()->getMenuItems().size() << ".\n";
				continue;
			}
		}

		if (--choise == -1) {
			if (mainMenu)
			{
				break;
			}
			else
			{
				stack.pop();
				system("CLS");
				continue;
			}
		}

		subMenuPtr = dynamic_cast<SubMenu*>(stack.top()->getMenuItems()[choise]);
		if (subMenuPtr != 0)
		{
			stack.push(subMenuPtr);
		}
		else
		{
			menuItemPtr = dynamic_cast<MenuItem*>(stack.top()->getMenuItems()[choise]);
			cout << '\n';
			menuItemPtr->activate();
			cout << "\n";
			system("pause");
		}

		system("CLS");
	}
}

SubMenu* MainMenu::getCurrentMenu()
{
	return stack.top();
}
