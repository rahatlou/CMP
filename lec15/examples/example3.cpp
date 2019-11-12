// example3.cpp
#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

template< typename  T >
void printObject(const T& input) {
  cout << "printObject(const T& input): with T = " << typeid( T ).name() << endl;
  cout << input << endl;
}

class Dummy {
  public:
    Dummy(const string& name="") {
      name_ = name;
    }
  private:
    string name_;
};

int main() {

  string name("jane");
  Dummy  bad("bad");

  printObject( name );
  printObject( bad );

  return 0;
}
