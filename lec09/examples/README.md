
- Fill 1D histogram and save pdf file: [01-app1.cc](01-app1.cc)
- change properties of histograms: [02-app2.cc](02-app2.cc)
- Generate random number with TRandom, fit 1D histogram and store to TFile: [02-app3](02-app3.cc)



To compile and link the executable:
```c++
g++ -o /tmp/app 01-app1.cc  `$ROOTSYS/bin/root-config --libs --cflags`
```
