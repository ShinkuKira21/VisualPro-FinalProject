#pragma once
#include "Decoder.h"

// Cache Namespace
extern "C" _declspec(dllexport) Cache::TemporaryStorage* InitialiseTS();

extern "C" _declspec(dllexport) void DisposeTS(Cache::TemporaryStorage* ts);

// Decoder Tools
extern "C" _declspec(dllexport) const char* FindSubStr(Cache::TemporaryStorage* ts, const char* str, int pos, char seperator);