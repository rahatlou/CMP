# Input/output in ROOT: data storage with [TTree](https://root.cern.ch/doc/master/classTTree.html) and [TFile](https://root.cern.ch/doc/master/classTFile.html)

## Data storage
- So far you have mainly used text files to store data in your programs and perform analysis.
- this solution cannot scale when you have a large sample of data to be measured, stored, and analysed
- Binary files with dedicated storage containers provide an efficient solution

# Storage of custom objects

- Another problem is how to store custom objects e.g. `Datum` which is not your typical `int`, `double`, `float`, or `string`
- And what about histograms such as `TH1F` and more advanced objects used in `ROOT` ?
