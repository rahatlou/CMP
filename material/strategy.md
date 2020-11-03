# Strategy Pattern

[Strategy pattern](https://en.wikipedia.org/wiki/Strategy_pattern) is a
commonly used design pattern to select algorithms at runtime.
For details take a look at the book [Design Patterns](https://en.wikipedia.org/wiki/Design_Patterns)
by Gamma et al. See also [https://www.bogotobogo.com/DesignPatterns/strategy.php](https://www.bogotobogo.com/DesignPatterns/strategy.php) for a nice introduction
with examples.

This is the UML diagram for the Strategy pattern

![Strategy Pattern](strategy_pattern.gif "Strategy Pattern")

Context is usually the client or the application, making use of the strategy.

In this lecture we apply this pattern to implement several integration algorithms
that can be used at runtime to integrate a function provided by the user.  

## Numerical Integrator
In **Laboratorio di Calcolo** and **Laboratorio Computazionale** you learned about
several numerical methods for integration of functions
  - midpoint or rectangles  rule
  - trapezoidal rule
  - Simpson
  - MC method


The [Integrator](../examples/11/Integrator.h) class defines the generic strategy
```c++
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
```
A pointer to a function is used to integrate the function provided by the user.
This has to be a standard single-values C function.

In the concrete strategy [MCIntegrator](../examples/11/MCIntegrator.h) we add new methods and data members specific to the concrete strategy with the MC method.
```c++
  class MCIntegrator : public Integrator {

    public:
      MCIntegrator(int n=1000);
      void setNPoints( int n ) {
          npoints_ = n;
      }
      virtual double integrate(double xlo, double xhi) const;

    private:
      int npoints_;
      double uniform(double a, double b) const;

  };
  ```
There are two contexts showing the use of the strategy to integrate the exponential ([app1](../examples/11/app1.cc) )and the sinus ([app2](../examples/11/app2.cc)) functions from the math library.
```c++
MCIntegrator mcalgo(100);
mcalgo.setIntegrand(exp);

double a,b;
cout << "Program computes integral of the exponential function between  a->b" << endl;
cout << "a: ";
cin >> a;
cout << "b: ";
cin >> b;

double analyticalIntegral = mcalgo.integrand(b) - mcalgo.integrand(a);
cout << "analytical integral: " << analyticalIntegral << endl;


for(int n= 10; n< 1e8; n *=10 ) {
    mcalgo.setNPoints(n);
    double sum = mcalgo.integrate( a, b ); // integral from a -> b
    cout << "# points: " << setw(10) << n
         << "\t Integral: " << setprecision(6) << sum
         << "\t residual: "
         << sum - analyticalIntegral
         << "\t fractional difference: " << setprecision(3) << 100*(sum - analyticalIntegral)/analyticalIntegral << " %"
         << endl;
}
```
Since the analytical integral of the exponential is trivial, comparison is provided between the numerical and analytical results.

To compile the applications:
```
g++ -o /tmp/app1 app1.cc MCIntegrator.cc
```
and
```
g++ -o /tmp/app2 app2.cc MCIntegrator.cc
```
### Exercise
 1. Write the missing classes to implement at least 2 other methods of Integration
 2. Study the difference between the estimated integrals between the methods
 3. make plots of the differences as a function of number of points or divisions with ROOT

## Numerical Integration with Custom functions
In the previous example we could only integrate single-values C functions.

We now want to modify our integration strategy to integrate our own Function objects using the classes studies in the previous lecture.

The main different is that instead of C-style pointer to function, the new [CustomIntegrator class](../examples/11/CustomIntegrator.h) uses `Function*` for its data member `integrand_`
```c++
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
```
Note how we are providing two accessors to use the `integrand_` function.

[Function](../examples/11/Function.h) is our  abstract class for all functions
```c++
class Function {
  public:
    Function(const std::string& name);
    virtual double value(double x) const = 0;
    virtual void print() const;
    virtual std::string name() const { return name_; }

  private:
    std::string name_;
};
```
And we have implemented one concrete function [Gauss](../examples/11/Gauss.h)
```c++
class Gauss : public Function {
  public:
    Gauss(const std::string& name, double mean, double width);

    virtual double value(double x) const;
    virtual void print() const;

  private:
    double mean_;
    double width_;
};
```
And here is an example of using out base class for functions and integrators ([app11](../examples/11/app11.cc))
```c++
CustomMCIntegrator cinteg = CustomMCIntegrator();
Function*  g1 = new Gauss("g1", 0., 1.);
cinteg.setIntegrand( g1 );

double a,b;
cout << "Program computes integral of the Gaussian function between  a x sigma -> b x sigma" << endl;
cout << "a: ";
cin >> a;
cout << "b: ";
cin >> b;

for(int n= 10; n< 1e8; n *=10 ) {
    cinteg.setNPoints(n);
    double sum = cinteg.integrate( a, b ); // integral from a -> b
    cout << "# points: " << setw(10) << n
         << "\t Integral: " << setprecision(6) << sum
         << endl;
}
```
You can link the executable and run it
```
$ g++ -o /tmp/app11 app11.cc CustomMCIntegrator.cc Gauss.cc Function.cc
$ /tmp/app11
Program computes integral of the Gaussian function between  a x sigma -> b x sigma
a: -1
b: 1
# points:         10	 Integral: 0.755633
# points:        100	 Integral: 0.684529
# points:       1000	 Integral: 0.682981
# points:      10000	 Integral: 0.682928
# points:     100000	 Integral: 0.683128
# points:    1000000	 Integral: 0.682514
# points:   10000000	 Integral: 0.682711
```
### Exercise
  1. add new methods to Gauss to modify its parameters after it has been created
  1. Add at least a new function class, e.g. Line and exponential
  2. add at least one more numerical integrators
  3. study the difference between algorithms for a given function and make plots of the differences with ROOT
