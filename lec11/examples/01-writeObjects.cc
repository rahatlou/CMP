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

  // generate random measurements in the range [x1,x2]
  // and uncertainties from a guassion with 5% resolution

  double x1=0.9, x2=1.1;
  double resol = 0.05;

   
  // ==== store data in a TTree

  TString rootfname("/tmp/dati.root");
  TFile* orootfile = new TFile( rootfname, "RECREATE");
  if( !orootfile->IsOpen() ) {
    std::cout << "problems creating root file. existing... " << std::endl;
    exit(-1);
  }
  std::cout << "storing output in root file " << rootfname << std::endl;

  // variables to be stored in the tree
  const int nMeasMax=200; // maxim size of static array
  double x[nMeasMax], dx[nMeasMax];
  int nmeas;

  // create the tree
  TTree* tree = new TTree("datatree","tree containg our data");
  
  // now set the info for each branch of the tree to correspond to our data
  tree->Branch("nmeas", &nmeas, "nmeas/I");
  tree->Branch("value", x,  "value[nmeas]/D"); // nmeas is the index of value[]
  tree->Branch("error", dx, "error[nmeas]/D"); // and error[] in the tree

 
  //new random generator
  TRandom1*  gen = new TRandom1();
  gen->SetSeed(0); //use machine clock

  
  // # of experiments and average # of measurements 
  int nMeasAvg=10;
  int nexp = 100;

  for(int iexp=0; iexp<nexp; iexp++) {

    // each experiment has a different # of measurements
    nmeas = gen->Poisson(nMeasAvg);
    
    if( nmeas > nMeasMax ) {
      std::cout << "WARNING: nmeas > " << nMeasMax << " your TTRee will be corrupted" << std::endl;
    }
    
    for(int i=0; i< nmeas; ++i) {
      // genarate value
      x[i] = x1 + gen->Uniform(x2-x1);
    
      //generate uncertainty based on the value
      dx[i] = gen->Gaus(x[i], x[i]*resol);        
    }

    tree->Fill(); // write the data from memory to file at end of each experiment

    
  } // end of experiments

  
  tree->Write();
   
  // critical to close the file!
  orootfile->Close();
  
  
  return 0;
}
