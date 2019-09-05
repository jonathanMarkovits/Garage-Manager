#include "pch.h"
#include "Program.h"


Program::Program()
{
}


Program::~Program()
{
}

void Program::run()
{
	SubMenu* main = new SubMenu("Garage Manager");
	MainMenu* mainMenu = new MainMenu(main);
	Menu* insert = new Insert();
	Menu* licenseNumberList = new LicenseNumbersList();
	Menu* changeStatus = new ChangeStatus();
	Menu* inflate = new Inflate();
	Menu* refuel = new Refuel();
	Menu* charge = new Charge();
	Menu* display = new Display();

	main->addItem(insert);
	main->addItem(licenseNumberList);
	main->addItem(changeStatus);
	main->addItem(inflate);
	main->addItem(refuel);
	main->addItem(charge);
	main->addItem(display);
	mainMenu->run();
}
