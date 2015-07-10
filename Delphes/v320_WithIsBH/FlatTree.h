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

  doublesP DR_gjet_BH_;
  doublesP DPT_gjet_BH_;
  doublesP Pt_gjet_;
  doublesP Eta_gjet_;
  intsP BH_gjet_;

  int Ngenjet_, Ngenjet_BH_;
  int Ngenjet20_, Ngenjet20_BH_;
 
  int leptonic_;
  int electronic_;
  int muonic_;
  int taunic_;
  int topN_;
  int wN_;
 
//  TH1F* hSumWeight_;

 
};
//#endif

//#ifdef FlatTree_cxx
FlatTree::FlatTree()
{
   DR_gjet_BH_  = new doubles;
   DPT_gjet_BH_ = new doubles;
   Pt_gjet_ = new doubles;
   Eta_gjet_ = new doubles;
   BH_gjet_ = new ints;

}
void FlatTree::book(TTree* tree)
{
  tree_ = tree;
//  hSumWeight_ = new TH1F("hSumWeight","hSumWeight",1,0,2);

  tree_->Branch("run"  , &run_  , "run/I");
  tree_->Branch("lumi" , &lumi_ , "lumi/I");
  tree_->Branch("event", &event_, "event/I");

  tree_->Branch("weight", &weight_, "weight/D");

  tree_->Branch("DR_gjet_BH"  , DR_gjet_BH_  );
  tree_->Branch("DPT_gjet_BH"  , DPT_gjet_BH_  );
  tree_->Branch("Pt_gjet"  , Pt_gjet_  );
  tree_->Branch("Eta_gjet" , Eta_gjet_ );
  tree_->Branch("BH_gjet"  , BH_gjet_  );

  tree_->Branch("Ngenjet", &Ngenjet_, "Ngenjet/I");
  tree_->Branch("Ngenjet_BH", &Ngenjet_BH_, "Ngenjet_BH/I");
  tree_->Branch("Ngenjet20", &Ngenjet20_, "Ngenjet20/I");
  tree_->Branch("Ngenjet20_BH", &Ngenjet20_BH_, "Ngenjet20_BH/I");

  tree_->Branch("leptonic",  &leptonic_, "leptonic/I" );
  tree_->Branch("electronic",  &electronic_, "electronic/I" );
  tree_->Branch("muonic",  &muonic_, "muonic/I" );
  tree_->Branch("taunic",  &taunic_, "taunic/I" );
  tree_->Branch("topN",  &topN_, "topN/I" );
  tree_->Branch("wN",  &wN_, "wN/I" );

}
void FlatTree::clear()
{
   DR_gjet_BH_->clear();
   DPT_gjet_BH_->clear();
   Pt_gjet_->clear();
   Eta_gjet_->clear();
   BH_gjet_->clear();

   weight_=1.0;

   Ngenjet_=-999;
   Ngenjet_BH_=-999;

   Ngenjet20_=-999;
   Ngenjet20_BH_=-999;

   leptonic_  =-99;
   electronic_  =-99;
   muonic_  =-99;
   taunic_  =-99;
   wN_  =-99;
   topN_  =-99;

}
FlatTree::~FlatTree()
{
}
#endif
