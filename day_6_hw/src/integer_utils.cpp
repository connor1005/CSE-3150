#include <iostream>

#include "../include/integer_utils.h"

using std::cout, std::endl, std::cin;
namespace integer_utils{
  void runIntegerOption(){
    int x;
    int y;
    cout << "Enter first integer: ";
    cin >> x;
    cout << "Enter second integer: ";
    cin >> y;

    if (y == 0){
      cout << "Error: division by zero" << endl;
      return;}

    int quotient = x/y;
    cout << "Result: " << quotient << endl;

    //comment
    cout << "After post-increment: " << x++ << endl;
    cout << "After pre-increment: " << ++x << endl;

  }
}
