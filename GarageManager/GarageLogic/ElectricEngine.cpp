#include "stdafx.h"
#include "ElectricEngine.h"


ElectricEngine::ElectricEngine()
{
}


ElectricEngine::~ElectricEngine()
{
}

ElectricEngine::ElectricEngine(float _currentAmountOfEnergy, float _maxAmountOfEnergy) : Engine(_currentAmountOfEnergy, _maxAmountOfEnergy)
{
}

string ElectricEngine::toString()
{
	string toString = "";

	toString += "Remaining battery precentage: " + to_string(getRemainingEnergyPercentage()) + '\n';

	return toString;
}
