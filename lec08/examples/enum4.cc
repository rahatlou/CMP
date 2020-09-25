//enum4.cc
#include "Fitter.h"
#include <iostream>
using namespace std;

int main() {

  analysis::Fitter myFitter;

  analysis::Fitter::Status stat = 
                            myFitter.fit();

  if( stat == analysis::Fitter::Succesful ) {
    cout << "fit succesful!" << endl;
  } else {
    cout << "Fit had problems ... status = "
         << stat << endl;
  }

  return 0;
}
