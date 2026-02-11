#include <iostream>
#include "../include/string_utils.h"
using std::cin, std::cout, std::endl,std::string;

namespace string_utils {
  /*
   * In this function, we read an integer that is the length of the string. If it is over 20, error
   *
   * Then, read the string. After reading, copy the characters into a character array.
   *
   * Insert a null character after.
   */
  int runStringOption(){
    int len;
    cout << "Enter string length: ";
    cin >> len;
    if (len >= 20){
      cout << "Error: String must be less than 20" << endl;
      return 1;}
    std::cin.ignore();
    cout << "Enter string: ";
    string input;
    char array[20];
    std::getline(cin, input);
    for(int i = 0; i < len; i++){
      array[i] = input[i];
    }
    array[len] = '\0';
  
    cout << "C-style string: " << array << endl;
  return 0;
  }

}
