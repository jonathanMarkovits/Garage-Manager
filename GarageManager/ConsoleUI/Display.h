#pragma once
#include "MenuItem.h"

class Display : public MenuItem
{
public:
	Display();
	~Display();
	void activate() override;
};

