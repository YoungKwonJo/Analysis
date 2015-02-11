#ifndef FlatTree_h
#define FlatTree_h

#include <vector>
#include "TTree.h"

struct FlatTree
{
 public:
  FlatTree(bool isMC=false);
  ~FlatTree();

  void book(TTree* tree); // book leaves to fill the tree
  void clear();

  typedef std::vector<double> doubles;
  typedef doubles* doublesP;
public:
  TTree* tree_;
  int run_, lumi_, event_;
  double lep1_pt_,  lep2_pt_, lep1_eta_, lep2_eta_, lep1_relIso_, lep2_relIso_;
  int     lep1_Q_,  lep2_Q_;

  double  MET_, METPHI_, ZMass_, Zdphi_;
  int     nVertex_, nJet30_, nbJet30L_,nbJet30M_, nbJet30T_;
  int     nJet50_, nbJet50L_,nbJet50M_, nbJet50T_;

  double jet1_pt_, jet2_pt_, jet3_pt_, jet4_pt_;
  double jet1_eta_, jet2_eta_, jet3_eta_, jet4_eta_;
  double jet1_phi_, jet2_phi_, jet3_phi_, jet4_phi_;
  double jet1_bTag_, jet2_bTag_, jet3_bTag_, jet4_bTag_;

  bool isMC_;
  double gentop_lep1_pt_, gentop_lep1_eta_, gentop_lep2_pt_, gentop_lep2_eta_;
  int gentop_NJets_, gentop_NJets10_, gentop_NJets20_, gentop_NJets25_, gentop_NJets30_, gentop_NJets40_;
  int gentop_NaddJets20_, gentop_NaddJets40_, gentop_NaddbJets_, gentop_NaddbJets20_, gentop_NaddbJets40_;
  int gentop_NaddbQuarks20_, gentop_NaddbQuarks40_;
  int gentop_NbJets_, gentop_NbJets20_, gentop_NbJets25_, gentop_NbJets30_, gentop_NbJets40_;
  int gentop_NbQuarks_, gentop_NbQuarks20_, gentop_NbQuarks40_;
  int gentop_NbQuarksNoTop_, gentop_NbQuarksTop_;
  int gentop_NcJets_, gentop_NcJets10_, gentop_NcJets15_, gentop_NcJets20_, gentop_NcJets25_, gentop_NcJets30_, gentop_NcJets40_, gentop_NcQuarks_;
  int gentop_allHadronic_, gentop_diLeptonicEleEle_, gentop_diLeptonicMuoEle_, gentop_diLeptonicMuoMuo_;
  int gentop_diLeptonicTauEle_, gentop_diLeptonicTauMuo_, gentop_diLeptonicTauTau_, gentop_semiLeptonic_;

};
//#endif

