#ifndef CustomINTEGRATOR_HH
#define CustomINTEGRATOR_HH

#include "Function.h"

class CustomIntegrator {

  public:
    CustomIntegrator() {
      integrand_ = 0;
    }
    void setIntegrand( Function* f ) {
        integrand_ = f;
    }
    double integrand(double x) const {
        return integrand_->value(x);
    }

    Function* integrand() const {
        return integrand_;
    }
    virtual double integrate(double xlo, double xhi) const = 0;

  private:
    Function* integrand_;

};
#endif
