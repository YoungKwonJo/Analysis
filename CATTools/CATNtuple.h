//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Mar  5 12:56:38 2015 by ROOT version 5.34/18
// from TTree event/event
// found on file: ../ntuple_ttbar_tag711_aod_0.root
//////////////////////////////////////////////////////////

#ifndef CATNtuple_h
#define CATNtuple_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include <vector>

// Fixed size dimensions of array or collections stored in the TTree if any.
using namespace std;

class CATNtuple {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Int_t           run;
   Int_t           lumi;
   Int_t           event;
   Int_t           HLTDoubleEl;
   Int_t           HLTDoubleMu;
   Int_t           HLTMuEl;
   Int_t           HLTSingleEl;
   Int_t           HLTSingleMu;
   Int_t           nVertex;
   Double_t        puWeight;
   Double_t        puWeightDn;
   Double_t        puWeightUp;
   Double_t        pvX;
   Double_t        pvY;
   Double_t        pvZ;
   vector<double>  *pdfWeight;
   vector<double>  *electrons_dxy;
   vector<double>  *electrons_dz;
   vector<double>  *electrons_eta;
   vector<double>  *electrons_idLoose;
   vector<double>  *electrons_idTight;
   vector<double>  *electrons_isGsfCtfScPixChargeConsistent;
   vector<double>  *electrons_m;
   vector<double>  *electrons_phi;
   vector<double>  *electrons_pt;
   vector<double>  *electrons_q;
   vector<double>  *electrons_relIso03;
   vector<double>  *electrons_relIso04;
   vector<double>  *electrons_scEta;
   vector<double>  *gentop_NJets;
   vector<double>  *gentop_NJets10;
   vector<double>  *gentop_NJets20;
   vector<double>  *gentop_NJets25;
   vector<double>  *gentop_NJets30;
   vector<double>  *gentop_NJets40;
   vector<double>  *gentop_NaddJets20;
   vector<double>  *gentop_NaddJets40;
   vector<double>  *gentop_NaddbJets;
   vector<double>  *gentop_NaddbJets1;
   vector<double>  *gentop_NaddbJets20;
   vector<double>  *gentop_NaddbJets201;
   vector<double>  *gentop_NaddbJets40;
   vector<double>  *gentop_NaddbJets401;
   vector<double>  *gentop_NaddbQuarks20;
   vector<double>  *gentop_NaddbQuarks40;
   vector<double>  *gentop_NbJets;
   vector<double>  *gentop_NbJets1;
   vector<double>  *gentop_NbJets20;
   vector<double>  *gentop_NbJets201;
   vector<double>  *gentop_NbJets25;
   vector<double>  *gentop_NbJets251;
   vector<double>  *gentop_NbJets30;
   vector<double>  *gentop_NbJets301;
   vector<double>  *gentop_NbJets40;
   vector<double>  *gentop_NbJets401;
   vector<double>  *gentop_NbQuarks;
   vector<double>  *gentop_NbQuarks20;
   vector<double>  *gentop_NbQuarks40;
   vector<double>  *gentop_NbQuarksNoTop;
   vector<double>  *gentop_NbQuarksTop;
   vector<double>  *gentop_NcJets;
   vector<double>  *gentop_NcJets1;
   vector<double>  *gentop_NcJets10;
   vector<double>  *gentop_NcJets101;
   vector<double>  *gentop_NcJets15;
   vector<double>  *gentop_NcJets151;
   vector<double>  *gentop_NcJets20;
   vector<double>  *gentop_NcJets201;
   vector<double>  *gentop_NcJets25;
   vector<double>  *gentop_NcJets251;
   vector<double>  *gentop_NcJets30;
   vector<double>  *gentop_NcJets301;
   vector<double>  *gentop_NcJets40;
   vector<double>  *gentop_NcJets401;
   vector<double>  *gentop_NcQuarks;
   vector<double>  *gentop_allHadronic;
   vector<double>  *gentop_diLeptonicEleEle;
   vector<double>  *gentop_diLeptonicMuoEle;
   vector<double>  *gentop_diLeptonicMuoMuo;
   vector<double>  *gentop_diLeptonicTauEle;
   vector<double>  *gentop_diLeptonicTauMuo;
   vector<double>  *gentop_diLeptonicTauTau;
   vector<double>  *gentop_lepton1_eta;
   vector<double>  *gentop_lepton1_phi;
   vector<double>  *gentop_lepton1_pt;
   vector<double>  *gentop_lepton2_eta;
   vector<double>  *gentop_lepton2_phi;
   vector<double>  *gentop_lepton2_pt;
   vector<double>  *gentop_semiLeptonic;
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
   vector<double>  *muon_dxy;
   vector<double>  *muon_dz;
   vector<double>  *muon_eta;
   vector<double>  *muon_isGlobal;
   vector<double>  *muon_isLoose;
   vector<double>  *muon_isTight;
   vector<double>  *muon_isTracker;
   vector<double>  *muon_m;
   vector<double>  *muon_phi;
   vector<double>  *muon_pt;
   vector<double>  *muon_q;
   vector<double>  *muon_relIso03;
   vector<double>  *muon_relIso04;
   vector<double>  *partonTop_eta;
   vector<double>  *partonTop_m;
   vector<double>  *partonTop_pdgId;
   vector<double>  *partonTop_phi;
   vector<double>  *partonTop_pt;
   vector<double>  *partonTop_q;
   vector<double>  *pseudoTop_eta;
   vector<double>  *pseudoTop_m;
   vector<double>  *pseudoTop_pdgId;
   vector<double>  *pseudoTop_phi;
   vector<double>  *pseudoTop_pt;
   vector<double>  *pseudoTop_q;
   vector<double>  *pseudoTopJet_eta;
   vector<double>  *pseudoTopJet_m;
   vector<double>  *pseudoTopJet_pdgId;
   vector<double>  *pseudoTopJet_phi;
   vector<double>  *pseudoTopJet_pt;
   vector<double>  *pseudoTopJet_q;
   vector<double>  *pseudoTopLepton_eta;
   vector<double>  *pseudoTopLepton_m;
   vector<double>  *pseudoTopLepton_pdgId;
   vector<double>  *pseudoTopLepton_phi;
   vector<double>  *pseudoTopLepton_pt;
   vector<double>  *pseudoTopLepton_q;
   vector<double>  *pseudoTopNu_eta;
   vector<double>  *pseudoTopNu_pdgId;
   vector<double>  *pseudoTopNu_phi;
   vector<double>  *pseudoTopNu_pt;

