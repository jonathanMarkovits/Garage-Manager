#pragma once
#include <string>
#include <vector>
using namespace std;

class Menu
{
	typedef void(*activateFunctionDef)();

protected:
	vector<activateFunctionDef> activateFunctions;
	string name;
	bool visible;

public:
	Menu();
	~Menu();
	Menu(string _name);
	Menu(activateFunctionDef _act, string _name);
	string getName();
	vector<activateFunctionDef> getActivateFunctions();
	void insertActivateFunction(activateFunctionDef _activateFunction);
	bool getVisible();
	void setVisible(bool _visible);
	virtual void activate();
	virtual void dummy() = 0;
};

