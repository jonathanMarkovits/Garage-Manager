#pragma once
#include "MenuItem.h"

class Insert : public MenuItem
{
public:
	Insert();
	~Insert();
	void activate() override;
};

