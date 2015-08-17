//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon Aug 17 13:28:11 2015 by ROOT version 6.02/05
// from TTree event/event
// found on file: ../ntuple_TT_powheg.root
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
   Bool_t          CSCTightHaloFilter;
   Bool_t          EcalDeadCellTriggerPrimitiveFilter;
   Bool_t          HBHENoiseFilter;
   Bool_t          eeBadScFilter;
   Bool_t          goodVertices;
   Int_t           HLTDoubleEle33CaloIdLGsfTrkIdVL;
   Int_t           HLTEle12CaloIdLTrackIdLIsoVL;
   Int_t           HLTEle16Ele12Ele8CaloIdLTrackIdL;
   Int_t           HLTEle17CaloIdLTrackIdLIsoVL;
   Int_t           HLTEle17Ele12CaloIdLTrackIdLIsoVLDZ;
   Int_t           HLTEle23Ele12CaloIdLTrackIdLIsoVL;
   Int_t           HLTEle23Ele12CaloIdLTrackIdLIsoVLDZ;
   Int_t           HLTEle27eta2p1WPLooseGsfTriCentralPFJet30;
   Int_t           HLTMu17Mu8DZ;
   Int_t           HLTMu17TkMu8DZ;
   Int_t           HLTMu17TrkIsoVVLEle12CaloIdLTrackIdLIsoVL;
   Int_t           HLTMu17TrkIsoVVLMu8TrkIsoVVL;
   Int_t           HLTMu17TrkIsoVVLMu8TrkIsoVVLDZ;
   Int_t           HLTMu17TrkIsoVVLTkMu8TrkIsoVVL;
   Int_t           HLTMu8TrkIsoVVLEle17CaloIdLTrackIdLIsoVL;
   Int_t           NgenJet;
   Int_t           genTtbarId;
   Int_t           genTtbarLeptonDecay;
   Int_t           nGoodPV;
   Int_t           nPV;
   Int_t           nTrueInteraction;
   Int_t           pdfWeightId1;
   Int_t           pdfWeightId2;
   Double_t        pdfWeightQ;
   Double_t        pdfWeightX1;
   Double_t        pdfWeightX2;
   Double_t        puWeight;
   Double_t        puWeightDn;
   Double_t        puWeightUp;
   vector<double>  *pdfWeight;
   vector<double>  *electrons_chIso03;
   vector<double>  *electrons_chIso04;
   vector<double>  *electrons_eta;
   vector<double>  *electrons_idHEEP51;
   vector<double>  *electrons_idLoose;
   vector<double>  *electrons_idMedium;
   vector<double>  *electrons_idTeto;
   vector<double>  *electrons_idTight;
   vector<double>  *electrons_m;
   vector<double>  *electrons_nhIso03;
   vector<double>  *electrons_nhIso04;
   vector<double>  *electrons_phIso03;
   vector<double>  *electrons_phIso04;
   vector<double>  *electrons_phi;
   vector<double>  *electrons_pt;
   vector<double>  *electrons_puChIso03;
   vector<double>  *electrons_puChIso04;
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
   vector<double>  *jetsPuppi_CSVInclV2;
   vector<double>  *jetsPuppi_eta;
   vector<double>  *jetsPuppi_hadronFlavour;
   vector<double>  *jetsPuppi_m;
   vector<double>  *jetsPuppi_partonFlavour;
   vector<double>  *jetsPuppi_phi;
   vector<double>  *jetsPuppi_pt;
   vector<double>  *jetsPuppi_vtxMass;
   vector<double>  *met_phi;
   vector<double>  *met_pt;
   vector<double>  *metNoHF_phi;
   vector<double>  *metNoHF_pt;
   vector<double>  *metPfMva_phi;
   vector<double>  *metPfMva_pt;
   vector<double>  *metPuppi_phi;
   vector<double>  *metPuppi_pt;
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
   vector<double>  *slimmedGenJets_eta;
   vector<double>  *slimmedGenJets_m;
   vector<double>  *slimmedGenJets_phi;
   vector<double>  *slimmedGenJets_pt;

   // List of branches
   TBranch        *b_run;   //!
   TBranch        *b_lumi;   //!
   TBranch        *b_event;   //!
   TBranch        *b_CSCTightHaloFilter;   //!
   TBranch        *b_EcalDeadCellTriggerPrimitiveFilter;   //!
   TBranch        *b_HBHENoiseFilter;   //!
   TBranch        *b_eeBadScFilter;   //!
   TBranch        *b_goodVertices;   //!
   TBranch        *b_HLTDoubleEle33CaloIdLGsfTrkIdVL;   //!
   TBranch        *b_HLTEle12CaloIdLTrackIdLIsoVL;   //!
   TBranch        *b_HLTEle16Ele12Ele8CaloIdLTrackIdL;   //!
   TBranch        *b_HLTEle17CaloIdLTrackIdLIsoVL;   //!
   TBranch        *b_HLTEle17Ele12CaloIdLTrackIdLIsoVLDZ;   //!
   TBranch        *b_HLTEle23Ele12CaloIdLTrackIdLIsoVL;   //!
   TBranch        *b_HLTEle23Ele12CaloIdLTrackIdLIsoVLDZ;   //!
   TBranch        *b_HLTEle27eta2p1WPLooseGsfTriCentralPFJet30;   //!
   TBranch        *b_HLTMu17Mu8DZ;   //!
   TBranch        *b_HLTMu17TkMu8DZ;   //!
   TBranch        *b_HLTMu17TrkIsoVVLEle12CaloIdLTrackIdLIsoVL;   //!
   TBranch        *b_HLTMu17TrkIsoVVLMu8TrkIsoVVL;   //!
   TBranch        *b_HLTMu17TrkIsoVVLMu8TrkIsoVVLDZ;   //!
   TBranch        *b_HLTMu17TrkIsoVVLTkMu8TrkIsoVVL;   //!
   TBranch        *b_HLTMu8TrkIsoVVLEle17CaloIdLTrackIdLIsoVL;   //!
   TBranch        *b_NgenJet;   //!
   TBranch        *b_genTtbarId;   //!
   TBranch        *b_genTtbarLeptonDecay;   //!
   TBranch        *b_nGoodPV;   //!
   TBranch        *b_nPV;   //!
   TBranch        *b_nTrueInteraction;   //!
   TBranch        *b_pdfWeightId1;   //!
   TBranch        *b_pdfWeightId2;   //!
   TBranch        *b_pdfWeightQ;   //!
   TBranch        *b_pdfWeightX1;   //!
   TBranch        *b_pdfWeightX2;   //!
   TBranch        *b_puWeight;   //!
   TBranch        *b_puWeightDn;   //!
   TBranch        *b_puWeightUp;   //!
   TBranch        *b_pdfWeight;   //!
   TBranch        *b_electrons_chIso03;   //!
   TBranch        *b_electrons_chIso04;   //!
   TBranch        *b_electrons_eta;   //!
   TBranch        *b_electrons_idHEEP51;   //!
   TBranch        *b_electrons_idLoose;   //!
   TBranch        *b_electrons_idMedium;   //!
   TBranch        *b_electrons_idTeto;   //!
   TBranch        *b_electrons_idTight;   //!
   TBranch        *b_electrons_m;   //!
   TBranch        *b_electrons_nhIso03;   //!
   TBranch        *b_electrons_nhIso04;   //!
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
   TBranch        *b_jets_eta;   //!
   TBranch        *b_jets_hadronFlavour;   //!
   TBranch        *b_jets_m;   //!
   TBranch        *b_jets_partonFlavour;   //!
   TBranch        *b_jets_phi;   //!
   TBranch        *b_jets_pt;   //!
   TBranch        *b_jets_vtxMass;   //!
   TBranch        *b_jetsPuppi_CSVInclV2;   //!
   TBranch        *b_jetsPuppi_eta;   //!
   TBranch        *b_jetsPuppi_hadronFlavour;   //!
   TBranch        *b_jetsPuppi_m;   //!
   TBranch        *b_jetsPuppi_partonFlavour;   //!
   TBranch        *b_jetsPuppi_phi;   //!
   TBranch        *b_jetsPuppi_pt;   //!
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
   TBranch        *b_slimmedGenJets_eta;   //!
   TBranch        *b_slimmedGenJets_m;   //!
   TBranch        *b_slimmedGenJets_phi;   //!
   TBranch        *b_slimmedGenJets_pt;   //!

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
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("../ntuple_TT_powheg.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("../ntuple_TT_powheg.root");
      }
      TDirectory * dir = (TDirectory*)f->Get("../ntuple_TT_powheg.root:/ntuple");
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
   electrons_idHEEP51 = 0;
   electrons_idLoose = 0;
   electrons_idMedium = 0;
   electrons_idTeto = 0;
   electrons_idTight = 0;
   electrons_m = 0;
   electrons_nhIso03 = 0;
   electrons_nhIso04 = 0;
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
   jets_eta = 0;
   jets_hadronFlavour = 0;
   jets_m = 0;
   jets_partonFlavour = 0;
   jets_phi = 0;
   jets_pt = 0;
   jets_vtxMass = 0;
   jetsPuppi_CSVInclV2 = 0;
   jetsPuppi_eta = 0;
   jetsPuppi_hadronFlavour = 0;
   jetsPuppi_m = 0;
   jetsPuppi_partonFlavour = 0;
   jetsPuppi_phi = 0;
   jetsPuppi_pt = 0;
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
   slimmedGenJets_eta = 0;
   slimmedGenJets_m = 0;
   slimmedGenJets_phi = 0;
   slimmedGenJets_pt = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("run", &run, &b_run);
   fChain->SetBranchAddress("lumi", &lumi, &b_lumi);
   fChain->SetBranchAddress("event", &event, &b_event);
   fChain->SetBranchAddress("CSCTightHaloFilter", &CSCTightHaloFilter, &b_CSCTightHaloFilter);
   fChain->SetBranchAddress("EcalDeadCellTriggerPrimitiveFilter", &EcalDeadCellTriggerPrimitiveFilter, &b_EcalDeadCellTriggerPrimitiveFilter);
   fChain->SetBranchAddress("HBHENoiseFilter", &HBHENoiseFilter, &b_HBHENoiseFilter);
   fChain->SetBranchAddress("eeBadScFilter", &eeBadScFilter, &b_eeBadScFilter);
   fChain->SetBranchAddress("goodVertices", &goodVertices, &b_goodVertices);
   fChain->SetBranchAddress("HLTDoubleEle33CaloIdLGsfTrkIdVL", &HLTDoubleEle33CaloIdLGsfTrkIdVL, &b_HLTDoubleEle33CaloIdLGsfTrkIdVL);
   fChain->SetBranchAddress("HLTEle12CaloIdLTrackIdLIsoVL", &HLTEle12CaloIdLTrackIdLIsoVL, &b_HLTEle12CaloIdLTrackIdLIsoVL);
   fChain->SetBranchAddress("HLTEle16Ele12Ele8CaloIdLTrackIdL", &HLTEle16Ele12Ele8CaloIdLTrackIdL, &b_HLTEle16Ele12Ele8CaloIdLTrackIdL);
   fChain->SetBranchAddress("HLTEle17CaloIdLTrackIdLIsoVL", &HLTEle17CaloIdLTrackIdLIsoVL, &b_HLTEle17CaloIdLTrackIdLIsoVL);
   fChain->SetBranchAddress("HLTEle17Ele12CaloIdLTrackIdLIsoVLDZ", &HLTEle17Ele12CaloIdLTrackIdLIsoVLDZ, &b_HLTEle17Ele12CaloIdLTrackIdLIsoVLDZ);
   fChain->SetBranchAddress("HLTEle23Ele12CaloIdLTrackIdLIsoVL", &HLTEle23Ele12CaloIdLTrackIdLIsoVL, &b_HLTEle23Ele12CaloIdLTrackIdLIsoVL);
   fChain->SetBranchAddress("HLTEle23Ele12CaloIdLTrackIdLIsoVLDZ", &HLTEle23Ele12CaloIdLTrackIdLIsoVLDZ, &b_HLTEle23Ele12CaloIdLTrackIdLIsoVLDZ);
   fChain->SetBranchAddress("HLTEle27eta2p1WPLooseGsfTriCentralPFJet30", &HLTEle27eta2p1WPLooseGsfTriCentralPFJet30, &b_HLTEle27eta2p1WPLooseGsfTriCentralPFJet30);
   fChain->SetBranchAddress("HLTMu17Mu8DZ", &HLTMu17Mu8DZ, &b_HLTMu17Mu8DZ);
   fChain->SetBranchAddress("HLTMu17TkMu8DZ", &HLTMu17TkMu8DZ, &b_HLTMu17TkMu8DZ);
   fChain->SetBranchAddress("HLTMu17TrkIsoVVLEle12CaloIdLTrackIdLIsoVL", &HLTMu17TrkIsoVVLEle12CaloIdLTrackIdLIsoVL, &b_HLTMu17TrkIsoVVLEle12CaloIdLTrackIdLIsoVL);
   fChain->SetBranchAddress("HLTMu17TrkIsoVVLMu8TrkIsoVVL", &HLTMu17TrkIsoVVLMu8TrkIsoVVL, &b_HLTMu17TrkIsoVVLMu8TrkIsoVVL);
   fChain->SetBranchAddress("HLTMu17TrkIsoVVLMu8TrkIsoVVLDZ", &HLTMu17TrkIsoVVLMu8TrkIsoVVLDZ, &b_HLTMu17TrkIsoVVLMu8TrkIsoVVLDZ);
   fChain->SetBranchAddress("HLTMu17TrkIsoVVLTkMu8TrkIsoVVL", &HLTMu17TrkIsoVVLTkMu8TrkIsoVVL, &b_HLTMu17TrkIsoVVLTkMu8TrkIsoVVL);
   fChain->SetBranchAddress("HLTMu8TrkIsoVVLEle17CaloIdLTrackIdLIsoVL", &HLTMu8TrkIsoVVLEle17CaloIdLTrackIdLIsoVL, &b_HLTMu8TrkIsoVVLEle17CaloIdLTrackIdLIsoVL);
   fChain->SetBranchAddress("NgenJet", &NgenJet, &b_NgenJet);
   fChain->SetBranchAddress("genTtbarId", &genTtbarId, &b_genTtbarId);
   fChain->SetBranchAddress("genTtbarLeptonDecay", &genTtbarLeptonDecay, &b_genTtbarLeptonDecay);
   fChain->SetBranchAddress("nGoodPV", &nGoodPV, &b_nGoodPV);
   fChain->SetBranchAddress("nPV", &nPV, &b_nPV);
   fChain->SetBranchAddress("nTrueInteraction", &nTrueInteraction, &b_nTrueInteraction);
   fChain->SetBranchAddress("pdfWeightId1", &pdfWeightId1, &b_pdfWeightId1);
   fChain->SetBranchAddress("pdfWeightId2", &pdfWeightId2, &b_pdfWeightId2);
   fChain->SetBranchAddress("pdfWeightQ", &pdfWeightQ, &b_pdfWeightQ);
   fChain->SetBranchAddress("pdfWeightX1", &pdfWeightX1, &b_pdfWeightX1);
   fChain->SetBranchAddress("pdfWeightX2", &pdfWeightX2, &b_pdfWeightX2);
   fChain->SetBranchAddress("puWeight", &puWeight, &b_puWeight);
   fChain->SetBranchAddress("puWeightDn", &puWeightDn, &b_puWeightDn);
   fChain->SetBranchAddress("puWeightUp", &puWeightUp, &b_puWeightUp);
   fChain->SetBranchAddress("pdfWeight", &pdfWeight, &b_pdfWeight);
   fChain->SetBranchAddress("electrons_chIso03", &electrons_chIso03, &b_electrons_chIso03);
   fChain->SetBranchAddress("electrons_chIso04", &electrons_chIso04, &b_electrons_chIso04);
   fChain->SetBranchAddress("electrons_eta", &electrons_eta, &b_electrons_eta);
   fChain->SetBranchAddress("electrons_idHEEP51", &electrons_idHEEP51, &b_electrons_idHEEP51);
   fChain->SetBranchAddress("electrons_idLoose", &electrons_idLoose, &b_electrons_idLoose);
   fChain->SetBranchAddress("electrons_idMedium", &electrons_idMedium, &b_electrons_idMedium);
   fChain->SetBranchAddress("electrons_idTeto", &electrons_idTeto, &b_electrons_idTeto);
   fChain->SetBranchAddress("electrons_idTight", &electrons_idTight, &b_electrons_idTight);
   fChain->SetBranchAddress("electrons_m", &electrons_m, &b_electrons_m);
   fChain->SetBranchAddress("electrons_nhIso03", &electrons_nhIso03, &b_electrons_nhIso03);
   fChain->SetBranchAddress("electrons_nhIso04", &electrons_nhIso04, &b_electrons_nhIso04);
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
   fChain->SetBranchAddress("jets_eta", &jets_eta, &b_jets_eta);
   fChain->SetBranchAddress("jets_hadronFlavour", &jets_hadronFlavour, &b_jets_hadronFlavour);
   fChain->SetBranchAddress("jets_m", &jets_m, &b_jets_m);
   fChain->SetBranchAddress("jets_partonFlavour", &jets_partonFlavour, &b_jets_partonFlavour);
   fChain->SetBranchAddress("jets_phi", &jets_phi, &b_jets_phi);
   fChain->SetBranchAddress("jets_pt", &jets_pt, &b_jets_pt);
   fChain->SetBranchAddress("jets_vtxMass", &jets_vtxMass, &b_jets_vtxMass);
   fChain->SetBranchAddress("jetsPuppi_CSVInclV2", &jetsPuppi_CSVInclV2, &b_jetsPuppi_CSVInclV2);
   fChain->SetBranchAddress("jetsPuppi_eta", &jetsPuppi_eta, &b_jetsPuppi_eta);
   fChain->SetBranchAddress("jetsPuppi_hadronFlavour", &jetsPuppi_hadronFlavour, &b_jetsPuppi_hadronFlavour);
   fChain->SetBranchAddress("jetsPuppi_m", &jetsPuppi_m, &b_jetsPuppi_m);
   fChain->SetBranchAddress("jetsPuppi_partonFlavour", &jetsPuppi_partonFlavour, &b_jetsPuppi_partonFlavour);
   fChain->SetBranchAddress("jetsPuppi_phi", &jetsPuppi_phi, &b_jetsPuppi_phi);
   fChain->SetBranchAddress("jetsPuppi_pt", &jetsPuppi_pt, &b_jetsPuppi_pt);
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
   fChain->SetBranchAddress("slimmedGenJets_eta", &slimmedGenJets_eta, &b_slimmedGenJets_eta);
   fChain->SetBranchAddress("slimmedGenJets_m", &slimmedGenJets_m, &b_slimmedGenJets_m);
   fChain->SetBranchAddress("slimmedGenJets_phi", &slimmedGenJets_phi, &b_slimmedGenJets_phi);
   fChain->SetBranchAddress("slimmedGenJets_pt", &slimmedGenJets_pt, &b_slimmedGenJets_pt);
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
