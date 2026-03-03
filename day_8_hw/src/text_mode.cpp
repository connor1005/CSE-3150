#include <iostream>
#include <string>
#include <cctype>
#include "../include/text_mode.h"

namespace text_mode {
  void run(int argc, char* argv[]) {
    if (argc < 3) {
      std::cout << "Missing argument for text mode." << std::endl;
      return;
    }
    std::string str = argv[2];
    std::cout << "Original: " << str << std::endl;
    size_t len = str.size();
    std::cout << "Length: " << len << std::endl;
    
    int letters = 0, digits = 0, spaces = 0, puncts = 0;

    for (char c : str) {
      if (std::isalpha(c)) letters++;
      if (std::isdigit(c)) digits++;
      if (std::isspace(c)) spaces++;
      if (std::ispunct(c)) puncts++;
    }

    std::cout << "Letters: " << letters << std::endl;
    std::cout << "Digits: " << digits << std::endl;
    std::cout << "Spaces: " << spaces << std::endl;
    std::cout << "Punctuation: " << puncts << std::endl;

    std::string upper_copy = "";
    for (size_t i = 0; i < len; ++i) {
      upper_copy += std::toupper(str[i]);
    }
    std::cout << "Uppercase: " << upper_copy << std::endl;

    for (size_t i = 0; i < len; ++i) {
      str[i] = std::tolower(str[i]);
    }
    std::cout << "Lowercase: " << str << std::endl;

    if (str.find("test") != std::string::npos) {
      std::cout << "Contains 'test': Yes" << std::endl;
    }
    else{
      std::cout << "Contains 'test': No" << std::endl;
    }

    size_t space_pos = str.find(' ');
    if (space_pos != std::string::npos){
      std::string first_word = str.substr(0, space_pos);
      std::cout << "First word: " << first_word << std::endl;
    }
  }
}
