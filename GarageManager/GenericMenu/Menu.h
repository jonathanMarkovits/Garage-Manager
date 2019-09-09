#pragma once
#include <string>
#include <vector>
using namespace std;

class Menu
{
	typedef void(*activateFunctionDef)();

protected:
	vector<activateFunctionDef> m_ActivateFunctions;
	string m_Name;
	bool m_Visible;

public:
	Menu();
	~Menu();
	Menu(string i_Name);
	Menu(activateFunctionDef i_ActivateFunctions, string i_Name);
	string GetName();
	void InsertActivateFunction(activateFunctionDef i_ActivateFunction);
	bool GetVisiblity();
	void SetVisiblity(bool i_Visible);
	vector<activateFunctionDef> GetActivateFunctions();
	virtual void Activate();

protected:
	virtual void dummy() = 0;
};

