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

string Car::toString()
{
	string toString = "";

	toString += Vehicle::toString();
	toString += "Color: " + GarageLogicUtils::colorEnumToString(carProperties->getColor()) + '\n';
	toString += "Number of doors: " + to_string(carProperties->getNumberOfDoors()) + '\n';

	return toString;
}
