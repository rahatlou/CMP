#define Analysis_cxx
#include "Analysis.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

// additional header files needed for analysis
#include <iostream>
using std::cout;
using std::endl;
#include "TFitResultPtr.h"
#include "TFitResult.h"
#include "TF1.h"
#include "TMatrix.h"

void Analysis::Loop()
{
//   In a ROOT session, you can do:
//      root> .L Analysis.C
//      root> Analysis t
//      root> t.GetEntry(12); // Fill t data members with entry number 12
//      root> t.Show();       // Show values of entry 12
//      root> t.Show(16);     // Read and show values of entry 16
//      root> t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   if (fChain == 0) return;

   //===============================================
   // create your histograms here before looping over data
   //===============================================
   int nbins = 50;
   double x1=0.8, x2 = 1.2;
   TH1F hdx1("hdx1", "distribution of dx values",
             nbins, x1, x2 );

   TH1F hdxRMS("hdxRMS", "distribution of dx RMS for experiments",
	       nbins, 0.03, 0.08);
   hdxRMS.GetXaxis()->SetTitle("Distribution of RMS of uncertainty dx [cm]");

   TH1F hdxoverx("hdxoverx", "distribution of dx/x",
	       nbins, 0.00, 0.03);
   hdxoverx.GetXaxis()->SetTitle("Distribution of dx/x");
   hdxoverx.GetYaxis()->SetTitle(Form("Entries/%.3f",0.10/nbins) );

   TH1I hnmeas("hnmeas","Number of measurements per experiment", 21, -0.5, 20.5);
   hnmeas.GetXaxis()->SetTitle("Number of measurements");
   hnmeas.GetYaxis()->SetTitle( Form("Entries") );

   TH2F h2RMS("h2RMS", "Distribution of dx RMS vs numb. measurements",
	      21, -0.5, 20.5,
	      nbins, 0.03, 0.08 );
   h2RMS.GetXaxis()->SetTitle("Number of measurements");
   h2RMS.GetYaxis()->SetTitle("dx RMS");

   double binwidth = (x2-x1) / nbins;
   std::cout << "# bins: " << nbins << "\t bin width: " << binwidth << std::endl;


   //===== loop over data 
   Long64_t nentries = fChain->GetEntriesFast();
   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;

      // print info every N events
      if(jentry%100 == 0) {
	cout << "experiment: " << jentry << "\t # measurements: " << nmeas << endl;
      }

      // plot of # measurements
      hnmeas.Fill(nmeas);

      // for each experiment reset the content so RMS computed correctly
      hdxRMS.Clear();

      // for each experiment read the measurements
      for(int i = 0; i< nmeas; ++i) {
	// fill histogram
	hdx1.Fill( value[i] );
	hdxoverx.Fill( error[i]/value[i] );
 
      } // loop on mesurements

      // compute RMS for measurements in each experiment
      // and fill a histogram
      hdxRMS.Fill( hdx1.GetRMS() );
      h2RMS.Fill( nmeas, hdx1.GetRMS() );
      
   } // end of loop over data


   // ===== make pretty plots and store them
   TCanvas canv("canv", "canvas to make plots", 1280,1024);
   gStyle->SetOptStat(111111);

   gStyle->SetMarkerStyle(21);

   hdxoverx.SetMarkerStyle(21);
   hdxoverx.SetMarkerSize(1.5);
   hdxoverx.Draw();
   canv.SaveAs("/tmp/dxoverx.pdf");

   // fit the distribution with a Gaussian
   TFitResultPtr fitres = hdxoverx.Fit("gaus","S");

   // global fit options for showing
   gStyle->SetOptFit(1111);
   
   hdxoverx.Draw("pe");
   canv.SaveAs("/tmp/dxoverx-fit.pdf");

   TF1 *fitfun = hdxoverx.GetFunction("gaus");
   fitfun->Print();
  
   // draw just the fitted functions
   fitfun->Draw();
   canv.SaveAs("/tmp/fitfun.pdf");

   // also access fit information for further analysis
   double chi2 = fitres->Chi2();
   int dof = fitres->Ndf();
   
   // mean 
   double mean = fitres->Parameter(1);
   double meanErr = fitres->ParError(1);

   cout << "Fit chi2: " << chi2 << " with dof: " << dof << "\t mean: " << mean << " +- " << meanErr << endl;
   cout << "correlation between mean and sigma: " << fitres->Correlation(1, 2) << endl;

 
   
}
