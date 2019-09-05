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
