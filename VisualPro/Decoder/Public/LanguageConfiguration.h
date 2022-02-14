#pragma once
#include "../../Manager/Public/programmingPlanner.h"
#include <fstream>
// RapidXML was picked to parse in XML files
#include "../../packages/rapidxml.1.13/build/native/include/rapidxml/rapidxml.hpp"
#include "../../packages/rapidxml.1.13/build/native/include/rapidxml/rapidxml_utils.hpp"

namespace Decoder_Tools
{
	class _declspec(dllimport) XMLTools;
	class _declspec(dllimport) Decoder;
	//class _declspec(dllimport) FileStream;
	
	class _declspec(dllexport) SupportedLanguages
	{
		XMLTools* xmlTools;
		std::string languages;
		rapidxml::xml_document<> document;
		

		std::vector<rapidxml::xml_node<>*> nodes;
		std::vector<std::vector<rapidxml::xml_attribute<>*>> attributes;

		std::vector<std::string> libs;
		std::vector<std::vector<std::string>> syntax;
		
		public:
			SupportedLanguages(XMLTools* xmlTools, const char* language = "");

			const char* ListAvailableLanguages();
			int GetLanguageIndex(const char* language);
		
			void ParseLanguage(int languageSelector);

			std::string DecodeLibrary(int i);
			std::string DecodeSyntax(int i, int j);
			std::vector<std::string> DecodeSyntax(int i);
		
		private:
			void StartFindLanguages(); // Binds both FindDefaultLanguages and FindUserDefinedLanguages functions.
			void FindDefaultLanguages();
			void FindUserDefinedLanguages();

			void ParseLibraries(rapidxml::xml_node<>* baseNode);
			void ParseSyntax(rapidxml::xml_node<>* baseNode);
	};

	class _declspec(dllexport) LanguageCompiler
	{
		SupportedLanguages* sl;
		std::string language, data;
		int zIndex = 0; const char* member, *seperator; bool bTagsEnabled;
		std::vector<ProgrammingPlanner*> pPlanner;

		//								Memory will only get used in SyntaxCompilation Part 2:)
		// MemoryName:Value
		std::vector<std::string>  libs, tags;
		std::vector<std::vector<std::string>> syntax;
		std::vector<std::vector<std::vector<std::string>>> plannerSyntax;

		public:
			LanguageCompiler(SupportedLanguages* sl, std::vector<ProgrammingPlanner*> pPlanner, const char* libraries, const char* syntax);

			void Compilation();
			std::string LibraryCompilation();

			// Two Parts
			void SyntaxCompilation(std::vector<std::string>* syntaxLib, size_t typeIndex, size_t nodeIndex, const char* name); // One - Combines with Syntax (from XML)
			std::string SyntaxCompilation(std::vector<std::vector<std::string>> lib, std::vector<std::string> argIDs, int parentID, size_t elementIndex, size_t nodeIndex, const char* name, bool bChild = false); // Two - Generates Code
		
			std::string ChildHandler(const char* data);
			static std::string StringCompilation(const char* str, const char* strToTest, const char* strToReplace);
		
			// Syntax Comp
			void LibraryConstructor(std::string elements);
			void SyntaxConstructor(std::string elements);
		
			// Planner Interface
			std::string ParseSyntax(std::vector<std::string>* syntaxLib, size_t typeIndex, size_t nodeIndex);
			void Parse_ProgrammingPlanner();
			int GetType_ProgrammingPlanner(int i, int j);
			int GetParentID_ProgrammingPlanner(int i, int j);
			int GetParentID_ProgrammingPlanner(const char* str);
			std::string Retrieve_ProgrammingPlanner(size_t i, size_t k, size_t jOffset);

			// Temporary Tools
			std::string* GetArgumentComponents(const char* str);
	};
	
	class _declspec(dllexport) XMLConfiguration
	{
		rapidxml::xml_document<> doc;
		int limiter = 2;
		std::string languages[2], xmlDir;

		protected:
			const int GetLimiter();
			const char* GetConfDirectory();
		
		public:
			XMLConfiguration(std::string xmlDir, std::string xmlFile, bool debug = false);
			const char* GetConfDirectory(int selection);
			bool GetFileStatus(std::string fileToCheck);

		private:
			void FetchConfigNodes();
	};

	class _declspec(dllexport) XMLTools : public XMLConfiguration
	{
		public:
			XMLTools(std::string xmlDir, std::string xmlFile, bool debug = false);

			rapidxml::file<> OpenXML(const char* xmlFileName);

			rapidxml::xml_node<>* SelectNode(rapidxml::xml_node<>* parent, int depth);
			rapidxml::xml_attribute<>* SelectAttribute(rapidxml::xml_node<>* parent, int depth);
	};

	
	/* Depreciated for now - Considering saving files via C++ or C#
	 * I'll check performance for both and decide if it's worth calling
	 * the class in the already loaded file. (I am considering to writing C
	 * file writing and reading methods.)
	 */

	/*
	class _declspec(dllexport) FileStream
	{
		std::ifstream inFileStream;
		std::string line;
		std::string fileContent;
		
		public:
			FileStream(const char* dir, const char* filename);

			// Returns file content
			const char* GetFileContent();

		private:
			void FileStreamToConstChar();
	};*/
}


