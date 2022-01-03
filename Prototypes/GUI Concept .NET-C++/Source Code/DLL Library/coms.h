#pragma once
#include "Car.h"
#include "SaveFile.h"

extern "C" _declspec(dllexport) const char* Helloworld();

// opt == true(Addition) and opt == false(Subtraction) 
extern "C" _declspec(dllexport) double Calculator(double x, double y, bool opt);

// Car Class
extern "C" _declspec(dllexport) Car* InitialiseCar(const char* make, const char* model, const char* modelNumber);

extern "C" _declspec(dllexport) char* Ignition(Car* car, int currentMode);

extern "C" _declspec(dllexport) void DisposeCar(Car* car);

// SaveFile Class
extern "C" _declspec(dllexport) void Save(const char* data, const char* fileDirectory);