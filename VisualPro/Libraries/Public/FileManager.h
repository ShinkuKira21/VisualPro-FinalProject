#pragma once
#include <string>
#include <fstream>

// NEW ADDITION - ADDED 13/02/2022 (Decided it was better to save file via C++)
namespace FileManager
{
	// First Created in Prototype Application
	class _declspec(dllexport) FileManager
	{
		protected:
			std::string data, fileDirectory;
		public:
			void SaveFile(const char* data, const char* fileDirectory);
	};
}