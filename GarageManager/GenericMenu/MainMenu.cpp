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
	Menu* menu;
	vector<Menu*> visibleItems;
	string tmp;
	bool exitOrBack;
	bool validInput;
	int choise;

	while (true)
	{
		visibleItems = getVisibleItems();
		exitOrBack = stack.size() == 1;
		validInput = false;
		stack.top()->show();
		cout << "0. " << (exitOrBack ? "exit" : "back") << '\n';
		cout << "\nPlease choose an option.\n";
		while (!validInput)
		{
			try
			{
				cin >> tmp;
				choise = stoi(tmp);
				if (choise < 0 || choise > visibleItems.size()) throw new exception;
				validInput = true;
			}
			catch (...)
			{
				cout << "Invalid input, the program expects a number between 0 to " << visibleItems.size() << ".\n";
				continue;
			}
		}

		if (--choise == -1) {
			if (exitOrBack)
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

		menu = visibleItems[choise];
		menu->activate();

		subMenuPtr = dynamic_cast<SubMenu*>(menu);
		if (subMenuPtr != 0)
		{
			if (!subMenuPtr->getIsBlocked())
			{
				stack.push(subMenuPtr);
			}
			else
			{
				cout << "The program cannot open this menu.\n";
				system("pause");
			}
		}
		else
		{
			menuItemPtr = dynamic_cast<MenuItem*>(menu);
			cout << "\nThe operation complited seccessfully.\n";
			system("pause");
		}

		system("CLS");
	}
}

SubMenu* MainMenu::getCurrentMenu()
{
	return stack.top();
}

vector<Menu*> MainMenu::getVisibleItems()
{
	vector<Menu*> visibleItems;

	for (Menu* item : getCurrentMenu()->getMenuItems())
	{
		if (item->getVisible())
		{
			visibleItems.push_back(item);
		}
	}

	return visibleItems;
}
