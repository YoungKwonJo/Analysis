#ifndef Jet_h
#define Jet_h

#include <vector>
#include <TLorentzVector.h>
#include <iostream>

class Jet{
  public:
   explicit Jet(TLorentzVector vec, double CSV, int flavor )
   {
      vec_=vec; CSV_=CSV; flavor_=flavor;
   }
   double Pt() { return vec_.Pt(); };
   double Eta() { return vec_.Eta(); };
   double Phi() { return vec_.Phi(); };

   double Px() { return vec_.Px(); };
   double Py() { return vec_.Py(); };
   double Pz() { return vec_.Pz(); };

   TLorentzVector vec_; 
   double CSV_;
   int flavor_;
};

#endif

