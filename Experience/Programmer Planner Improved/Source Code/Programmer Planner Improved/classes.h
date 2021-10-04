#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

#pragma once

/* Author: Edward Patch */


using namespace std;

class IO
{
	protected:
		
		stringstream stream;
		string uInput;
		int nInput;

	public:
		string GetInput(string message) 
		{ 
			cout << message;  
			getline(cin, uInput); 
			return uInput; 
		}

		int GetNumber(string message) 
		{ 
			cout << message;

			getline(cin, uInput); 
			stream.str(uInput);
			stream >> nInput;
			stream.clear();

			return nInput; }
};

class Introduction
{
	private:
		IO io;

	protected:
		string skipTutorial;
		string moreExamples;

	public:
		void Version()
		{
			cout << "\n\t\tThis software is in Alpha! Created by Edward Patch.\n\n";
			cout << "   This software will help you write CPP programs or other languages!\n\n\t\t";

			cout << "\n\t\t\t\tWhat's new: \n\n";
			cout << "\t\t\t(>) Code has been updated\n";
			cout << "\t\t(>) C++, C# and Python is now supported.\n\n\t\t";

			skipTutorial = io.GetInput("Would you like to skip the tutorial? (Yes or No): ");

			system("CLS");

			if (skipTutorial == "No" || skipTutorial == "no")
			{
				Tutorial();
			}
		}

		void Tutorial()
		{
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

			moreExamples = io.GetInput("Would you like more examples? (Yes or No): ");

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
};

class ListLimitHandler
{
	private:
		IO io;

	protected:
		string list;
		int limit;
		

	public:
		int SetLimit(string targ)
		{
			while (true)
			{
				cout << "How many " << targ << " does your idea include?: ";

				limit = io.GetNumber("");

				if (targ == "Function" && limit < 1)
				{
					cout << "Error: " << targ << " limit can not be lower than 1!\n\n";
					continue;
				}

				if (targ == "Variable" && limit < 0)
				{
					cout << "Error: " << targ << " limit can not be lower than 0!";
					continue;
				}
				
				break;
			}
			return limit;
		}
};

class ListHandler
{
	private:
		//Local Variables
		IO io;
		ListLimitHandler limit;
		
		string userOption;
		int position;

		//Local Functions
		string Plan()
		{
			string list;

			list = io.GetInput("\n (>) ");

			return list;
		}

		string DataTypePlan(string* dList, int i)
		{
			string list;

			cout << "  " << dList[i];
			list = io.GetInput("  (>) ");

			return list;
		}

		string ArgumentSelector(string* vList, int i)
		{
			string list;

			cout << "Does " << vList[i] << " need to communicate to another function? (Yes/No) ";

			list = io.GetInput("(>) ");

			return list;
		}

	protected:
		int fLit, vLit;

		string* functionList;
		string* functionDataTypeList;
		string* variableList;
		string* varDataTypeList;
		string* argumentSelector;

	public:
		void SetPointers()
		{
			functionList = new string[fLit];
			functionDataTypeList = new string[fLit];
			variableList = new std::string[vLit];
			varDataTypeList = new string[vLit];
			argumentSelector = new string[vLit];
		}		
		
		void SetList(string targ)
		{	
			if (targ == "fun")
			{
				cout << "List your potential functions below:\n";
				for (int i = 0; i < fLit; i++)
					functionList[i] = Plan();
			}				

			else if (targ == "fDT")
			{
				cout << "\t\t\t\tGuide: \n";
				cout << "\tvoid - does not return\n";
				cout << "\tstring - returns letters/numbers (no mathematical operations)\n";
				cout << "\tint, float and double - returns mathematical numbers (0, 0.123456, 0.123456789012)\n";
				cout << "\tbool - returns True/False\n\n";
				cout << "List your data types below:\n";

				for (int i = 0; i < fLit; i++)
					functionDataTypeList[i] = DataTypePlan(functionList, i);
			}

			else if (targ == "var")
			{
				cout << "List your potential variables below:\n";

				for (int i = 0; i < vLit; i++)
					variableList[i] = Plan();
			}

			else
			{
				cout << "\t\t\t\tGuide: \n";
				cout << "\tstring - Stores letters/numbers (no mathematical operations)\n";
				cout << "\tint, float and double - stores mathematical numbers (0, 0.123456, 0.123456789012)\n";
				cout << "\tbool - stores True/False\n\n";
				cout << "List your data types below:\n";

				for (int i = 0; i < vLit; i++)
				{
					varDataTypeList[i] = DataTypePlan(variableList, i);
					argumentSelector[i] = ArgumentSelector(variableList, i);
				}
			}
			system("CLS");
		}

