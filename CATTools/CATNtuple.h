//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Oct 27 11:50:12 2015 by ROOT version 6.02/05
// from TTree event/event
// found on file: /xrootd/store/user/youngjo/Cattools/v7-4-3/TTJets_aMC/ntuple_002.root
//////////////////////////////////////////////////////////

#ifndef CATNtuple_h
#define CATNtuple_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TH1D.h>

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
   Int_t           filterRECO;
   Int_t           filterTrigELEL;
   Int_t           filterTrigMUEL;
   Int_t           filterTrigMUMU;
   Int_t           nGoodPV;
   Int_t           nPV;
   Int_t           NgenJet;
   Int_t           genTtbarId;
   Int_t           genTtbarLeptonDecay;
   Int_t           genWeightId1;
   Int_t           genWeightId2;
   Int_t           nTrueInteraction;
   Int_t           partonTopChannel;
   Float_t         genWeight;
   Float_t         genWeightQ;
   Float_t         genWeightX1;
   Float_t         genWeightX2;
   Float_t         lheWeight;
   Float_t         puWeight;
   Float_t         puWeightDn;
   Float_t         puWeightUp;
   vector<float>   *pdfWeight;
   vector<float>   *electrons_chIso03;
   vector<float>   *electrons_chIso04;
   vector<float>   *electrons_eta;
   vector<float>   *electrons_idHEEPV60;
   vector<float>   *electrons_idLoose;
   vector<float>   *electrons_idMedium;
   vector<float>   *electrons_idTight;
   vector<float>   *electrons_idVeto;
   vector<float>   *electrons_isPF;
   vector<float>   *electrons_m;
   vector<float>   *electrons_matched;
   vector<float>   *electrons_mvaMedium;
   vector<float>   *electrons_mvaNonTrigWp80;
   vector<float>   *electrons_mvaNonTrigWp90;
   vector<float>   *electrons_mvaTight;
   vector<float>   *electrons_nhIso03;
   vector<float>   *electrons_nhIso04;
   vector<float>   *electrons_passConversionVeto;
   vector<float>   *electrons_phIso03;
   vector<float>   *electrons_phIso04;
   vector<float>   *electrons_phi;
   vector<float>   *electrons_pt;
   vector<float>   *electrons_puChIso03;
   vector<float>   *electrons_puChIso04;
   vector<float>   *electrons_q;
   vector<float>   *electrons_relIso03;
   vector<float>   *electrons_relIso04;
   vector<float>   *electrons_scEta;
   vector<float>   *jets_CSVInclV2;
   vector<float>   *jets_LooseId;
   vector<float>   *jets_TightId;
   vector<float>   *jets_eta;
   vector<float>   *jets_hadronFlavour;
   vector<float>   *jets_looseJetID;
   vector<float>   *jets_m;
   vector<float>   *jets_partonFlavour;
   vector<float>   *jets_phi;
   vector<float>   *jets_pileupJetId;
   vector<float>   *jets_pt;
   vector<float>   *jets_shiftedEnDown;
   vector<float>   *jets_shiftedEnUp;
   vector<float>   *jets_smearedRes;
   vector<float>   *jets_smearedResDown;
   vector<float>   *jets_smearedResUp;
   vector<float>   *jets_tightJetID;
   vector<float>   *jets_vtxMass;
   vector<float>   *jetsPuppi_CSVInclV2;
   vector<float>   *jetsPuppi_LooseId;
   vector<float>   *jetsPuppi_TightId;
   vector<float>   *jetsPuppi_eta;
   vector<float>   *jetsPuppi_hadronFlavour;
   vector<float>   *jetsPuppi_looseJetID;
   vector<float>   *jetsPuppi_m;
   vector<float>   *jetsPuppi_partonFlavour;
   vector<float>   *jetsPuppi_phi;
   vector<float>   *jetsPuppi_pileupJetId;
   vector<float>   *jetsPuppi_pt;
   vector<float>   *jetsPuppi_shiftedEnDown;
   vector<float>   *jetsPuppi_shiftedEnUp;
   vector<float>   *jetsPuppi_smearedRes;
   vector<float>   *jetsPuppi_smearedResDown;
   vector<float>   *jetsPuppi_smearedResUp;
   vector<float>   *jetsPuppi_tightJetID;
   vector<float>   *jetsPuppi_vtxMass;
   vector<float>   *met_phi;
   vector<float>   *met_pt;
   vector<float>   *metNoHF_phi;
   vector<float>   *metNoHF_pt;
   vector<float>   *metPfMva_phi;
   vector<float>   *metPfMva_pt;
   vector<float>   *metPuppi_phi;
   vector<float>   *metPuppi_pt;
   vector<float>   *muons_dxy;
   vector<float>   *muons_dz;
   vector<float>   *muons_eta;
   vector<float>   *muons_isGlobal;
   vector<float>   *muons_isLoose;
   vector<float>   *muons_isPF;
   vector<float>   *muons_isTight;
   vector<float>   *muons_isTracker;
   vector<float>   *muons_m;
   vector<float>   *muons_matched;
   vector<float>   *muons_normalizedChi2;
   vector<float>   *muons_numberOfMatchedStations;
   vector<float>   *muons_numberOfValidMuonHits;
   vector<float>   *muons_numberOfValidPixelHits;
   vector<float>   *muons_phi;
   vector<float>   *muons_pt;
   vector<float>   *muons_q;
   vector<float>   *muons_relIso03;
   vector<float>   *muons_relIso04;
   vector<float>   *muons_trackerLayersWithMeasurement;
   vector<float>   *partonTop_eta;
   vector<float>   *partonTop_m;
   vector<float>   *partonTop_pdgId;
   vector<float>   *partonTop_phi;
   vector<float>   *partonTop_pt;
   vector<float>   *partonTop_q;
   vector<float>   *pseudoTop_eta;
   vector<float>   *pseudoTop_m;
   vector<float>   *pseudoTop_pdgId;
   vector<float>   *pseudoTop_phi;
   vector<float>   *pseudoTop_pt;
   vector<float>   *pseudoTop_q;
   vector<float>   *pseudoTopJet_eta;
   vector<float>   *pseudoTopJet_m;
   vector<float>   *pseudoTopJet_pdgId;
   vector<float>   *pseudoTopJet_phi;
   vector<float>   *pseudoTopJet_pt;
   vector<float>   *pseudoTopJet_q;
   vector<float>   *pseudoTopLepton_eta;
   vector<float>   *pseudoTopLepton_m;
   vector<float>   *pseudoTopLepton_pdgId;
   vector<float>   *pseudoTopLepton_phi;
   vector<float>   *pseudoTopLepton_pt;
   vector<float>   *pseudoTopLepton_q;
   vector<float>   *pseudoTopNu_eta;
   vector<float>   *pseudoTopNu_pdgId;
   vector<float>   *pseudoTopNu_phi;
   vector<float>   *pseudoTopNu_pt;

   // List of branches
   TBranch        *b_run;   //!
   TBranch        *b_lumi;   //!
   TBranch        *b_event;   //!
   TBranch        *b_filterRECO;   //!
   TBranch        *b_filterTrigELEL;   //!
   TBranch        *b_filterTrigMUEL;   //!
   TBranch        *b_filterTrigMUMU;   //!
   TBranch        *b_nGoodPV;   //!
   TBranch        *b_nPV;   //!
   TBranch        *b_NgenJet;   //!
   TBranch        *b_genTtbarId;   //!
   TBranch        *b_genTtbarLeptonDecay;   //!
   TBranch        *b_genWeightId1;   //!
   TBranch        *b_genWeightId2;   //!
   TBranch        *b_nTrueInteraction;   //!
   TBranch        *b_partonTopChannel;   //!
   TBranch        *b_genWeight;   //!
   TBranch        *b_genWeightQ;   //!
   TBranch        *b_genWeightX1;   //!
   TBranch        *b_genWeightX2;   //!
   TBranch        *b_lheWeight;   //!
   TBranch        *b_puWeight;   //!
   TBranch        *b_puWeightDn;   //!
   TBranch        *b_puWeightUp;   //!
   TBranch        *b_pdfWeight;   //!
   TBranch        *b_electrons_chIso03;   //!
   TBranch        *b_electrons_chIso04;   //!
   TBranch        *b_electrons_eta;   //!
   TBranch        *b_electrons_idHEEPV60;   //!
   TBranch        *b_electrons_idLoose;   //!
   TBranch        *b_electrons_idMedium;   //!
   TBranch        *b_electrons_idTight;   //!
   TBranch        *b_electrons_idVeto;   //!
   TBranch        *b_electrons_isPF;   //!
   TBranch        *b_electrons_m;   //!
   TBranch        *b_electrons_matched;   //!
   TBranch        *b_electrons_mvaMedium;   //!
   TBranch        *b_electrons_mvaNonTrigWp80;   //!
   TBranch        *b_electrons_mvaNonTrigWp90;   //!
   TBranch        *b_electrons_mvaTight;   //!
   TBranch        *b_electrons_nhIso03;   //!
   TBranch        *b_electrons_nhIso04;   //!
   TBranch        *b_electrons_passConversionVeto;   //!
   TBranch        *b_electrons_phIso03;   //!
   TBranch        *b_electrons_phIso04;   //!
   TBranch        *b_electrons_phi;   //!
   TBranch        *b_electrons_pt;   //!
   TBranch        *b_electrons_puChIso03;   //!
   TBranch        *b_electrons_puChIso04;   //!
   TBranch        *b_electrons_q;   //!
   TBranch        *b_electrons_relIso03;   //!
   TBranch        *b_electrons_relIso04;   //!
   TBranch        *b_electrons_scEta;   //!
   TBranch        *b_jets_CSVInclV2;   //!
   TBranch        *b_jets_LooseId;   //!
   TBranch        *b_jets_TightId;   //!
   TBranch        *b_jets_eta;   //!
   TBranch        *b_jets_hadronFlavour;   //!
   TBranch        *b_jets_looseJetID;   //!
   TBranch        *b_jets_m;   //!
   TBranch        *b_jets_partonFlavour;   //!
   TBranch        *b_jets_phi;   //!
   TBranch        *b_jets_pileupJetId;   //!
   TBranch        *b_jets_pt;   //!
   TBranch        *b_jets_shiftedEnDown;   //!
   TBranch        *b_jets_shiftedEnUp;   //!
   TBranch        *b_jets_smearedRes;   //!
   TBranch        *b_jets_smearedResDown;   //!
   TBranch        *b_jets_smearedResUp;   //!
   TBranch        *b_jets_tightJetID;   //!
   TBranch        *b_jets_vtxMass;   //!
   TBranch        *b_jetsPuppi_CSVInclV2;   //!
   TBranch        *b_jetsPuppi_LooseId;   //!
   TBranch        *b_jetsPuppi_TightId;   //!
   TBranch        *b_jetsPuppi_eta;   //!
   TBranch        *b_jetsPuppi_hadronFlavour;   //!
   TBranch        *b_jetsPuppi_looseJetID;   //!
   TBranch        *b_jetsPuppi_m;   //!
   TBranch        *b_jetsPuppi_partonFlavour;   //!
   TBranch        *b_jetsPuppi_phi;   //!
   TBranch        *b_jetsPuppi_pileupJetId;   //!
   TBranch        *b_jetsPuppi_pt;   //!
   TBranch        *b_jetsPuppi_shiftedEnDown;   //!
   TBranch        *b_jetsPuppi_shiftedEnUp;   //!
   TBranch        *b_jetsPuppi_smearedRes;   //!
   TBranch        *b_jetsPuppi_smearedResDown;   //!
   TBranch        *b_jetsPuppi_smearedResUp;   //!
   TBranch        *b_jetsPuppi_tightJetID;   //!
   TBranch        *b_jetsPuppi_vtxMass;   //!
   TBranch        *b_met_phi;   //!
   TBranch        *b_met_pt;   //!
   TBranch        *b_metNoHF_phi;   //!
   TBranch        *b_metNoHF_pt;   //!
   TBranch        *b_metPfMva_phi;   //!
   TBranch        *b_metPfMva_pt;   //!
   TBranch        *b_metPuppi_phi;   //!
   TBranch        *b_metPuppi_pt;   //!
   TBranch        *b_muons_dxy;   //!
   TBranch        *b_muons_dz;   //!
   TBranch        *b_muons_eta;   //!
   TBranch        *b_muons_isGlobal;   //!
   TBranch        *b_muons_isLoose;   //!
   TBranch        *b_muons_isPF;   //!
   TBranch        *b_muons_isTight;   //!
   TBranch        *b_muons_isTracker;   //!
   TBranch        *b_muons_m;   //!
   TBranch        *b_muons_matched;   //!
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
   virtual void     Loop(bool isMC_);
   //virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);

   virtual float    SF_muon(float pt, float eta);
   virtual float    SF_electron(float pt, float eta);

   virtual void fillCSVhistos(TFile *fileHF, TFile *fileLF);
   //virtual float get_csv_wgt( std::vector<double> jetPts, std::vector<double> jetEtas, std::vector<double> jetCSVs, std::vector<int> jetFlavors, 
   virtual float get_csv_wgt( std::vector<float>* jetPts, std::vector<float>* jetEtas, std::vector<float>* jetCSVs, std::vector<float>* jetFlavors, 
                                  int iSys, double &csvWgtHF, double &csvWgtLF, double &csvWgtCF );
