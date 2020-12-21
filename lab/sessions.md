# Laboratory sessions

## Session 1 (19/10/2020)
In this first session we design and implement a new class `Complex` to implement
mathematical operations between `Complex` and regular `double` objects.
- Choose the proper data members for the class
- Implement the constructors
- Implement `re()`, `im()`, `mag()`, `phase()`, `r()`, `phi()` member functions
- overload operators `+,-,*,/` between `Complex` objects
```c++
Complex a(-1,2), b(0.5, 0.9);
Complex c = a/b;
```
- overload operators for operations with a `double` on the rhs
```c++
Complex   i(0,1);
Complex d = i*3 + a + b/2.3 + 1.2;
```
- write global functions (or overload operators) for operations with a `double` on the lhs
```c++
Complex z = 3*i + 2/d;
```

## Session 2 (26/10/2020)
We design and implement a new class `Vector3D` to implement
mathematical operations with 3D vectors
- Choose the proper data members for the class
- Implement the constructors, including a copy constructor
- Take into account different coordinate systems: cartesian, polar, cylindrical
- Implement `r()`, `phi()`, `theta()`, `x()`, `y()`, `z()`  member functions
- overload operators `+,-,*,/` between `Vector3D` objects
```c++
const Vector3D a(-1,2,1), b(0.5, -0.5, 1.5);
Vector3D c = a + b;
```
- overload operators for operations with a `double` on both sides
```c++
Vector3D d = 0.5*a - b/1.5
```
- Implement `scalarProduct()` and `vectorProduct()` functions with appropriate arguments.


## Session 3 (2/11/2020)
The goal of this session is to implement an inheritance hierarchy for polymorphic
classes `Constant`, `Exponential`, and `Polynomial` based on the class [`Function`](examples/Function.h) already discussed during the lecture.
- Implement methods `value()`, `derivative()`, `integrate()` as declared in the header file provided (you cannot change the signature of these methods)
- Overload the `<<` operator for all classes
- Write a program `app.cc` to test your code. For example you can plot your functions in a histogram with ROOT.
- Submit your `Function.{h,cc}`, `Constant.{h,cc}`, `Exponential.{h,cc}`, and `Polynomial.{h,cc}` and the test application `app.cc`

You must separate the declaration (header file) from implementation (source file). Do not change the name of the classes. Make sure the name of the file corresponds to the class.

**Tip:** first implement, compile, and test the `Constant` class with all its methods in your application. Then implement  `Exponential` and make sure it behaves as expected. Finally, implement `Polynomial`.

## Session 4 (9/11/2020)
The scope of this session is the implementation of at least 2 numerical integration Methods
with the [Strategy Pattern](../material/strategy.md) for the `Function` hierarchy implemented last week.

