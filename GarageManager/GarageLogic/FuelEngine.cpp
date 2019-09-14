#include "stdafx.h"
#include "FuelEngine.h"


FuelEngine::FuelEngine()
{
}


FuelEngine::~FuelEngine()
{
}

FuelEngine::FuelEngine(FuelTypeEnum i_FuelType, float i_CurrentAmountOfFuel, float i_MaxAmountOfFuel) : Engine(i_CurrentAmountOfFuel, i_MaxAmountOfFuel)
{
	m_FuelType = i_FuelType;
}

void FuelEngine::refueling(float i_AmountOfFuelToAdd, FuelTypeEnum i_FuelType)
{
	if (m_FuelType != i_FuelType)
	{
		throw invalid_argument("This is not the right fuel type.");
	}

	recharge(i_AmountOfFuelToAdd);
}

string FuelEngine::toString()
{
	string toString = "";

	toString += "Fuel type: " + GarageLogicUtils::fuelTypeEnumToString(m_FuelType) + '\n';
	toString += "Remaining fuel percentage: " + to_string(getRemainingEnergyPercentage()) + "% (" + to_string(m_MaxAmountOfEnergy - m_CurrentAmountOfEnergy) + " liters to fill)\n";
	
	return toString;
}
