#pragma once
#include "TruckProperties.h"
#include "Vehicle.h"

class Truck : public Vehicle
{

	TruckProperties* truckProperties;

public:
	Truck();
	~Truck();
	Truck(Owner* _owner, VehicleProperties* _properties, Engine* _engine, TruckProperties* _truckProperties);
};

