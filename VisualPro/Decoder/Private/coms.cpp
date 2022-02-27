#include "../Public/coms.h"
#include "../../Manager/Public/manager.h"

Memory* InitialisePlannerClass()
{ return new Memory(); }

void AddPlan(Memory* memory, ProgrammingPlanner* programmingPlanner)
{
	if(memory != nullptr && programmingPlanner != nullptr)
		memory->programmingPlanner.push_back(programmingPlanner);
}

void DisposePlannerClass(Memory* memory)
{ delete memory; }

Decoder_Tools::XMLTools* InitialiseXMLClass(const char* xmlDir, const char* xmlFile, bool debug)
{ return new Decoder_Tools::XMLTools(xmlDir, xmlFile, debug); }


void DisposeXMLClass(Decoder_Tools::XMLTools* xml)
{ delete xml; }

const char* CompileLanguage(Memory* memory, Cache::TemporaryStorage* ts, Decoder_Tools::XMLTools* xmlDoc, const char* language, const char* libraries, const char* syntax)
{
	Decoder_Tools::SupportedLanguages supportedLanguages(xmlDoc, language);
	Decoder_Tools::LanguageCompiler languageCompiler(&supportedLanguages, memory->programmingPlanner, libraries, syntax);

	return ts->StrToCStr(languageCompiler.FetchCompiledData());
}

const char* SendCommand(Cache::TemporaryStorage* ts, Decoder_Tools::XMLTools* xmlDoc, const char* command, const char* language)
{
	if(xmlDoc != nullptr && ts != nullptr && !std::string(command).empty())
	{
		// Returns available libraries - Hex to Text | 4c4150 -> LAP (List All Packages)
		if (std::string(command) == "4c4150")
			return ts->StrToCStr(Decoder_Tools::SupportedLanguages(xmlDoc).ListAvailableLibraries(language));

		// Returns available syntaxes - Hex to Text | 4c4153 -> LAS (List All Syntaxes)
		if (std::string(command) == "4c4153")
			return ts->StrToCStr(Decoder_Tools::SupportedLanguages(xmlDoc).ListAvailableSyntaxes(language));

		// Returns available languages - Hex to Text | 4c414c -> LAL (List All Languages)
		if (std::string(command) == "4c414c")
			return ts->StrToCStr(Decoder_Tools::SupportedLanguages(xmlDoc).ListAvailableLanguages());
	}
	
	return nullptr;
}
