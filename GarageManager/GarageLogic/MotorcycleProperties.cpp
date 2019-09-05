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
