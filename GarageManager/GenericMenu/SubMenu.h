#pragma once
#include "Menu.h"
#include <vector>
#include <iostream>
using namespace std;

class SubMenu : public Menu
{

	vector<Menu*> menuItems;

public:
	SubMenu();
	~SubMenu();
	SubMenu(string _name);
	void addItem(Menu* item);
	void show(bool exitOrBack);
	vector<Menu*> getMenuItems();
};

