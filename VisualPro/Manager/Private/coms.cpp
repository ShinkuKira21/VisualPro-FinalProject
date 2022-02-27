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
		// Hex to Text | 612b -> a+
		if (std::string(inp) == "612b" && member != nullptr && dt != nullptr && name != nullptr)
			obj->Add(member, dt, name, parent);

		// Hex to Text | 7277 -> rw || Additional information:
		// Member converted to idToFind -- DT converted to newValue.
		// To make this function more reusable, 2D pointers could be looked into
		if (std::string(inp) == "7277") obj->Edit(id, (int)Functions().TextToNumber(member), dt);

		// Hex to Text | 726d -> rm
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