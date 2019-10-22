#include <iostream>
#include <vector>
#include "Datum.h"

int main() {


  std::vector<double> vals;
  vals.push_back(1.3);
  vals.push_back(-2.1);

  std::vector<double> errs;
  errs.push_back(0.2);
  errs.push_back(0.3);

  std::vector<Datum> data;
  data.push_back( Datum(1.3, 0.2) );
  data.push_back( Datum(-2.1, 0.3) );

 std:cout << "# dati:: " << data.size() << std::endl;

  // using traditional loop on an array
  int i=0;
  std::cout << "Using [] operator on vector" << std::endl;
  for(i=0; i< data.size(); ++i) {
    std::cout << "i: " << i
	      << "\t data: " << data[i].value() << " +/- " << data[i].error()
	      << std::endl;
  }

  // using vector iterator  
  i=0;
  std::cout << "std::vector<T>::iterator " << std::endl;
  for(std::vector<Datum>::iterator d = data.begin(); d != data.end(); d++) {
    //std::cout << "d: " << d << std::endl;
    i++;
    std::cout << "i: " << i
	      << "\t data: " << d->value() << " +/- " << d->error()
	      << std::endl;
  } 

    // using vector iterator  
  i=0;
  std::cout << "C+11 extension feature " << std::endl;
  for(Datum dit : data) {
    i++;
    std::cout << "i: " << i
	      << "\t data: " << dit.value() << " +/- " << dit.error()
	      << std::endl;
  }

  return 0;

}
