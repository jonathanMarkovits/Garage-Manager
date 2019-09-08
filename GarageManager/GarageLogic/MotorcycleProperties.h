#pragma once
#include "LicenseTypeEnum.h"

class MotorcycleProperties
{

	LicenseTypeEnum licenseType;
	int engineVolume;

public:
	MotorcycleProperties();
	~MotorcycleProperties();
	MotorcycleProperties(LicenseTypeEnum _licenseType, int _engineVolume);
	LicenseTypeEnum getLicenseType();
	int getEngineVolume();
};

