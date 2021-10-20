/*
Name: Wei Lin Li
Course: CSCI-135
Instructor: Tong Yi and Mike Zamansky
Assignment: Lab 7

main file, runs and tests removingLeadingSpaces function

*/

#include <iostream>
#include "funcs.h"

int main()
{

  std::string x = "       int x = 1;  ";
  x = removeLeadingSpaces(x);
  std::cout << x  << std::endl;


  return 0;
}
