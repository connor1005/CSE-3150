#include <iostream>
#include <cctype>
#include <sstream>

std::expected<bool, std::string> is_suspicious(std::string username){
	if (username.empty()){
		return std::unexpected("Empty username");
	}
	int digi_count = 0;
	for (char c : username){
		unsigned char uc = static_cast<unsigned char>(c);
		if (std::isdigit(uc)){
			digi_count++;
		}
		if (!std::isalnum(uc)){
			return true;
		}
	}
	if (digi_count > 2){
		return true;
	}
	return false;
}

int main(){
	std::vector<std::string> test_users = {"admin123", "user!!", "root", ""};
	std::unordered_map<std::string, std::string> results;
	
	for (const std::string& user : test_users){
		auto result = is_suspicious(user);
		if (result) {
			results[user] = (result.value() ? "Suspicious" : "Safe");
		}
		else{
			std::err << "Error for " << user << ":" << result.error() << std::endl;
		}
	}
	for (const auto& pair : results){
		std::cout << pair.first << "->" << pair.second << std::endl;
	}
	return 0;
}

