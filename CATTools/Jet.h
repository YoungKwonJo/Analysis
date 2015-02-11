#ifndef Jet_h
#define Jet_h

#include <vector>
#include <TLorentzVector.h>
#include <iostream>

class Jet{
  public:
   explicit Jet(TLorentzVector vec, double CSV, int flavor, double bHDR )
   {
      vec_=vec; CSV_=CSV; flavor_=flavor; bHDR_=bHDR;
   }
   ~Jet(){}

   double Pt() { return vec_.Pt(); };
   double Eta() { return vec_.Eta(); };
   double Phi() { return vec_.Phi(); };

   double Px() { return vec_.Px(); };
   double Py() { return vec_.Py(); };
   double Pz() { return vec_.Pz(); };

   double CSV() { return CSV_;};
   int flavor() { return flavor_;}  
   double DRwithBHadron() { return bHDR_; }

   TLorentzVector vec_; 
   double CSV_;
   int flavor_;
   double bHDR_;

   std::vector<int> BHid;
   std::vector<int> BQid;

};

#endif
