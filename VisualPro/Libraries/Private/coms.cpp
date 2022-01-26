#include "../Public/coms.h"

// Cache Namespace
Cache::TemporaryStorage* InitialiseTS()
{ return new Cache::TemporaryStorage(); }

void DisposeTS(Cache::TemporaryStorage* ts)
{ delete ts; }



// Decoder Tools
const char* FindSubStr(Cache::TemporaryStorage* ts, const char* str, int pos, char seperator)
{
	if (ts) return ts->StrToCStr(Decoder_Tools::Decoder::FindSubStr(str, pos, seperator));

	return "";
}