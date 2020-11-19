# Input/output in ROOT: data storage with [TFile](https://root.cern.ch/doc/master/classTFile.html)

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

first include all necessary header files:
```c++
// standard library header files
#include <iostream>

// ROOT heder files
#include "TRandom3.h"

#include "TH1F.h"
#include "TCanvas.h"

#include "TFile.h"
```
for the time being we are not using the command line variables.

```c++
int main( int argc, char* argv[]) {
```
Open the ROOT file and make sure the file was opened successfully.
Typical cause for failure
- wrong path
- no write privilege

```c++
  // Open TFile for output. Overwite output file if it already exists
  TString rootfname("/tmp/output.root");
  TFile rfile( rootfname, "RECREATE");
  if( !rfile.IsOpen() ) {
    std::cout << "problems creating root file. existing... " << std::endl;
    exit(-1);
  }
  std::cout << "storing output in root file " << rootfname << std::endl;
```

We want to generate the true value of the observable in a given range and then take into acclount the detector resolution to generate the measured value in the detector.

```c++
  // generate random true value in the range [x1,x2]
  // generate the measurement by accounting for a guassian resolution of 10%

  double x1=0.9, x2=1.1;
  double resol = 0.10;
```
Create new histograms to look at true and measured distributions. Note the histogram limits are set as a function of interval  and resolution.

```c++
  // create histograms
  int nbins = 100;
  double xlo = x1*(1-5*resol);
  double xhi = x2*(1+5*resol);
  double binwidth = (xhi-xlo) / nbins;
  std::cout << "# bins: " << nbins << "\t bin width: " << binwidth << std::endl;

  TH1F hx1("hx1", "distribution of true x",
	     nbins, xlo, xhi );

  TH1F hdx1("hdx1", "distribution of measured x",
	    nbins, xlo , xhi );
```

Use the root random generator and initialize the seed
```c++
  //new random generator
  TRandom3*  gen = new TRandom3();
  gen->SetSeed(0); //use machine clock
```
The true values have a flat distribution.

