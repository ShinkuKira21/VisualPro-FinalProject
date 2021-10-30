/* Author: Edward Patch */
/* Libraries Used: RapidXML, M. Kalicinski, “RapidXml,” RAPIDXML, 2009. http://rapidxml.sourceforge.net/.
	Description of Library: Gives tools to communicate with the XML document. However, the tool didn't offer navigational tools. Update: After researching further, there is a way to navigate XML using this library, however, it seemed to be very brief. I created these tools on top to navigate through the Language XML document with ease. */

#include "../Public/Decoder.h"

// Open Config

// Read Config

// Find Language Folder

// Open Language

// Parse

// Find extra languages

// Parse


// Open Configuration File to Configure Languages etc.
Decoder_Tools::XMLConfiguration::XMLConfiguration(std::string xmlDir, std::string xmlFile, bool debug)
{
	this->xmlDir = xmlDir;

	// add ../ + postDIR in debugging!
	if (debug) { std::cout << "[MODE:] XML DEBUG ACTIVE\n\n"; this->xmlDir = "../" + xmlDir; };
	
	// dir of XML Configuration File.
	std::string dir = this->xmlDir + "/" + xmlFile;
	
	// loads XML File
	rapidxml::file<> file(dir.c_str());

	// Parses the XML Document.
	doc.parse<0>(file.data());

	// Fetches Configuration Nodes
	FetchConfigNodes();
}

// Get's Limiter (basically depth)
const int Decoder_Tools::XMLConfiguration::GetLimiter()
{ return limiter; }

// Get's Configuration Directory(s)
const char* Decoder_Tools::XMLConfiguration::GetConfDirectory()
{ return xmlDir.c_str(); }

// Get's Configuration Directory based on Selection.
const char* Decoder_Tools::XMLConfiguration::GetConfDirectory(int selection)
{
	if(selection < 2)
		return languages[selection].c_str();

	return nullptr;
}

// Get's Configuration Nodes within XML Doc
void Decoder_Tools::XMLConfiguration::FetchConfigNodes()
{
	// get first node of XML document.
	rapidxml::xml_node<>* parent = doc.first_node();
	// Iterates through siblings
	int i = 0;

	// fills in language name values (first and last attribute within language)
	for (rapidxml::xml_node<>* child = parent->first_node(); child; child = child->next_sibling())
	{
		languages[i] = child->last_attribute()->value();
		i++;

		// if i is equal to limiter (basically depth) then break;
		if (i == limiter) break;
	}
}