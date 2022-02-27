#include "../../Libraries/Public/Functions.h"
#include "../Public/programmingPlanner.h"

namespace Test_Manager
{
	static class _declspec(dllimport) Functions func;

	void StartProgram();
	const char* MSGBoard();
	int Options(bool bError = false);
	void Actions(int option, bool& status, ProgrammingPlanner** proPlanner);
	
	void AddClass(ProgrammingPlanner** proPlanner);
	void EditClass(ProgrammingPlanner** proPlanner);
	void RemoveClass(ProgrammingPlanner** proPlanner);
	
	void AddFunction(ProgrammingPlanner** proPlanner);
	void EditFunction(ProgrammingPlanner** proPlanner);
	void RemoveFunction(ProgrammingPlanner** proPlanner);

	void StartProgram()
	{
		bool status = true;
		
		ProgrammingPlanner** proPlanner = new ProgrammingPlanner* [3];
		const char* sigs[3] = { "C", "F", "A" };

		for (int i = 0; i < 3; i++)
			proPlanner[i] = new ProgrammingPlanner(sigs[i]);

		while (status)
		{
			std::cout << MSGBoard();
			
			const int option = Options();

			func.ClearSystem();

			Actions(option, status, proPlanner);
		}

		for (int i = 0; i < 3; i++)
			delete proPlanner[i];

		delete[] proPlanner;
	}

	const char* MSGBoard()
	{
		const char* msg = "\t\t\tOption Board"
			"\n\t\t1) Add Class | 2) Edit Class | 3) Remove Class"
			"\n\n\t4) Add Function | 5) Edit Functions | 6) Remove Functions"
			"\n\t\t7) Return | 8) Exit"
			"\n\n";
		
		return msg;
	}

	int Options(bool bError)
	{
		int option;

		if (bError) std::cout << "Out of Bounds | Try again\n\n";

		option = int(func.NumberInput("Enter option: "));

		if (option < 1 || option > 8)
			Options(true);

		return option;
	}

	void Actions(int option, bool& status, ProgrammingPlanner** proPlanner)
	{

		
		if (option == 1) AddClass(proPlanner);
		if (option == 2) EditClass(proPlanner);
		if (option == 3) RemoveClass(proPlanner);
		if (option == 4) AddFunction(proPlanner);
		if (option == 5) EditFunction(proPlanner);
		if (option == 6) RemoveFunction(proPlanner);
		if (option == 7) status = false;
		if (option == 8) abort();
	}

	void AddClass(ProgrammingPlanner** proPlanner)
	{
		const std::string member = func.TextInput("Enter member: ");
		const std::string name = func.TextInput("Enter name: ");
		
		proPlanner[0]->Add(member.c_str(), "class", name.c_str());
	}

	void EditClass(ProgrammingPlanner** proPlanner)
	{
		const int id = func.NumberInput("Enter ID: ");

		// 0 - Member
		// 1 - DataType
		// 2 - Name
		const std::string member = func.TextInput("Enter member: ");
		const std::string name = func.TextInput("Enter name: ");

		proPlanner[0]->Edit(id, 0, member.c_str());
		proPlanner[0]->Edit(id, 2, name.c_str());
	}

	void RemoveClass(ProgrammingPlanner** proPlanner)
	{
		proPlanner[0]->Remove(int(func.NumberInput("Enter ID: ")));
	}
	
	void AddFunction(ProgrammingPlanner** proPlanner)
	{
		const std::string member = func.TextInput("Enter member: ");
		const std::string name = func.TextInput("Enter name: ");
		const std::string datatype = func.TextInput("Enter DataType: ");

		proPlanner[1]->Add(member.c_str(), datatype.c_str(), name.c_str());
	}

	void EditFunction(ProgrammingPlanner** proPlanner)
	{

	}

	void RemoveFunction(ProgrammingPlanner** proPlanner)
	{
		proPlanner[1]->Remove(int(func.NumberInput("Enter ID: ")));
	}
}