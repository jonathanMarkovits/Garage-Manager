#include "stdafx.h"
#include "VehicleProperties.h"

VehicleProperties::VehicleProperties()
{
}

VehicleProperties::~VehicleProperties()
{
}

VehicleProperties::VehicleProperties(string _modelName, string _licenseNumber, vector<Wheel*> _wheels)
{
	modelName = _modelName;
	licenseNumber = _licenseNumber;
	wheels = _wheels;
}

string VehicleProperties::toString()
{
	string toString = "";

	toString += "Model: " + modelName + '\n';
	toString += "License number: " + licenseNumber + '\n';
	for (Wheel* wheel : wheels)
	{
		toString += wheel->toString();
	}

	return toString;
}

string VehicleProperties::getLicenseNumber()
{
	return licenseNumber;
}

vector<Wheel*> VehicleProperties::getWheels()
{
	return wheels;
}
