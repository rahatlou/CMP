// standard library header files
#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>

// ROOT heder files
#include "TRandom3.h"

#include "TH1F.h"
#include "TCanvas.h"


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
      nbins, -5*resol , 5*resol );

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

    //generate uncertainty based on the resolution
    double dx = x*resol;

    // store Datum in vector
    dati.push_back( Datum( x, dx) );

    // fill histograms
    hx1.Fill(x);
    hdx1.Fill(dx);

  }


  // create canvas
  TCanvas canv("canv", "canvas for plotting", 1280, 1024);

  // make histograms nicer
  hx1.GetXaxis()->SetTitle("Distribution of \\deltax [GeV]");
  hx1.Draw();
  // make pdf file
  canv.SaveAs("/tmp/x.pdf");

  hdx1.GetXaxis()->SetTitle("Distribution of uncertainty \\deltax [cm]");
  hdx1.Draw("pe");
  canv.SaveAs("/tmp/dx.pdf");

  // one pdf with two panels
  canv.Clear();
  canv.Divide(1,2);
  canv.cd(1);
  hx1.Draw();
  canv.cd(2);
  hdx1.Draw("pe");
  canv.SaveAs("/tmp/plots.pdf");

  // store output on file
  std::ofstream ofile;
  std::string ofname("/tmp/dati.txt");
  std:: cout << "storing data in " << ofname << std::endl;
  ofile.open( ofname );

  for(std::vector<Datum>::const_iterator it = dati.begin(); it != dati.end(); ++it) {
    ofile << std::setprecision(3) << std::fixed ;
    ofile << it->value() << "\t" << it->error() << std::endl;
  }
  ofile.close();
  std::cout << ofname << " output file  successfully created" << std::endl;


  // find out size of dati file

  delete gen;

  return 0;
}
