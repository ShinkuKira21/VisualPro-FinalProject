/* Author: Edward Patch */
/* Libraries Used: RapidXML, M. Kalicinski, “RapidXml,” RAPIDXML, 2009. http://rapidxml.sourceforge.net/.
	Description of Library: Gives tools to communicate with the XML document. However, the tool didn't offer navigational tools. Update: After researching further, there is a way to navigate XML using this library, however, it seemed to be very brief. I created these tools on top to navigate through the Language XML document with ease. */

#pragma once

#include "../../Library_Tools/Public/Functions.h"

// RapidXML was picked to parse in XML files
#include "../../packages/rapidxml.1.13/build/native/include/rapidxml/rapidxml.hpp"
#include "../../packages/rapidxml.1.13/build/native/include/rapidxml/rapidxml_utils.hpp"

namespace Decoder_Tools
{	
	// Reads XML Configuration Document
	class _declspec(dllexport) XMLConfiguration
	{
		// XML Doc
		rapidxml::xml_document<> doc;
		int limiter = 2;
		std::string languages[2], xmlDir;

		protected:
			const int GetLimiter();
			const char* GetConfDirectory();
		
		public:
			XMLConfiguration(std::string xmlDir, std::string xmlFile, bool debug = false);
			const char* GetConfDirectory(int selection);

		private:
			void FetchConfigNodes();
	};

	// Offers XML Navigational Tools
	class _declspec(dllexport) XMLTools : public XMLConfiguration
	{
		public:
			XMLTools(std::string xmlDir, std::string xmlFile, bool debug = false);

			rapidxml::file<> OpenXML(const char* xmlFileName);

			rapidxml::xml_node<>* SelectNode(rapidxml::xml_node<>* parent, int depth);
			rapidxml::xml_attribute<>* SelectAttribute(rapidxml::xml_node<>* parent, int depth);
	};
}


