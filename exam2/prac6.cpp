#include <iostream>
#include <fstream>

void save_passing_students(std::string input_file, std::string output_file, int threshold){
	std::ifstream ifile(input_file);
	std::ofstream ofile(output_file);
	
	if(!ifile.is_open() || !ofile.is_open()){
		std::cerr << "Failed to open file" << std::endl;
		return;
	}
	
	std::string name;
	int score;

	while (ifile >> name >> score){
		if (score >= threshold){
			ofile << name << std::endl;
		}
	}
}

