// app1.cpp
#include "Counter.h"
#include <string>

int main() {

  Counter c1( std::string("c1") );
  Counter c2( std::string("c2") );
  Counter c3( std::string("c3") );

  c2.increment(135);
  c1.increment(5677);

  c1.print();
  c2.print();
  c3.print();

  return 0;
}
