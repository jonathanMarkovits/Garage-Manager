#include "stdafx.h"
#include "MenuItem.h"


MenuItem::MenuItem()
{
}


MenuItem::~MenuItem()
{
}

MenuItem::MenuItem(string _name) : Menu(_name)
{
}

MenuItem::MenuItem(void(*_act)(), string _name) : Menu(_act, _name)
{
}

void MenuItem::dummy()
{
}
