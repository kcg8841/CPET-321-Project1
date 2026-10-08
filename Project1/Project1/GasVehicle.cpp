#include <string>
#include <iostream>
#include "GasVehicle.h"
double GasVehicle::GetCapacity() {
	return GasVehicle::Capacity;
}
double GasVehicle::GetEfficiency() {
	return GasVehicle::Efficiency;
}
void GasVehicle::SetCapacity(double newC) {
	GasVehicle::Capacity = newC;
}
void GasVehicle::SetEfficiency(double newEff) {
	GasVehicle::Efficiency = newEff;
}
std::string GasVehicle::GetType() {
	return GasVehicle::Type; //this will always be "ICE"
}
void GasVehicle::SetType(std::string newType) {
	GasVehicle::Type = newType; //this SHOULD always be "ICE"
}
std::string GasVehicle::InfoOut() { //outputs specific information about the vehicle in string format
	std::string Range = std::to_string(Capacity * Efficiency);
	return "Propulsion Method: Gas\nRange: " + Range + "\nEfficency: " + std::to_string(GasVehicle::Efficiency) + "\n";
}