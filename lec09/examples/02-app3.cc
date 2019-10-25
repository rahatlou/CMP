// standard library header files
#include <iostream>

// ROOT heder files
#include "TRandom3.h"

#include "TH1F.h"
#include "TCanvas.h"

#include "TFile.h"


// my header files

int main( int argc, char* argv[]) {

  // Open TFile for output. Overwite output file if it already exists
  TString rootfname("/tmp/output.root");
  TFile rfile( rootfname, "RECREATE");
  if( !rfile.IsOpen() ) {
    std::cout << "problems creating root file. existing... " << std::endl;
    exit(-1);
  }
  std::cout << "storing output in root file " << rootfname << std::endl;



  // generate random true value in the range [x1,x2]
  // generate the measurement by accounting for a guassion resolution of 5%

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

  TH1F hdx1("hdx1", "distribution of measured x",
	    nbins, xlo , xhi );


  //new random generator
  TRandom3*  gen = new TRandom3();
  gen->SetSeed(0); //use machine clock

  // # measurements
  int nsig = 1000;

  for(int i=0; i< nsig; ++i) {


    // genarate true value
    double x = x1 + gen->Uniform(x2-x1);

    //generate meaured value based on the true value and resolution
    double dx = gen->Gaus(x, x*resol);

    // fill histograms
    hx1.Fill(x);
    hdx1.Fill(dx);

  }


  // create canvas
  TCanvas canv("canv", "canvas for plotting", 1280, 1024);

  // make histograms nicer and store to file
  hx1.GetXaxis()->SetTitle("Distribution of x [GeV]");
  hx1.Draw();
  canv.SaveAs("/tmp/x.pdf");

  hdx1.GetXaxis()->SetTitle("Distribution of uncertainty \\Delta x [GeV]");
  hdx1.Draw("pe"); // show points with error bars
  canv.SaveAs("/tmp/dx.pdf");


  // fit histogram with predefined Gaussian function
  hdx1.Fit("gaus");
  hdx1.Draw();
  canv.SaveAs("/tmp/dxfit.pdf");

  // delete the random generator
  delete gen;

  // store histograms to file
  hx1.Write();
  hdx1.Write();

  // close root file
  rfile.Close();

  return 0;
}
