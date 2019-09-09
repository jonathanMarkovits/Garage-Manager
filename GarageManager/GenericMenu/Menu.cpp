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

Menu::Menu(string i_Name)
{
	m_Name = i_Name;
	m_Visible = true;
}

Menu::Menu(activateFunctionDef i_ActivateFunctions, string i_Name)
{
	m_ActivateFunctions.push_back(i_ActivateFunctions);
	m_Name = i_Name;
	m_Visible = true;
}

string Menu::GetName()
{
	return m_Name;
}

vector<activateFunctionDef> Menu::GetActivateFunctions()
{
	return m_ActivateFunctions;
}

void Menu::InsertActivateFunction(activateFunctionDef i_ActivateFunction)
{
	m_ActivateFunctions.push_back(i_ActivateFunction);
}

bool Menu::GetVisiblity()
{
	return m_Visible;
}

void Menu::SetVisiblity(bool i_Visible)
{
	m_Visible = i_Visible;
}

void Menu::Activate()
{
	for (activateFunctionDef function : m_ActivateFunctions)
	{
		function();
	}
}

