// app1.cpp
#include <string>
#include <iostream>

int index() {
  int i = 27;
}

std::string name() {
  std::string str("test of g++ options");
  return str;

  // text after return
  int j = 56;
  j++;
}

int main() {
  int i = index();
  std::string st = name();
  std::cout << "i:"  << i
            << "\t st: "  << st
            << std::endl;

  return 0;
}
