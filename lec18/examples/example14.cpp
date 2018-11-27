// example14.cpp
#include <iostream>
#include <stdexcept>
using std::cin;
using std::cout;
using std::endl;
using std::runtime_error;

class MyError : public std::runtime_error {
  public:
    MyError() : std::runtime_error("division by zero") {}
};

double ratio(int i1, int i2) {
  if(i2 == 0) throw MyError();
  return i1/i2;
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

    } catch(MyError& ex) {
       cout << "error occurred..." << ex.what() << endl;
    }
  } while (true);

  return 0;
}
