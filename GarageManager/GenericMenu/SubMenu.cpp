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
	isBlocked = false;
}

SubMenu::SubMenu(void(*_act)(), string _name) : Menu(_act, _name)
{
	isBlocked = false;
}

void SubMenu::addItem(Menu* item)
{
	menuItems.push_back(item);
}

void SubMenu::deleteItem(int i)
{
	menuItems.erase(menuItems.begin() + i);
}

void SubMenu::show()
{
	string str = "";
	int i = 1;

	str += name + ":\n\n";
	for (Menu* menuItem : menuItems)
	{
		if (!menuItem->getVisible())
		{
			continue;
		}

		str += to_string(i++) + ". " + menuItem->getName() + '\n';
	}

	cout << str;
}

vector<Menu*> SubMenu::getMenuItems()
{
	return menuItems;
}

bool SubMenu::getIsBlocked()
{
	return isBlocked;
}

void SubMenu::setIsBlocked(bool _isBlocked)
{
	isBlocked = _isBlocked;
}

void SubMenu::dummy()
{
}
