#pragma once
#include <string>
#include "Owner.h"
#include "VehicleProperties.h"
#include "Engine.h"
//#include "StatusEnum.h"
using namespace std;

class Vehicle
{

	Owner* owner;
	VehicleProperties* properties;
	Engine* engine;
//	StatusEnum status;

public:
	Vehicle();
	~Vehicle();
	Vehicle(Owner* _owner, VehicleProperties* _properties, Engine* _engine);
	string toString();
};