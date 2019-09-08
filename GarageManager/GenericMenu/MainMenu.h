#pragma once
#include <iostream>
#include <stack>
#include <vector>
#include "SubMenu.h"
#include "MenuItem.h"
using namespace std;

class MainMenu
{

	stack<SubMenu*> stack;

public:
	MainMenu();
	~MainMenu();
	MainMenu(SubMenu* main);
	void run();
	SubMenu* getCurrentMenu();
	vector<Menu*> getVisibleItems();
};

