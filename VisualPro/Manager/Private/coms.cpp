#include "../Public/coms.h"

ProgrammingPlanner* InitialiseClass(Cache::TemporaryStorage* ts, const char* inp)
{
	ts->StrToCStr(inp);

	if (ts->cString != nullptr) 
	{
		ProgrammingPlanner* returnPlan = new ProgrammingPlanner(ts->cString);
		
		return returnPlan;
	}

	return nullptr;
}

void DisposeClass(ProgrammingPlanner* obj)
{
	delete obj;
	obj = nullptr;
}

void CallFunction(ProgrammingPlanner* obj, const char* inp, const char* member, const char* dt, const char* name, const char* parent, int id)
{
	if (obj != nullptr && inp != nullptr)
	{
		if (std::string(inp) == "612b" && member != nullptr && dt != nullptr && name != nullptr) obj->Add(member, dt, name, parent);
		if (std::string(inp) == "726d" && id > 0) obj->Remove(id);
	}

	inp = nullptr; member = nullptr; dt = nullptr; name = nullptr; parent = nullptr;
}

const char* CallStringFunction(ProgrammingPlanner* obj, Cache::TemporaryStorage* ts, const char* inp)
{
	if (obj != nullptr && inp != nullptr && ts != nullptr)
	{
		if (std::string(inp) == "List")
		{
			inp = nullptr;

			ts->StrToCStr(obj->ParseList());

			return ts->cString;
		}
	}

	inp = nullptr;

	return nullptr;
}