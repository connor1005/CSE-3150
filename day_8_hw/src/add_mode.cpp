#include "../include/add_mode.h"
#include <iostream>
#include <string>
#include <cctype>

namespace add_mode {
  int add(int a, int b){
    return a + b;
  }
  double add(double a, double b){
    return a + b;
  }
  std::string add(std::string a, std::string b){
    return a + b;
  }

  bool is_all_digits(const std::string& str){
    if (str.empty()) return false;
    for (char c : str){
      if (!std::isdigit(c)) return false;
    }
    return true;
  }

  void run(int argc, char* argv[]) {
    if (argc < 4){
      std::cout << "Missing arguments for add mode." << std::endl;
      return;
    }
    std::string arg1 = argv[2];
    std::string arg2 = argv[3];

    if (arg1.find('.') != std::string::npos || arg2.find('.') != std::string::npos) {
            double val1 = std::stod(arg1);
            double val2 = std::stod(arg2);
            std::cout << "Result: " << std::to_string(add(val1, val2)) << std::endl;
        }
    else if (is_all_digits(arg1) && is_all_digits(arg2)) {
      int val1 = std::stoi(arg1);
      int val2 = std::stoi(arg2);
      std::cout << "Result: " << std::to_string(add(val1, val2)) << std::endl;
    }
    else{
      std::cout << "Result: " << add(arg1, arg2) << std::endl;
    }
  }
}