		void ConfirmList()
		{
			cout << "Functions List: \n";

			for (int i = 0; i < fLit; i++)
			{
				cout << "\n  (" << i << ") " << functionList[i] << endl;
			}

			Configurator(0);

			system("CLS");

			cout << "Data Types List: \n";

			for (int i = 0; i < fLit; i++)
			{
				cout << "\n  " << functionList[i] << " (" << i << ") " << functionDataTypeList[i] << endl;
			}

			Configurator(1);

			system("CLS");

			if (vLit > 0)
			{
				cout << "Variables List: \n";

				for (int i = 0; i < vLit; i++)
				{
					cout << "\n  (" << i << ") " << variableList[i] << endl;
				}

				Configurator(2);

				system("CLS");

				cout << "Data Types List: \n";

				for (int i = 0; i < vLit; i++)
				{
					cout << "\n  " << variableList[i] << " (" << i << ") " << varDataTypeList[i] << endl;
				}

				Configurator(3);
			}			
		}

		void ShowList()
		{
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
		}

		void Configurator(int targ)
		{
			while (true)
			{
				userOption = io.GetInput("\n\n\t\tAre you happy with the list? (Yes/No): ");

				if (userOption == "No" || userOption == "no")
				{
					position = io.GetNumber("\n\t\tChoose a number from the list above that you wish to change: ");

					if (targ == 0)
						functionList[position] = io.GetInput("\n\t\tPlease enter a new function: ");

					else if (targ == 1)
						functionDataTypeList[position] = io.GetInput("\n\t\tPlease enter a new data type: ");

					else if (targ == 2)
						variableList[position] = io.GetInput("\n\t\tPlease enter a new variable: ");

					else
						varDataTypeList[position] = io.GetInput("\n\t\tPlease enter a new data type: ");
				}
				else
					break;
			}
		}

		void GetLimit(string targ)
		{
			if (targ == "fun")
				fLit = limit.SetLimit("Function");
			else
				vLit = limit.SetLimit("Variable");
		}

		void DeletePointers()
		{
			delete[] functionList, functionDataTypeList, variableList, varDataTypeList, argumentSelector;
		}

		string* GetFList() { return functionList; }
		string* GetFDTList() { return functionDataTypeList; }
		string* GetVList() { return variableList; }
		string* GetVDTList() { return varDataTypeList; }
		string* GetArgList() { return argumentSelector; }

		int GetFLit() { return fLit; }
		int GetVLit() { return vLit; }
};

class Generater : public ListHandler
{
	//CODE LIBRARY!
	private:
		IO io;

		void LanguageCPP()
		{
			code += "#include <iostream>\n";
			code += "#include <string>\n\n";

			code += "using namespace std;\n\n";

			for (int i = 0; i < fLit; i++)
			{
				code += functionDataTypeList[i] + " " + functionList[i] + "(";

				for (int j = 0; j < vLit; j++)
				{
					if (argumentSelector[j] == "Yes" || argumentSelector[j] == "yes")
					{
						if (j == 0)
							code += varDataTypeList[j] + " " + variableList[j];
						else
							code += ", " + varDataTypeList[j] + " " + variableList[j];
					}
				}

				code += ");\n";
			}

			code += "\nint main(int argc, char** argv)\n{\n";

			for (int i = 0; i < vLit; i++)
			{
				code += "  " + varDataTypeList[i] + " " + variableList[i] + ";\n";
			}

			code += "\n  return 0;\n}\n\n";

			for (int i = 0; i < fLit; i++)
			{
				code += functionDataTypeList[i];
				code += " " + functionList[i] + "(";

				for (int j = 0; j < vLit; j++)
				{
					if (argumentSelector[j] == "Yes" || argumentSelector[j] == "yes")
					{
						if (j == 0)
							code += varDataTypeList[j] + " " + variableList[j];
						else
							code += ", " + varDataTypeList[j] + " " + variableList[j];
					}
				}

				code += ")\n{\n\n}\n\n";
			}
		}

