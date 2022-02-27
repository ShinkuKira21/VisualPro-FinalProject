#pragma once
#include "../../Libraries/Public/Functions.h"
#include "../../Libraries/Public/Decoder.h"

class _declspec(dllimport) Functions;
class _declspec(dllimport) Decoder_Tools::Decoder;

class _declspec(dllexport) List : Functions
{
    protected:
        // ID - List 0:0, 0:1, 0:2, 1:0
        const char* signature;
        std::string** list; std::string** tmp; int sizeID, sizeTags;

    public:
        List(const char* signature);
        ~List();

        const char* Add(const char* name, const char* parent = "");
        void Edit(int id, const char* name);

        void Remove(int id);
        void Clear();
	
        const char* Find(const char* name);
        std::string Find(int id, bool bFindID = false, bool bReplace = false);
	
        std::string ListAll();
        std::string GetSignature();
	
        int Size();

    private:
        void PointerResizer(int sizer);
        void CopyPointer();
		
        void PointerUninitialisation(int opt = -1 /* default = all, 0 = list, 1 = tmp */);
        std::string IDGenerator();
};
