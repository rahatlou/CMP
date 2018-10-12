// this.cpp
#include <iostream>
#include <string>
using namespace std;

class Example {
  public:
   Example() { name_ = ""; }
   Example(const string& name);
   void printSelf() const;
  private:
   string name_;
};

Example::Example(const string& name) {
  name_ = name;
}


void
Example::printSelf() const {
  cout << "name: " << name_ 
       << "\t this: " << this
       << endl;
}


int main() {
  Example ex1("ex1");
  ex1.printSelf();

  cout << "&ex1: " << &ex1 << endl;

  return 0;
}