The measured values take into account the detector resolution that depends on the true value.
```c++
  // # measurements
  int nsig = 1000;

  for(int i=0; i< nsig; ++i) {


    // genarate true value
    double x = x1 + gen->Uniform(x2-x1);

    //generate meaured value based on the true value and resolution
    double dx = gen->Gaus(x, x*resol);

    // fill histograms
    hx1.Fill(x);
    hdx1.Fill(dx);

  }
```
After generating the data we now take care of plotting. We also change some histogram properties to make them nicer.
```c++
  // create canvas
  TCanvas canv("canv", "canvas for plotting", 1280, 1024);

  // make histograms nicer and store to file
  hx1.GetXaxis()->SetTitle("Distribution of x [GeV]");
  hx1.Draw();
  canv.SaveAs("/tmp/x.pdf");

  hdx1.GetXaxis()->SetTitle("Distribution of uncertainty \\Delta x [GeV]");
  hdx1.Draw("pe"); // show points with error bars
  canv.SaveAs("/tmp/dx.pdf");
```
A simple example of fitiing with predefined functions. For more options see the ROOT [user guide on fitting histograms](https://root.cern.ch/root/htmldoc/guides/users-guide/FittingHistograms.html)
```c++
  // fit histogram with predefined Gaussian function
  hdx1.Fit("gaus");
  hdx1.Draw();
  canv.SaveAs("/tmp/dxfit.pdf");
```
we can now delete the generator
```c++
  // delete the random generator
  delete gen;
```
histograms as objects can be written to
```c++
  // store histograms to file
  hx1.Write();
  hdx1.Write();

  // close root file
  rfile.Close();

  return 0;
}
```
- What is the standard deviation of the measured values?
- What the width of the fitted Gaussian ?
- How does the measured values compare to your expecation?

### Exercise:
- use command line to pass the name of the output file to programs
- use command line to specify the number of measurements and the resolution

# TTree for data storage

The [`TTree`](https://root.cern.ch/doc/master/classTTree.html) class has been designed to store large number of objects of the same class into file. For a detailed description see the [ROOT user guide on `TTree`](https://root.cern.ch/root/htmldoc/guides/users-guide/Trees.html).

### Tree structure
The tree is the prototype of the data structure to be stored. It is made of branches which can have as many leaves as your data points.

Each branch contains a distinct collection of objects of the same class. So in data analysis each variable, e.g. `x`, `energy`, `track` corresponds to a Branch. The copies of data (for each measurement or experiment) are the leaves of the branch.

### Examples
A number of [examples](../examples/ROOT/) are provided to write and read simple type of trees:

- Fill TTree and store in TFile:  [04-writeTree.cc](../examples/ROOT/04-writeTree.cc)
- Read TTree from file and fill histograms: [06-readTree.cc](../examples/ROOT/06-readTree.cc)
- Fill TTree with variable size branch and store in TFile: [07-writeObjects.cc](../examples/ROOT/07-writeObjects.cc)
- Read TTree from file and fill 1D and 2D histograms:[08-readTree.cc](../examples/ROOT/08-readTree.cc)

## Fill a simple Tree and store in TFile
The complete example is in [04-writeTree.cc](../examples/ROOT/04-writeTree.cc)

First open a root file and create a new TTree object
```c++
// ==== store data in a TTree

TString rootfname("/tmp/dati.root");
TFile* orootfile = new TFile( rootfname, "RECREATE");
if( !orootfile->IsOpen() ) {
  std::cout << "problems creating root file. existing... " << std::endl;
  exit(-1);
}
std::cout << "storing output in root file " << rootfname << std::endl;

TTree* tree = new TTree("datatree","tree containg our data");
```
the name of the `TTree` object, in this case `datatree`, and not the name of the C++ variable (`tree`) is important because ROOT stores all objects in a `TFile` with their name.

In order to store two scalar variables `x` and `dx` in the tree
```c++
// variables to be stored in the tree
double x, dx;
```
we set the reference to them in the two branches `value` and `error` of the tree
```c++
// now set the info for each branch of the tree to correspond to our data
tree->Branch("value", &x,  "value/D");
tree->Branch("error", &dx, "error/D");
```
note that there is no correlation between the name of the variable `x` and the name of the branch `value`.
The `Branch` function has 3 arguments
- name of the branch (`"value"`)
- pointer to variable in memory (`&x`)
- type of the variable in the branch (`"value/D"` which is a `double`)

Next we
- iterate over the data to be stored
- assign the values to `x` and `dx`
- Fill the tree
```c++
for(std::vector<Datum>::const_iterator it = dati.begin(); it != dati.end(); ++it) {
  // assign values to  C++ variables that are going to be stored in the branch
  x = it->value();
  dx = it->error();

  tree->Fill(); // store data in tree IN MEMORY
}
```
Finally in order to store the data to file
```c++
// now actually write tree in file on disk
tree->Write();

// critical to close the file!
orootfile->Close();
```
before closing the root file.

## Read TTree from file
The complete example is in [06-readTree.cc](../examples/ROOT/06-readTree.cc).

In order to access the data in a tree you need
- name of the ROOT file where the tree is stored (`/tmp/dati.root`")
- the name of the tree object (`datatree`)
- the name of the branches (`value` and `error`)

First open the ROOT file
```c++
TString rootfname("/tmp/dati.root");
TFile* orootfile = new TFile( rootfname );
if( !orootfile->IsOpen() ) {
  std::cout << "problems opening root file. existing... " << std::endl;
  exit(-1);
}
std::cout << "Reading data from root file " << rootfname << std::endl;
```
and retrieve a pointer to the tree object
```c++
// get pointer to tree object stored in the file
TTree* tree = (TTree*) orootfile->Get("datatree");
if(!tree) {
  std::cout << "null pointer for TTree! exiting..." << std::endl;
  exit(-1);
}
```
note the explicit cast of the tree object to `TTree*`.

Then declare the C++ variables to access the data in the branches, and set the branch address accordingly
```c++
// variables to be read from the tree
double y, dy;

// now set the info for each branch of the tree to correspond to our data
tree->SetBranchAddress("value", &y);
tree->SetBranchAddress("error", &dy);
```
Finally iterate over the entries in the tree and fill histograms or do any calculation
```c++
int nentries = tree->GetEntries();
for (int i=0; i<nentries; ++i) {
  tree->GetEntry(i); // read data from file to memory

  hx1.Fill(y);
  hdx1.Fill (dy);
}
```
Note that the `TTree::GetEntry()` call is what populates the `y` and `dy` variables
from the data in the tree on disk.

## Trees with variable size branches
Complete example in [07-writeObjects.cc](../examples/ROOT/07-writeObjects.cc)

In the previous example, each event has exactly one `value` and `error` stored. In reality, often we have to deal with situations were the number of objects to be stored varies across the events. For example, if we want to store the energy for all photons produced in a collision. The number of photons will be different in each event. The simplest way is to use fixed-size C-style arrays.

For example we want to store `nmeas` values of `x` and `dx` for `nexp` events, where `nmeas` has a different value for each experiment, e.g. according to a Poisson distribution.

First declare the variables
```c++
// variables to be stored in the tree
const int nMeasMax=200; // maximum size of static array per event
double x0, x[nMeasMax], dx[nMeasMax];
int nmeas;
```
we assume that the number of measurements will never exceed nMeasMax. This ugly limitation can be overcome in a future example `std::vector<T>`.

```c++
// now set the info for each branch of the tree to correspond to our data
tree->Branch("nmeas", &nmeas, "nmeas/I");
tree->Branch("value", x,  "value[nmeas]/D"); // nmeas is the index of value[]
tree->Branch("error", dx, "error[nmeas]/D"); // and error[] in the tree
```
note that we have a new branch to store `nmeas` which is used as the index for the array `value[nmeas]`

`nmeas` is extracted from a Poisson distribution. Arrays are filled before filling the tree
```c++
// # measurements
int nMeasAvg=50;
int nexp = 1000;

for(int iexp=0; iexp<nexp; iexp++) {

  nmeas = gen->Poisson(nMeasAvg);

  if( nmeas > nMeasMax ) {
    std::cout << "WARNING: nmeas > " << nMeasMax << " your TTRee will be corrupted" << std::endl;
  }

  for(int i=0; i< nmeas; ++i) {

    // genarate true value
    x0 = x1 + gen->Uniform(x2-x1);

    //generate meaured value based on the true value and resolution
    x[i] = gen->Gaus(x0, x0*resol);

    //generate an uncertainty based on the resolution
    dx[i] = x[i] * resol;
  }

  tree->Fill(); // write the data from memory to file at end of each experiment
```
and finally store the tree
```c++
} // end of experiments
tree->Write();
```

Reading the tree also requires some changes to account for the arrays (see the complete example in [08-readTree.cc](../examples/ROOT/08-readTree.cc))

Declare the variables and set the address for the branches
```c++
// variables to be read from the tree
const int nMeasMax = 200;
double y[nMeasMax], dy[nMeasMax];
int nmeas;

// now set the info for each branch of the tree to correspond to our data
tree->SetBranchAddress("value", y);
tree->SetBranchAddress("error", dy);
tree->SetBranchAddress("nmeas", &nmeas);
```
iterate over events in the tree, and for each event iterate over measurements
```c++
int nentries = tree->GetEntries();
for (int iexp=0; iexp<nentries; ++iexp) {
  tree->GetEntry(iexp); // read data from file to memory

  hnmeas.Fill(nmeas);

  // for each experiment read the measurements
  for(int i = 0; i< nmeas; ++i) {
    hdx1.Fill( dy[i] );
  } // loop on mesurements
} // end of experiments
```
