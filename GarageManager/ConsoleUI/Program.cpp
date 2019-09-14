#include "pch.h"
#include "Program.h"

typedef void(*activateFunctionDef)();

Garage* Program::s_Garage = new Garage();
Vehicle* Program::s_CurrentVehicle = nullptr;
SubMenu* Program::s_VehicleOperation = nullptr;
SubMenu* Program::s_Refuel = nullptr;
MenuItem* Program::s_Charge = nullptr;
bool Program::s_ValidVehicle = false;

Program::Program()
{
}

Program::~Program()
{
}

void Program::Run()
{
	SubMenu* main = new SubMenu("Garage Manager");
	MainMenu* mainMenu = new MainMenu(main);

	SubMenu* insert = new SubMenu("Insert a new vehicle into the garage");
	MenuItem* insertFuelBasedMotorcycle = new MenuItem(&InsertFuelBasedMotorcycleActivate, "Fuel-Based Motorcycle\n   2 tires with max air pressure of 33 (psi), Octane 95 (fuel), 8 liters fuel tank\n");
	MenuItem* insertElectricMotorcycle = new MenuItem(&InsertElectricMotorcycleActivate, "Electric Motorcycle\n   2 tires with max air pressure of 33 (psi), Max battery life – 1.4 hours\n");
	MenuItem* insertFuelBasedCar = new MenuItem(&InsertFuelBasedCarActivate, "Fuel-Based Car\n   4 tires with max air pressure of 31 (psi), Octane 96 fuel, 55 liter fuel tank\n");
	MenuItem* insertElectricCar = new MenuItem(&InsertElectricCarActivate, "Electric Car\n   4 tires with max air pressure of 31 (psi), Max battery life – 1.8 hours\n");
	MenuItem* insertFuelBasedTruck = new MenuItem(&InsertFuelBasedTruckActivate, "Fuel-Based Truck\n   12 tires with max air pressure of 26 (psi), Soler fuel, 110 liter fuel tank\n");

	SubMenu* licenseNumberList = new SubMenu("Display a list of license numbers currently in the garage");
	MenuItem* displayAll = new MenuItem(&DisplayAllActivate, "Display all license numbers.");
	MenuItem* displayInRepair = new MenuItem(&DisplayInRepairActivate, "Display 'In repair' license numbers.");
	MenuItem* displayRepaired = new MenuItem(&DisplayRepairedActivate, "Display 'Repaired' license numbers.");
	MenuItem* displayPayedFor = new MenuItem(&DisplayPayedForActivate, "Display 'Payed for' license numbers.");

	s_VehicleOperation = new SubMenu("Find a vehicle by license number");
	s_VehicleOperation->InsertActivateFunction((activateFunctionDef)&VehicleOperationActivate);
	s_VehicleOperation->InsertActivateFunction((activateFunctionDef)&FuelOrElectricMenu);
	
	SubMenu* changeStatus = new SubMenu("Change status");
	MenuItem* inRepair = new MenuItem(&InRepairActivate, GarageLogicUtils::statusEnumToString(StatusEnum::inRepair));
	MenuItem* repaired = new MenuItem(&RepairedActivate, GarageLogicUtils::statusEnumToString(StatusEnum::repaired));
	MenuItem* payedFor = new MenuItem(&PayedForActivate, GarageLogicUtils::statusEnumToString(StatusEnum::payedFor));

	MenuItem* inflate = new MenuItem(&InflateActivate, "Inflate tires to maximum");

	s_Refuel = new SubMenu("Refuel");
	MenuItem* soler = new MenuItem(&SolerActivate, GarageLogicUtils::fuelTypeEnumToString(FuelTypeEnum::soler));
	MenuItem* octane95 = new MenuItem(&Octane95Activate, GarageLogicUtils::fuelTypeEnumToString(FuelTypeEnum::octane95));
	MenuItem* octane96 = new MenuItem(&Octane96Activate, GarageLogicUtils::fuelTypeEnumToString(FuelTypeEnum::octane96));
	MenuItem* octane98 = new MenuItem(&Octane98Activate, GarageLogicUtils::fuelTypeEnumToString(FuelTypeEnum::octane98));

	s_Charge = new MenuItem(&ChargeActivate, "Charge");
	MenuItem* display = new MenuItem(&DisplayActivate, "Display vehicle information");

	licenseNumberList->AddItem(displayAll);
	licenseNumberList->AddItem(displayInRepair);
	licenseNumberList->AddItem(displayRepaired);
	licenseNumberList->AddItem(displayPayedFor);

	s_Refuel->AddItem(soler);
	s_Refuel->AddItem(octane95);
	s_Refuel->AddItem(octane96);
	s_Refuel->AddItem(octane98);

	insert->AddItem(insertFuelBasedMotorcycle);
	insert->AddItem(insertElectricMotorcycle);
	insert->AddItem(insertFuelBasedCar);
	insert->AddItem(insertElectricCar);
	insert->AddItem(insertFuelBasedTruck);

	main->AddItem(insert);
	main->AddItem(licenseNumberList);
	main->AddItem(s_VehicleOperation);

	s_VehicleOperation->AddItem(changeStatus);
	s_VehicleOperation->AddItem(inflate);
	s_VehicleOperation->AddItem(s_Refuel);
	s_VehicleOperation->AddItem(s_Charge);
	s_VehicleOperation->AddItem(display);

	changeStatus->AddItem(inRepair);
	changeStatus->AddItem(repaired);
	changeStatus->AddItem(payedFor);
	
	mainMenu->Run();
}

