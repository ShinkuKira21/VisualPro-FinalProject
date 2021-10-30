/* Author: Edward Patch */

#include "../Public/Decoder.h"

void Decoder_Tools::Decoder::Decipher()
{ }


// FIRST MADE IN C#
std::string Decoder_Tools::Decoder::FindSubStr(const char* str, const char* strToTest, char separator, int pos)
{
	// # TO_DO:- Add FindSubStr(const char* str, int pos, char separator)
	
	//name;value
	//io;iostream
	//string:string
	std::string substr;
	bool bEnablePos = false;
	
	// loop through the str argument length, declaring i and j variables, incrementing j.
	for(size_t i = 0, j = 0; i < std::string(str).length(); i++)
	{
		// if str[i] is not equal to seperator, add str[i] to substr
		if (str[i] != separator)
			substr += str[i];

		// if str[i] is equal to seperator or i + 1 is equal to str length
		if (str[i] == separator || i + 1 == std::string(str).length())
		{
			// returns j if position met and bEnablePos is true
			if (pos == j && bEnablePos) return substr;
			if (substr == strToTest && pos == -2) return std::to_string(j);
			// if substr is equal to strToTest and mode is -2, return position.

			j++;
			
			// if substr is equal to strToTest and mode is -1, return word found.
			if(substr == strToTest && pos == -1) return substr;

			// clear substr
			substr.clear();
		}

		// if substr is equal to strToTest enable bEnablePos (for the position == j statement)
		if (substr == strToTest) bEnablePos = true;

		// if (bEnablePos is false and j is more than or equal to pos + 1), pos is more than mode -1.
		// return empty string
		if (pos > -1 && (!bEnablePos && (int)j >= pos + 1)) return std::string();
	}

	// return substr (this should usually be empty if at this point)
	return substr;
}

// Finds SubString based on Start, End and Position
std::string Decoder_Tools::Decoder::FindSubStr(const char* str, char start, char end, int pos)
{
	int count = 0; std::string substr; bool bStarted = false;

	// loops str size
	for(size_t i = 0; i < std::string(str).size(); i++)
	{
		// if bStarted is not true and str[i] is equal to start and count equals pos
		// bStarted is set to true and continue.
		if(!bStarted && str[i] == start && count == pos)
		{ bStarted = true; continue; }

		// if bStarted is not true and str[i] is equal to start, increment count
		if (!bStarted && str[i] == start)
			count++;

		// if bStarted and str[i] is not equal to end,
		// add str[i] to substr.
		if (bStarted && str[i] != end)
			substr += str[i];

		// else if bStarted, break loop.
		else if (bStarted)
			break;
	}
	
	return substr;
}

// Find substring based on index
std::string Decoder_Tools::Decoder::FindSubStr(const char* str, int pos, char separator)
{
	std::string substr;

	// loops str length
	for(size_t i = 0, j = 0; i < std::string(str).length(); i++)
	{
		// if str[i] is not equal to seperator,
		// add str[i] to substr
		if (str[i] != separator)
			substr += str[i];
		
		// if str[i] is equal to seperator or i + 1 is equal to str length
		if(str[i] == separator || i + 1 == std::string(str).length())
		{ 
			// if j equal to position, return
			if ((int)j == pos) return substr;
			j++;
			substr.clear();
		}
	}
	
	return "";
}

// Find index of the string
int Decoder_Tools::Decoder::FindStrIndex(const char* str, char charToTest)
{	
	// loops str length and return index if str[i] is equal to charToTest
	for(size_t i = 0; i < std::string(str).length(); i++)
		if (str[i] == charToTest) return (int)i;
	
	return -1;
}

// Replaces Word After Finding It
std::string Decoder_Tools::Decoder::ReplaceWord(const char* str, const char* strToTest, const char* replaceStr)
{
	// sets start using std::string().find function passing strToTest through
	const size_t start = std::string(str).find(strToTest);
	const size_t end = start + std::string(strToTest).size();
	// sets end using start adding std::string().size() passing strToTest through

	// sets str to substr
	std::string substr = str;

	// makes sure start is not invalid
	// if start is equal to npos, replace the start and end in substr with replaceStr argument.
	if(start != std::string::npos) substr.replace(start, end, replaceStr);

	return substr;
}
