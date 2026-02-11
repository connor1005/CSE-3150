#include <iostream>
#include "../include/do_while_count_utils.h"
using std::cout, std::endl, std::cin;


namespace do_while_count_utils{
  void runDoWhileCount(){
    int num;
    do {
      cout << "Enter a number between 1 and 5: ";
      cin >> num;
    } while (num < 1 || num > 5);

    int numbers[] = {1, 2, 3, 4, 5};

    for (int value : numbers){
      cout << "Value: " << value << endl;
      
      if (value == num){
        break;}
    }
  }
}
