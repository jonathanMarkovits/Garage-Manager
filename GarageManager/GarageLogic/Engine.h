#pragma once
#include <string>
using namespace std;

class Engine
{

protected:
	float m_CurrentAmountOfEnergy;
	float m_MaxAmountOfEnergy;

public:
	Engine();
	~Engine();
	Engine(float _currentAmountOfEnergy, float _maxAmountOfEnergy);
	void recharge(float amountOfEnergyToAdd);
	virtual string toString() = 0;
	float getRemainingEnergyPercentage();
};

