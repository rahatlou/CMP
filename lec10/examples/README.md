
- Fill 1D histogram and save pdf file: [01-app1.cc](01-app1.cc)
- change properties of histograms: [02-app2.cc](02-app2.cc)
- store data in ASCII file with ofstream: [03-app3.cc](03-app3.cc)
- Fill TTree and store in TFile:  [04-writeTree.cc](04-writeTree.cc)
- Store also 1D histograms in TFile: [05-writeObjects.cc](05-writeObjects.cc)
- read TTree from file and fill histograms: [06-readTree.cc](06-readTree.cc)
- Fill TTree with variable size branch and store in TFile: [07-writeObjects.cc](07-writeObjects.cc)
- Read TTree from file and fill 1D and 2D histograms:
[08-readTree.cc](08-readTree.cc)


To compile and link the executable:
```c++
g++ -o /tmp/app `$ROOTSYS/bin/root-config --cflags --libs` Datum.cc app.cc
```

for example

```c++
g++ -o /tmp/write `$ROOTSYS/bin/root-config --cflags --libs` Datum.cc 04-writeTree.cc
g++ -o /tmp/read `$ROOTSYS/bin/root-config --cflags --libs` Datum.cc 06-readTree.cc

```





