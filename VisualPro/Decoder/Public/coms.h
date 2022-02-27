#pragma once

#include "LanguageConfiguration.h"
#include <vector>

//Memory for the ProgrammingPlanner Communication
struct Memory
{ std::vector<ProgrammingPlanner*> programmingPlanner; };

// Group Programming Planner Lists
extern "C" _declspec(dllexport) Memory* InitialisePlannerClass();

extern "C" _declspec(dllexport) void AddPlan(Memory* memory, ProgrammingPlanner * programmingPlanner);

extern "C" _declspec(dllexport) void DisposePlannerClass(Memory* memory);

// Configures Language Compiler
extern "C" _declspec(dllexport) Decoder_Tools::XMLTools* InitialiseXMLClass(const char* xmlDir, const char* xmlFile, bool debug);

extern "C" _declspec(dllexport) void DisposeXMLClass(Decoder_Tools::XMLTools* xml); 

// Calls the Language Compiler
extern "C" _declspec(dllexport) const char* CompileLanguage(Memory* memory, Cache::TemporaryStorage* ts, Decoder_Tools::XMLTools * xmlDoc, const char* language, const char* libraries, const char* syntax);

// Misc Commands
extern "C" _declspec(dllexport) const char* SendCommand(Cache::TemporaryStorage* ts, Decoder_Tools::XMLTools* xmlDoc, const char* command, const char* language = "");