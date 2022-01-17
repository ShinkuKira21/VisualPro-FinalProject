#pragma once
#include <string>

namespace Tools
{
	inline char* StrToChar(std::string str)
	{
		char* result = new char[str.length() + 1];
		
		for(int i = 0; i < str.length(); i++)
		{
			result[i] = str[i];

			if (i + 1 == str.length())
				result[i + 1] = '\0';
		}

		return result;
	}

	extern "C" _declspec(dllexport) inline void DeleteCPointer(char* cPointer)
	{ delete[] cPointer; }
}

struct CarStorage
{
	std::string make, model, modelNumber;
};

class Car
{
	CarStorage cs;
	
	public:
		Car(const char* make, const char* model, const char* modelNumber);
		std::string ModeSelector(int currentMode);
};