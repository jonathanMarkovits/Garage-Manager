#include "stdafx.h"
#include "GarageLogicUtils.h"


GarageLogicUtils::GarageLogicUtils()
{
}


GarageLogicUtils::~GarageLogicUtils()
{
}

string GarageLogicUtils::fuelTypeEnumToString(FuelTypeEnum fuelType)
{
	string str = "";

	switch (fuelType)
	{
	case (FuelTypeEnum::octane95):
		str = "Octane 95";
		break;
	case (FuelTypeEnum::octane96):
		str = "Octane 96";
		break;
	case (FuelTypeEnum::octane98):
		str = "Octane 98";
		break;
	case (FuelTypeEnum::soler):
		str = "Soler";
		break;
	default:
		break;
	}

	return str;
}

string GarageLogicUtils::colorEnumToString(ColorEnum color)
{
	string str = "";

	switch (color)
	{
	case (ColorEnum::black):
		str = "Black";
		break;
	case (ColorEnum::blue):
		str = "Blue";
		break;
	case (ColorEnum::gray):
		str = "Gray";
		break;
	case (ColorEnum::red):
		str = "Red";
		break;
	default:
		break;
	}

	return str;
}

string GarageLogicUtils::licenseTypeEnumToString(LicenseTypeEnum licenseType)
{
	string str = "";

	switch (licenseType)
	{
	case (LicenseTypeEnum::A):
		str = "A";
		break;
	case (LicenseTypeEnum::A1):
		str = "A1";
		break;
	case (LicenseTypeEnum::A2):
		str = "A2";
		break;
	case (LicenseTypeEnum::B):
		str = "B";
		break;
	default:
		break;
	}

	return str;
}

string GarageLogicUtils::statusEnumToString(StatusEnum status)
{
	string str = "";

	switch (status)
	{
	case (StatusEnum::inRepair):
		str = "In repair";
		break;
	case (StatusEnum::repaired):
		str = "Repaired";
		break;
	case (StatusEnum::payedFor):
		str = "Payed for";
		break;
	default:
		break;
	}

	return str;
}
