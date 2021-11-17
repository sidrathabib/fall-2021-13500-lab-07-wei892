/*
Name: Wei Lin Li
Course: CSCI-135
Instructor: Tong Yi and Mike Zamansky
Assignment: Lab 7

this is the indent function, it will return 
-1 if its a }
or a 1 if its a {
*/

#include <iostream>
#include <cctype>
#include "indent.h"

int countChar(std::string line, char c) {
  int len = line.length();
  for (int i = 0; i < len; i++){
    char c = line[i];
    if (c == '{') {
	return 1;
      }
    else if (c == '}') {
	return -1;
      }
  }
  return 0;
}
