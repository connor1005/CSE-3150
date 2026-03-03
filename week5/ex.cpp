#include <iostream>
#include <string>

using std::string, std::cout, std::cin, std::endl;

int main(int argc, char* argv[]){
  if (argc < 3){
    return 1;}
  int a = std::stoi(argv[1]);
  int b = std::stoi(argv[2]);
  cout << a + b << endl;
  return 0;
}
