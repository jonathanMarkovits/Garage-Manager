# Garage-Manager
Developing a computer software that “manages” a vehicle garage. 
The system will manage a garage that handles these five types of vehicles - 
* <b>Fuel-Based Motorcycle</b>  
2 tires with max air pressure of 33 (psi), Octane 95 (fuel), 8 liters fuel tank 
* <b>Electric Motorcycle</b>  
2 tires with max air pressure of 33 (psi), Max battery life – 1.4 hours 
* <b>Fuel-Based Car</b>  
4 tires with max air pressure of 31 (psi), Octane 96 fuel, 55 liter fuel tank 
* <b>Electric Car</b>  
4 tires with max air pressure of 31 (psi), Max battery life – 1.8 hours 
* <b>Fuel-Based Truck</b>  
12 tires with max air pressure of 26 (psi), Soler fuel, 110 liter fuel tank 
 
<b><ins>Every vehicle contains the following properties:</ins></b> 
* Model Name (String) 
* License Number (String) 
* Remaining Energy Percentage (Fuel/Battery) (float)
* Wheels, with each wheel containing the following:
  * Manufacturer Name (String) o Current Air Pressure (float) 
  * Max Air Pressure Recommended by the manufacturer’s (float)
  * Inflate Action (A method that receives how much more air to add to a wheel, and changes the air pressure while not crossing the max limit) 
* A motorcycle (Fuel/Electric), apart from the vehicle properties, also has the following properties:
  * License type – A, A1, A2, B
  * Engine Volume (int) 
* A car (Fuel/Electric), apart from the vehicle properties, also has the following properties:
  * Color – Red, Blue, Black, Gray
  * Number of doors – 2, 3, 4, or 5 
* A truck, apart from the vehicle properties, also has the following properties: 
  * Contains dangerous materials? (bool)
  * Volume of cargo (float) 
* Every fuel based vehicle contains the following properties and operations: 
  * Fuel type – Soler, Octane 95, Octane 96, Octane 98 
  * Current amount of fuel in liters (float)
  * Max amount of fuel in liters (float) 
  * Refueling operation - (A method that receives how much more fuel to add, and changes the amount of fuel, if the fuel type is correct, and the fuel tank is less than full) 
* Every electric based vehicle contains the following properties and operations: 
  * Remaining time of engine operation in hours (float)
  * Max time of engine operation in hours (float) 
  * Recharge operation - (A method that receives how many more hours to add, and charges the battery, while not crossing the max limit) 
* Every individual vehicle in the garage contains the following properties: 
  * Owner name (String)
  * Owner Phone Number (String) 
  * Vehicle status – In Repair, Repaired, Payed for 
    * Every new vehicle is initiated as “In Repair” 
 
<b><ins>The system will supply the user with the following functions:</b></ins>
1. “Insert” a new vehicle into the garage. The user will be asked to select a vehicle type out of the supported vehicle types, and to input the license number of the vehicle. If the vehicle is already in the garage (based on license number) the system will display an appropriate message and will use the vehicle in the garage (and will change the vehicle status to “In Repair”), if not, a new object of that vehicle type will be created and the user will be prompted to input the values for the properties of his vehicle, according to the type of vehicle he wishes to add. 
2. Display a list of license numbers currently in the garage, with a filtering option based on the status of each vehicle 
3. Change a certain vehicle’s status (Prompting the user for the license number and new desired status) 
4. Inflate tires to maximum (Prompting the user for the license number) 
5. Refuel a fuel-based vehicle (Prompting the user for the license number, fuel type and amount to fill) 
6. Charge an electric-based vehicle (Prompting the user for the license number and number of minutes to charge) 
7. Display vehicle information (License number, Model name, Owner name, Status in garage, Tire specifications (manufacturer and air pressure), Fuel status + Fuel type / Battery status, other relevant information based on vehicle type)

