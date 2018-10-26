# Using TTree not created by you

Very often you will have to analyse data stored in a TTree not created
by you. This is typical in particle physics experiments.

In principle to write an application to read the
TTree, you need the list and types of all branches in order to
`BranchSetAddress` for each of them. This can be both **painful** and
**tedious** to do. Luckily this part can be generated automatically by
ROOT.

Let's assume you have `/tmp/dati.root` created by
[01-writeObjects.cc](examples/01-writeObjects.cc).

**Reminder**: you can create the executable and produce the root file
with
```
g++ -o /tmp/write 01-writeObjects.cc `root-config --libs --cflags`
/tmp/write
storing output in root file /tmp/dati.root
```

## Create a custom class for TTree data
You can inspect and create a skeleton for a class based on the TTree
data
```
root /tmp/dati.root
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
TFile**		/tmp/dati.root
 TFile*		/tmp/dati.root
  KEY: TTree	datatree;1	tree containg our data
root [2] datatree->Print()
******************************************************************************
*Tree    :datatree  : tree containg our data                                 *
*Entries :      100 : Total =           19709 bytes  File  Size =      15648 *
*        :          : Tree compression factor =   1.19                       *
******************************************************************************
*Br    0 :nmeas     : nmeas/I                                                *
*Entries :      100 : Total  Size=        961 bytes  File Size  =        278 *
*Baskets :        1 : Basket Size=      32000 bytes  Compression=   1.71     *
*............................................................................*
*Br    1 :value     : value[nmeas]/D                                         *
*Entries :      100 : Total  Size=       9252 bytes  File Size  =       6044 *
*Baskets :        1 : Basket Size=      32000 bytes  Compression=   1.43     *
*............................................................................*
*Br    2 :error     : error[nmeas]/D                                         *
*Entries :      100 : Total  Size=       9252 bytes  File Size  =       8668 *
*Baskets :        1 : Basket Size=      32000 bytes  Compression=   1.00     *
*............................................................................*
root [3] datatree->MakeClass("Analysis");
...
ignore the errors and warnings about libHbook and libFortran
Info in <TTreePlayer::MakeClass>: Files: Analysis.h and Analysis.C generated from TTree: datatree
```
this will generate 2 files `Analysis.h` and `Analysis.C`

There is a new class `Analysis` defined in  [`Analysis.h`](examples/Analysis.h)
```c++
class Analysis {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Int_t           nmeas;
   Double_t        value[17];   //[nmeas]  change 17 --> 100 or
   Double_t        error[17];   //[nmeas]   another big value 

   // List of branches
   TBranch        *b_nmeas;   //!
   TBranch        *b_value;   //!
   TBranch        *b_error;   //!

   Analysis(TTree *tree=0);
   virtual ~Analysis();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};
```
 you notice that `17` is a non-typical value! It is that maximum
 length of the array in the tree. You need to modify this by hand and set it to a *large value* based on infortmation provided to you
   by whoever created the root file. This is yet another unfortunate example of static C arrays. We will change this to be `100`.

You wil also notice that  [`Analysis.h`](examples/Analysis.h) implements also most of the
class member functions
```c++
Analysis::Analysis(TTree *tree) : fChain(0) 
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
Analysis::Analysis(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero) exit
   if (tree == 0) {
        std::cout << "No tree has been provided. exiting!" << std::endl;
        exit(-1);
   }
   Init(tree);
}
```
You also need to modify the destructor and comment out the `delete`
because we have changed the constructor to take a pointer 
```
Analysis::~Analysis()
{
   if (!fChain) return;
   //delete fChain->GetCurrentFile();
}
```


The rest of the code in  [`Analysis.h`](examples/Analysis.h) can be
left unchanged. Note that function`Init()` sets the Branch Adderess
correctly for all branches in the tree.

```c++
void Analysis::Init(TTree *tree)
{
 if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("nmeas", &nmeas, &b_nmeas);
   fChain->SetBranchAddress("value", value, &b_value);
   fChain->SetBranchAddress("error", error, &b_error);
   Notify();
}
```
Looking at  [`Analysis.C`](examples/Analysis.C) it implements the most
important function `Analysis::Loop()` which will be used to analyse the
data in the TTree.

