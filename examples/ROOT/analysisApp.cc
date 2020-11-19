// standard library header files
#include <iostream>
#include <fstream>
#include <iomanip>

// ROOT heder files
#include "TH1F.h"
#include "TCanvas.h"
#include "TTree.h"
#include "TFile.h"
#include "TString.h"
#include "TStyle.h"

// my header files
#include "DataTree.h"

int main( int argc, char* argv[]) {


  // ==== Read data from input file
  TString rootfname("/tmp/dati01.root");
  TFile* infile =  TFile::Open( rootfname );
  if( !infile->IsOpen() ) {
    std::cout << "problems opening root file. existing... " << std::endl;
    exit(-1);
  }
  std::cout << "Reading data from root file " << rootfname << std::endl;

  // get pointer to tree object stored in the file
  TTree* tree = (TTree*) infile->Get("datatree");
  if(!tree) {
    std::cout << "null pointer for TTree! exiting..." << std::endl;
    exit(-1);
  }

  // instantiate object for data analysis
  // and pass the tree pointer to the constructor
  DataTree analyser( tree );

  analyser.Loop();

  // critical to close the file!
  infile->Close();

  return 0;
}
