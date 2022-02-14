#pragma once
#ifndef MANAGER_H
#define MANAGER_H
#include "manager.h"

#endif // MANAGER_H

class _declspec(dllimport) Manager;

class _declspec(dllexport) ProgrammingPlanner : public Manager
{	
	public:
		ProgrammingPlanner(const char* signature);
};