```c++
void Analysis::Loop()
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
This is the file to be modified by you to add your custom analysis
code.

## Using the new Analysis  class

The new application [02-analysis.cc](examples/02-analysis.cc) for data
analysis is much simpler because all analysis code will be implemented in
`Analysis::Loop()` inside [Analysis.C](examples/Analysis.C).
```c++
int main( int argc, char* argv[]) {

  // get name of root file from command line
  if(argc < 2) {
    cout << "usage: 02-analysis <rootfile>" << endl;
    cout << "provide the rootfile containing the tree for analysis" << endl;
    exit(-1);
  }
  
  // ==== open TFile
  TString fname(argv[1]);
  TFile* rootfile = TFile::Open(fname);
  if( !rootfile->IsOpen() ) {
    std::cout << "problems reading root file. existing... " << std::endl;
    exit(-1);
  }
  std::cout << "reading data from " << fname << std::endl;

  //=== pointer to TTree
  // get pointer to tree object stored in the file
  // you can also acquire the name of the tree from command line
  TTree* tree = (TTree*) rootfile->Get("datatree");
  if(!tree) {
    std::cout << "null pointer for TTree! exiting..." << std::endl;
    exit(-1);
  }

  Analysis an(tree);
  // all your analysis code will be in Analysis.C
  an.Loop();

  // close root file!
  rootfile->Close();
  
  return 0;
}
```

You can create the executable
```
g++ -o /tmp/app 02-analysis.cc Analysis.C `root-config --libs --cflags`
```
### Analysis::Loop()

This function is implemented in  [Analysis.C](examples/Analysis.c) and
has three main parts

##### preparing hisotgrams
```c++
  //===============================================
   // create your histograms here before looping over data
   //===============================================
   int nbins = 50;
   double x1=0.8, x2 = 1.2;
   TH1F hdx1("hdx1", "distribution of dx values",
             nbins, x1, x2 );

   TH1F hdxRMS("hdxRMS", "distribution of dx RMS for experiments",
	       nbins, 0.03, 0.08);
   hdxRMS.GetXaxis()->SetTitle("Distribution of RMS of uncertainty dx [cm]");

   TH1F hdxoverx("hdxoverx", "distribution of dx/x",
	       nbins, 0.00, 0.03);
   hdxoverx.GetXaxis()->SetTitle("Distribution of dx/x");
   hdxoverx.GetYaxis()->SetTitle(Form("Entries/%.3f",0.10/nbins) );

   TH1I hnmeas("hnmeas","Number of measurements per experiment", 21, -0.5, 20.5);
   hnmeas.GetXaxis()->SetTitle("Number of measurements");
   hnmeas.GetYaxis()->SetTitle( Form("Entries") );

   TH2F h2RMS("h2RMS", "Distribution of dx RMS vs numb. measurements",
	      21, -0.5, 20.5,
	      nbins, 0.03, 0.08 );
   h2RMS.GetXaxis()->SetTitle("Number of measurements");
   h2RMS.GetYaxis()->SetTitle("dx RMS");

   double binwidth = (x2-x1) / nbins;
   std::cout << "# bins: " << nbins << "\t bin width: " << binwidth << std::endl;
```

#### Loop over data
```c++
   //===== loop over data 
   Long64_t nentries = fChain->GetEntriesFast();
   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;

      // print info every N events
      if(jentry%100 == 0) {
	cout << "experiment: " << jentry << "\t # measurements: " << nmeas << endl;
      }

      // plot of # measurements
      hnmeas.Fill(nmeas);

      // for each experiment reset the content so RMS computed correctly
      hdxRMS.Clear();

      // for each experiment read the measurements
      for(int i = 0; i< nmeas; ++i) {
	// fill histogram
	hdx1.Fill( value[i] );
	hdxoverx.Fill( error[i]/value[i] );
 
      } // loop on mesurements

      // compute RMS for measurements in each experiment
      // and fill a histogram
      hdxRMS.Fill( hdx1.GetRMS() );
      h2RMS.Fill( nmeas, hdx1.GetRMS() );
      
	  } // end of loop over data
