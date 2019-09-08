#pragma once
#include <string>
#include "Engine.h"
#include "GarageLogicUtils.h"
using namespace std;

class FuelEngine : public Engine
{

	FuelTypeEnum fuelType;

public:
	FuelEngine();
	~FuelEngine();
	FuelEngine(FuelTypeEnum _fuelType, float _currentAmountOfFuel, float _maxAmountOfFuel);
	void refueling(float amountOfFuelToAdd, FuelTypeEnum _fuelType);
	string toString() override;
};

