#include <string>
#include "Vehicle.h"
#ifndef GasVehicle_H
#define GasVehicle_H
class GasVehicle : public Vehicle {
private:
	double Capacity; //fuel capacity
	double Efficiency; //miles per gallon
	std::string Type; //says that it is a gas car
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