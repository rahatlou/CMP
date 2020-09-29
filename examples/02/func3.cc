// func3.cc
#include <iostream>

double pi() {
  return 3.14;
}

extern void print(); // declare to compiler print() is a void method


int main() {

   std::cout << "pi: " << pi() << std::endl;
   print();

   return 0;
}

// now implement/define the method void print()
void print() {
  std::cout << "void function print()" << std::endl;
}

