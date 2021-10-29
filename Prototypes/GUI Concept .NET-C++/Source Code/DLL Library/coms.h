#pragma once
#include <string>
#include "Car.h"

extern "C" _declspec(dllexport) const char* Helloworld();

extern "C" _declspec(dllexport) double Calculator(double x, double y, bool opt);

// Car Class
extern "C" _declspec(dllexport) Car* InitialiseCar(const char* make, const char* model, const char* modelNumber);

extern "C" _declspec(dllexport) char* Ignition(Car* car, int currentMode);

extern "C" _declspec(dllexport) void DisposeCar(Car* car);