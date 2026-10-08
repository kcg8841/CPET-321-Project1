#include <string>
#include <iostream>
#include "ElectricVehicle.h"
double ElectricVehicle::GetCapacity() {
	return ElectricVehicle::Capacity;
}
double ElectricVehicle::GetEfficiency() {
	return ElectricVehicle::Efficiency;
}
void ElectricVehicle::SetCapacity(double newC) {
	ElectricVehicle::Capacity = newC;
}
void ElectricVehicle::SetEfficiency(double newEff) {
	ElectricVehicle::Efficiency = newEff;
}
std::string ElectricVehicle::GetType() {
	return ElectricVehicle::Type;
}
void ElectricVehicle::SetType(std::string newType) {
	ElectricVehicle::Type = newType;
}
std::string ElectricVehicle::InfoOut() {
	std::string Range = std::to_string(Capacity * Efficiency);
	return "Propulsion Method: Electric\nRange: " + Range + "\nEfficency: " + std::to_string(ElectricVehicle::Efficiency) + "\n";
}