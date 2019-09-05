#include "stdafx.h"
#include "FuelEngine.h"


FuelEngine::FuelEngine()
{
}


FuelEngine::~FuelEngine()
{
}

FuelEngine::FuelEngine(string _fuelType, float _currentAmountOfFuel, float _maxAmountOfFuel) : Engine(_currentAmountOfFuel, _maxAmountOfFuel)
{
	fuelType = _fuelType;
}

void FuelEngine::refueling(float amountOfFuelToAdd, string _fuelType)
{
	if (fuelType != _fuelType)
	{

	}

	recharge(amountOfFuelToAdd);
}
