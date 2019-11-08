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


Now we write a program to store Datum in branches. For example [03-writeCustomObject.cc](examples/03-writeCustomObject.cc)

First you need to add these additional lines in your application
```c++
// my header files
#include "Datum.h"

#ifdef __MAKECINT__
#pragma link C++ class Datum+;
#endif
```

Then you add a new branch for your Datum object
```c++
 // create the tree
  TTree* tree = new TTree("datatree","tree containg our data");

  // variables to be stored in the tree
  Datum  dato;

  // now set the info for each branch of the tree to correspond to our data
  tree->Branch("datum", &dato);
  ```

Generate pseudo-measurements and add data to the tree
```c++
for(int i=0; i< nmeas; ++i) {
  // genarate value
  double x0 = x1 + gen->Uniform(x2-x1);
  double x = gen->Gaus(x0 , x0*resol);
  double err =  (x2-x1)/sqrt(12);
  dato = Datum( x,  gen->Gaus(err , err*0.10) );

  // add leaf to the  tree
  tree->Fill();
}
```

Link you application, adding also the dictionary `MyDict.cxx` in addition to `Datum.cc`
```
g++ -o /tmp/03-write  03-writeCustomObject.cc Datum.cc MyDict.cxx `$ROOTSYS/bin/root-config --libs --cflags`
```
and run
```
/tmp/03-write
storing output in root file /tmp/dati.root
```
you should now see there is only one branch in your tree called `datum`



## Reading custom objects from TTree

We now want to write a new application
[04-readTreeCustomObject.cc](examples/04-readTreeCustomObject.cc) to read
back the `Datum` objects stored in the root file from the previous example.

After opening the file and getting a pointer to the TTree
```c++
  TString rootfname("/tmp/dati.root");
  TFile* orootfile = new TFile( rootfname );
  if( !orootfile->IsOpen() ) {
    std::cout << "problems opdening root file. existing... " << std::endl;
    exit(-1);
  }
  std::cout << "Reading data from root file " << rootfname << std::endl;
  ```
  You need as usual to set the branch address to read the data
  ```c++
  // Pointer to a Datum object to be read from Branch
  Datum* d=0;

  // now set the info for each branch of the tree to correspond to our data
  tree->SetBranchAddress("datum", &d);
  ```
  *Note that you are setting the address of a pointer  to a Datum
  object in the branch!*

As usual you can now loop over all the entries in the tree and access
your Datum object which is the leaf of the tree
```c++
  int nentries = tree->GetEntries();
  for (int i=0; i<nentries; ++i) {
    tree->GetEntry(i); // read data from file to memory

    hx1.Fill( d->value() );
    hdx1.Fill ( d->error() );
  }
  ```

Link the new executable `read`
```
g++ -o /tmp/04-read 04-readTreeCustomObject.cc  Datum.cc MyDict.cxx `$ROOTSYS/bin/root-config --libs --cflags`
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

```c++
  TH1F hx1("hx1", "distribution of x values",
	     nbins, x1, x2 );

  // use TString::Form() function to add correct y axis label with bin width
  hx1.GetYaxis()->SetTitle(Form("entries/%.3f", binwidth));
```


# Using TTree not created by you

Very often you will have to analyse data stored in a TTree not created
by you. This is typical in particle physics experiments.

In principle, to write an application to read the
TTree, you need the list and types of all branches in order to
`BranchSetAddress` for each of them. This can be both **painful** and
**tedious** to do. Luckily this part can be generated automatically by
ROOT.

Let's assume you have `/tmp/dati01.root` created by
[01-writeObjects.cc](examples/01-writeObjects.cc)

```bash
g++ -o /tmp/01-write 01-writeObjects.cc `$ROOTSYS/bin/root-config --libs --cflags`
/tmp/01-write
storing output in root file /tmp/dati01.root
```

You can inspect and create a skeleton for a class based on the Tree
object
```
root /tmp/dati01.root
   ------------------------------------------------------------
  | Welcome to ROOT 6.14/00                http://root.cern.ch |
  |                               (c) 1995-2018, The ROOT Team |
  | Built for macosx64                                         |
  | From tag v6-14-00, 13 June 2018                            |
  | Try '.help', '.demo', '.license', '.credits', '.quit'/'.q' |
   ------------------------------------------------------------

root [0]
Attaching file /tmp/dati.root as _file0...
(TFile *) 0x7fe4798df040
root [1] .ls
TFile**		/tmp/dati01.root
 TFile*		/tmp/dati01.root
  KEY: TTree	datatree;1	tree containg our data
root [2] datatree->Print()
******************************************************************************
*Tree    :datatree  : tree containg our data                                 *
*Entries :      100 : Total =           19069 bytes  File  Size =      17615 *
*        :          : Tree compression factor =   1.01                       *
******************************************************************************
*Br    0 :nmeas     : nmeas/I                                                *
*Entries :      100 : Total  Size=        961 bytes  File Size  =        279 *
*Baskets :        1 : Basket Size=      32000 bytes  Compression=   1.71     *
*............................................................................*
*Br    1 :value     : value[nmeas]/D                                         *
*Entries :      100 : Total  Size=       8932 bytes  File Size  =       8348 *
*Baskets :        1 : Basket Size=      32000 bytes  Compression=   1.00     *
*............................................................................*
*Br    2 :error     : error[nmeas]/D                                         *
*Entries :      100 : Total  Size=       8932 bytes  File Size  =       8348 *
*Baskets :        1 : Basket Size=      32000 bytes  Compression=   1.00     *
*............................................................................*
root [3] datatree->MakeClass("DataTree");
...
ignore the errors and warnings about libHbook and libFortran
Info in <TTreePlayer::MakeClass>: Files: DataTree.h and DataTree.C generated from TTree: datatree
```
this will generate 2 files `DataTree.h` and `DataTree.C`

Let's start with taking a look at [`DataTree.h`](examples/DataTree.h)
```c++
//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Oct 23 11:32:33 2018 by ROOT version 6.14/00
// from TTree datatree/tree containg our data
// found on file: /tmp/dati.root
//////////////////////////////////////////////////////////

