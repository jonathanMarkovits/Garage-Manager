// Menu.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "Menu.h"

typedef void(*activateFunctionDef)();

Menu::Menu()
{
}

Menu::~Menu()
{
}

Menu::Menu(string _name)
{
	name = _name;
	visible = true;
}

Menu::Menu(activateFunctionDef _act, string _name)
{
	activateFunctions.push_back(_act);
	name = _name;
	visible = true;
}

string Menu::getName()
{
	return name;
}

vector<activateFunctionDef> Menu::getActivateFunctions()
{
	return activateFunctions;
}

void Menu::insertActivateFunction(activateFunctionDef _activateFunction)
{
	activateFunctions.push_back(_activateFunction);
}

bool Menu::getVisible()
{
	return visible;
}

void Menu::setVisible(bool _visible)
{
	visible = _visible;
}

void Menu::activate()
{
	for (activateFunctionDef function : activateFunctions)
	{
		function();
	}
}

