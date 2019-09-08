#pragma once
#include "Engine.h"
#include <string>
using namespace std;

class ElectricEngine : public Engine
{
public:
	ElectricEngine();
	~ElectricEngine();
	ElectricEngine(float _currentAmountOfEnergy, float _maxAmountOfEnergy);
	string toString() override;
};

