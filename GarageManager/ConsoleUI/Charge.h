#pragma once
#include "MenuItem.h"

class Charge : public MenuItem
{
public:
	Charge();
	~Charge();
	void activate() override;
};

