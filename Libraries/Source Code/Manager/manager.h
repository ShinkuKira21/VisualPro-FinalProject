#pragma once
#include "../../LinkedList/Public/list.h"

#include <vector>

struct _declspec(dllimport) TemporaryStorage;
class _declspec(dllimport) List;
class _declspec(dllimport) Functions;

class _declspec(dllexport) Manager : Functions
{
	TemporaryStorage* ts;
	
	protected:
		// 0 - members, 1 - datatypes, 3 - names
		List* managedList; const int listSize = 3;
		const char** list;
		int countClasses, countFunctions, countArguments;
		int id; // Debugging
	
		virtual void Decryption();
	
	public:
		Manager(const char* signature);
		virtual ~Manager();

		virtual void Add(const char* member, const char* dt, const char* name, const char* parent = "");
		virtual void Remove(int id);
		virtual std::string Find(int id, bool bFindID = false);
		virtual std::string ParseList();
		virtual std::string GetSignature();
};

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

	char* StrToCStr(std::string str)
	{
		cString = new char[str.length() + 1];

		for (int i = 0; i < str.length(); i++)
		{
			cString[i] = str[i];
			if (i + 1 == str.length())
				cString[i + 1] = '\0';
		}

		return cString;
	}

	void ClearCString() { delete[] cString; }

	~TemporaryStorage()
	{	if(list != nullptr) delete[] list; }
};