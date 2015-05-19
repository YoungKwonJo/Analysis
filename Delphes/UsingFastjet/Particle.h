#ifndef Particle_h
#define Particle_h

//#include <vector>
#include <TLorentzVector.h>
//#include <iostream>

class Particle { //: TLorentzVector{
  public:
   explicit Particle(bool isNull_){ isNull__=isNull_;}
   Particle(Double_t px_, Double_t py_, Double_t pz_, Double_t e_ )
   {
      vec_= TLorentzVector(px_,py_,pz_,e_); isNull__=false;
   }
   ~Particle(){}


   double Pt() { return vec_.Pt(); };
   double Eta() { return vec_.Eta(); };
   double Phi() { return vec_.Phi(); };

   double Px() { return vec_.Px(); };
   double Py() { return vec_.Py(); };
   double Pz() { return vec_.Pz(); };

   void setPdgId(int pdgid_)  { pdgid__=pdgid_;    }
   void setCharge(int charge_){ charge__=charge_;  }
   void setJetArea(double jetArea_) { jetArea__=jetArea_; }

   int pdgId(){ return pdgid__; }
   int charge(){ return charge__; }
   double jetArea() { return jetArea__; }

   bool isNull(){ return isNull__;}
   bool isNotnull(){ return !isNull__;}

  private:
   TLorentzVector vec_;
   int charge__, pdgid__;
   double jetArea__; 
   bool isNull__;
};

#endif

