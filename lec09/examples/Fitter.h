#ifndef Fitter_h_
#define Fitter_h_
// Fitter.h
namespace analysis {

  class Fitter {
    public:
      enum Status { Succesful=0, 
                    Failed,
                    Problems };

      Fitter() { };

      Status fit() {
        return Succesful;
      }
    private:
  }; // class Fitter
} //namespace
#endif
