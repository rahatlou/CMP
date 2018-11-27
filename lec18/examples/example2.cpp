// example2.cpp
#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

template< class  DataType >
void printArray(const DataType* data, int nMax) {
  cout << "printObject(const T& input): with DataType = " << typeid( DataType ).name() << endl;
  for(int i=0; i<nMax; ++i) {
    cout << data[i] << "\t";
  }
  cout << endl;
}

int main() {

  int i[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

  const int n1 = 3;
  double x[n1] = { -0.1, 2.2, 12.21};
  
  string days[] = { "Mon", "Tue", "Wed", "Thur", "Fri", "Sat", "Sun"};

  printArray( i, 10 );
  printArray( x, n1 );
  printArray( days, 7 );

  return 0;
}
