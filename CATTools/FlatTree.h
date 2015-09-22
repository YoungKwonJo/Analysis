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
  void copy(FlatTree *my_);
  void setBranch(TTree* tree);

  typedef std::vector<float> floats;
  typedef floats* floatsP;

  typedef std::vector<int> ints;
  typedef ints* intsP;

public:
  TTree* tree_;
  int run_, lumi_, event_;
  float weight_, genWeight_, lheWeight_;

  float ll_lep1_pt_, ll_lep1_eta_, ll_lep1_phi_, ll_lep1_iso_, ll_zmass_;
  float ll_lep2_pt_, ll_lep2_eta_, ll_lep2_phi_, ll_lep2_iso_;
  int  ll_lep1_q_, ll_lep2_q_;
  int  ll_lep1_MCmatched_, ll_lep2_MCmatched_;
  int ll_lep1_pdgid_, ll_lep2_pdgid_, lepton_N_;

  float met_, metphi_;
  float metNoHFphi_, metNoHF_,    metPfMvaphi_, metPfMva_,   metPuppiphi_, metPuppi_;   

  floatsP jet_pt_, jet_eta_, jet_phi_, jet_csv_; 
  floatsP jetPuppi_pt_, jetPuppi_eta_, jetPuppi_phi_, jetPuppi_csv_; 
  //order csv;

  int nBJet20T_, nBJet20M_, nBJet20L_, nJet20_;
  int nBJet30T_, nBJet30M_, nBJet30L_, nJet30_;
  int nBJet20TPuppi_, nBJet20MPuppi_, nBJet20LPuppi_, nJet20Puppi_;
  int nBJet30TPuppi_, nBJet30MPuppi_, nBJet30LPuppi_, nJet30Puppi_;

  int isMM_, isEE_, isEM_, Category_,NgenJet_, Categorytb_;

  int Nmu_, Nel_, NmuIso_, NelIso_; 
//  TH1F* hSumWeight_;

   Bool_t          CSCTightHaloFilter_;
   Bool_t          EcalDeadCellTriggerPrimitiveFilter_;
   Bool_t          HBHENoiseFilter_;
   Bool_t          eeBadScFilter_;
   Bool_t          goodVertices_;

   Int_t           HLTEle17Ele12CaloIdLTrackIdLIsoVLDZ_;
   Int_t           HLTEle17Ele12CaloIdLTrackIdLIsoVLDZold_;
   Int_t           HLTMu17TrkIsoVVLEle12CaloIdLTrackIdLIsoVL_;
   Int_t           HLTMu17TrkIsoVVLEle12CaloIdLTrackIdLIsoVLold_;
   Int_t           HLTMu17TrkIsoVVLMu8TrkIsoVVLDZ_;
   Int_t           HLTMu17TrkIsoVVLMu8TrkIsoVVLDZold_;
   Int_t           HLTMu17TrkIsoVVLTkMu8TrkIsoVVLDZ_;
   Int_t           HLTMu17TrkIsoVVLTkMu8TrkIsoVVLDZold_;
   Int_t           HLTMu8TrkIsoVVLEle17CaloIdLTrackIdLIsoVL_;
   Int_t           HLTMu8TrkIsoVVLEle17CaloIdLTrackIdLIsoVLold_;

   Int_t           nGoodPV_;
   Int_t           nPV_;
   Int_t           nTrueInteraction_;

   float pdfWeightId1_, pdfWeightId2_, pdfWeightQ_  , pdfWeightX1_ , pdfWeightX2_ , puWeight_; 
   float CutsD_,LikelihoodD_,MLP_,MLPBFGS_,MLPBNN_,BDT_,BDTD_,BDTG_;
 
};
//#endif

