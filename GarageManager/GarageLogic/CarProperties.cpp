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
