#ifndef Jet_h
#define Jet_h

#include <vector>
#include <TLorentzVector.h>
#include <iostream>

class Jet{
  public:
   explicit Jet(double pt, double eta, double phi, double mass, double CSV)//, double minDRL)//, int flavor, double bHDR )
   {
      vec_.SetPtEtaPhiM(pt,eta,phi,mass); CSV_=CSV;// flavor_=flavor; bHDR_=bHDR;
      //minDRL_ =minDRL;
   }
   ~Jet(){}
   //void setDRl(double minDRL) {  minDRL_ =minDRL; }
   double Pt() { return vec_.Pt(); };
   double Eta() { return vec_.Eta(); };
   double Phi() { return vec_.Phi(); };

   double Px() { return vec_.Px(); };
   double Py() { return vec_.Py(); };
   double Pz() { return vec_.Pz(); };

   double CSV() { return CSV_;};
   //double DRl() { return minDRL_;};
//   int flavor() { return flavor_;}  
//   double DRwithBHadron() { return bHDR_; }

   TLorentzVector vec_; 
   double CSV_;//, minDRL_;
//   int flavor_;
//   double bHDR_;

//   std::vector<int> BHid;
//   std::vector<int> BQid;

};

#endif
