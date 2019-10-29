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
The complete example is in [06-readTree.cc](examples/06-readTree.cc).

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
