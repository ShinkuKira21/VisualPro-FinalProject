#include "linkedlist.h"

// Global
static Functions func;

void StartProgram();
const char* MSGBoard();
int Options(bool bError = false);
void Actions(int option, LinkedList* linked, bool& status);

int main()
{
    StartProgram();

    std::cout << "\n\n\t\t\tEnd of Execution\n";

    return 0;
}

void StartProgram()
{
    std::cout << "\t\t\tStart of Execution\n";

    LinkedList* classes = new LinkedList("C");
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
                      "\n\t\t1) Add | 2) Remove | 3) Find by ID"
					  "\n\t\t4) Find One by Name | 5) Find All by Name"
					  "\n\t\t6) List all | 7) Exit"
                      "\n\n";
    return msg;
}

int Options(bool bError)
{
    int option;

    if(bError) std::cout << "Out of Bounds | Try again\n\n";

    option = int(func.NumberInput("Enter option: "));

    if(option < 1 || option > 7)
        Options(true);

    return option;
}

void Actions(int option, LinkedList* linked, bool& status)
{
    std::string name;
    int id;

    if (option == 1 || option == 4) name = func.TextInput("Enter name: ");
    else if (option == 6) { std::cout << linked->List() << std::endl; func.PauseSystem(); }
    else if (option == 7) status = false;
    else id = int(func.NumberInput("Enter ID: "));
	
    func.ClearSystem();

    if (option == 1) linked->AddList(name.c_str());
    if (option == 2) linked->RemoveList(id);
    if (option == 3) std::cout << linked->Find(id);
    if (option == 4) std::cout << linked->Find(name.c_str()); 
}
