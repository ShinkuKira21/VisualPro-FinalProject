/* Author: Edward Patch */

#include "classes.h"

void ClassManager();
void IntroductionManager();

int main(int argc, char** argv)
{
	ClassManager();

	return 0;
}

void ClassManager()
{	
	//Initiated here aswell to delete pointers.
	Generater gen;

	IntroductionManager();
	gen.ListManager();

	system("PAUSE");
	system("CLS");

	gen.CodeManager();

	gen.DeletePointers();
}

void IntroductionManager()
{
	
	Introduction intro;

	intro.Version();
}

void Generater::ListManager()
{
	//I found the set and get limits messy (Wanted to do funList.limit() or varList.limit(); instead of this way)
	GetLimit("fun");
	GetLimit("var");

	system("CLS");

	SetPointers();

	SetList("fun");
	SetList("fDT");
	SetList("var");
	SetList("vDT");

	ConfirmList();

	system("CLS");

	ShowList();
}

void Generater::CodeManager()
{
	//Temporary (I need a better way to handle this)
	FunctionPreview();
	VariablePreview();

	system("PAUSE");
	system("CLS");

	LanguageSelector();

	system("CLS");

	DisplayCode();

	SaveCode();
}