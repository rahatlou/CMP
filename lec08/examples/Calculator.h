#ifndef Calculator_h
#define Calculator_h

#include <vector>
#include "Datum.h"

class Calculator {
 public:
  Calculator();

  static Datum weightedAverage(const std::vector<Datum>&);
  static Datum arithmeticAverage(const std::vector<Datum>&);
  static Datum geometricAverage(const std::vector<Datum>&);

};

#endif