VehicleProperties* Program::GetVehicleProperties(int i_NumberOfWheels, float i_MaxAirPressure)
{
	string modelName = "";
	string licenseNumber = "";
	string wheelManufacturerName = "";
	vector<Wheel*> wheels;
	Wheel* wheel = nullptr;
	float currentAirPressure = 0;
	bool uniqueLicenseNumber = false;
	bool firstTime = true;

	cout << "Please enter the model name." << endl;
	cin >> modelName;
	cout << "Please enter the license number." << endl;
	while (!uniqueLicenseNumber)
	{
		if (!firstTime)
		{
			cout << "This license number already exsists in the garage, please enter a unique one." << endl;
		}

		cin >> licenseNumber;
		firstTime = false;
		if (!Program::s_Garage->getVehicleByLicenseNumber(licenseNumber))
		{
			uniqueLicenseNumber = true;
		}
	}

	cout << "Please enter the wheels' manufacturer name." << endl;
	cin >> wheelManufacturerName;
	for (int i = 0; i < i_NumberOfWheels; i++)
	{
		cout << "Please enter the current air pressure of wheel number " << (i + 1) << '.' << endl;
		cin >> currentAirPressure;
		wheel = new Wheel(wheelManufacturerName, currentAirPressure, i_MaxAirPressure);
		wheels.push_back(wheel);
	}

	return new VehicleProperties(modelName, licenseNumber, wheels);
}

Owner* Program::GetOwnersDetails()
{
	string name = "";
	string phoneNumber = "";
	
	cout << "Please enter the owner's name." << endl;
	cin >> name;
	cout << "Please type the owner's phone number." << endl;
	cin >> phoneNumber;

	return new Owner(name, phoneNumber);
}

CarProperties* Program::GetCarProperties()
{
	SubMenu* menu = new SubMenu("Please choose the right color");
	InstantMenu* colorMenu = new InstantMenu(menu);
	MenuItem* black = new MenuItem(GarageLogicUtils::colorEnumToString(ColorEnum::black));
	MenuItem* blue = new MenuItem(GarageLogicUtils::colorEnumToString(ColorEnum::blue));
	MenuItem* gray = new MenuItem(GarageLogicUtils::colorEnumToString(ColorEnum::gray));
	MenuItem* red = new MenuItem(GarageLogicUtils::colorEnumToString(ColorEnum::red));
	ColorEnum color = (ColorEnum)0;
	int numberOfDoors = 0;

	menu->AddItem(black);
	menu->AddItem(blue);
	menu->AddItem(gray);
	menu->AddItem(red);
	color = (ColorEnum)(colorMenu->Run() - 1);
	cout << "Please enter the amount of doors." << endl;
	cin >> numberOfDoors;

	return new CarProperties(color, numberOfDoors);
}

