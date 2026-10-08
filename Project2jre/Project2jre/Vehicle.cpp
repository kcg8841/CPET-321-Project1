#include <string>
#include "Vehicle.h"
//definitions for Vehicle
std::string Vehicle::GetMake() {
	return Vehicle::Make;
}
std::string Vehicle::GetModel() {
	return Vehicle::Model;
}
int Vehicle::GetYear() {
	return Vehicle::Year;
}
void Vehicle::SetMake(std::string newMake) {
	Vehicle::Make = newMake;
}
void Vehicle::SetModel(std::string newModel) {
	Vehicle::Model = newModel;
}
void Vehicle::SetYear(int newYear) {
	Vehicle::Year = newYear;
}

