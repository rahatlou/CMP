// wgtavg.cc
#include <vector> 
#include <iostream> 
 
#include "Datum.h" // basic data object 
#include "InputService.h" // class dedicated to handle input of data
#include "Calculator.h" // impelments various algorithms 

using std::cout;
using std::endl;

int main() { 
 
 std::vector<Datum> dati = InputService::readDataFromUser();
  
  Datum r1 = Calculator::weightedAverage(dati);
  cout << "weighted average: " << r1 << endl;

  Datum r2 = Calculator::arithmeticAverage(dati); 

  Datum r3 = Calculator::geometricAverage(dati);

 
  return 0;
} 
