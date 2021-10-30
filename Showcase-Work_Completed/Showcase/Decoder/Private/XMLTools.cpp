/* Author: Edward Patch */
/* Libraries Used: RapidXML, M. Kalicinski, “RapidXml,” RAPIDXML, 2009. http://rapidxml.sourceforge.net/.
	Description of Library: Gives tools to communicate with the XML document. However, the tool didn't offer navigational tools. Update: After researching further, there is a way to navigate XML using this library, however, it seemed to be very brief. I created these tools on top to navigate through the Language XML document with ease. */

#include "../Public/Decoder.h"

// Configures the location of the XML document and sets debug to false default
Decoder_Tools::XMLTools::XMLTools(std::string xmlDir, std::string xmlFile, bool debug) : XMLConfiguration(xmlDir, xmlFile, debug)
{ }

// Opens XML Document
rapidxml::file<> Decoder_Tools::XMLTools::OpenXML(const char* xmlFileName)
{
	// Gets the directory and file name of the xml file.
	std::string dir = std::string(GetConfDirectory()) + '/' + xmlFileName;

	// Opens XML File via rapidxml library.
	rapidxml::file<> file(dir.c_str());

	return file;
}

// Selects a node based on depth.
rapidxml::xml_node<>* Decoder_Tools::XMLTools::SelectNode(rapidxml::xml_node<>* parent, int depth)
{	
	int i = 0;

	// loop unless child is nullptr.
	for(rapidxml::xml_node<>* child = parent->first_node(); child; child = child->next_sibling())
	{
		// if i is equal to depth, return child, else i increment
		if(i == depth)
			return child;

		i++;
	}

	// if no child found, return nullptr
	return nullptr;
}

// Selects attributes based on depth.
rapidxml::xml_attribute<>* Decoder_Tools::XMLTools::SelectAttribute(rapidxml::xml_node<>* parent, int depth)
{
	int i = 0;

	// loop unless child is nullptr
	for(rapidxml::xml_attribute<>* child = parent->first_attribute(); child; child = child->next_attribute())
	{
		// if i is equal to depth, return child, else i increment.
		if (i == depth)
			return child;
		
		i++;
	}
	
	// if no child found, return nullptr.
	return nullptr;
}