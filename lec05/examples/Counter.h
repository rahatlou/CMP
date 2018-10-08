#ifndef Counter_h_
#define Counter_h_
#include <string>

class Counter {
  public:
    Counter(const std::string& name);
    ~Counter();
    int value();
    void reset();
    void increment();
    void increment(int step);
    void print();

  private:
    int count_;
    std::string name_;
};
#endif
