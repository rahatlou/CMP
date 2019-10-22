// app2.cpp
#include "Counter.h"
#include <string>

int main() {

  Counter c1( std::string("c1") );

  int count = 344;

  if( 1.1 <= 2.02 ) {
    Counter c2( std::string("c2") );

    Counter c3( std::string("c3") );
    if( count == 344 ) {
      Counter c4( std::string("c4") );
    }
    Counter c5( std::string("c5") );
    for(int i=0; i<3; ++i) {
      Counter c6( std::string("c6") );
    }
  }

  return 0;
}
