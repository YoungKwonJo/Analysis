#ifndef FlatNtuple_h
#define FlatNtuple_h

#include <vector>
#include "TTree.h"

struct FlatNtuple
{
 public:
  FlatNtuple(bool isMC=false);
  ~FlatNtuple();

  void book(TTree* tree); // book leaves to fill the tree
//  void setBranch(TTree* tree);
//       {tree_ = tree; tree_->SetBranchAddress("run", &run_);}
  void clear();

public:
  TTree* tree_;
  int run_, lumi_, event_;
  int  cutSteps_;

  double lep1_pt_, lep2_pt_, lep1_eta_, lep2_eta_, lep1_relIso_, lep2_relIso_;
  double MET_, ZMass_;
  int nJet30_, nJet50_, nbJet30T_, nbJet50T_;

  double jet1_pt_, jet2_pt_, jet3_pt_, jet4_pt_;
  double jet1_eta_, jet2_eta_, jet3_eta_, jet4_eta_;
  double jet1_csv_, jet2_csv_, jet3_csv_, jet4_csv_;
  int jet1_flavor_, jet2_flavor_, jet3_flavor_, jet4_flavor_;

  double tMass_, tbarMass_, kinweight_, kinNuEt_, kinNubarEt_;

  bool isMC_;
  int  ttIndex_, nVertex_;
  double puweight_,puweightUp_, puweightDw_, csvweight_, leptonweight_;

};
//#endif

//#ifdef FlatNtuple_cxx
FlatNtuple::FlatNtuple(bool isMC)
{
   isMC_ = isMC;
}
void FlatNtuple::book(TTree* tree)
{
  tree_ = tree;

  tree_->Branch("run"  , &run_  , "run/I");
  tree_->Branch("lumi" , &lumi_ , "lumi/I");
  tree_->Branch("event", &event_, "event/I");

  tree_->Branch("cutSteps", &cutSteps_, "cutSteps/I");

  tree_->Branch("lep1_pt"    , &lep1_pt_    , "lep1_pt/D"    );
  tree_->Branch("lep2_pt"    , &lep2_pt_    , "lep2_pt/D"    );
  tree_->Branch("lep1_eta"   , &lep1_eta_   , "lep1_eta/D"   );
  tree_->Branch("lep2_eta"   , &lep2_eta_   , "lep2_eta/D"   );
  tree_->Branch("lep1_relIso", &lep1_relIso_, "lep1_relIso/D");
  tree_->Branch("lep2_relIso", &lep2_relIso_, "lep2_relIso/D");

  tree_->Branch("MET"     ,  &MET_     , "MET/D"     );
  tree_->Branch("ZMass"   ,  &ZMass_   , "ZMass/D"   ); 
  tree_->Branch("nJet30"  ,  &nJet30_  , "nJet30/I"  );
  tree_->Branch("nJet50"  ,  &nJet50_  , "nJet50/I"  );
  tree_->Branch("nbJet30T",  &nbJet30T_, "nbJet30T/I");
  tree_->Branch("nbJet50T",  &nbJet50T_, "nbJet50T/I");

  tree_->Branch("jet1_pt" ,  &jet1_pt_ , "jet1_pt/D" ); 
  tree_->Branch("jet2_pt" ,  &jet2_pt_ , "jet2_pt/D" ); 
  tree_->Branch("jet3_pt" ,  &jet3_pt_ , "jet3_pt/D" ); 
  tree_->Branch("jet4_pt" ,  &jet4_pt_ , "jet4_pt/D" ); 
  tree_->Branch("jet1_eta",  &jet1_eta_, "jet1_eta/D" );
  tree_->Branch("jet2_eta",  &jet2_eta_, "jet2_eta/D" );
  tree_->Branch("jet3_eta",  &jet3_eta_, "jet3_eta/D" );
  tree_->Branch("jet4_eta",  &jet4_eta_, "jet4_eta/D" );
  tree_->Branch("jet1_csv",  &jet1_csv_, "jet1_csv/D" );
  tree_->Branch("jet2_csv",  &jet2_csv_, "jet2_csv/D" );
  tree_->Branch("jet3_csv",  &jet3_csv_, "jet3_csv/D" );
  tree_->Branch("jet4_csv",  &jet4_csv_, "jet4_csv/D" );

  tree_->Branch("jet1_flavor",  &jet1_flavor_, "jet1_flavor/I" );
  tree_->Branch("jet2_flavor",  &jet2_flavor_, "jet2_flavor/I" );
  tree_->Branch("jet3_flavor",  &jet3_flavor_, "jet3_flavor/I" );
  tree_->Branch("jet4_flavor",  &jet4_flavor_, "jet4_flavor/I" );

  tree_->Branch("tMass"    ,  &tMass_    , "tMass/D"    );    
  tree_->Branch("tbarMass" ,  &tbarMass_ , "tbarMass/D" ); 
  tree_->Branch("kinweight",  &kinweight_, "kinweight/D");
  tree_->Branch("kinNuEt"  ,  &kinNuEt_  , "kinNuEt/D"  );  
  tree_->Branch("kinNubarEt" ,  &kinNubarEt_ , "kinNubarEt/D" ); 

  if(isMC_)
  {
     tree_->Branch("ttIndex"   ,     &ttIndex_      , "ttIndex/I"    );    
     tree_->Branch("nVertex"   ,     &nVertex_      , "nVertex/I"    );    
     tree_->Branch("puweight"  ,     &puweight_     , "puweight/D"   );    
     tree_->Branch("puweightUp",     &puweightUp_   , "puweightUp/D" ); 
     tree_->Branch("puweightDw",     &puweightDw_   , "puweightDw/D" ); 
     tree_->Branch("csvweight" ,     &csvweight_    , "csvweight/D"  );   
     tree_->Branch("leptonweight" ,  &leptonweight_ , "leptonweight/D"  );   
  }

}
void FlatNtuple::clear()
{
   cutSteps_=-999;
   lep1_pt_=-999;   lep2_pt_=-999;   lep1_eta_=-999;   lep2_eta_=-999;   lep1_relIso_=-999;   lep2_relIso_=-999;
   MET_=-999;   ZMass_=-999;
   nJet30_=-999;   nJet50_=-999;   nbJet30T_=-999;   nbJet50T_=-999;

   jet1_pt_=-999;    jet2_pt_=-999;    jet3_pt_=-999;    jet4_pt_=-999;
   jet1_eta_=-999;   jet2_eta_=-999;   jet3_eta_=-999;   jet4_eta_=-999;
   jet1_csv_=-999;   jet2_csv_=-999;   jet3_csv_=-999;   jet4_csv_=-999;
   jet1_flavor_=-999;   jet2_flavor_=-999;   jet3_flavor_=-999;   jet4_flavor_=-999;

   tMass_=-999;   tbarMass_=-999;   kinweight_=-999;   kinNuEt_=-999;   kinNubarEt_=-999;

   nVertex_=-999;
   puweight_=-999;  puweightUp_=-999;   puweightDw_=-999;   csvweight_=-999;

}
FlatNtuple::~FlatNtuple()
{
}
#endif
