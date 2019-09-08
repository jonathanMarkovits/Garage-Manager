#pragma once
#include "CarProperties.h"
#include "Vehicle.h"

class Car : public Vehicle
{

protected:
	CarProperties* carProperties;

public:
	Car();
	~Car();
	Car(Owner* _owner, VehicleProperties* _properties, Engine* _engine, CarProperties* _carProperties);
	string toString() override;
};

