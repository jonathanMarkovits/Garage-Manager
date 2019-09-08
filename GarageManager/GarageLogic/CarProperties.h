#pragma once
#include "ColorEnum.h"

class CarProperties
{

	ColorEnum color;
	int numberOfDoors;

public:
	CarProperties();
	~CarProperties();
	CarProperties(ColorEnum _color, int _numberOfDoors);
	ColorEnum getColor();
	int getNumberOfDoors();
};

