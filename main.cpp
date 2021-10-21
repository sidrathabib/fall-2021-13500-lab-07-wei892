/*
Name: Wei Lin Li
Course: CSCI-135
Instructor: Tong Yi and Mike Zamansky
Assignment: Lab 7

main file, runs and tests removingLeadingSpaces function

*/

#include <iostream>
#include <fstream>
#include "unindent.h"

int main()
{
  std::cout << "testing removeLeadingSpaces with a sentence:\n" << std::endl;
  std::string x = "       int x = 1;  ";
  x = removeLeadingSpaces(x);
  std::cout << x  << std::endl;

  std::cout << "\n=======================\n";
  
  std::cout << "\ntesting removeLeadingSpaces with bad-code file\n" << std::endl;
  std::string line;
  std::string output = ""; //delete later
  std::ifstream in;

  in.open("bad-code.cpp");

  if(in.fail())
  {
    std::cerr << "File cannot be opened";
    exit(1);
  }

  std::ofstream out;
  out.open("removed-indentation.cpp");
  while (getline(in, line))
    {
      //std::cout << line <<std::endl;
      out << removeLeadingSpaces(line);
      out << "\n";
    }
  in.close();
  out.close();

  //std::ifstream in;
  in.open("removed-indentation.cpp");
  if (in.fail())
    {
      std::cerr << "File cannot be opened";
      exit(1);
    }
  
  while (getline(in, line))
  {
    //std::cout << "running fixed indentation" << std::endl;
    std::cout << line << std::endl;
  }
  in.close();

  std::cout << "\n==========================================\n";
  //std::cout << output;

  return 0;
}
