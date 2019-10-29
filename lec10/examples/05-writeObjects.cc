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

#include "TStyle.h" // needed to change dispaly options for stats and fit paramters

// my header files
#include "Datum.h"

int main( int argc, char* argv[]) {

  // generate random measurements in the range [x1,x2]
  // and uncertainties from a guassion with 10% width

  double x1=0.9, x2=1.1;
  double resol = 0.10;

  // create histograms
  int nbins = 100;
  double xlo = x1*(1-5*resol);
  double xhi = x2*(1+5*resol);
  double binwidth = (xhi-xlo) / nbins;
  std::cout << "# bins: " << nbins << "\t bin width: " << binwidth << std::endl;

  TH1F hx1("hx1", "distribution of true x",
       nbins, xlo, xhi );

  TH1F hdx1("hdx1", "distribution of  x uncertainty",
      nbins, -0.1 , 0.3 );

  TH1F hpull("hpull", "pull distribution",
          nbins, -6 , 6 );

  //new random generator
  TRandom3*  gen = new TRandom3();
  gen->SetSeed(0); //use machine clock


  // # measurements
  int nmeas = 1000;
  std::vector<Datum> dati;

  for(int i=0; i< nmeas; ++i) {

    // genarate true value
    double x0 = x1 + gen->Uniform(x2-x1);

    //generate meaured value based on the true value and resolution
    double x = gen->Gaus(x0, x0*resol);

    //generate an uncertainty based on the resolution
    double dx = x*resol;

    // store Datum in vector
    dati.push_back( Datum( x, dx) );

    // fill histograms
    hx1.Fill(x);
    hdx1.Fill(dx);
    hpull.Fill((x-x0)/dx);

  }


  // create canvas
  TCanvas canv("canv", "canvas for plotting", 1280, 1024);

  // show all statistical and fit parameters
  //  https://root.cern.ch/doc/master/classTPaveStats.html
  gStyle->SetOptStat(111111);
  gStyle->SetOptFit(1111);

  // make histograms nicer
  hx1.GetXaxis()->SetTitle("Distribution of x [GeV]");
  hx1.Draw();
  // make pdf file
  canv.SaveAs("/tmp/x.pdf");

  hdx1.GetXaxis()->SetTitle("Distribution of uncertainty \\deltax [GeV]");
  hdx1.Draw("pe");
  canv.SaveAs("/tmp/dx.pdf");

  // one pdf with two panels
  canv.Clear();
  canv.Divide(2,2);
  canv.cd(1);
  hx1.Fit("gaus");
  hx1.Draw();
  canv.cd(2);
  hdx1.Fit("gaus");
  hdx1.Draw("pe");
  canv.cd(3);
  hpull.GetXaxis()->SetTitle("Distribution of (x-x0)/\\deltax");
  hpull.Fit("gaus");
  hpull.Draw();
  canv.SaveAs("/tmp/plots.pdf");

  // store output on file
  std::ofstream ofile;
  std::string ofname("/tmp/dati.txt");
  std:: cout << "storing data in " << ofname << std::endl;
  ofile.open( ofname );

  for(std::vector<Datum>::const_iterator it = dati.begin(); it != dati.end(); ++it) {
    ofile << std::setprecision(5) << std::fixed ;
    ofile << it->value() << "\t" << it->error() << std::endl;
  }
  ofile.close();
  std::cout << ofname << " output file  successfully created" << std::endl;


  // find out size of dati file


  // ==== store data in a TTree

  TString rootfname("/tmp/dati.root");
  TFile* orootfile = new TFile( rootfname, "RECREATE");
  if( !orootfile->IsOpen() ) {
    std::cout << "problems creating root file. existing... " << std::endl;
    exit(-1);
  }
  std::cout << "storing output in root file " << rootfname << std::endl;


  TTree* tree = new TTree("datatree","tree containg our data");

  // variables to be stored in the tree
  double x, dx;

  // now set the info for each branch of the tree to correspond to our data
  tree->Branch("value", &x,  "value/D");
  tree->Branch("error", &dx, "error/D");

  for(std::vector<Datum>::const_iterator it = dati.begin(); it != dati.end(); ++it) {
    // assign values to  C++ variables that are going to be stored in the branch
    x = it->value();
    dx = it->error();

    tree->Fill(); // store data in tree IN MEMORY
  }

  // you can  store also additional objects to the file!
  orootfile->cd();
  hx1.Write();
  hdx1.Write();


  // now actually write tree in file on disk
  tree->Write();

  // critical to close the file!
  orootfile->Close();

  delete gen;

  return 0;
}
