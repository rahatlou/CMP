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

#ifdef __MAKECINT__
#pragma link C++ class Datum+;
#endif

int main( int argc, char* argv[]) {

  // generate random measurements in the range [x1,x2]
  // and uncertainties from a guassion

  double x1=0.9, x2=1.1;
  double resol = 0.15;


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
  Datum  dato;

  // now set the info for each branch of the tree to correspond to our data
  tree->Branch("datum", &dato);

  int nmeas = 100;

  //new random generator
  TRandom1*  gen = new TRandom1();
  gen->SetSeed(0); //use machine clock

  for(int i=0; i< nmeas; ++i) {
    // genarate value
    double x0 = x1 + gen->Uniform(x2-x1);
    double x = gen->Gaus(x0 , x0*resol);
    double err =  (x2-x1)/sqrt(12);
    dato = Datum( x,  gen->Gaus(err , err*0.10) );

    // add leaf to the  tree
    tree->Fill();
  }


  tree->Write();


  // critical to close the file!
  orootfile->Close();


  return 0;
}
