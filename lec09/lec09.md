# Input/output in ROOT: data storage with [TTree](https://root.cern.ch/doc/master/classTTree.html) and [TFile](https://root.cern.ch/doc/master/classTFile.html)

## Data storage
- So far you have mainly used text files to store data in your programs and perform analysis.
- this solution cannot scale when you have a large sample of data to be measured, stored, and analysed
- Binary files with dedicated storage containers provide an efficient solution

## Storage of custom objects

- Another problem is storage of objects of custom types e.g. `Datum` which is not your typical `int`, `double`, `float`, or `string`
- And what about histograms such as `TH1F` and more advanced objects used in `ROOT` ?

### [TFile](https://root.cern.ch/doc/master/classTFile.html)
- In ROOT we use the File class for storage of data
- Detailed description of the class is available in the [user guide](https://root.cern/root/htmldoc/guides/users-guide/ROOTUsersGuide.html#inputoutput)
- TFile is similar to a UNIX directory
  * it can contain directories and objects
  * objects are stored in machine independent format  

- To use a TFile object you need to include its header
``` c++
// ... some code...
#include "TFile.h"
TFile f("outputfile.root");
```

## Generation of random numbers in ROOT

- ROOT has several random number generators
- For a summary of available generators see the reference for [TRandom](https://root.cern.ch/doc/master/classTRandom.html)
  * we will be using the [TRandom3 class](https://root.cern.ch/doc/master/classTRandom.html) in our examples
- TRandom provides generators for a number of commonly used functions
  * Uniform
  * Gaussian
  * Exponential
  * Breit-Wigner
  * Binomial
  * Poisson
  * Landau
- It also has functions to generate custom random numbers
  * from an existing histogram
  * from a custom function

## Example: filling histograms and storage to TFile
The complete example is available as [examples/02-app3](examples/02-app3.cc)
