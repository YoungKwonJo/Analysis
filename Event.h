//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Mar  5 07:45:59 2014 by ROOT version 5.32/00
// from TTree event/Mixed event tree
// found on file: /afs/cern.ch/work/y/youngjo/public/For8Tev/KrAFT_20140224/TTJets_FullLeptMGDecays_8TeV-madgraph-tauola_396.root
//////////////////////////////////////////////////////////

#ifndef Event_h
#define Event_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include <vector>
#include <vector>
#include <vector>
#include "CSVWeight.h"
#include <TLorentzVector.h>

// Fixed size dimensions of array or collections stored in the TTree if any.
using namespace std;
enum LeptonType {
    Muon,
    Electron
};

class Event {
public :
   CSVWeight *csvWgt;// = new CSVWeight();

   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Int_t           run;
   Int_t           lumi;
   Int_t           event;
   Double_t        puWeight;
   Double_t        puWeightUp;
   Double_t        puWeightDn;
   Int_t           nVertex;
   Int_t           nPileup;
   vector<double>  *muons_pt;
   vector<double>  *muons_eta;
   vector<double>  *muons_phi;
   vector<double>  *muons_m;
   vector<int>     *muons_Q;
   vector<unsigned int> *muons_type;
   vector<double>  *muons_relIso;
   vector<double>  *electrons_pt;
   vector<double>  *electrons_eta;
   vector<double>  *electrons_phi;
   vector<double>  *electrons_m;
   vector<int>     *electrons_Q;
   vector<unsigned int> *electrons_type;
   vector<double>  *electrons_relIso;
   vector<double>  *electrons_mva;
   vector<double>  *electrons_scEta;
   vector<unsigned int> *electrons_qConsistent;
   vector<double>  *jets_pt;
   vector<double>  *jets_eta;
   vector<double>  *jets_phi;
   vector<double>  *jets_m;
   vector<double>  *jets_bTag;
   vector<double>  *jets_partonflavor;
   vector<double>  *jets_JESUp;
   vector<double>  *jets_JESDn;
   Double_t        met_pt;
   Double_t        metJESUp_pt;
   Double_t        metJESDn_pt;
   Double_t        met_phi;
   Double_t        metJESUp_phi;
   Double_t        metJESDn_phi;
   vector<double>  *jpsis_pt;
   vector<double>  *jpsis_eta;
   vector<double>  *jpsis_phi;
   vector<double>  *jpsis_m;
   vector<double>  *jpsis_lxy;
   vector<double>  *jpsis_pt1;
   vector<double>  *jpsis_eta1;
   vector<double>  *jpsis_phi1;
   vector<double>  *jpsis_pt2;
   vector<double>  *jpsis_eta2;
   vector<double>  *jpsis_phi2;
   vector<int>     *jpsis_nPixHits1;
   vector<int>     *jpsis_nPixHits2;
   vector<double>  *pdfWeights;
   Int_t           gluon2t_N;
   vector<double>  *jets_JER;
   vector<double>  *jets_JERUp;
   vector<double>  *jets_JERDn;
   Double_t        metJER_pt;
   Double_t        metJERUp_pt;
   Double_t        metJERDn_pt;
   Double_t        metJER_phi;
   Double_t        metJERUp_phi;
   Double_t        metJERDn_phi;
   Double_t        genWeight;
   Int_t           pdf_id1;
   Int_t           pdf_id2;
   Double_t        pdf_x1;
   Double_t        pdf_x2;
   Double_t        pdf_q;
   vector<double>  *genJets_pt;
   vector<double>  *genJets_eta;
   vector<double>  *genJets_phi;
   vector<double>  *genJets_m;
   vector<int>     *genJets_decayFromBHadron;
   vector<int>     *genJets_decayFromCHadron;
   vector<double>  *genParticles_pt;
   vector<double>  *genParticles_eta;
   vector<double>  *genParticles_phi;
   vector<double>  *genParticles_m;
   vector<int>     *genParticles_pdgId;
   vector<int>     *genParticles_mother;
   Double_t        genttbarM;
   Int_t           nGenJet20;
   Int_t           nGenbJet20;
   Int_t           nGenaddbJet20;
   Int_t           nGencJet20;
   Int_t           nGenJet40;
   Int_t           nGenbJet40;
   Int_t           nGenaddbJet40;
   Int_t           nGencJet40;
   Int_t           ttbarGen_dileptonic;
   Double_t        genLep1_pt;
   Double_t        genLep2_pt;
   Double_t        genLep1_eta;
   Double_t        genLep2_eta;

