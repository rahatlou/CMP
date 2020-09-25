// app2.cpp
#include "TH1F.h"
#include "TCanvas.h"

int main() {

  // create histogram
  TH1F h1("h1","my first historgram",100,-6.0,6.0);

  // fill histogram with 10000 random gaussian numbers
  h1.FillRandom("gaus",10000);

  // add labels to axis
  h1.GetXaxis()->SetTitle("Gaussian variable");
  h1.GetYaxis()->SetTitle("arbitrary Units");

  // create a canvas to draw tour histogram
  TCanvas c1("c1","my canvas",1024,800);

  // draw the histogram
  h1.Draw();

  // save canvas a JPG file
  c1.SaveAs("canvas.jpg");

  // change fill color to blue
  h1.SetFillColor(kBlue);

  // draw again the histogram
  h1.Draw();
  c1.SaveAs("canvas-blue.jpg");

  // dra histograms as points with errors
  h1.Draw("pe");
  
  // save canvas a PDF file
  c1.SaveAs("canvas-points.pdf");


  return 0;
}
