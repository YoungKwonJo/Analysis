//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Jul 30 17:02:09 2015 by ROOT version 6.02/05
// from TTree event/event
// found on file: ../ntuple_ttjets_madgraph_pythia8.root
//////////////////////////////////////////////////////////

#ifndef CATNtuple_h
#define CATNtuple_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "vector"
using namespace std;

class CATNtuple {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Int_t           run;
   Int_t           lumi;
   Int_t           event;
   Int_t           HLTDoubleEl;
   Int_t           HLTDoubleMu;
   Int_t           HLTMuEl;
   Int_t           HLTSingleEl;
   Int_t           HLTSingleMu;
   Int_t           NgenJet;
   Int_t           genTtbarId;
   Int_t           genTtbarLeptonDecay;
   Int_t           nVertex;
   Double_t        puWeight;
   Double_t        puWeightDn;
   Double_t        puWeightUp;
   Double_t        pvX;
   Double_t        pvY;
   Double_t        pvZ;
   vector<double>  *pdfWeight;
   vector<double>  *electrons_eta;
   vector<double>  *electrons_idHEEP51;
   vector<double>  *electrons_idLoose;
   vector<double>  *electrons_idMedium;
   vector<double>  *electrons_idTeto;
   vector<double>  *electrons_idTight;
   vector<double>  *electrons_isPF;
   vector<double>  *electrons_isPassConversionVeto;
   vector<double>  *electrons_m;
   vector<double>  *electrons_phi;
   vector<double>  *electrons_pt;
   vector<double>  *electrons_q;
   vector<double>  *electrons_relIso03;
   vector<double>  *electrons_relIso04;
   vector<double>  *electrons_scEta;
   vector<double>  *jets_CSVInclV2;
   vector<double>  *jets_eta;
   vector<double>  *jets_hadronFlavour;
   vector<double>  *jets_m;
   vector<double>  *jets_partonFlavour;
   vector<double>  *jets_phi;
   vector<double>  *jets_pt;
   vector<double>  *jets_vtxMass;
   vector<double>  *met_phi;
   vector<double>  *met_pt;
   vector<double>  *muons_dxy;
   vector<double>  *muons_dz;
   vector<double>  *muons_eta;
   vector<double>  *muons_isGlobal;
   vector<double>  *muons_isLoose;
   vector<double>  *muons_isPF;
   vector<double>  *muons_isTight;
   vector<double>  *muons_isTracker;
   vector<double>  *muons_m;
   vector<double>  *muons_normalizedChi2;
   vector<double>  *muons_numberOfMatchedStations;
   vector<double>  *muons_numberOfValidMuonHits;
   vector<double>  *muons_numberOfValidPixelHits;
   vector<double>  *muons_phi;
   vector<double>  *muons_pt;
   vector<double>  *muons_q;
   vector<double>  *muons_relIso03;
   vector<double>  *muons_relIso04;
   vector<double>  *muons_trackerLayersWithMeasurement;

   // List of branches
   TBranch        *b_run;   //!
   TBranch        *b_lumi;   //!
   TBranch        *b_event;   //!
   TBranch        *b_HLTDoubleEl;   //!
   TBranch        *b_HLTDoubleMu;   //!
   TBranch        *b_HLTMuEl;   //!
   TBranch        *b_HLTSingleEl;   //!
   TBranch        *b_HLTSingleMu;   //!
   TBranch        *b_NgenJet;   //!
   TBranch        *b_genTtbarId;   //!
   TBranch        *b_genTtbarLeptonDecay;   //!
   TBranch        *b_nVertex;   //!
   TBranch        *b_puWeight;   //!
   TBranch        *b_puWeightDn;   //!
   TBranch        *b_puWeightUp;   //!
   TBranch        *b_pvX;   //!
   TBranch        *b_pvY;   //!
   TBranch        *b_pvZ;   //!
   TBranch        *b_pdfWeight;   //!
   TBranch        *b_electrons_eta;   //!
   TBranch        *b_electrons_idHEEP51;   //!
   TBranch        *b_electrons_idLoose;   //!
   TBranch        *b_electrons_idMedium;   //!
   TBranch        *b_electrons_idTeto;   //!
   TBranch        *b_electrons_idTight;   //!
   TBranch        *b_electrons_isPF;   //!
   TBranch        *b_electrons_isPassConversionVeto;   //!
   TBranch        *b_electrons_m;   //!
   TBranch        *b_electrons_phi;   //!
   TBranch        *b_electrons_pt;   //!
   TBranch        *b_electrons_q;   //!
   TBranch        *b_electrons_relIso03;   //!
   TBranch        *b_electrons_relIso04;   //!
   TBranch        *b_electrons_scEta;   //!
   TBranch        *b_jets_CSVInclV2;   //!
   TBranch        *b_jets_eta;   //!
   TBranch        *b_jets_hadronFlavour;   //!
   TBranch        *b_jets_m;   //!
   TBranch        *b_jets_partonFlavour;   //!
   TBranch        *b_jets_phi;   //!
   TBranch        *b_jets_pt;   //!
   TBranch        *b_jets_vtxMass;   //!
   TBranch        *b_met_phi;   //!
   TBranch        *b_met_pt;   //!
   TBranch        *b_muons_dxy;   //!
   TBranch        *b_muons_dz;   //!
   TBranch        *b_muons_eta;   //!
   TBranch        *b_muons_isGlobal;   //!
   TBranch        *b_muons_isLoose;   //!
   TBranch        *b_muons_isPF;   //!
   TBranch        *b_muons_isTight;   //!
   TBranch        *b_muons_isTracker;   //!
   TBranch        *b_muons_m;   //!
   TBranch        *b_muons_normalizedChi2;   //!
   TBranch        *b_muons_numberOfMatchedStations;   //!
   TBranch        *b_muons_numberOfValidMuonHits;   //!
   TBranch        *b_muons_numberOfValidPixelHits;   //!
   TBranch        *b_muons_phi;   //!
   TBranch        *b_muons_pt;   //!
   TBranch        *b_muons_q;   //!
   TBranch        *b_muons_relIso03;   //!
   TBranch        *b_muons_relIso04;   //!
   TBranch        *b_muons_trackerLayersWithMeasurement;   //!

