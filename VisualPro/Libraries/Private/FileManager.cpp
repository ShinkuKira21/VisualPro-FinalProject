#include "../Public/FileManager.h"

void FileManager::FileManager::SaveFile(const char* data, const char* fileDirectory)
{
	this->data = data; this->fileDirectory = fileDirectory;

	std::ofstream file(fileDirectory);
	file << data;
	file.close();
}

