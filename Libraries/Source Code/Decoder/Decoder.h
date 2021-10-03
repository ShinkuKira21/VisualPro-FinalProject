#pragma once

#include "../../Libraries/Public/Functions.h"

class _declspec(dllimport) Functions;

// Trying out a Namespace to hold DLL Classes

namespace Decoder_Tools
{
	class _declspec(dllexport) Decoder : Functions
	{
		public:
			void Decipher();
			
			static std::string FindSubStr(const char* str, const char* strToTest, char separator, int pos = -1);
			static std::string FindSubStr(const char* str, char start, char end, int pos);
			static std::string FindSubStr(const char* str, int pos, char separator);

			static std::string ReplaceWord(const char* str, const char* strToTest, const char* replaceStr);
		
			static int FindStrIndex(const char* str, char charToTest);
	};
}