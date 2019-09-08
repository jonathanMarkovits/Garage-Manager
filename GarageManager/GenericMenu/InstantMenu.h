#pragma once
#include "SubMenu.h"

class InstantMenu
{

	SubMenu* menu;

public:
	InstantMenu();
	~InstantMenu();
	InstantMenu(SubMenu* _menu);
	int run();
};

