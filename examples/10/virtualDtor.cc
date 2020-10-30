// virtualDtor.cc
#include <iostream>

using std::cout;
using std::endl;

class Base {
  public:
  Base(double x) {
    x_ = new double(x);
    cout << "Base(" << x << ") called" << endl;
  }
  virtual ~Base() {
    cout << "~Base() called" << endl;
    delete x_;
  }
  private:
   double* x_;
};

class Derived : public Base {
  public:
  Derived(double x) : Base(x){
    cout << "Derived("<<x<<") called" << endl;
  }
  virtual ~Derived() {
    cout << "~Derived() called" << endl;
  }
};

int main() {
  Base* a = new Derived(1.2);
  delete a;
  return 0;
}
