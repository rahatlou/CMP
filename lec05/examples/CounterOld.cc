// CounterOld.cc
#include "CounterOld.h"
#include <iostream>
using std::cout;
using std::endl;

Counter::Counter() {
  count_ = 0;
};

int Counter::value()  {
  return count_;
}

void Counter::reset() {
  count_ = 0;
}

void Counter::increment(int step) {
  count_ = count_+step;
}
