#include "stdafx.h"
#include "MainMenu.h"

MainMenu::MainMenu()
{
}

MainMenu::~MainMenu()
{
}

MainMenu::MainMenu(SubMenu* i_Menu)
{
	m_MenuStack.push(i_Menu);
}

void MainMenu::Run()
{
	SubMenu* subMenuPtr = nullptr;
	MenuItem* menuItemPtr = nullptr;
	Menu* menu = nullptr;
	vector<Menu*> visibleItems;
	string tmp = "";
	bool exitOrBack = false;
	bool validInput = false;
	int choise = 0;

	while (true)
	{
		visibleItems = getVisibleItems();
		exitOrBack = m_MenuStack.size() == 1;
		validInput = false;
		m_MenuStack.top()->Show();
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
				m_MenuStack.pop();
				system("CLS");
				continue;
			}
		}

		menu = visibleItems[choise];
		menu->Activate();

		subMenuPtr = dynamic_cast<SubMenu*>(menu);
		if (subMenuPtr != 0)
		{
			if (!subMenuPtr->GetIsBlocked())
			{
				m_MenuStack.push(subMenuPtr);
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
			cout << "\nThe operation completed seccessfully.\n";
			system("pause");
		}

		system("CLS");
	}
}

SubMenu* MainMenu::getCurrentMenu()
{
	return m_MenuStack.top();
}

vector<Menu*> MainMenu::getVisibleItems()
{
	vector<Menu*> visibleItems;

	for (Menu* item : getCurrentMenu()->GetMenuItems())
	{
		if (item->GetVisiblity())
		{
			visibleItems.push_back(item);
		}
	}

	return visibleItems;
}
