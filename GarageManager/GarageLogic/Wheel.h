#pragma once
#include <string>
using namespace std;

class Wheel
{

	string manufacturerName;
	float currentAirPressure;
	float maxAirPressure;

public:
	Wheel();
	~Wheel();
	Wheel(string _manufacturerName, float _currentAirPressure, float _maxAirPressure);
	void inflateAction(float amountOfAirToInflate);
};

