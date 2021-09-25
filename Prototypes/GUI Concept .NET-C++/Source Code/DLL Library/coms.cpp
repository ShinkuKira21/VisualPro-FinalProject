#include "coms.h"

const char* Helloworld()
{ return "C++ says Helloworld"; }

double Calculator(double x, double y, bool opt)
{
	if (opt) return x + y;

	return x - y;
}
