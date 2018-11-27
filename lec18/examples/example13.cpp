// example3.cpp

#include <iostream>
#include <stdexcept>
using std::cin;
using std::cout;
using std::endl;
using std::runtime_error;

double ratio(int i1, int i2) {
  if(i2 == 0) throw std::runtime_error("error in ratio");
  return (double) i1/i2;
}


int main() {
  int i1 = 0;
  int i2 = 0;

  cout << "Compute ratio a/b of 2 integers (ctrl-C to end)" << endl;

  do{
    cout << "a? ";
    cin >> i1;
    cout << "b? ";
    cin >> i2;

    try {
      cout << "a/b =  " << ratio(i1,i2) << endl;

    } catch(std::runtime_error& ex) {
       cout << ex.what() << ": denominator is 0"  << endl;
    }
  } while (true);
  return 0;
}
