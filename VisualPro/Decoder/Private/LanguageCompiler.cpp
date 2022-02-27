/* Author: Edward Patch */
/* Libraries Used: RapidXML, M. Kalicinski, “RapidXml,” RAPIDXML, 2009. http://rapidxml.sourceforge.net/ (accessed Oct. 30, 2021).
	Description of Library: Gives tools to communicate with the XML document. However, the tool didn't offer navigational tools. Update: After researching further, there is a way to navigate XML using this library, however, it seemed to be very brief. I created these tools on top to navigate through the Language XML document with ease. */

#include "../Public/LanguageConfiguration.h"

Decoder_Tools::LanguageCompiler::LanguageCompiler(SupportedLanguages* sl, std::vector<ProgrammingPlanner*> pPlanner, const char* libraries, const char* syntax)
{
	// Initialisation
	this->pPlanner = pPlanner;
	this->sl = sl;
	this->language = std::string(language);
	data = std::string();
	
	Parse_ProgrammingPlanner();
	
	// Gathers relevant libraries and syntax.
	LibraryConstructor(libraries);
	SyntaxConstructor(syntax);
	
	Compilation();
}

const std::string Decoder_Tools::LanguageCompiler::FetchCompiledData()
{ return data; }


void Decoder_Tools::LanguageCompiler::Compilation()
{
	// NOW HERE COMES THE FUNKY PART
	// Convert Programming Planner (or Programmer Planner Improved)
	// To the LanguageCompiler Class. (The Twist):- XML Document
	// will be used to enable customisation.
	// (This will have to be dynamic logic and not static logic.)

	// LibraryConstructor (Works)
	// # TO_DO:- (Store each value from XML doc to LanguageCompiler)
	// # -> Add the headers to header section in correspondence to the
	//      language syntax.
	// # -> Recheck for memory improvements
	// (C# could be using FindSubStr from C++ DLL as it's already loaded,
	// this improves execution time, but isn't too much of a problem right now.)

	/* Name will be passed on as a ARRAY or POINTER(most likely pointer as C# uses
	 * intptr) std::vector<> or std::string* can be used if the C Lang comms handle
	 * the communication (and C# loops) to initialise. Otherwise, arrays will have
	 * to be passed on through C++ DLL.
	 *
	 - Selected STRING. (Using a separator, alt-31 (\x1f) to put my Decoder Tools to do its tests).
	 */

	 // Library (first part)
	if (!libs.empty())
		data += LibraryCompilation();

	// we already have the handpicked syntax
	// Header syntax already being used
	std::vector<int> ids;
	std::vector<std::string> argIDs, syntaxLib;
	
	// parSyntax | parSyntaxBytes
	std::vector<std::vector<std::string>> libs[2];

	// REWORKING
	for (size_t i = 0; i < plannerSyntax.size(); i++)
	{
		for (size_t j = 0; j < plannerSyntax[i].size(); j++)
		{
			std::string name;
			int type = GetType_ProgrammingPlanner((int)i, (int)j);

			if (type == 2)
			{
				argIDs.push_back(pPlanner[i]->Find((int)j + 1, true));
				argIDs.push_back(pPlanner[i]->Find((int)j + 1));
			}
				
			for (size_t k = 0; !(name = ParseSyntax(&syntaxLib, i + 1, k)).empty(); k++)
			{
				SyntaxCompilation(&syntaxLib, i, j, name.c_str());

				libs[type].push_back(syntaxLib);
				ids.push_back((int)j+1);
				
				syntaxLib.clear();
			}
		}
	}

	for(size_t i = 0; i < 2; i++)
		for (size_t j = 0; j < libs[i].size(); j++)
			for (size_t k = 0; k < libs[i][j].size(); k++)
				data += SyntaxCompilation(libs[i], argIDs, ids[j], j, k, libs[i][j][1].c_str(), (bool)i);
}

std::string Decoder_Tools::LanguageCompiler::LibraryCompilation()
{
	bool bMiddle = true;
	
	std::vector<std::string> element;
	std::string compiledData, header, name, decipher;

	header = Decoder::FindSubStr(syntax[0][0].c_str(), 2, '\x1f');
	name = Decoder::FindSubStr(syntax[0][1].c_str(), 2, '\x1f');

	if (name == "lr") name = "<>";
	
	int indexI = Decoder::FindStrIndex(header.c_str(), '\\');
	int indexJ = Decoder::FindStrIndex(header.c_str(), '/');

	if (indexI > -1 && indexJ == -1) bMiddle = false;
	
	if (indexI > -1)
		for (size_t i = 0; i < libs.size(); i++)
		{
			for (size_t j = 0; j < header.size(); j++)
			{
				if ((int)j != indexI && (int)j != indexJ) compiledData += header[j];

				if ((int)j == indexI && bMiddle) compiledData += name[0] + libs[i] + name[1];
				
				if ((int)j == indexI && !bMiddle) compiledData += libs[i] + name[0];
			}
			
			compiledData += "\n\n";
		}
			
	return compiledData;
}

