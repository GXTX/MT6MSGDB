#include <string>
#include <vector>
#include <filesystem>

#include "rapidcsv.h"

int main()
{
	if (!std::filesystem::exists("db.csv")) {
		std::cerr << "Can't find db.csv\n";
		return 1;
	}

	rapidcsv::Document db("db.csv");

	std::vector<std::string> enums = db.GetColumn<std::string>("ENUM");
	std::vector<std::string> text = db.GetColumn<std::string>("US");

	std::cout << "MessageList = {\r\n";
	for (auto i = 0; i < enums.size(); i++) {
		std::cout << "	{\r\n";
		std::printf("		MessageID = \"%s\",\r\n", enums.at(i).c_str());
		std::printf("		Message = \"%s\",\r\n", text.at(i).c_str());
		std::cout << "	},\r\n";
	}
	std::cout << "};";

	return 0;
}