#include <iostream>
#include <fstream>
#include <cctype>
#include <sstream>

std::expected<int*, std::string> create_safe_copy(const int* arr, int size){
	if (size < 1){
		return std::unexpected("Invalid size");
	}

