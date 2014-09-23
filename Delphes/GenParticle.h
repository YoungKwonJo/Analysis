#ifndef GenParticle_h
#define GenParticle_h

#include <vector>
//#include "CSVWeight.h"
#include <TLorentzVector.h>
#include <iostream>

class GenParticle{
  public:
   explicit GenParticle(TLorentzVector vec, int id, int Q, int mid, int idx )
   {
      vec_=vec; id_=id; Q_=Q; mid_=mid; idx_=idx;
   }
   ~GenParticle(){}

   double Pt() { return vec_.Pt(); };
   double y()  { return vec_.Rapidity(); };
   double Eta() { return vec_.Eta(); };
   double Phi() { return vec_.Phi(); };

   double Px() { return vec_.Px(); };
   double Py() { return vec_.Py(); };
   double Pz() { return vec_.Pz(); };

   int PdgId() { return id_; }
   int Charge() { return Q_; }
   int MotherPdgId() { return mid_; }

   TLorentzVector vec_; 
   int id_;
   int Q_;
   int mid_;
   int idx_;
};

#endif

