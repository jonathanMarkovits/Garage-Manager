#pragma once
#include <string>
#include "Engine.h"
using namespace std;

class FuelEngine : public Engine
{

	string fuelType;

public:
	FuelEngine();
	~FuelEngine();
	FuelEngine(string _fuelType, float _currentAmountOfFuel, float _maxAmountOfFuel);
	void refueling(float amountOfFuelToAdd, string _fuelType);
};

