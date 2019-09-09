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
	static Garage* s_Garage;
	static Vehicle* s_CurrentVehicle;
	static SubMenu* s_VehicleOperation;
	static SubMenu* s_Refuel;
	static MenuItem* s_Charge;
	static bool s_ValidVehicle;

	Program();
	~Program();
	static void Run();
	static VehicleProperties* GetVehicleProperties(int i_NumberOfWheels, float i_MaxAirPressure);
	static Owner* GetOwnersDetails();
	static CarProperties* GetCarProperties();
	static FuelEngine* GetFuelEngineDetails(float i_MaxAmountOfFuel);
	static ElectricEngine* GetElectricEngineDetails(float i_MaxAmountOfEnergy);
	static MotorcycleProperties* GetMotorcycleProperties();
	static string GetLicenseNumber();
	static TruckProperties* GetTruckProperties();
	static void VehicleOperationActivate();
	static void FuelOrElectricMenu();
	static void InsertFuelBasedMotorcycleActivate();
	static void InsertElectricMotorcycleActivate();
	static void InsertFuelBasedCarActivate();
	static void InsertElectricCarActivate();
	static void InsertFuelBasedTruckActivate();
	static void DisplayListWithFilters(bool i_InRepair, bool i_Repaired, bool i_PayedFor);
	static void DisplayAllActivate();
	static void DisplayInRepairActivate();
	static void DisplayRepairedActivate();
	static void DisplayPayedForActivate();
	static void InRepairActivate();
	static void RepairedActivate();
	static void PayedForActivate();
	static void InflateActivate();
	static void Refuel(FuelTypeEnum i_FuelType);
	static void SolerActivate();
	static void Octane95Activate();
	static void Octane96Activate();
	static void Octane98Activate();
	static void ChargeActivate();
	static void DisplayActivate();
};

