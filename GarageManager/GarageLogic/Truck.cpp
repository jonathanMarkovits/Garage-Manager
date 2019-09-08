#include "stdafx.h"
#include "Truck.h"


Truck::Truck()
{
}


Truck::~Truck()
{
}

Truck::Truck(Owner* _owner, VehicleProperties* _properties, Engine* _engine, TruckProperties* _truckProperties) :
	Vehicle(_owner, _properties, _engine)
{
	truckProperties = _truckProperties;
}

string Truck::toString()
{
	string toString = "";
	string containsDangerousMaterials = truckProperties->getContainsDangerousMaterials() ? "Yes" : "No";

	toString += Vehicle::toString();
	toString += "Contains dangerous materials: " + containsDangerousMaterials + '\n';
	toString += "Volume of cargo: " + to_string(truckProperties->getVolumeOfCargo()) + '\n';

	return toString;
}
