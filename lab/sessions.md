# Laboratory sessions

## Session 1 (28/10/2019)
In this first session we design and implement a new class `Complex` to implement
mathematical operations between `Complex` and regular `double` objects.
- overload operators `+,-,*,/` between `Complex` objects and operator `<<` for output
```c++
Complex a(-1,2), b(0.5, 0.9);
Complex c = a/b;
cout << c << endl;
```
- overload operators for operations with a `double` on the rhs
```c++
Complex   i(0,1);
Complex d = i*3 + a + b/2.3 + 1.2;
```
- overload operators for operations with a `double` on the lhs
```c++
Complex z = 3*i + 2/d;
```

## Session 2 (11/11/2019)
The scope of this session is to exercise input/output of `TTree` with `TFile`

- Finish implementing class `Complex`
- prepare dictionary for `Complex` to be used in ROOT  
- generate 10'000 random `Complex` numbers with magnitude `r<1`
- create a `TTree` with a single branch that contains a `Complex` object
- Store the `TTree` to disk with `TFile`
- Use `TTree::MakeClass("Analyser")` function to generate the `Analyser` class
from the stored `TTree`
- write a new analysis application to read back the `TTree ` from file using the
new `Analyser` class


## Session 3 (18/11/2019)
The scope of this session is the implementation of at least 2 numerical integration Methods
with the [Strategy Pattern](../lec13/strategy.md).

- Implement the trapezoid or midpoint Method
- Use a function with known primitive, e.f. the exponential, to compare precision of
integration with the MC method


## Session  4 (25/11/2019)
The scope of this session is to read a `TTree` provided by someone else and perform data analysis.
Specifically, the `TTree` with contain generator-level and reconstructed information
from simulated proton-proton collisions.
