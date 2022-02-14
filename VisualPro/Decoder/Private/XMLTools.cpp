/* Author: Edward Patch */
/* Libraries Used: RapidXML, M. Kalicinski, “RapidXml,” RAPIDXML, 2009. http://rapidxml.sourceforge.net/ (accessed Oct. 30, 2021).
	Description of Library: Gives tools to communicate with the XML document. However, the tool didn't offer navigational tools. Update: After researching further, there is a way to navigate XML using this library, however, it seemed to be very brief. I created these tools on top to navigate through the Language XML document with ease. */

#include "../Public/LanguageConfiguration.h"

Decoder_Tools::XMLTools::XMLTools(std::string xmlDir, std::string xmlFile, bool debug) : XMLConfiguration(xmlDir, xmlFile, debug)
{ }

rapidxml::file<> Decoder_Tools::XMLTools::OpenXML(const char* xmlFileName)
{
	std::string dir = std::string(GetConfDirectory()) + '/' + xmlFileName;

	rapidxml::file<> file(dir.c_str());
	return file;
}

rapidxml::xml_node<>* Decoder_Tools::XMLTools::SelectNode(rapidxml::xml_node<>* parent, int depth)
{	
	int i = 0;

	for(rapidxml::xml_node<>* child = parent->first_node(); child; child = child->next_sibling())
	{
		if(i == depth)
			return child;

		i++;
	}

	return nullptr;
}

rapidxml::xml_attribute<>* Decoder_Tools::XMLTools::SelectAttribute(rapidxml::xml_node<>* parent, int depth)
{
	int i = 0;

	for(rapidxml::xml_attribute<>* child = parent->first_attribute(); child; child = child->next_attribute())
	{
		if (i == depth)
			return child;
		
		i++;
	}
	
	return nullptr;
}