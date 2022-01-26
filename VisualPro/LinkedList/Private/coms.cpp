//#include "../Public/coms.h"
//
//List* InitialiseClass(const char* inp)
//{ 
//	if(inp != nullptr) return new List(inp); 
//	return nullptr;
//}
//
//void DisposeClass(List* obj)
//{
//	if (obj != nullptr)
//	{
//		delete obj;
//		obj = nullptr;
//	}
//}
//
//const char* CallFunction(List* obj, const char* inp, const char* name, const char* parent, int id)
//{
//	if (obj != nullptr && inp != nullptr)
//	{
//		if (std::string(inp) == "Add" && name != nullptr) return obj->AddList(name, parent);
//		if (std::string(inp) == "Rem" && id != NULL) obj->RemoveList(id);
//		if (std::string(inp) == "FindName" && name != nullptr) return obj->Find(name);
//		if (std::string(inp) == "FindID" && id != NULL) return obj->Find(id).c_str();
//	}
//	
//	return "";
//}