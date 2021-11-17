/*
Name: Wei Lin Li
Course: CSCI-135
Instructor: Tong Yi and Mike Zamansky
Assignment: Lab 7

main file, runs indent and unindent function

*/

#include <iostream>
#include <fstream>
#include <cctype>
#include "unindent.h"
#include "indent.h"

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

  if(in.fail()) {
    std::cerr << "File cannot be opened";
    exit(1);
  }

  std::ofstream out;
  out.open("removed-indentation.cpp");
  while (getline(in, line)) {
      out << removeLeadingSpaces(line);
      out << "\n";
    }
  in.close();
  out.close();

  in.open("removed-indentation.cpp");
  if (in.fail()) {
      std::cerr << "File cannot be opened";
      exit(1);
    }
  
  while (getline(in, line)) {
    std::cout << line << std::endl;
  }
  in.close();

  std::cout << "\n=======================\n";

  std::cout << "Returning tabs to badly indented code: \n" << std::endl;
  in.open("bad-code.cpp");
  if (in.fail()) {
      std::cerr << "File cannot be opened";
      exit(1);
    }
  out.open("correct-indentation.cpp");
  std::string result;
  int tab = 0;
  while (getline(in, line)) {
      if (countChar(line, '}') == -1) {
	  tab--;
	}
      
      for (int i = 0; i<tab; i++)
	{
	  out << "\t";
	}
      
      out << removeLeadingSpaces(line);
      out << "\n";

      if (countChar(line, '{') == 1)
	{
	  tab++;
	}
    }
  in.close();
  out.close();

  in.open("correct-indentation.cpp");
  if (in.fail())
    {
      std::cerr << "File cannot be opened";
      exit(1);
    }

  while (getline(in, line))
    {
      std::cout << line << std::endl;
    }

  return 0;
}