//#ifdef FlatTree_cxx
FlatTree::FlatTree()
{
   jet_pt_  = new floats;
   jet_eta_  = new floats;
   jet_phi_  = new floats;
   jet_csv_  = new floats;

   jetPuppi_pt_  = new floats;
   jetPuppi_eta_  = new floats;
   jetPuppi_phi_  = new floats;
   jetPuppi_csv_  = new floats;

}
void FlatTree::book(TTree* tree)
{
  tree_ = tree;
//  hSumWeight_ = new TH1F("hSumWeight","hSumWeight",1,0,2);

  tree_->Branch("run"  , &run_  , "run/I");
  tree_->Branch("lumi" , &lumi_ , "lumi/I");
  tree_->Branch("event", &event_, "event/I");
  tree_->Branch("weight", &weight_, "weight/F");
  tree_->Branch("genWeight", &genWeight_, "genWeight/F");
  tree_->Branch("lheWeight", &lheWeight_, "lheWeight/F");

  tree_->Branch("jet_pt"  , jet_pt_  );
  tree_->Branch("jet_eta"  , jet_eta_  );
  tree_->Branch("jet_phi"  , jet_phi_  );
  tree_->Branch("jet_csv"  , jet_csv_  );

  tree_->Branch("nJet20",    &nJet20_,     "nJet20/I");
  tree_->Branch("nBJet20T",  &nBJet20T_,   "nBJet20T/I");
  tree_->Branch("nBJet20M",  &nBJet20M_,   "nBJet20M/I");
  tree_->Branch("nBJet20L",  &nBJet20L_,   "nBJet20L/I");

  tree_->Branch("nJet30",    &nJet30_,     "nJet30/I");
  tree_->Branch("nBJet30T",  &nBJet30T_,   "nBJet30T/I");
  tree_->Branch("nBJet30M",  &nBJet30M_,   "nBJet30M/I");
  tree_->Branch("nBJet30L",  &nBJet30L_,   "nBJet30L/I");

  tree_->Branch("jetPuppi_pt"  , jetPuppi_pt_  );
  tree_->Branch("jetPuppi_eta"  , jetPuppi_eta_  );
  tree_->Branch("jetPuppi_phi"  , jetPuppi_phi_  );
  tree_->Branch("jetPuppi_csv"  , jetPuppi_csv_  );

  tree_->Branch("nJet20Puppi",    &nJet20Puppi_,     "nJet20Puppi/I");
  tree_->Branch("nBJet20TPuppi",  &nBJet20TPuppi_,   "nBJet20TPuppi/I");
  tree_->Branch("nBJet20MPuppi",  &nBJet20MPuppi_,   "nBJet20MPuppi/I");
  tree_->Branch("nBJet20LPuppi",  &nBJet20LPuppi_,   "nBJet20LPuppi/I");

  tree_->Branch("nJet30Puppi",    &nJet30Puppi_,     "nJet30Puppi/I");
  tree_->Branch("nBJet30TPuppi",  &nBJet30TPuppi_,   "nBJet30TPuppi/I");
  tree_->Branch("nBJet30MPuppi",  &nBJet30MPuppi_,   "nBJet30MPuppi/I");
  tree_->Branch("nBJet30LPuppi",  &nBJet30LPuppi_,   "nBJet30LPuppi/I");

///////
  tree_->Branch("Nmu",    &Nmu_,     "Nmu/I");
  tree_->Branch("Nel",    &Nel_,     "Nel/I");
  tree_->Branch("NmuIso", &NmuIso_,  "NmuIso/I");
  tree_->Branch("NelIso", &NelIso_,  "NelIso/I");

///////
  tree_->Branch("met",    &met_,    "met/F");
  tree_->Branch("metphi", &metphi_, "metphi/F");

  tree_->Branch("metNoHFphi",    &metNoHFphi_,  "metNoHFphi/F"); 
  tree_->Branch("metNoHF",       &metNoHF_,     "metNoHF/F");   
  tree_->Branch("metPfMvaphi",   &metPfMvaphi_, "metPfMvaphi/F");
  tree_->Branch("metPfMva",      &metPfMva_,    "metPfMva/F");  
  tree_->Branch("metPuppiphi",   &metPuppiphi_, "metPuppiphi/F");
  tree_->Branch("metPuppi",      &metPuppi_,    "metPuppi/F");  

/////
  tree_->Branch("ll_lep1_pt",   &ll_lep1_pt_,    "ll_lep1_pt/F");
  tree_->Branch("ll_lep1_eta",  &ll_lep1_eta_,   "ll_lep1_eta/F");
  tree_->Branch("ll_lep1_phi",  &ll_lep1_phi_,   "ll_lep1_phi/F");
  tree_->Branch("ll_lep1_q",    &ll_lep1_q_,     "ll_lep1_q/I");
  tree_->Branch("ll_lep1_MCmatched",    &ll_lep1_MCmatched_,     "ll_lep1_MCmatched/I");
  tree_->Branch("ll_lep1_iso",  &ll_lep1_iso_,   "ll_lep1_iso/F");
  tree_->Branch("ll_lep2_pt",   &ll_lep2_pt_,    "ll_lep2_pt/F");
  tree_->Branch("ll_lep2_eta",  &ll_lep2_eta_,   "ll_lep2_eta/F");
  tree_->Branch("ll_lep2_phi",  &ll_lep2_phi_,   "ll_lep2_phi/F");
  tree_->Branch("ll_lep2_q",    &ll_lep2_q_,     "ll_lep2_q/I");
  tree_->Branch("ll_lep2_MCmatched",    &ll_lep2_MCmatched_,     "ll_lep2_MCmatched/I");
  tree_->Branch("ll_lep2_iso",  &ll_lep2_iso_,   "ll_lep2_iso/F");
  tree_->Branch("ll_zmass",     &ll_zmass_,      "ll_zmass/F");
  tree_->Branch("ll_lep1_pdgid",&ll_lep1_pdgid_,  "ll_lep1_pdgid/I");
  tree_->Branch("ll_lep2_pdgid",&ll_lep2_pdgid_,  "ll_lep2_pdgid/I");
  tree_->Branch("lepton_N",&lepton_N_,  "lepton_N/I");

/////
  tree_->Branch("isMM",  &isMM_, "isMM/I" );
  tree_->Branch("isEE",  &isEE_, "isEE/I" );
  tree_->Branch("isEM",  &isEM_, "isEM/I" );

  tree_->Branch("Category",  &Category_, "Category/I" );
  tree_->Branch("Categorytb",  &Categorytb_, "Categorytb/I" );
  tree_->Branch("NgenJet",  &NgenJet_, "NgenJet/I" );
//////

  tree_->Branch("pdfWeightId1",&pdfWeightId1_, "pdfWeightId1/F");
  tree_->Branch("pdfWeightId2",&pdfWeightId2_, "pdfWeightId2/F");
  tree_->Branch("pdfWeightQ",  &pdfWeightQ_,   "pdfWeightQ/F");  
  tree_->Branch("pdfWeightX1", &pdfWeightX1_,  "pdfWeightX1/F"); 
  tree_->Branch("pdfWeightX2", &pdfWeightX2_,  "pdfWeightX2/F"); 
  tree_->Branch("puWeight",    &puWeight_,     "puWeight/F");    


/////
  tree_->Branch("CSCTightHaloFilter",                         &CSCTightHaloFilter_,                          "CSCTightHaloFilter/O");                         
  tree_->Branch("EcalDeadCellTriggerPrimitiveFilter",         &EcalDeadCellTriggerPrimitiveFilter_,          "EcalDeadCellTriggerPrimitiveFilter/O");
  tree_->Branch("HBHENoiseFilter",                            &HBHENoiseFilter_,                             "HBHENoiseFilter/O");
  tree_->Branch("eeBadScFilter",                              &eeBadScFilter_,                               "eeBadScFilter/O");
  tree_->Branch("goodVertices",                               &goodVertices_,                                "goodVertices/O");
  tree_->Branch("HLTEle17Ele12CaloIdLTrackIdLIsoVLDZ",             &HLTEle17Ele12CaloIdLTrackIdLIsoVLDZ_,             "HLTEle17Ele12CaloIdLTrackIdLIsoVLDZ/I");
  tree_->Branch("HLTEle17Ele12CaloIdLTrackIdLIsoVLDZold",          &HLTEle17Ele12CaloIdLTrackIdLIsoVLDZold_,          "HLTEle17Ele12CaloIdLTrackIdLIsoVLDZold/I");
  tree_->Branch("HLTMu17TrkIsoVVLEle12CaloIdLTrackIdLIsoVL",       &HLTMu17TrkIsoVVLEle12CaloIdLTrackIdLIsoVL_,       "HLTMu17TrkIsoVVLEle12CaloIdLTrackIdLIsoVL/I");
  tree_->Branch("HLTMu17TrkIsoVVLEle12CaloIdLTrackIdLIsoVLold",    &HLTMu17TrkIsoVVLEle12CaloIdLTrackIdLIsoVLold_,    "HLTMu17TrkIsoVVLEle12CaloIdLTrackIdLIsoVLold/I");
  tree_->Branch("HLTMu17TrkIsoVVLMu8TrkIsoVVLDZ",                  &HLTMu17TrkIsoVVLMu8TrkIsoVVLDZ_,                  "HLTMu17TrkIsoVVLMu8TrkIsoVVLDZ/I");
  tree_->Branch("HLTMu17TrkIsoVVLMu8TrkIsoVVLDZold",               &HLTMu17TrkIsoVVLMu8TrkIsoVVLDZold_,               "HLTMu17TrkIsoVVLMu8TrkIsoVVLDZold/I");
  tree_->Branch("HLTMu17TrkIsoVVLTkMu8TrkIsoVVLDZ",                &HLTMu17TrkIsoVVLTkMu8TrkIsoVVLDZ_,                "HLTMu17TrkIsoVVLTkMu8TrkIsoVVLDZ/I");
  tree_->Branch("HLTMu17TrkIsoVVLTkMu8TrkIsoVVLDZold",             &HLTMu17TrkIsoVVLTkMu8TrkIsoVVLDZold_,             "HLTMu17TrkIsoVVLTkMu8TrkIsoVVLDZold/I");
  tree_->Branch("HLTMu8TrkIsoVVLEle17CaloIdLTrackIdLIsoVL",        &HLTMu8TrkIsoVVLEle17CaloIdLTrackIdLIsoVL_,        "HLTMu8TrkIsoVVLEle17CaloIdLTrackIdLIsoVL/I");
  tree_->Branch("HLTMu8TrkIsoVVLEle17CaloIdLTrackIdLIsoVLold",     &HLTMu8TrkIsoVVLEle17CaloIdLTrackIdLIsoVLold_,     "HLTMu8TrkIsoVVLEle17CaloIdLTrackIdLIsoVLold/I");

  tree_->Branch("nGoodPV",            &nGoodPV_,          "nGoodPV/I");
  tree_->Branch("nPV",                &nPV_,              "nPV/I");
  tree_->Branch("nTrueInteraction",   &nTrueInteraction_, "nTrueInteraction/I");
/// 

  tree_->Branch("CutsD",        &CutsD_,        "CutsD/F");
  tree_->Branch("LikelihoodD",  &LikelihoodD_,  "LikelihoodD/F");
  tree_->Branch("MLP",          &MLP_,          "MLP/F");
  tree_->Branch("MLPBFGS",      &MLPBFGS_,      "MLPBFGS/F");
  tree_->Branch("MLPBNN",       &MLPBNN_,       "MLPBNN/F");
  tree_->Branch("BDT",          &BDT_,          "BDT/F");
  tree_->Branch("BDTD",         &BDTD_,         "BDTD/F");
  tree_->Branch("BDTG",         &BDTG_,         "BDTG/F");

}
void FlatTree::copy(FlatTree *my_)
{
   jet_pt_->clear();
   jet_eta_->clear();
   jet_phi_->clear();
   jet_csv_->clear();

   jetPuppi_pt_->clear();
   jetPuppi_eta_->clear();
   jetPuppi_phi_->clear();
   jetPuppi_csv_->clear();

   for (int i=0;i<my_->jet_pt_->size();i++)
   {
     jet_pt_ ->push_back(my_->jet_pt_ ->at(i) );
     jet_eta_->push_back(my_->jet_eta_->at(i) );
     jet_phi_->push_back(my_->jet_phi_->at(i) );
     jet_csv_->push_back(my_->jet_csv_->at(i) );
   }

   for (int i=0;i<my_->jetPuppi_pt_->size();i++)
   {
     jetPuppi_pt_ ->push_back(my_->jetPuppi_pt_ ->at(i) );
     jetPuppi_eta_->push_back(my_->jetPuppi_eta_->at(i) );
     jetPuppi_phi_->push_back(my_->jetPuppi_phi_->at(i) );
     jetPuppi_csv_->push_back(my_->jetPuppi_csv_->at(i) );
   }

   run_   =my_->run_  ;
   lumi_  =my_->lumi_ ;
   event_ =my_->event_;

   weight_   =my_->weight_   ;
   genWeight_=my_->genWeight_;
   lheWeight_=my_->lheWeight_;

   Nmu_          =my_->Nmu_          ;
   Nel_          =my_->Nel_          ;
   NmuIso_       =my_->NmuIso_       ;
   NelIso_       =my_->NelIso_       ;
   nBJet20T_     =my_->nBJet20T_     ;
   nBJet20M_     =my_->nBJet20M_     ;
   nBJet20L_     =my_->nBJet20L_     ;
   nJet20_       =my_->nJet20_       ;
   nBJet30T_     =my_->nBJet30T_     ;
   nBJet30M_     =my_->nBJet30M_     ;
   nBJet30L_     =my_->nBJet30L_     ;
   nJet30_       =my_->nJet30_       ;
   nBJet20TPuppi_=my_->nBJet20TPuppi_;
   nBJet20M_     =my_->nBJet20M_     ;
   nBJet20L_     =my_->nBJet20L_     ;
   nJet20_       =my_->nJet20_       ;
   nBJet30TPuppi_=my_->nBJet30TPuppi_;
   nBJet30M_     =my_->nBJet30M_     ;
   nBJet30L_     =my_->nBJet30L_     ;
   nJet30_       =my_->nJet30_       ;
///
   met_               =my_->met_               ;
   metphi_            =my_->metphi_            ;
   metNoHFphi_        =my_->metNoHFphi_        ;
   metNoHF_           =my_->metNoHF_           ;
   metPfMvaphi_       =my_->metPfMvaphi_       ;
   metPfMva_          =my_->metPfMva_          ;
   metPuppiphi_       =my_->metPuppiphi_       ;
   metPuppi_          =my_->metPuppi_          ;
   ll_lep1_pt_        =my_->ll_lep1_pt_        ;
   ll_lep1_eta_       =my_->ll_lep1_eta_       ;
   ll_lep1_phi_       =my_->ll_lep1_phi_       ;
   ll_lep1_iso_       =my_->ll_lep1_iso_       ;
   ll_zmass_          =my_->ll_zmass_          ;
   ll_lep2_pt_        =my_->ll_lep2_pt_        ;
   ll_lep2_eta_       =my_->ll_lep2_eta_       ;
   ll_lep2_phi_       =my_->ll_lep2_phi_       ;
   ll_lep2_iso_       =my_->ll_lep2_iso_       ;
   ll_lep1_q_         =my_->ll_lep1_q_         ;
   ll_lep2_q_         =my_->ll_lep2_q_         ;
   ll_lep1_MCmatched_ =my_->ll_lep1_MCmatched_ ;
   ll_lep2_MCmatched_ =my_->ll_lep2_MCmatched_ ;
   ll_lep1_pdgid_     =my_->ll_lep1_pdgid_     ;
   ll_lep2_pdgid_     =my_->ll_lep2_pdgid_     ;
   lepton_N_          =my_->lepton_N_          ;
   isMM_              =my_->isMM_              ;
   isEE_              =my_->isEE_              ;
   isEM_              =my_->isEM_              ;
   Category_          =my_->Category_          ;
   Categorytb_        =my_->Categorytb_        ;
   NgenJet_           =my_->NgenJet_           ;

////////
  pdfWeightId1_                                 =my_->pdfWeightId1_                                ;
  pdfWeightId2_                                 =my_->pdfWeightId2_                                ;
  pdfWeightQ_                                   =my_->pdfWeightQ_                                  ;
  pdfWeightX1_                                  =my_->pdfWeightX1_                                 ;
  pdfWeightX2_                                  =my_->pdfWeightX2_                                 ;
  puWeight_                                     =my_->puWeight_                                    ;
  CSCTightHaloFilter_                           =my_->CSCTightHaloFilter_                          ;
  EcalDeadCellTriggerPrimitiveFilter_           =my_->EcalDeadCellTriggerPrimitiveFilter_          ;
  HBHENoiseFilter_                              =my_->HBHENoiseFilter_                             ;
  eeBadScFilter_                                =my_->eeBadScFilter_                               ;
  goodVertices_                                 =my_->goodVertices_                                ;
  HLTEle17Ele12CaloIdLTrackIdLIsoVLDZ_          =my_->HLTEle17Ele12CaloIdLTrackIdLIsoVLDZ_         ;
  HLTEle17Ele12CaloIdLTrackIdLIsoVLDZold_       =my_->HLTEle17Ele12CaloIdLTrackIdLIsoVLDZold_      ;
  HLTMu17TrkIsoVVLEle12CaloIdLTrackIdLIsoVL_    =my_->HLTMu17TrkIsoVVLEle12CaloIdLTrackIdLIsoVL_   ;
  HLTMu17TrkIsoVVLEle12CaloIdLTrackIdLIsoVLold_ =my_->HLTMu17TrkIsoVVLEle12CaloIdLTrackIdLIsoVLold_;
  HLTMu17TrkIsoVVLMu8TrkIsoVVLDZ_               =my_->HLTMu17TrkIsoVVLMu8TrkIsoVVLDZ_              ;
  HLTMu17TrkIsoVVLMu8TrkIsoVVLDZold_            =my_->HLTMu17TrkIsoVVLMu8TrkIsoVVLDZold_           ;
  HLTMu17TrkIsoVVLTkMu8TrkIsoVVLDZ_             =my_->HLTMu17TrkIsoVVLTkMu8TrkIsoVVLDZ_            ;
  HLTMu17TrkIsoVVLTkMu8TrkIsoVVLDZold_          =my_->HLTMu17TrkIsoVVLTkMu8TrkIsoVVLDZold_         ;
  HLTMu8TrkIsoVVLEle17CaloIdLTrackIdLIsoVL_     =my_->HLTMu8TrkIsoVVLEle17CaloIdLTrackIdLIsoVL_    ;
  HLTMu8TrkIsoVVLEle17CaloIdLTrackIdLIsoVLold_  =my_->HLTMu8TrkIsoVVLEle17CaloIdLTrackIdLIsoVLold_ ;
  nGoodPV_                                      =my_->nGoodPV_                                     ;
  nPV_                                          =my_->nPV_                                         ;
  nTrueInteraction_                             =my_->nTrueInteraction_                            ;
 
  CutsD_      =my_->CutsD_;
  LikelihoodD_=my_->LikelihoodD_;
  MLP_        =my_->MLP_;
  MLPBFGS_    =my_->MLPBFGS_;
  MLPBNN_     =my_->MLPBNN_;
  BDT_        =my_->BDT_;
  BDTD_       =my_->BDTD_;
  BDTG_       =my_->BDTG_;

}

