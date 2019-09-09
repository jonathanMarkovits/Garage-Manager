#pragma once
#include "Menu.h"
#include <vector>
#include <iostream>
using namespace std;

class SubMenu : public Menu
{

	vector<Menu*> m_MenuItems;
	bool m_IsBlocked;

public:
	SubMenu();
	~SubMenu();
	SubMenu(string i_Name);
	SubMenu(void(*i_ActivateFunction)(), string i_Name);
	void AddItem(Menu* i_Item);
	void Show();
	bool GetIsBlocked();
	void SetIsBlocked(bool i_IsBlocked);
	vector<Menu*> GetMenuItems();

private:
	void dummy() override;
};

