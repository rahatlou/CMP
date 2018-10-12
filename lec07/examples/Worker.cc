#include "Worker.h"

#include <iostream>
using namespace std;


Worker::Worker() {
  alg_ = new Algo();
  cout << "Worker() alg_: " << alg_ << endl;
}

Worker::Worker(const Worker& worker) {
  alg_ = worker.alg_;
  cout << "Worker(const Worker& worker) alg_: " << endl;
}


Worker::Worker(Algo* algo) {
  alg_ = algo;
  cout << "Woorker(Algo* algo) alg_: " << endl;
}

Worker::Worker(const Algo& algo) {
  alg_ = new Algo(algo);
  cout << "Worker(const Algo& algo) changed alg_: " << endl;
}

Worker::~Worker() {
  cout << "~Worker() deleting alg_: " << alg_ << endl;
  delete alg_;
}


void Worker::setAlgo(Algo* algo) {
      cout << "Worker::setAlgo changed alg_ from "<< alg_
           << " to " << algo << endl;
      alg_ = algo;
}
