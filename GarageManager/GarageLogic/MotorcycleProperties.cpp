#include "stdafx.h"
#include "MotorcycleProperties.h"


MotorcycleProperties::MotorcycleProperties()
{
}


MotorcycleProperties::~MotorcycleProperties()
{
}

MotorcycleProperties::MotorcycleProperties(LicenseTypeEnum _licenseType, int _engineVolume)
{
	licenseType = _licenseType;
	engineVolume = _engineVolume;
}

LicenseTypeEnum MotorcycleProperties::getLicenseType()
{
	return licenseType;
}

int MotorcycleProperties::getEngineVolume()
{
	return engineVolume;
}
