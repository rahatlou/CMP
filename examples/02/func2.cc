// func2.cc
#include <iostream>

double pi() {
  return 3.14;
}

int main() {

   std::cout << "pi: " << pi() << std::endl;
   print();

   return 0;
}

void print() {
  std::cout << "void function print()" << std::endl;
}

