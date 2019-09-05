#pragma once
#include "MenuItem.h"

class LicenseNumbersList : public MenuItem
{
public:
	LicenseNumbersList();
	~LicenseNumbersList();
	void activate() override;
};

