#include "stdafx.h"
#include "Car.h"


Car::Car()
{
}


Car::~Car()
{
}

Car::Car(Owner * _owner, VehicleProperties * _properties, Engine * _engine, CarProperties * _carProperties) :
	Vehicle(_owner, _properties, _engine)
{
	carProperties = _carProperties;
}
