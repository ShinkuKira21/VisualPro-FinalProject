#include "../Public/manager.h"

Manager::Manager(const char* signature)
{
	ts = nullptr;
	managedList = new List(signature);
	
	list = new const char*[listSize];

	// member, datatype and name
	list[0] = "M:"; list[1] = "D:"; list[2] = "N:";
}

Manager::~Manager()
{
	delete managedList;
	delete[] list;

	delete ts;
}

void Manager::Add(const char* member, const char* dt, const char* name, const char* parent)
{
	const std::string strToAdd = std::string(list[0]) + std::string(member) + ";" + std::string(list[1]) + std::string(dt) + ";" + std::string(list[2]) + std::string(name);

	std::string strID = std::string(managedList->Add(strToAdd.c_str(), parent)).substr(2);
	id = int(TextToNumber(strID));
}

void Manager::Remove(int id)
{ managedList->Remove(id); }

std::string Manager::Find(int id, bool bFindID)
{ return managedList->Find(id, bFindID); }

std::string Manager::ParseList()
{ return managedList->ListAll(); }

std::string Manager::GetSignature()
{ return managedList->GetSignature(); }

void Manager::Decryption()
{
	const std::string decipher = managedList->Find(id);
	ts = new TemporaryStorage(listSize);
	
	for (int i = 0; i < decipher.length(); i++)
		if (decipher[i] == ':')
		{
			i++;
			
			for (int j = i; decipher[j] != ';' && j < decipher.length(); j++)
			{
				if (decipher[i - 2] == list[0][0])
					ts->list[0] += decipher[j];

				else if (decipher[i - 2] == list[1][0])
					ts->list[1] += decipher[j];

				else ts->list[2] += decipher[j];
			}
		}
}