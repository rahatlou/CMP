#define DataTree_cxx
#include "DataTree.h"

void DataTree::Loop()
{
   if (fChain == 0) return;

   // loop over events in the tree
   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
   } // end of event Loop

}
