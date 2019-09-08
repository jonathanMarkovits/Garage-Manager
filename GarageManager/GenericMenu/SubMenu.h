#pragma once
#include "Menu.h"
#include <vector>
#include <iostream>
using namespace std;

class SubMenu : public Menu
{

	vector<Menu*> menuItems;
	bool isBlocked;

public:
	SubMenu();
	~SubMenu();
	SubMenu(string _name);
	SubMenu(void(*_act)(), string _name);
	void addItem(Menu* item);
	void deleteItem(int i);
	void show();
	vector<Menu*> getMenuItems();
	bool getIsBlocked();
	void setIsBlocked(bool _isBlocked);
	void dummy();
};

