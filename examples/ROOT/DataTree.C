#define DataTree_cxx
#include "DataTree.h"
#include "TH2.h"
#include "TStyle.h"
#include "TCanvas.h"

#include <iostream>
#include "TH1F.h"
#include "TCanvas.h"
#include "TPaveStats.h"

void DataTree::Loop()
{
   if (fChain == 0) return;

   // create a new TFile to store output
   // this is a different file from the one where the inout data is stored
   TFile outfile("/tmp/analysis.root","RECREATE");

   // book histograms
   TH1F  hx("hx","distribution of all x", 50, 0.4, 1.8);
   TH1F  hxmean("hxmean","distribution of average x per experiment", 50, 0.9, 1.1);

   TH1F  hdx("hdx","distribution of all \\deltax", 50, 0., 0.1);
   TH1F  hdxstdev("hdxstdev","distribution of Std. Dev of \\deltax per experiment", 50, 0., 0.01);

   TH1F  hxSmalldx("hxSmalldx","distribution of all x with small errors", 100, 0.5, 2.5);

   TH2F  hdxvsxall("hdxvsxall", "\\deltax vs x",50, 0.4, 1.8, 50, 0., 0.1 );


   // loop over events in the tree
   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;

      // ---- add your code here to do analysis with data in the Tree
      if(jentry%5==0) std::cout << "processing event: " << jentry << std::endl;

      // reset histograms to compute mean and std Dev
      //hx->Clear();
      hx.Clear();
      hdx.Clear();

      // loop over measurements in this event
      for(int im=0; im < nmeas; im++) {
        // fill histos to compute mean and stdev for each experiment/event
        //hx->Fill(value[im]);
        hx.Fill(value[im]);
        hdx.Fill(error[im]);

        hdxvsxall.Fill( value[im], error[im] );

        // only plot value for small errors
        if(error[im]<0.05) hxSmalldx.Fill(value[im]);
      }

      // fill histo with info for each event/experiment
      hxmean.Fill( hx.GetMean() );
      hdxstdev.Fill( hdx.GetStdDev() );

      // --- end of analysis code
   } // end of event Loop


   // make newplots
   TCanvas* c1 = new TCanvas("c1","canvas", 1280,1024);
   c1->Divide(2,2);
   gStyle->SetOptStat(111111);

   c1->cd(1);

   hxmean.Draw();

   c1->cd(2);
   hdxstdev.Draw();

   c1->cd(3);
   hxSmalldx.Draw();

   c1->cd(4);
   hdxvsxall.Draw("colz3");

   c1->SaveAs("/tmp/analysisPlots.pdf");

  // write objects to output file
  hxmean.Write();
  hdxstdev.Write();
  hxSmalldx.Write();
  hdxvsxall.Write();
  c1->Write();

  // close outout file
  outfile.Close();

}
