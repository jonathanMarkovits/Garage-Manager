#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Wheel.h"
using namespace std;

class VehicleProperties
{

	vector<Wheel*> wheels;
	string modelName;
	string licenseNumber;
	float remainingEnergyPercentage;

public:
	VehicleProperties();
	~VehicleProperties();
	VehicleProperties(string _modelName, string _licenseNumber, float _remainingEnergyPercentage, vector<Wheel*> _wheels);
	string toString();
};

