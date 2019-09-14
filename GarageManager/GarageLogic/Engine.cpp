#include "stdafx.h"
#include "Engine.h"


Engine::Engine()
{
}


Engine::~Engine()
{
}

Engine::Engine(float i_CurrentAmountOfEnergy, float i_MaxAmountOfEnergy)
{
	m_CurrentAmountOfEnergy = i_CurrentAmountOfEnergy;
	m_MaxAmountOfEnergy = i_MaxAmountOfEnergy;
}

void Engine::recharge(float i_AmountOfEnergyToAdd)
{
	if (i_AmountOfEnergyToAdd + m_CurrentAmountOfEnergy > m_MaxAmountOfEnergy)
	{
		throw range_error("The amount of fuel you try to add exceeds the capacity.");
	}

	m_CurrentAmountOfEnergy += i_AmountOfEnergyToAdd;
}

float Engine::getRemainingEnergyPercentage()
{
	return (m_CurrentAmountOfEnergy / m_MaxAmountOfEnergy) * 100;
}
