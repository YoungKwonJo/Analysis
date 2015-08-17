#ifndef FlatTree_h
#define FlatTree_h

#include <vector>
#include "TTree.h"
//#include "TH1F.h"

using namespace std;

struct FlatTree
{
 public:
  FlatTree();
  ~FlatTree();

  void book(TTree* tree); // book leaves to fill the tree
  void clear();

  typedef std::vector<double> doubles;
  typedef doubles* doublesP;

  typedef std::vector<int> ints;
  typedef ints* intsP;

public:
  TTree* tree_;
  int run_, lumi_, event_;
  double weight_;

  double mm_mu1_pt_, mm_mu1_eta_, mm_mu1_phi_, mm_mu1_iso_, mm_zmass_;
  double mm_mu2_pt_, mm_mu2_eta_, mm_mu2_phi_, mm_mu2_iso_;
                                               
  double ee_el1_pt_, ee_el1_eta_, ee_el1_phi_, ee_el1_iso_, ee_zmass_;
  double ee_el2_pt_, ee_el2_eta_, ee_el2_phi_, ee_el2_iso_;
                                               
  double em_mu1_pt_, em_mu1_eta_, em_mu1_phi_, em_mu1_iso_,  em_zmass_;
  double em_el2_pt_, em_el2_eta_, em_el2_phi_, em_el2_iso_;

  double met_, metphi_;
  double metNoHFphi_, metNoHF_,    metPfMvaphi_, metPfMva_,   metPuppiphi_, metPuppi_;   

  int  mm_mu1_q_, mm_mu2_q_, ee_el1_q_, ee_el2_q_, em_mu1_q_, em_el2_q_;
  double mm_mu1_dr_el_, mm_mu2_dr_el_, ee_el1_dr_mu_, ee_el2_dr_mu_, em_mu1_dr_el_, em_el2_dr_mu_;

  doublesP jet_pt_, jet_eta_, jet_phi_, jet_csv_, jet_drl_; 
  doublesP jetPuppi_pt_, jetPuppi_eta_, jetPuppi_phi_, jetPuppi_csv_, jetPuppi_drl_; 
  //order csv;
  int nBJetT_, nBJetM_, nBJetL_, nJet_;
  int nBJetTPuppi_, nBJetMPuppi_, nBJetLPuppi_, nJetPuppi_;

  int isMM_, isEE_, isEM_, Category_,NgenJet_;

  int Nmu_, Nel_, NmuIso_, NelIso_; 
//  TH1F* hSumWeight_;

   Bool_t          CSCTightHaloFilter_;
   Bool_t          EcalDeadCellTriggerPrimitiveFilter_;
   Bool_t          HBHENoiseFilter_;
   Bool_t          eeBadScFilter_;
   Bool_t          goodVertices_;
   Int_t           HLTDoubleEle33CaloIdLGsfTrkIdVL_;
   Int_t           HLTEle12CaloIdLTrackIdLIsoVL_;
   Int_t           HLTEle16Ele12Ele8CaloIdLTrackIdL_;
   Int_t           HLTEle17CaloIdLTrackIdLIsoVL_;
   Int_t           HLTEle17Ele12CaloIdLTrackIdLIsoVLDZ_;
   Int_t           HLTEle23Ele12CaloIdLTrackIdLIsoVL_;
   Int_t           HLTEle23Ele12CaloIdLTrackIdLIsoVLDZ_;
   Int_t           HLTEle27eta2p1WPLooseGsfTriCentralPFJet30_;
   Int_t           HLTMu17Mu8DZ_;
   Int_t           HLTMu17TkMu8DZ_;
   Int_t           HLTMu17TrkIsoVVLEle12CaloIdLTrackIdLIsoVL_;
   Int_t           HLTMu17TrkIsoVVLMu8TrkIsoVVL_;
   Int_t           HLTMu17TrkIsoVVLMu8TrkIsoVVLDZ_;
   Int_t           HLTMu17TrkIsoVVLTkMu8TrkIsoVVL_;
   Int_t           HLTMu8TrkIsoVVLEle17CaloIdLTrackIdLIsoVL_;

   Int_t           nGoodPV_;
   Int_t           nPV_;
   Int_t           nTrueInteraction_;
 
};
//#endif

