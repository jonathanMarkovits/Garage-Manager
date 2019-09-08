#include "stdafx.h"
#include "Wheel.h"


Wheel::Wheel(string _manufacturerName, float _currentAirPressure, float _maxAirPressure)
{
	manufacturerName = _manufacturerName;
	currentAirPressure = _currentAirPressure;
	maxAirPressure = _maxAirPressure;
}


Wheel::Wheel()
{
}

Wheel::~Wheel()
{
}

void Wheel::inflateAction(float amountOfAirToInflate)
{
	if (amountOfAirToInflate + currentAirPressure > maxAirPressure)
	{
		currentAirPressure = maxAirPressure;
	}
	else
	{
		currentAirPressure = maxAirPressure;
	}
}

string Wheel::toString()
{
	return "Manufacturer name: " + manufacturerName + ", max air pressure: " + to_string(maxAirPressure) + ", current air pressure: " + to_string(currentAirPressure) + '\n';
}
