// ctor.cc
#include <iostream>
using std::cout;
using std::endl;

class Datum {
  public:
    Datum(double x) { x_ = x; }
    double value()  { return x_; }
    void setValue(double x) { x_ = x; }
    void print() {
      cout << "x: " << x_ << endl;
    }

  private:
    double x_;
};

int main() {

  Datum d1(1.2);
  d1.print();

  //Datum d2;  // no default ctor. compiler error if uncommented
  //d2.print();

  Datum d3 = d1; // default assigment by compiler
  d3.print();

  cout << "&d1: " << &d1 << "\t &d3: " << &d3 << endl;

  return 0;

}
