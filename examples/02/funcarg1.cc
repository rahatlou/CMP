// funcarg1.cc
#include <iostream>

using namespace std;

void emptyLine() {
  cout << "\n----------------------------------\n"
       << endl;
}

void f1(double x) {
  cout << "f1: input value of x = "
       << x << endl;
  x = 1.234;
  cout << "f1: change value of x in f1(). x = " 
       << x << endl;
}

void f2(double& x) {
  cout << "f2: input value of x = " 
       << x << endl;
  x = 1.234;
  cout << "f2: change value of x in f2(). x = "
        << x << endl;
}


int main() {

   double a = 1.; // define a

   emptyLine();
   cout << "main: before calling f1, a = " << a<< endl;
   f1(a);  // void function
   cout << "main: after calling f1, a = " << a<< endl;

   emptyLine();
   cout << "main: before calling f2, a = " << a<< endl;
   f2(a);  // void function
   cout << "main: after calling f2, a = " << a<< endl;

   return 0;
}
