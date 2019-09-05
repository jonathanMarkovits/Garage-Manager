#pragma once
#include "MotorcycleProperties.h"
#include "Vehicle.h"

class Motorcycle : public Vehicle
{

protected:
	MotorcycleProperties* motorcycleProperties;

public:
	Motorcycle();
	~Motorcycle();
	Motorcycle(Owner* _owner, VehicleProperties* _properties, Engine* _engine, MotorcycleProperties* _motorcycleProperties);
};

