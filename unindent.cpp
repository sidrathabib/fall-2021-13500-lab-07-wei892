/*
Name: Wei Lin Li
Course: CSCI-135
Instructor: Tong Yi and Mike Zamansky
Assignment: Lab 7 

this is the unident function, it'll call the removeLeadingSpaces
in a while loop until it finishes reading everything

*/

#include <iostream>

#include "unindent.h"

//removing indentation
std::string removeLeadingSpaces(std::string line)
{
  int len = line.length();
  std::string output;

  int i = 0;
  if (isspace(line[i]))
    {
      do //(isspace(line[i]));
      {
	i++;
      }while (isspace(line[i]));

    }
  
  output = line.substr(i);

  return output;
}
