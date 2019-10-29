# TTree for data storage

The [`TTree`](https://root.cern.ch/doc/master/classTTree.html) class has been designed to store large number of objects of the same class into file.
For a detailed description see the [ROOT user guide on `TTree`](https://root.cern.ch/root/htmldoc/guides/users-guide/Trees.html).

In this lecture a number of [examples](examples/) are provided to write and raed simple type of trees:

- Fill TTree and store in TFile:  [04-writeTree.cc](examples/04-writeTree.cc)
- Read TTree from file and fill histograms: [06-readTree.cc](examples/06-readTree.cc)
- Fill TTree with variable size branch and store in TFile: [07-writeObjects.cc](examples/07-writeObjects.cc)
- Read TTree from file and fill 1D and 2D histograms:[08-readTree.cc](examples/08-readTree.cc)

## Fill a simple Tree and store in TFile:
The complete example is in [04-writeTree.cc](examples/04-writeTree.cc)
