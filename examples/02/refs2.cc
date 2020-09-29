// refs2.cpp
#include <iostream>
using namespace std;

int main() {

   int a = 1;

   int* b = &a;
   *b = 3;

   cout << "value of a: " << a
        << ", address of a, &a: " << &a
        << endl;

   int& x = a;
   x = 45;

   cout << "value of a: " << a
        << ", address of a, &a: " << &a
        << endl;

   return 0;
}
