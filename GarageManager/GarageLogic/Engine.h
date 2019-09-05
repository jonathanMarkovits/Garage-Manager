#pragma once

class Engine
{

protected:
	float currentAmountOfEnergy;
	float maxAmountOfEnergy;

public:
	Engine();
	~Engine();
	Engine(float _currentAmountOfEnergy, float _maxAmountOfEnergy);
	void recharge(float amountOfEnergyToAdd);
};

