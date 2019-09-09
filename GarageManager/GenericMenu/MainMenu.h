#pragma once
#include <iostream>
#include <stack>
#include <vector>
#include "SubMenu.h"
#include "MenuItem.h"
using namespace std;

class MainMenu
{

	stack<SubMenu*> m_MenuStack;

public:
	MainMenu();
	~MainMenu();
	MainMenu(SubMenu* i_Menu);
	void Run();

private:
	SubMenu* getCurrentMenu();
	vector<Menu*> getVisibleItems();
};

