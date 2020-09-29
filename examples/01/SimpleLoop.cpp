// SimpleLoop.cpp
#include <iostream>
using namespace std;

int main() { // main begins here

   int nIterations;

   cout << "How many iterations? ";

   cin >> nIterations;

   int step = 1;
   cout << "step of iteration? " ;
   cin >> step;


   for(int index=0; index < nIterations; index+=step) { 
     cout << "index: " << index << endl;
   }
   return 0;

} // end of main
