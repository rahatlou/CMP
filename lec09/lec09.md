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
