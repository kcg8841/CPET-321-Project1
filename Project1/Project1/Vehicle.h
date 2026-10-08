#include <string>
#ifndef Vehicle_H
#define Vehicle_H
class Vehicle {
private:
	std::string Make;
	std::string Model;
	std::string Color;
	int Year;
	int Reservations[3]; //A value of 0 means there is no reservation stored, any value above 0 means that there is a reservation on the date at that number
public:
	std::string GetMake();
	std::string GetModel();
	std::string GetColor();
	int GetYear();
	int GetReservations(); //this should output a pointer to the array? outputs each specific date that has a reservation //CHECK if the car date already exists
	void SetMake(std::string newMake);
	void SetModel(std::string newModel);
	void SetColor(std::string newColor);
	void SetYear(int newYear);

	//For the AddReservation function:
		// A return value of 0 means the function was completed with out issue
		//A return value of 1 means the reservation is already in the system
		//A return value of 2 means there is no room in the system
	int AddReservation(int newDate);//function that puts a specific day into reservations. this should put it in the next available slot.
	//For the DeleteReservation function:
		// A return value of 0 means the function was completed with out issue
		//A return value of 1 means the requested reservation was not in the system
	int DeleteReservation(int oldDate);//function that REMOVES a specific reservation. This will prooooobably just be called whenever the reservation is on a date that is lower than the current date. I think this would be best if it is just called automatically at the start of each day to clear unused space
	
	virtual std::string InfoOut() = 0; //outputs information about the vehicle


	//methods  anmd variables I believe should be added:
	//a variable that tracks each day thata car is reserved. This SHOULD only be an int, as it seems like only 1 reservation can be tracked at a time. WRONG
	//this variable should be an array of int size 3
	//a way to access and change reservation status. duh
	//I need to keep track of the current day, not sure if that should be a job for my classes though
	// the date the program starts running is 1.

	//ADD a color for the car done
	//

	//add to infouout:
	//color
	//resrervation datses?

};

#endif