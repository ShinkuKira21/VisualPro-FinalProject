#include "coms.h"

const char* Helloworld()
{ return "C++ says Helloworld"; }

double Calculator(double x, double y, bool opt)
{
	if (opt) return x + y;

	return x - y;
}

// Car Class
Car* InitialiseCar(const char* make, const char* model, const char* modelNumber)
{
	if (!std::string(make).empty() && !std::string(model).empty() && !std::string(modelNumber).empty())
		return new Car(make, model, modelNumber);

	return nullptr;
}

char* Ignition(Car* car, int currentMode)
{
	if (car != nullptr)
		return Tools::StrToChar(car->ModeSelector(currentMode));

	return nullptr;
}

void DisposeCar(Car* car)
{ delete car; }

// SaveFile Class
void Save(const char* data, const char* fileDirectory)
{ 
	if(data != nullptr && fileDirectory != nullptr)
		SaveFile file(data, fileDirectory); 
}