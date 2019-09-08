#include "stdafx.h"
#include "Motorcycle.h"


Motorcycle::Motorcycle()
{
}


Motorcycle::~Motorcycle()
{
}

Motorcycle::Motorcycle(Owner* _owner, VehicleProperties* _properties, Engine* _engine, MotorcycleProperties* _motorcycleProperties) :
	Vehicle(_owner, _properties, _engine)
{
	motorcycleProperties = _motorcycleProperties;
}

string Motorcycle::toString()
{
	string toString = "";

	toString += Vehicle::toString();
	toString += "License type: " + GarageLogicUtils::licenseTypeEnumToString(motorcycleProperties->getLicenseType()) + '\n';
	toString += "Engine's volume: " + to_string(motorcycleProperties->getEngineVolume()) + '\n';

	return toString;
}