   // List of branches
   TBranch        *b_run;   //!
   TBranch        *b_lumi;   //!
   TBranch        *b_event;   //!
   TBranch        *b_puWeight;   //!
   TBranch        *b_puWeightUp;   //!
   TBranch        *b_puWeightDn;   //!
   TBranch        *b_nVertex;   //!
   TBranch        *b_nPileup;   //!
   TBranch        *b_muons_pt;   //!
   TBranch        *b_muons_eta;   //!
   TBranch        *b_muons_phi;   //!
   TBranch        *b_muons_m;   //!
   TBranch        *b_muons_Q;   //!
   TBranch        *b_muons_type;   //!
   TBranch        *b_muons_relIso;   //!
   TBranch        *b_electrons_pt;   //!
   TBranch        *b_electrons_eta;   //!
   TBranch        *b_electrons_phi;   //!
   TBranch        *b_electrons_m;   //!
   TBranch        *b_electrons_Q;   //!
   TBranch        *b_electrons_type;   //!
   TBranch        *b_electrons_relIso;   //!
   TBranch        *b_electrons_mva;   //!
   TBranch        *b_electrons_scEta;   //!
   TBranch        *b_electrons_qConsistent;   //!
   TBranch        *b_jets_pt;   //!
   TBranch        *b_jets_eta;   //!
   TBranch        *b_jets_phi;   //!
   TBranch        *b_jets_m;   //!
   TBranch        *b_jets_bTag;   //!
   TBranch        *b_jets_partonflavor;   //!
   TBranch        *b_jets_JESUp;   //!
   TBranch        *b_jets_JESDn;   //!
   TBranch        *b_met_pt;   //!
   TBranch        *b_metJESUp_pt;   //!
   TBranch        *b_metJESDn_pt;   //!
   TBranch        *b_met_phi;   //!
   TBranch        *b_metJESUp_phi;   //!
   TBranch        *b_metJESDn_phi;   //!
   TBranch        *b_jpsis_pt;   //!
   TBranch        *b_jpsis_eta;   //!
   TBranch        *b_jpsis_phi;   //!
   TBranch        *b_jpsis_m;   //!
   TBranch        *b_jpsis_lxy;   //!
   TBranch        *b_jpsis_pt1;   //!
   TBranch        *b_jpsis_eta1;   //!
   TBranch        *b_jpsis_phi1;   //!
   TBranch        *b_jpsis_pt2;   //!
   TBranch        *b_jpsis_eta2;   //!
   TBranch        *b_jpsis_phi2;   //!
   TBranch        *b_jpsis_nPixHits1;   //!
   TBranch        *b_jpsis_nPixHits2;   //!
   TBranch        *b_pdfWeights;   //!
   TBranch        *b_gluon2t_N;   //!
   TBranch        *b_jets_JER;   //!
   TBranch        *b_jets_JERUp;   //!
   TBranch        *b_jets_JERDn;   //!
   TBranch        *b_metJER_pt;   //!
   TBranch        *b_metJERUp_pt;   //!
   TBranch        *b_metJERDn_pt;   //!
   TBranch        *b_metJER_phi;   //!
   TBranch        *b_metJERUp_phi;   //!
   TBranch        *b_metJERDn_phi;   //!
   TBranch        *b_genWeight;   //!
   TBranch        *b_pdf_id1;   //!
   TBranch        *b_pdf_id2;   //!
   TBranch        *b_pdf_x1;   //!
   TBranch        *b_pdf_x2;   //!
   TBranch        *b_pdf_q;   //!
   TBranch        *b_genJets_pt;   //!
   TBranch        *b_genJets_eta;   //!
   TBranch        *b_genJets_phi;   //!
   TBranch        *b_genJets_m;   //!
   TBranch        *b_genJets_decayFromBHadron;   //!
   TBranch        *b_genJets_decayFromCHadron;   //!
   TBranch        *b_genParticles_pt;   //!
   TBranch        *b_genParticles_eta;   //!
   TBranch        *b_genParticles_phi;   //!
   TBranch        *b_genParticles_m;   //!
   TBranch        *b_genParticles_pdgId;   //!
   TBranch        *b_genParticles_mother;   //!
   TBranch        *b_genttbarM;   //!
   TBranch        *b_nGenJet20;   //!
   TBranch        *b_nGenbJet20;   //!
   TBranch        *b_nGenaddbJet20;   //!
   TBranch        *b_nGencJet20;   //!
   TBranch        *b_nGenJet40;   //!
   TBranch        *b_nGenbJet40;   //!
   TBranch        *b_nGenaddbJet40;   //!
   TBranch        *b_nGencJet40;   //!
   TBranch        *b_ttbarGen_dileptonic;   //!
   TBranch        *b_genLep1_pt;   //!
   TBranch        *b_genLep2_pt;   //!
   TBranch        *b_genLep1_eta;   //!
   TBranch        *b_genLep2_eta;   //!

