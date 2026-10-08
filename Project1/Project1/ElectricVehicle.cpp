#include <string>
#include <iostream>
#include "ElectricVehicle.h"
double ElectricVehicle::GetCapacity() {
	return Capacity;
}
double ElectricVehicle::GetEfficiency() {
	return Efficiency;
}
void ElectricVehicle::SetCapacity(double newC) {
	Capacity = newC;
}
void ElectricVehicle::SetEfficiency(double newEff) {
	Efficiency = newEff;
}
std::string ElectricVehicle::GetType() {
	return Type; //this will always be "EV"
}
void ElectricVehicle::SetType(std::string newType) {
	Type = newType; //this SHOULD always be "EV"
}
std::string ElectricVehicle::InfoOut() { //outputs specific information about the vehicle in string format
	std::string Range = std::to_string(Capacity * Efficiency);
	return "Propulsion Method: Electric\nRange: " + Range + "\nEfficency: " + std::to_string(Efficiency) + "\n";
}