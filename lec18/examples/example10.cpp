// example0.cpp
#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

#include "Dummy.h"

int main() {


  Dummy<std::string>* d1 = 0;
  Dummy<double>* d2 = 0;

  int value = 0;
  while(value<1 || value>10) {
    cout << "Give me a number [1,10]: ";
    cin >> value;
  }

  cout << flush;

  if(value>5) d1 = new Dummy<std::string>( "string" );
  else        d2 = new Dummy<double>( 1.1 );

  if( d1 != 0 ) d1->print();
  if( d2 != 0 ) d2->print();

  return 0;
}
