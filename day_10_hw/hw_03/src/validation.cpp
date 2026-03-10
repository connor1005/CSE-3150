#include <iostream>
#include "../include/validation.h"
#include <cctype>
using namespace std;

bool is_valid_password(std::string password){
	//check password requirements
	//use range-based loop
	//use functions from <cctype>
	bool length = false;
	bool upper = false;
	bool special = false;
	
	for (char c : password) {
		if (isupper(c)) upper = true;
		if (!isalnum(c)) special = true;
	}
	if (password.length() >= 8) length = true;
	
	if (length && upper && special) return true;

	return false;
}
