#define CODAnalysis_cxx
#include "CODAnalysis.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void CODAnalysis::Loop()
{
//   In a ROOT session, you can do:
//      root> .L CODAnalysis.C
//      root> CODAnalysis t
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



   // === prepare histograms
   TH1F hnphot("hnphot", " Number of photon candidates", 11, -0.5, 10.5);
   TH1F hphotE("hphotE", " Energy of photons", 100, 0., 1000.);
   hphotE.GetXaxis()->SetTitle("energy [GeV]");

   TH1F hphotPt("hphotPt", " Transverse momentum of photons", 100, 0., 1000.);
   hphotPt.GetXaxis()->SetTitle("pt [GeV]");
  TH2F hphotPos("hphotPos", " Phi vs eta map", 100, - 3.14, 3.14, 100, -5, 5.);
  hphotPos.GetXaxis()->SetTitle("#eta");
  hphotPos.GetYaxis()->SetTitle("#phi [rad]");


   TH1F hngenpart("hnpart", " Number of generated photons", 11, -0.5, 10.5);
   TH1F hgenPt("hgenPt", " Transverse momentum of generated particles", 100, 0., 4000.);
   hgenPt.GetXaxis()->SetTitle("p_{t} [GeV]");


   // loop over events
   Long64_t nentries = fChain->GetEntriesFast();
   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;

      // generated particles 
      int nPartons = 0;
      for(int i=0; i< nGenPart; ++i) {
	// skip protons which have PDG ID = 2212
	if(pdgId_genPart[i] == 2212) continue;
	nPartons++;
	hgenPt.Fill( pt_genPart[i]);
      }
      hngenpart.Fill( nPartons );

      
      // photons
      hnphot.Fill(nPhoton);
      // loop over photons
      for(int i=0; i< nPhoton; ++i) {
	hphotE.Fill(energy_phot[i]);
	hphotPt.Fill(pt_phot[i]);
	
	hphotPos.Fill(phi_phot[i], eta_phot[i]);
	
      }   
      
   } // end of events


   TCanvas canv("canv","", 1280, 1024);
   gStyle->SetOptStat(111111);
   gStyle->SetOptFit(1111);

   // make plots
   canv.Divide(2,2);
   canv.cd(1);
   hnphot.Draw();

   canv.cd(2);
   hphotE.Draw();

   canv.cd(3);
   hphotPos.Draw("box");

   canv.cd(4);
   hphotPt.Draw("");

   canv.SaveAs("/tmp/photons.pdf");

   // plots for generated particles
   canv.Clear();
   canv.Divide(1,2);
   canv.cd(1);
   hngenpart.Draw();

   canv.cd(2);
   hgenPt.Draw();

   canv.SaveAs("/tmp/genparticles.pdf");

   canv.Clear();
   canv.SetLogy();
   hgenPt.Draw();

   canv.SaveAs("/tmp/genparticles-log.pdf");

   
}