FuelEngine* Program::GetFuelEngineDetails(float i_MaxAmountOfFuel)
{
	FuelTypeEnum fuelType = (FuelTypeEnum)0;
	float currentAmountOfFuel = 0;
	SubMenu* menu = new SubMenu("Choose the fuel's type:");
	MenuItem* soler = new MenuItem(GarageLogicUtils::fuelTypeEnumToString(FuelTypeEnum::soler));
	MenuItem* octane95 = new MenuItem(GarageLogicUtils::fuelTypeEnumToString(FuelTypeEnum::octane95));
	MenuItem* octane96 = new MenuItem(GarageLogicUtils::fuelTypeEnumToString(FuelTypeEnum::octane96));
	MenuItem* octane98 = new MenuItem(GarageLogicUtils::fuelTypeEnumToString(FuelTypeEnum::octane98));
	InstantMenu* fuelMenu = new InstantMenu(menu);

	menu->AddItem(soler);
	menu->AddItem(octane95);
	menu->AddItem(octane96);
	menu->AddItem(octane98);
	fuelType = (FuelTypeEnum)(fuelMenu->Run() - 1);
	cout << "Please enter the current amount of fuel." << endl;
	cin >> currentAmountOfFuel;
	
	return new FuelEngine(fuelType, currentAmountOfFuel, i_MaxAmountOfFuel);
}

ElectricEngine* Program::GetElectricEngineDetails(float i_MaxAmountOfEnergy)
{
	float currentAmountOfEnergy = 0;

	cout << "Please enter the current amount of fuel." << endl;
	cin >> currentAmountOfEnergy;

	return new ElectricEngine(currentAmountOfEnergy, i_MaxAmountOfEnergy);
}

MotorcycleProperties* Program::GetMotorcycleProperties()
{
	SubMenu* menu = new SubMenu("Please choose the license's type.");
	InstantMenu* licenseTypeMenu = new InstantMenu(menu);
	MenuItem* a = new MenuItem(GarageLogicUtils::licenseTypeEnumToString(LicenseTypeEnum::A));
	MenuItem* a1 = new MenuItem(GarageLogicUtils::licenseTypeEnumToString(LicenseTypeEnum::A1));
	MenuItem* a2 = new MenuItem(GarageLogicUtils::licenseTypeEnumToString(LicenseTypeEnum::A2));
	MenuItem* b = new MenuItem(GarageLogicUtils::licenseTypeEnumToString(LicenseTypeEnum::B));
	LicenseTypeEnum licenseType = (LicenseTypeEnum)0;
	int engineVolume = 0;

	menu->AddItem(a);
	menu->AddItem(a1);
	menu->AddItem(a2);
	menu->AddItem(b);
	licenseType = (LicenseTypeEnum)(licenseTypeMenu->Run() - 1);
	cout << "Please enter the engine's volume." << endl;
	cin >> engineVolume;

	return new MotorcycleProperties(licenseType, engineVolume);
}

string Program::GetLicenseNumber()
{
	string licenseNumber = "";

	cout << "Please enter a license number." << endl;
	cin >> licenseNumber;

	return licenseNumber;
}

