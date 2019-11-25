
# Using TTree provided by others

In this example we use a root file ([examples/codTree_QCD_Pt_1400to1800.root](examples/codTree_QCD_Pt_1400to1800.root)) produced on simulated proton-proton
collisions at the CERN
[Large Hadron Collider](https://home.cern/topics/large-hadron-collider)
and using the [CMS experiment](http://cms.cern). These data are provided
as part of the CMS Open Data effort at [CERN](http://cern.ch). More details available at
[CMS Open Data Portal](http://opendata.cern.ch/search?page=1&size=20&experiment=CMS).


1. First we create the analysis class using MakeClass
```
$ root -l codTree_QCD_Pt_1400to1800.root
root [0]
Attaching file codTree_QCD_Pt_1400to1800.root as _file0...
(TFile *) 0x7fa32c9cbf60
root [1] .ls
TFile**		codTree_QCD_Pt_1400to1800.root
 TFile*		codTree_QCD_Pt_1400to1800.root
  KEY: TDirectoryFile	codana;1	codana
root [2] codana->cd()
(bool) true
root [3] .ls
TDirectoryFile*		codana	codana
 KEY: TTree	codtree;1
 root [4] codtree->MakeClass("Analysis")
 ```

2. Modify the header file `Analysis.C`  to
   1. change size of static arrays
   2. change constructor
   3. change destructor to remove the `delete fchain` line

3. check that your `Analysis` class code is correct by compiling it
```shell
g++ -c Analysis.C `root-config --cflags`
```

4. Write a new application
   `analyser.cc` to use the new `Analysis` class.
   The constructor of `Analysis` object needs a valid pointer to the tree. This is the code needed in `analyser.cc` to obtain such a pointer
   ```c++
   // ==== open TFile
TString fname("name of file with full or relative path");
TFile* rootfile = TFile::Open(fname);
if( !rootfile->IsOpen() ) {
  std::cout << "problems reading root file. existing... " << std::endl;
  exit(-1);
}
std::cout << "reading data from " << fname << std::endl;

//=== pointer to TTree
// get pointer to tree object stored in the file
// you can also acquire the name of the tree from command line
TDirectoryFile* dir = (TDirectoryFile*)rootfile->Get("codana");
TTree* tree = (TTree*) dir->Get("codtree");
if(!tree) {
  std::cout << "null pointer for TTree! exiting..." << std::endl;
  exit(-1);
}
```

5. Finally start analysing the data by changing `Analysis::Loop` in
`Analysis.C`

6. Link your executable and start doing analysis
```shell
g++ -o /tmp/app analyser.cc  Analysis.C `root-config --libs --cflags`
/tmp/app codTree_QCD_Pt_1400to1800.root
```

## A first example

In this first example we want to find out what is stored in the file
by looking at some basic variables
```c++
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
```
## Exercise
  1. use the `TLorentzVecotor` class of ROOT to manipulate the 4-momentum of the
  particles in the `TTree` and compute the invariant mass.
