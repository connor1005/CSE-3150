#include <iostream>
#include "../include/while_count_utils.h"
using std::cout, std::cin, std::endl;

namespace while_count_utils{
  void runWhileCount(){
    int num;
    cout << "Enter a number to count to: ";
    cin >> num;
    while (num > 10){
      cout << "I'm programmed to only count up to 10!" << endl;
      cout << "Enter a number to count to: ";
      cin >> num;
    }
    for (int i = 0; i <= num; i++){
      if (i != 5){
        cout << i << endl;}
    }
  }
}
