#include "../Public/list.h"

List::List(const char* signature)
{
    list = nullptr; tmp = nullptr;
    this->signature = signature;
	sizeID = 0;  sizeTags = 2;
}

List::~List()
{   PointerUninitialisation();  }

const char* List::Add(const char* name, const char* parent)
{
    PointerResizer(1);

    std::string affix;
	
    // 0 - 0 - id, 0 - 1 - name
    if (!std::string(parent).empty()) affix = "\x1fP-" + std::string(parent);
    list[sizeID - 1][0] = IDGenerator() + affix;
    list[sizeID - 1][1] = name;

    return list[sizeID - 1][0].c_str();
}

void List::Edit(int id, const char* name)
{
	if(--id < sizeID)
		// Hex to Ascii: [edit] (edit)
        list[id][1] = name;
}

void List::Remove(int id)
{
    if (sizeID != 0)
    {
        //Hex to Ascii: [rm] (remove)
        if(Find(id, false, true) == "726d")
			PointerResizer(-1);
    }
}

void List::Clear()
{ PointerUninitialisation(); }


std::string List::Find(int id, bool bFindID, bool bReplace)
{
    int altID = 1;
    if (bFindID) altID = 0;

    const std::string strID = std::string(signature) + "-" + NumberToText(id);
    std::string listID, test;
	
    for (int i = 0; i < sizeID; i++)
        if (!(test = Decoder_Tools::Decoder::FindSubStr(list[i][0].c_str(), strID.c_str(), '\x1f')).empty())
        {                                                     //Hex to Ascii: [rm] (remove)
            if (bReplace) { list[i][0] = ""; list[i][1] = ""; return "726d"; }
            return list[i][altID];
        }
          
		return std::string();
}

const char* List::Find(const char* name)
{
    for(int i = 0; i < sizeID; i++)
	    if (std::string(name) == list[i][1])
	        return list[i][1].c_str();

    return "";
}

std::string List::ListAll()
{
    std::string strList;

    for (int i = 0; i < sizeID; i++)
    {
        for (int j = 0; j < sizeTags; j++)
            strList += list[i][j] + "  ";

        strList += '\n';
    }

    strList += '\n';
	
    return strList;
}

std::string List::GetSignature()
{ return signature; }

int List::Size() { return sizeID; }

void List::PointerResizer(int sizer)
{
    if (sizeID != 0)
    {
        CopyPointer();
        PointerUninitialisation();
    }

    sizeID += sizer;

    int newSize = 1; int idCounter = 0;

    if (sizer == -1)
        newSize = -1;
	
    list = new std::string*[sizeID];

    for(int i = 0; i < sizeID; i++)
        list[i] = new std::string[sizeTags];

    if (sizeID > 1 || sizer == -1)
        for (int i = 0; i < sizeID - newSize; i++)
        {
            for (int j = 0; j < sizeTags; j++)
            {   
				if (!tmp[i][j].empty())
                    list[idCounter][j] = tmp[i][j];
            }

            idCounter++;
            if (tmp[i][0].empty()) idCounter--;
            
        }

	if(sizeID - 1 != 0)
		PointerUninitialisation(1);
}

std::string List::IDGenerator()
{
    int id; std::string strID;
	
    if (sizeID == 1) id = 1;
    else id = int(TextToNumber(list[sizeID - 2][0].substr(2))) + 1;
	
    strID = std::string(signature);
    strID += "-" + NumberToText(id);
	
    return strID;
}

void List::CopyPointer()
{
    tmp = new std::string * [sizeID];

    for (int i = 0; i < sizeID; i++)
    {
        tmp[i] = new std::string[sizeTags];

        for (int j = 0; j < sizeTags; j++)
            tmp[i][j] = list[i][j];
    }
}

void List::PointerUninitialisation(int opt)
{
	if(opt == -1 && list != nullptr)
	{
        for (int i = 0; i < sizeID; i++)
            delete[] list[i];

        delete[] list;
	}

    if(opt == 1 && tmp != nullptr)
	{
        for (int i = 0; i < sizeID - 1; i++)
            delete[] tmp[i];

        delete[] tmp;
	}
}