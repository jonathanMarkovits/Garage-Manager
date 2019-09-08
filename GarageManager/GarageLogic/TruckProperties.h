#pragma once

class TruckProperties
{

	bool containsDangerousMaterials;
	float volumeOfCargo;

public:
	TruckProperties();
	~TruckProperties();
	TruckProperties(bool _containsDangerousMaterials, float _volumeOfCargo);
	bool getContainsDangerousMaterials();
	float getVolumeOfCargo();
};

