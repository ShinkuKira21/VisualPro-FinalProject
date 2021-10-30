#include "../Library_Tools/Public/Decoder.h"
#include "../Decoder/Public/Decoder.h"

Functions func;

void LibraryToolsTest();
void XMLTest();

int main(int argc, char* argv)
{
	int uc = 0;
	while (uc < 3)
	{
		uc = (int)func.NumberInput("(1): Test Library_Tools::Decoder | (2) Test XML Functions\n(3) Exit\n\nSelection: ");

		if (uc == 1) LibraryToolsTest();
		if (uc == 2) XMLTest();

		func.ClearSystem();
	}
	

	return 0;
}

void LibraryToolsTest()
{
	func.ClearSystem();

	std::cout << "Author: Edward Patch\n\n";
	
	std::cout << func.ColorText("\t\tAchievement: This section was completed before 19/11/2021 (01/11/2021),\n\t\tgiving 19 days ahead of time to complete other areas of the project.\n\n", 30, 42, 2);
	std::cout << "What is this program trying to demonstrate?\n";
	std::cout << "Due to the complexities of a software writing a code,\n there would have to be a string decoder library.";
	std::cout << "This program will demonstrate each function offered by Library_Tools::Decoder.\n";

	func.PauseSystem();
	func.ClearSystem();

	std::cout << "Function Name: FindSubStr | Desc: via comparison between two strings and seperator.\nTo exit, enter 'exit'\n\n";

	const char* list = "Hello|Bye|Good Morning|Good Bye!";
	std::cout << list << std::endl << std::endl;
	
	std::string str = "";
	Decoder_Tools::Decoder dc;
	while (str != "exit")
	{
		str = func.TextInput("Search for Word (or) Type 'exit': ");

		if (!dc.FindSubStr(list, str.c_str(), '|').empty())
			std::cout << "Word Found\n\n";
		else if(str != "exit") std::cout << "Word Not Found\n\n";
	}

	func.ClearSystem();

	std::cout << "Function Name: FindSubStr | Desc: via starting and ending character.\nTo exit, enter 'exit'\n\n";

	list = "AiLoYeaNcS";
	std::cout << list << std::endl << std::endl;

	char start, end;
	std::string word;
	while (true)
	{
		str = func.TextInput("Type Start Character (or) enter 'exit' to exit: ");

		if (str == "exit") break;
		start = str[0];

		str = func.TextInput("Type End Character (or) enter 'exit' to exit: ");
		end = str[0];
		
		if (!(word = dc.FindSubStr(list, start, end, 0)).empty())
			std::cout << "Word Found - Word: " << word << "\n\n";
		else if (str != "exit") std::cout << "Word Not Found\n\n";
	}

	func.ClearSystem();

	std::cout << "Function Name: FindSubStr | Desc: gets word via string, position and seperator.\nTo exit, enter 'exit'\n\n";

	list = "#include <iostream>`using system;`import java.io.*";
	std::cout << list << std::endl << std::endl;

	int pos;
	while (true)
	{
		str = func.TextInput("Enter 'exit' to exit (or) Press enter to continue: ");
		if (str == "exit") break;
		pos = (int)func.NumberInput("Enter position (seperator = `) (index-0): ");

		if (!(word = dc.FindSubStr(list, pos, '`')).empty())
			std::cout << "Characters Found - Characters: " << word << "\n\n";
		else if (str != "exit") std::cout << "Characters Not Found\n\n";
	}

	func.ClearSystem();

	std::cout << "Function Name: FindStrIndex | Desc: gets Index of first character.\nTo exit, enter 'exit'\n\n";

	list = "Hello, world";
	std::cout << list << std::endl << std::endl;
	while (true)
	{
		str = func.TextInput("Search for Character (or) enter 'exit' to exit: ");
		if (str == "exit") break;

		if ((pos = dc.FindStrIndex(list, str[0])) != -1)
			std::cout << "Character Found - Index: " << pos << "\n\n";
		else if (str != "exit") std::cout << "Character Not Found\n\n";
	}

	func.ClearSystem();

	std::cout << "Function Name: ReplaceWord | Desc: finds and replaces selected word.\nTo exit, enter 'exit'\n\n";

	std::string replaceStr = "Hello name, have you had a good morning? name I have had an alert, it's your birthday.\nYou are age today!";
	std::cout << replaceStr << std::endl << std::endl;

	std::string replace;
	while (true)
	{
		str = func.TextInput("Search for Word to Replace (or) enter 'exit' to exit: ");
		if (str == "exit") break;

		replace = func.TextInput("Replace word: ");

		replaceStr = dc.ReplaceWord(replaceStr.c_str(), str.c_str(), replace.c_str());

		std::cout << replaceStr << std::endl << std::endl;
	}
}

void XMLTest()
{
	func.ClearSystem();

	std::cout << "Author: Edward Patch\nLibrary used: RapidXML (Author: M. Kalicinski, 'RapidXml,' RAPIDXML, 2009. http://rapidxml.sourceforge.net/\n\n";

	std::cout << func.ColorText("\t\tAchievement: This section was completed on time.\n\n", 30, 42, 2);
	std::cout << "What is this program trying to demonstrate?:\n";
	std::cout << " This program demonstrates a XML Library which extends the RapidXML library.\n";
	std::cout << "The objective of this library is to allow dynamic languages to be added within the software,\n making the existing Programming Planner Improved a better software.";
	std::cout << "\nThe program will demonstrate each function offered by XML Tools.\n\n";

	func.PauseSystem();
	func.ClearSystem();

	Decoder_Tools::XMLTools xml("conf-xml", "conf.xml");
	std::cout << "!Configuration Loaded! - Reading from Example XML\n";

	// xml document tools via rapidXML
	rapidxml::xml_document<> doc;
	// file tools via rapidXML
	rapidxml::file<> file = xml.OpenXML("VisualPro.xml");

	// parses xml document
	doc.parse<0>(file.data());

	// declares a baseNode and calls xml's select node (first language)
	rapidxml::xml_node<>* baseNode = xml.SelectNode(doc.first_node(), 0);
	std::vector<rapidxml::xml_node<>*> childNode;
	rapidxml::xml_attribute<>* attributeNode;

	// selects childNode (index 0) from baseNode.
	childNode.push_back(xml.SelectNode(baseNode, 0));

	// displays the first node (language) and first attribute (name)
	std::cout << "Language: " << xml.SelectAttribute(baseNode, 0)->value() << std::endl;


	const char* list[2] = { "name: ", " | value: " };

	std::cout << "Libraries:\n";

	// select first childNode (libraries)
	for (int i = 0, j = 1; xml.SelectNode(childNode[0], i); i++, j++)
	{
		// push back the next child (i is depth)
		childNode.push_back(xml.SelectNode(childNode[0], i));

		// select childNode (latest push) and start finding all attributes
		for (int k = 0; xml.SelectAttribute(childNode[j], k); k++)
			std::cout << list[k] << xml.SelectAttribute(childNode[j], k)->value();

		std::cout << std::endl;
	}

	func.PauseSystem();
}