void FlatTree::clear()
{
   jet_pt_->clear();
   jet_eta_->clear();
   jet_phi_->clear();
   jet_csv_->clear();

   jetPuppi_pt_->clear();
   jetPuppi_eta_->clear();
   jetPuppi_phi_->clear();
   jetPuppi_csv_->clear();

   weight_=1.0;
   genWeight_=1.0;
   lheWeight_=1.0;

   Nmu_=-99; Nel_=-99;
   NmuIso_=-99; NelIso_=-99;
//
   nBJet20T_=-99; nBJet20M_=-99; nBJet20L_=-99; nJet20_=-99;
   nBJet30T_=-99; nBJet30M_=-99; nBJet30L_=-99; nJet30_=-99;
   nBJet20TPuppi_=-99; nBJet20M_=-99; nBJet20L_=-99; nJet20_=-99;
   nBJet30TPuppi_=-99; nBJet30M_=-99; nBJet30L_=-99; nJet30_=-99;
///
   met_=-99.0; metphi_=-99.;
   metNoHFphi_=-99.0; metNoHF_=-99.0;    metPfMvaphi_=-99.0; metPfMva_=-99.0;   metPuppiphi_=-99.0; metPuppi_=-99.0;   
///
   ll_lep1_pt_=-99.; ll_lep1_eta_=-99.; ll_lep1_phi_=-99.; ll_lep1_iso_=-99.; ll_zmass_=-99.;
   ll_lep2_pt_=-99.; ll_lep2_eta_=-99.; ll_lep2_phi_=-99.; ll_lep2_iso_=-99.;
 
    ll_lep1_q_=-99;  ll_lep2_q_=-99;
    ll_lep1_MCmatched_=0;  ll_lep2_MCmatched_=0;
    ll_lep1_pdgid_=-99;  ll_lep2_pdgid_=-99;
    lepton_N_=-99;
///////
  isMM_=-99; isEE_=-99; isEM_=-99;
  Category_=-99;
  Categorytb_=-99;
  NgenJet_=-99;

////////
  pdfWeightId1_  =1.;
  pdfWeightId2_  =1.;
  pdfWeightQ_    =1.;
  pdfWeightX1_   =1.;
  pdfWeightX2_   =1.;
  puWeight_      =1.;
///////

  CSCTightHaloFilter_=false;
  EcalDeadCellTriggerPrimitiveFilter_=false;
  HBHENoiseFilter_=false;
  eeBadScFilter_=false;
  goodVertices_=false;

  HLTEle17Ele12CaloIdLTrackIdLIsoVLDZ_=0;
  HLTEle17Ele12CaloIdLTrackIdLIsoVLDZold_=0;
  HLTMu17TrkIsoVVLEle12CaloIdLTrackIdLIsoVL_=0;
  HLTMu17TrkIsoVVLEle12CaloIdLTrackIdLIsoVLold_=0;
  HLTMu17TrkIsoVVLMu8TrkIsoVVLDZ_=0;
  HLTMu17TrkIsoVVLMu8TrkIsoVVLDZold_=0;
  HLTMu17TrkIsoVVLTkMu8TrkIsoVVLDZ_=0;
  HLTMu17TrkIsoVVLTkMu8TrkIsoVVLDZold_=0;
  HLTMu8TrkIsoVVLEle17CaloIdLTrackIdLIsoVL_=0;
  HLTMu8TrkIsoVVLEle17CaloIdLTrackIdLIsoVLold_=0;

  nGoodPV_=0;
  nPV_=0;
  nTrueInteraction_=0;

  CutsD_      = 99.;
  LikelihoodD_= 99.;
  MLP_        = 99.;
  MLPBFGS_    = 99.;
  MLPBNN_     = 99.;
  BDT_        = 99.;
  BDTD_       = 99.;
  BDTG_       = 99.;

}
///////////
void FlatTree::setBranch(TTree* tree)
{
  tree_ = tree;
  tree_->SetMakeClass(1);
  tree_->SetBranchAddress("run", &run_);
  tree_->SetBranchAddress("lumi", &lumi_);
  tree_->SetBranchAddress("event", &event_);

  tree_->SetBranchAddress("jet_pt"     , &jet_pt_     );
  tree_->SetBranchAddress("jet_eta"     , &jet_eta_     );
  tree_->SetBranchAddress("jet_phi"     , &jet_phi_     );
  tree_->SetBranchAddress("jet_csv"     , &jet_csv_     );

  tree_->SetBranchAddress("jetPuppi_pt"     , &jetPuppi_pt_     );
  tree_->SetBranchAddress("jetPuppi_eta"     , &jetPuppi_eta_     );
  tree_->SetBranchAddress("jetPuppi_phi"     , &jetPuppi_phi_     );
  tree_->SetBranchAddress("jetPuppi_csv"     , &jetPuppi_csv_     );

   tree_->SetBranchAddress("weight",   &weight_   );
   tree_->SetBranchAddress("genWeight",&genWeight_);
   tree_->SetBranchAddress("lheWeight",&lheWeight_);

   tree_->SetBranchAddress("Nmu",          &Nmu_          );
   tree_->SetBranchAddress("Nel",          &Nel_          );
   tree_->SetBranchAddress("NmuIso",       &NmuIso_       );
   tree_->SetBranchAddress("NelIso",       &NelIso_       );
   tree_->SetBranchAddress("nBJet20T",     &nBJet20T_     );
   tree_->SetBranchAddress("nBJet20M",     &nBJet20M_     );
   tree_->SetBranchAddress("nBJet20L",     &nBJet20L_     );
   tree_->SetBranchAddress("nJet20",       &nJet20_       );
   tree_->SetBranchAddress("nBJet30T",     &nBJet30T_     );
   tree_->SetBranchAddress("nBJet30M",     &nBJet30M_     );
   tree_->SetBranchAddress("nBJet30L",     &nBJet30L_     );
   tree_->SetBranchAddress("nJet30",       &nJet30_       );
   tree_->SetBranchAddress("nBJet20TPuppi",&nBJet20TPuppi_);
   tree_->SetBranchAddress("nBJet20M",     &nBJet20M_     );
   tree_->SetBranchAddress("nBJet20L",     &nBJet20L_     );
   tree_->SetBranchAddress("nJet20",       &nJet20_       );
   tree_->SetBranchAddress("nBJet30TPuppi",&nBJet30TPuppi_);
   tree_->SetBranchAddress("nBJet30M",     &nBJet30M_     );
   tree_->SetBranchAddress("nBJet30L",     &nBJet30L_     );
   tree_->SetBranchAddress("nJet30",       &nJet30_       );
///
   tree_->SetBranchAddress("met",               &met_               );
   tree_->SetBranchAddress("metphi",            &metphi_            );
   tree_->SetBranchAddress("metNoHFphi",        &metNoHFphi_        );
   tree_->SetBranchAddress("metNoHF",           &metNoHF_           );
   tree_->SetBranchAddress("metPfMvaphi",       &metPfMvaphi_       );
   tree_->SetBranchAddress("metPfMva",          &metPfMva_          );
   tree_->SetBranchAddress("metPuppiphi",       &metPuppiphi_       );
   tree_->SetBranchAddress("metPuppi",          &metPuppi_          );
   tree_->SetBranchAddress("ll_lep1_pt",        &ll_lep1_pt_        );
   tree_->SetBranchAddress("ll_lep1_eta",       &ll_lep1_eta_       );
   tree_->SetBranchAddress("ll_lep1_phi",       &ll_lep1_phi_       );
   tree_->SetBranchAddress("ll_lep1_iso",       &ll_lep1_iso_       );
   tree_->SetBranchAddress("ll_zmass",          &ll_zmass_          );
   tree_->SetBranchAddress("ll_lep2_pt",        &ll_lep2_pt_        );
   tree_->SetBranchAddress("ll_lep2_eta",       &ll_lep2_eta_       );
   tree_->SetBranchAddress("ll_lep2_phi",       &ll_lep2_phi_       );
   tree_->SetBranchAddress("ll_lep2_iso",       &ll_lep2_iso_       );
   tree_->SetBranchAddress("ll_lep1_q",         &ll_lep1_q_         );
   tree_->SetBranchAddress("ll_lep2_q",         &ll_lep2_q_         );
   tree_->SetBranchAddress("ll_lep1_MCmatched", &ll_lep1_MCmatched_ );
   tree_->SetBranchAddress("ll_lep2_MCmatched", &ll_lep2_MCmatched_ );
   tree_->SetBranchAddress("ll_lep1_pdgid",     &ll_lep1_pdgid_     );
   tree_->SetBranchAddress("ll_lep2_pdgid",     &ll_lep2_pdgid_     );
   tree_->SetBranchAddress("lepton_N",          &lepton_N_          );
   tree_->SetBranchAddress("isMM",              &isMM_              );
   tree_->SetBranchAddress("isEE",              &isEE_              );
   tree_->SetBranchAddress("isEM",              &isEM_              );
   tree_->SetBranchAddress("Category",          &Category_          );
   tree_->SetBranchAddress("Categorytb",        &Categorytb_        );
   tree_->SetBranchAddress("NgenJet",           &NgenJet_           );

////////
   tree_->SetBranchAddress("pdfWeightId1",                                 &pdfWeightId1_                                );
   tree_->SetBranchAddress("pdfWeightId2",                                 &pdfWeightId2_                                );
   tree_->SetBranchAddress("pdfWeightQ",                                   &pdfWeightQ_                                  );
   tree_->SetBranchAddress("pdfWeightX1",                                  &pdfWeightX1_                                 );
   tree_->SetBranchAddress("pdfWeightX2",                                  &pdfWeightX2_                                 );
   tree_->SetBranchAddress("puWeight",                                     &puWeight_                                    );
   tree_->SetBranchAddress("CSCTightHaloFilter",                           &CSCTightHaloFilter_                          );
   tree_->SetBranchAddress("EcalDeadCellTriggerPrimitiveFilter",           &EcalDeadCellTriggerPrimitiveFilter_          );
   tree_->SetBranchAddress("HBHENoiseFilter",                              &HBHENoiseFilter_                             );
   tree_->SetBranchAddress("eeBadScFilter",                                &eeBadScFilter_                               );
   tree_->SetBranchAddress("goodVertices",                                 &goodVertices_                                );
   tree_->SetBranchAddress("HLTEle17Ele12CaloIdLTrackIdLIsoVLDZ",          &HLTEle17Ele12CaloIdLTrackIdLIsoVLDZ_         );
   tree_->SetBranchAddress("HLTEle17Ele12CaloIdLTrackIdLIsoVLDZold",       &HLTEle17Ele12CaloIdLTrackIdLIsoVLDZold_      );
   tree_->SetBranchAddress("HLTMu17TrkIsoVVLEle12CaloIdLTrackIdLIsoVL",    &HLTMu17TrkIsoVVLEle12CaloIdLTrackIdLIsoVL_   );
   tree_->SetBranchAddress("HLTMu17TrkIsoVVLEle12CaloIdLTrackIdLIsoVLold", &HLTMu17TrkIsoVVLEle12CaloIdLTrackIdLIsoVLold_);
   tree_->SetBranchAddress("HLTMu17TrkIsoVVLMu8TrkIsoVVLDZ",               &HLTMu17TrkIsoVVLMu8TrkIsoVVLDZ_              );
   tree_->SetBranchAddress("HLTMu17TrkIsoVVLMu8TrkIsoVVLDZold",            &HLTMu17TrkIsoVVLMu8TrkIsoVVLDZold_           );
   tree_->SetBranchAddress("HLTMu17TrkIsoVVLTkMu8TrkIsoVVLDZ",             &HLTMu17TrkIsoVVLTkMu8TrkIsoVVLDZ_            );
   tree_->SetBranchAddress("HLTMu17TrkIsoVVLTkMu8TrkIsoVVLDZold",          &HLTMu17TrkIsoVVLTkMu8TrkIsoVVLDZold_         );
   tree_->SetBranchAddress("HLTMu8TrkIsoVVLEle17CaloIdLTrackIdLIsoVL",     &HLTMu8TrkIsoVVLEle17CaloIdLTrackIdLIsoVL_    );
   tree_->SetBranchAddress("HLTMu8TrkIsoVVLEle17CaloIdLTrackIdLIsoVLold",  &HLTMu8TrkIsoVVLEle17CaloIdLTrackIdLIsoVLold_ );
   tree_->SetBranchAddress("nGoodPV",                                      &nGoodPV_                                     );
   tree_->SetBranchAddress("nPV",                                          &nPV_                                         );
   tree_->SetBranchAddress("nTrueInteraction",                             &nTrueInteraction_                            );

   tree_->SetBranchAddress("CutsD",     &CutsD_);
   tree_->SetBranchAddress("LikelihoodD",&LikelihoodD_);
   tree_->SetBranchAddress("MLP",       &MLP_);
   tree_->SetBranchAddress("MLPBFGS",   &MLPBFGS_);
   tree_->SetBranchAddress("MLPBNN",    &MLPBNN_);
   tree_->SetBranchAddress("BDT",       &BDT_);
   tree_->SetBranchAddress("BDTD",      &BDTD_);
   tree_->SetBranchAddress("BDTG",      &BDTG_);

}

///////////
FlatTree::~FlatTree()
{
}
#endif
