#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

using namespace std;

void Version();
void Tutorial();
void ExtraExamples();
void Manager(int fLit, int vLit);
void Configurator(string* fList, string* fDTList, string* vList, string* vDTList, int selection);
string FunctionPlan();
string FunctionDataTypePlan(string* fList, int i);
string VariablePlan();
string VarDataTypePlan(string* vList, int i);
void FunctionMaker(string* fList, string* dTList, int fLit);
void VariableMaker(string* vList, string* dTList, int vLit);
void SaveCode(string* fList, string* vList, string* fDTList, string* vDTList, int fLit, int vLit);

string StringInput(string message)
{
	stringstream stream;
	string uInput;

	cout << message;

	getline(cin, uInput);

	return uInput;
}

int NumberInput(string message)
{
	stringstream stream;
	string uInput;

	int nInput;

	cout << message;

	getline(cin, uInput);
	stream.str(uInput);
	stream >> nInput;
	stream.clear();

	return nInput;
}

int main(int argc, char** argv)
{
	Version();
	
	//Limits!
	int functionLimit = NumberInput("How many functions does your idea include?: ");
	int variableLimit = NumberInput("How many variables does your idea include?: ");

	Manager(functionLimit, variableLimit);

	return 0;
}

void Version()
{
	string skipTutorial;

	cout << "\n\t\tThis software is in Alpha! Created by Edward Patch.\n\n";
	cout << "   This software will help you write CPP programs or other languages!\n\n\t\t";

	skipTutorial = StringInput("Would you like to skip the tutorial? (Yes or No): ");

	system("CLS");

	if (skipTutorial == "No" || skipTutorial == "no")
	{
		Tutorial();
	}
}

void Tutorial()
{
	string moreExamples;

	cout << "\n\t\tThis is a guideline/tutorial of how the software works!\n\n";
	cout << "\n\t(>) You will get asked how many functions will your idea include.\n\n";
	cout << "\n\t(>) You will get asked how many variables will your idea include.\n\n\n\n\t\t\t";

	system("PAUSE");
	system("CLS");

	cout << "\n\t\t\t\tPage 2\n\n";
	cout << "\n\t(>) You will get asked to type a list of functions that comes to your mind.\n";
	cout << "\tA calculator has many operations/functions, the four main ones: \n";
	cout << "\t\t(>) Addition\n\t\t(>) Subtraction\n\t\t(>) Division\n\t\t(>) Multiplication\n\n";

	cout << "\n\t(>) You will get asked what type of data that function will return.\n";
	cout << "\tThese functions below will return number types.\n";
	cout << "\t\tAddition (>) double\n\t\tSubtraction (>) double\n\t\tDivision (>) double\n\t\tMultiplication (>) double\n\n";

	cout << "\n\t(>) You will get asked to type a list of variables that comes to your mind.\n";
	cout << "\tA calculator would have a minimum of 2 variables: \n";
	cout << "\t\t(>) number1\n\t\t(>) number2\n\n";

	cout << "\n\t(>) You will get asked what type of data that variable will accept.\n";
	cout << "\tThe datatype of number1 and number2 would be number types: \n";
	cout << "\t\tNumber1 (>) int\n\t\tNumber1 (>) int\n\n\t\t";

	moreExamples = StringInput("Would you like more examples? (Yes or No): ");

	system("CLS");

	if (moreExamples == "Yes" || moreExamples == "yes")
	{
		ExtraExamples();
	}
}

