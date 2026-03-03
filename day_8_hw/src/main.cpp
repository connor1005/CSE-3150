#include <iostream>
#include <string>
#include "text_mode.h"
#include "add_mode.h"
#include "stats_mode.h"

int main(int argc, char* argv[]) {
  if (argc < 2) {
    std::cout << "Usage: ./analyzer <mode> [arguments]" << std::endl;
    return 1;
  }

  std::string mode_str = argv[1];
  int mode_int = 0;

  if (mode_str == "text") {
    mode_int = 1;}
  else if (mode_str == "add") {
    mode_int = 2;}
  else if (mode_str == "stats") {
    mode_int = 3;}

  switch (mode_int) {
    case 1:
      text_mode::run(argc, argv);
      break;
    case 2:
      add_mode::run(argc, argv);
      break;
    case 3:
      stats_mode::run(argc, argv);
      break;
    default:
      std::cout << "Invalid mode" << std::endl;
      return 1;
  }
  return 0;
}
