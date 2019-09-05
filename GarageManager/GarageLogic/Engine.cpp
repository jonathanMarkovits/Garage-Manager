#include "stdafx.h"
#include "Engine.h"


Engine::Engine()
{
}


Engine::~Engine()
{
}

Engine::Engine(float _currentAmountOfEnergy, float _maxAmountOfEnergy)
{
	currentAmountOfEnergy = _currentAmountOfEnergy;
	maxAmountOfEnergy = _maxAmountOfEnergy;
}

void Engine::recharge(float amountOfEnergyToAdd)
{
	if (amountOfEnergyToAdd + currentAmountOfEnergy > maxAmountOfEnergy)
	{

	}

	currentAmountOfEnergy += amountOfEnergyToAdd;
}
