#ifndef Lepton_h
#define Lepton_h

#include <vector>
#include "CSVWeight.h"
#include <TLorentzVector.h>
#include <iostream>

class Lepton{
  public:
   explicit Lepton(TLorentzVector vec, double Iso, int Q )
   {
      vec_=vec; Iso_=Iso; Q_=Q;
   }
   double Pt() { return vec_.Pt(); };
   double Eta() { return vec_.Eta(); };
   double Phi() { return vec_.Phi(); };

   TLorentzVector vec_; 
   double Iso_;
   int Q_;
};

#endif