#ifndef DataTree_h
#define DataTree_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class DataTree {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Int_t           nmeas;
   Double_t        value[17];   //[nmeas]  you need to change by hand  17 -> 200
   Double_t        error[17];   //[nmeas]  you need to change by hand  17 -> 200
    // List of branches
   TBranch        *b_nmeas;   //!
   TBranch        *b_value;   //!
   TBranch        *b_error;   //!

   DataTree(TTree *tree=0);
   virtual ~DataTree();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif
```
 you notice that `17` is a non-typical value! It is that maximum
 length of the array in the tree. You need to modify this by hand and set it to a *large value* based on infortmation provided to you
   by whoever created the root file. This is yet another unfortunate example of static C arrays. We will change this to be `200`.

You wil also notice that  [`DataTree.h`](examples/DataTree.h) implements also most of the
class member functions
```c++
#ifdef DataTree_cxx
DataTree::DataTree(TTree *tree) : fChain(0)
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/tmp/dati.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("/tmp/dati.root");
      }
      f->GetObject("datatree",tree);

   }
   Init(tree);
}
```
The constor needs a pointer to a TTree in order to build a new
   DataTree object. It is better to change the the defult behaviour to
   avoid problems in the future

```c++
#ifdef DataTree_cxx
#include<iostream>
DataTree::DataTree(TTree *tree) : fChain(0)
{
// if parameter tree is not specified (or zero) exit
   if (tree == 0) {
        std::cout << "No tree has been provided. exiting!" << std::endl;
        exit(-1)
      }
      f->GetObject("datatree",tree);

   }
   Init(tree);
}
```



The rest of the code in  [`DataTree.h`](examples/DataTree.h) can be left unchanged:
```c++
DataTree::~DataTree()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t DataTree::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t DataTree::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}
```
In particular the `Init()` function does set the Branch Adderess
correctly for all branches in the tree.

```c++
void DataTree::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("nmeas", &nmeas, &b_nmeas);
   fChain->SetBranchAddress("value", value, &b_value);
   fChain->SetBranchAddress("error", error, &b_error);
   Notify();
}

Bool_t DataTree::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void DataTree::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t DataTree::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
```
Looking at  [`DataTreeORIG.C`](examples/DataTreeORIG.C) generated by `ROOT` it implements the most
important function DataTree::Loop() which is used to analyse the
data in the TTree.

```c++
#define DataTree_cxx
#include "DataTree.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void DataTree::Loop()
{
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
   }
}
```
This is the file to be modified by you to add your custom analysis code.
In [`DataTree.C`](examples/DataTree.C) you see an example of a modified `Loop()` function to
- open a new output ROOT file
- book histograms
- loop over events
- do some calculations
- plot histograms and save them in a pdf file
- store objects in the outout root file
```c++
void DataTree::Loop()
{
   if (fChain == 0) return;

   // create a new TFile to store output
   // this is a different file from the one where the inout data is stored
   TFile outfile("/tmp/analysis.root","RECREATE");

   // book histograms
   TH1F  hx("hx","distribution of all x", 50, 0.4, 1.8);
   TH1F  hxmean("hxmean","distribution of average x per experiment", 50, 0.9, 1.1);

   TH1F  hdx("hdx","distribution of all \\deltax", 50, 0., 0.1);
   TH1F  hdxstdev("hdxstdev","distribution of Std. Dev of \\deltax per experiment", 50, 0., 0.01);

   TH1F  hxSmalldx("hxSmalldx","distribution of all x with small errors", 100, 0.5, 2.5);

   TH2F  hdxvsxall("hdxvsxall", "\\deltax vs x",50, 0.4, 1.8, 50, 0., 0.1 );


   // loop over events in the tree
   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;

      // ---- add your code here to do analysis with data in the Tree
      if(jentry%5==0) std::cout << "processing event: " << jentry << std::endl;

      // reset histograms to compute mean and std Dev
      //hx->Clear();
      hx.Clear();
      hdx.Clear();

      // loop over measurements in this event
      for(int im=0; im < nmeas; im++) {
        // fill histos to compute mean and stdev for each experiment/event
        //hx->Fill(value[im]);
        hx.Fill(value[im]);
        hdx.Fill(error[im]);

        hdxvsxall.Fill( value[im], error[im] );

        // only plot value for small errors
        if(error[im]<0.05) hxSmalldx.Fill(value[im]);
      }

      // fill histo with info for each event/experiment
      hxmean.Fill( hx.GetMean() );
      hdxstdev.Fill( hdx.GetStdDev() );

      // --- end of analysis code
   } // end of event Loop


   // make newplots
   TCanvas* c1 = new TCanvas("c1","canvas", 1280,1024);
   c1->Divide(2,2);
   gStyle->SetOptStat(111111);

   c1->cd(1);

   hxmean.Draw();

   c1->cd(2);
   hdxstdev.Draw();

   c1->cd(3);
   hxSmalldx.Draw();

   c1->cd(4);
   hdxvsxall.Draw("colz3");

   c1->SaveAs("/tmp/analysisPlots.pdf");

  // write objects to output file
  hxmean.Write();
  hdxstdev.Write();
  hxSmalldx.Write();
  hdxvsxall.Write();
  c1->Write();

  // close outout file
  outfile.Close();

}
```
