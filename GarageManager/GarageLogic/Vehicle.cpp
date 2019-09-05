#include "stdafx.h"
#include "Vehicle.h"

Vehicle::Vehicle()
{
}

Vehicle::~Vehicle()
{
}

Vehicle::Vehicle(Owner* _owner, VehicleProperties* _properties, Engine* _engine)
{
	owner = _owner;
	properties = _properties;
	engine = _engine;
//	status = StatusEnum::inRepair;
}

string Vehicle::toString()
{
	string toString = "";
	
	toString += properties->toString();

	return toString;
}
