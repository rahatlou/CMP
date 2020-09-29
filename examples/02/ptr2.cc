// ptr2.cc
#include <iostream>
using namespace std;

int main() {

   int v3[] = { 1, 2, 3, 4, 5, 6, 7 }; // array of size 7

   int* d = v3;

   int*c = &v3[4];

   cout << "d = " << d << ", *d: " << *d <<endl;

   cout << "c = " << c << ", *c: " << *c <<endl;

   //int* e = c + d;  // not allowed

   cout << "c-d: " << c - d << endl;
   cout << "d-c: " << d - c << endl;

   //int* e = c-d;

   int f = c - d;

   float g = c - d;


   cout << "f: " << f << " g: " << g << endl;


   int *  h = &v3[6] + (d-c);


    cout << "int *  h = &v3[6] + (d-c): " << h << " *h: " << *h << endl;

   return 0;
}
