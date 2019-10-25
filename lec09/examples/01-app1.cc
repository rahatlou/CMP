// standard library header files
#include <vector>

// ROOT heder files
#include "TRandom3.h"

#include "TH1F.h"
#include "TCanvas.h"


// my header files

int main( int argc, char* argv[]) {

  // generate random measurements in the range [x1,x2]
  // and uncertainties from a guassion with 5% resolution

  double x1=0.9, x2=1.1;
  double resol = 0.05;

  // create histograms
  int nbins = 50;
  TH1F hx1("hx1", "distribution of x values",
	     nbins, x1*(1-5*resol), x2*(1+5*resol) );

  TH1F hdx1("hdx1", "distribution of x uncdertainties",
	    nbins, x1*(1-5*resol), x2*(1+5*resol) );

  double binwidth = (x2*(1+5*resol)-x1*(1-5*resol)) / nbins;

  //new random generator
  TRandom3*  gen = new TRandom3();
  gen->SetSeed(0); //use machine clock

  // # measurements
  int nmeas = 100;

  for(int i=0; i< nmeas; ++i) {


    // genarate value
    double x = x1 + gen->Uniform(x2-x1);

    //generate uncertainty based on the value
    double dx = gen->Gaus(x, x*resol);

    // fill histograms
    hx1.Fill(x);
    hdx1.Fill(dx);

  }


  // create canvas
  TCanvas canv("canv", "canvas for plotting", 1280, 1024);

  hx1.Draw();
  canv.SaveAs("/tmp/x.pdf");

  hdx1.Draw();
  canv.SaveAs("/tmp/dx.pdf");


  return 0;
}
