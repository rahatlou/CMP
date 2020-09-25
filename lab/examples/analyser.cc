// standard library header files
#include <iostream>

// ROOT heder files
#include "TTree.h"
#include "TFile.h"
#include "TString.h"

// my header files
#include "CODAnalysis.h"

using std::cout;
using std::endl;

int main( int argc, char* argv[]) {

  // get name of root file from command line
  if(argc < 2) {
    cout << "usage: 03-CODanalyser <rootfile>" << endl;
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
  TDirectoryFile* dir = (TDirectoryFile*)rootfile->Get("codana");
  TTree* tree = (TTree*) dir->Get("codtree");
  if(!tree) {
    std::cout << "null pointer for TTree! exiting..." << std::endl;
    exit(-1);
  }

  CODAnalysis an(tree);
  // all your analysis code will be in Analysis.C
  an.Loop();

  // close root file!
  rootfile->Close();
  
  return 0;
}
