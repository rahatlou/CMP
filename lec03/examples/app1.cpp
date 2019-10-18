// app1.cpp
#include "Datum1.cc"

int main() {

  Datum d1;
  d1.print();

  Datum d2(0.23,0.212);
  d2.print();

  Datum d3( d2 );
  d3.print();

  return 0;
}
