#include <iostream>
#include "../include/do_while_count_utils.h"
#include "../include/grade_utils.h"
#include "../include/integer_utils.h"
#include "../include/string_utils.h"
#include "../include/while_count_utils.h"
using std::cout, std::endl, std::cin;



int main(){
  int userNum;
  do{
    cout << " 1. Integer operations \n 2. Character arrays and C-style strings \n 3. Grade evaluation\n 4. While-loop counting \n 5. Do-while and range-based for counting \n 6. Quit" << endl;
  
  cin >> userNum;
  
  switch(userNum){
    case 1:
      integer_utils::runIntegerOption();
      break;
    case 2:
      if (string_utils::runStringOption() != 0){
        return 1;}
      break;
    case 3:
      if (grade_utils::calculateGrade() == -1.0){
        return 1;}
      break;
    case 4:
      while_count_utils::runWhileCount();
      break;
    case 5:
      do_while_count_utils::runDoWhileCount();
      break;
    case 6:
      break;
    default:
      cout << "Please select a valid option :(\n";
      break;
  }
  }
  while(userNum != 6);
  






  cout << "Goodbye!" << endl;
return 0;
}
