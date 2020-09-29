// Pointers.cpp
#include <iostream>
using namespace std;

int main() { // main begins here

   int a; // a is a lable for a location of memory dtoring an int value

   cout << "Insert value of a: ";
   cin >> a; // store value provided by user in location of memory held by a

   int* b; // b is  a pointer to varible of type a

   b  = &a; // value of b is the adress of memory location assigned to a

   cout << "value of a: " << a << endl;
   cout << "address of a: " << b << endl;

   return 0;
} // end of main
