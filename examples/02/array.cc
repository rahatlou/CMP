// array.cc
#include <iostream>
using namespace std;

int main() {


   int vect[3] = {1,2,3}; // vector of int
   int v2[3]; // no default value!!
   int v3[] = { 1, 2, 3, 4, 5, 6, 7 }; // array of size 7

   int* c = vect; // non-initialized pointer
   int* d = v3;
   int* e = v2;

   for(int i = 0; i<5; ++i) {
     cout << "i: " << i << ", d = " << d << ", *d: " << *d;
     ++d;
     cout << ", c = " << c << ", *c: " << *c;
     ++c;
     cout << ", e = " << e << ", *e: " << *e << endl;
     ++e;
   }

   return 0;
}
