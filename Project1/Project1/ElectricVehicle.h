#include <string>
#include "Vehicle.h"
#ifndef ElectricVehicle_H
#define ElectricVehicle_H
class ElectricVehicle : public Vehicle {
private:
	double Capacity; //energy capacity
	double Efficiency; //miles per gallon
	std::string Type; // says that this is an electric vehicle
public:
	double GetCapacity();
	double GetEfficiency();
	std::string GetType();
	void SetCapacity(double newC);
	void SetEfficiency(double newEff);
	void SetType(std::string newType);
	std::string InfoOut();
};

#endif