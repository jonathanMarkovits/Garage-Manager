#pragma once
#include <string>
using namespace std;

class Menu
{

protected:
	string name;

public:
	Menu();
	~Menu();
	Menu(string _name);
	string getName();
	virtual void dummy();
};

