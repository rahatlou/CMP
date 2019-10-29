# TTree for data storage

The [`TTree`](https://root.cern.ch/doc/master/classTTree.html) class has been designed to store large number of objects of the same class into file. For a detailed description see the [ROOT user guide on `TTree`](https://root.cern.ch/root/htmldoc/guides/users-guide/Trees.html).

### Tree structure
The tree is the prototype of the data structure to be stored. It is made of branches which can have as many leaves as your data points.

Each branch contains a distinct collection of objects of the same class. So in data analysis each variable, e.g. `x`, `energy`, `track` corresponds to a Branch. The copies of data (for each measurement or experiment) are the leaves of the branch.

### Examples
A number of [examples](examples/) are provided to write and read simple type of trees:

- Fill TTree and store in TFile:  [04-writeTree.cc](examples/04-writeTree.cc)
- Read TTree from file and fill histograms: [06-readTree.cc](examples/06-readTree.cc)
- Fill TTree with variable size branch and store in TFile: [07-writeObjects.cc](examples/07-writeObjects.cc)
- Read TTree from file and fill 1D and 2D histograms:[08-readTree.cc](examples/08-readTree.cc)

## Fill a simple Tree and store in TFile
The complete example is in [04-writeTree.cc](examples/04-writeTree.cc)

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

In this example we want to store two scalar variables `x` and `dx` in
```c++
// variables to be stored in the tree
double x, dx;
```
which requires setting them as the reference for the two branches `value` and `error` in the tree
```c++
// now set the info for each branch of the tree to correspond to our data
tree->Branch("value", &x,  "value/D");
tree->Branch("error", &dx, "error/D");

```
