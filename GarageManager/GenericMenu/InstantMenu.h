#pragma once
#include "SubMenu.h"

class InstantMenu
{

	SubMenu* m_Menu;

public:
	InstantMenu();
	~InstantMenu();
	InstantMenu(SubMenu* i_Menu);
	int Run();
};

