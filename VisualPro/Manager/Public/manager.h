#pragma once
#include "../../LinkedList/Public/list.h"

#include <vector>

struct _declspec(dllimport) Cache::TemporaryStorage;
class _declspec(dllimport) List;
class _declspec(dllimport) Functions;

class _declspec(dllexport) Manager : Functions
{
	Cache::TemporaryStorage* ts;
	
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