//#ifdef FlatTree_cxx
FlatTree::FlatTree()
{
   jet_pt_  = new doubles;
   jet_eta_  = new doubles;
   jet_phi_  = new doubles;
   jet_csv_  = new doubles;
   jet_drl_  = new doubles;

   jetPuppi_pt_  = new doubles;
   jetPuppi_eta_  = new doubles;
   jetPuppi_phi_  = new doubles;
   jetPuppi_csv_  = new doubles;
   jetPuppi_drl_  = new doubles;

}
void FlatTree::book(TTree* tree)
{
  tree_ = tree;
//  hSumWeight_ = new TH1F("hSumWeight","hSumWeight",1,0,2);

  tree_->Branch("run"  , &run_  , "run/I");
  tree_->Branch("lumi" , &lumi_ , "lumi/I");
  tree_->Branch("event", &event_, "event/I");
  tree_->Branch("weight", &weight_, "weight/D");

  tree_->Branch("jet_pt"  , jet_pt_  );
  tree_->Branch("jet_eta"  , jet_eta_  );
  tree_->Branch("jet_phi"  , jet_phi_  );
  tree_->Branch("jet_csv"  , jet_csv_  );
  tree_->Branch("jet_drl"  , jet_drl_  );

  tree_->Branch("nJet",    &nJet_,     "nJet/I");
  tree_->Branch("nBJetT",  &nBJetT_,   "nBJetT/I");
  tree_->Branch("nBJetM",  &nBJetM_,   "nBJetM/I");
  tree_->Branch("nBJetL",  &nBJetL_,   "nBJetL/I");

  tree_->Branch("jetPuppi_pt"  , jetPuppi_pt_  );
  tree_->Branch("jetPuppi_eta"  , jetPuppi_eta_  );
  tree_->Branch("jetPuppi_phi"  , jetPuppi_phi_  );
  tree_->Branch("jetPuppi_csv"  , jetPuppi_csv_  );
  tree_->Branch("jetPuppi_drl"  , jetPuppi_drl_  );

  tree_->Branch("nJetPuppi",    &nJetPuppi_,     "nJetPuppi/I");
  tree_->Branch("nBJetTPuppi",  &nBJetTPuppi_,   "nBJetTPuppi/I");
  tree_->Branch("nBJetMPuppi",  &nBJetMPuppi_,   "nBJetMPuppi/I");
  tree_->Branch("nBJetLPuppi",  &nBJetLPuppi_,   "nBJetLPuppi/I");

///////
  tree_->Branch("Nmu",    &Nmu_,     "Nmu/I");
  tree_->Branch("Nel",    &Nel_,     "Nel/I");
  tree_->Branch("NmuIso", &NmuIso_,  "NmuIso/I");
  tree_->Branch("NelIso", &NelIso_,  "NelIso/I");

///////
  tree_->Branch("met",    &met_,    "met/D");
  tree_->Branch("metphi", &metphi_, "metphi/D");

  tree_->Branch("metNoHFphi",    &metNoHFphi_,  "metNoHFphi/D"); 
  tree_->Branch("metNoHF",       &metNoHF_,     "metNoHF/D");   
  tree_->Branch("metPfMvaphi",   &metPfMvaphi_, "metPfMvaphi/D");
  tree_->Branch("metPfMva",      &metPfMva_,    "metPfMva/D");  
  tree_->Branch("metPuppiphi",   &metPuppiphi_, "metPuppiphi/D");
  tree_->Branch("metPuppi",      &metPuppi_,    "metPuppi/D");  

/////

  tree_->Branch("mm_mu1_pt",   &mm_mu1_pt_,    "mm_mu1_pt/D");
  tree_->Branch("mm_mu1_eta",  &mm_mu1_eta_,   "mm_mu1_eta/D");
  tree_->Branch("mm_mu1_phi",  &mm_mu1_phi_,   "mm_mu1_phi/D");
  tree_->Branch("mm_mu1_q",    &mm_mu1_q_,     "mm_mu1_q/I");
  tree_->Branch("mm_mu1_iso",  &mm_mu1_iso_,   "mm_mu1_iso/D");
  tree_->Branch("mm_mu2_pt",   &mm_mu2_pt_,    "mm_mu2_pt/D");
  tree_->Branch("mm_mu2_eta",  &mm_mu2_eta_,   "mm_mu2_eta/D");
  tree_->Branch("mm_mu2_phi",  &mm_mu2_phi_,   "mm_mu2_phi/D");
  tree_->Branch("mm_mu2_q",    &mm_mu2_q_,     "mm_mu2_q/I");
  tree_->Branch("mm_mu2_iso",  &mm_mu2_iso_,   "mm_mu2_iso/D");
  tree_->Branch("mm_zmass",    &mm_zmass_,     "mm_zmass/D");

  tree_->Branch("ee_el1_pt",   &ee_el1_pt_,    "ee_el1_pt/D");
  tree_->Branch("ee_el1_eta",  &ee_el1_eta_,   "ee_el1_eta/D");
  tree_->Branch("ee_el1_phi",  &ee_el1_phi_,   "ee_el1_phi/D");
  tree_->Branch("ee_el1_q",    &ee_el1_q_,     "ee_el1_q/I");
  tree_->Branch("ee_el1_iso",  &ee_el1_iso_,   "ee_el1_iso/D");
  tree_->Branch("ee_el2_pt",   &ee_el2_pt_,    "ee_el2_pt/D");
  tree_->Branch("ee_el2_eta",  &ee_el2_eta_,   "ee_el2_eta/D");
  tree_->Branch("ee_el2_phi",  &ee_el2_phi_,   "ee_el2_phi/D");
  tree_->Branch("ee_el2_q",    &ee_el2_q_,     "ee_el2_q/I");
  tree_->Branch("ee_el2_iso",  &ee_el2_iso_,   "ee_el2_iso/D");
  tree_->Branch("ee_zmass",    &ee_zmass_,     "ee_zmass/D");

  tree_->Branch("em_mu1_pt",   &em_mu1_pt_,    "em_mu1_pt/D");
  tree_->Branch("em_mu1_eta",  &em_mu1_eta_,   "em_mu1_eta/D");
  tree_->Branch("em_mu1_phi",  &em_mu1_phi_,   "em_mu1_phi/D");
  tree_->Branch("em_mu1_q",    &em_mu1_q_,     "em_mu1_q/I");
  tree_->Branch("em_mu1_iso",  &em_mu1_iso_,   "em_mu1_iso/D");
  tree_->Branch("em_el2_pt",   &em_el2_pt_,    "em_el2_pt/D");
  tree_->Branch("em_el2_eta",  &em_el2_eta_,   "em_el2_eta/D");
  tree_->Branch("em_el2_phi",  &em_el2_phi_,   "em_el2_phi/D");
  tree_->Branch("em_el2_q",    &em_el2_q_,     "em_el2_q/I");
  tree_->Branch("em_el2_iso",  &em_el2_iso_,   "em_el2_iso/D");
  tree_->Branch("em_zmass",    &em_zmass_,     "em_zmass/D");

  
   tree_->Branch("mm_mu1_dr_el",&mm_mu1_dr_el_,"mm_mu1_dr_el/D");
   tree_->Branch("mm_mu2_dr_el",&mm_mu2_dr_el_,"mm_mu2_dr_el/D");
   tree_->Branch("ee_el1_dr_mu",&ee_el1_dr_mu_,"ee_el1_dr_mu/D");
   tree_->Branch("ee_el2_dr_mu",&ee_el2_dr_mu_,"ee_el2_dr_mu/D");
   tree_->Branch("em_mu1_dr_el",&em_mu1_dr_el_,"em_mu1_dr_el/D");
   tree_->Branch("em_el2_dr_mu",&em_el2_dr_mu_,"em_el2_dr_mu/D");

/////
  tree_->Branch("isMM",  &isMM_, "isMM/I" );
  tree_->Branch("isEE",  &isEE_, "isEE/I" );
  tree_->Branch("isEM",  &isEM_, "isEM/I" );

  tree_->Branch("Category",  &Category_, "Category/I" );
  tree_->Branch("NgenJet",  &NgenJet_, "NgenJet/I" );

/////
  tree_->Branch("CSCTightHaloFilter",                         &CSCTightHaloFilter_,                          "CSCTightHaloFilter/O");                         
  tree_->Branch("EcalDeadCellTriggerPrimitiveFilter",         &EcalDeadCellTriggerPrimitiveFilter_,          "EcalDeadCellTriggerPrimitiveFilter/O");
  tree_->Branch("HBHENoiseFilter",                            &HBHENoiseFilter_,                             "HBHENoiseFilter/O");
  tree_->Branch("eeBadScFilter",                              &eeBadScFilter_,                               "eeBadScFilter/O");
  tree_->Branch("goodVertices",                               &goodVertices_,                                "goodVertices/O");
  tree_->Branch("HLTDoubleEle33CaloIdLGsfTrkIdVL",            &HLTDoubleEle33CaloIdLGsfTrkIdVL_,             "HLTDoubleEle33CaloIdLGsfTrkIdVL/I");
  tree_->Branch("HLTEle12CaloIdLTrackIdLIsoVL",               &HLTEle12CaloIdLTrackIdLIsoVL_,                "HLTEle12CaloIdLTrackIdLIsoVL/I");
  tree_->Branch("HLTEle16Ele12Ele8CaloIdLTrackIdL",           &HLTEle16Ele12Ele8CaloIdLTrackIdL_,            "HLTEle16Ele12Ele8CaloIdLTrackIdL/I");
  tree_->Branch("HLTEle17CaloIdLTrackIdLIsoVL",               &HLTEle17CaloIdLTrackIdLIsoVL_,                "HLTEle17CaloIdLTrackIdLIsoVL/I");
  tree_->Branch("HLTEle17Ele12CaloIdLTrackIdLIsoVLDZ",        &HLTEle17Ele12CaloIdLTrackIdLIsoVLDZ_,         "HLTEle17Ele12CaloIdLTrackIdLIsoVLDZ/I");
  tree_->Branch("HLTEle23Ele12CaloIdLTrackIdLIsoVL",          &HLTEle23Ele12CaloIdLTrackIdLIsoVL_,           "HLTEle23Ele12CaloIdLTrackIdLIsoVL/I");
  tree_->Branch("HLTEle23Ele12CaloIdLTrackIdLIsoVLDZ",        &HLTEle23Ele12CaloIdLTrackIdLIsoVLDZ_,         "HLTEle23Ele12CaloIdLTrackIdLIsoVLDZ/I");
  tree_->Branch("HLTEle27eta2p1WPLooseGsfTriCentralPFJet30",  &HLTEle27eta2p1WPLooseGsfTriCentralPFJet30_,   "HLTEle27eta2p1WPLooseGsfTriCentralPFJet30/I");
  tree_->Branch("HLTMu17Mu8DZ",                               &HLTMu17Mu8DZ_,                                "HLTMu17Mu8DZ/I");
  tree_->Branch("HLTMu17TkMu8DZ",                             &HLTMu17TkMu8DZ_,                              "HLTMu17TkMu8DZ/I");
  tree_->Branch("HLTMu17TrkIsoVVLEle12CaloIdLTrackIdLIsoVL",  &HLTMu17TrkIsoVVLEle12CaloIdLTrackIdLIsoVL_,   "HLTMu17TrkIsoVVLEle12CaloIdLTrackIdLIsoVL/I");
  tree_->Branch("HLTMu17TrkIsoVVLMu8TrkIsoVVL",               &HLTMu17TrkIsoVVLMu8TrkIsoVVL_,                "HLTMu17TrkIsoVVLMu8TrkIsoVVL/I");
  tree_->Branch("HLTMu17TrkIsoVVLMu8TrkIsoVVLDZ",             &HLTMu17TrkIsoVVLMu8TrkIsoVVLDZ_,              "HLTMu17TrkIsoVVLMu8TrkIsoVVLDZ/I");
  tree_->Branch("HLTMu17TrkIsoVVLTkMu8TrkIsoVVL",             &HLTMu17TrkIsoVVLTkMu8TrkIsoVVL_,              "HLTMu17TrkIsoVVLTkMu8TrkIsoVVL/I");
  tree_->Branch("HLTMu8TrkIsoVVLEle17CaloIdLTrackIdLIsoVL",   &HLTMu8TrkIsoVVLEle17CaloIdLTrackIdLIsoVL_,    "HLTMu8TrkIsoVVLEle17CaloIdLTrackIdLIsoVL/I");

  tree_->Branch("nGoodPV",            &nGoodPV_,          "nGoodPV/I");
  tree_->Branch("nPV",                &nPV_,              "nPV/I");
  tree_->Branch("nTrueInteraction",   &nTrueInteraction_, "nTrueInteraction/I");
/// 

}
void FlatTree::clear()
{
   jet_pt_->clear();
   jet_eta_->clear();
   jet_phi_->clear();
   jet_csv_->clear();
   jet_drl_->clear();

   jetPuppi_pt_->clear();
   jetPuppi_eta_->clear();
   jetPuppi_phi_->clear();
   jetPuppi_csv_->clear();
   jetPuppi_drl_->clear();

   weight_=1.0;

   Nmu_=-99; Nel_=-99;
   NmuIso_=-99; NelIso_=-99;
//
   nBJetT_=-99; nBJetM_=-99; nBJetL_=-99; nJet_=-99;
   nBJetTPuppi_=-99; nBJetM_=-99; nBJetL_=-99; nJet_=-99;
///
   met_=-99.0; metphi_=-99.;
   metNoHFphi_=-99.0; metNoHF_=-99.0;    metPfMvaphi_=-99.0; metPfMva_=-99.0;   metPuppiphi_=-99.0; metPuppi_=-99.0;   
///

   mm_mu1_pt_=-99.; mm_mu1_eta_=-99.; mm_mu1_phi_=-99.; mm_mu1_iso_=-99.; mm_zmass_=-99.;
   mm_mu2_pt_=-99.; mm_mu2_eta_=-99.; mm_mu2_phi_=-99.; mm_mu2_iso_=-99.;
   ee_el1_pt_=-99.; ee_el1_eta_=-99.; ee_el1_phi_=-99.; ee_el1_iso_=-99.; ee_zmass_=-99.;
   ee_el2_pt_=-99.; ee_el2_eta_=-99.; ee_el2_phi_=-99.; ee_el2_iso_=-99.;
   em_mu1_pt_=-99.; em_mu1_eta_=-99.; em_mu1_phi_=-99.; em_mu1_iso_=-99.; em_zmass_=-99.;
   em_el2_pt_=-99.; em_el2_eta_=-99.; em_el2_phi_=-99.; em_el2_iso_=-99.;

   mm_mu1_dr_el_=-99.;  mm_mu2_dr_el_=-99.;  ee_el1_dr_mu_=-99.;  ee_el2_dr_mu_=-99.;  em_mu1_dr_el_=-99.;  em_el2_dr_mu_=-99.; 

    mm_mu1_q_=-99;  mm_mu2_q_=-99;
    ee_el1_q_=-99;  ee_el2_q_=-99;
    em_mu1_q_=-99;  em_el2_q_=-99;

///////
  isMM_=-99; isEE_=-99; isEM_=-99;
  Category_=-99;
  NgenJet_=-99;

///////
  CSCTightHaloFilter_=false;
  EcalDeadCellTriggerPrimitiveFilter_=false;
  HBHENoiseFilter_=false;
  eeBadScFilter_=false;
  goodVertices_=false;
  HLTDoubleEle33CaloIdLGsfTrkIdVL_=0;
  HLTEle12CaloIdLTrackIdLIsoVL_=0;
  HLTEle16Ele12Ele8CaloIdLTrackIdL_=0;
  HLTEle17CaloIdLTrackIdLIsoVL_=0;
  HLTEle17Ele12CaloIdLTrackIdLIsoVLDZ_=0;
  HLTEle23Ele12CaloIdLTrackIdLIsoVL_=0;
  HLTEle23Ele12CaloIdLTrackIdLIsoVLDZ_=0;
  HLTEle27eta2p1WPLooseGsfTriCentralPFJet30_=0;
  HLTMu17Mu8DZ_=0;
  HLTMu17TkMu8DZ_=0;
  HLTMu17TrkIsoVVLEle12CaloIdLTrackIdLIsoVL_=0;
  HLTMu17TrkIsoVVLMu8TrkIsoVVL_=0;
  HLTMu17TrkIsoVVLMu8TrkIsoVVLDZ_=0;
  HLTMu17TrkIsoVVLTkMu8TrkIsoVVL_=0;
  HLTMu8TrkIsoVVLEle17CaloIdLTrackIdLIsoVL_=0;

  nGoodPV_=0;
  nPV_=0;
  nTrueInteraction_=0;
 

}
FlatTree::~FlatTree()
{
}
#endif
