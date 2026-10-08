#include <string>
#include <iostream>
#include "Vehicle.h"
//definitions for Vehicle
std::string Vehicle::GetMake() {
	return Vehicle::Make;
}
std::string Vehicle::GetModel() {
	return Vehicle::Model;
}
std::string Vehicle::GetColor() {
	return Vehicle::Color;
}
int Vehicle::GetYear() {
	return Vehicle::Year;
}
int GetReservations();
void Vehicle::SetMake(std::string newMake) {
	Vehicle::Make = newMake;
}
void Vehicle::SetModel(std::string newModel) {
	Vehicle::Model = newModel;
}
void Vehicle::SetColor(std::string newColor) {
	Vehicle::Color = newColor;
}
void Vehicle::SetYear(int newYear) {
	Vehicle::Year = newYear;
}
int Vehicle::AddReservation(int newDate) {
	for (int lcv; lcv < 3; lcv++) {
		if (Reservations[lcv] == newDate) { //if the date has already been reserved
			return 1; //this reservation is already in the system
		}
		if (Reservations[lcv] == 0) {
			Reservations[lcv] = newDate;
			return 0; //Reservation added without issue
		}
	}
	return 2; //there are no available slots.
}
int Vehicle::DeleteReservation(int oldDate) {
	for (int lcv; lcv < 3; lcv++) {
		if (Reservations[lcv] == oldDate) {
			Reservations[lcv] = 0;
			return 0; //succeeded without issue
		}
	}
	return 1; //the requested reservation was not in the system.
}
