#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

bool is_strong(std::string p) {
	bool has_upp = false;
	for (char c : p) {
		if (std::isupper(c)){
			has_upp = true;
		}
	}
	bool has_len = (p.length() >= 8);
	return (has_upp && has_len);
}

int main(){
	std::ifstream passwords('passwords.txt');

	if (!passwords) {
		std::err << "error with opening file" << std::endl;
		return 1;
	}
	std::string line;
	while (std::getline(passwords, line)) {
		if (!is_strong(line)){
			std::cerr << "Invalid" << std::endl;
		}
	}
	return 0;
}
