#ifndef Worker_h
#define Worker_h

#include "Algo.h"


class Worker {
  public:
    Worker();
    Worker(const Worker& worker);
    Worker(Algo* algo);
    //Worker(Algo& algo);
    Worker(const Algo& algo);

    ~Worker();

    void setAlgo(Algo* algo);

  private:
    Algo* alg_;
};
#endif
