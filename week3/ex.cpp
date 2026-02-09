#include <iostream>
#include <string>

int main(){
  int x = 5;
  if (x ==5){
    std::cout << '5' << std::endl;
  }
  else if (x != 3){
    std::cout <<  "x isn't 3" << std::endl;
  }else{
    std::cout << "None of the above" << std::endl;
  }
  return 0;
}
