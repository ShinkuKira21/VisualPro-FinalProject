#include "../../Libraries/Public/Functions.h"
#include "../Public/list.h"

namespace Test_List
{
	static class _declspec(dllimport) Functions func;
	
    void StartProgram();
    const char* MSGBoard();
    int Options(bool bError = false);
    void Actions(int option, List* linked, bool& status);
	
	void StartProgram()
	{
		List* classes = new List("C");
	    bool status = true;

	    while(status)
	    {
	        std::cout << MSGBoard();
	        const int option = Options();
	        func.ClearSystem();

	        Actions(option, classes, status);
	    }
	}

	const char* MSGBoard()
	{
	    const char* msg = "\t\t\tOption Board"
	                      "\n\t\t1) Add | 2) Edit | 3) Remove "
						  "\n\t\t 4) Find by ID | 5) Find One by Name | 6) Find All by Name"
						  "\n\t\t7) List all | 8) Return | 9) Exit"
	                      "\n\n";
	    return msg;
	}

	int Options(bool bError)
	{
	    int option;

	    if(bError) std::cout << "Out of Bounds | Try again\n\n";

	    option = int(func.NumberInput("Enter option: "));

	    if(option < 1 || option > 9)
	        Options(true);

	    return option;
	}

	void Actions(int option, List* linked, bool& status)
	{
	    std::string name;
	    int id;

		if (option < 2 || option == 5) name = func.TextInput("Enter name: ");
		else if (option == 7) { std::cout << linked->ListAll() << std::endl; func.PauseSystem(); }
		else if (option == 8) status = false;
		else if (option == 9) exit(0);
	    else id = int(func.NumberInput("Enter ID: "));
		
	    func.ClearSystem();

	    if (option == 1) linked->Add(name.c_str());
		if (option == 2) linked->Edit(id, func.TextInput("Enter name: ").c_str());
	    if (option == 3) linked->Remove(id);
	    if (option == 4) std::cout << linked->Find(id);
	    if (option == 5) std::cout << linked->Find(name.c_str()); 
	}
}