   CATNtuple(TTree *tree=0);
   virtual ~CATNtuple();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef CATNtuple_cxx
CATNtuple::CATNtuple(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("../ntuple_ttjets_madgraph_pythia8.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("../ntuple_ttjets_madgraph_pythia8.root");
      }
      TDirectory * dir = (TDirectory*)f->Get("../ntuple_ttjets_madgraph_pythia8.root:/ntuple");
      dir->GetObject("event",tree);

   }
   Init(tree);
}

CATNtuple::~CATNtuple()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t CATNtuple::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t CATNtuple::LoadTree(Long64_t entry)
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

void CATNtuple::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   pdfWeight = 0;
   electrons_eta = 0;
   electrons_idHEEP51 = 0;
   electrons_idLoose = 0;
   electrons_idMedium = 0;
   electrons_idTeto = 0;
   electrons_idTight = 0;
   electrons_isPF = 0;
   electrons_isPassConversionVeto = 0;
   electrons_m = 0;
   electrons_phi = 0;
   electrons_pt = 0;
   electrons_q = 0;
   electrons_relIso03 = 0;
   electrons_relIso04 = 0;
   electrons_scEta = 0;
   jets_CSVInclV2 = 0;
   jets_eta = 0;
   jets_hadronFlavour = 0;
   jets_m = 0;
   jets_partonFlavour = 0;
   jets_phi = 0;
   jets_pt = 0;
   jets_vtxMass = 0;
   met_phi = 0;
   met_pt = 0;
   muons_dxy = 0;
   muons_dz = 0;
   muons_eta = 0;
   muons_isGlobal = 0;
   muons_isLoose = 0;
   muons_isPF = 0;
   muons_isTight = 0;
   muons_isTracker = 0;
   muons_m = 0;
   muons_normalizedChi2 = 0;
   muons_numberOfMatchedStations = 0;
   muons_numberOfValidMuonHits = 0;
   muons_numberOfValidPixelHits = 0;
   muons_phi = 0;
   muons_pt = 0;
   muons_q = 0;
   muons_relIso03 = 0;
   muons_relIso04 = 0;
   muons_trackerLayersWithMeasurement = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("run", &run, &b_run);
   fChain->SetBranchAddress("lumi", &lumi, &b_lumi);
   fChain->SetBranchAddress("event", &event, &b_event);
   fChain->SetBranchAddress("HLTDoubleEl", &HLTDoubleEl, &b_HLTDoubleEl);
   fChain->SetBranchAddress("HLTDoubleMu", &HLTDoubleMu, &b_HLTDoubleMu);
   fChain->SetBranchAddress("HLTMuEl", &HLTMuEl, &b_HLTMuEl);
   fChain->SetBranchAddress("HLTSingleEl", &HLTSingleEl, &b_HLTSingleEl);
   fChain->SetBranchAddress("HLTSingleMu", &HLTSingleMu, &b_HLTSingleMu);
   fChain->SetBranchAddress("NgenJet", &NgenJet, &b_NgenJet);
   fChain->SetBranchAddress("genTtbarId", &genTtbarId, &b_genTtbarId);
   fChain->SetBranchAddress("genTtbarLeptonDecay", &genTtbarLeptonDecay, &b_genTtbarLeptonDecay);
   fChain->SetBranchAddress("nVertex", &nVertex, &b_nVertex);
   fChain->SetBranchAddress("puWeight", &puWeight, &b_puWeight);
   fChain->SetBranchAddress("puWeightDn", &puWeightDn, &b_puWeightDn);
   fChain->SetBranchAddress("puWeightUp", &puWeightUp, &b_puWeightUp);
   fChain->SetBranchAddress("pvX", &pvX, &b_pvX);
   fChain->SetBranchAddress("pvY", &pvY, &b_pvY);
   fChain->SetBranchAddress("pvZ", &pvZ, &b_pvZ);
   fChain->SetBranchAddress("pdfWeight", &pdfWeight, &b_pdfWeight);
   fChain->SetBranchAddress("electrons_eta", &electrons_eta, &b_electrons_eta);
   fChain->SetBranchAddress("electrons_idHEEP51", &electrons_idHEEP51, &b_electrons_idHEEP51);
   fChain->SetBranchAddress("electrons_idLoose", &electrons_idLoose, &b_electrons_idLoose);
   fChain->SetBranchAddress("electrons_idMedium", &electrons_idMedium, &b_electrons_idMedium);
   fChain->SetBranchAddress("electrons_idTeto", &electrons_idTeto, &b_electrons_idTeto);
   fChain->SetBranchAddress("electrons_idTight", &electrons_idTight, &b_electrons_idTight);
   fChain->SetBranchAddress("electrons_isPF", &electrons_isPF, &b_electrons_isPF);
   fChain->SetBranchAddress("electrons_isPassConversionVeto", &electrons_isPassConversionVeto, &b_electrons_isPassConversionVeto);
   fChain->SetBranchAddress("electrons_m", &electrons_m, &b_electrons_m);
   fChain->SetBranchAddress("electrons_phi", &electrons_phi, &b_electrons_phi);
   fChain->SetBranchAddress("electrons_pt", &electrons_pt, &b_electrons_pt);
   fChain->SetBranchAddress("electrons_q", &electrons_q, &b_electrons_q);
   fChain->SetBranchAddress("electrons_relIso03", &electrons_relIso03, &b_electrons_relIso03);
   fChain->SetBranchAddress("electrons_relIso04", &electrons_relIso04, &b_electrons_relIso04);
   fChain->SetBranchAddress("electrons_scEta", &electrons_scEta, &b_electrons_scEta);
   fChain->SetBranchAddress("jets_CSVInclV2", &jets_CSVInclV2, &b_jets_CSVInclV2);
   fChain->SetBranchAddress("jets_eta", &jets_eta, &b_jets_eta);
   fChain->SetBranchAddress("jets_hadronFlavour", &jets_hadronFlavour, &b_jets_hadronFlavour);
   fChain->SetBranchAddress("jets_m", &jets_m, &b_jets_m);
   fChain->SetBranchAddress("jets_partonFlavour", &jets_partonFlavour, &b_jets_partonFlavour);
   fChain->SetBranchAddress("jets_phi", &jets_phi, &b_jets_phi);
   fChain->SetBranchAddress("jets_pt", &jets_pt, &b_jets_pt);
   fChain->SetBranchAddress("jets_vtxMass", &jets_vtxMass, &b_jets_vtxMass);
   fChain->SetBranchAddress("met_phi", &met_phi, &b_met_phi);
   fChain->SetBranchAddress("met_pt", &met_pt, &b_met_pt);
   fChain->SetBranchAddress("muons_dxy", &muons_dxy, &b_muons_dxy);
   fChain->SetBranchAddress("muons_dz", &muons_dz, &b_muons_dz);
   fChain->SetBranchAddress("muons_eta", &muons_eta, &b_muons_eta);
   fChain->SetBranchAddress("muons_isGlobal", &muons_isGlobal, &b_muons_isGlobal);
   fChain->SetBranchAddress("muons_isLoose", &muons_isLoose, &b_muons_isLoose);
   fChain->SetBranchAddress("muons_isPF", &muons_isPF, &b_muons_isPF);
   fChain->SetBranchAddress("muons_isTight", &muons_isTight, &b_muons_isTight);
   fChain->SetBranchAddress("muons_isTracker", &muons_isTracker, &b_muons_isTracker);
   fChain->SetBranchAddress("muons_m", &muons_m, &b_muons_m);
   fChain->SetBranchAddress("muons_normalizedChi2", &muons_normalizedChi2, &b_muons_normalizedChi2);
   fChain->SetBranchAddress("muons_numberOfMatchedStations", &muons_numberOfMatchedStations, &b_muons_numberOfMatchedStations);
   fChain->SetBranchAddress("muons_numberOfValidMuonHits", &muons_numberOfValidMuonHits, &b_muons_numberOfValidMuonHits);
   fChain->SetBranchAddress("muons_numberOfValidPixelHits", &muons_numberOfValidPixelHits, &b_muons_numberOfValidPixelHits);
   fChain->SetBranchAddress("muons_phi", &muons_phi, &b_muons_phi);
   fChain->SetBranchAddress("muons_pt", &muons_pt, &b_muons_pt);
   fChain->SetBranchAddress("muons_q", &muons_q, &b_muons_q);
   fChain->SetBranchAddress("muons_relIso03", &muons_relIso03, &b_muons_relIso03);
   fChain->SetBranchAddress("muons_relIso04", &muons_relIso04, &b_muons_relIso04);
   fChain->SetBranchAddress("muons_trackerLayersWithMeasurement", &muons_trackerLayersWithMeasurement, &b_muons_trackerLayersWithMeasurement);
   Notify();
}

Bool_t CATNtuple::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void CATNtuple::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t CATNtuple::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef CATNtuple_cxx