//#ifdef FlatTree_cxx
FlatTree::FlatTree(bool isMC)
{
   isMC_ = isMC;
}
void FlatTree::book(TTree* tree)
{
  tree_ = tree;

  tree_->Branch("run"  , &run_  , "run/I");
  tree_->Branch("lumi" , &lumi_ , "lumi/I");
  tree_->Branch("event", &event_, "event/I");

  tree_->Branch("lep1_pt"    , &lep1_pt_    , "lep1_pt/D"    );
  tree_->Branch("lep2_pt"    , &lep2_pt_    , "lep2_pt/D"    );
  tree_->Branch("lep1_eta"   , &lep1_eta_   , "lep1_eta/D"   );
  tree_->Branch("lep2_eta"   , &lep2_eta_   , "lep2_eta/D"   );
  tree_->Branch("lep1_relIso", &lep1_relIso_, "lep1_relIso/D");
  tree_->Branch("lep2_relIso", &lep2_relIso_, "lep2_relIso/D");
  tree_->Branch("lep1_Q"    , &lep1_Q_    , "lep1_Q/I"    );
  tree_->Branch("lep2_Q"    , &lep2_Q_    , "lep2_Q/I"    );
 
  tree_->Branch("nVertex" ,  &nVertex_ , "nVertex/I" );    
  tree_->Branch("MET"     ,  &MET_     , "MET/D"     );
  tree_->Branch("METPHI"  ,  &METPHI_     , "METPHI/D"     );
  tree_->Branch("ZMass"   ,  &ZMass_   , "ZMass/D"   ); 
  tree_->Branch("Zdphi"   ,  &Zdphi_   , "Zdphi/D"   ); 

  tree_->Branch("nJet30"  ,    &nJet30_  , "nJet30/I"  );
  tree_->Branch("nbJet30L"  ,    &nbJet30L_  , "nbJet30L/I"  );
  tree_->Branch("nbJet30M"  ,    &nbJet30M_  , "nbJet30M/I"  );
  tree_->Branch("nbJet30T"  ,    &nbJet30T_  , "nbJet30T/I"  );

  tree_->Branch("nJet50"  ,    &nJet50_  , "nJet50/I"  );
  tree_->Branch("nbJet50L"  ,    &nbJet50L_  , "nbJet50L/I"  );
  tree_->Branch("nbJet50M"  ,    &nbJet50M_  , "nbJet50M/I"  );
  tree_->Branch("nbJet50T"  ,    &nbJet50T_  , "nbJet50T/I"  );

  tree_->Branch("jet1_pt",   &jet1_pt_,  "jet1_pt/D");
  tree_->Branch("jet2_pt",   &jet2_pt_,  "jet2_pt/D");
  tree_->Branch("jet3_pt",   &jet3_pt_,  "jet3_pt/D");
  tree_->Branch("jet4_pt",   &jet4_pt_,  "jet4_pt/D");
  tree_->Branch("jet1_eta",  &jet1_eta_, "jet1_eta/D");
  tree_->Branch("jet2_eta",  &jet2_eta_, "jet2_eta/D");
  tree_->Branch("jet3_eta",  &jet3_eta_, "jet3_eta/D");
  tree_->Branch("jet4_eta",  &jet4_eta_, "jet4_eta/D");
  tree_->Branch("jet1_phi",  &jet1_phi_, "jet1_phi/D");
  tree_->Branch("jet2_phi",  &jet2_phi_, "jet2_phi/D");
  tree_->Branch("jet3_phi",  &jet3_phi_, "jet3_phi/D");
  tree_->Branch("jet4_phi",  &jet4_phi_, "jet4_phi/D");
  tree_->Branch("jet1_bTag", &jet1_bTag_, "jet1_bTag/D");
  tree_->Branch("jet2_bTag", &jet2_bTag_, "jet2_bTag/D");
  tree_->Branch("jet3_bTag", &jet3_bTag_, "jet3_bTag/D");
  tree_->Branch("jet4_bTag", &jet4_bTag_, "jet4_bTag/D");

// isMC
 tree_->Branch("gentop_lep1_pt",  &gentop_lep1_pt_,   "gentop_lep1_pt/D"); 
 tree_->Branch("gentop_lep1_eta", &gentop_lep1_eta_,  "gentop_lep1_eta/D");
 tree_->Branch("gentop_lep2_pt",  &gentop_lep2_pt_,   "gentop_lep2_pt/D");
 tree_->Branch("gentop_lep2_eta", &gentop_lep2_eta_,  "gentop_lep2_eta/D");

   tree_->Branch("gentop_NJets",           &gentop_NJets_  ,          "gentop_NJets/I");
   tree_->Branch("gentop_NJets10",         &gentop_NJets10_,          "gentop_NJets10/I");
   tree_->Branch("gentop_NJets20",         &gentop_NJets20_,          "gentop_NJets20/I");
   tree_->Branch("gentop_NJets25",         &gentop_NJets25_,          "gentop_NJets25/I");
   tree_->Branch("gentop_NJets30",         &gentop_NJets30_,          "gentop_NJets30/I");
   tree_->Branch("gentop_NJets40",         &gentop_NJets40_,          "gentop_NJets40/I");
   tree_->Branch("gentop_NaddJets20",      &gentop_NaddJets20_,       "gentop_NaddJets20/I");
   tree_->Branch("gentop_NaddJets40",      &gentop_NaddJets40_,       "gentop_NaddJets40/I");
   tree_->Branch("gentop_NaddbJets",       &gentop_NaddbJets_,        "gentop_NaddbJets/I");
   tree_->Branch("gentop_NaddbJets20",     &gentop_NaddbJets20_,      "gentop_NaddbJets20/I");
   tree_->Branch("gentop_NaddbJets40",     &gentop_NaddbJets40_,      "gentop_NaddbJets40/I");
   tree_->Branch("gentop_NaddbQuarks20",   &gentop_NaddbQuarks20_,    "gentop_NaddbQuarks20/I");
   tree_->Branch("gentop_NaddbQuarks40",   &gentop_NaddbQuarks40_,    "gentop_NaddbQuarks40/I");
   tree_->Branch("gentop_NbJets",          &gentop_NbJets_,           "gentop_NbJets/I");
   tree_->Branch("gentop_NbJets20",        &gentop_NbJets20_,         "gentop_NbJets20/I");
   tree_->Branch("gentop_NbJets25",        &gentop_NbJets25_,         "gentop_NbJets25/I");
   tree_->Branch("gentop_NbJets30",        &gentop_NbJets30_,         "gentop_NbJets30/I");
   tree_->Branch("gentop_NbJets40",        &gentop_NbJets40_,         "gentop_NbJets40/I");
   tree_->Branch("gentop_NbQuarks",        &gentop_NbQuarks_,         "gentop_NbQuarks/I");
   tree_->Branch("gentop_NbQuarks20",      &gentop_NbQuarks20_,       "gentop_NbQuarks20/I");
   tree_->Branch("gentop_NbQuarks40",      &gentop_NbQuarks40_,       "gentop_NbQuarks40/I");
   tree_->Branch("gentop_NbQuarksNoTop",   &gentop_NbQuarksNoTop_,    "gentop_NbQuarksNoTop/I");
   tree_->Branch("gentop_NbQuarksTop",     &gentop_NbQuarksTop_,      "gentop_NbQuarksTop/I");
   tree_->Branch("gentop_NcJets",          &gentop_NcJets_,           "gentop_NcJets/I");
   tree_->Branch("gentop_NcJets10",        &gentop_NcJets10_,         "gentop_NcJets10/I");
   tree_->Branch("gentop_NcJets15",        &gentop_NcJets15_,         "gentop_NcJets15/I");
   tree_->Branch("gentop_NcJets20",        &gentop_NcJets20_,         "gentop_NcJets20/I");
   tree_->Branch("gentop_NcJets25",        &gentop_NcJets25_,         "gentop_NcJets25/I");
   tree_->Branch("gentop_NcJets30",        &gentop_NcJets30_,         "gentop_NcJets30/I");
   tree_->Branch("gentop_NcJets40",        &gentop_NcJets40_,         "gentop_NcJets40/I");
   tree_->Branch("gentop_NcQuarks",        &gentop_NcQuarks_,         "gentop_NcQuarks/I");
   tree_->Branch("gentop_allHadronic",     &gentop_allHadronic_,      "gentop_allHadronic/I");
   tree_->Branch("gentop_diLeptonicEleEle",&gentop_diLeptonicEleEle_, "gentop_diLeptonicEleEle/I");
   tree_->Branch("gentop_diLeptonicMuoEle",&gentop_diLeptonicMuoEle_, "gentop_diLeptonicMuoEle/I");
   tree_->Branch("gentop_diLeptonicMuoMuo",&gentop_diLeptonicMuoMuo_, "gentop_diLeptonicMuoMuo/I");
   tree_->Branch("gentop_diLeptonicTauEle",&gentop_diLeptonicTauEle_, "gentop_diLeptonicTauEle/I");
   tree_->Branch("gentop_diLeptonicTauMuo",&gentop_diLeptonicTauMuo_, "gentop_diLeptonicTauMuo/I");
   tree_->Branch("gentop_diLeptonicTauTau", &gentop_diLeptonicTauTau_,  "gentop_diLeptonicTauTau/I");
   tree_->Branch("gentop_semiLeptonic",     &gentop_semiLeptonic_,      "gentop_semiLeptonic/I");


}
void FlatTree::clear()
{
   lep1_pt_=-999;       lep2_pt_=-999;   
   lep1_eta_=-999;      lep2_eta_=-999;   
   lep1_Q_=-999;        lep2_Q_=-999;   
   lep1_relIso_=-999;   lep2_relIso_=-999;
   nVertex_=-999;       
   MET_=-999;       
   METPHI_=-999;       
   ZMass_=-999;
   Zdphi_=-999;
   nJet30_=-999;
   nbJet30L_=-999;
   nbJet30M_=-999;
   nbJet30T_=-999;

   nJet50_=-999;
   nbJet50L_=-999;
   nbJet50M_=-999;
   nbJet50T_=-999;

   gentop_lep1_pt_=-999; gentop_lep1_eta_=-999; gentop_lep2_pt_=-999; gentop_lep2_eta_=-999;
   gentop_NJets_=-999;
   gentop_NJets10_=-999;
   gentop_NJets20_=-999;
   gentop_NJets25_=-999;
   gentop_NJets30_=-999;
   gentop_NJets40_=-999;
   gentop_NaddJets20_=-999;
   gentop_NaddJets40_=-999;
   gentop_NaddbJets_=-999;
   gentop_NaddbJets20_=-999;
   gentop_NaddbJets40_=-999;
   gentop_NaddbQuarks20_=-999;
   gentop_NaddbQuarks40_=-999;
   gentop_NbJets_=-999;
   gentop_NbJets20_=-999;
   gentop_NbJets25_=-999;
   gentop_NbJets30_=-999;
   gentop_NbJets40_=-999;
   gentop_NbQuarks_=-999;
   gentop_NbQuarks20_=-999;
   gentop_NbQuarks40_=-999;
   gentop_NbQuarksNoTop_=-999;
   gentop_NbQuarksTop_=-999;
   gentop_NcJets_=-999;
   gentop_NcJets10_=-999;
   gentop_NcJets15_=-999;
   gentop_NcJets20_=-999;
   gentop_NcJets25_=-999;
   gentop_NcJets30_=-999;
   gentop_NcJets40_=-999;
   gentop_NcQuarks_=-999;
   gentop_allHadronic_=-999;
   gentop_diLeptonicEleEle_=-999;
   gentop_diLeptonicMuoEle_=-999;
   gentop_diLeptonicMuoMuo_=-999;
   gentop_diLeptonicTauEle_=-999;
   gentop_diLeptonicTauMuo_=-999;
   gentop_diLeptonicTauTau_=-999;
   gentop_semiLeptonic_=-999;

}
FlatTree::~FlatTree()
{
}
#endif
