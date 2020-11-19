#ifndef INTEGRATOR_HH
#define INTEGRATOR_HH

class Integrator {

  public:
    Integrator() {
      integrand_ = 0;
    }
    void setIntegrand( double(*f)(double) ) {
        integrand_ = f;
    }
    double integrand(double x) const {
        return integrand_(x);
    }
    virtual double integrate(double xlo, double xhi) const = 0;

  private:
    double (*integrand_)(double);

};
#endif
