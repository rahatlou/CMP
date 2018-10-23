# Storing custom objects in TTree

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

Generate pseuso-measurements and add data to the tree
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
g++ -o /tmp/app `$ROOTSYS/bin/root-config --libs --cflags` 01-writeObjects.cc Datum.cc MyDict.cxx
```



