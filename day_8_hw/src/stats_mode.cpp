#include "../include/stats_mode.h"
#include <iostream>
#include <string>
#include <cctype>

namespace stats_mode {
  void run(int argc, char* argv[]) {
    if (argc < 3){
      std::cout << "Missing argument for stats mode." << std::endl;
      return;
    }
    std::string str = argv[2];
    size_t len = str.size();
    std::cout << "Length: " << len << std::endl;

    std::string unique_chars = "";
    for (char c : str){
      bool found = false;
      for (size_t i = 0; i < unique_chars.size(); ++i){
        if (unique_chars[i] == c){
          found = true;
          break;
        }
      }
      if (!found) {
        unique_chars += c;
      }
    }
    std::cout << "Unique: " << unique_chars.size() << std::endl;

    bool is_alnum = true;
    for (char c : str){
      if (!std::isalnum(c)) {
        is_alnum = false;
        break;
      }
    }
    std::cout << "Alphanumeric: " << (is_alnum ? "Yes" : "No") << std::endl;
    
    std::string reversed_str = "";
    for (size_t i = len; i > 0; --i) {
      reversed_str += str[i - 1];
    }
    std::cout << "Reversed: " << reversed_str << std::endl;

    std::string no_spaces = "";
    for (char c : str) {
      if (c != ' ') {
        no_spaces += c;
      }
    }
    std::cout << "Without spaces: " << no_spaces << std::endl;

    bool is_palindrome = true;
    size_t no_space_len = no_spaces.size();
    if(no_space_len == 0){
      is_palindrome = true;}
    else{
    for (size_t i = 0; i < no_space_len / 2; ++i) {
      if (std::tolower(no_spaces[i]) != std::tolower(no_spaces[no_space_len - 1 - i])) {
        is_palindrome = false;
        break;
      }
    }
    }
    std::cout << "Palindrome " << (is_palindrome ? "Yes" : "No") << std::endl;
  }
}
