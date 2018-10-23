// standard library header files
#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>

// ROOT heder files
#include "TRandom1.h"
#include "TH1F.h"
#include "TCanvas.h"
#include "TTree.h"
#include "TFile.h"
#include "TString.h"

// my header files
#include "Datum.h"

int main( int argc, char* argv[]) {

    // create histograms
  int nbins = 50;
  double x1 = 0.5, x2 = 1.5;
  double binwidth = (x2-x1) / nbins;

  TH1F hx1("hx1", "distribution of x values",
	     nbins, x1, x2 );

  // use TString::Form() function to add correct y axis label with bin width 
  hx1.GetYaxis()->SetTitle(Form("entries/%.3f cm", binwidth));

  TH1F hdx1("hdx1", "distribution of x uncdertainties",
	    nbins, x1, x2 );

  std::cout << "# bins: " << nbins << "\t bin width: " << binwidth << std::endl;

  hdx1.GetYaxis()->SetTitle(Form("entries/%.3f cm", binwidth));
  
  // ==== Read data from file 

  TString rootfname("/tmp/dati.root");
  TFile* orootfile = new TFile( rootfname );
  if( !orootfile->IsOpen() ) {
    std::cout << "problems opdening root file. existing... " << std::endl;
    exit(-1);
  }
  std::cout << "Reading data from root file " << rootfname << std::endl;

  // get pointer to tree object stored in the file
  TTree* tree = (TTree*) orootfile->Get("datatree");
  if(!tree) {
    std::cout << "null pointer for TTree! exiting..." << std::endl;
    exit(-1);
  }
  
  // Pointer to a Datum object to be read from Branch
  Datum* d=0;
  
  // now set the info for each branch of the tree to correspond to our data
  tree->SetBranchAddress("datum", &d);

  // vector of Datum for our data being read
  std::vector<Datum> dati;

  int nentries = tree->GetEntries();
  for (int i=0; i<nentries; ++i) {
    tree->GetEntry(i); // read data from file to memory
    
    hx1.Fill( d->value() );
    hdx1.Fill ( d->error() );

    // Fill our Datum vector for later use
    dati.push_back( *d );
  }


  // ==== make plots
 
  hx1.GetXaxis()->SetTitle("Distribution of x [cm]");
  hdx1.GetXaxis()->SetTitle("Distribution of uncertainty dx [cm]");
 
  // one pdf with two panels
  // create canvas
  TCanvas canv("canv", "canvas for plotting", 1280, 1024);
  canv.Divide(1,2);
  canv.cd(1);
  hx1.SetFillColor(kRed);
  hx1.Draw();
  canv.cd(2);
  //hdx1.SetMarkerType(22);
  hdx1.Draw("pe");
  canv.SaveAs("/tmp/newplots.pdf");


  // critical to close the file!
  orootfile->Close();
  
  return 0;
}
