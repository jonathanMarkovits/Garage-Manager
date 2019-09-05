// Menu.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "Menu.h"

Menu::Menu()
{
}

Menu::~Menu()
{
}

Menu::Menu(string _name)
{
	name = _name;
}

string Menu::getName()
{
	return name;
}

void Menu::dummy()
{
}
