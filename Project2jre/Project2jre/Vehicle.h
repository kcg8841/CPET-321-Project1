#include <string>
#ifndef Vehicle_H
#define Vehicle_H
class Vehicle {
private:
	std::string Make;
	std::string Model;
	int Year;
public:
	std::string GetMake();
	std::string GetModel();
	int GetYear();
	void SetMake(std::string newMake);
	void SetModel(std::string newModel);
	void SetYear(int newYear);
	virtual std::string InfoOut() = 0; //outputs information about the vehicle
};

#endif