   Event(TTree *tree=0);
   virtual ~Event();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop(char *Name,double weight,int isZ,int v,char* DecayMode,bool isMC);
   virtual double   SF(double pt, double eta, LeptonType type);
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef Event_cxx
Event::Event(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/afs/cern.ch/work/y/youngjo/public/For8Tev/KrAFT_20140224/TTJets_FullLeptMGDecays_8TeV-madgraph-tauola_396.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("/afs/cern.ch/work/y/youngjo/public/For8Tev/KrAFT_20140224/TTJets_FullLeptMGDecays_8TeV-madgraph-tauola_396.root");
      }
      TDirectory * dir = (TDirectory*)f->Get("/afs/cern.ch/work/y/youngjo/public/For8Tev/KrAFT_20140224/TTJets_FullLeptMGDecays_8TeV-madgraph-tauola_396.root:/MuMu");
      dir->GetObject("event",tree);

   }
   Init(tree);
   csvWgt = new CSVWeight();
}

Event::~Event()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t Event::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t Event::LoadTree(Long64_t entry)
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

void Event::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   muons_pt = 0;
   muons_eta = 0;
   muons_phi = 0;
   muons_m = 0;
   muons_Q = 0;
   muons_type = 0;
   muons_relIso = 0;
   electrons_pt = 0;
   electrons_eta = 0;
   electrons_phi = 0;
   electrons_m = 0;
   electrons_Q = 0;
   electrons_type = 0;
   electrons_relIso = 0;
   electrons_mva = 0;
   electrons_scEta = 0;
   electrons_qConsistent = 0;
   jets_pt = 0;
   jets_eta = 0;
   jets_phi = 0;
   jets_m = 0;
   jets_bTag = 0;
   jets_partonflavor = 0;
   jets_JESUp = 0;
   jets_JESDn = 0;
   jpsis_pt = 0;
   jpsis_eta = 0;
   jpsis_phi = 0;
   jpsis_m = 0;
   jpsis_lxy = 0;
   jpsis_pt1 = 0;
   jpsis_eta1 = 0;
   jpsis_phi1 = 0;
   jpsis_pt2 = 0;
   jpsis_eta2 = 0;
   jpsis_phi2 = 0;
   jpsis_nPixHits1 = 0;
   jpsis_nPixHits2 = 0;
   pdfWeights = 0;
   jets_JER = 0;
   jets_JERUp = 0;
   jets_JERDn = 0;
   genJets_pt = 0;
   genJets_eta = 0;
   genJets_phi = 0;
   genJets_m = 0;
   genJets_decayFromBHadron = 0;
   genJets_decayFromCHadron = 0;
   genParticles_pt = 0;
   genParticles_eta = 0;
   genParticles_phi = 0;
   genParticles_m = 0;
   genParticles_pdgId = 0;
   genParticles_mother = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("run", &run, &b_run);
   fChain->SetBranchAddress("lumi", &lumi, &b_lumi);
   fChain->SetBranchAddress("event", &event, &b_event);
   fChain->SetBranchAddress("puWeight", &puWeight, &b_puWeight);
   fChain->SetBranchAddress("puWeightUp", &puWeightUp, &b_puWeightUp);
   fChain->SetBranchAddress("puWeightDn", &puWeightDn, &b_puWeightDn);
   fChain->SetBranchAddress("nVertex", &nVertex, &b_nVertex);
   fChain->SetBranchAddress("nPileup", &nPileup, &b_nPileup);
   fChain->SetBranchAddress("muons_pt", &muons_pt, &b_muons_pt);
   fChain->SetBranchAddress("muons_eta", &muons_eta, &b_muons_eta);
   fChain->SetBranchAddress("muons_phi", &muons_phi, &b_muons_phi);
   fChain->SetBranchAddress("muons_m", &muons_m, &b_muons_m);
   fChain->SetBranchAddress("muons_Q", &muons_Q, &b_muons_Q);
   fChain->SetBranchAddress("muons_type", &muons_type, &b_muons_type);
   fChain->SetBranchAddress("muons_relIso", &muons_relIso, &b_muons_relIso);
   fChain->SetBranchAddress("electrons_pt", &electrons_pt, &b_electrons_pt);
   fChain->SetBranchAddress("electrons_eta", &electrons_eta, &b_electrons_eta);
   fChain->SetBranchAddress("electrons_phi", &electrons_phi, &b_electrons_phi);
   fChain->SetBranchAddress("electrons_m", &electrons_m, &b_electrons_m);
   fChain->SetBranchAddress("electrons_Q", &electrons_Q, &b_electrons_Q);
   fChain->SetBranchAddress("electrons_type", &electrons_type, &b_electrons_type);
   fChain->SetBranchAddress("electrons_relIso", &electrons_relIso, &b_electrons_relIso);
   fChain->SetBranchAddress("electrons_mva", &electrons_mva, &b_electrons_mva);
   fChain->SetBranchAddress("electrons_scEta", &electrons_scEta, &b_electrons_scEta);
   fChain->SetBranchAddress("electrons_qConsistent", &electrons_qConsistent, &b_electrons_qConsistent);
   fChain->SetBranchAddress("jets_pt", &jets_pt, &b_jets_pt);
   fChain->SetBranchAddress("jets_eta", &jets_eta, &b_jets_eta);
   fChain->SetBranchAddress("jets_phi", &jets_phi, &b_jets_phi);
   fChain->SetBranchAddress("jets_m", &jets_m, &b_jets_m);
   fChain->SetBranchAddress("jets_bTag", &jets_bTag, &b_jets_bTag);
   fChain->SetBranchAddress("jets_partonflavor", &jets_partonflavor, &b_jets_partonflavor);
   fChain->SetBranchAddress("jets_JESUp", &jets_JESUp, &b_jets_JESUp);
   fChain->SetBranchAddress("jets_JESDn", &jets_JESDn, &b_jets_JESDn);
   fChain->SetBranchAddress("met_pt", &met_pt, &b_met_pt);
   fChain->SetBranchAddress("metJESUp_pt", &metJESUp_pt, &b_metJESUp_pt);
   fChain->SetBranchAddress("metJESDn_pt", &metJESDn_pt, &b_metJESDn_pt);
   fChain->SetBranchAddress("met_phi", &met_phi, &b_met_phi);
   fChain->SetBranchAddress("metJESUp_phi", &metJESUp_phi, &b_metJESUp_phi);
   fChain->SetBranchAddress("metJESDn_phi", &metJESDn_phi, &b_metJESDn_phi);
   fChain->SetBranchAddress("jpsis_pt", &jpsis_pt, &b_jpsis_pt);
   fChain->SetBranchAddress("jpsis_eta", &jpsis_eta, &b_jpsis_eta);
   fChain->SetBranchAddress("jpsis_phi", &jpsis_phi, &b_jpsis_phi);
   fChain->SetBranchAddress("jpsis_m", &jpsis_m, &b_jpsis_m);
   fChain->SetBranchAddress("jpsis_lxy", &jpsis_lxy, &b_jpsis_lxy);
   fChain->SetBranchAddress("jpsis_pt1", &jpsis_pt1, &b_jpsis_pt1);
   fChain->SetBranchAddress("jpsis_eta1", &jpsis_eta1, &b_jpsis_eta1);
   fChain->SetBranchAddress("jpsis_phi1", &jpsis_phi1, &b_jpsis_phi1);
   fChain->SetBranchAddress("jpsis_pt2", &jpsis_pt2, &b_jpsis_pt2);
   fChain->SetBranchAddress("jpsis_eta2", &jpsis_eta2, &b_jpsis_eta2);
   fChain->SetBranchAddress("jpsis_phi2", &jpsis_phi2, &b_jpsis_phi2);
   fChain->SetBranchAddress("jpsis_nPixHits1", &jpsis_nPixHits1, &b_jpsis_nPixHits1);
   fChain->SetBranchAddress("jpsis_nPixHits2", &jpsis_nPixHits2, &b_jpsis_nPixHits2);
   fChain->SetBranchAddress("pdfWeights", &pdfWeights, &b_pdfWeights);
   fChain->SetBranchAddress("gluon2t_N", &gluon2t_N, &b_gluon2t_N);
   fChain->SetBranchAddress("jets_JER", &jets_JER, &b_jets_JER);
   fChain->SetBranchAddress("jets_JERUp", &jets_JERUp, &b_jets_JERUp);
   fChain->SetBranchAddress("jets_JERDn", &jets_JERDn, &b_jets_JERDn);
   fChain->SetBranchAddress("metJER_pt", &metJER_pt, &b_metJER_pt);
   fChain->SetBranchAddress("metJERUp_pt", &metJERUp_pt, &b_metJERUp_pt);
   fChain->SetBranchAddress("metJERDn_pt", &metJERDn_pt, &b_metJERDn_pt);
   fChain->SetBranchAddress("metJER_phi", &metJER_phi, &b_metJER_phi);
   fChain->SetBranchAddress("metJERUp_phi", &metJERUp_phi, &b_metJERUp_phi);
   fChain->SetBranchAddress("metJERDn_phi", &metJERDn_phi, &b_metJERDn_phi);
   fChain->SetBranchAddress("genWeight", &genWeight, &b_genWeight);
   fChain->SetBranchAddress("pdf_id1", &pdf_id1, &b_pdf_id1);
   fChain->SetBranchAddress("pdf_id2", &pdf_id2, &b_pdf_id2);
   fChain->SetBranchAddress("pdf_x1", &pdf_x1, &b_pdf_x1);
   fChain->SetBranchAddress("pdf_x2", &pdf_x2, &b_pdf_x2);
   fChain->SetBranchAddress("pdf_q", &pdf_q, &b_pdf_q);
   fChain->SetBranchAddress("genJets_pt", &genJets_pt, &b_genJets_pt);
   fChain->SetBranchAddress("genJets_eta", &genJets_eta, &b_genJets_eta);
   fChain->SetBranchAddress("genJets_phi", &genJets_phi, &b_genJets_phi);
   fChain->SetBranchAddress("genJets_m", &genJets_m, &b_genJets_m);
   fChain->SetBranchAddress("genJets_decayFromBHadron", &genJets_decayFromBHadron, &b_genJets_decayFromBHadron);
   fChain->SetBranchAddress("genJets_decayFromCHadron", &genJets_decayFromCHadron, &b_genJets_decayFromCHadron);
   fChain->SetBranchAddress("genParticles_pt", &genParticles_pt, &b_genParticles_pt);
   fChain->SetBranchAddress("genParticles_eta", &genParticles_eta, &b_genParticles_eta);
   fChain->SetBranchAddress("genParticles_phi", &genParticles_phi, &b_genParticles_phi);
   fChain->SetBranchAddress("genParticles_m", &genParticles_m, &b_genParticles_m);
   fChain->SetBranchAddress("genParticles_pdgId", &genParticles_pdgId, &b_genParticles_pdgId);
   fChain->SetBranchAddress("genParticles_mother", &genParticles_mother, &b_genParticles_mother);
   fChain->SetBranchAddress("genttbarM", &genttbarM, &b_genttbarM);
   fChain->SetBranchAddress("nGenJet20", &nGenJet20, &b_nGenJet20);
   fChain->SetBranchAddress("nGenbJet20", &nGenbJet20, &b_nGenbJet20);
   fChain->SetBranchAddress("nGenaddbJet20", &nGenaddbJet20, &b_nGenaddbJet20);
   fChain->SetBranchAddress("nGencJet20", &nGencJet20, &b_nGencJet20);
   fChain->SetBranchAddress("nGenJet40", &nGenJet40, &b_nGenJet40);
   fChain->SetBranchAddress("nGenbJet40", &nGenbJet40, &b_nGenbJet40);
   fChain->SetBranchAddress("nGenaddbJet40", &nGenaddbJet40, &b_nGenaddbJet40);
   fChain->SetBranchAddress("nGencJet40", &nGencJet40, &b_nGencJet40);
   fChain->SetBranchAddress("ttbarGen_dileptonic", &ttbarGen_dileptonic, &b_ttbarGen_dileptonic);
   fChain->SetBranchAddress("genLep1_pt", &genLep1_pt, &b_genLep1_pt);
   fChain->SetBranchAddress("genLep2_pt", &genLep2_pt, &b_genLep2_pt);
   fChain->SetBranchAddress("genLep1_eta", &genLep1_eta, &b_genLep1_eta);
   fChain->SetBranchAddress("genLep2_eta", &genLep2_eta, &b_genLep2_eta);
   Notify();
}

Bool_t Event::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void Event::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t Event::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef Event_cxx
