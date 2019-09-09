#include "stdafx.h"
#include "SubMenu.h"


SubMenu::SubMenu()
{
}


SubMenu::~SubMenu()
{
}

SubMenu::SubMenu(string i_Name) : Menu(i_Name)
{
	m_IsBlocked = false;
}

SubMenu::SubMenu(void(*i_ActivateFunction)(), string i_Name) : Menu(i_ActivateFunction, i_Name)
{
	m_IsBlocked = false;
}

void SubMenu::AddItem(Menu* i_Item)
{
	m_MenuItems.push_back(i_Item);
}

void SubMenu::Show()
{
	string str = "";
	int i = 1;

	str += m_Name + ":\n\n";
	for (Menu* menuItem : m_MenuItems)
	{
		if (!menuItem->GetVisiblity())
		{
			continue;
		}

		str += to_string(i++) + ". " + menuItem->GetName() + '\n';
	}

	cout << str;
}

vector<Menu*> SubMenu::GetMenuItems()
{
	return m_MenuItems;
}

bool SubMenu::GetIsBlocked()
{
	return m_IsBlocked;
}

void SubMenu::SetIsBlocked(bool i_IsBlocked)
{
	m_IsBlocked = i_IsBlocked;
}

void SubMenu::dummy()
{
}
