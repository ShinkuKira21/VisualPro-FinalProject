#include "../Public/LanguageConfiguration.h"

namespace Test_Decoder
{
	void StartProgram()
	{
		// Creation (Temporary)
		std::string inp, syntax;
		inp = "io\x1f\string"; syntax += "header"; syntax += '\x1f'; syntax += "class"; syntax += '\x1f'; syntax += "function";
		
		//std::vector<std::string> str;
		//std::vector<ProgrammingPlanner*> progPlanner;

		//int numOfClasses, numOfFunctions, indexA = -1, indexB = 0;

		//numOfClasses = (int)Functions().NumberInput("Enter a number of classes (0 is allowed): ");
		//numOfFunctions = (int)Functions().NumberInput("Enter a number of functions (0 is allowed): ");

		//if (numOfClasses > 0)
		//{
		//	progPlanner.push_back(new ProgrammingPlanner("C"));
		//	syntax += '\x1f'; syntax += "class";
		//	indexA = 0;
		//}
		//	

		//if (numOfFunctions > 0)
		//{
		//	syntax += '\x1f'; syntax += "function";
		//	progPlanner.push_back(new ProgrammingPlanner("F"));
		//	if (indexA == 0) indexB = 1;
		//}
		//	
		//
		//Functions().ClearSystem();

		//for (size_t i = 0; i < numOfClasses; i++)
		//{
		//	

		//	str.push_back(Functions().TextInput("Enter Member: "));
		//	str.push_back("Class");
		//	str.push_back(Functions().TextInput("Enter Name: "));
		//	str.push_back("");

		//	if(i != 0)
		//		str[3] = Functions().TextInput("Enter Child (C-" + std::to_string(i-1) + "): ").c_str();
		//	
		//	progPlanner[indexA]->Add(str[0].c_str(), str[1].c_str(), str[2].c_str(), str[3].c_str());
		//
		//	str.clear();
		//	Functions().ClearSystem();
		//}


		//for (size_t i = 0; i < numOfFunctions; i++)
		//{
		//	str.push_back(Functions().TextInput("Enter Member: "));
		//	str.push_back(Functions().TextInput("Enter DataType: "));
		//	str.push_back(Functions().TextInput("Enter Name: "));
		//	str.push_back("");

		//	if (i != 0)
		//		str[3] = Functions().TextInput("Enter Child (F-" + std::to_string(i - 1) + "): ").c_str();

		//	progPlanner[indexB]->Add(str[0].c_str(), str[1].c_str(), str[2].c_str(), str[3].c_str());

		//	str.clear();
		//	Functions().ClearSystem();
		//}

		//// Finds configuration file
		//Decoder_Tools::XMLTools xml("conf-xml", "conf.xml", true);

		//std::cout << "Available Languages: " << Decoder_Tools::SupportedLanguages(&xml).ListAvailableLanguages() << std::endl;

		//Decoder_Tools::SupportedLanguages supportedLanguages(&xml, Functions().TextInput("Enter a Language: ").c_str());
		//Decoder_Tools::LanguageCompiler lc(&supportedLanguages, progPlanner, inp.c_str(), syntax.c_str());
		//
		//Functions().PauseSystem();
		//Functions().ClearSystem();

		//std::cout << lc.FetchCompiledData();

		std::vector<ProgrammingPlanner*> test;

		// Signatures play a big part to determine where the
		// parents, children and arguments belong.
		test.push_back(new ProgrammingPlanner("C"));
		test.push_back(new ProgrammingPlanner("F"));
		//test.push_back(new ProgrammingPlanner("A"));

		for (int i = 0; i < 2; i++) 
			test[0]->Add("public", "class", std::to_string(i).c_str());

	/*	for(int i = 2; i < 4; i++)
			test[1]->Add("private", "int", std::to_string(i).c_str());
			*/
		//test[1]->Add("null", "int", "MyArg", "F-1");
		//test[1]->Add("null", "string", "MyStr", "F-1");

		// Adding Function to Class - 2 -> (F-ID-P-C-ID  Member:;DataType:;N:)
		//test[0]->Add("public", "class", "SubClass-2", "C-1"); 
		
		Decoder_Tools::XMLTools xml("conf-xml", "conf.xml", true);

		std::cout << Decoder_Tools::SupportedLanguages(&xml).ListAvailableLibraries("C++") << std::endl;
		std::cout << Decoder_Tools::SupportedLanguages(&xml).ListAvailableSyntaxes("C++") << std::endl;

		// It works!:)
		std::cout << Decoder_Tools::SupportedLanguages(&xml).ListAvailableLanguages() << std::endl;

		Functions().PauseSystem();

		Decoder_Tools::SupportedLanguages supportedLanguages(&xml, "C++");
		Decoder_Tools::LanguageCompiler lc(&supportedLanguages, test, inp.c_str(), syntax.c_str());
		std::cout << lc.FetchCompiledData();
	}
}