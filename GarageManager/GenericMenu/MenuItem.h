#pragma once
#include "Menu.h"

class MenuItem : public Menu
{
public:
	MenuItem();
	~MenuItem();
	MenuItem(string _name);
	virtual void activate() = 0;
};

