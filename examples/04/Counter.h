// Counter.h
// Counter Class: simple counter class. Allows simple or step
// increments and also a reset function

// include header files for types and classes
// used in the declaration

class Counter {
  public:
    Counter();
    int value();
    void reset();
    void increment();
    void increment(int step);

  private:
    int count_;
};
