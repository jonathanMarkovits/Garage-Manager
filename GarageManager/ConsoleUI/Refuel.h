#pragma once
#include "MenuItem.h"

class Refuel : public MenuItem
{
public:
	Refuel();
	~Refuel();
	void activate() override;
};

