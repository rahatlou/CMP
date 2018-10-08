#ifndef Counter_Old_h_
#define Counter_Old_h_
// CounterOld.h

class Counter {
  public:
    Counter();
    int value();
    void reset();
    void increment(int step = 1);

  private:
    int count_;
};
#endif
