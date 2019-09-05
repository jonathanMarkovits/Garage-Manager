#include "stdafx.h"
#include "VehicleProperties.h"

VehicleProperties::VehicleProperties()
{
}

VehicleProperties::~VehicleProperties()
{
}

VehicleProperties::VehicleProperties(string _modelName, string _licenseNumber, float _remainingEnergyPercentage, vector<Wheel*> _wheels)
{
	modelName = _modelName;
	licenseNumber = _licenseNumber;
	remainingEnergyPercentage = _remainingEnergyPercentage;
	wheels = _wheels;
}

string VehicleProperties::toString()
{
	string toString = "";

	toString += "Model: " + modelName + '\n';
	toString += "License number: " + licenseNumber + '\n';
	toString += "Remaining energy percentage: " + to_string(remainingEnergyPercentage) + '\n';
	for (Wheel* wheel : wheels)
	{

	}

	return toString;
}
