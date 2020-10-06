// app2.cpp
#include <iostream>
using std::cout;  // use using only for specific classes
using std::endl;  // not for entire namespace

class Counter {
  public:
    Counter() { count_ = 0; x_=0.0; };
    int value()  { return count_; }
    void reset() { count_ = 0; x_=0.0; }
    void increment() { count_++; }
    void increment(int step) { count_ = count_+step; }
    void print() {
      cout << "---- Counter::print() : begin ----" << endl;
      cout << "my count_: " << count_ << endl;
      cout << "my address: " << this << endl; // this is special pointer
      cout << "&x_ : " << &x_ << "  sizeof(x_): " << sizeof(x_) << endl;
      cout << "&count_ : " << &count_ << "  sizeof(count_): " << sizeof(count_) << endl;
      cout << "---- Counter::print() : end ----" << endl;
    }

  private:
    int count_;
    double x_; // dummy variable
};

// print counter info by reference
void printCounter(Counter& counter)  {
  cout << "printCounter: counter value: " << counter.value() << endl;
}

// print counter info of pointer to counter
void printByPtr(Counter* counter)  {
  cout << "printByPtr: counter value: " << counter->value() << endl;
}

int main() {
  Counter counter;
  counter.increment(7);

  // ptr is a pointer to a Counter Object
  Counter* ptr = &counter;
  cout << "ptr = &counter: " << &counter << endl;

  // use . to access member of objects
  cout << "counter.value(): " << counter.value() << endl;

  // use -> with pointer to objects
  cout << "ptr->value(): " << ptr->value() << endl;

  printCounter( counter );
  printByPtr( ptr );

  ptr->print();

  cout << "sizeof(ptr): " << sizeof(ptr) << "\t"
       << "sizeof(counter): " << sizeof(counter)
       << endl;

  return 0;
}
