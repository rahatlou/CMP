// standard library header files
#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>

// ROOT heder files
#include "TH1F.h"
#include "TCanvas.h"
#include "TTree.h"
#include "TFile.h"
#include "TString.h"

// my header files
#include "Datum.h"

int main( int argc, char* argv[]) {

  double x1=0.9, x2=1.1;
  double resol = 0.10;

  // create histograms
  int nbins = 50;
  double xlo = x1*(1-5*resol);
  double xhi = x2*(1+5*resol);
  double binwidth = (xhi-xlo) / nbins;
  TH1F hx1("hx1", "distribution of value",
	     nbins, xlo, xhi );

  TH1F hdx1("hdx1", "distribution of error",
	    nbins, -0.1, 0.4 );

  std::cout << "# bins: " << nbins << "\t bin width: " << binwidth << std::endl;

  // ==== Read data from file

  TString rootfname("/tmp/dati.root");
  TFile* orootfile = new TFile( rootfname );
  if( !orootfile->IsOpen() ) {
    std::cout << "problems opening root file. existing... " << std::endl;
    exit(-1);
  }
  std::cout << "Reading data from root file " << rootfname << std::endl;

  // get pointer to tree object stored in the file
  TTree* tree = (TTree*) orootfile->Get("datatree");
  if(!tree) {
    std::cout << "null pointer for TTree! exiting..." << std::endl;
    exit(-1);
  }

  // variables to be read from the tree
  double y, dy;

  // now set the info for each branch of the tree to correspond to our data
  tree->SetBranchAddress("value", &y);
  tree->SetBranchAddress("error", &dy);

  // vector of Datum for our data being read
  std::vector<Datum> dati;


  int nentries = tree->GetEntries();
  for (int i=0; i<nentries; ++i) {
    tree->GetEntry(i); // read data from file to memory

    // populate our Datum object
    dati.push_back( Datum(y, dy) );

    hx1.Fill(y);
    hdx1.Fill (dy);
  }


  // ==== make plots

  hx1.GetXaxis()->SetTitle("Distribution of x [GeV]");
  hdx1.GetXaxis()->SetTitle("Distribution of \\deltax [GeV]");

  // one pdf with two panels
  // create canvas
  TCanvas canv("canv", "canvas for plotting", 1280, 1024);
  canv.Divide(1,2);
  canv.cd(1);
  hx1.Fit("gaus");
  hx1.Draw();
  canv.cd(2);
  hdx1.Fit("gaus");
  hdx1.Draw("pe");
  canv.SaveAs("/tmp/newplots.pdf");


  // critical to close the file!
  orootfile->Close();

  return 0;
}
