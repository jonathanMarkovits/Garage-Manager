#include "stdafx.h"
#include "CarProperties.h"


CarProperties::CarProperties()
{
}


CarProperties::~CarProperties()
{
}

CarProperties::CarProperties(ColorEnum _color, int _numberOfDoors)
{
	color = _color;
	numberOfDoors = _numberOfDoors;
}

ColorEnum CarProperties::getColor()
{
	return color;
}

int CarProperties::getNumberOfDoors()
{
	return numberOfDoors;
}