void Decoder_Tools::LanguageCompiler::SyntaxCompilation(std::vector<std::string>* syntaxLib, size_t typeIndex, size_t nodeIndex, const char* name)
{
	// Part One!
	// 0: member | 1: dt | 2: name
	const char* currentPlan[3], * wordsToFind[3] = { "member", "dt", "name" };
	
	for (size_t i = 0; i < plannerSyntax[typeIndex][nodeIndex].size(); i++)
		if (i < 3)
		{
			currentPlan[i] = plannerSyntax[typeIndex][nodeIndex][i].c_str();
			
			// restrict the replacer! - Problem: It will change Arguments to it's parent's variable
			// within function layouts. - fixed with str(name) != "args"
			if(std::string(name) != "args")
				for (size_t j = 0; j < syntaxLib->size(); j++)
					syntaxLib->at(j) = StringCompilation(syntaxLib->at(j).c_str(), wordsToFind[i], currentPlan[i]);
		}
}

std::string Decoder_Tools::LanguageCompiler::SyntaxCompilation(std::vector<std::vector<std::string>> lib, std::vector<std::string> argsID, int parentID, size_t elementIndex, size_t nodeIndex, const char* name, bool bChild)
{
	// Part Two

	//should only check if size is 4
	// uses tab order to indicate where it fits
	Functions func; std::string data;

	// zIndex: 0 = begin, 1 = end, 2 = begin-end, 3 = mid

	// Works out any attributes that are required for the language constructor
	// index is going to be tested. We need a int that is in range of 1-3.
	zIndex = (int)func.TextToNumber(std::string(name).substr(std::string(name).size() - 1));
	
	if (zIndex == 2 && nodeIndex == 0) 
	{ tags.clear(); tags.push_back(lib[elementIndex][2]); tags.push_back(lib[elementIndex][3]); }
	
	// Starts at 2 as we do not need type or name
	if(name[0] == 'c')
	{
		// construction
		if(zIndex == 0)
			if (nodeIndex == 2) { data += lib[elementIndex][nodeIndex]; bTagsEnabled = true; } 
		
		if (zIndex == 3)
		{
			if (nodeIndex == 2) member = lib[elementIndex][nodeIndex].c_str(); // store member layout  for nesting
			if (nodeIndex == 3) { data += lib[elementIndex][nodeIndex]; bTagsEnabled = true; }
		}

		// REFERENCE TO OLD VERSION OF PROGRAMMER PLANNER (Refer to Appendix: ):
		// Triple Space = Tab
		if (zIndex == 2 && bTagsEnabled) 
		{ 
			const std::string parentType = (lib[elementIndex][0] + "-" + std::to_string(parentID)).c_str();
			data += '\n' + tags[0] + "\n   " + parentType + "\x1f\n" + tags[1] + "\n\n"; bTagsEnabled = !bTagsEnabled; 
		}
	}

	
	else if(std::string(name) == "args" && nodeIndex == 0)
	{
		// arguments - count parents (loop)
		data += lib[elementIndex][3];
		
		for (size_t i = 0; i < argsID.size(); i++)
			if (parentID == GetParentID_ProgrammingPlanner(argsID[i].c_str()))
			{
				std::string* currentString = GetArgumentComponents(argsID[i+1].c_str());
				
				std::string jStr = lib[elementIndex][5];
				
				const char* wordsToFind[3] = { "member", "dt", "name" };
				for (size_t j = 0; j < 3; j++)
					jStr = StringCompilation(jStr.c_str(), wordsToFind[j], currentString[j].c_str()); //here

				delete[] currentString;
				
				if (data.substr(data.size() - 1) != lib[elementIndex][3]) data += lib[elementIndex][2] + ' ';
				data += jStr;
			}

		data += lib[elementIndex][4];
	}
	
	// if child is true then reroute how data is managed (Explanation:-1)
	/* Children would need to edit Data and fit inside the class. 
		Data is going is sent to a ChildHandler function to handle
		which child belongs to which object.
	*/
	if (bChild)
	{
		
	}

	return data;
}

std::string Decoder_Tools::LanguageCompiler::StringCompilation(const char* str, const char* strToTest, const char* strToReplace)
{ return Decoder::ReplaceWord(str, strToTest, strToReplace); }


std::string Decoder_Tools::LanguageCompiler::ParseSyntax(std::vector<std::string>* syntaxLib, size_t typeIndex, size_t nodeIndex)
{
	std::string data;

	if(typeIndex < syntax.size() && nodeIndex < syntax[typeIndex].size())
	{
		for (size_t i = 0; !(data = Decoder::FindSubStr(syntax[typeIndex][nodeIndex].c_str(), (int)i, '\x1f')).empty(); i++)
			syntaxLib->push_back(data);
		return syntaxLib->at(1);
	}
		
	return "";
}

void Decoder_Tools::LanguageCompiler::LibraryConstructor(std::string elements)
{
	std::vector<std::string> element;
	std::string decipher;
	
	for (int i = 0; !(decipher = Decoder::FindSubStr(elements.c_str(), i, '\x1f')).empty(); i++)
		element.push_back(decipher);

	decipher.clear();
	
	for (int i = 0; i < element.size() && !(decipher = Decoder::FindSubStr(sl->DecodeLibrary(i).c_str(), element[i].c_str(), '\x1f', 1)).empty(); i++)
		libs.push_back(decipher);
}

