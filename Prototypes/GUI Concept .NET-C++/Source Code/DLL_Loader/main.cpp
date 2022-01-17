#include <iostream>
#include <windows.h>
#include <tchar.h>

typedef const char* (*Helloworld_t)();
typedef double (*Calculator_t)(double x, double y, bool opt);

int main()
{
	auto dll = LoadLibrary(_T("DLL_Library.dll"));
	auto helloworld = (Helloworld_t)GetProcAddress(dll, "Helloworld");
	auto calculator = (Calculator_t)GetProcAddress(dll, "Calculator");

	if(dll)
	{
		std::cout << helloworld() << "\n";
		std::cout << "Add: " << calculator(7, 3, true) << " | Subtraction: " << calculator(7, 3, false);
	}
	else
		std::cout << "Not Found";

	FreeLibrary(dll);

	

	return 0;
}