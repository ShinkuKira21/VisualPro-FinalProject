/* Author: Edward Patch */
/* Libraries Used: RapidXML, M. Kalicinski, “RapidXml,” RAPIDXML, 2009. http://rapidxml.sourceforge.net/ (accessed Oct. 30, 2021).
	Description of Library: Gives tools to communicate with the XML document. However, the tool didn't offer navigational tools. Update: After researching further, there is a way to navigate XML using this library, however, it seemed to be very brief. I created these tools on top to navigate through the Language XML document with ease. */

#include "../Public/LanguageConfiguration.h"

// Open Config

// Read Config

// Find Language Folder

// Open Language

// Parse

// Find extra languages

// Parse


Decoder_Tools::XMLConfiguration::XMLConfiguration(std::string xmlDir, std::string xmlFile, bool debug)
{
	this->xmlDir = xmlDir;

	// add ../ + postDIR in debugging!
	if (debug) { std::cout << "[MODE:] XML DEBUG ACTIVE\n\n"; this->xmlDir = "../" + xmlDir; };
	
	std::string dir = this->xmlDir + "/" + xmlFile;
	
	rapidxml::file<> file(dir.c_str());

	doc.parse<0>(file.data());

	FetchConfigNodes();
}

const int Decoder_Tools::XMLConfiguration::GetLimiter()
{ return limiter; }

const char* Decoder_Tools::XMLConfiguration::GetConfDirectory()
{ return xmlDir.c_str(); }

const char* Decoder_Tools::XMLConfiguration::GetConfDirectory(int selection)
{
	if(selection < 2)
		return languages[selection].c_str();

	return nullptr;
}

bool Decoder_Tools::XMLConfiguration::GetFileStatus(std::string fileToCheck)
{
	std::fstream file; file.open(std::string(GetConfDirectory()) + '/' + fileToCheck);

	if (file.fail()) return false;
	return true;
}


void Decoder_Tools::XMLConfiguration::FetchConfigNodes()
{
	rapidxml::xml_node<>* parent = doc.first_node();
	// Iterates through siblings
	int i = 0;
	for (rapidxml::xml_node<>* child = parent->first_node(); child; child = child->next_sibling())
	{
		languages[i] = child->last_attribute()->value();
		i++;

		if (i == limiter) break;
	}
}