#pragma once
#include "Menu.h"

class MenuItem : public Menu
{
public:
	MenuItem();
	~MenuItem();
	MenuItem(string i_Name);
	MenuItem(void(*i_ActivateFunction)(), string i_Name);

private:
	void dummy() override;
};

