#include "pch.h"
#include "Program.h"

typedef void(*activateFunctionDef)();

Garage* Program::garage = new Garage();
Vehicle* Program::currentVehicle = nullptr;
SubMenu* Program::vehicleOperation = nullptr;
SubMenu* Program::refuel = nullptr;
MenuItem* Program::charge = nullptr;
bool Program::validVehicle = false;

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

	SubMenu* insert = new SubMenu("Insert a new vehicle into the garage");
	MenuItem* insertFuelBasedMotorcycle = new MenuItem(&insertFuelBasedMotorcycleActivate, "Fuel-Based Motorcycle\n   2 tires with max air pressure of 33 (psi), Octane 95 (fuel), 8 liters fuel tank\n");
	MenuItem* insertElectricMotorcycle = new MenuItem(&insertElectricMotorcycleActivate, "Electric Motorcycle\n   2 tires with max air pressure of 33 (psi), Max battery life – 1.4 hours\n");
	MenuItem* insertFuelBasedCar = new MenuItem(&insertFuelBasedCarActivate, "Fuel-Based Car\n   4 tires with max air pressure of 31 (psi), Octane 96 fuel, 55 liter fuel tank\n");
	MenuItem* insertElectricCar = new MenuItem(&insertElectricCarActivate, "Electric Car\n   4 tires with max air pressure of 31 (psi), Max battery life – 1.8 hours\n");
	MenuItem* insertFuelBasedTruck = new MenuItem(&insertFuelBasedTruckActivate, "Fuel-Based Truck\n   12 tires with max air pressure of 26 (psi), Soler fuel, 110 liter fuel tank\n");

	SubMenu* licenseNumberList = new SubMenu("Display a list of license numbers currently in the garage");
	MenuItem* displayAll = new MenuItem(&displayAllActivate, "Display all license numbers.");
	MenuItem* displayInRepair = new MenuItem(&displayInRepairActivate, "Display 'In repair' license numbers.");
	MenuItem* displayRepaired = new MenuItem(&displayRepairedActivate, "Display 'Repaired' license numbers.");
	MenuItem* displayPayedFor = new MenuItem(&displayPayedForActivate, "Display 'Payed for' license numbers.");

	vehicleOperation = new SubMenu("Find a vehicle by license number");
	vehicleOperation->insertActivateFunction((activateFunctionDef)&vehicleOperationActivate);
	vehicleOperation->insertActivateFunction((activateFunctionDef)&fuelOrElectricMenu);
	
	SubMenu* changeStatus = new SubMenu("Change status");
	MenuItem* inRepair = new MenuItem(&inRepairActivate, "In repair");
	MenuItem* repaired = new MenuItem(&repairedActivate, "Repaired");
	MenuItem* payedFor = new MenuItem(&payedForActivate, "Payed for");

	MenuItem* inflate = new MenuItem(&inflateActivate, "Inflate tires to maximum.");

	refuel = new SubMenu("Refuel");
	MenuItem* soler = new MenuItem(&solerActivate, "Soler");
	MenuItem* octane95 = new MenuItem(&octane95Activate, "Octane 95");
	MenuItem* octane96 = new MenuItem(&octane96Activate, "Octane 96");
	MenuItem* octane98 = new MenuItem(&octane98Activate, "Octane 98");

	charge = new MenuItem(&chargeActivate, "Charge");
	MenuItem* display = new MenuItem(&displayActivate, "Display vehicle information.");

	licenseNumberList->addItem(displayAll);
	licenseNumberList->addItem(displayInRepair);
	licenseNumberList->addItem(displayRepaired);
	licenseNumberList->addItem(displayPayedFor);

	refuel->addItem(soler);
	refuel->addItem(octane95);
	refuel->addItem(octane96);
	refuel->addItem(octane98);

	insert->addItem(insertFuelBasedMotorcycle);
	insert->addItem(insertElectricMotorcycle);
	insert->addItem(insertFuelBasedCar);
	insert->addItem(insertElectricCar);
	insert->addItem(insertFuelBasedTruck);

	main->addItem(insert);
	main->addItem(licenseNumberList);
	main->addItem(vehicleOperation);

	vehicleOperation->addItem(changeStatus);
	vehicleOperation->addItem(inflate);
	vehicleOperation->addItem(refuel);
	vehicleOperation->addItem(charge);
	vehicleOperation->addItem(display);

	changeStatus->addItem(inRepair);
	changeStatus->addItem(repaired);
	changeStatus->addItem(payedFor);
