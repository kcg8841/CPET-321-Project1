#include <string>
#include <iostream>
#include "Vehicle.h"
//definitions for Vehicle
std::string Vehicle::GetMake() {
	return Make;
}
std::string Vehicle::GetModel() {
	return Model;
}
std::string Vehicle::GetColor() {
	return Color;
}
int Vehicle::GetYear() {
	return Year;
}
int* Vehicle::GetReservations() {
	return Reservations;
}
void Vehicle::SetMake(std::string newMake) {
	Make = newMake;
}
void Vehicle::SetModel(std::string newModel) {
	Model = newModel;
}
void Vehicle::SetColor(std::string newColor) {
	Color = newColor;
}
void Vehicle::SetYear(int newYear) {
	Year = newYear;
}
int Vehicle::AddReservation(int newDate) {
	for (int lcv = 0; lcv < 3; lcv++) {
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
	for (int lcv = 0; lcv < 3; lcv++) {
		if (Reservations[lcv] == oldDate) {
			Reservations[lcv] = 0;
			return 0; //succeeded without issue
		}
	}
	return 1; //the requested reservation was not in the system.
}
