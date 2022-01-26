#pragma once
#include "programmingPlanner.h"

// Create
extern "C" _declspec(dllexport) ProgrammingPlanner* InitialiseClass(Cache::TemporaryStorage* ts, const char* inp);
// Dispose
extern "C" _declspec(dllexport) void DisposeClass(ProgrammingPlanner* obj);
// Function Handler
extern "C" _declspec(dllexport) void CallFunction(ProgrammingPlanner* obj, const char* inp, const char* member, const char* dt, const char* name, const char* parent, int id);
// CString Handler
extern "C" _declspec(dllexport) const char* CallStringFunction(ProgrammingPlanner* obj, Cache::TemporaryStorage* ts, const char* inp);