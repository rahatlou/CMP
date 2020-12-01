#define CODAnalysis_cxx
#include "CODAnalysis.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TLorentzVector.h>


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

   double massMax(13000), massMin(6000);
   int massN(100);

   TH1F hmass("hmass","Event Invariant mass",massN, massMin, massMax);
   hmass.GetXaxis()->SetTitle("event invariant mass [GeV]");
   double wm = (massMax-massMin)/massN;
   hmass.GetYaxis()->SetTitle(Form("#entries/%.1f GeV", wm));

   TH1F hpp("hpp","pp Invariant mass",massN, massMin, massMax);
   hpp.GetXaxis()->SetTitle("p-p invariant mass [GeV]");
   hpp.GetYaxis()->SetTitle(Form("#entries/%.1f GeV", wm));


   // loop over events
   Long64_t nentries = fChain->GetEntriesFast();
   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;


      // tot P4
      TLorentzVector pTot, pPP;

      // generated particles
      int nPartons = 0;
      for(int i=0; i< nGenPart; ++i) {
        // skip protons which have PDG ID = 2212
       	if(pdgId_genPart[i] == 2212) {
          TLorentzVector p;
          double eta = eta_genPart[i];
          if(eta>0) { eta = 100;} else {eta = -100;}
          p.SetPtEtaPhiE(pt_genPart[i],eta,phi_genPart[i],energy_genPart[i]);
          std::cout << "proton: " << pt_genPart[i] << "\t" << eta_genPart[i]
                    <<"\t" << phi_genPart[i] << "\t" << energy_genPart[i] << std::endl;
          pPP += p;
          continue;
        }
       	nPartons++;
	      hgenPt.Fill( pt_genPart[i]);

        TLorentzVector pi;
        pi.SetPtEtaPhiE(pt_genPart[i],eta_genPart[i],phi_genPart[i],energy_genPart[i]);
        pTot += pi;
      }
      hngenpart.Fill( nPartons );
      hmass.Fill(pTot.M());
      hpp.Fill(pPP.M());
      std::cout << "PP invariant mass: " << pPP.M() << std::endl;

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

   hmass.Draw();
   canv.SaveAs("/tmp/eventmass.pdf");

   hpp.Draw();
   canv.SaveAs("/tmp/ppmass.pdf");


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
