/* Author: Edward Patch */
/* Libraries Used: RapidXML, M. Kalicinski, “RapidXml,” RAPIDXML, 2009. http://rapidxml.sourceforge.net/ (accessed Oct. 30, 2021).
	Description of Library: Gives tools to communicate with the XML document. However, the tool didn't offer navigational tools. Update: After researching further, there is a way to navigate XML using this library, however, it seemed to be very brief. I created these tools on top to navigate through the Language XML document with ease. */

#include "../Public/LanguageConfiguration.h"

Decoder_Tools::SupportedLanguages::SupportedLanguages(XMLTools* xmlTools, const char* language)
{
	this->xmlTools = xmlTools;

	// Opens main language XML file.
	LoadXMLFile(language);
}

void Decoder_Tools::SupportedLanguages::LoadXMLFile(const char* language)
{
	if (this->xmlTools->GetFileStatus("VisualPro.xml") != false)
	{
		rapidxml::file<> file = this->xmlTools->OpenXML("VisualPro.xml");
		document.parse<0>(file.data());

		ParseLanguage(GetLanguageIndex(language));
	}
	else languages = "";
}


void Decoder_Tools::SupportedLanguages::StartFindLanguages()
{
	FindDefaultLanguages();
	FindUserDefinedLanguages();

	for (int i = 0; i < attributes[0].size(); i++)
	{
		languages += attributes[0][i]->value();
		
		if (i + 1 != attributes[0].size()) languages += '\x1f';
	}
	
	attributes.clear();
}


void Decoder_Tools::SupportedLanguages::FindDefaultLanguages()
{
	// Parent Node (<language/> tag)
	nodes.push_back(document.first_node());

	attributes.emplace_back();
	
	// IF STATEMENT ADDS I INDEX BY +1 OFFSET.
	// J INDEX IS USED TO DESCRIBE NEXT INDEX.
	for(int i = 1, j = 0; xmlTools->SelectNode(nodes[0], j); i++, j++)
	{
		nodes.push_back(xmlTools->SelectNode(nodes[0], j));
		attributes[0].push_back(xmlTools->SelectAttribute(nodes[i], 0));
	}
	     
	nodes.clear(); // frees up nodes
}

void Decoder_Tools::SupportedLanguages::FindUserDefinedLanguages()
{
	// FIND TOTAL XML FIlES

	// PARSE EACH LANGUAGE
}


void Decoder_Tools::SupportedLanguages::ParseLanguage(int languageSelector)
{
	if (languages.empty()) StartFindLanguages();

	if (languageSelector == -1) return;

	// Store XML Locations
	rapidxml::xml_node<>* baseNode;

	baseNode = xmlTools->SelectNode(document.first_node(), languageSelector);

	ParseLibraries(baseNode);
	ParseSyntax(baseNode);
}

void Decoder_Tools::SupportedLanguages::ParseLibraries(rapidxml::xml_node<>* baseNode)
{
	// Finds Language Libraries XML Nodes
	nodes.push_back(xmlTools->SelectNode(baseNode, 0));
	
	for (int i = 1, j = 0; xmlTools->SelectNode(nodes[0], j); i++, j++)
	{
		nodes.push_back(xmlTools->SelectNode(nodes[0], j));

		attributes.emplace_back();
		for (int k = 0; xmlTools->SelectAttribute(nodes[i], k); k++)
			attributes[j].push_back(xmlTools->SelectAttribute(nodes[i], k));
	}

	nodes.clear();

	// 0, 1, 2, 3
	for (int i = 0; i < attributes.size(); i++)
	{
		libs.emplace_back();
		for (int j = 0; j < attributes[i].size(); j++)
		{
			if (j != 0) libs[i] += "\x1f"; libs[i] += attributes[i][j]->value();
		}
	}
	
	attributes.clear();
}

void Decoder_Tools::SupportedLanguages::ParseSyntax(rapidxml::xml_node<>* baseNode)
{
	// Finds Language Syntax XML Nodes
	rapidxml::xml_node<>* rapidXML = xmlTools->SelectNode(baseNode, 1);
	rapidxml::xml_node<>* node; rapidxml::xml_attribute<>* attribute;
	
	for (int i = 0; (node = xmlTools->SelectNode(rapidXML, i)); i++)
	{
		nodes.push_back(node);
		
		for (int j = 0, d = 1; (node = xmlTools->SelectNode(nodes[0], j)); j++, d++)
		{
			nodes.push_back(node);

			attributes.emplace_back();

			for (int k = 0; (attribute = xmlTools->SelectAttribute(nodes[d], k)); k++)
				attributes[j].push_back(attribute);
		}
		
		nodes.clear();
		syntax.emplace_back();

		// 0 - headers
		for (int j = 0; j < attributes.size(); j++)
		{
			syntax[i].emplace_back();

			for (int k = 0; k < attributes[j].size(); k++)
			{
				if (k != 0) syntax[i][j] += "\x1f";  syntax[i][j] += attributes[j][k]->value();
			}
		}

		attributes.clear();		
	}
}

std::string Decoder_Tools::SupportedLanguages::DecodeLibrary(size_t i)
{
	if (i < libs.size()) return libs[i];
	return "";
}

std::vector<std::string> Decoder_Tools::SupportedLanguages::DecodeSyntax(size_t i)
{ 
	if (i < syntax.size()) return syntax[i];
	return std::vector<std::string>(); // empty vector
}

std::string Decoder_Tools::SupportedLanguages::DecodeSyntax(size_t i, size_t j)
{
	if (i < syntax.size()) 
		if(j < syntax[i].size())
			return syntax[i][j];
	
	return "";
}

const char* Decoder_Tools::SupportedLanguages::ListAvailableLanguages()
{ return languages.c_str(); }

std::string Decoder_Tools::SupportedLanguages::ListAvailableLibraries(const char* language)
{
	LoadXMLFile(language);

	std::string libraries;
	for (size_t i = 0; i < libs.size(); i++)
		i + 1 != libs.size() ? libraries += Decoder::FindSubStr(DecodeLibrary(i).c_str(), 0, '\x1f') + '\x1f' : libraries += Decoder::FindSubStr(DecodeLibrary(i).c_str(), 0, '\x1f');

	return libraries;
}

std::string Decoder_Tools::SupportedLanguages::ListAvailableSyntaxes(const char* language)
{
	LoadXMLFile(language);
	std::string syntaxes;
	for (size_t i = 0; i < syntax.size(); i++)
		i + 1 != syntax.size() ? syntaxes += Decoder::FindSubStr(DecodeSyntax(i, 0).c_str(), 0, '\x1f') += '\x1f' : syntaxes += Decoder::FindSubStr(DecodeSyntax(i, 0).c_str(), 0, '\x1f');
	return syntaxes;
}

int Decoder_Tools::SupportedLanguages::GetLanguageIndex(const char* language)
{
	Functions func;
	if (languages.empty()) StartFindLanguages();

	if (std::string(language).empty()) return -1;
	return func.TextToNumber(Decoder::FindSubStr(languages.c_str(), language, '\x1f', -2));
}