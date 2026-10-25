#ifndef Database_H
#define Database_H
#include <string>
#include "Vehicle.h"

// Holds up to 50 vehicles and manages their reservations
class Database {
private:
	Vehicle* inventory[50]; // nullptr = empty slot
	int inventorycount;
	int currentdate; // starts on 1

public:
	Database();
	~Database(); // deletes the vehicles

	// File format: Make Model Color Year Type Capacity Efficiency (Type is ICE or EV)
	// Returns number of vehicles imported, -1 = can't open file, -2 = bad line, -3 = bad type
	int importcars(std::string filename);
	int getcount();
	Vehicle* getvehicle(int index); // nullptr if index is not valid

	int getdate();
	void advancedate(); // next day, then clears old reservations for every vehicle

	// true if the car is free on that date and has fewer than 3 reservations
	bool checkavailability(int index, int reservationdate);
	// Deletes reservations before today. Returns number deleted, -1 = bad index
	int updateavailability(int index, int today);
	// 0 = ok, 1 = already reserved that date, 2 = already has 3, 3 = date not in future, -1 = bad index
	int createreservation(int index, int reservationdate);
	// 0 = ok, 1 = no reservation on that date, -1 = bad index
	int deletereservation(int index, int reservationdate);
}; // Database

#endif