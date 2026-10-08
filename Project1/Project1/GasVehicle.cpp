#include <string>
#include <iostream>
#include "GasVehicle.h"
double GasVehicle::GetCapacity() {
	return Capacity;
}
double GasVehicle::GetEfficiency() {
	return Efficiency;
}
void GasVehicle::SetCapacity(double newC) {
	Capacity = newC;
}
void GasVehicle::SetEfficiency(double newEff) {
	Efficiency = newEff;
}
std::string GasVehicle::GetType() {
	return Type; //this will always be "ICE"
}
void GasVehicle::SetType(std::string newType) {
	Type = newType; //this SHOULD always be "ICE"
}
std::string GasVehicle::InfoOut() { //outputs specific information about the vehicle in string format
	std::string Range = std::to_string(Capacity * Efficiency);
	return "Propulsion Method: Gas\nRange: " + Range + "\nEfficency: " + std::to_string(Efficiency) + "\n";
}