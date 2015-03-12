#ifndef CutSet_h
#define CutSet_h

#include <vector>
#include <string>
#include <TLorentzVector.h>
#include <TChain.h>
#include <TCut.h>
#include <TH1F.h>
#include <iostream>
using namespace std;

class CutSet{
  public:
   explicit CutSet(char* step, TCut cut, TCut cut_em, TCut weight)
   {
      step_=step; 
      cut_=cut; cut_em_=cut_em;
      weight_=weight;
   }
   void print()
   {
     cout << "cut-step:"<<step_ <<", TCut:"<< cut_.GetTitle() 
          <<"\", TCut_em:"<<cut_em_.GetTitle()<< ", weight:" <<weight_.GetTitle() << endl;
   }   
   ~CutSet(){}
   string step_;
   TCut cut_, cut_em_, weight_;
};

#endif
