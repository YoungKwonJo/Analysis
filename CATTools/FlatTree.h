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
  int  mm_mu1_q_, mm_mu2_q_, ee_el1_q_, ee_el2_q_, em_mu1_q_, em_el2_q_;

  doublesP jet_pt_, jet_eta_, jet_phi_, jet_csv_; 
  //order csv;
  int nBJetT_, nBJetM_, nBJetL_, nJet_;

  int isMM_, isEE_, isEM_, Category_,NgenJet_;

  int Nmu_, Nel_; 
//  TH1F* hSumWeight_;

 
};
//#endif

//#ifdef FlatTree_cxx
FlatTree::FlatTree()
{
   jet_pt_  = new doubles;
   jet_eta_  = new doubles;
   jet_phi_  = new doubles;
   jet_csv_  = new doubles;
   //BH_gjet_ = new ints;

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

  tree_->Branch("Nmu",    &Nmu_,     "Nmu/I");
  tree_->Branch("Nel",    &Nel_,     "Nel/I");

  tree_->Branch("nJet",    &nJet_,     "nJet/I");
  tree_->Branch("nBJetT",  &nBJetT_,   "nBJetT/I");
  tree_->Branch("nBJetM",  &nBJetM_,   "nBJetM/I");
  tree_->Branch("nBJetL",  &nBJetL_,   "nBJetL/I");

  tree_->Branch("met",    &met_,    "met/D");
  tree_->Branch("metphi", &metphi_, "metphi/D");
/////

  tree_->Branch("mm_mu1_pt",   &mm_mu1_pt_,    "mm_mu1_pt/D");
  tree_->Branch("mm_mu1_eta",  &mm_mu1_eta_,   "mm_mu1_eta/D");
  tree_->Branch("mm_mu1_phi",  &mm_mu1_phi_,   "mm_mu1_phi/D");
  tree_->Branch("mm_mu1_q",  &mm_mu1_q_,   "mm_mu1_q/I");
  tree_->Branch("mm_mu1_iso",  &mm_mu1_iso_,   "mm_mu1_iso/D");
  tree_->Branch("mm_mu2_pt",   &mm_mu2_pt_,    "mm_mu2_pt/D");
  tree_->Branch("mm_mu2_eta",  &mm_mu2_eta_,   "mm_mu2_eta/D");
  tree_->Branch("mm_mu2_phi",  &mm_mu2_phi_,   "mm_mu2_phi/D");
  tree_->Branch("mm_mu2_q",  &mm_mu2_q_,   "mm_mu2_q/I");
  tree_->Branch("mm_mu2_iso",  &mm_mu2_iso_,   "mm_mu2_iso/D");
  tree_->Branch("mm_zmass",    &mm_zmass_,     "mm_zmass/D");

  tree_->Branch("ee_el1_pt",   &ee_el1_pt_,    "ee_el1_pt/D");
  tree_->Branch("ee_el1_eta",  &ee_el1_eta_,   "ee_el1_eta/D");
  tree_->Branch("ee_el1_phi",  &ee_el1_phi_,   "ee_el1_phi/D");
  tree_->Branch("ee_el1_q",  &ee_el1_q_,   "ee_el1_q/I");
  tree_->Branch("ee_el1_iso",  &ee_el1_iso_,   "ee_el1_iso/D");
  tree_->Branch("ee_el2_pt",   &ee_el2_pt_,    "ee_el2_pt/D");
  tree_->Branch("ee_el2_eta",  &ee_el2_eta_,   "ee_el2_eta/D");
  tree_->Branch("ee_el2_phi",  &ee_el2_phi_,   "ee_el2_phi/D");
  tree_->Branch("ee_el2_q",  &ee_el2_q_,   "ee_el2_q/I");
  tree_->Branch("ee_el2_iso",  &ee_el2_iso_,   "ee_el2_iso/D");
  tree_->Branch("ee_zmass",    &ee_zmass_,     "ee_zmass/D");

  tree_->Branch("em_mu1_pt",   &em_mu1_pt_,    "em_mu1_pt/D");
  tree_->Branch("em_mu1_eta",  &em_mu1_eta_,   "em_mu1_eta/D");
  tree_->Branch("em_mu1_phi",  &em_mu1_phi_,   "em_mu1_phi/D");
  tree_->Branch("em_mu1_q",  &em_mu1_q_,   "em_mu1_q/I");
  tree_->Branch("em_mu1_iso",  &em_mu1_iso_,   "em_mu1_iso/D");
  tree_->Branch("em_el2_pt",   &em_el2_pt_,    "em_el2_pt/D");
  tree_->Branch("em_el2_eta",  &em_el2_eta_,   "em_el2_eta/D");
  tree_->Branch("em_el2_phi",  &em_el2_phi_,   "em_el2_phi/D");
  tree_->Branch("em_el2_q",  &em_el2_q_,   "em_el2_q/I");
  tree_->Branch("em_el2_iso",  &em_el2_iso_,   "em_el2_iso/D");
  tree_->Branch("em_zmass",    &em_zmass_,     "em_zmass/D");

/////
  tree_->Branch("isMM",  &isMM_, "isMM/I" );
  tree_->Branch("isEE",  &isEE_, "isEE/I" );
  tree_->Branch("isEM",  &isEM_, "isEM/I" );

  tree_->Branch("Category",  &Category_, "Category/I" );
  tree_->Branch("NgenJet",  &NgenJet_, "NgenJet/I" );

}
void FlatTree::clear()
{
   jet_pt_->clear();
   jet_eta_->clear();
   jet_phi_->clear();
   jet_csv_->clear();

   weight_=1.0;

   Nmu_=-99; Nel_=-99;
   nBJetT_=-99; nBJetM_=-99; nBJetL_=-99; nJet_=-99;
   met_=-99.0; metphi_=-99.;
///

   mm_mu1_pt_=-99.; mm_mu1_eta_=-99.; mm_mu1_phi_=-99.; mm_mu1_iso_=-99.; mm_zmass_=-99.;
   mm_mu2_pt_=-99.; mm_mu2_eta_=-99.; mm_mu2_phi_=-99.; mm_mu2_iso_=-99.;
   ee_el1_pt_=-99.; ee_el1_eta_=-99.; ee_el1_phi_=-99.; ee_el1_iso_=-99.; ee_zmass_=-99.;
   ee_el2_pt_=-99.; ee_el2_eta_=-99.; ee_el2_phi_=-99.; ee_el2_iso_=-99.;
   em_mu1_pt_=-99.; em_mu1_eta_=-99.; em_mu1_phi_=-99.; em_mu1_iso_=-99.; em_zmass_=-99.;
   em_el2_pt_=-99.; em_el2_eta_=-99.; em_el2_phi_=-99.; em_el2_iso_=-99.;

    mm_mu1_q_=-99;  mm_mu2_q_=-99;
    ee_el1_q_=-99;  ee_el2_q_=-99;
    em_mu1_q_=-99;  em_el2_q_=-99;

///
  isMM_=-99; isEE_=-99; isEM_=-99;
  Category_=-99;
  NgenJet_=-99;
}
FlatTree::~FlatTree()
{
}
#endif
