#pragma once
#include <string>
#include "Owner.h"
#include "VehicleProperties.h"
#include "Engine.h"
#include "GarageLogicUtils.h"
using namespace std;

class Vehicle
{

	Owner* owner;
	VehicleProperties* properties;
	Engine* engine;
	StatusEnum status;

public:
	Vehicle();
	~Vehicle();
	Vehicle(Owner* _owner, VehicleProperties* _properties, Engine* _engine);
	virtual string toString();
	VehicleProperties* getProperties();
	void setStatus(StatusEnum _status);
	StatusEnum getStatus();
	Engine* getEngine();
};