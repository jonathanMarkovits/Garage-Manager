#pragma once
#include "ColorEnum.h"
#include "FuelTypeEnum.h"
#include "LicenseTypeEnum.h"
#include "StatusEnum.h"
#include <string>
using namespace std;

class GarageLogicUtils
{
public:
	GarageLogicUtils();
	~GarageLogicUtils();
	static string fuelTypeEnumToString(FuelTypeEnum fuelType);
	static string colorEnumToString(ColorEnum color);
	static string licenseTypeEnumToString(LicenseTypeEnum licenseType);
	static string statusEnumToString(StatusEnum status);
};

