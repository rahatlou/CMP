#ifndef CounterNS_h_
#define CounterNS_h_
#include <string>

namespace rome {
  namespace didattica {

    class Counter {
      public:
        Counter(const std::string& name);
        ~Counter();
        int value();
        void reset();
        void increment(int step=1);
        void print();

      private:
        int count_;
        std::string name_;
    }; // class counter

  } // namespace didattica
} //namespace rome
#endif
