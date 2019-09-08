#pragma once
#include <vector>
#include "Vehicle.h"
using namespace std;

class Garage
{

	vector<Vehicle*> vehicles;

public:
	Garage();
	~Garage();
	void addVehicle(Vehicle* newVehicle);
	Vehicle* getVehicleByLicenseNumber(string licenseNumber);
	vector<Vehicle*> getVehicles();
};

