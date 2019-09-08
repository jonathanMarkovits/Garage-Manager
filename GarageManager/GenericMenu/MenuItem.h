#pragma once
#include "Menu.h"

class MenuItem : public Menu
{
public:
	MenuItem();
	~MenuItem();
	MenuItem(string _name); //delete
	MenuItem(void(*_act)(), string _name);
	void dummy();
};

