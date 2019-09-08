#pragma once
#include <string>
using namespace std;

class Owner
{

	string name;
	string phoneNumber;

public:
	Owner(string _name, string _phoneNumber);
	Owner();
	~Owner();
	string toString();
};

