#include <iostream>
#include <fstream>

int count_unique_students(std::string filename){
	std::ifstream file(filename);
	if (!file){
		std::cerr << "Error opening file" << std::endl;
		return -1;
	}
	std::string line;
	std::unordered_set<std::string> seen_list;
	while (std::getline(file, line)){
		if (line.empty()) continue;
		seen_list.insert(line);
	}
	return static_cast<int>(seen_list.size());
}