- Implement the `Integrator` base class as discussed at the lecture
- Implement the Monte Carlo method  (`MCIntegrator`)
- Implement the trapezoid or midpoint Method (`MidpointIntegrator`)
- Use a function with known primitive, e.g. `Exponential`, to compare precision of
integration between the two methods and the analytical results
- Make a 1D histogram of the difference `MCMethod-Analytical`, using the ROOT [`TH1F`](https://root.cern.ch/root/htmldoc/guides/users-guide/Histograms.html#histograms) class
  - save the graph as `residual-mc.pdf`
  - make the same plot for the midpoint method
- Plot the difference `MCMethod-Analytical` as a function of trial points `N`, using the ROOT [`TGraph`](https://root.cern.ch/root/html534/guides/users-guide/Graphs.html#tgraph) class
  - save the graph as `residual-mc-tgraph.pdf`
  - make the same plot for the midpoint method
- Once the methods are verified to work, you can integrate other functions, e.g. `Gaussian`, to further test your numerical implementation


## Session 5 (16/11/2020)
Implement the `Parallel` and `Series` of resistors as a polymorphic inheritance hierarchy with the [Composite Pattern](../material/composite.md).

<img src="Resistors.jpg" alt="Composite Pattern for resistors" width=400/>

### Class `Resistor`
- two data members: `name_` and `resistance_`
- virtual methods `value()`, `name()`, `print()`
```C++
Resistor ("r1", 1000);
r1.print();
```
should produce
```C++
r1: 1000 Ohm
```
- setter methods `setName()` and `setValue()`

### Class `Parallel`
- data member `components_`: list of `Resistor` pointers
- member function `add()` to add pointers of `Resistor` objects
- virtual method `value()` compute and return the correct value of the resistance by using the `value()` method of its children
```C++
Resistor r1("r1", 100); // assume ohm
Resistor r2("r2", 200);

Parallel p1("p1");
p1.add(&r1);
p1.add(&r2);

cout << "p1 resistance: " << p1.value() << " Ohm" << endl;

r1.setValue(200);

// you should obtain  a new value for p1
cout << "p1 resistance: " << p1.value() << " Ohm" << endl;
```

- `print()` method should show the structure of the `Parallel`. call `print()` recursively for components.
```C++
p1.print();
```
should produce
```C++
Parallel p1: r1 || r2 : 100 Ohm
  r1: 200 ohm
  r2: 200 Ohm
```

### Class `Series`
Same as `Parallel` but with the correct calculation of resistance. Also `print()` function should use ` -- ` instead of `||`


### Optional
- overload of `<<` operator
```C++
cout << r1 << r2 << p1 << endl;
```
   + **tip**: you could modify `print()` in order to use it properly within `<<`


## Session 6 (23/11/2020)
Today we use the random generator in ROOT to simulate decay of a particle of mass `M` to two lighter particles of mass `m1` and `m2` (`m1 < M` and `m2 < M`). We then study the impact of the detector resolution on the measured invariant mass of the particles.

- The data sample consists of 10^4 events
- In each event there is a B meson (mass `5279 MeV`) decaying to a pion (`140 MeV`) and a kaon (`500 MeV`). The B meson has a momentum of `300 MeV` along the `x` axis.
- In the center of mass of the B meson, the decay products have a momentum `p* = sqrt(M_B^4 + m_pi^4 + m_K^4 - 2 M_B^2 m_pi^2 - 2 M^*2 m_K^2 - 2 m_pi^2 m_K^2 )/(2M_B)` and their direction is random.
   - Pay attention to the proper generation of angles `theta*` and `phi*` in the center of mass. For example, you can use the method [`sphere()`](https://root.cern.ch/doc/master/classTRandom.html#a8b9e587b2cd44f10ed3a4094613e8591) in [`TRandom`](https://root.cern.ch/doc/master/classTRandom.html).
- Use the class [`TLorentzVector`](https://root.cern.ch/doc/master/classTLorentzVector.html) to boost the momentum of the pion and the kaon to the laboratory reference frame.
- Compute the invariant mass of the pion and kaon in the laboratory frame and fill a 1D histogram, with proper legend, axis label and units. You should obtain a delta function at the B mass.
  - save the plot as a pdf file `true-mass.pdf`

- Compute the opening angle between the kaon and the pion in the laboratory and fill a 1D histogram, with proper legend, axis label and units.
  - save the plot as a pdf file `opening-angle.pdf`

Now we simulate the effect of the detector in measuring the momentum. We assume the tracking detector has a Gaussian resolution `\sigma`, e.g `3%`. This process is called **smearing**.

We call `p_K_0` and `p_pi_0`, respectively, the magnitude of the momentum of the kaon and the pion in the laboratory. The detector does not change the direction of the particles.

- Generate the measured momentum `p_K_meas` and `p_pi_meas` of the particles using a Gaussian model for the Detector
- Compute the new 4-momentum of the particles in the Laboratory
- Compute the invariant mass of the measured kaon and pion and fill a 1D histogram
  - what is the mean and the width of the distribution ?
  - is it in agreement with your expectation ?
  - save the plot as a pdf file `measured-mass.pdf`

- Plot the 1D histogram of the true mass (before smearing) and overlay the measured mass (after smearing)
  - save the plot as a pdf file `invariant-mass.pdf`

You can now simulate the effect of different detectors with `1%`,`5%`, and `10%` momentum resolution. Compute the distribution of the invariant mass for each detector. Plot them all together (change the color or histogram filling for each detector).

### Optional
Store the simulated sample in a `TTree`. Each event should have the following Branches
- `p_B`
- `nDau`
- `mass[nDau]`
- `p[nDau]`
- `theta[nDau]`
- `phi[nDau]`

In our case `nDau` will always be `2` for all events.


## Session 7 (30/11/2020)

### Students who did not finish session 6
Complete the exercise from Session 6.
- implement the 3 detectors and show their impact on the invariant mass
- produce a TTree and store it in a ROOT file.
- produce the pdf for all plots
Make sure the root file and the pdf files are submitted for evaluation.

### Students who completed session 6
Read a `TTree` provided by someone else and perform data analysis.
Specifically, the `TTree` with contain generator-level and reconstructed information
from simulated proton-proton collisions at the Large Hadron Collider.
All details at [CODanalysis.md](CODanalysis.md)


## Session 8 (7/12/2020)
Today we simulate the energy loss by ionisation. You can use simple python or jupyter notebook.

### Bethe-Bloch formula
The average energy lost `<dE/dx>` by a relativistic particle in a material of thickness `dx`  can be estimated with the [Bethe-Bloch formula](http://pdg.lbl.gov/2009/reviews/rpp2009-rev-passage-particles-matter.pdf). For simplicity, assume Z/A ~ 2.
  - define a `BetheBloch()` function with proper arguments to compute `<dE/dx>`

Compute the distribution of `<dE/dx>` divided by the density as a function of `beta x gamma` for water, Pb, and air, and plot them  with different colors and proper legend.
  - use log scale for `x` and `y` axes
You should see that the distribution is universal and shows little dependence on the material.

Plot the distribution of `dE/dx` in lead (Pb) for electrons and protons as a function of momentum `p` and use different colors and proper legend.


### Effective energy loss
Consider a beam of `10^12` protons with momentum distributed uniformly between 10 MeV and 6.5 TeV.
The effective energy lost `dE/dx` by a particle is simulated as a Gaussian distribution with the mean given by the average  `<dE/dx>` computed with the [Bethe-Bloch formula](http://pdg.lbl.gov/2009/reviews/rpp2009-rev-passage-particles-matter.pdf), and a width of `3%`.
  - You can use the [random](https://docs.python.org/3/library/random.html) or
  the [NumPy random](https://docs.scipy.org/doc//numpy-1.10.4/reference/generated/numpy.random.normal.html) module.

Plot the distribution of effective lost energy by these protons as a function of their momentum.
Overlay in the same plot the Bethe-Bloch formula.

### Stopping power
Estimate the the thickness of the material needed to stop a particle of a given momentum
- Ask user to provide the mass of the particle  (in MeV)
- Ask user for the momentum of the particle (in MeV)
- Show the distribution of `<dE/dx>` as a function of momentum in water, rock, pb, and air with different colors and legend on the same plot.
- compute and print the the thickness (in cm) of water, rock, pb, and air necessary to stop the particle.


### Atomic and Nuclear properties
- [Lead (Pb)](https://pdg.lbl.gov/2019/AtomicNuclearProperties/HTML/lead_Pb.html)
- [water](https://pdg.lbl.gov/2015/AtomicNuclearProperties/HTML/water_liquid.html)
- [air](https://pdg.lbl.gov/2019/AtomicNuclearProperties/HTML/air_dry_1_atm.html)
- [rock](https://pdg.lbl.gov/2019/AtomicNuclearProperties/HTML/standard_rock.html)

## Session 9 (14/12/2020)
Today we simulate the motion of a body under gravity with friction. In addition
to the python program (or jupyter notebook) upload also the pdf files for the plots.
([pdf](python-gravity-friction.pdf))

## Session 10 (21/12/2020)
Today we exercise with data generation and fitting. We simulate the Higgs mass spectrum and fit it with a signal and background model before performing some simple statistical analysis.

Step by step instructions are available as a [notebook](lab10.ipynb). You should submit the completed notebook. You can also save the most meaningful plots as pdf and submit them as well.


<!--

## Session 7 (16/12/2019)
Use python to simulate the [Compton scattering spectrum](compton.pdf).

-->