//	std::cout << std::fixed;
//	std::cout << std::setprecision(2);
	mainMenu->run();
}

VehicleProperties* Program::getVehicleProperties(int numberOfWheels, float maxAirPressure)
{
	string modelName = "";
	string licenseNumber = "";
	string wheelManufacturerName = "";
	vector<Wheel*> wheels;
	Wheel* wheel;
	float currentAirPressure = 0;

	cout << "Please enter the model name.\n";
	cin >> modelName;
	cout << "Please enter the license number.\n";
	cin >> licenseNumber;
	cout << "Please enter the wheels' manufacturer name.\n";
	cin >> wheelManufacturerName;
	for (int i = 0; i < numberOfWheels; i++)
	{
		cout << "Please enter the current air pressure of wheel number " << (i + 1) << ".\n";
		cin >> currentAirPressure;
		wheel = new Wheel(wheelManufacturerName, currentAirPressure, maxAirPressure);
		wheels.push_back(wheel);
	}

	return new VehicleProperties(modelName, licenseNumber, wheels);
}

Owner* Program::getOwnersDetails()
{
	string name = "";
	string phoneNumber = "";
	
	cout << "Please enter the owner's name.\n";
	cin >> name;
	cout << "Please type the owner's phone number.\n";
	cin >> phoneNumber;

	return new Owner(name, phoneNumber);
}

CarProperties* Program::getCarProperties()
{
	SubMenu* menu = new SubMenu("Please choose the right color");
	InstantMenu* colorMenu = new InstantMenu(menu);
	MenuItem* black = new MenuItem("Black");
	MenuItem* blue = new MenuItem("Blue");
	MenuItem* gray = new MenuItem("Gray");
	MenuItem* red = new MenuItem("Red");
	ColorEnum color = (ColorEnum)0;
	int numberOfDoors = 0;

	menu->addItem(black);
	menu->addItem(blue);
	menu->addItem(gray);
	menu->addItem(red);
	color = (ColorEnum)(colorMenu->run() - 1);
	cout << "Please enter the amount of doors.\n";
	cin >> numberOfDoors;

	return new CarProperties(color, numberOfDoors);
}

FuelEngine* Program::getFuelEngineDetails(float maxAmountOfFuel)
{
	FuelTypeEnum fuelType = (FuelTypeEnum)0;
	float currentAmountOfFuel = 0;
	SubMenu* menu = new SubMenu("Choose the fuel's type:");
	MenuItem* soler = new MenuItem("Soler");
	MenuItem* octane95 = new MenuItem("Octane 95");
	MenuItem* octane96 = new MenuItem("Octane 96");
	MenuItem* octane98 = new MenuItem("Octane 98");
	InstantMenu* fuelMenu = new InstantMenu(menu);

	menu->addItem(soler);
	menu->addItem(octane95);
	menu->addItem(octane96);
	menu->addItem(octane98);
	fuelType = (FuelTypeEnum)(fuelMenu->run() - 1);
	cout << "Please enter the current amount of fuel.\n";
	cin >> currentAmountOfFuel;
	
	return new FuelEngine(fuelType, maxAmountOfFuel, currentAmountOfFuel);
}

ElectricEngine* Program::getElectricEngineDetails(float maxAmountOfEnergy)
{
	float currentAmountOfEnergy = 0;

	cout << "Please enter the current amount of fuel.\n";
	cin >> currentAmountOfEnergy;

	return new ElectricEngine(currentAmountOfEnergy, maxAmountOfEnergy);
}

