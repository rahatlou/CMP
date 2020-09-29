// SimpleVars.cpp
#include <iostream>
using namespace std;

int main() {

   int samples; // declaration only

   int events = 0; // declaration and assignment

   samples = 123; // assignment


   cout << "How many samples? " ;
   cin >> samples; // assigment via I/O


    cout << "samples: " << samples
         << "\t"  // insert a tab in the printout
         <<  "events: " << events
         << endl;

   return 0;

} // end of main
