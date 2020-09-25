// standard library header files
#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>

// ROOT heder files
#include "TRandom3.h"
#include "TH1F.h"
#include "TCanvas.h"
#include "TTree.h"
#include "TFile.h"
#include "TString.h"

// my header files
#include "Datum.h"

int main( int argc, char* argv[]) {

  // generate random measurements in the range [x1,x2]
  // and uncertainties from a guassion with 5% resolution

  double x1=0.9, x2=1.1;
  double resol = 0.10;


  // ==== store data in a TTree

  TString rootfname("/tmp/dati.root");
  TFile* orootfile = new TFile( rootfname, "RECREATE");
  if( !orootfile->IsOpen() ) {
    std::cout << "problems creating root file. existing... " << std::endl;
    exit(-1);
  }
  std::cout << "storing output in root file " << rootfname << std::endl;

  // create the tree
  TTree* tree = new TTree("datatree","tree containg our data");

  // variables to be stored in the tree
  const int nMeasMax=200; // maximum size of static array per event
  double x0, x[nMeasMax], dx[nMeasMax];
  int nmeas;

  // now set the info for each branch of the tree to correspond to our data
  tree->Branch("nmeas", &nmeas, "nmeas/I");
  tree->Branch("value", x,  "value[nmeas]/D"); // nmeas is the index of value[]
  tree->Branch("error", dx, "error[nmeas]/D"); // and error[] in the tree


  //new random generator
  TRandom3*  gen = new TRandom3();
  gen->SetSeed(0); //use machine clock

  // # measurements
  int nMeasAvg=50;
  int nexp = 1000;


  for(int iexp=0; iexp<nexp; iexp++) {


    nmeas = gen->Poisson(nMeasAvg);

    if( nmeas > nMeasMax ) {
      std::cout << "WARNING: nmeas > " << nMeasMax << " your TTRee will be corrupted" << std::endl;
    }

    for(int i=0; i< nmeas; ++i) {

      // genarate true value
      x0 = x1 + gen->Uniform(x2-x1);

      //generate meaured value based on the true value and resolution
      x[i] = gen->Gaus(x0, x0*resol);

      //generate an uncertainty based on the resolution
      dx[i] = x[i]*resol;
    }

    tree->Fill(); // write the data from memory to file at end of each experiment


  } // end of experiments
  tree->Write();


  // critical to close the file!
  orootfile->Close();


  return 0;
}
