#include <fstream>

class SaveFile {
	protected:
		std::string data, fileDirectory;

	public:
		SaveFile(std::string data, std::string fileDirectory);
};