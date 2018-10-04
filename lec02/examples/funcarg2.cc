// funcarg2.cc
#include <iostream>

using namespace std;

void f2(const double& x) {
  cout << "f2: input value of x = " 
       << x << endl;
  x = 1.234;
  cout << "f2: change value of x in f2(). x = "
        << x << endl;
}

int main() {

   double a = 1.;
   f2(a);

   return 0;
}
