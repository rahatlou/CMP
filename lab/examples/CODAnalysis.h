//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Fri Oct 26 09:48:04 2018 by ROOT version 6.14/00
// from TTree codtree/
// found on file: codTree_QCD_Pt_1400to1800.root
//////////////////////////////////////////////////////////

#ifndef CODAnalysis_h
#define CODAnalysis_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class CODAnalysis {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Int_t           event;
   Int_t           run;
   Int_t           lumi;
   Float_t         rho;
   Int_t           nVert;
   Int_t           nPU;
   Int_t           nGenPart;
   Float_t         pt_genPart[100];   //[nGenPart]
   Float_t         eta_genPart[100];   //[nGenPart]
   Float_t         phi_genPart[100];   //[nGenPart]
   Float_t         energy_genPart[100];   //[nGenPart]
   Float_t         mass_genPart[100];   //[nGenPart]
   Int_t           pdgId_genPart[100];   //[nGenPart]
   Int_t           nPhoton;
   Float_t         pt_phot[100];   //[nPhoton]
   Float_t         eta_phot[100];   //[nPhoton]
   Float_t         phi_phot[100];   //[nPhoton]
   Float_t         energy_phot[100];   //[nPhoton]
   Float_t         eRaw_phot[100];   //[nPhoton]
   Float_t         eSC_phot[100];   //[nPhoton]
   Float_t         e1x5_phot[100];   //[nPhoton]
   Float_t         e2x5_phot[100];   //[nPhoton]
   Float_t         e3x3_phot[100];   //[nPhoton]
   Float_t         e5x5_phot[100];   //[nPhoton]
   Float_t         maxEnergyXtal_phot[100];   //[nPhoton]
   Float_t         sigmaEtaEta_phot[100];   //[nPhoton]
   Float_t         sigmaIetaIeta_phot[100];   //[nPhoton]
   Float_t         r1x5_phot[100];   //[nPhoton]
   Float_t         r2x5_phot[100];   //[nPhoton]
   Float_t         r9_phot[100];   //[nPhoton]
   Float_t         hOverE_phot[100];   //[nPhoton]
   Float_t         hTowOverE_phot[100];   //[nPhoton]
   Float_t         ecalRecHitSumEtConeDR04_phot[100];   //[nPhoton]
   Float_t         hcalTowerSumEtConeDR04_phot[100];   //[nPhoton]
   Float_t         hcalTowerSumEtBcConeDR04_phot[100];   //[nPhoton]
   Float_t         trkSumPtSolidConeDR04_phot[100];   //[nPhoton]
   Float_t         trkSumPtHollowConeDR04_phot[100];   //[nPhoton]
   Int_t           nTrkSolidConeDR04_phot[100];   //[nPhoton]
   Int_t           nTrkHollowConeDR04_phot[100];   //[nPhoton]
   Float_t         ecalRecHitSumEtConeDR03_phot[100];   //[nPhoton]
   Float_t         hcalTowerSumEtConeDR03_phot[100];   //[nPhoton]
   Float_t         hcalTowerSumEtBcConeDR03_phot[100];   //[nPhoton]
   Float_t         trkSumPtSolidConeDR03_phot[100];   //[nPhoton]
   Float_t         trkSumPtHollowConeDR03_phot[100];   //[nPhoton]
   Int_t           nTrkSolidConeDR03_phot[100];   //[nPhoton]
   Int_t           nTrkHollowConeDR03_phot[100];   //[nPhoton]
   Float_t         chIsoPF_phot[100];   //[nPhoton]
   Float_t         nhIsoPF_phot[100];   //[nPhoton]
   Float_t         phIsoPF_phot[100];   //[nPhoton]
   Bool_t          hasPixelSeed_phot[100];   //[nPhoton]
   Int_t           nEcalRecHit;
   Int_t           iPhi_ecalRecHit[10000];   //[nEcalRecHit]
   Int_t           iEta_ecalRecHit[10000];   //[nEcalRecHit]
   Float_t         energy_ecalRecHit[10000];   //[nEcalRecHit]
   Int_t           nPFCand;
   Float_t         pt_pfCand[10000];   //[nPFCand]
   Float_t         eta_pfCand[10000];   //[nPFCand]
   Float_t         phi_pfCand[10000];   //[nPFCand]
   Float_t         energy_pfCand[10000];   //[nPFCand]
   Float_t         mass_pfCand[10000];   //[nPFCand]
   Int_t           pdgId_pfCand[10000];   //[nPFCand]
   Int_t           nCaloTower;
   Float_t         pt_caloTower[5000];   //[nCaloTower]
   Float_t         eta_caloTower[5000];   //[nCaloTower]
   Float_t         phi_caloTower[5000];   //[nCaloTower]
   Float_t         mass_caloTower[5000];   //[nCaloTower]
   Float_t         energy_caloTower[5000];   //[nCaloTower]
   Float_t         emEnergy_caloTower[5000];   //[nCaloTower]
   Float_t         hadEnergy_caloTower[5000];   //[nCaloTower]
   Float_t         outerEnergy_caloTower[5000];   //[nCaloTower]

   // List of branches
   TBranch        *b_event;   //!
   TBranch        *b_run;   //!
   TBranch        *b_lumi ;   //!
   TBranch        *b_rho;   //!
   TBranch        *b_nVert;   //!
   TBranch        *b_nPU;   //!
   TBranch        *b_nGenPart;   //!
   TBranch        *b_pt_genPart;   //!
   TBranch        *b_eta_genPart;   //!
   TBranch        *b_phi_genPart;   //!
   TBranch        *b_energy_genPart;   //!
   TBranch        *b_mass_genPart;   //!
   TBranch        *b_pdgId_genPart;   //!
   TBranch        *b_nPhoton;   //!
   TBranch        *b_pt_phot;   //!
   TBranch        *b_eta_phot;   //!
   TBranch        *b_phi_phot;   //!
   TBranch        *b_energy_phot;   //!
   TBranch        *b_eRaw_phot;   //!
   TBranch        *b_eSC_phot;   //!
   TBranch        *b_e1x5_phot;   //!
   TBranch        *b_e2x5_phot;   //!
   TBranch        *b_e3x3_phot;   //!
   TBranch        *b_e5x5_phot;   //!
   TBranch        *b_maxEnergyXtal_phot;   //!
   TBranch        *b_sigmaEtaEta_phot;   //!
   TBranch        *b_sigmaIetaIeta_phot;   //!
   TBranch        *b_r1x5_phot;   //!
   TBranch        *b_r2x5_phot;   //!
   TBranch        *b_r9_phot;   //!
   TBranch        *b_hOverE_phot;   //!
   TBranch        *b_hTowOverE_phot;   //!
   TBranch        *b_ecalRecHitSumEtConeDR04_phot;   //!
   TBranch        *b_hcalTowerSumEtConeDR04_phot;   //!
   TBranch        *b_hcalTowerSumEtBcConeDR04_phot;   //!
   TBranch        *b_trkSumPtSolidConeDR04_phot;   //!
   TBranch        *b_trkSumPtHollowConeDR04_phot;   //!
   TBranch        *b_nTrkSolidConeDR04_phot;   //!
   TBranch        *b_nTrkHollowConeDR04_phot;   //!
   TBranch        *b_ecalRecHitSumEtConeDR03_phot;   //!
   TBranch        *b_hcalTowerSumEtConeDR03_phot;   //!
   TBranch        *b_hcalTowerSumEtBcConeDR03_phot;   //!
   TBranch        *b_trkSumPtSolidConeDR03_phot;   //!
   TBranch        *b_trkSumPtHollowConeDR03_phot;   //!
   TBranch        *b_nTrkSolidConeDR03_phot;   //!
   TBranch        *b_nTrkHollowConeDR03_phot;   //!
   TBranch        *b_chIsoPF_phot;   //!
   TBranch        *b_nhIsoPF_phot;   //!
   TBranch        *b_phIsoPF_phot;   //!
   TBranch        *b_hasPixelSeed_phot;   //!
   TBranch        *b_nEcalRecHit;   //!
   TBranch        *b_iPhi_ecalRecHit;   //!
   TBranch        *b_iEta_ecalRecHit;   //!
   TBranch        *b_energy_ecalRecHit;   //!
   TBranch        *b_nPFCand;   //!
   TBranch        *b_pt_pfCand;   //!
   TBranch        *b_eta_pfCand;   //!
   TBranch        *b_phi_pfCand;   //!
   TBranch        *b_energy_pfCand;   //!
   TBranch        *b_mass_pfCand;   //!
   TBranch        *b_pdgId_pfCand;   //!
   TBranch        *b_nCaloTower;   //!
   TBranch        *b_pt_caloTower;   //!
   TBranch        *b_eta_caloTower;   //!
   TBranch        *b_phi_caloTower;   //!
   TBranch        *b_mass_caloTower;   //!
   TBranch        *b_energy_caloTower;   //!
   TBranch        *b_emEnergy_caloTower;   //!
   TBranch        *b_hadEnergy_caloTower;   //!
   TBranch        *b_outerEnergy_caloTower;   //!

   CODAnalysis(TTree *tree=0);
   virtual ~CODAnalysis();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef CODAnalysis_cxx

