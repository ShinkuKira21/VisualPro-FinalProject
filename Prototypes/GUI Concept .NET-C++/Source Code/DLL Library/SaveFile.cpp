#include "SaveFile.h"

SaveFile::SaveFile(std::string data, std::string fileDirectory)
{
	this->data = data; this->fileDirectory = fileDirectory;
	
	std::ofstream file(fileDirectory.c_str());
	file << data;
}