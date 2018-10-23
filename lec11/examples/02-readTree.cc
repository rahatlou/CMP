// standard library header files
#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>

// ROOT heder files
#include "TRandom1.h"
#include "TH1F.h"
#include "TH2F.h"

#include "TCanvas.h"
#include "TTree.h"
#include "TFile.h"
#include "TString.h"
#include "TStyle.h"

// my header files
#include "Datum.h"

int main( int argc, char* argv[]) {

    // create histograms
  int nbins = 50;
  double x1 = 0.5, x2 = 1.5;
  TH1F hdx1("hdx1", "distribution of dx values",
	     nbins, x1, x2 );

  TH1F hdxRMS("hdxRMS", "distribution of dx RMS in all experiments",
	    nbins, 0.05, 0.10 );

  double binwidth = (x2-x1) / nbins;
  std::cout << "# bins: " << nbins << "\t bin width: " << binwidth << std::endl;
 
  
  TH1I hnmeas("hnmeas","Number of measurements per experiment", 21, -0.5, 20.5);
  TH2F h2RMS("h2RMS", "Distribution of dx RMS vs numb. measurements",
	     21, -0.5, 20.5,
	     nbins, 0.05, 0.10 );
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
  
  // variables to be read from the tree
  // You need to define maximum number of cells in the array
  // this is *UGLY* but necessary
  const int nMeasMax = 200; 
  double y[nMeasMax], dy[nMeasMax];
  int nmeas;
  
  // now set the info for each branch of the tree to correspond to our data
  tree->SetBranchAddress("value", y);
  tree->SetBranchAddress("error", dy);
  tree->SetBranchAddress("nmeas", &nmeas);

  int nentries = tree->GetEntries();
  for (int iexp=0; iexp<nentries; ++iexp) {
    tree->GetEntry(iexp); // read data from file to memory

    // vector of Datum in case you want to use your Datum class
    std::vector<Datum> dati;

    // plot of # measurements
    hnmeas.Fill(nmeas);
    
    // for each experiment read the measurements
    for(int i = 0; i< nmeas; ++i) {
      dati.push_back( Datum(y[i], dy[i]) );
      // fill histogram
      hdx1.Fill( dy[i] );
      

    } // loop on mesurements

    // compute RMS for measurements in each experiment
    // and fill a histogram
    hdxRMS.Fill( hdx1.GetRMS() );
    h2RMS.Fill(nmeas, hdx1.GetRMS() );
    
  } // end of experiments


  // ==== make plots

  // useful plot settings
  gStyle->SetOptStat(111111); // show over and underflow
  

  // create canvas
  TCanvas canv("canv", "canvas for plotting", 1280, 1024);
  h2RMS.GetXaxis()->SetTitle("Number of measurements");
  h2RMS.GetYaxis()->SetTitle("dx RMS");
  h2RMS.Draw("box");
  canv.SaveAs("/tmp/2dRMS.pdf");


  canv.Clear();
  canv.Divide(1,2);
  canv.cd(1);
  hnmeas.GetXaxis()->SetTitle("Number of measurements");
  hnmeas.Draw("");

  canv.cd(2);
  hdxRMS.GetXaxis()->SetTitle("Distribution of RMS of uncertainty dx");
 hdxRMS.Draw("pe");

  canv.SaveAs("/tmp/expplots.pdf");

  
  // critical to close the file!
  orootfile->Close();
  
  
  return 0;
}
