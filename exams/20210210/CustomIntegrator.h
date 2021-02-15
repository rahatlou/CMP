#ifndef CustomINTEGRATOR_HH
#define CustomINTEGRATOR_HH

class Function;

class CustomIntegrator {

  public:
    CustomIntegrator() {
    }
    virtual double integrate(double xlo, double xhi, const Function* f) const = 0;

  private:

};
#endif
