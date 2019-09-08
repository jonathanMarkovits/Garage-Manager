#include "stdafx.h"
#include "TruckProperties.h"


TruckProperties::TruckProperties()
{
}


TruckProperties::~TruckProperties()
{
}

TruckProperties::TruckProperties(bool _containsDangerousMaterials, float _volumeOfCargo)
{
	containsDangerousMaterials = _containsDangerousMaterials;
	volumeOfCargo = _volumeOfCargo;
}

bool TruckProperties::getContainsDangerousMaterials()
{
	return containsDangerousMaterials;
}

float TruckProperties::getVolumeOfCargo()
{
	return volumeOfCargo;
}
