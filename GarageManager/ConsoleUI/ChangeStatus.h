#pragma once
#include "MenuItem.h"

class ChangeStatus : public MenuItem
{
public:
	ChangeStatus();
	~ChangeStatus();
	void activate() override;
};