		void LanguageCS()
		{
			code += "using System;\n\n";

			code += "namespace Programmer\n";
			code += "{\n";
			code += "  class Planner\n";
			code += "  {\n";
			code += "    static void Main(string[] args)\n";
			code += "    {\n";

			for (int i = 0; i < vLit; i++)
			{
				if (varDataTypeList[i] == "float")
					code += "\t  " + varDataTypeList[i] + " " + variableList[i] + " = 0.00f;\n";

				else if (varDataTypeList[i] == "double")
					code += "\t  " + varDataTypeList[i] + " " + variableList[i] + " = 0.00d;\n";

				else if (varDataTypeList[i] == "int")
					code += "\t  " + varDataTypeList[i] + " " + variableList[i] + " = 0;\n";

				else
					code += "\t  " + varDataTypeList[i] + " " + variableList[i] + ";\n";
			}

			code += "    }\n\n";

			for (int i = 0; i < fLit; i++)
			{
				code += "    static " + functionDataTypeList[i] + " " + functionList[i] + "(";

				for (int j = 0; j < vLit; j++)
				{
					if (argumentSelector[j] == "Yes" || argumentSelector[j] == "yes")
					{
						if (j == 0)
							code += varDataTypeList[j] + " " + variableList[j];
						else
							code += ", " + varDataTypeList[j] + " " + variableList[j];
					}
				}

				code += ")\n    {\n\n";

				if (functionDataTypeList[i] != "void")
					code += "\t  return 0;\n    }\n\n";
				else
					code += "    }\n\n";
			
			}

			code += "  }\n}\n\n\n";
		}

		void LanguagePython()
		{
			code += "def main(): \n";

			for (int i = 0; i < vLit; i++)
			{
				code += "  " + variableList[i];
				if (varDataTypeList[i] == "float" || varDataTypeList[i] == "double")
				{
					code += " = 0.00\n";
				}
				else if (varDataTypeList[i] == "int")
				{
					code += " = 0\n";
				}
				else
					code += " = \"\"\n";
			}

			for (int i = 0; i < fLit; i++)
			{
				code += "\n  " + functionList[i];
				code += "(";

				for (int j = 0; j < vLit; j++)
				{
					if (argumentSelector[j] == "Yes" || argumentSelector[j] == "yes")
					{
						if (j == 0)
							code += variableList[j];
						else
							code += ", " + variableList[j];
					}
				}	

				code += ")\n\n";
			}

			for (int i = 0; i < fLit; i++)
			{
				code += "def " + functionList[i];
				code += "(";

				for (int j = 0; j < vLit; j++)
				{
					if (argumentSelector[j] == "Yes" || argumentSelector[j] == "yes")
					{
						if (j == 0)
							code += variableList[j];
						else
							code += ", " + variableList[j];
					}
				}
				code += "):\n  pass\n\n";
				
			}
			code += "main()\n\n\n";
		}

	protected:

		ofstream file;

		string dir = "./SaveLocation/", fileName, fileType;

		string code;
		string saveFile;
		string language;
		

	public:

		void FunctionPreview()
		{
			cout << "Potential Functions:\n\n";

			for (int i = 0; i < fLit; i++)
			{
				cout << "  " << functionDataTypeList[i] << " " << functionList[i] << "()\n";
				
				if (functionDataTypeList[i] == "void")
					cout << "  {\n\n  }\n\n\n";
				else
					cout << "  {\n\n    return 0;\n  }\n\n\n";
			}
		}

		void VariablePreview()
		{
			cout << "Potential Variables:\n\n";
			for (int i = 0; i < vLit; i++)
			{
				cout << "  " << varDataTypeList[i] << " " << variableList[i] << ";\n\n\n";
			}
		}

		void LanguageSelector()
		{
			while (true)
			{
				system("CLS");
				language = io.GetInput("What programming language? (CS, CPP, Python etc...): ");
				if (language != "cpp" && language != "cs" && language != "python")
				{
					cout << "Sorry, please type either cs, cpp or python.\n";
					system("PAUSE");
				}
				else
					CodeGenerator();
					break;
			}
		}

		void CodeGenerator()
		{
			if (language == "cpp")
			{
				LanguageCPP();
				fileType = ".cpp";
			}

			if (language == "cs")
			{
				LanguageCS();
				fileType = ".cs";
			}

			if (language == "python")
			{
				LanguagePython();
				fileType = ".py";
			}
		}

		void DisplayCode()
		{
			cout << code;
		}

		void SaveCode()
		{
			saveFile = io.GetInput("\n\nWould you like to save your plan? (Yes/No): ");
			if (saveFile == "Yes" || saveFile == "yes")
			{
				fileName = io.GetInput("File Name: ");

				fileName = fileName + fileType;

				file.open(dir + fileName);
				file << code << endl;
				file.close();
			}				
		}

		void ListManager();
		void CodeManager();
};