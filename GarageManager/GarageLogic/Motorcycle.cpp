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
