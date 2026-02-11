#include <iostream>

int add(int a, int b){
  return a + b;
}

double add(double a, double b){
  return a + b;
}

int main(){
  std::cout << add(1,2) << std::endl;
  std::cout << add(1.5, 2.25) << std::endl;
}