void Decoder_Tools::LanguageCompiler::SyntaxConstructor(std::string elements)
{
	bool bElementAvailable = false;
	std::vector<std::string> element;
	std::string decipher;

	for (int i = 0; !(decipher = Decoder::FindSubStr(elements.c_str(), i, '\x1f')).empty(); i++)
		element.push_back(decipher);

	decipher.clear();

	// Syntax Nodes
	for (int i = 0, d = 0; d < element.size() && !sl->DecodeSyntax(i).empty(); i++)
	{
		// Header // 1 (0, 0) | i = 0, j = ?
		if (element[d] == Decoder::FindSubStr(sl->DecodeSyntax(i).at(0).c_str(), element[d].c_str(), '\x1f', 0))
		{
			syntax.emplace_back();
			bElementAvailable = !bElementAvailable;
		}
		
		for (int j = 0; bElementAvailable && j < sl->DecodeSyntax(i).size(); j++)
			syntax[d].push_back(sl->DecodeSyntax(i, j));

		if (bElementAvailable)
		{ d++; bElementAvailable = !bElementAvailable; }
	}		
}

void Decoder_Tools::LanguageCompiler::Parse_ProgrammingPlanner()
{
	// VECTOR 3D LOGIC (BEST FIT IN THIS SCENARIO) -
	// Without this method I could have used single vectors, pointers or I could have rerun another substr test
	// Substr tests are slow! but because each logic is ran at different times it doesn't impact the software.
	// This demonstrates a 3D Vector. This could also be done with pointers.
	std::string jStr, kStr;

	for (size_t i = 0; i < pPlanner.size(); i++)
	{
		plannerSyntax.emplace_back();
		
		for (size_t j = 0, d = 1; !(jStr = pPlanner[i]->Find((int)d)).empty(); j++, d++)
		{
			plannerSyntax[i].emplace_back();
			
			for (size_t k = 0; !(kStr = std::string(Decoder::FindSubStr(jStr.c_str(), ':', ';', (int)k))).empty(); k++)
			{
				if (kStr == "null") kStr = std::string(); plannerSyntax[i][j].push_back(kStr);
			}
				
		}
	}
}

int Decoder_Tools::LanguageCompiler::GetType_ProgrammingPlanner(int i, int j)
{
	// Finds parents, children and arguments

	// Argument - is called first as it is quicker to find arguments first.
	if (pPlanner[i]->GetSignature() == "A") return 2;
	
	const int index = GetParentID_ProgrammingPlanner(i, j);
	
	// Child
	if (index != -1) return 1;

	// parent
	return 0;
}

int Decoder_Tools::LanguageCompiler::GetParentID_ProgrammingPlanner(int i, int j)
{
	// change this logic 
	int parentID; Functions func;
	const std::string id = pPlanner[i]->Find(j+1, true);
	
	std::string childID = Decoder::FindSubStr(id.c_str(), 1, '\x1f'),
	relation = Decoder::FindSubStr(childID.c_str(), 2, '-');
	
	// if relation is not empty, set parentID to TextToNumber(relation), else set to -1
	!relation.empty() ? parentID = (int)func.TextToNumber(relation) : parentID = -1;

	return parentID;
}

int Decoder_Tools::LanguageCompiler::GetParentID_ProgrammingPlanner(const char* str)
{
	int parentID; Functions func;
	
	std::string childID = Decoder::FindSubStr(str, 1, '\x1f'),
	relation = Decoder::FindSubStr(childID.c_str(), 2, '-');

	// if relation is not empty, set parentID to TextToNumber(relation), else set to -1
	!relation.empty() ? parentID = (int)func.TextToNumber(relation) : parentID = -1;

	return parentID;
}

std::string Decoder_Tools::LanguageCompiler::Retrieve_ProgrammingPlanner(size_t i, size_t k, size_t jOffset)
{
	for (size_t j = jOffset; i < plannerSyntax.size() && j < plannerSyntax[i].size(); j++)
		if (k < plannerSyntax[i][j].size()) return plannerSyntax[i][j][k];

	return std::string();
}

std::string* Decoder_Tools::LanguageCompiler::GetArgumentComponents(const char* str)
{
	// Temporary Function - Explanation: Due to some poor software planning,
	// the arguments does not fit in this scenario very well. The fact that
	// arguments rely on Functions XML nodes and others do not, is one of the
	// reasonings. (This library could be re-modified. Planner Syntax, may not always
	// have a type order of 0 - class, 1 - function, 2 - argument but of 0 - function, 2 - argument
	// Setting up a dictionary type could fix this problem.
	std::string iStr, *argComps = new std::string[3];

	for (size_t i = 0; !(iStr = std::string(Decoder::FindSubStr(str, ':', ';', (int)i))).empty(); i++)
	{ if (iStr == "null") iStr = std::string(); argComps[i] = iStr; }
	
	return argComps;
}
