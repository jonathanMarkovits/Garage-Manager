#include "stdafx.h"
#include "SubMenu.h"


SubMenu::SubMenu()
{
}


SubMenu::~SubMenu()
{
}

SubMenu::SubMenu(string _name) : Menu(_name)
{
}

void SubMenu::addItem(Menu* item)
{
	menuItems.push_back(item);
}

void SubMenu::show(bool exitOrBack)
{
	cout << name << ":\n";
	cout << "0. " << (exitOrBack ? "exit" : "back") << '\n';
	for (int i = 1; i <= menuItems.size(); i++)
	{
		cout << i << ". " << menuItems[i - 1]->getName() + '\n';
	}
}

vector<Menu*> SubMenu::getMenuItems()
{
	return menuItems;
}