```

### Making plots and fitting
```c++
  // ===== make pretty plots and store them
   TCanvas canv("canv", "canvas to make plots", 1280,1024);
   gStyle->SetOptStat(111111);

   gStyle->SetMarkerStyle(21);

   hdxoverx.SetMarkerStyle(21);
   hdxoverx.SetMarkerSize(1.5);
   hdxoverx.Draw();
   canv.SaveAs("/tmp/dxoverx.pdf");

   // fit the distribution with a Gaussian
   TFitResultPtr fitres = hdxoverx.Fit("gaus","S");

   // global fit options for showing
   gStyle->SetOptFit(1111);
   
   hdxoverx.Draw("pe");
   canv.SaveAs("/tmp/dxoverx-fit.pdf");

   TF1 *fitfun = hdxoverx.GetFunction("gaus");
   fitfun->Print();
  
   // draw just the fitted functions
   fitfun->Draw();
   canv.SaveAs("/tmp/fitfun.pdf");

   // also access fit information for further analysis
   double chi2 = fitres->Chi2();
   int dof = fitres->Ndf();
   
   // mean 
   double mean = fitres->Parameter(1);
   double meanErr = fitres->ParError(1);

   cout << "Fit chi2: " << chi2 << " with dof: " << dof << "\t mean: " << mean << " +- " << meanErr << endl;
   cout << "correlation between mean and sigma: " << fitres->Correlation(1, 2) << endl;
```


# Using TTree provided by others

In this example we use a root file produced on simulated proton-proton
collisions at the CERN
[Large Hadron Collider](https://home.cern/topics/large-hadron-collider)
and using the [CMS experiment](http://cms.cern). These data are provided
as part of the CMS Open Data effort at [CERN](http://cern.ch). More details available at
[CMS Open Data Portal](http://opendata.cern.ch/search?page=1&size=20&experiment=CMS).


1. First we create the analysis class using MakeClass
```
$ root -l codTree_QCD_Pt_1400to1800.root
root [0] 
Attaching file codTree_QCD_Pt_1400to1800.root as _file0...
(TFile *) 0x7fa32c9cbf60
root [1] .ls
TFile**		codTree_QCD_Pt_1400to1800.root	
 TFile*		codTree_QCD_Pt_1400to1800.root	
  KEY: TDirectoryFile	codana;1	codana
root [2] codana->cd()
(bool) true
root [3] .ls
TDirectoryFile*		codana	codana
 KEY: TTree	codtree;1	
 root [4] codtree->MakeClass("CODAnalysis")
 ```

2. Modify the header file [CODAnalysis.C](examples/CODAnalysis.C)  to
   1. change size of static arrays
   2. change constructor
   3. change destructor to remove the `delete fchain` line

3. check that your `CODAnalysis` class code is correct by compiling it
```
g++ -c CODAnalysis.C `root-config --cflags`
```

4. Write a new application
   [03-CODanalyser.cc](examples/03-CODanalyser.cc) to use the new
   `CODAnalysis` class

5. Finally start analysing the data by changing `CODAnalysis::Loop` in
[CODAnalysis.C](examples/CODAnalysis.C)

6. Link your executable and start doing analysis
```
g++ -o /tmp/CODapp 03-CODanalyser.cc  CODAnalysis.C `root-config
--libs --cflags`
/tmp/CODapp codTree_QCD_Pt_1400to1800.root
```

## First example

In this first example we want to find out what is stored in the file
by looking at some basic variables
```c++
   // loop over events
   Long64_t nentries = fChain->GetEntriesFast();
   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;

      // generated particles 
      int nPartons = 0;
      for(int i=0; i< nGenPart; ++i) {
	// skip protons which have PDG ID = 2212
	if(pdgId_genPart[i] == 2212) continue;
	nPartons++;
	hgenPt.Fill( pt_genPart[i]);
      }
      hngenpart.Fill( nPartons );

      
      // photons
      hnphot.Fill(nPhoton);
      // loop over photons
      for(int i=0; i< nPhoton; ++i) {
	hphotE.Fill(energy_phot[i]);
	hphotPt.Fill(pt_phot[i]);
	
	hphotPos.Fill(phi_phot[i], eta_phot[i]);
	
      }   
      
   } // end of events
```
