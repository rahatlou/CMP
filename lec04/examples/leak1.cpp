// app6.cpp
#include <iostream>
using namespace std;

int main() {

  for(int i=0; i<10000; ++i){

    double* ptr = new double[100000];
    ptr[0] = 1.1;

    cout << "i: " << i
         << ", ptr: " << ptr
         << ", ptr[0]: " << ptr[0]
         << endl;

    // delete[] ptr; // ops! memory leak!
  }
  return 0;
}
