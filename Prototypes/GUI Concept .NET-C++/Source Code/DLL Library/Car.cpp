#include "Car.h"
#include <string>

Car::Car(const char* make, const char* model, const char* modelNumber)
{
	cs.make = make;
	cs.model = model;
	cs.modelNumber = modelNumber;
}


std::string Car::ModeSelector(int currentMode)
{
	std::string make = cs.make, model = cs.model, modelNumber = cs.modelNumber;
	
	if (currentMode == 0)
		return std::string("Thanks for driving the " + make + " " + model + "\nModel Number:" + modelNumber);

	if (currentMode == 1)
		return std::string("Welcome to your " + make + " " + model + "\nModel Number:" + modelNumber);

	return "Speed: 0MPH | Millage: 87000MI";
}
