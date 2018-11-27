// example7.cpp
#include <iostream>
#include <string>
using namespace std;

#include "Vector.h"

int main() {
  Vector<string> vstr;
  vstr[0] = "test";
  vstr[1] = "foo";
  cout << vstr << endl;

  Vector<double,1000> v1;

  return 0;
}