// CSV reweighting
TH1D* h_csv_wgt_hf[9][6];
TH1D* c_csv_wgt_hf[9][6];
TH1D* h_csv_wgt_lf[9][4][3];


};

#endif

#ifdef CATNtuple_cxx
CATNtuple::CATNtuple(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/xrootd/store/user/youngjo/Cattools/v7-4-3/TTJets_aMC/ntuple_002.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("/xrootd/store/user/youngjo/Cattools/v7-4-3/TTJets_aMC/ntuple_002.root");
      }
      TDirectory * dir = (TDirectory*)f->Get("/xrootd/store/user/youngjo/Cattools/v7-4-3/TTJets_aMC/ntuple_002.root:/ntuple");
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
   electrons_chIso03 = 0;
   electrons_chIso04 = 0;
   electrons_eta = 0;
   electrons_idHEEPV60 = 0;
   electrons_idLoose = 0;
   electrons_idMedium = 0;
   electrons_idTight = 0;
   electrons_idVeto = 0;
   electrons_isPF = 0;
   electrons_m = 0;
   electrons_matched = 0;
   electrons_mvaMedium = 0;
   electrons_mvaNonTrigWp80 = 0;
   electrons_mvaNonTrigWp90 = 0;
   electrons_mvaTight = 0;
   electrons_nhIso03 = 0;
   electrons_nhIso04 = 0;
   electrons_passConversionVeto = 0;
   electrons_phIso03 = 0;
   electrons_phIso04 = 0;
   electrons_phi = 0;
   electrons_pt = 0;
   electrons_puChIso03 = 0;
   electrons_puChIso04 = 0;
   electrons_q = 0;
   electrons_relIso03 = 0;
   electrons_relIso04 = 0;
   electrons_scEta = 0;
   jets_CSVInclV2 = 0;
   jets_LooseId = 0;
   jets_TightId = 0;
   jets_eta = 0;
   jets_hadronFlavour = 0;
   jets_looseJetID = 0;
   jets_m = 0;
   jets_partonFlavour = 0;
   jets_phi = 0;
   jets_pileupJetId = 0;
   jets_pt = 0;
   jets_shiftedEnDown = 0;
   jets_shiftedEnUp = 0;
   jets_smearedRes = 0;
   jets_smearedResDown = 0;
   jets_smearedResUp = 0;
   jets_tightJetID = 0;
   jets_vtxMass = 0;
   jetsPuppi_CSVInclV2 = 0;
   jetsPuppi_LooseId = 0;
   jetsPuppi_TightId = 0;
   jetsPuppi_eta = 0;
   jetsPuppi_hadronFlavour = 0;
   jetsPuppi_looseJetID = 0;
   jetsPuppi_m = 0;
   jetsPuppi_partonFlavour = 0;
   jetsPuppi_phi = 0;
   jetsPuppi_pileupJetId = 0;
   jetsPuppi_pt = 0;
   jetsPuppi_shiftedEnDown = 0;
   jetsPuppi_shiftedEnUp = 0;
   jetsPuppi_smearedRes = 0;
   jetsPuppi_smearedResDown = 0;
   jetsPuppi_smearedResUp = 0;
   jetsPuppi_tightJetID = 0;
   jetsPuppi_vtxMass = 0;
   met_phi = 0;
   met_pt = 0;
   metNoHF_phi = 0;
   metNoHF_pt = 0;
   metPfMva_phi = 0;
   metPfMva_pt = 0;
   metPuppi_phi = 0;
   metPuppi_pt = 0;
   muons_dxy = 0;
   muons_dz = 0;
   muons_eta = 0;
   muons_isGlobal = 0;
   muons_isLoose = 0;
   muons_isPF = 0;
   muons_isTight = 0;
   muons_isTracker = 0;
   muons_m = 0;
   muons_matched = 0;
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
   fChain->SetBranchAddress("filterRECO", &filterRECO, &b_filterRECO);
   fChain->SetBranchAddress("filterTrigELEL", &filterTrigELEL, &b_filterTrigELEL);
   fChain->SetBranchAddress("filterTrigMUEL", &filterTrigMUEL, &b_filterTrigMUEL);
   fChain->SetBranchAddress("filterTrigMUMU", &filterTrigMUMU, &b_filterTrigMUMU);
   fChain->SetBranchAddress("nGoodPV", &nGoodPV, &b_nGoodPV);
   fChain->SetBranchAddress("nPV", &nPV, &b_nPV);
   fChain->SetBranchAddress("NgenJet", &NgenJet, &b_NgenJet);
   fChain->SetBranchAddress("genTtbarId", &genTtbarId, &b_genTtbarId);
   fChain->SetBranchAddress("genTtbarLeptonDecay", &genTtbarLeptonDecay, &b_genTtbarLeptonDecay);
   fChain->SetBranchAddress("genWeightId1", &genWeightId1, &b_genWeightId1);
   fChain->SetBranchAddress("genWeightId2", &genWeightId2, &b_genWeightId2);
   fChain->SetBranchAddress("nTrueInteraction", &nTrueInteraction, &b_nTrueInteraction);
   fChain->SetBranchAddress("partonTopChannel", &partonTopChannel, &b_partonTopChannel);
   fChain->SetBranchAddress("genWeight", &genWeight, &b_genWeight);
   fChain->SetBranchAddress("genWeightQ", &genWeightQ, &b_genWeightQ);
   fChain->SetBranchAddress("genWeightX1", &genWeightX1, &b_genWeightX1);
   fChain->SetBranchAddress("genWeightX2", &genWeightX2, &b_genWeightX2);
   fChain->SetBranchAddress("lheWeight", &lheWeight, &b_lheWeight);
   fChain->SetBranchAddress("puWeight", &puWeight, &b_puWeight);
   fChain->SetBranchAddress("puWeightDn", &puWeightDn, &b_puWeightDn);
   fChain->SetBranchAddress("puWeightUp", &puWeightUp, &b_puWeightUp);
   fChain->SetBranchAddress("pdfWeight", &pdfWeight, &b_pdfWeight);
   fChain->SetBranchAddress("electrons_chIso03", &electrons_chIso03, &b_electrons_chIso03);
   fChain->SetBranchAddress("electrons_chIso04", &electrons_chIso04, &b_electrons_chIso04);
   fChain->SetBranchAddress("electrons_eta", &electrons_eta, &b_electrons_eta);
   fChain->SetBranchAddress("electrons_idHEEPV60", &electrons_idHEEPV60, &b_electrons_idHEEPV60);
   fChain->SetBranchAddress("electrons_idLoose", &electrons_idLoose, &b_electrons_idLoose);
   fChain->SetBranchAddress("electrons_idMedium", &electrons_idMedium, &b_electrons_idMedium);
   fChain->SetBranchAddress("electrons_idTight", &electrons_idTight, &b_electrons_idTight);
   fChain->SetBranchAddress("electrons_idVeto", &electrons_idVeto, &b_electrons_idVeto);
   fChain->SetBranchAddress("electrons_isPF", &electrons_isPF, &b_electrons_isPF);
   fChain->SetBranchAddress("electrons_m", &electrons_m, &b_electrons_m);
   fChain->SetBranchAddress("electrons_matched", &electrons_matched, &b_electrons_matched);
   fChain->SetBranchAddress("electrons_mvaMedium", &electrons_mvaMedium, &b_electrons_mvaMedium);
   fChain->SetBranchAddress("electrons_mvaNonTrigWp80", &electrons_mvaNonTrigWp80, &b_electrons_mvaNonTrigWp80);
   fChain->SetBranchAddress("electrons_mvaNonTrigWp90", &electrons_mvaNonTrigWp90, &b_electrons_mvaNonTrigWp90);
   fChain->SetBranchAddress("electrons_mvaTight", &electrons_mvaTight, &b_electrons_mvaTight);
   fChain->SetBranchAddress("electrons_nhIso03", &electrons_nhIso03, &b_electrons_nhIso03);
   fChain->SetBranchAddress("electrons_nhIso04", &electrons_nhIso04, &b_electrons_nhIso04);
   fChain->SetBranchAddress("electrons_passConversionVeto", &electrons_passConversionVeto, &b_electrons_passConversionVeto);
   fChain->SetBranchAddress("electrons_phIso03", &electrons_phIso03, &b_electrons_phIso03);
   fChain->SetBranchAddress("electrons_phIso04", &electrons_phIso04, &b_electrons_phIso04);
   fChain->SetBranchAddress("electrons_phi", &electrons_phi, &b_electrons_phi);
   fChain->SetBranchAddress("electrons_pt", &electrons_pt, &b_electrons_pt);
   fChain->SetBranchAddress("electrons_puChIso03", &electrons_puChIso03, &b_electrons_puChIso03);
   fChain->SetBranchAddress("electrons_puChIso04", &electrons_puChIso04, &b_electrons_puChIso04);
   fChain->SetBranchAddress("electrons_q", &electrons_q, &b_electrons_q);
   fChain->SetBranchAddress("electrons_relIso03", &electrons_relIso03, &b_electrons_relIso03);
   fChain->SetBranchAddress("electrons_relIso04", &electrons_relIso04, &b_electrons_relIso04);
   fChain->SetBranchAddress("electrons_scEta", &electrons_scEta, &b_electrons_scEta);
   fChain->SetBranchAddress("jets_CSVInclV2", &jets_CSVInclV2, &b_jets_CSVInclV2);
   fChain->SetBranchAddress("jets_LooseId", &jets_LooseId, &b_jets_LooseId);
   fChain->SetBranchAddress("jets_TightId", &jets_TightId, &b_jets_TightId);
   fChain->SetBranchAddress("jets_eta", &jets_eta, &b_jets_eta);
   fChain->SetBranchAddress("jets_hadronFlavour", &jets_hadronFlavour, &b_jets_hadronFlavour);
   fChain->SetBranchAddress("jets_looseJetID", &jets_looseJetID, &b_jets_looseJetID);
   fChain->SetBranchAddress("jets_m", &jets_m, &b_jets_m);
   fChain->SetBranchAddress("jets_partonFlavour", &jets_partonFlavour, &b_jets_partonFlavour);
   fChain->SetBranchAddress("jets_phi", &jets_phi, &b_jets_phi);
   fChain->SetBranchAddress("jets_pileupJetId", &jets_pileupJetId, &b_jets_pileupJetId);
   fChain->SetBranchAddress("jets_pt", &jets_pt, &b_jets_pt);
   fChain->SetBranchAddress("jets_shiftedEnDown", &jets_shiftedEnDown, &b_jets_shiftedEnDown);
   fChain->SetBranchAddress("jets_shiftedEnUp", &jets_shiftedEnUp, &b_jets_shiftedEnUp);
   fChain->SetBranchAddress("jets_smearedRes", &jets_smearedRes, &b_jets_smearedRes);
   fChain->SetBranchAddress("jets_smearedResDown", &jets_smearedResDown, &b_jets_smearedResDown);
   fChain->SetBranchAddress("jets_smearedResUp", &jets_smearedResUp, &b_jets_smearedResUp);
   fChain->SetBranchAddress("jets_tightJetID", &jets_tightJetID, &b_jets_tightJetID);
   fChain->SetBranchAddress("jets_vtxMass", &jets_vtxMass, &b_jets_vtxMass);
   fChain->SetBranchAddress("jetsPuppi_CSVInclV2", &jetsPuppi_CSVInclV2, &b_jetsPuppi_CSVInclV2);
   fChain->SetBranchAddress("jetsPuppi_LooseId", &jetsPuppi_LooseId, &b_jetsPuppi_LooseId);
   fChain->SetBranchAddress("jetsPuppi_TightId", &jetsPuppi_TightId, &b_jetsPuppi_TightId);
   fChain->SetBranchAddress("jetsPuppi_eta", &jetsPuppi_eta, &b_jetsPuppi_eta);
   fChain->SetBranchAddress("jetsPuppi_hadronFlavour", &jetsPuppi_hadronFlavour, &b_jetsPuppi_hadronFlavour);
   fChain->SetBranchAddress("jetsPuppi_looseJetID", &jetsPuppi_looseJetID, &b_jetsPuppi_looseJetID);
   fChain->SetBranchAddress("jetsPuppi_m", &jetsPuppi_m, &b_jetsPuppi_m);
   fChain->SetBranchAddress("jetsPuppi_partonFlavour", &jetsPuppi_partonFlavour, &b_jetsPuppi_partonFlavour);
   fChain->SetBranchAddress("jetsPuppi_phi", &jetsPuppi_phi, &b_jetsPuppi_phi);
   fChain->SetBranchAddress("jetsPuppi_pileupJetId", &jetsPuppi_pileupJetId, &b_jetsPuppi_pileupJetId);
   fChain->SetBranchAddress("jetsPuppi_pt", &jetsPuppi_pt, &b_jetsPuppi_pt);
   fChain->SetBranchAddress("jetsPuppi_shiftedEnDown", &jetsPuppi_shiftedEnDown, &b_jetsPuppi_shiftedEnDown);
   fChain->SetBranchAddress("jetsPuppi_shiftedEnUp", &jetsPuppi_shiftedEnUp, &b_jetsPuppi_shiftedEnUp);
   fChain->SetBranchAddress("jetsPuppi_smearedRes", &jetsPuppi_smearedRes, &b_jetsPuppi_smearedRes);
   fChain->SetBranchAddress("jetsPuppi_smearedResDown", &jetsPuppi_smearedResDown, &b_jetsPuppi_smearedResDown);
   fChain->SetBranchAddress("jetsPuppi_smearedResUp", &jetsPuppi_smearedResUp, &b_jetsPuppi_smearedResUp);
   fChain->SetBranchAddress("jetsPuppi_tightJetID", &jetsPuppi_tightJetID, &b_jetsPuppi_tightJetID);
   fChain->SetBranchAddress("jetsPuppi_vtxMass", &jetsPuppi_vtxMass, &b_jetsPuppi_vtxMass);
   fChain->SetBranchAddress("met_phi", &met_phi, &b_met_phi);
   fChain->SetBranchAddress("met_pt", &met_pt, &b_met_pt);
   fChain->SetBranchAddress("metNoHF_phi", &metNoHF_phi, &b_metNoHF_phi);
   fChain->SetBranchAddress("metNoHF_pt", &metNoHF_pt, &b_metNoHF_pt);
   fChain->SetBranchAddress("metPfMva_phi", &metPfMva_phi, &b_metPfMva_phi);
   fChain->SetBranchAddress("metPfMva_pt", &metPfMva_pt, &b_metPfMva_pt);
   fChain->SetBranchAddress("metPuppi_phi", &metPuppi_phi, &b_metPuppi_phi);
   fChain->SetBranchAddress("metPuppi_pt", &metPuppi_pt, &b_metPuppi_pt);
   fChain->SetBranchAddress("muons_dxy", &muons_dxy, &b_muons_dxy);
   fChain->SetBranchAddress("muons_dz", &muons_dz, &b_muons_dz);
   fChain->SetBranchAddress("muons_eta", &muons_eta, &b_muons_eta);
   fChain->SetBranchAddress("muons_isGlobal", &muons_isGlobal, &b_muons_isGlobal);
   fChain->SetBranchAddress("muons_isLoose", &muons_isLoose, &b_muons_isLoose);
   fChain->SetBranchAddress("muons_isPF", &muons_isPF, &b_muons_isPF);
   fChain->SetBranchAddress("muons_isTight", &muons_isTight, &b_muons_isTight);
   fChain->SetBranchAddress("muons_isTracker", &muons_isTracker, &b_muons_isTracker);
   fChain->SetBranchAddress("muons_m", &muons_m, &b_muons_m);
   fChain->SetBranchAddress("muons_matched", &muons_matched, &b_muons_matched);
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
void CATNtuple::fillCSVhistos(TFile* fileHF, TFile* fileLF){
//https://twiki.cern.ch/twiki/bin/view/CMS/TTbarHbbRun2ReferenceAnalysis#Applying_CSV_weights
  for( int iSys=0; iSys<9; iSys++ ){
    for( int iPt=0; iPt<5; iPt++ ) h_csv_wgt_hf[iSys][iPt] = NULL;
    for( int iPt=0; iPt<3; iPt++ ){
      for( int iEta=0; iEta<3; iEta++ )h_csv_wgt_lf[iSys][iPt][iEta] = NULL;
    }
  }
  for( int iSys=0; iSys<5; iSys++ ){
    for( int iPt=0; iPt<5; iPt++ ) c_csv_wgt_hf[iSys][iPt] = NULL;
  }

  // CSV reweighting /// only care about the nominal ones
  for( int iSys=0; iSys<9; iSys++ ){
    TString syst_csv_suffix_hf = "final";
    TString syst_csv_suffix_c = "final";
    TString syst_csv_suffix_lf = "final";
    
    switch( iSys ){
    case 0:
      // this is the nominal case
      break;
    case 1:
      // JESUp
      syst_csv_suffix_hf = "final_JESUp"; syst_csv_suffix_lf = "final_JESUp";
      syst_csv_suffix_c  = "final_cErr1Up";
      break;
    case 2:
      // JESDown
      syst_csv_suffix_hf = "final_JESDown"; syst_csv_suffix_lf = "final_JESDown";
      syst_csv_suffix_c  = "final_cErr1Down";
      break;
    case 3:
      // purity up
      syst_csv_suffix_hf = "final_LFUp"; syst_csv_suffix_lf = "final_HFUp";
      syst_csv_suffix_c  = "final_cErr2Up";
      break;
    case 4:
      // purity down
      syst_csv_suffix_hf = "final_LFDown"; syst_csv_suffix_lf = "final_HFDown";
      syst_csv_suffix_c  = "final_cErr2Down";
      break;
    case 5:
      // stats1 up
      syst_csv_suffix_hf = "final_Stats1Up"; syst_csv_suffix_lf = "final_Stats1Up";
      break;
    case 6:
      // stats1 down
      syst_csv_suffix_hf = "final_Stats1Down"; syst_csv_suffix_lf = "final_Stats1Down";
      break;
    case 7:
      // stats2 up
      syst_csv_suffix_hf = "final_Stats2Up"; syst_csv_suffix_lf = "final_Stats2Up";
      break;
    case 8:
      // stats2 down
      syst_csv_suffix_hf = "final_Stats2Down"; syst_csv_suffix_lf = "final_Stats2Down";
      break;
    }

    for( int iPt=0; iPt<6; iPt++ ) h_csv_wgt_hf[iSys][iPt] = (TH1D*)fileHF->Get( Form("csv_ratio_Pt%i_Eta0_%s",iPt,syst_csv_suffix_hf.Data()) );

    if( iSys<5 ){
      for( int iPt=0; iPt<6; iPt++ ) c_csv_wgt_hf[iSys][iPt] = (TH1D*)fileHF->Get( Form("c_csv_ratio_Pt%i_Eta0_%s",iPt,syst_csv_suffix_c.Data()) );
    }
    
    for( int iPt=0; iPt<4; iPt++ ){
      for( int iEta=0; iEta<3; iEta++ )h_csv_wgt_lf[iSys][iPt][iEta] = (TH1D*)fileLF->Get( Form("csv_ratio_Pt%i_Eta%i_%s",iPt,iEta,syst_csv_suffix_lf.Data()) );
    }
  }

  return;
}
#endif // #ifdef CATNtuple_cxx