void ExtraExamples()
{
	cout << "\n\t\t\t\tExtra Examples: Functions\n\n";
	cout << "\n\tToaster\n";
	cout << "\tA toaster has 3 primary functions: \n";
	cout << "\t\t(>) HeatUp\n\t\t(>) CoolDown\n\t\t(>) Timer\n\n";

	cout << "\n\tDishwasher\n";
	cout << "\tA dishwasher has 5 primary functions: \n";
	cout << "\t\t(>) Modes\n\t\t(>) Wash\n\t\t(>) Rinse\n\t\t(>) Dry\n\t\t(>) Drain\n\n";

	cout << "\n\tPhone\n";
	cout << "\tA phone has 2 primary functions required to communicate: \n";
	cout << "\t\t(>) Call\n\t\t(>) SMS\n\n\t\t\t\t";

	system("PAUSE");
	system("CLS");

	cout << "\n\t\t\t\tExtra Examples: Function Data Types\n\n";
	cout << "\n\tToaster\n";
	cout << "\tThe toaster's functions need to return a data type: \n";
	cout << "\t\tHeatUp (>) float\n\t\tCoolDown (>) float\n\t\tTimer (>) int\n\n";

	cout << "\n\tDishwasher\n";
	cout << "\tThe dishwashers functions need to return a data type: \n";
	cout << "\t\tModes (>) int\n\t\tWash (>) bool\n\t\tRinse (>) bool\n\t\tDry (>) bool\n\t\tDrain (>) bool\n\n";

	cout << "\n\tPhone\n";
	cout << "\tThe phone features do not need to return data (if so use void): \n";
	cout << "\t\tCall (>) void\n\t\tSMS (>) void\n\n\t\t\t\t";

	system("PAUSE");
	system("CLS");

	cout << "\n\t\t\t\tExtra Examples: Variables\n\n";
	cout << "\n\tToaster\n";
	cout << "\tA toaster has 3 primary variables: \n";
	cout << "\t\t(>) power\n\t\t(>) temperature\n\t\t(>) timer\n\n";

	cout << "\n\tDishwasher\n";
	cout << "\tA dishwasher has 7 primary variables: \n";
	cout << "\t\t(>) power\n\t\t(>) hardWash\n\t\t(>) mediumWash\n\t\t(>) softWash\n\t\t(>) temperature\n\t\t(>) waterQuantity\n\t\t(>) waterLeftToDrain\n\n";

	cout << "\n\tPhone\n";
	cout << "\tA phone has 2 primary variables required to communicate: \n";
	cout << "\t\t(>) phoneNumber\n\t\t(>) subject\n\t\t(>) body\n\t\t(>) signal\n\n";

	system("PAUSE");
	system("CLS");

	cout << "\n\t\t\t\tExtra Examples: Variable Data Types\n\n";
	cout << "\n\tToaster\n";
	cout << "\tThe toasters variables need to hold certain data: \n";
	cout << "\t\tpower (>) bool\n\t\ttemperature (>) float\n\t\ttimer (>) int\n\n";

	cout << "\n\tDishwasher\n";
	cout << "\tA dishwasher has 7 primary variables: \n";
	cout << "\t\tpower (>) bool\n\t\thardWash (>) bool\n\t\tmediumWash (>) bool\n\t\tsoftWash (>) bool\n\t\ttemperature (>) float\n\t\twaterQuantity (>) float\n\t\twaterLeftToDrain (>) float\n\n";

	cout << "\n\tPhone\n";
	cout << "\tA phone has 2 primary variables required to communicate: \n";
	cout << "\t\tphoneNumber (>) string\n\t\tsubject (>) string\n\t\tbody (>) string\n\t\tsignal (>) double\n\n";

	system("PAUSE");
	system("CLS");
}

void Manager(int fLit, int vLit)
{
	string* functionList = new string[fLit];
	string* functionDataTypeList = new string[fLit];
	string* variableList = new string[vLit];
	string* varDataTypeList = new string[vLit];
	string saveFile;

	system("CLS");

	cout << "List your potential functions below:\n";

	for (int i = 0; i < fLit; i++)
	{
		functionList[i] = FunctionPlan();
	}
	
	system("CLS");

	cout << "\t\t\t\tGuide: \n";
	cout << "\tvoid - does not return\n";
	cout << "\tstring - returns letters/numbers (no mathematical operations)\n";
	cout << "\tint, float and double - returns mathematical numbers (0, 0.123456, 0.123456789012)\n";
	cout << "\tbool - returns True/False\n\n";
	cout << "List your data types below:\n";
	for (int i = 0; i < fLit; i++)
	{
		functionDataTypeList[i] = FunctionDataTypePlan(functionList, i);
	}

	system("CLS");

	cout << "List your potential variables below:\n";

	for (int i = 0; i < vLit; i++)
	{
		variableList[i] = VariablePlan();
	}

	system("CLS");

	cout << "\t\t\t\tGuide: \n";
	cout << "\tString - Stores letters/numbers (no mathematical operations)\n";
	cout << "\tint, float and double - stores mathematical numbers (0, 0.123456, 0.123456789012)\n";
	cout << "\tbool - stores True/False\n\n";
	cout << "List your data types below:\n";
	for (int i = 0; i < vLit; i++)
	{
		varDataTypeList[i] = VarDataTypePlan(variableList, i);
	}

	system("CLS");
		
	cout << "Functions List: \n";

	for (int i = 0; i < fLit; i++)
	{
		cout << "\n  (" << i << ") " << functionList[i] << endl;
	}

	Configurator(functionList, functionDataTypeList, variableList, varDataTypeList, 0);

	system("CLS");

	cout << "Data Types List: \n";

	for (int i = 0; i < fLit; i++)
	{
		cout << "\n  " << functionList[i] << " (" << i << ") " << functionDataTypeList[i] << endl;
	}

	Configurator(functionList, functionDataTypeList, variableList, varDataTypeList, 1);

	system("CLS");

	cout << "Variables List: \n";

	for (int i = 0; i < vLit; i++)
	{
		cout << "\n  (" << i << ") " << variableList[i] << endl;
	}

	Configurator(functionList, functionDataTypeList, variableList, varDataTypeList, 2);
	
	system("CLS");

	cout << "Data Types List: \n";

	for (int i = 0; i < vLit; i++)
	{
		cout << "\n  " << variableList[i] << " (" << i << ") " << varDataTypeList[i] << endl;
	}

	Configurator(functionList, functionDataTypeList, variableList, varDataTypeList, 3);

	system("CLS");

	cout << "New Functions List: \n";

	for (int i = 0; i < fLit; i++)
	{
		cout << "\n  (>) " << functionList[i] << endl << endl;
	}

	cout << "New Data Type List: \n";

	for (int i = 0; i < fLit; i++)
	{
		cout << "\n  " << functionList[i] << " (" << i << ") " << functionDataTypeList[i] << endl << endl;
	}

	cout << "New Variables List: \n";

	for (int i = 0; i < vLit; i++)
	{
		cout << "\n  (>) " << variableList[i] << endl << endl;
	}

	cout << "New Data Type List: \n";

	for (int i = 0; i < vLit; i++)
	{
		cout << "\n  " << variableList[i] << " (" << i << ") " << varDataTypeList[i] << endl << endl;
	}

	system("PAUSE");
	system("CLS");

	FunctionMaker(functionList, functionDataTypeList, fLit);
	VariableMaker(variableList, varDataTypeList, vLit);

	saveFile = StringInput("Would you like to save your plan? (Yes/No): ");
	if (saveFile == "Yes" || saveFile == "yes")
	{
		system("CLS");
		SaveCode(functionList, variableList, functionDataTypeList, varDataTypeList, fLit, vLit);
	}

	delete[] functionList, functionDataTypeList, variableList, varDataTypeList;
}

