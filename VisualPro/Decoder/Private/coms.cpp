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

char* CompileLanguage(Memory* memory, Cache::TemporaryStorage ts, Decoder_Tools::XMLTools* xmlDoc, const char* language, const char* libraries, const char* syntax)
{
	Decoder_Tools::SupportedLanguages supportedLanguages(xmlDoc, language);
	Decoder_Tools::LanguageCompiler languageCompiler(&supportedLanguages, memory->programmingPlanner, libraries, syntax);

	return nullptr;
}

const char* SendCommand(Cache::TemporaryStorage* ts, Decoder_Tools::XMLTools* xmlDoc, const char* command)
{
	if(xmlDoc != nullptr && ts != nullptr && !std::string(command).empty())
	{
		// Returns available languages
		if (std::string(command) == "LAL")
			return ts->StrToCStr(Decoder_Tools::SupportedLanguages(xmlDoc).ListAvailableLanguages());
			
	}
	
	return nullptr;
}
