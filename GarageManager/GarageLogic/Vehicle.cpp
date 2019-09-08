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
	status = StatusEnum::inRepair;
}

string Vehicle::toString()
{
	string toString = "";
	
	toString += properties->toString();
	toString += owner->toString();
	toString += engine->toString();
	toString += "Status: " + GarageLogicUtils::statusEnumToString(status) + '\n';

	return toString;
}

VehicleProperties* Vehicle::getProperties()
{
	return properties;
}

void Vehicle::setStatus(StatusEnum _status)
{
	status = _status;
}

StatusEnum Vehicle::getStatus()
{
	return status;
}

Engine* Vehicle::getEngine()
{
	return engine;
}
