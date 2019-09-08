#include "stdafx.h"
#include "Owner.h"


Owner::Owner(string _name, string _phoneNumber)
{
	name = _name;
	phoneNumber = _phoneNumber;
}

Owner::Owner()
{
}

Owner::~Owner()
{
}

string Owner::toString()
{
	string toString = "";

	toString += "Owner's name: " + name + '\n';
	toString += "Owner's phone number: " + phoneNumber + '\n';

	return toString;
}
