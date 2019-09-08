#pragma once
#include <string>
//#include <iomanip>
#include "MainMenu.h"
#include "SubMenu.h"
#include "InstantMenu.h"
#include "Car.h"
#include "FuelEngine.h"
#include "ElectricEngine.h"
#include "Motorcycle.h"
#include "Truck.h"
#include "Garage.h"
using namespace std;

class Program
{
public:
	static Garage* garage;
	static Vehicle* currentVehicle;
	static SubMenu* vehicleOperation;
	static SubMenu* refuel;
	static MenuItem* charge;
	static bool validVehicle;

	Program();
	~Program();
	static void run();
	static VehicleProperties* getVehicleProperties(int numberOfWheels, float maxAirPressure);
	static Owner* getOwnersDetails();
	static CarProperties* getCarProperties();
	static FuelEngine* getFuelEngineDetails(float maxAmountOfFuel);
	static ElectricEngine* getElectricEngineDetails(float maxAmountOfEnergy);
	static MotorcycleProperties* getMotorcycleProperties();
	static string getLicenseNumber();
	static TruckProperties* getTruckProperties();
	static void vehicleOperationActivate();
	static void fuelOrElectricMenu();
	static void insertFuelBasedMotorcycleActivate();
	static void insertElectricMotorcycleActivate();
	static void insertFuelBasedCarActivate();
	static void insertElectricCarActivate();
	static void insertFuelBasedTruckActivate();
	static void displayListWithFilters(bool inRepair, bool repaired, bool payedFor);
	static void displayAllActivate();
	static void displayInRepairActivate();
	static void displayRepairedActivate();
	static void displayPayedForActivate();
	static void inRepairActivate();
	static void repairedActivate();
	static void payedForActivate();
	static void inflateActivate();
	static void refuelActivate(FuelTypeEnum fuelType);
	static void solerActivate();
	static void octane95Activate();
	static void octane96Activate();
	static void octane98Activate();
	static void chargeActivate();
	static void displayActivate();
};

