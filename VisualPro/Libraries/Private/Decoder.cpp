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
	
	for(size_t i = 0, j = 0; i < std::string(str).length(); i++)
	{
		if (str[i] != separator)
			substr += str[i];

		if (str[i] == separator || i + 1 == std::string(str).length())
		{
			if (pos == j && bEnablePos) return substr;
			if (substr == strToTest && pos == -2) return std::to_string(j);
			
			j++;
			
			if(substr == strToTest && pos == -1) return substr;

			substr.clear();
		}

		if (substr == strToTest) bEnablePos = true;

		if (pos > -1 && (!bEnablePos && (int)j >= pos + 1)) return std::string();
	}

	return substr;
}

std::string Decoder_Tools::Decoder::FindSubStr(const char* str, char start, char end, int pos)
{
	int count = 0; std::string substr; bool bStarted = false;

	for(size_t i = 0; i < std::string(str).size(); i++)
	{
		if(!bStarted && str[i] == start && count == pos)
		{ bStarted = true; continue; }

		if (!bStarted && str[i] == start)
			count++;

		if (bStarted && str[i] != end)
			substr += str[i];

		else if (bStarted)
			break;
	}
	
	return substr;
}


std::string Decoder_Tools::Decoder::FindSubStr(const char* str, int pos, char separator)
{
	std::string substr;

	for(size_t i = 0, j = 0; i < std::string(str).length(); i++)
	{
		if (str[i] != separator)
			substr += str[i];
		
		if(str[i] == separator || i + 1 == std::string(str).length())
		{
			if ((int)j == pos) return substr;
			j++;
			substr.clear();
		}
	}
	
	return "";
}

int Decoder_Tools::Decoder::FindStrIndex(const char* str, char charToTest)
{	
	for(size_t i = 0; i < std::string(str).length(); i++)
		if (str[i] == charToTest) return (int)i;
	
	return -1;
}

std::string Decoder_Tools::Decoder::ReplaceWord(const char* str, const char* strToTest, const char* replaceStr)
{
	const size_t start = std::string(str).find(strToTest);
	const size_t end = start + std::string(strToTest).size();

	std::string substr = str;

	if(start != std::string::npos) substr.replace(start, end, replaceStr);

	return substr;
}
