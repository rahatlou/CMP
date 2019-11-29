#include "MCIntegrator.h"
#include <stdlib.h>
#include <time.h>

MCIntegrator::MCIntegrator(int n) : Integrator() {
    npoints_  = n;
    srand48(time(0));
}


double MCIntegrator::uniform(double a, double b) const{
    return a + (b-a)*lrand48()/RAND_MAX;
}

double MCIntegrator::integrate(double xlo, double xhi) const {
    double sum = 0.;
    for(int i=0; i< npoints_; i++) {
      sum += integrand( uniform(xlo,xhi) );
    }
    sum *= (xhi-xlo)/npoints_;
    return sum;
}
