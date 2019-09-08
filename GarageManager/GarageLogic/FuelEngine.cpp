#include "stdafx.h"
#include "FuelEngine.h"


FuelEngine::FuelEngine()
{
}


FuelEngine::~FuelEngine()
{
}

FuelEngine::FuelEngine(FuelTypeEnum _fuelType, float _currentAmountOfFuel, float _maxAmountOfFuel) : Engine(_currentAmountOfFuel, _maxAmountOfFuel)
{
	fuelType = _fuelType;
}

void FuelEngine::refueling(float amountOfFuelToAdd, FuelTypeEnum _fuelType)
{
	if (fuelType != _fuelType)
	{
		throw new exception;
	}

	recharge(amountOfFuelToAdd);
}

string FuelEngine::toString()
{
	string toString = "";

	toString += "Fuel type: " + GarageLogicUtils::fuelTypeEnumToString(fuelType) + '\n';
	toString += "Remaining fuel percentage: " + to_string(getRemainingEnergyPercentage()) + '\n';
	
	return toString;
}
