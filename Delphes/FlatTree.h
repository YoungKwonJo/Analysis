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
  int     nVertex_, nJet30_, nbJet30T_;
  double M_j12_, M_j34_;
  double gM_j12_, gM_j34_;

  int nJet30BH_, nJet30BQ_, nJet30BTQ_, nJet30BHiggs_;
  int nJet30CH_, nJet30CQ_, nJet30CTQ_, nJet30CHiggs_;

  double jet1_pt_, jet2_pt_, jet3_pt_, jet4_pt_;
  double jet1_eta_, jet2_eta_, jet3_eta_, jet4_eta_;
  double jet1_phi_, jet2_phi_, jet3_phi_, jet4_phi_;
  double jet1_bTag_, jet2_bTag_, jet3_bTag_, jet4_bTag_;

  double jet1_bDR_, jet2_bDR_, jet3_bDR_, jet4_bDR_;
  int jet1_flavor_, jet2_flavor_, jet3_flavor_, jet4_flavor_;

  double gjet1_pt_, gjet2_pt_, gjet3_pt_, gjet4_pt_;
  double gjet1_eta_, gjet2_eta_, gjet3_eta_, gjet4_eta_;
  double gjet1_phi_, gjet2_phi_, gjet3_phi_, gjet4_phi_;

  double gjet1_bTag_, gjet2_bTag_, gjet3_bTag_, gjet4_bTag_;
  double gjet1_bDR_, gjet2_bDR_, gjet3_bDR_, gjet4_bDR_;
  int gjet1_flavor_, gjet2_flavor_, gjet3_flavor_, gjet4_flavor_;

// generated level
  bool isMC_;

  int NgBQ1st_;
  double gBQ1st_DR1fromT_, gBQ1st_DR2add_;
  double gBQ1st_M1fromT_, gBQ1st_M2add_;
  double gBQ1st_DR1jjfromT_, gBQ1st_DR2jjadd_;
  double gBQ1st_M1jjfromT_, gBQ1st_M2jjadd_;


  int NgBQlast_;
  double gBQlast_DR1_, gBQlast_DR2_, gBQlast_DR3_, gBQlast_DR4_;
  doublesP gBQlast_pt_;
  doublesP gBQlast_eta_;
//  int nbJet30g_; // with reco

  //int gnbJet30_;
  int gnJet30BH_, gnJet30BQ_, gnJet30BTQ_, gnJet30BHiggs_;
  int gnJet30CH_, gnJet30CQ_, gnJet30CTQ_, gnJet30CHiggs_;
  int gnJetOverlap_; 
  int gnJetBNTQ_, gnJetBNTQOverlap_;
  int gnJet30BTHiggs_;
 
  int gnJet30_;
  int leptonic_;
  int electronic_;
  int muonic_;
  int taunic_;
  int topN_;
  int wN_;
  //int t2w_1_,   t2w_2_;
  //int w2lnu_1_, w2lnu_2_;

  int ttIndex_;
  int dileptonic_;
  //double puweight_, puweightUp_, puweightDw_, bTagweight_, leptonweight_;
  //int nGenbJet20_, nGencJet20_, nGenJet20_;
  //double genLep1_pt_, genLep2_pt_, genLep1_eta_, genLep2_eta_;
 
};
//#endif

