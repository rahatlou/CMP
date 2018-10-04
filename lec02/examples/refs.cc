// refs.cpp
#include <iostream>
using namespace std;

int main() {

   int a = 1;

   int* b; // b is  a pointer to varible of type int

   b  = &a; // value of b is the adress of memory location assigned to a

   int& x = a;


   cout << "value of a: " << a
        << ", address of a, &a: " << &a
        << endl;

   cout << "value of x: " << x
        << ", address of x, &x: " << &x
        << endl;

   cout << "value of b: " << b
        << ", address of b, &b: " << &b
        << ", value of *b: " << *b
        << endl;


   return 0;
} // end of main