   // List of branches
   TBranch        *b_run;   //!
   TBranch        *b_lumi;   //!
   TBranch        *b_event;   //!
   TBranch        *b_HLTDoubleEl;   //!
   TBranch        *b_HLTDoubleMu;   //!
   TBranch        *b_HLTMuEl;   //!
   TBranch        *b_HLTSingleEl;   //!
   TBranch        *b_HLTSingleMu;   //!
   TBranch        *b_nVertex;   //!
   TBranch        *b_puWeight;   //!
   TBranch        *b_puWeightDn;   //!
   TBranch        *b_puWeightUp;   //!
   TBranch        *b_pvX;   //!
   TBranch        *b_pvY;   //!
   TBranch        *b_pvZ;   //!
   TBranch        *b_pdfWeight;   //!
   TBranch        *b_electrons_dxy;   //!
   TBranch        *b_electrons_dz;   //!
   TBranch        *b_electrons_eta;   //!
   TBranch        *b_electrons_idLoose;   //!
   TBranch        *b_electrons_idTight;   //!
   TBranch        *b_electrons_isGsfCtfScPixChargeConsistent;   //!
   TBranch        *b_electrons_m;   //!
   TBranch        *b_electrons_phi;   //!
   TBranch        *b_electrons_pt;   //!
   TBranch        *b_electrons_q;   //!
   TBranch        *b_electrons_relIso03;   //!
   TBranch        *b_electrons_relIso04;   //!
   TBranch        *b_electrons_scEta;   //!
   TBranch        *b_gentop_NJets;   //!
   TBranch        *b_gentop_NJets10;   //!
   TBranch        *b_gentop_NJets20;   //!
   TBranch        *b_gentop_NJets25;   //!
   TBranch        *b_gentop_NJets30;   //!
   TBranch        *b_gentop_NJets40;   //!
   TBranch        *b_gentop_NaddJets20;   //!
   TBranch        *b_gentop_NaddJets40;   //!
   TBranch        *b_gentop_NaddbJets;   //!
   TBranch        *b_gentop_NaddbJets1;   //!
   TBranch        *b_gentop_NaddbJets20;   //!
   TBranch        *b_gentop_NaddbJets201;   //!
   TBranch        *b_gentop_NaddbJets40;   //!
   TBranch        *b_gentop_NaddbJets401;   //!
   TBranch        *b_gentop_NaddbQuarks20;   //!
   TBranch        *b_gentop_NaddbQuarks40;   //!
   TBranch        *b_gentop_NbJets;   //!
   TBranch        *b_gentop_NbJets1;   //!
   TBranch        *b_gentop_NbJets20;   //!
   TBranch        *b_gentop_NbJets201;   //!
   TBranch        *b_gentop_NbJets25;   //!
   TBranch        *b_gentop_NbJets251;   //!
   TBranch        *b_gentop_NbJets30;   //!
   TBranch        *b_gentop_NbJets301;   //!
   TBranch        *b_gentop_NbJets40;   //!
   TBranch        *b_gentop_NbJets401;   //!
   TBranch        *b_gentop_NbQuarks;   //!
   TBranch        *b_gentop_NbQuarks20;   //!
   TBranch        *b_gentop_NbQuarks40;   //!
   TBranch        *b_gentop_NbQuarksNoTop;   //!
   TBranch        *b_gentop_NbQuarksTop;   //!
   TBranch        *b_gentop_NcJets;   //!
   TBranch        *b_gentop_NcJets1;   //!
   TBranch        *b_gentop_NcJets10;   //!
   TBranch        *b_gentop_NcJets101;   //!
   TBranch        *b_gentop_NcJets15;   //!
   TBranch        *b_gentop_NcJets151;   //!
   TBranch        *b_gentop_NcJets20;   //!
   TBranch        *b_gentop_NcJets201;   //!
   TBranch        *b_gentop_NcJets25;   //!
   TBranch        *b_gentop_NcJets251;   //!
   TBranch        *b_gentop_NcJets30;   //!
   TBranch        *b_gentop_NcJets301;   //!
   TBranch        *b_gentop_NcJets40;   //!
   TBranch        *b_gentop_NcJets401;   //!
   TBranch        *b_gentop_NcQuarks;   //!
   TBranch        *b_gentop_allHadronic;   //!
   TBranch        *b_gentop_diLeptonicEleEle;   //!
   TBranch        *b_gentop_diLeptonicMuoEle;   //!
   TBranch        *b_gentop_diLeptonicMuoMuo;   //!
   TBranch        *b_gentop_diLeptonicTauEle;   //!
   TBranch        *b_gentop_diLeptonicTauMuo;   //!
   TBranch        *b_gentop_diLeptonicTauTau;   //!
   TBranch        *b_gentop_lepton1_eta;   //!
   TBranch        *b_gentop_lepton1_phi;   //!
   TBranch        *b_gentop_lepton1_pt;   //!
   TBranch        *b_gentop_lepton2_eta;   //!
   TBranch        *b_gentop_lepton2_phi;   //!
   TBranch        *b_gentop_lepton2_pt;   //!
   TBranch        *b_gentop_semiLeptonic;   //!
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
   TBranch        *b_muon_dxy;   //!
   TBranch        *b_muon_dz;   //!
   TBranch        *b_muon_eta;   //!
   TBranch        *b_muon_isGlobal;   //!
   TBranch        *b_muon_isLoose;   //!
   TBranch        *b_muon_isTight;   //!
   TBranch        *b_muon_isTracker;   //!
   TBranch        *b_muon_m;   //!
   TBranch        *b_muon_phi;   //!
   TBranch        *b_muon_pt;   //!
   TBranch        *b_muon_q;   //!
   TBranch        *b_muon_relIso03;   //!
   TBranch        *b_muon_relIso04;   //!
   TBranch        *b_partonTop_eta;   //!
   TBranch        *b_partonTop_m;   //!
   TBranch        *b_partonTop_pdgId;   //!
   TBranch        *b_partonTop_phi;   //!
   TBranch        *b_partonTop_pt;   //!
   TBranch        *b_partonTop_q;   //!
   TBranch        *b_pseudoTop_eta;   //!
   TBranch        *b_pseudoTop_m;   //!
   TBranch        *b_pseudoTop_pdgId;   //!
   TBranch        *b_pseudoTop_phi;   //!
   TBranch        *b_pseudoTop_pt;   //!
   TBranch        *b_pseudoTop_q;   //!
   TBranch        *b_pseudoTopJet_eta;   //!
   TBranch        *b_pseudoTopJet_m;   //!
   TBranch        *b_pseudoTopJet_pdgId;   //!
   TBranch        *b_pseudoTopJet_phi;   //!
   TBranch        *b_pseudoTopJet_pt;   //!
   TBranch        *b_pseudoTopJet_q;   //!
   TBranch        *b_pseudoTopLepton_eta;   //!
   TBranch        *b_pseudoTopLepton_m;   //!
   TBranch        *b_pseudoTopLepton_pdgId;   //!
   TBranch        *b_pseudoTopLepton_phi;   //!
   TBranch        *b_pseudoTopLepton_pt;   //!
   TBranch        *b_pseudoTopLepton_q;   //!
   TBranch        *b_pseudoTopNu_eta;   //!
   TBranch        *b_pseudoTopNu_pdgId;   //!
   TBranch        *b_pseudoTopNu_phi;   //!
   TBranch        *b_pseudoTopNu_pt;   //!

