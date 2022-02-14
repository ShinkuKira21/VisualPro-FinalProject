#include "../LinkedList/Private/test-list.cpp"
#include "../Manager/Private/test-manager.cpp"
#include "../Decoder/Private/test-decoder.cpp"
#include "../Manager/Public/coms.h"

// Globals
const char* MSGBoard();
int Options(bool bError = false);
void Actions(int option, bool& status);
void TestDLL();
  
int main(int argc, char** argv)
{
	bool status = true;
	
	while(status)
	{
		std::cout << MSGBoard();
		
		Actions(Options(), status);
	}
	
	return 0;
}

const char* MSGBoard()
{
	const char* msg = "\t\t\tTesting Board"
		"\n\t\t1) Test Linked List | 2) Test Manager"
		"\n\t\t3) Test DLL | 4) Test Decoder"
		"\n\t\t5) Exit"
		"\n\n";
	
	return msg;
}

int Options(bool bError)
{
	int option;

	if (bError) std::cout << "Out of Bounds | Try again\n\n";

	option = int(Test_List::func.NumberInput("Enter option: "));

	if (option < 1 || option > 5)
		Options(true);

	return option;
}

void Actions(int option, bool& status)
{
	Test_List::func.ClearSystem();
	if (option == 1) Test_List::StartProgram();
	else if (option == 2) Test_Manager::StartProgram();
	else if (option == 3) TestDLL();
	else if (option == 4) Test_Decoder::StartProgram();
	else status = !status;
}

void TestDLL()
{
	ProgrammingPlanner* pp = new ProgrammingPlanner("C");
	Cache::TemporaryStorage* ts = nullptr;

	CallFunction(pp, "Add", "protected", "class", "Ford", "", 0);
	CallFunction(pp, "Add", "public", "class", "Vauxhall", "1", 0);
	CallFunction(pp, "Add", "private", "class", "Mercedes", "1", 1);
	std::cout << "DLL List:\n" << CallStringFunction(pp, ts, "List") << "\n\n"; std::cout << "Local List:\n" << pp->ParseList();
	DisposeClass(pp);
	pp = nullptr;
}