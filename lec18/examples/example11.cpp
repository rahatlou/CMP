// example1.cpp
#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

#include "NewDummy.h"

int main() {
  NewDummy<std::string> d1( "d1" );
  NewDummy<std::string> d2( "d2" );
  NewDummy<std::string> d3( "d3" );

  NewDummy<double> f1( 0.1 );
  NewDummy<double> f2( -56.45 );

  cout << "NewDummy<std::string>::total(): " << NewDummy<std::string>::total() << endl;
  cout << "NewDummy<double>::total(): " << NewDummy<double>::total() << endl;

  cout << "NewDummy<int>::total(): " << NewDummy<int>::total() << endl;

  return 0;
}