void Configurator(string* fList, string* fDTList, string* vList, string* vDTList, int selection)
{
	string userOption;
	int position;

	while (true)
	{
		userOption = StringInput("\n\n\t\tAre you happy with the list? (Yes/No): ");

		if (userOption == "No" || userOption == "no")
		{
			position = NumberInput("\n\t\tChoose a number from the list above that you wish to change: ");

			if (selection == 0)
				fList[position] = StringInput("\n\t\tPlease enter a new function: ");

			else if(selection == 1)
				fDTList[position] = StringInput("\n\t\tPlease enter a new data type: ");

			else if(selection == 2)
				vList[position] = StringInput("\n\t\tPlease enter a new variable: ");

			else
				vDTList[position] = StringInput("\n\t\tPlease enter a new data type: ");
		}
		else
			break;
	}		
}

string FunctionPlan()
{
	string list;
		
	list = StringInput("\n  (>) ");

	return list;
}

string FunctionDataTypePlan(string* fList, int i)
{
	string list;

	cout << "  " << fList[i];
	list = StringInput(" (>) ");

	return list;
}

string VariablePlan()
{
	string list;

	list = StringInput("\n  (>) ");

	return list;
}

string VarDataTypePlan(string* vList, int i)
{
	string list;

	cout << "  " << vList[i];
	list = StringInput(" (>) ");

	return list;
}

void FunctionMaker(string* fList, string* dTList,int fLit)
{
	cout << "Potential Functions:\n\n";

	for (int i = 0; i < fLit; i++)
	{
		cout << "  " << dTList[i] << " " << fList[i] << "()\n";
		cout << "  {\n\n  }\n\n\n";
	}
}

void VariableMaker(string* vList, string* dTList, int vLit)
{
	cout << "Potential Variables:\n\n";
	for (int i = 0; i < vLit; i++)
	{
		cout << "  " << dTList[i] << " " << vList[i] << ";\n\n\n";
	}
}

void SaveCode(string* fList, string* vList, string* fDTList, string* vDTList, int fLit, int vLit)
{
	string code;
	ofstream output;
	string fileName, fileType;

	fileName = StringInput("Enter a file name: ");

	while (true)
	{
		system("CLS");
		fileType = StringInput("What programming language? (C#, CPP, Python etc...): ");
		if (fileType != "CPP" && fileType != "cpp" && fileType != "c++")
		{
			cout << "Sorry, CPP is the only language available. New features coming soon.\n";
			system("PAUSE");
		}
		else
			fileName = fileName + ".cpp";
			system("CLS");
			break;			
	}

	code += "#include <iostream>\n";
	code += "#include <string>\n\n";

	code += "using namespace std;\n\n";

	for (int i = 0; i < fLit; i++)
	{
		code += fDTList[i] + " " + fList[i] + "(";
		for (int j = 0; j < vLit; j++)
		{
			if (j < vLit - 1)
				code += vDTList[j] + " " + vList[j] + ", ";
			else
				code += vDTList[j] + " " + vList[j];

		}
		code += ");\n";
	}

	code += "\nint main(int argc, char** argv)\n{\n";
	
	for (int i = 0; i < vLit; i++)
	{
		code += "  " + vDTList[i] + " " + vList[i] + ";\n";
	}

	code += "\n  return 0;\n}\n\n";

	for (int i = 0; i < fLit; i++)
	{
		code += fDTList[i];
		code += " " + fList[i] + "(";

		for (int j = 0; j < vLit; j++)
		{
			if (j < vLit - 1)
				code += vDTList[j] + " " + vList[j] + ", ";
			else
				code += vDTList[j] + " " + vList[j];
			
		}
		
		code += ")\n{\n\n}\n\n";
	}
	
	cout << code;
	
	output.open(fileName);
	output << code << endl;
	output.close();

	cout << "\nThe file has saved in the programs root folder. Enjoy.\n";

}