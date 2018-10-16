#include "Datum.h"
#include <iostream>
using std::cout;
using std::endl;

int main() {

    Datum d1(-1.1,0.1);
    Datum d2(-1.0, 0.2);
    Datum d3(-1.11, 0.099);
    Datum d4(-1.10001, 0.09999999);

    cout << "d1: " << d1 << endl;
    cout << "d2: " << d2 << endl;
    cout << "d3: " << d3 << endl;
    cout << "d4: " << d4 << endl;
    

    for(double eps = 0.1; eps > 1e-8; eps /= 10) {
      Datum::setTolerance( eps );
      cout << "Datum tolerance  = " << eps << endl;
      
      if( d1 == d2 ) cout << "\t d1 same as d2" << endl;
      if( d1 == d3 ) cout << "\t d1 same as d3" << endl;
      if( d1 == d4 ) cout << "\t d1 same as d4" << endl;
    }
    return 0;
}