   CATNtuple(TTree *tree=0);
   virtual ~CATNtuple();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop(char *DecayMode,bool isSignal,bool isMC);
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
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("../ntuple_ttbar_tag711_aod_0.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("../ntuple_ttbar_tag711_aod_0.root");
      }
      TDirectory * dir = (TDirectory*)f->Get("../ntuple_ttbar_tag711_aod_0.root:/ntuple");
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
   electrons_dxy = 0;
   electrons_dz = 0;
   electrons_eta = 0;
   electrons_idLoose = 0;
   electrons_idTight = 0;
   electrons_isGsfCtfScPixChargeConsistent = 0;
   electrons_m = 0;
   electrons_phi = 0;
   electrons_pt = 0;
   electrons_q = 0;
   electrons_relIso03 = 0;
   electrons_relIso04 = 0;
   electrons_scEta = 0;
   gentop_NJets = 0;
   gentop_NJets10 = 0;
   gentop_NJets20 = 0;
   gentop_NJets25 = 0;
   gentop_NJets30 = 0;
   gentop_NJets40 = 0;
   gentop_NaddJets20 = 0;
   gentop_NaddJets40 = 0;
   gentop_NaddbJets = 0;
   gentop_NaddbJets1 = 0;
   gentop_NaddbJets20 = 0;
   gentop_NaddbJets201 = 0;
   gentop_NaddbJets40 = 0;
   gentop_NaddbJets401 = 0;
   gentop_NaddbQuarks20 = 0;
   gentop_NaddbQuarks40 = 0;
   gentop_NbJets = 0;
   gentop_NbJets1 = 0;
   gentop_NbJets20 = 0;
   gentop_NbJets201 = 0;
   gentop_NbJets25 = 0;
   gentop_NbJets251 = 0;
   gentop_NbJets30 = 0;
   gentop_NbJets301 = 0;
   gentop_NbJets40 = 0;
   gentop_NbJets401 = 0;
   gentop_NbQuarks = 0;
   gentop_NbQuarks20 = 0;
   gentop_NbQuarks40 = 0;
   gentop_NbQuarksNoTop = 0;
   gentop_NbQuarksTop = 0;
   gentop_NcJets = 0;
   gentop_NcJets1 = 0;
   gentop_NcJets10 = 0;
   gentop_NcJets101 = 0;
   gentop_NcJets15 = 0;
   gentop_NcJets151 = 0;
   gentop_NcJets20 = 0;
   gentop_NcJets201 = 0;
   gentop_NcJets25 = 0;
   gentop_NcJets251 = 0;
   gentop_NcJets30 = 0;
   gentop_NcJets301 = 0;
   gentop_NcJets40 = 0;
   gentop_NcJets401 = 0;
   gentop_NcQuarks = 0;
   gentop_allHadronic = 0;
   gentop_diLeptonicEleEle = 0;
   gentop_diLeptonicMuoEle = 0;
   gentop_diLeptonicMuoMuo = 0;
   gentop_diLeptonicTauEle = 0;
   gentop_diLeptonicTauMuo = 0;
   gentop_diLeptonicTauTau = 0;
   gentop_lepton1_eta = 0;
   gentop_lepton1_phi = 0;
   gentop_lepton1_pt = 0;
   gentop_lepton2_eta = 0;
   gentop_lepton2_phi = 0;
   gentop_lepton2_pt = 0;
   gentop_semiLeptonic = 0;
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
   muon_dxy = 0;
   muon_dz = 0;
   muon_eta = 0;
   muon_isGlobal = 0;
   muon_isLoose = 0;
   muon_isTight = 0;
   muon_isTracker = 0;
   muon_m = 0;
   muon_phi = 0;
   muon_pt = 0;
   muon_q = 0;
   muon_relIso03 = 0;
   muon_relIso04 = 0;
   partonTop_eta = 0;
   partonTop_m = 0;
   partonTop_pdgId = 0;
   partonTop_phi = 0;
   partonTop_pt = 0;
   partonTop_q = 0;
   pseudoTop_eta = 0;
   pseudoTop_m = 0;
   pseudoTop_pdgId = 0;
   pseudoTop_phi = 0;
   pseudoTop_pt = 0;
   pseudoTop_q = 0;
   pseudoTopJet_eta = 0;
   pseudoTopJet_m = 0;
   pseudoTopJet_pdgId = 0;
   pseudoTopJet_phi = 0;
   pseudoTopJet_pt = 0;
   pseudoTopJet_q = 0;
   pseudoTopLepton_eta = 0;
   pseudoTopLepton_m = 0;
   pseudoTopLepton_pdgId = 0;
   pseudoTopLepton_phi = 0;
   pseudoTopLepton_pt = 0;
   pseudoTopLepton_q = 0;
   pseudoTopNu_eta = 0;
   pseudoTopNu_pdgId = 0;
   pseudoTopNu_phi = 0;
   pseudoTopNu_pt = 0;
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
   fChain->SetBranchAddress("nVertex", &nVertex, &b_nVertex);
   fChain->SetBranchAddress("puWeight", &puWeight, &b_puWeight);
   fChain->SetBranchAddress("puWeightDn", &puWeightDn, &b_puWeightDn);
   fChain->SetBranchAddress("puWeightUp", &puWeightUp, &b_puWeightUp);
   fChain->SetBranchAddress("pvX", &pvX, &b_pvX);
   fChain->SetBranchAddress("pvY", &pvY, &b_pvY);
   fChain->SetBranchAddress("pvZ", &pvZ, &b_pvZ);
   fChain->SetBranchAddress("pdfWeight", &pdfWeight, &b_pdfWeight);
   fChain->SetBranchAddress("electrons_dxy", &electrons_dxy, &b_electrons_dxy);
   fChain->SetBranchAddress("electrons_dz", &electrons_dz, &b_electrons_dz);
   fChain->SetBranchAddress("electrons_eta", &electrons_eta, &b_electrons_eta);
   fChain->SetBranchAddress("electrons_idLoose", &electrons_idLoose, &b_electrons_idLoose);
   fChain->SetBranchAddress("electrons_idTight", &electrons_idTight, &b_electrons_idTight);
   fChain->SetBranchAddress("electrons_isGsfCtfScPixChargeConsistent", &electrons_isGsfCtfScPixChargeConsistent, &b_electrons_isGsfCtfScPixChargeConsistent);
   fChain->SetBranchAddress("electrons_m", &electrons_m, &b_electrons_m);
   fChain->SetBranchAddress("electrons_phi", &electrons_phi, &b_electrons_phi);
   fChain->SetBranchAddress("electrons_pt", &electrons_pt, &b_electrons_pt);
   fChain->SetBranchAddress("electrons_q", &electrons_q, &b_electrons_q);
   fChain->SetBranchAddress("electrons_relIso03", &electrons_relIso03, &b_electrons_relIso03);
   fChain->SetBranchAddress("electrons_relIso04", &electrons_relIso04, &b_electrons_relIso04);
   fChain->SetBranchAddress("electrons_scEta", &electrons_scEta, &b_electrons_scEta);
   fChain->SetBranchAddress("gentop_NJets", &gentop_NJets, &b_gentop_NJets);
   fChain->SetBranchAddress("gentop_NJets10", &gentop_NJets10, &b_gentop_NJets10);
   fChain->SetBranchAddress("gentop_NJets20", &gentop_NJets20, &b_gentop_NJets20);
   fChain->SetBranchAddress("gentop_NJets25", &gentop_NJets25, &b_gentop_NJets25);
   fChain->SetBranchAddress("gentop_NJets30", &gentop_NJets30, &b_gentop_NJets30);
   fChain->SetBranchAddress("gentop_NJets40", &gentop_NJets40, &b_gentop_NJets40);
   fChain->SetBranchAddress("gentop_NaddJets20", &gentop_NaddJets20, &b_gentop_NaddJets20);
   fChain->SetBranchAddress("gentop_NaddJets40", &gentop_NaddJets40, &b_gentop_NaddJets40);
   fChain->SetBranchAddress("gentop_NaddbJets", &gentop_NaddbJets, &b_gentop_NaddbJets);
   fChain->SetBranchAddress("gentop_NaddbJets1", &gentop_NaddbJets1, &b_gentop_NaddbJets1);
   fChain->SetBranchAddress("gentop_NaddbJets20", &gentop_NaddbJets20, &b_gentop_NaddbJets20);
   fChain->SetBranchAddress("gentop_NaddbJets201", &gentop_NaddbJets201, &b_gentop_NaddbJets201);
   fChain->SetBranchAddress("gentop_NaddbJets40", &gentop_NaddbJets40, &b_gentop_NaddbJets40);
   fChain->SetBranchAddress("gentop_NaddbJets401", &gentop_NaddbJets401, &b_gentop_NaddbJets401);
   fChain->SetBranchAddress("gentop_NaddbQuarks20", &gentop_NaddbQuarks20, &b_gentop_NaddbQuarks20);
   fChain->SetBranchAddress("gentop_NaddbQuarks40", &gentop_NaddbQuarks40, &b_gentop_NaddbQuarks40);
   fChain->SetBranchAddress("gentop_NbJets", &gentop_NbJets, &b_gentop_NbJets);
   fChain->SetBranchAddress("gentop_NbJets1", &gentop_NbJets1, &b_gentop_NbJets1);
   fChain->SetBranchAddress("gentop_NbJets20", &gentop_NbJets20, &b_gentop_NbJets20);
   fChain->SetBranchAddress("gentop_NbJets201", &gentop_NbJets201, &b_gentop_NbJets201);
   fChain->SetBranchAddress("gentop_NbJets25", &gentop_NbJets25, &b_gentop_NbJets25);
   fChain->SetBranchAddress("gentop_NbJets251", &gentop_NbJets251, &b_gentop_NbJets251);
   fChain->SetBranchAddress("gentop_NbJets30", &gentop_NbJets30, &b_gentop_NbJets30);
   fChain->SetBranchAddress("gentop_NbJets301", &gentop_NbJets301, &b_gentop_NbJets301);
   fChain->SetBranchAddress("gentop_NbJets40", &gentop_NbJets40, &b_gentop_NbJets40);
   fChain->SetBranchAddress("gentop_NbJets401", &gentop_NbJets401, &b_gentop_NbJets401);
   fChain->SetBranchAddress("gentop_NbQuarks", &gentop_NbQuarks, &b_gentop_NbQuarks);
   fChain->SetBranchAddress("gentop_NbQuarks20", &gentop_NbQuarks20, &b_gentop_NbQuarks20);
   fChain->SetBranchAddress("gentop_NbQuarks40", &gentop_NbQuarks40, &b_gentop_NbQuarks40);
   fChain->SetBranchAddress("gentop_NbQuarksNoTop", &gentop_NbQuarksNoTop, &b_gentop_NbQuarksNoTop);
   fChain->SetBranchAddress("gentop_NbQuarksTop", &gentop_NbQuarksTop, &b_gentop_NbQuarksTop);
   fChain->SetBranchAddress("gentop_NcJets", &gentop_NcJets, &b_gentop_NcJets);
   fChain->SetBranchAddress("gentop_NcJets1", &gentop_NcJets1, &b_gentop_NcJets1);
   fChain->SetBranchAddress("gentop_NcJets10", &gentop_NcJets10, &b_gentop_NcJets10);
   fChain->SetBranchAddress("gentop_NcJets101", &gentop_NcJets101, &b_gentop_NcJets101);
   fChain->SetBranchAddress("gentop_NcJets15", &gentop_NcJets15, &b_gentop_NcJets15);
   fChain->SetBranchAddress("gentop_NcJets151", &gentop_NcJets151, &b_gentop_NcJets151);
   fChain->SetBranchAddress("gentop_NcJets20", &gentop_NcJets20, &b_gentop_NcJets20);
   fChain->SetBranchAddress("gentop_NcJets201", &gentop_NcJets201, &b_gentop_NcJets201);
   fChain->SetBranchAddress("gentop_NcJets25", &gentop_NcJets25, &b_gentop_NcJets25);
   fChain->SetBranchAddress("gentop_NcJets251", &gentop_NcJets251, &b_gentop_NcJets251);
   fChain->SetBranchAddress("gentop_NcJets30", &gentop_NcJets30, &b_gentop_NcJets30);
   fChain->SetBranchAddress("gentop_NcJets301", &gentop_NcJets301, &b_gentop_NcJets301);
   fChain->SetBranchAddress("gentop_NcJets40", &gentop_NcJets40, &b_gentop_NcJets40);
   fChain->SetBranchAddress("gentop_NcJets401", &gentop_NcJets401, &b_gentop_NcJets401);
   fChain->SetBranchAddress("gentop_NcQuarks", &gentop_NcQuarks, &b_gentop_NcQuarks);
   fChain->SetBranchAddress("gentop_allHadronic", &gentop_allHadronic, &b_gentop_allHadronic);
   fChain->SetBranchAddress("gentop_diLeptonicEleEle", &gentop_diLeptonicEleEle, &b_gentop_diLeptonicEleEle);
   fChain->SetBranchAddress("gentop_diLeptonicMuoEle", &gentop_diLeptonicMuoEle, &b_gentop_diLeptonicMuoEle);
   fChain->SetBranchAddress("gentop_diLeptonicMuoMuo", &gentop_diLeptonicMuoMuo, &b_gentop_diLeptonicMuoMuo);
   fChain->SetBranchAddress("gentop_diLeptonicTauEle", &gentop_diLeptonicTauEle, &b_gentop_diLeptonicTauEle);
   fChain->SetBranchAddress("gentop_diLeptonicTauMuo", &gentop_diLeptonicTauMuo, &b_gentop_diLeptonicTauMuo);
   fChain->SetBranchAddress("gentop_diLeptonicTauTau", &gentop_diLeptonicTauTau, &b_gentop_diLeptonicTauTau);
   fChain->SetBranchAddress("gentop_lepton1_eta", &gentop_lepton1_eta, &b_gentop_lepton1_eta);
   fChain->SetBranchAddress("gentop_lepton1_phi", &gentop_lepton1_phi, &b_gentop_lepton1_phi);
   fChain->SetBranchAddress("gentop_lepton1_pt", &gentop_lepton1_pt, &b_gentop_lepton1_pt);
   fChain->SetBranchAddress("gentop_lepton2_eta", &gentop_lepton2_eta, &b_gentop_lepton2_eta);
   fChain->SetBranchAddress("gentop_lepton2_phi", &gentop_lepton2_phi, &b_gentop_lepton2_phi);
   fChain->SetBranchAddress("gentop_lepton2_pt", &gentop_lepton2_pt, &b_gentop_lepton2_pt);
   fChain->SetBranchAddress("gentop_semiLeptonic", &gentop_semiLeptonic, &b_gentop_semiLeptonic);
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
   fChain->SetBranchAddress("muon_dxy", &muon_dxy, &b_muon_dxy);
   fChain->SetBranchAddress("muon_dz", &muon_dz, &b_muon_dz);
   fChain->SetBranchAddress("muon_eta", &muon_eta, &b_muon_eta);
   fChain->SetBranchAddress("muon_isGlobal", &muon_isGlobal, &b_muon_isGlobal);
   fChain->SetBranchAddress("muon_isLoose", &muon_isLoose, &b_muon_isLoose);
   fChain->SetBranchAddress("muon_isTight", &muon_isTight, &b_muon_isTight);
   fChain->SetBranchAddress("muon_isTracker", &muon_isTracker, &b_muon_isTracker);
   fChain->SetBranchAddress("muon_m", &muon_m, &b_muon_m);
   fChain->SetBranchAddress("muon_phi", &muon_phi, &b_muon_phi);
   fChain->SetBranchAddress("muon_pt", &muon_pt, &b_muon_pt);
   fChain->SetBranchAddress("muon_q", &muon_q, &b_muon_q);
   fChain->SetBranchAddress("muon_relIso03", &muon_relIso03, &b_muon_relIso03);
   fChain->SetBranchAddress("muon_relIso04", &muon_relIso04, &b_muon_relIso04);
   fChain->SetBranchAddress("partonTop_eta", &partonTop_eta, &b_partonTop_eta);
   fChain->SetBranchAddress("partonTop_m", &partonTop_m, &b_partonTop_m);
   fChain->SetBranchAddress("partonTop_pdgId", &partonTop_pdgId, &b_partonTop_pdgId);
   fChain->SetBranchAddress("partonTop_phi", &partonTop_phi, &b_partonTop_phi);
   fChain->SetBranchAddress("partonTop_pt", &partonTop_pt, &b_partonTop_pt);
   fChain->SetBranchAddress("partonTop_q", &partonTop_q, &b_partonTop_q);
   fChain->SetBranchAddress("pseudoTop_eta", &pseudoTop_eta, &b_pseudoTop_eta);
   fChain->SetBranchAddress("pseudoTop_m", &pseudoTop_m, &b_pseudoTop_m);
   fChain->SetBranchAddress("pseudoTop_pdgId", &pseudoTop_pdgId, &b_pseudoTop_pdgId);
   fChain->SetBranchAddress("pseudoTop_phi", &pseudoTop_phi, &b_pseudoTop_phi);
   fChain->SetBranchAddress("pseudoTop_pt", &pseudoTop_pt, &b_pseudoTop_pt);
   fChain->SetBranchAddress("pseudoTop_q", &pseudoTop_q, &b_pseudoTop_q);
   fChain->SetBranchAddress("pseudoTopJet_eta", &pseudoTopJet_eta, &b_pseudoTopJet_eta);
   fChain->SetBranchAddress("pseudoTopJet_m", &pseudoTopJet_m, &b_pseudoTopJet_m);
   fChain->SetBranchAddress("pseudoTopJet_pdgId", &pseudoTopJet_pdgId, &b_pseudoTopJet_pdgId);
   fChain->SetBranchAddress("pseudoTopJet_phi", &pseudoTopJet_phi, &b_pseudoTopJet_phi);
   fChain->SetBranchAddress("pseudoTopJet_pt", &pseudoTopJet_pt, &b_pseudoTopJet_pt);
   fChain->SetBranchAddress("pseudoTopJet_q", &pseudoTopJet_q, &b_pseudoTopJet_q);
   fChain->SetBranchAddress("pseudoTopLepton_eta", &pseudoTopLepton_eta, &b_pseudoTopLepton_eta);
   fChain->SetBranchAddress("pseudoTopLepton_m", &pseudoTopLepton_m, &b_pseudoTopLepton_m);
   fChain->SetBranchAddress("pseudoTopLepton_pdgId", &pseudoTopLepton_pdgId, &b_pseudoTopLepton_pdgId);
   fChain->SetBranchAddress("pseudoTopLepton_phi", &pseudoTopLepton_phi, &b_pseudoTopLepton_phi);
   fChain->SetBranchAddress("pseudoTopLepton_pt", &pseudoTopLepton_pt, &b_pseudoTopLepton_pt);
   fChain->SetBranchAddress("pseudoTopLepton_q", &pseudoTopLepton_q, &b_pseudoTopLepton_q);
   fChain->SetBranchAddress("pseudoTopNu_eta", &pseudoTopNu_eta, &b_pseudoTopNu_eta);
   fChain->SetBranchAddress("pseudoTopNu_pdgId", &pseudoTopNu_pdgId, &b_pseudoTopNu_pdgId);
   fChain->SetBranchAddress("pseudoTopNu_phi", &pseudoTopNu_phi, &b_pseudoTopNu_phi);
   fChain->SetBranchAddress("pseudoTopNu_pt", &pseudoTopNu_pt, &b_pseudoTopNu_pt);
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