#include <iostream>

CODAnalysis::CODAnalysis(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
     std::cout << "CODAnalysis::CODAnalysis : No tree provided. exiting now! " << std::endl;
   }
   Init(tree);
}

CODAnalysis::~CODAnalysis()
{
   if (!fChain) return;
   //delete fChain->GetCurrentFile();
}

Int_t CODAnalysis::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t CODAnalysis::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void CODAnalysis::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("event", &event, &b_event);
   fChain->SetBranchAddress("run", &run, &b_run);
   fChain->SetBranchAddress("lumi", &lumi, &b_lumi );
   fChain->SetBranchAddress("rho", &rho, &b_rho);
   fChain->SetBranchAddress("nVert", &nVert, &b_nVert);
   fChain->SetBranchAddress("nPU", &nPU, &b_nPU);
   fChain->SetBranchAddress("nGenPart", &nGenPart, &b_nGenPart);
   fChain->SetBranchAddress("pt_genPart", pt_genPart, &b_pt_genPart);
   fChain->SetBranchAddress("eta_genPart", eta_genPart, &b_eta_genPart);
   fChain->SetBranchAddress("phi_genPart", phi_genPart, &b_phi_genPart);
   fChain->SetBranchAddress("energy_genPart", energy_genPart, &b_energy_genPart);
   fChain->SetBranchAddress("mass_genPart", mass_genPart, &b_mass_genPart);
   fChain->SetBranchAddress("pdgId_genPart", pdgId_genPart, &b_pdgId_genPart);
   fChain->SetBranchAddress("nPhoton", &nPhoton, &b_nPhoton);
   fChain->SetBranchAddress("pt_phot", pt_phot, &b_pt_phot);
   fChain->SetBranchAddress("eta_phot", eta_phot, &b_eta_phot);
   fChain->SetBranchAddress("phi_phot", phi_phot, &b_phi_phot);
   fChain->SetBranchAddress("energy_phot", energy_phot, &b_energy_phot);
   fChain->SetBranchAddress("eRaw_phot", eRaw_phot, &b_eRaw_phot);
   fChain->SetBranchAddress("eSC_phot", eSC_phot, &b_eSC_phot);
   fChain->SetBranchAddress("e1x5_phot", e1x5_phot, &b_e1x5_phot);
   fChain->SetBranchAddress("e2x5_phot", e2x5_phot, &b_e2x5_phot);
   fChain->SetBranchAddress("e3x3_phot", e3x3_phot, &b_e3x3_phot);
   fChain->SetBranchAddress("e5x5_phot", e5x5_phot, &b_e5x5_phot);
   fChain->SetBranchAddress("maxEnergyXtal_phot", maxEnergyXtal_phot, &b_maxEnergyXtal_phot);
   fChain->SetBranchAddress("sigmaEtaEta_phot", sigmaEtaEta_phot, &b_sigmaEtaEta_phot);
   fChain->SetBranchAddress("sigmaIetaIeta_phot", sigmaIetaIeta_phot, &b_sigmaIetaIeta_phot);
   fChain->SetBranchAddress("r1x5_phot", r1x5_phot, &b_r1x5_phot);
   fChain->SetBranchAddress("r2x5_phot", r2x5_phot, &b_r2x5_phot);
   fChain->SetBranchAddress("r9_phot", r9_phot, &b_r9_phot);
   fChain->SetBranchAddress("hOverE_phot", hOverE_phot, &b_hOverE_phot);
   fChain->SetBranchAddress("hTowOverE_phot", hTowOverE_phot, &b_hTowOverE_phot);
   fChain->SetBranchAddress("ecalRecHitSumEtConeDR04_phot", ecalRecHitSumEtConeDR04_phot, &b_ecalRecHitSumEtConeDR04_phot);
   fChain->SetBranchAddress("hcalTowerSumEtConeDR04_phot", hcalTowerSumEtConeDR04_phot, &b_hcalTowerSumEtConeDR04_phot);
   fChain->SetBranchAddress("hcalTowerSumEtBcConeDR04_phot", hcalTowerSumEtBcConeDR04_phot, &b_hcalTowerSumEtBcConeDR04_phot);
   fChain->SetBranchAddress("trkSumPtSolidConeDR04_phot", trkSumPtSolidConeDR04_phot, &b_trkSumPtSolidConeDR04_phot);
   fChain->SetBranchAddress("trkSumPtHollowConeDR04_phot", trkSumPtHollowConeDR04_phot, &b_trkSumPtHollowConeDR04_phot);
   fChain->SetBranchAddress("nTrkSolidConeDR04_phot", nTrkSolidConeDR04_phot, &b_nTrkSolidConeDR04_phot);
   fChain->SetBranchAddress("nTrkHollowConeDR04_phot", nTrkHollowConeDR04_phot, &b_nTrkHollowConeDR04_phot);
   fChain->SetBranchAddress("ecalRecHitSumEtConeDR03_phot", ecalRecHitSumEtConeDR03_phot, &b_ecalRecHitSumEtConeDR03_phot);
   fChain->SetBranchAddress("hcalTowerSumEtConeDR03_phot", hcalTowerSumEtConeDR03_phot, &b_hcalTowerSumEtConeDR03_phot);
   fChain->SetBranchAddress("hcalTowerSumEtBcConeDR03_phot", hcalTowerSumEtBcConeDR03_phot, &b_hcalTowerSumEtBcConeDR03_phot);
   fChain->SetBranchAddress("trkSumPtSolidConeDR03_phot", trkSumPtSolidConeDR03_phot, &b_trkSumPtSolidConeDR03_phot);
   fChain->SetBranchAddress("trkSumPtHollowConeDR03_phot", trkSumPtHollowConeDR03_phot, &b_trkSumPtHollowConeDR03_phot);
   fChain->SetBranchAddress("nTrkSolidConeDR03_phot", nTrkSolidConeDR03_phot, &b_nTrkSolidConeDR03_phot);
   fChain->SetBranchAddress("nTrkHollowConeDR03_phot", nTrkHollowConeDR03_phot, &b_nTrkHollowConeDR03_phot);
   fChain->SetBranchAddress("chIsoPF_phot", chIsoPF_phot, &b_chIsoPF_phot);
   fChain->SetBranchAddress("nhIsoPF_phot", nhIsoPF_phot, &b_nhIsoPF_phot);
   fChain->SetBranchAddress("phIsoPF_phot", phIsoPF_phot, &b_phIsoPF_phot);
   fChain->SetBranchAddress("hasPixelSeed_phot", hasPixelSeed_phot, &b_hasPixelSeed_phot);
   fChain->SetBranchAddress("nEcalRecHit", &nEcalRecHit, &b_nEcalRecHit);
   fChain->SetBranchAddress("iPhi_ecalRecHit", iPhi_ecalRecHit, &b_iPhi_ecalRecHit);
   fChain->SetBranchAddress("iEta_ecalRecHit", iEta_ecalRecHit, &b_iEta_ecalRecHit);
   fChain->SetBranchAddress("energy_ecalRecHit", energy_ecalRecHit, &b_energy_ecalRecHit);
   fChain->SetBranchAddress("nPFCand", &nPFCand, &b_nPFCand);
   fChain->SetBranchAddress("pt_pfCand", pt_pfCand, &b_pt_pfCand);
   fChain->SetBranchAddress("eta_pfCand", eta_pfCand, &b_eta_pfCand);
   fChain->SetBranchAddress("phi_pfCand", phi_pfCand, &b_phi_pfCand);
   fChain->SetBranchAddress("energy_pfCand", energy_pfCand, &b_energy_pfCand);
   fChain->SetBranchAddress("mass_pfCand", mass_pfCand, &b_mass_pfCand);
   fChain->SetBranchAddress("pdgId_pfCand", pdgId_pfCand, &b_pdgId_pfCand);
   fChain->SetBranchAddress("nCaloTower", &nCaloTower, &b_nCaloTower);
   fChain->SetBranchAddress("pt_caloTower", pt_caloTower, &b_pt_caloTower);
   fChain->SetBranchAddress("eta_caloTower", eta_caloTower, &b_eta_caloTower);
   fChain->SetBranchAddress("phi_caloTower", phi_caloTower, &b_phi_caloTower);
   fChain->SetBranchAddress("mass_caloTower", mass_caloTower, &b_mass_caloTower);
   fChain->SetBranchAddress("energy_caloTower", energy_caloTower, &b_energy_caloTower);
   fChain->SetBranchAddress("emEnergy_caloTower", emEnergy_caloTower, &b_emEnergy_caloTower);
   fChain->SetBranchAddress("hadEnergy_caloTower", hadEnergy_caloTower, &b_hadEnergy_caloTower);
   fChain->SetBranchAddress("outerEnergy_caloTower", outerEnergy_caloTower, &b_outerEnergy_caloTower);
   Notify();
}

Bool_t CODAnalysis::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void CODAnalysis::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t CODAnalysis::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef CODAnalysis_cxx
