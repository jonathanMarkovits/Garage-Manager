#include "stdafx.h"
#include "MenuItem.h"


MenuItem::MenuItem()
{
}


MenuItem::~MenuItem()
{
}

MenuItem::MenuItem(string i_Name) : Menu(i_Name)
{
}

MenuItem::MenuItem(void(*i_ActivateFunction)(), string i_Name) : Menu(i_ActivateFunction, i_Name)
{
}

void MenuItem::dummy()
{
}
