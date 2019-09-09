#include "stdafx.h"
#include "Garage.h"


Garage::Garage()
{
}


Garage::~Garage()
{
}

void Garage::addVehicle(Vehicle* newVehicle)
{
	vehicles.push_back(newVehicle);
}

Vehicle* Garage::getVehicleByLicenseNumber(string licenseNumber)
{
	Vehicle* returnedVehicle = nullptr;

	for (Vehicle* vehicle : vehicles)
	{
		if (vehicle->getProperties()->getLicenseNumber() == licenseNumber)
		{
			returnedVehicle = vehicle;
		}
	}

	return returnedVehicle;
}

vector<Vehicle*> Garage::getVehicles()
{
	return vehicles;
}
