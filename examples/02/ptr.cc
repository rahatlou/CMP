// ptr.cc
#include <iostream>
using namespace std;

int main() {

   int v3[] = { 1, 2, 3, 4, 5, 6, 7 }; // array of size 7

   int* d = v3;

   cout << "d = " << d << ", *d: " << *d <<endl;

   d++;
   cout << "d = " << d << ", *d: " << *d <<endl;

   d = d+3;
   cout << "d = " << d << ", *d: " << *d <<endl;

   d = d+4;
   cout << "d = " << d << ", *d: " << *d <<endl;

   return 0;
}
