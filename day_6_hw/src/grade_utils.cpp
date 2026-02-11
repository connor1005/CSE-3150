#include <iostream>
#include "../include/grade_utils.h"
using std::cin, std::cout, std::endl, std::string;

namespace grade_utils {
  double calculateGrade(){
    char stu_type;
    int num_grade;
    cout << "Enter student type (U for undergrad, G for grad): ";
    cin >> stu_type;
    cout << "Enter numeric grade: ";
    cin >> num_grade;
    if (num_grade > 100 || num_grade < 0){
      cout << "Invalid grade" << endl;
      return -1.0;}

    cout << "Status: ";
    if (stu_type == 'U' || stu_type == 'u'){
      if (num_grade >= 60){
        cout << "Pass" << endl;}
      else{
      cout << "Fail" << endl;
    }}

    else if (stu_type == 'G' || stu_type == 'g'){
      if (num_grade >= 70){
        cout << "Pass" << endl;}
      else{
      cout << "Fail" << endl;}
    }
    return num_grade;
  }
}
