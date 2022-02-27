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
			static int FindStrIndex(const char* str, char charToTest);

			static std::string ReplaceWord(const char* str, const char* strToTest, const char* replaceStr);
			static std::string ReplaceWord(const char* str, int depth, char start, char end, const char* replaceStr);
			
	};
}

namespace Cache
{
	struct _declspec(dllexport) TemporaryStorage
	{
		std::string* list;
		char* cString;

		TemporaryStorage() { list = nullptr; cString = nullptr; }

		TemporaryStorage(int size)
		{
			list = new std::string[size];
			for (int i = 0; i < size; i++)
				list[i] = "";
		}

		const char* StrToCStr(std::string str)
		{
			ClearCString();
			if (str.empty()) return nullptr;

			cString = new char[str.length() + 1];

			for (int i = 0; i < str.length(); i++)
			{
				cString[i] = str[i];
				if (i + 1 == str.length())
					cString[i + 1] = '\0';
			}

			return cString;
		}

		void ClearCString() { delete[] cString; cString = nullptr; }

		~TemporaryStorage()
		{ if (list != nullptr) delete[] list; }
	};
}