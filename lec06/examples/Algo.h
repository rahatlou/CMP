#ifndef Algo_h
#define Algo_h

class Algo {
 public:
   Algo() { params_ = 0; }
   Algo(const Algo& algo) { params_ = algo.params_; }


   double compute(const double& arg) const;

  private:
   int params_;
};
#endif
