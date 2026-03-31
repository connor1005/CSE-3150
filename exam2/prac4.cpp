#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include "prac4.h"

void check_duplicates(std::string filename){
	std::ifstream students(filename);
	if (!students.is_open()){
		std::cerr << "Error opening file " << students << std::endl;
		return;
	}
	
	std::string line;
	std::unordered_set<std::string> seen_names;
	bool found_duplicate = false;

	while (std::getline(students,line)) {
		if (line.empty()) continue;
		auto result = seen_names.insert(line);
		if (!result.second) {
			std::cout << "Duplicate detected: " << line << std::endl;
			found_duplicate = true;
		}
	}
	if (!found_duplicate){
		std::cout << "No duplicates detected." << std::endl;
	}
	students.close();
}
