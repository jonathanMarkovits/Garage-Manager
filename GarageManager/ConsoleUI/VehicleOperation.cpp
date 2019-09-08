#include "pch.h"
#include "VehicleOperation.h"


VehicleOperation::VehicleOperation()
{
}

VehicleOperation::~VehicleOperation()
{
}

VehicleOperation::VehicleOperation(string _name) : SubMenu(_name)
{
}


void VehicleOperation::activate()
{
	string licenseNumber = Program::getLicenseNumber();
	Program::currentVehicle = Program::grarge->getVehicleByLicenseNumber(licenseNumber);

	setIsBlocked(false);
	if (!Program::currentVehicle)
	{
		setIsBlocked(true);
		cout << "This license number is not registered.\n";
	}
}
