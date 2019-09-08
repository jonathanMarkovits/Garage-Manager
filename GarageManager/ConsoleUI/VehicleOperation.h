#pragma once
#include "Program.h"

class VehicleOperation : public SubMenu
{
public:
	VehicleOperation();
	~VehicleOperation();
	VehicleOperation(string _name);
	void activate() override;
};

