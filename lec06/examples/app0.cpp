// app0.cpp
// testing Worker class

#include <iostream>
using std::cout;
using std::endl;

#include "Worker.h"
#include "Algo.h"


int main() {

  Worker work1;

  // dynmic allocation 
  Algo* alg1 = new Algo();

  work1.setAlgo( alg1 );

  work1.setAlgo( new Algo() );

  delete alg1;

  return 0;
}