//#ifdef FlatTree_cxx
FlatTree::FlatTree(bool isMC)
{
   isMC_ = isMC;
   gBQlast_pt_  = new doubles;
   gBQlast_eta_ = new doubles;

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
  tree_->Branch("nJet30BH"  ,   &nJet30BH_  ,  "nJet30BH/I"  );
  tree_->Branch("nJet30BQ"  ,   &nJet30BQ_  ,  "nJet30BQ/I"  );
  tree_->Branch("nJet30BTQ"  ,  &nJet30BTQ_  , "nJet30BTQ/I"  );
  tree_->Branch("nJet30BHiggs", &nJet30BHiggs_,"nJet30BHiggs/I"  );
  tree_->Branch("nJet30CH"  ,   &nJet30CH_  ,  "nJet30CH/I"  );
  tree_->Branch("nJet30CQ"  ,   &nJet30CQ_  ,  "nJet30CQ/I"  );
  tree_->Branch("nJet30CTQ"  ,  &nJet30CTQ_  , "nJet30CTQ/I"  );
  tree_->Branch("nJet30CHiggs", &nJet30CHiggs_,"nJet30CHiggs/I"  );

  //tree_->Branch("nbJet30g"  ,  &nbJet30g_  , "nbJet30g/I"  );
  //tree_->Branch("gnbJet30"  ,  &gnbJet30_  , "gnbJet30/I"  );
  tree_->Branch("gnJet30BH"  ,   &gnJet30BH_  ,  "gnJet30BH/I"  );
  tree_->Branch("gnJet30BQ"  ,   &gnJet30BQ_  ,  "gnJet30BQ/I"  );
  tree_->Branch("gnJet30BTQ"  ,  &gnJet30BTQ_  , "gnJet30BTQ/I"  );
  tree_->Branch("gnJet30BHiggs", &gnJet30BHiggs_,"gnJet30BHiggs/I"  );
  tree_->Branch("gnJet30BTHiggs", &gnJet30BTHiggs_,"gnJet30BTHiggs/I"  );
  tree_->Branch("gnJetOverlap", &gnJetOverlap_,"gnJetOverlap/I"  );
  tree_->Branch("gnJetBNTQ", &gnJetBNTQ_,"gnJetBNTQ/I"  );
  tree_->Branch("gnJetBNTQOverlap", &gnJetBNTQOverlap_,"gnJetBNTQOverlap/I"  );

  tree_->Branch("gnJet30CH"  ,   &gnJet30CH_  ,  "gnJet30CH/I"  );
  tree_->Branch("gnJet30CQ"  ,   &gnJet30CQ_  ,  "gnJet30CQ/I"  );
  tree_->Branch("gnJet30CTQ"  ,  &gnJet30CTQ_  , "gnJet30CTQ/I"  );
  tree_->Branch("gnJet30CHiggs", &gnJet30CHiggs_,"gnJet30CHiggs/I"  );

  tree_->Branch("NgBQ1st",  &NgBQ1st_, "NgBQ1st/I");
  tree_->Branch("gBQ1st_DR1fromT",  &gBQ1st_DR1fromT_, "gBQ1st_DR1fromT/D");
  tree_->Branch("gBQ1st_M1fromT",  &gBQ1st_M1fromT_, "gBQ1st_M1fromT/D");
  tree_->Branch("gBQ1st_DR2add",  &gBQ1st_DR2add_, "gBQ1st_DR2add/D");
  tree_->Branch("gBQ1st_M2add",  &gBQ1st_M2add_, "gBQ1st_M2add/D");

  tree_->Branch("gBQ1st_DR1jjfromT",  &gBQ1st_DR1jjfromT_, "gBQ1st_DR1jjfromT/D");
  tree_->Branch("gBQ1st_M1jjfromT",  &gBQ1st_M1jjfromT_, "gBQ1st_M1jjfromT/D");
  tree_->Branch("gBQ1st_DR2jjadd",  &gBQ1st_DR2jjadd_, "gBQ1st_DR2jjadd/D");
  tree_->Branch("gBQ1st_M2jjadd",  &gBQ1st_M2jjadd_, "gBQ1st_M2jjadd/D");

  tree_->Branch("NgBQlast",  &NgBQlast_, "NgBQlast/I");
  tree_->Branch("gBQlast_DR1",  &gBQlast_DR1_, "gBQlast_DR1/D");
  tree_->Branch("gBQlast_DR2",  &gBQlast_DR2_, "gBQlast_DR2/D");

  tree_->Branch("gBQlast_DR3",  &gBQlast_DR3_, "gBQlast_DR3/D");
  tree_->Branch("gBQlast_DR4",  &gBQlast_DR4_, "gBQlast_DR4/D");

  tree_->Branch("gBQlast_pt"  , gBQlast_pt_  );
  tree_->Branch("gBQlast_eta"  , gBQlast_eta_  );

//  tree_->Branch("nJet50"  ,  &nJet50_  , "nJet50/I"  );
  tree_->Branch("nbJet30T",  &nbJet30T_, "nbJet30T/I");
  tree_->Branch("M_j12",  &M_j12_, "M_j12/D");
  tree_->Branch("M_j34",  &M_j34_, "M_j34/D");
  tree_->Branch("gM_j12",  &gM_j12_, "gM_j12/D");
  tree_->Branch("gM_j34",  &gM_j34_, "gM_j34/D");
//  tree_->Branch("nbJet50T",  &nbJet50T_, "nbJet50T/I");

  tree_->Branch("jet1_pt" ,  &jet1_pt_ , "jet1_pt/D" ); 
  tree_->Branch("jet2_pt" ,  &jet2_pt_ , "jet2_pt/D" ); 
  tree_->Branch("jet3_pt" ,  &jet3_pt_ , "jet3_pt/D" ); 
  tree_->Branch("jet4_pt" ,  &jet4_pt_ , "jet4_pt/D" ); 
  tree_->Branch("jet1_eta",  &jet1_eta_, "jet1_eta/D" );
  tree_->Branch("jet2_eta",  &jet2_eta_, "jet2_eta/D" );
  tree_->Branch("jet3_eta",  &jet3_eta_, "jet3_eta/D" );
  tree_->Branch("jet4_eta",  &jet4_eta_, "jet4_eta/D" );
  tree_->Branch("jet1_phi",  &jet1_phi_, "jet1_phi/D" );
  tree_->Branch("jet2_phi",  &jet2_phi_, "jet2_phi/D" );
  tree_->Branch("jet3_phi",  &jet3_phi_, "jet3_phi/D" );
  tree_->Branch("jet4_phi",  &jet4_phi_, "jet4_phi/D" );
 
  tree_->Branch("jet1_bTag",  &jet1_bTag_, "jet1_bTag/D" );
  tree_->Branch("jet2_bTag",  &jet2_bTag_, "jet2_bTag/D" );
  tree_->Branch("jet3_bTag",  &jet3_bTag_, "jet3_bTag/D" );
  tree_->Branch("jet4_bTag",  &jet4_bTag_, "jet4_bTag/D" );

  tree_->Branch("jet1_bDR",  &jet1_bDR_, "jet1_bDR/D" );
  tree_->Branch("jet2_bDR",  &jet2_bDR_, "jet2_bDR/D" );
  tree_->Branch("jet3_bDR",  &jet3_bDR_, "jet3_bDR/D" );
  tree_->Branch("jet4_bDR",  &jet4_bDR_, "jet4_bDR/D" );

  if(isMC_)
  {
     tree_->Branch("gnJet30"  ,  &gnJet30_  , "gnJet30/I"  );

     tree_->Branch("gjet1_pt" ,  &gjet1_pt_ , "gjet1_pt/D" ); 
     tree_->Branch("gjet2_pt" ,  &gjet2_pt_ , "gjet2_pt/D" ); 
     tree_->Branch("gjet3_pt" ,  &gjet3_pt_ , "gjet3_pt/D" ); 
     tree_->Branch("gjet4_pt" ,  &gjet4_pt_ , "gjet4_pt/D" ); 
     tree_->Branch("gjet1_eta",  &gjet1_eta_, "gjet1_eta/D" );
     tree_->Branch("gjet2_eta",  &gjet2_eta_, "gjet2_eta/D" );
     tree_->Branch("gjet3_eta",  &gjet3_eta_, "gjet3_eta/D" );
     tree_->Branch("gjet4_eta",  &gjet4_eta_, "gjet4_eta/D" );
     tree_->Branch("gjet1_phi",  &gjet1_phi_, "gjet1_phi/D" );
     tree_->Branch("gjet2_phi",  &gjet2_phi_, "gjet2_phi/D" );
     tree_->Branch("gjet3_phi",  &gjet3_phi_, "gjet3_phi/D" );
     tree_->Branch("gjet4_phi",  &gjet4_phi_, "gjet4_phi/D" );

/*
     tree_->Branch("gjet1_bTag",  &gjet1_bTag_, "gjet1_bTag/D" );
     tree_->Branch("gjet2_bTag",  &gjet2_bTag_, "gjet2_bTag/D" );
     tree_->Branch("gjet3_bTag",  &gjet3_bTag_, "gjet3_bTag/D" );
     tree_->Branch("gjet4_bTag",  &gjet4_bTag_, "gjet4_bTag/D" );
*/
     tree_->Branch("gjet1_bDR",  &gjet1_bDR_, "gjet1_bDR/D" );
     tree_->Branch("gjet2_bDR",  &gjet2_bDR_, "gjet2_bDR/D" );
     tree_->Branch("gjet3_bDR",  &gjet3_bDR_, "gjet3_bDR/D" );
     tree_->Branch("gjet4_bDR",  &gjet4_bDR_, "gjet4_bDR/D" );

     tree_->Branch("jet1_flavor",  &jet1_flavor_, "jet1_flavor/I" );
     tree_->Branch("jet2_flavor",  &jet2_flavor_, "jet2_flavor/I" );
     tree_->Branch("jet3_flavor",  &jet3_flavor_, "jet3_flavor/I" );
     tree_->Branch("jet4_flavor",  &jet4_flavor_, "jet4_flavor/I" );
/*
     tree_->Branch("gjet1_flavor",  &gjet1_flavor_, "gjet1_flavor/I" );
     tree_->Branch("gjet2_flavor",  &gjet2_flavor_, "gjet2_flavor/I" );
     tree_->Branch("gjet3_flavor",  &gjet3_flavor_, "gjet3_flavor/I" );
     tree_->Branch("gjet4_flavor",  &gjet4_flavor_, "gjet4_flavor/I" );
*/
     tree_->Branch("leptonic",  &leptonic_, "leptonic/I" );
     tree_->Branch("electronic",  &electronic_, "electronic/I" );
     tree_->Branch("muonic",  &muonic_, "muonic/I" );
     tree_->Branch("taunic",  &taunic_, "taunic/I" );
     tree_->Branch("topN",  &topN_, "topN/I" );
     tree_->Branch("wN",  &wN_, "wN/I" );

     tree_->Branch("ttIndex"   ,     &ttIndex_      , "ttIndex/I"    );    

     tree_->Branch("dileptonic",  &dileptonic_,  "dileptonic/I");
//     tree_->Branch("genLep1_pt" , &genLep1_pt_ , "genLep1_pt/D"); 
//     tree_->Branch("genLep2_pt" , &genLep2_pt_ , "genLep2_pt/D"); 
//     tree_->Branch("genLep1_eta", &genLep1_eta_, "genLep1_eta/D");
//     tree_->Branch("genLep2_eta", &genLep2_eta_, "genLep2_eta/D");

/*     tree_->Branch("puweight"  ,     &puweight_     , "puweight/D"   );    
     tree_->Branch("puweightUp",     &puweightUp_   , "puweightUp/D" ); 
     tree_->Branch("puweightDw",     &puweightDw_   , "puweightDw/D" ); 
     tree_->Branch("bTagweight" ,     &bTagweight_    , "bTagweight/D"  );   
     tree_->Branch("leptonweight" ,  &leptonweight_ , "leptonweight/D"  );   
*/
  }

}
void FlatTree::clear()
{
   gBQlast_pt_->clear();
   gBQlast_eta_->clear();

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
   //nbJet30g_=-999;
   //gnbJet30_=-999;
   nJet30BH_=-999; nJet30BQ_=-999; nJet30BTQ_=-999; nJet30BHiggs_=-999;
   nJet30CH_=-999; nJet30CQ_=-999; nJet30CTQ_=-999; nJet30CHiggs_=-999;

   NgBQ1st_=-999;
   gBQ1st_DR1fromT_=-999; gBQ1st_DR2add_=-999;
   gBQ1st_M1fromT_=-999; gBQ1st_M2add_=-999;
   gBQ1st_DR1jjfromT_=-999; gBQ1st_DR2jjadd_=-999;
   gBQ1st_M1jjfromT_=-999; gBQ1st_M2jjadd_=-999;

   NgBQlast_=-999;
   gBQlast_DR1_=-999; gBQlast_DR2_=-999; gBQlast_DR3_=-999; gBQlast_DR4_=-999;

   gnJet30BH_=-999; gnJet30BQ_=-999; gnJet30BTQ_=-999; 
gnJet30BHiggs_=-999;
gnJet30BTHiggs_=-999;
   gnJetOverlap_=-999;
   gnJetBNTQ_=-999;
   gnJetBNTQOverlap_=-999;
   gnJet30CH_=-999; gnJet30CQ_=-999; gnJet30CTQ_=-999; gnJet30CHiggs_=-999;

   nbJet30T_=-999;
   M_j12_=-999;
   M_j34_=-999;
   gM_j12_=-999;
   gM_j34_=-999;

   jet1_pt_=-999;       jet2_pt_=-999;       jet3_pt_=-999;       jet4_pt_=-999;
   jet1_eta_=-999;      jet2_eta_=-999;      jet3_eta_=-999;      jet4_eta_=-999;
   jet1_phi_=-999;      jet2_phi_=-999;      jet3_phi_=-999;      jet4_phi_=-999;
   jet1_bTag_=-999;      jet2_bTag_=-999;      jet3_bTag_=-999;      jet4_bTag_=-999;
   jet1_bDR_=-999;      jet2_bDR_=-999;      jet3_bDR_=-999;      jet4_bDR_=-999;

   gjet1_pt_=-999;       gjet2_pt_=-999;       gjet3_pt_=-999;       gjet4_pt_=-999;
   gjet1_eta_=-999;      gjet2_eta_=-999;      gjet3_eta_=-999;      gjet4_eta_=-999;
   gjet1_phi_=-999;      gjet2_phi_=-999;      gjet3_phi_=-999;      gjet4_phi_=-999;
   gjet1_bTag_=-999;      gjet2_bTag_=-999;      gjet3_bTag_=-999;      gjet4_bTag_=-999;
   gjet1_bDR_=-999;      gjet2_bDR_=-999;      gjet3_bDR_=-999;      gjet4_bDR_=-999;

   if(isMC_)
   {
     gnJet30_=-999;
     jet1_flavor_=-999;   jet2_flavor_=-999;   jet3_flavor_=-999;   jet4_flavor_=-999;
     gjet1_flavor_=-999;   gjet2_flavor_=-999;   gjet3_flavor_=-999;   gjet4_flavor_=-999;
     leptonic_  =-99;
     electronic_  =-99;
     muonic_  =-99;
     taunic_  =-99;
     wN_  =-99;
     topN_  =-99;

//     puweight_=-999;      puweightUp_=-999;    puweightDw_=-999;    bTagweight_=-999;
     dileptonic_ =-999;
     ttIndex_=0;
//   genLep1_pt_ =-999;  genLep2_pt_ =-999;
//   genLep1_eta_=-999;  genLep2_eta_=-999;
   }
   else 
   {
     jet1_flavor_=0;  jet2_flavor_=0;   jet3_flavor_=0;  jet4_flavor_=0;
//     gjet1_flavor_=0;  gjet2_flavor_=0;   gjet3_flavor_=0;  gjet4_flavor_=0;
//     puweight_=1;     puweightUp_=1;    puweightDw_=1;   bTagweight_=1;
//     dileptonic_ =1;
     ttIndex_=0;
   }

}
FlatTree::~FlatTree()
{
}
#endif
