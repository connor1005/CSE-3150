#include <iostream>
#include "audit_mode.h"
#include "validation.h"
#include <cctype>
#include <fstream>
#include <sstream>

void process_file(std::string input, std::string output){
	char in_delim = '\t';
	if (input.length() >= 4) {
		std::string ext = input.substr(input.length() - 4);
		//tsv
		if (ext == ".tsv") in_delim = '\t';
		//csv
		else if (ext == ".csv") in_delim = ',';
}
	char out_delim = '\t';
	if (output.length() >= 4) {
		std::string ext = output.substr(output.length() - 4);
		//tsv
		if (ext == ".tsv") out_delim = '\t';
		//csv
		else if (ext == ".csv") out_delim = ',';
}
	std::ifstream in_file(input);
	std::ofstream out_file(output, std::ios::app);

	if (!in_file || !out_file) {
		std::cout << "Error opening file" << std::endl;
		return;
	}
	
	std::string line;

	while (std::getline(in_file, line)) {
		std::stringstream ss(line);
		std::string username, email, password;

		std::getline(ss, username, in_delim);
		std::getline(ss, email, in_delim);
		std::getline(ss, password);

		if (!is_valid_password(password)){
			out_file << username << out_delim << email << out_delim << password << '\n';
		}
	}
}


void run_menu(){
	int choice = 0;
	while (choice != 3){
		std::cout << "1. Check a single password\n"
			  << "2. Process a TSV/CSV file\n"
			  << "3. Quit\n";
		std::cin >> choice;

		switch(choice){
			case 1: {
				std::string password;
				std::cout << "Enter a password:\n";
				std::cin.ignore(256, '\n');
				std::getline(std::cin, password);
				if (is_valid_password(password)) {
					std::cout << "Valid\n";}
				else{
					std::cout << "Invalid\n";}
				break;
				}
			case 2: {
				std::string input_path, output_path;

				std::cout << "Input file path: ";
				std::cin >> input_path;
				std::cout << "Output file path: ";
				std::cin >> output_path;
				process_file(input_path, output_path);
				break;
				}
			case 3:
				break;
			default:
				std::cout << "Invalid choice" << std::endl;
				break;
		}
		}

}
