# Trees with variable-size arrays

## storing arrays of values

In a typical data analysis, we deal with data collected for different
experiments or events. For example in particle physics,
an event corresponds to data recorded by the detector following  a
collision.

In general you might have a set of sensors or detectors that collect
information when requested. We collect this data, which can
potentially be correleated and/or related together to define an event
or experiment.

for example we measure `x` and its uncertainty `nmeas` times, but the
value of `nmeas` can be different for diffrent groups or for the same
group at different times.

In [01-writeObjects.cc](examples/01-writeObjects.cc) we want to store
variable-size array of information

Let's assume that there can be at most `nMeasMax` measurements in
each experiment
```
  // variables to be stored in the tree
  const int nMeasMax=200; // maxim size of static array
  double x[nMeasMax], dx[nMeasMax];
  int nmeas;
  ```
as you see we are forced to use old-style static C arrays!

Then we create the new Tree
```
  // create the tree
  TTree* tree = new TTree("datatree","tree containg our data");
  
  // now set the info for each branch of the tree to correspond to our data
  tree->Branch("nmeas", &nmeas, "nmeas/I");
  tree->Branch("value", x,  "value[nmeas]/D"); // nmeas is the index of value[]
  tree->Branch("error", dx, "error[nmeas]/D"); // and error[] in the tree
  ```

And finally we can loop over experiments and measurements
```
  // # of experiments and average # of measurements 
  int nMeasAvg=10;
  int nexp = 100;

  for(int iexp=0; iexp<nexp; iexp++) {

    // each experiment has a different # of measurements
    nmeas = gen->Poisson(nMeasAvg);
    
    if( nmeas > nMeasMax ) {
      std::cout << "WARNING: nmeas > " << nMeasMax << " your TTRee will be corrupted" << std::endl;
    }
    
    for(int i=0; i< nmeas; ++i) {
      // genarate value
      x[i] = x1 + gen->Uniform(x2-x1);
    
      //generate uncertainty based on the value
      dx[i] = gen->Gaus(x[i], x[i]*resol);        
    }

    tree->Fill(); // write the data from memory to file at end of each experiment

    
  } // end of experiments
  ```

for every experiment we store the number of measurements `nmeas` that
tells us the number of actual data points stored in `value` and
`error` branches.

Link the executable and run
```
$ g++ -o /tmp/01-write `$ROOTSYS/bin/root-config --libs --cflags` 01-writeObjects.cc Datum.cc
$ /tmp/01-write
storing output in root file /tmp/dati.root
```


## reading variable-size arrays from TTree

In [02-readTree](examples/02-readTree.cc) we want to read the TTree
with variable-size arrays.

Get pointer to the TTree in the file
```
  // get pointer to tree object stored in the file
  TTree* tree = (TTree*) orootfile->Get("datatree");
  if(!tree) {
    std::cout << "null pointer for TTree! exiting..." << std::endl;
    exit(-1);
  }
  ```

Now define the arrays in memory that will be filled with data stored
in the file and set the branch address
```
  // variables to be read from the tree
  // You need to define maximum number of cells in the array
  // this is *UGLY* but necessary
  const int nMeasMax = 200; 
  double y[nMeasMax], dy[nMeasMax];
  int nmeas;

  // now set the info for each branch of the tree to correspond to our data
  tree->SetBranchAddress("value", y);
  tree->SetBranchAddress("error", dy);
  tree->SetBranchAddress("nmeas", &nmeas);

```
Now loop over experiments and analyse data for each experiment
```
  int nentries = tree->GetEntries();
  for (int iexp=0; iexp<nentries; ++iexp) {
    tree->GetEntry(iexp); // read data from file to memory

    // vector of Datum in case you want to use your Datum class
    std::vector<Datum> dati;

    // plot of # measurements
    hnmeas.Fill(nmeas);
    
    // for each experiment read the measurements
    for(int i = 0; i< nmeas; ++i) {
      dati.push_back( Datum(y[i], dy[i]) );
      // fill histogram
      hdx1.Fill( dy[i] );
      

    } // loop on mesurements

    // compute RMS for measurements in each experiment
    // and fill a histogram
    hdxRMS.Fill( hdx1.GetRMS() );
    h2RMS.Fill(nmeas, hdx1.GetRMS() );
    
  } // end of experiments
  ```

This time we are also filling a 2D hisotogram that shows the
distribution of uncdertainties as a function of number of measurements:
```
  TH2F h2RMS("h2RMS", "Distribution of dx RMS vs numb. measurements",
	     21, -0.5, 20.5,
	     nbins, 0.05, 0.10 );
```

Before plotting the histograms you can set options for additional
info to be shown
```
  // useful plot settings
   gStyle->SetOptStat(111111); // show over and underflow  
```