TruckProperties* Program::GetTruckProperties()
{
	char ans = 0;
	bool containsDangerousMaterials = false;
	bool firstTry = true;
	float volumeOfCargo = 0;

	cout << "Does the truck contains toxic dangerous materials? (y/n)" << endl;
	while (ans != 'y' && ans != 'n')
	{
		if (!firstTry)
		{
			cout << "The program expects 'y' or 'n' only." << endl;
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

	cout << "Please enter the volume of the cargo." << endl;
	cin >> volumeOfCargo;
	
	return new TruckProperties(containsDangerousMaterials, volumeOfCargo);
}

void Program::VehicleOperationActivate()
{
	string licenseNumber = Program::GetLicenseNumber();
	Program::s_CurrentVehicle = Program::s_Garage->getVehicleByLicenseNumber(licenseNumber);

	Program::s_VehicleOperation->SetIsBlocked(false);
	Program::s_ValidVehicle = true;
	if (!Program::s_CurrentVehicle)
	{
		Program::s_VehicleOperation->SetIsBlocked(true);
		cout << "This license number is not registered." << endl;
		Program::s_ValidVehicle = false;
	}
}

void Program::FuelOrElectricMenu()
{
	FuelEngine* fuelEnginePtr;
	
	if (Program::s_ValidVehicle)
	{
		fuelEnginePtr = dynamic_cast<FuelEngine*>(Program::s_CurrentVehicle->getEngine());

		if (fuelEnginePtr)
		{
			Program::s_Refuel->SetVisiblity(true);
			Program::s_Charge->SetVisiblity(false);
		}
		else
		{
			Program::s_Refuel->SetVisiblity(false);
			Program::s_Charge->SetVisiblity(true);
		}
	}
}

void Program::InsertFuelBasedMotorcycleActivate()
{
	Owner* owner = Program::GetOwnersDetails();
	VehicleProperties* vehicleProperties = Program::GetVehicleProperties(2, 33);
	Engine* engine = Program::GetFuelEngineDetails(8);
	MotorcycleProperties* motorcyclePropertise = Program::GetMotorcycleProperties();
	Vehicle* motorcycle = new Motorcycle(owner, vehicleProperties, engine, motorcyclePropertise);

	Program::s_Garage->addVehicle(motorcycle);
}

void Program::InsertElectricMotorcycleActivate()
{
	Owner* owner = Program::GetOwnersDetails();
	VehicleProperties* vehicleProperties = Program::GetVehicleProperties(2, 33);
	Engine* engine = Program::GetElectricEngineDetails(1.4f);
	MotorcycleProperties* motorcycleProperties = Program::GetMotorcycleProperties();
	Vehicle* motorcycle = new Motorcycle(owner, vehicleProperties, engine, motorcycleProperties);

	Program::s_Garage->addVehicle(motorcycle);
}

void Program::InsertFuelBasedCarActivate()
{
	Owner* owner = Program::GetOwnersDetails();
	VehicleProperties* vehicleProperties = Program::GetVehicleProperties(4, 31);
	Engine* engine = Program::GetFuelEngineDetails(55);
	CarProperties* carProperties = Program::GetCarProperties();
	Vehicle* car = new Car(owner, vehicleProperties, engine, carProperties);

	Program::s_Garage->addVehicle(car);
}

void Program::InsertElectricCarActivate()
{
	Owner* owner = Program::GetOwnersDetails();
	VehicleProperties* vehicleProperties = Program::GetVehicleProperties(4, 31);
	Engine* engine = Program::GetElectricEngineDetails(1.8f);
	CarProperties* carProperties = Program::GetCarProperties();
	Vehicle* car = new Car(owner, vehicleProperties, engine, carProperties);

	Program::s_Garage->addVehicle(car);
}

void Program::InsertFuelBasedTruckActivate()
{
	Owner* owner = Program::GetOwnersDetails();
	VehicleProperties* vehicleProperties = Program::GetVehicleProperties(12, 26);
	Engine* engine = Program::GetFuelEngineDetails(110);
	TruckProperties* truckProperties = Program::GetTruckProperties();
	Vehicle* truck = new Truck(owner, vehicleProperties, engine, truckProperties);

	Program::s_Garage->addVehicle(truck);
}

void Program::DisplayListWithFilters(bool i_InRepair, bool i_Repaired, bool i_PayedFor)
{
	string str = "";
	int i = 1;

	for (Vehicle* vehicle : Program::s_Garage->getVehicles())
	{
		if (!i_InRepair && vehicle->getStatus() == StatusEnum::inRepair ||
			!i_Repaired && vehicle->getStatus() == StatusEnum::repaired ||
			!i_PayedFor && vehicle->getStatus() == StatusEnum::payedFor)
		{
			continue;
		}

		str += to_string(i++) + ". " + vehicle->getProperties()->getLicenseNumber() + '\n';
	}

	cout << str;
}

void Program::DisplayAllActivate()
{
	const bool v_IncludeInRepair = true;
	const bool v_IncludeReparired = true;
	const bool v_IncludePayedFor = true;

	DisplayListWithFilters(v_IncludeInRepair, v_IncludeReparired, v_IncludePayedFor);
}

void Program::DisplayInRepairActivate()
{
	const bool v_IncludeInRepair = true;
	const bool v_IncludeReparired = false;
	const bool v_IncludePayedFor = false;

	DisplayListWithFilters(v_IncludeInRepair, v_IncludeReparired, v_IncludePayedFor);
}

void Program::DisplayRepairedActivate()
{
	const bool v_IncludeInRepair = false;
	const bool v_IncludeReparired = true;
	const bool v_IncludePayedFor = false;

	DisplayListWithFilters(v_IncludeInRepair, v_IncludeReparired, v_IncludePayedFor);
}

void Program::DisplayPayedForActivate()
{
	const bool v_IncludeInRepair = false;
	const bool v_IncludeReparired = false;
	const bool v_IncludePayedFor = true;

	DisplayListWithFilters(v_IncludeInRepair, v_IncludeReparired, v_IncludePayedFor);
}

void Program::InRepairActivate()
{
	Program::s_CurrentVehicle->setStatus(StatusEnum::inRepair);
}

void Program::RepairedActivate()
{
	Program::s_CurrentVehicle->setStatus(StatusEnum::repaired);
}

void Program::PayedForActivate()
{
	Program::s_CurrentVehicle->setStatus(StatusEnum::payedFor);
}

void Program::InflateActivate()
{
	for (Wheel* wheel : Program::s_CurrentVehicle->getProperties()->getWheels())
	{
		wheel->inflateAction(FLT_MAX);
	}
}

void Program::Refuel(FuelTypeEnum i_FuelType)
{
	float amountOfFuelToAdd = 0;

	cout << "Please enter the amount of liters to refuel." << endl;
	cin >> amountOfFuelToAdd;
	((FuelEngine*)Program::s_CurrentVehicle->getEngine())->refueling(amountOfFuelToAdd, i_FuelType);
}


void Program::SolerActivate()
{
	try
	{
		Refuel(FuelTypeEnum::soler);
	}
	catch (invalid_argument& e)
	{
		cout << endl << "Soler is not the appropiate type of fuel for this vehicle.";
	}
	catch (range_error& e)
	{
		cout << endl << "The amount of fuel you try to add exceeds the capacity.";
	}
}

void Program::Octane95Activate()
{
	try
	{
		Refuel(FuelTypeEnum::octane95);
	}
	catch (invalid_argument& e)
	{
		cout << endl << "Octane 95 is not the appropiate type of fuel for this vehicle.";
	}
	catch (range_error& e)
	{
		cout << endl << "The amount of fuel you try to add exceeds the capacity.";
	}
}

void Program::Octane96Activate()
{
	try
	{
		Refuel(FuelTypeEnum::octane96);
	}
	catch (invalid_argument& e)
	{
		cout << endl << "Octane 96 is not the appropiate type of fuel for this vehicle.";
	}
	catch (range_error& e)
	{
		cout << endl << "The amount of fuel you try to add exceeds the capacity.";
	}
}

void Program::Octane98Activate()
{
	try
	{
		Refuel(FuelTypeEnum::octane98);
	}
	catch (invalid_argument& e)
	{
		cout << endl << "Octane 98 is not the appropiate type of fuel for this vehicle.";
	}
	catch (range_error& e)
	{
		cout << endl << "The amount of fuel you try to add exceeds the capacity.";
	}
}

void Program::ChargeActivate()
{
	float amountOfEnergyToAdd = 0;

	cout << "Please enter the amount of minutes to charge." << endl;
	cin >> amountOfEnergyToAdd;
	try
	{
		((ElectricEngine*)Program::s_CurrentVehicle->getEngine())->recharge(amountOfEnergyToAdd);
	}
	catch (range_error& e)
	{
		cout << endl << "The amount of fuel you try to add exceeds the capacity."
	}
}

void Program::DisplayActivate()
{
	cout << Program::s_CurrentVehicle->toString();
}

