// vect3.cc
#include <iostream>
using namespace std;

int main() {


   float vect[3] = {0.4,1.34,56.156}; // vector of int
   float v2[3]; // use default value 0 for each element
   float v3[] = { 0.9, -0.1, -0.65}; // array of size 7

   for(int i = 0; i<3; ++i) {
     cout << "i: " << i << "\t"
          << "vect[" << i << "]: " << vect[i] << "    \t"
          << "v2[" << i << "]: " << v2[i] << " \t"
          << "v3[" << i << "]: " << v3[i]
           << endl;
   }

   return 0;
}