MotorcycleProperties* Program::getMotorcycleProperties()
{
	SubMenu* menu = new SubMenu("Please choose the license's type.");
	InstantMenu* licenseTypeMenu = new InstantMenu(menu);
	MenuItem* a = new MenuItem("A");
	MenuItem* a1 = new MenuItem("A1");
	MenuItem* a2 = new MenuItem("A2");
	MenuItem* b = new MenuItem("B");
	LicenseTypeEnum licenseType = (LicenseTypeEnum)0;
	int engineVolume = 0;

	menu->addItem(a);
	menu->addItem(a1);
	menu->addItem(a2);
	menu->addItem(b);
	licenseType = (LicenseTypeEnum)(licenseTypeMenu->run() - 1);
	cout << "Please enter the engine's volume.\n";
	cin >> engineVolume;

	return new MotorcycleProperties(licenseType, engineVolume);
}

string Program::getLicenseNumber()
{
	string licenseNumber = "";

	cout << "Please enter a license number.\n";
	cin >> licenseNumber;

	return licenseNumber;
}

TruckProperties* Program::getTruckProperties()
{
	char ans = 0;
	bool containsDangerousMaterials = false;
	bool firstTry = true;
	float volumeOfCargo = 0;

	cout << "Does the truck contains toxic dangerous materials? (y/n)\n";
	while (ans != 'y' && ans != 'n')
	{
		if (!firstTry)
		{
			cout << "The program expects 'y' or 'n' only.\n";
		}
		else
		{
			firstTry = false;
		}

		cin >> ans;
	}
	if (ans == 'y')
	{
		containsDangerousMaterials = true;
	}

	cout << "Please enter the volume of the cargo.\n";
	cin >> volumeOfCargo;
	
	return new TruckProperties(containsDangerousMaterials, volumeOfCargo);
}

void Program::vehicleOperationActivate()
{
	string licenseNumber = Program::getLicenseNumber();
	Program::currentVehicle = Program::garage->getVehicleByLicenseNumber(licenseNumber);

	Program::vehicleOperation->setIsBlocked(false);
	Program::validVehicle = true;
	if (!Program::currentVehicle)
	{
		Program::vehicleOperation->setIsBlocked(true);
		cout << "This license number is not registered.\n";
		Program::validVehicle = false;
	}
}

void Program::fuelOrElectricMenu()
{
	FuelEngine* fuelEnginePtr;
	
	if (Program::validVehicle)
	{
		fuelEnginePtr = dynamic_cast<FuelEngine*>(Program::currentVehicle->getEngine());

		if (fuelEnginePtr)
		{
			Program::refuel->setVisible(true);
			Program::charge->setVisible(false);
		}
		else
		{
			Program::refuel->setVisible(false);
			Program::charge->setVisible(true);
		}
	}
}

void Program::insertFuelBasedMotorcycleActivate()
{
	Owner* owner = Program::getOwnersDetails();
	VehicleProperties* vehicleProperties = Program::getVehicleProperties(2, 33);
	Engine* engine = Program::getFuelEngineDetails(8);
	MotorcycleProperties* motorcyclePropertise = Program::getMotorcycleProperties();
	Vehicle* motorcycle = new Motorcycle(owner, vehicleProperties, engine, motorcyclePropertise);

	Program::garage->addVehicle(motorcycle);
}

void Program::insertElectricMotorcycleActivate()
{
	Owner* owner = Program::getOwnersDetails();
	VehicleProperties* vehicleProperties = Program::getVehicleProperties(2, 33);
	Engine* engine = Program::getElectricEngineDetails(1.4);
	MotorcycleProperties* motorcycleProperties = Program::getMotorcycleProperties();
	Vehicle* motorcycle = new Motorcycle(owner, vehicleProperties, engine, motorcycleProperties);

	Program::garage->addVehicle(motorcycle);
}

void Program::insertFuelBasedCarActivate()
{
	Owner* owner = Program::getOwnersDetails();
	VehicleProperties* vehicleProperties = Program::getVehicleProperties(4, 31);
	Engine* engine = Program::getFuelEngineDetails(55);
	CarProperties* carProperties = Program::getCarProperties();
	Vehicle* car = new Car(owner, vehicleProperties, engine, carProperties);

	Program::garage->addVehicle(car);
}

