#include "../Public/coms.h"

// Cache Namespace
Cache::TemporaryStorage* InitialiseTS()
{ return new Cache::TemporaryStorage(); }

void DisposeTS(Cache::TemporaryStorage* ts)
{ delete ts; }

// Decoder Tools
const char* FindSubStr(Cache::TemporaryStorage* ts, const char* str, int pos, char seperator)
{
	if(ts) return ts->StrToCStr(Decoder_Tools::Decoder::FindSubStr(str, pos, seperator));

	return "";
}

// File Manager
void FileController(const char* command, const char* data, const char* directory)
{
	if (data != nullptr && directory != nullptr)
		if (std::string(command) == "707574") FileManager::FileManager().SaveFile(data, directory);
}