Create canvas and show plots
```
  // create canvas
  TCanvas canv("canv", "canvas for plotting", 1280, 1024);
  h2RMS.GetXaxis()->SetTitle("Number of measurements");
  h2RMS.GetYaxis()->SetTitle("dx RMS");
  h2RMS.Draw("box");
  canv.SaveAs("/tmp/2dRMS.pdf");
```

Now link the executable
```
g++ -o /tmp/02-read `$ROOTSYS/bin/root-config --libs --cflags` 02-readTree.cc  Datum.cc
```

and run
```
/tmp/02-read
# bins: 50	 bin width: 0.02
Reading data from root file /tmp/dati.root
Info in <TCanvas::Print>: pdf file /tmp/2dRMS.pdf has been created
Info in <TCanvas::Print>: pdf file /tmp/expplots.pdf has been created
```



# Trees with custom objects 

## Storing custom objects in TTree

First we need to tell ROOT about our class and its interface. This requires generating a Dictionary for your class.
For example suppose we want to store `Datum` objects in TTree branches.

Generate dictionary for `Datum`
```
$ROOTSYS/bin/rootcint -f MyDict.cxx Datum.h
```

This will create a new file `MyDict.cxx`. You can check it was successful by compiling it
```
g++ -c `$ROOTSYS/bin/root-config --cflags` MyDict.cxx
```
If everything worked fine you will see
```
ls MyDict*
MyDict.cxx        MyDict.o          MyDict_rdict.pcm
```


Now we write a program to store Datum in branches. For example [04-readTreeCustomObject.cc](examples/04-readTreeCustomObject.cc)

First you need to add these additional lines in your application
```
// my header files
#include "Datum.h"

#ifdef __MAKECINT__
#pragma link C++ class Datum+;
#endif
```

Then you add a new branch for your Datum object
```C++
 // create the tree
  TTree* tree = new TTree("datatree","tree containg our data");

  // variables to be stored in the tree
  Datum  dato;
  
  // now set the info for each branch of the tree to correspond to our data
  tree->Branch("datum", &dato);
  ```

Generate pseudo-measurements and add data to the tree
```
  for(int i=0; i< nmeas; ++i) {
    // genarate value
    double x = x1 + gen->Uniform(x2-x1);

    dato = Datum( x, gen->Gaus(x , x*resol) );

    // add leaf to the  tree
    tree->Fill(); 
  }
```

Link you application, adding also the dictionary `MyDict.cxx` in addition to `Datum.cc`
```
g++ -o /tmp/03-write `$ROOTSYS/bin/root-config --libs --cflags` 03-writeCustomObject.cc Datum.cc MyDict.cxx
```
and run
```
/tmp/03-write
storing output in root file /tmp/dati.root
```
you should now see there is only one branch in your tree called `datum` 



## Reading custom objects from TTree

We now want to read back the `Datum` objects store in the file with [04-readTreeCustomObject.cc](examples/04-readTreeCustomObject.cc).

After opening the file and getting a pointer to the TTree
```
  TString rootfname("/tmp/dati.root");
  TFile* orootfile = new TFile( rootfname );
  if( !orootfile->IsOpen() ) {
    std::cout << "problems opdening root file. existing... " << std::endl;
    exit(-1);
  }
  std::cout << "Reading data from root file " << rootfname << std::endl;
  ```
  You need as usual to set the branch address to read the data
  ```
  // Pointer to a Datum object to be read from Branch
  Datum* d=0;
  
  // now set the info for each branch of the tree to correspond to our data
  tree->SetBranchAddress("datum", &d);
  ```
  *Note that you are setting the address of a pointer  to a Datum
  object in the branch!*

As usual you can now loop over all the entries in the tree and access
your Datum object which is the leaf of the tree
```
  int nentries = tree->GetEntries();
  for (int i=0; i<nentries; ++i) {
    tree->GetEntry(i); // read data from file to memory
    
    hx1.Fill( d->value() );
    hdx1.Fill ( d->error() );
  }
  ```
  
Link the new executable `read`
```
g++ -o /tmp/04-read `$ROOTSYS/bin/root-config --libs --cflags` 04-readTreeCustomObject.cc  Datum.cc MyDict.cxx
```

and run it
```
/tmp/04-read
# bins: 50	 bin width: 0.02
Reading data from root file /tmp/dati.root
Info in <TCanvas::Print>: pdf file /tmp/newplots.pdf has been created
```

You will notice that this time the plots correctly report also the
entries per bin width in the Y axis label. This is done with the
[TString::Form()](https://root.cern.ch/doc/v614/classTString.html#aeb44d6183d8b1f1b7090dbd3c93f5e39)
function which has a syntax very similar to `sprintf` in C.

```
  TH1F hx1("hx1", "distribution of x values",
	     nbins, x1, x2 );

  // use TString::Form() function to add correct y axis label with bin width 
  hx1.GetYaxis()->SetTitle(Form("entries/%.3f cm", binwidth));
```



