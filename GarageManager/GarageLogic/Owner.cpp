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

string Owner::getName()
{
	return name;
}
