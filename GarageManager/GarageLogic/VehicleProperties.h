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

public:
	VehicleProperties();
	~VehicleProperties();
	VehicleProperties(string _modelName, string _licenseNumber, vector<Wheel*> _wheels);
	string toString();
	string getLicenseNumber();
	vector<Wheel*> getWheels();
};