void Program::insertElectricCarActivate()
{
	Owner* owner = Program::getOwnersDetails();
	VehicleProperties* vehicleProperties = Program::getVehicleProperties(4, 31);
	Engine* engine = Program::getElectricEngineDetails(1.8);
	CarProperties* carProperties = Program::getCarProperties();
	Vehicle* car = new Car(owner, vehicleProperties, engine, carProperties);

	Program::garage->addVehicle(car);
}

void Program::insertFuelBasedTruckActivate()
{
	Owner* owner = Program::getOwnersDetails();
	VehicleProperties* vehicleProperties = Program::getVehicleProperties(12, 26);
	Engine* engine = Program::getFuelEngineDetails(110);
	TruckProperties* truckProperties = Program::getTruckProperties();
	Vehicle* truck = new Truck(owner, vehicleProperties, engine, truckProperties);

	Program::garage->addVehicle(truck);
}

void Program::displayListWithFilters(bool inRepair, bool repaired, bool payedFor)
{
	string str = "";
	int i = 1;

	for (Vehicle* vehicle : Program::garage->getVehicles())
	{
		if (!inRepair && vehicle->getStatus() == StatusEnum::inRepair ||
			!repaired && vehicle->getStatus() == StatusEnum::repaired ||
			!payedFor && vehicle->getStatus() == StatusEnum::payedFor)
		{
			continue;
		}

		str += to_string(i++) + ". " + vehicle->getProperties()->getLicenseNumber() + '\n';
	}

	cout << str;
}

void Program::displayAllActivate()
{
	displayListWithFilters(true, true, true);
}

void Program::displayInRepairActivate()
{
	displayListWithFilters(true, false, false);
}

void Program::displayRepairedActivate()
{
	displayListWithFilters(false, true, false);
}

void Program::displayPayedForActivate()
{
	displayListWithFilters(false, false, true);
}

void Program::inRepairActivate()
{
	Program::currentVehicle->setStatus(StatusEnum::inRepair);
}

void Program::repairedActivate()
{
	Program::currentVehicle->setStatus(StatusEnum::repaired);
}

void Program::payedForActivate()
{
	Program::currentVehicle->setStatus(StatusEnum::payedFor);
}

void Program::inflateActivate()
{
	for (Wheel* wheel : Program::currentVehicle->getProperties()->getWheels())
	{
		wheel->inflateAction(INT_MAX);
	}

	cout << "The wheels were inflated successfully.";
}

void Program::refuelActivate(FuelTypeEnum fuelType)
{
	float amountOfFuelToAdd = 0;

	cout << "Please enter the amount of liters to refuel.\n";
	cin >> amountOfFuelToAdd;
	((FuelEngine*)Program::currentVehicle->getEngine())->refueling(amountOfFuelToAdd, fuelType);
}


void Program::solerActivate()
{
	try
	{
		refuelActivate(FuelTypeEnum::soler);
	}
	catch (...)
	{
		cout << "\nSoler is not the appropiate type of fuel for this vehicle.";
	}
}

void Program::octane95Activate()
{
	try
	{
		refuelActivate(FuelTypeEnum::octane95);
	}
	catch (...)
	{
		cout << "\nOctane 95 is not the appropiate type of fuel for this vehicle.";
	}
}

void Program::octane96Activate()
{
	try
	{
		refuelActivate(FuelTypeEnum::octane96);
	}
	catch (...)
	{
		cout << "\nOctane 96 is not the appropiate type of fuel for this vehicle.";
	}
}

void Program::octane98Activate()
{
	try
	{
		refuelActivate(FuelTypeEnum::octane98);
	}
	catch (...)
	{
		cout << "\nOctane 98 is not the appropiate type of fuel for this vehicle.";
	}
}

void Program::chargeActivate()
{
	float amountOfEnergyToAdd = 0;

	cout << "Please enter the amount of minutes to charge.";
	cin >> amountOfEnergyToAdd;
	((ElectricEngine*)Program::currentVehicle->getEngine())->recharge(amountOfEnergyToAdd);
}

void Program::displayActivate()
{
	cout << Program::currentVehicle->toString();
}

