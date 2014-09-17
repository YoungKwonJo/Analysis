#define Delphes_cxx
#include "Delphes.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TLorentzVector.h>
#include <TH1F.h>
#include <TH2F.h>
#include <iostream>
#include <TH1D.h>
#include <TH2D.h>

#include "mJet.h"
#include "Lepton.h"
//#include "TtFullLepKinSolver.C"
#include "FlatTree.h"
/*
  typedef std::vector<int> ints;
  typedef std::vector<unsigned int> uints;
  typedef std::vector<double> doubles;
  typedef ints* intsP;
  typedef uints* uintsP;
  typedef doubles* doublesP;
*/
typedef std::vector<Lepton> Leptons;
typedef Leptons* LeptonsP;

typedef std::vector<GenParticle> GenParticles;
typedef GenParticles* GenParticlesP;
bool compByPtLep(Lepton a, Lepton b)
{
   return a.Pt() > b.Pt();
};

typedef std::vector<mJet> mJets;
typedef mJets* mJetsP;
bool compByPtJet(mJet a, mJet b)
{
   return a.Pt() > b.Pt();
};
bool compByPtGenParticle(GenParticle a, GenParticle b)
{
   return a.Pt() > b.Pt();
};


void Delphes::Loop(bool isttjj)
{
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   TTree *tree_ = new TTree(Form("ntuple"),"");
   FlatTree* fevent_ = new FlatTree(true);
   fevent_->book(tree_);

   LeptonsP muons_;        muons_     = new Leptons;
   LeptonsP electrons_;    electrons_ = new Leptons;
   mJetsP   jets_;         jets_      = new mJets;

   mJetsP gjets_;            gjets_ = new mJets;
   //GenParticlesP gBHad_;      gBHad_ = new GenParticles;

   GenParticlesP gDBHad_;     gDBHad_   = new GenParticles;
   GenParticlesP gDBQ_;       gDBQ_     = new GenParticles;
   GenParticlesP gDBTQ_;      gDBTQ_    = new GenParticles;
   GenParticlesP gDBHiggs_;   gDBHiggs_ = new GenParticles;

   GenParticlesP gDCHad_;     gDCHad_   = new GenParticles;
   GenParticlesP gDCQ_;       gDCQ_     = new GenParticles;
   GenParticlesP gDCTQ_;      gDCTQ_    = new GenParticles;
   GenParticlesP gDCHiggs_;   gDCHiggs_ = new GenParticles;

//   std::vector< std::vector<int> > BQjet;

   GenParticlesP gBQlast_;     gBQlast_   = new GenParticles;
   GenParticlesP gQQfirst_;     gQQfirst_   = new GenParticles;
   GenParticlesP gBQfirst_;     gBQfirst_   = new GenParticles;
   GenParticlesP gLep_;     gLep_   = new GenParticles;
   double dr_=0.5;

   int Testing =0;
   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
      Testing++;
      //if(Testing>20) break;
      //if(Testing>6000) break;
      if(Testing%10000==0) cout << "event: " << Testing << endl;

      fevent_->clear();
      //gBHad_->clear();
      gDBHad_->clear(); gDBQ_->clear(); gDBTQ_->clear(); gDBHiggs_->clear(); 
      gDCHad_->clear(); gDCQ_->clear(); gDCTQ_->clear(); gDCHiggs_->clear();
      //BQjet.clear();
      gBQlast_->clear();
      gBQfirst_->clear();
      gQQfirst_->clear();
      gLep_->clear();
////////
//      fevent_->nVertex_ =
      fevent_->MET_     = MissingET_MET[0];
      fevent_->METPHI_  = MissingET_Phi[0];
      fevent_->event_   = Event_; 

/////////////////////
//check letonic decay
      bool findtop=false, findtopb=false;
      int topN=0, wN=0, leptonic = 0;
      int muonic=0, electronic=0, taunic=0;
      for(int i=0;i<Particle_size;i++ )
      {
         /*
         if(Particle_Status[i]<30 && Particle_Status[i]>10)
//         if( abs(Particle_PID[i]) >10 && abs(Particle_PID[i])<20)
              cout << "event:"<< ientry <<", idx:"<< i << ", pdgid:" << Particle_PID[i] << ", midx:"<< Particle_M1[i]<< ", status:"<< Particle_Status[i] << endl;
         if(Particle_Status[i]>70 && Particle_Status[i]<90)
              cout << "event:"<< ientry <<", idx:"<< i << ", pdgid:" << Particle_PID[i] << ", midx:"<< Particle_M1[i]<< ", status:"<< Particle_Status[i] << endl;
         */ /*
         if( abs(Particle_PID[i])==6 && Particle_PID[Particle_D1[i]] != Particle_PID[i])
           cout << "event:"<< ientry <<", idx:"<< i << ", top, did1:"<< Particle_PID[Particle_D1[i]]<< ", did2:"<< Particle_PID[Particle_D2[i]] << endl;
         if( abs(Particle_PID[i])==24 && Particle_PID[Particle_D1[i]] != Particle_PID[i])
           cout << "event:"<< ientry <<", idx:"<< i << ", w, did1:"<< Particle_PID[Particle_D1[i]]<< ", did2:"<< Particle_PID[Particle_D2[i]] << endl;
          */

         // ttbar dileptonic check 
         if( (Particle_PID[i]==6 && findtop==false ) || (Particle_PID[i]==-6 && findtopb==false))
         {  
            int id1 = Particle_D1[getLastIdX(i,0)];
            int id2 = Particle_D2[getLastIdX(i,0)];
  
            int pdgidD1 = Particle_PID[id1];
            int pdgidD2 = Particle_PID[id2];
            int id11 = Particle_D1[getLastIdX(id1,0)];
            int id12 = Particle_D2[getLastIdX(id1,0)];
            int id21 = Particle_D1[getLastIdX(id2,0)];
            int id22 = Particle_D2[getLastIdX(id2,0)];
            int pdgidD11 = Particle_PID[id11];
            int pdgidD12 = Particle_PID[id12];
            int pdgidD21 = Particle_PID[id21];
            int pdgidD22 = Particle_PID[id22];
            topN++;
            if( (abs(pdgidD1)==24 && abs(pdgidD2)==5) || (abs(pdgidD1)==5 && abs(pdgidD2)==24) )
            {  wN++; 
               if(abs(pdgidD1)==24)
               {
                 if ( abs(pdgidD11) >10 && abs(pdgidD11)<17 && abs(pdgidD12) >10 && abs(pdgidD12)<17 )
                 {
                    if(abs(pdgidD11) >10 && abs(pdgidD11)<13) electronic++;
                    if(abs(pdgidD11) >12 && abs(pdgidD11)<15) muonic++;
                    if(abs(pdgidD11) >14 && abs(pdgidD11)<17) { 
                       taunic++;
                       int id111 = Particle_D1[getLastIdX(id11,0)];
                       int id112 = Particle_D2[getLastIdX(id11,0)];
                       int id121 = Particle_D1[getLastIdX(id12,0)];
                       int id122 = Particle_D2[getLastIdX(id12,0)];

                       int pdgidD111 = Particle_PID[id111];
                       int pdgidD112 = Particle_PID[id112];
                       int pdgidD121 = Particle_PID[id121];
                       int pdgidD122 = Particle_PID[id122];
                       if(abs(pdgidD111) >10 && abs(pdgidD111)<13) electronic++;
                       if(abs(pdgidD121) >10 && abs(pdgidD121)<13) electronic++;
                       if(abs(pdgidD111) >12 && abs(pdgidD111)<15) muonic++;
                       if(abs(pdgidD121) >12 && abs(pdgidD121)<15) muonic++;
                    }
                    leptonic++;
                 }
               } 
               if(abs(pdgidD2)==24)
               {
                 if ( abs(pdgidD21) >10 && abs(pdgidD21)<17 && abs(pdgidD22) >10 && abs(pdgidD22)<17 )
                 {
                    if(abs(pdgidD11) >10 && abs(pdgidD11)<13) electronic++;
                    if(abs(pdgidD11) >12 && abs(pdgidD11)<15) muonic++;
                    if(abs(pdgidD11) >14 && abs(pdgidD11)<17) {
                       taunic++;
                       int id111 = Particle_D1[getLastIdX(id11,0)];
                       int id112 = Particle_D2[getLastIdX(id11,0)];
                       int id121 = Particle_D1[getLastIdX(id12,0)];
                       int id122 = Particle_D2[getLastIdX(id12,0)];

                       int pdgidD111 = Particle_PID[id111];
                       int pdgidD112 = Particle_PID[id112];
                       int pdgidD121 = Particle_PID[id121];
                       int pdgidD122 = Particle_PID[id122];
                       if(abs(pdgidD111) >10 && abs(pdgidD111)<13) electronic++;
                       if(abs(pdgidD121) >10 && abs(pdgidD121)<13) electronic++;
                       if(abs(pdgidD111) >12 && abs(pdgidD111)<15) muonic++;
                       if(abs(pdgidD121) >12 && abs(pdgidD121)<15) muonic++;
                    }
                    leptonic++;
                 }
               }
            }
            if(Particle_PID[i]==6) findtop=true;
            if(Particle_PID[i]==-6) findtopb=true;
         }    

      }
      fevent_->topN_ = topN;
      fevent_->wN_ = wN;
      fevent_->leptonic_ = leptonic;
      fevent_->electronic_ = electronic;
      fevent_->muonic_ = muonic;
      fevent_->taunic_ = taunic;

      //tree_->Fill();     continue;
/////////////////
//check Ancestors(b/c hadron, b/c quark, top, higgs) in particle with status == 1
      if(leptonic>1)for(int i=0;i<Particle_size;i++ )
      {

         if(Particle_Status[i]<30 && Particle_Status[i]>10)
         {
              ;//cout << "event:"<< ientry <<", idx:"<< i << ", pdgid:" << Particle_PID[i] << ", midx:"<< Particle_M1[i]<< ", status:"<< Particle_Status[i] << endl;
         }
         if(Particle_Status[i]>20 && Particle_Status[i]<60 && abs(Particle_PID[i])<5 && 
               abs(Particle_PID[Particle_M1[i]])!=abs(Particle_PID[i]) && abs(Particle_PID[Particle_M1[i]])!=5 && abs(Particle_PID[Particle_M1[i]])<30)
         {
             GenParticle gp_ =getGenParticle(i);
             gQQfirst_->push_back(gp_);
             /*cout <<"first QQ: event:" << (Testing-1) <<", pdgid:"<<Particle_PID[i] << ", idx: "<< i << ", pT:"<<Particle_PT[i] << ", eta:"<<Particle_Eta[i]
                  <<", M1("<<Particle_M1[i]<<"):"<<Particle_PID[Particle_M1[i]]
                  <<", m1-status:"<< Particle_Status[Particle_M1[i]] //<< endl;
                  <<", D1("<<Particle_D1[i]<<"):"<<Particle_PID[Particle_D1[i]] << endl;*/
         }
         //first bq
         if(abs(Particle_PID[i])==5 && abs(Particle_PID[Particle_M1[i]])!=5 && Particle_Status[i]>20 && Particle_Status[i]<60)
         {
             GenParticle gp_ =getGenParticle(i);
             gBQfirst_->push_back(gp_);
             /*cout <<"first bQ: event:" << (Testing-1) << ", idx: "<< i << ", pT:"<<Particle_PT[i] << ", eta:"<<Particle_Eta[i]
                  <<", M1("<<Particle_M1[i]<<"):"<<Particle_PID[Particle_M1[i]]
                  <<", m1-status:"<< Particle_Status[Particle_M1[i]] //<< endl;
                  <<", D1("<<Particle_D1[i]<<"):"<<Particle_PID[Particle_D1[i]] << endl;*/
         }
         //last bq
         if(abs(Particle_PID[i])==5 && abs(Particle_PID[Particle_D1[i]])!=5)
         {
             GenParticle gp_ =getGenParticle(i);
            // if(Particle_Status[Particle_M1[get1stIdX(i,0)]]<40) gBQlast_->push_back(gp_);
             /*cout <<"last bQ: event:" << (Testing-1) << ", idx: "<< i << ", pT:"<<Particle_PT[i] << ", eta:"<<Particle_Eta[i] 
                  <<", M1("<<Particle_M1[get1stIdX(i,0)]<<"):"<<Particle_PID[Particle_M1[get1stIdX(i,0)]] 
                  <<", m1-status:"<< Particle_Status[Particle_M1[get1stIdX(i,0)]] //<< endl;
                  <<", D1("<<Particle_D1[i]<<"):"<<Particle_PID[Particle_D1[i]] << endl;*/
         }
         if(Particle_Status[i]==1)
         {
             GenParticle gp_ =getGenParticle(i);
             if(abs(Particle_PID[i])==11 || abs(Particle_PID[i])==13) 
             {
                gLep_->push_back(gp_);
             }
             bool isSameB=false;
             if(isFromBHad(i,0)==2)
             {
                gDBHad_->push_back(gp_);
                int bid = isFromBQ(i,0);
                if(bid>-1 && Particle_Status[Particle_M1[get1stIdX(bid,0)]]<40) 
                {
                  gp_.mid_=bid; gDBQ_->push_back(gp_);
                  int tid = isFromTop(i,0);
                  int hid = isFromHiggs(i,0); 
                  if(tid>-1) { gp_.mid_=tid; gDBTQ_->push_back(gp_);    }
                  if(hid>-1) { gp_.mid_=hid; gDBHiggs_->push_back(gp_); }
                }
             }
             else if(isFromCHad(i,0)>-1)
             {
                gDCHad_->push_back(gp_);
                int cid = isFromCQ(i,0);
                if(cid>-1 && Particle_Status[Particle_M1[get1stIdX(cid,0)]]<40)
                {
                  gp_.mid_=cid; gDCQ_->push_back(gp_);
                  int tid = isFromTop(i,0);
                  int hid = isFromHiggs(i,0);                  
                  if(tid>-1){ gp_.mid_=tid; gDCTQ_->push_back(gp_);    }
                  if(hid>-1){ gp_.mid_=hid; gDCHiggs_->push_back(gp_); }
                }
             }
         }
      }
//////////
      std::sort(gBQlast_->begin(),gBQlast_->end(),compByPtGenParticle);

      fevent_->NgBQlast_  = gBQlast_->size();
      if(gBQlast_->size()>1)
      {  
         double bQ_DR[4]={999,999,999,99};
         for(int i=0;i<gBQlast_->size();i++)
         {
           fevent_->gBQlast_pt_ ->push_back(gBQlast_->at(i).Pt());
           fevent_->gBQlast_eta_->push_back(gBQlast_->at(i).Eta());

           if(i<gBQlast_->size()-1)
           for(int j=i+1;j<gBQlast_->size();j++)
           {
                 double DR1_=fabs(gBQlast_->at(i).vec_.DeltaR(gBQlast_->at(j).vec_));
                  if(bQ_DR[i]>DR1_) bQ_DR[i]=DR1_;            
           }
         }
         fevent_->gBQlast_DR1_= bQ_DR[0];
         fevent_->gBQlast_DR2_= bQ_DR[1];
         fevent_->gBQlast_DR3_= bQ_DR[2];
         fevent_->gBQlast_DR4_= bQ_DR[3];
      }

//////////
// choose genjet
      gjets_->clear();
      int gnjet =0, gnjet50=0;
      int gnjetBH=0, gnjetBQ=0, gnjetBTQ=0, gnjetBHiggs=0;
      int gnjetCH=0, gnjetCQ=0, gnjetCTQ=0, gnjetCHiggs=0;
      for(int i=0;i<GenJet_size;i++ )
      {
         bool overlap_=false;  // jet cleaning..
         if(GenJet_PT[i]>30 && fabs(GenJet_Eta[i])<2.5)
         {
            double x_ = GenJet_PT[i]*TMath::Cos(GenJet_Phi[i]);
            double y_ = GenJet_PT[i]*TMath::Sin(GenJet_Phi[i]);
            double z_ = GenJet_PT[i]*sinh(GenJet_Eta[i]);
            double e_ = TMath::Sqrt(x_*x_+y_*y_+z_*z_+GenJet_Mass[i]*GenJet_Mass[i]);
            TLorentzVector Ajet_(x_,y_,z_,e_);
//            if(GenJet_Particles[i].GetEntries()>0) cout << "genjet particle:"<<" idx:"<< i << ", entries:" <<  GenJet_Particles[i].GetEntries() << endl;
            for(int j=0;j<gLep_->size();j++ )
            if( gLep_->at(j).Pt()>20 && fabs(gLep_->at(j).Eta())<2.4 )
            if( fabs( Ajet_.DeltaR(gLep_->at(j).vec_) )< dr_ )         overlap_=true;
            if(overlap_ ) continue;
            
            mJet gjet_(TLorentzVector( x_,y_,z_,e_),GenJet_BTag[i],0, 999);
            double DRBH_ = 999, DRBQ_=999, DRBTQ_=999, DRBHiggs_=999;
            double DRCH_ = 999, DRCQ_=999, DRCTQ_=999, DRCHiggs_=999;
            for(int j=0;j<gDBHad_->size();j++)
            {  
                double DR1_=fabs(Ajet_.DeltaR(gDBHad_->at(j).vec_)); 
                if(DRBH_>DR1_) DRBH_=DR1_;           
                if(DR1_<dr_)  { gjet_.BHid.push_back( gDBHad_->at(j).mid_ ); } 
            }
            if(DRBH_<dr_) for(int j=0;j<gDBQ_->size();j++)                                                                                                                           
            { 
                double DR1_=fabs(Ajet_.DeltaR(gDBQ_->at(j).vec_));   
                if(DRBQ_>DR1_) DRBQ_=DR1_;           
                if(DR1_<dr_)
                {
                   gjet_.BQid.push_back( gDBQ_->at(j).mid_ );    
                } 
            }
//            for(int j=0;j<gDBTQ_->size();j++)                                                                                                           
//            {  double DR1_=fabs(Ajet_.DeltaR(gDBTQ_->at(j).vec_));  if(DRBTQ_>DR1_) DRBTQ_=DR1_;         if(DRBTQ_<dr_) break;     }
//            for(int j=0;j<gDBHiggs_->size();j++)
//            {  double DR1_=fabs(Ajet_.DeltaR(gDBHiggs_->at(j).vec_)); if(DRBHiggs_>DR1_) DRBHiggs_=DR1_; if(DRBHiggs_<dr_) break;  }
/*            if(DRBH_>dr_)
            {
               for(int j=0;j<gDCHad_->size();j++)
               {  double DR1_=fabs(Ajet_.DeltaR(gDCHad_->at(j).vec_)); if(DRCH_>DR1_) DRCH_=DR1_;   if(DRCH_<dr_) break;  }
               for(int j=0;j<gDCQ_->size();j++)
               {  double DR1_=fabs(Ajet_.DeltaR(gDCQ_->at(j).vec_));   if(DRCQ_>DR1_) DRCQ_=DR1_;   if(DRCQ_<dr_) break;  }
               for(int j=0;j<gDCTQ_->size();j++)
               {  double DR1_=fabs(Ajet_.DeltaR(gDCTQ_->at(j).vec_));  if(DRCTQ_>DR1_) DRCTQ_=DR1_; if(DRCTQ_<dr_) break;  }
               for(int j=0;j<gDCHiggs_->size();j++)
               {  double DR1_=fabs(Ajet_.DeltaR(gDCHiggs_->at(j).vec_)); if(DRCHiggs_>DR1_) DRCHiggs_=DR1_; if(DRCHiggs_<dr_) break;  }
            }*/
            gjet_.bHDR_ = DRBQ_;
            gjets_->push_back(gjet_);

            gnjet++;
            if(DRBH_<dr_)     gnjetBH++;
            if(DRBQ_<dr_)     gnjetBQ++;
            if(DRBTQ_<dr_)    gnjetBTQ++;
            if(DRBHiggs_<dr_) gnjetBHiggs++;

/*
            if(DRCH_<dr_)     gnjetCH++;
            if(DRCQ_<dr_)     gnjetCQ++;
            if(DRCTQ_<dr_)    gnjetCTQ++;
            if(DRCHiggs_<dr_) gnjetCHiggs++;
*/
            if(GenJet_PT[i]>50) gnjet50++;
         }
      }
      std::sort(gjets_->begin(), gjets_->end(), compByPtJet);

//////////
//////////
//check double-count about matching
      ////int j=0;

      int gnJetOverlap =0;
      int gnJetBNTQ=0; 
      int gnJetBNTQOverlap=0;
      gnjetBH=0;
      gnjetBQ=0;
      gnjetBTQ=0;
      gnjetBHiggs=0;
      int gnjetBTHiggs=0;

      std::vector<int> bhids;
      std::vector<int> bqids;
      std::vector<int> bbb;
      std::vector<int> ccc;
      for( mJets::const_iterator vec1 = gjets_->begin() ; vec1 != gjets_->end(); vec1++)
      {
         bbb.clear();
         ccc.clear();
         mJet vec11 = *vec1;
//         cout << endl << "gjet "  << ": Pt:"<< vec11.Pt() << ": ";
         //for checking bH
         std::vector<int> vec2 = vec1->BHid;

         ///////////
         //check double counts in BH
         bool isDoubleCount =false; int bhid_=0;
         bool isBH=false;
         bool isCheckOverlapBH=false;
         for( std::vector< int >::const_iterator vv = vec2.begin() ; vv != vec2.end() ; vv++) 
         {
            if((*vv)>0) 
            {
              isBH=true;
              //check overlap in BH
              bool isCheckOverlapBH_F_=true;
              for(int i=0;i<bbb.size();i++)
              { if(bbb.at(i)==(*vv)){ isCheckOverlapBH=true; isCheckOverlapBH_F_=false;} }    
              if(isCheckOverlapBH_F_) bbb.push_back( (*vv) ); 
            }
         }
         if(bhids.size()>0)
         {
            for(int j=0;j<bbb.size();j++)
            { 
               bool isDoubleCount_F_=true;
               for(int i=0;i<bhids.size();i++)
               {
                  if(bhids.at(i)==bbb.at(j)){ isDoubleCount=true; isDoubleCount_F_=false; }
               }
               if(isDoubleCount_F_) bhids.push_back( bbb.at(j) );
            }
         } 
         else for(int j=0;j<bbb.size();j++) bhids.push_back(bbb.at(j));
///////////

         //if(!isDoubleCount && isBH)
         if( isBH)
         {
            gnjetBH++;
            //for checking bQ 
            std::vector<int> vec3 = vec1->BQid;
            bool isBQ=false;
            bool isDoubleCountBQ=false;
            bool isCheckOverlapBQ=false;
            for( std::vector< int >::const_iterator vv = vec3.begin() ; vv != vec3.end() ; vv++)
            {
               if((*vv)>0)
               {
                 isBQ=true;
                 //check overlap in BQ
                 bool isCheckOverlapBQ_F_=true;
                 for(int i=0;i<ccc.size();i++)
                 { 
                    if(ccc.at(i)==(*vv)) { isCheckOverlapBQ=true; isCheckOverlapBQ_F_=false;}
                 }
                 if(isCheckOverlapBQ_F_)  ccc.push_back( (*vv) ); 
               }
            }
            if(bqids.size()>0)
            {
               for(int j=0;j<ccc.size();j++)
               {
                 bool isDoubleCountBQ_F_=true;
                 for(int i=0;i<bqids.size();i++)
                 {
                    if(bqids.at(i)==ccc.at(j)) { isDoubleCountBQ=true; isDoubleCountBQ_F_=false; }
                 }
                 if(isDoubleCountBQ_F_) bqids.push_back(ccc.at(j)); 
               }
            } 
            else for(int j=0;j<ccc.size();j++) bqids.push_back(ccc.at(j));

            /////////
            //if(!isDoubleCountBQ && isBQ )
            if(isBQ )
            {
               gnjetBQ++;
               if(isCheckOverlapBQ) gnJetOverlap++;
              
               // count about "t to b", "higgs to b"
               double DRBTQ_=999, DRBHiggs_=999;
               for(int j=0;j<gDBTQ_->size();j++)
               {  double DR1_=fabs(vec1->vec_.DeltaR(gDBTQ_->at(j).vec_));  if(DRBTQ_>DR1_) DRBTQ_=DR1_;         if(DRBTQ_<0.1) break;  }
               for(int j=0;j<gDBHiggs_->size();j++)
               {  double DR1_=fabs(vec1->vec_.DeltaR(gDBHiggs_->at(j).vec_)); if(DRBHiggs_>DR1_) DRBHiggs_=DR1_; if(DRBHiggs_<0.1) break;  }
               if(DRBTQ_<0.1)    gnjetBTQ++;
               else {
                 gnJetBNTQ++;
                 if(isCheckOverlapBQ) gnJetBNTQOverlap++;
               }
               if(DRBHiggs_<0.1) gnjetBHiggs++;
               if(DRBTQ_<0.1 || DRBHiggs_<0.1) gnjetBTHiggs++;
            }
         }
//////////////

      }

//////////
      fevent_->gnJet30_  = gnjet;
//      fevent_->gnbJet30_  = gnbjet;
      fevent_->gnJet30BH_  = gnjetBH;
      fevent_->gnJet30BQ_  = gnjetBQ;
      fevent_->gnJet30BTQ_ = gnjetBTQ;
      fevent_->gnJet30BHiggs_  = gnjetBHiggs;
      fevent_->gnJet30BTHiggs_  = gnjetBTHiggs;
/*      fevent_->gnJet30CH_  = gnjetCH;
      fevent_->gnJet30CQ_  = gnjetCQ;
      fevent_->gnJet30CTQ_ = gnjetCTQ;
      fevent_->gnJet30CHiggs_  = gnjetCHiggs;
*/
      fevent_->gnJetBNTQ_ = gnJetBNTQ;
      fevent_->gnJetBNTQOverlap_ = gnJetBNTQOverlap;
      fevent_->gnJetOverlap_   = gnJetOverlap;

      if(gnjet>0) { fevent_->gjet1_pt_ =gjets_->at(0).Pt();  fevent_->gjet1_eta_=gjets_->at(0).Eta();
                    fevent_->gjet1_bDR_ = gjets_->at(0).bHDR_;
      //              fevent_->gjet1_bTag_=gjets_->at(0).CSV_; fevent_->gjet1_flavor_=gjets_->at(0).flavor_; 
      }
      if(gnjet>1) { fevent_->gjet2_pt_ =gjets_->at(1).Pt();  fevent_->gjet2_eta_=gjets_->at(1).Eta();
                    fevent_->gjet2_bDR_ = gjets_->at(1).bHDR_;
      //              fevent_->gjet2_bTag_=gjets_->at(1).CSV_; fevent_->gjet2_flavor_=gjets_->at(1).flavor_; 
                    fevent_->gM_j12_ = (gjets_->at(0).vec_+gjets_->at(1).vec_).M();
      }
      if(gnjet>2) { fevent_->gjet3_pt_ =gjets_->at(2).Pt();  fevent_->gjet3_eta_=gjets_->at(2).Eta();
                    fevent_->gjet3_bDR_ = gjets_->at(2).bHDR_;
      //              fevent_->gjet3_bTag_=gjets_->at(2).CSV_; fevent_->gjet3_flavor_=gjets_->at(2).flavor_; 
      }
      if(gnjet>3) { fevent_->gjet4_pt_ =gjets_->at(3).Pt();  fevent_->gjet4_eta_=gjets_->at(3).Eta();
                    fevent_->gjet4_bDR_ = gjets_->at(3).bHDR_;
                    fevent_->gM_j34_ = (gjets_->at(2).vec_+gjets_->at(3).vec_).M();
      //              fevent_->gjet4_bTag_=gjets_->at(3).CSV_; fevent_->gjet4_flavor_=gjets_->at(3).flavor_; 
      }

/////////////
//choose lepton

      muons_->clear(); electrons_->clear(); jets_->clear();
      for(int i=0;i<Electron_size;i++ )
      {
         if( Electron_PT[i]>20. && fabs(Electron_Eta[i])<2.4)
         {
            double x_ = Electron_PT[i]*TMath::Cos(Electron_Eta[i]);
            double y_ = Electron_PT[i]*TMath::Sin(Electron_Eta[i]);
            double z_ = Electron_PT[i]*sinh(Electron_Eta[i]);
            double e_ = TMath::Sqrt(x_*x_+y_*y_+z_*z_+0.0005*0.0005);
            Lepton el_(TLorentzVector( x_,y_,z_,e_), 0, Electron_Charge[i]);
            electrons_->push_back(el_);
         }
      }
      std::sort(electrons_->begin(), electrons_->end(), compByPtLep);      
      for(int i=0;i<Muon_size;i++ )
      {
         if( Muon_PT[i]>20. && fabs(Muon_Eta[i])<2.4)
         {
            double x_ = Muon_PT[i]*TMath::Cos(Muon_Phi[i]);
            double y_ = Muon_PT[i]*TMath::Sin(Muon_Phi[i]);
            double z_ = Muon_PT[i]*sinh(Muon_Eta[i]);
            double e_ = TMath::Sqrt(x_*x_+y_*y_+z_*z_+0.01*0.01);
            Lepton mu_(TLorentzVector( x_,y_,z_,e_), 0, Muon_Charge[i]);
            muons_->push_back(mu_);
         }
      }

      std::sort(muons_->begin(), muons_->end(), compByPtLep);
/////////////////
// choose dilepton
      if(muonic>1 && muons_->size()>1)
      {
         fevent_->ZMass_    = (muons_->at(0).vec_+muons_->at(1).vec_).M();
         fevent_->Zdphi_    = fabs(muons_->at(0).vec_.DeltaPhi(muons_->at(1).vec_));
         fevent_->lep1_pt_  = muons_->at(0).Pt();
         fevent_->lep1_eta_ = muons_->at(0).Eta();
         fevent_->lep2_pt_  = muons_->at(1).Pt();
         fevent_->lep2_eta_ = muons_->at(1).Eta();
         fevent_->lep1_Q_   = muons_->at(0).Q_;
         fevent_->lep2_Q_   = muons_->at(1).Q_;
      }
      if(electronic>1 && electrons_->size()>1)
      {
         fevent_->ZMass_    = (electrons_->at(0).vec_+electrons_->at(1).vec_).M();
         fevent_->Zdphi_    = fabs(electrons_->at(0).vec_.DeltaPhi(electrons_->at(1).vec_));
         fevent_->lep1_pt_  = electrons_->at(0).Pt();
         fevent_->lep1_eta_ = electrons_->at(0).Eta();
         fevent_->lep2_pt_  = electrons_->at(1).Pt();
         fevent_->lep2_eta_ = electrons_->at(1).Eta();
         fevent_->lep1_Q_   = electrons_->at(0).Q_;
         fevent_->lep2_Q_   = electrons_->at(1).Q_;
      }
      if(muonic>0 && electronic>0 && muons_->size()>0 && electrons_->size()>0)
      {
         fevent_->ZMass_    = (muons_->at(0).vec_+electrons_->at(0).vec_).M();
         fevent_->Zdphi_    = fabs(muons_->at(0).vec_.DeltaPhi(electrons_->at(0).vec_));
         fevent_->lep1_pt_  = muons_->at(0).Pt();
         fevent_->lep1_eta_ = muons_->at(0).Eta();
         fevent_->lep2_pt_  = electrons_->at(0).Pt();
         fevent_->lep2_eta_ = electrons_->at(0).Eta();
         fevent_->lep1_Q_   = muons_->at(0).Q_;
         fevent_->lep2_Q_   = electrons_->at(0).Q_;
      }

///////////////////////////////
//choose jet
      int njet =0, njet50=0, nbjet=0;
      int njetBH=0, njetBQ=0, njetBTQ=0, njetBHiggs=0;
      int njetCH=0, njetCQ=0, njetCTQ=0, njetCHiggs=0;
//, njetbg=0;
      for(int i=0;i<Jet_size;i++ )
      {
         bool overlapMu=false, overlapEl=false;  // jet cleaning..
         if(Jet_PT[i]>30 && fabs(Jet_Eta[i])<2.5)
         {
            double x_ = Jet_PT[i]*TMath::Cos(Jet_Phi[i]);
            double y_ = Jet_PT[i]*TMath::Sin(Jet_Phi[i]);
            double z_ = Jet_PT[i]*sinh(Jet_Eta[i]);
            double e_ = TMath::Sqrt(x_*x_+y_*y_+z_*z_+Jet_Mass[i]*Jet_Mass[i]);
            TLorentzVector Ajet_(x_,y_,z_,e_);

            for(int j=0;j<electrons_->size();j++ )
            if( fabs( Ajet_.DeltaR(electrons_->at(j).vec_) )< dr_ ) overlapEl=true;
            for(int j=0;j<muons_->size();j++ )
            if( fabs( Ajet_.DeltaR(muons_->at(j).vec_) )< dr_ )     overlapMu=true;
            if(overlapEl || overlapMu) continue;

            /*double DR_ = 999;
            for(int j=0;j<gDBHad_->size();j++)
            {
                double DR1_=fabs(Ajet_.DeltaR(gDBHad_->at(j).vec_));
                if(DR_>DR1_) DR_=DR1_;
                if(DR_<dr_) break;
            }*/

            mJet jet_(TLorentzVector( x_,y_,z_,e_),Jet_BTag[i],0,999);
            double DRBH_ = 999, DRBQ_=999, DRBTQ_=999, DRBHiggs_=999;
            double DRCH_ = 999, DRCQ_=999, DRCTQ_=999, DRCHiggs_=999;
            for(int j=0;j<gDBHad_->size();j++)
            {  double DR1_=fabs(Ajet_.DeltaR(gDBHad_->at(j).vec_)); if(DRBH_>DR1_) DRBH_=DR1_;           if(DRBH_<dr_)      break;  }
            for(int j=0;j<gDBQ_->size();j++)                                                                                  
            {  double DR1_=fabs(Ajet_.DeltaR(gDBQ_->at(j).vec_));   if(DRBQ_>DR1_) DRBQ_=DR1_;           if(DRBQ_<dr_)      break;  }
            for(int j=0;j<gDBTQ_->size();j++)                                                                                  
            {  double DR1_=fabs(Ajet_.DeltaR(gDBTQ_->at(j).vec_));  if(DRBTQ_>DR1_) DRBTQ_=DR1_;         if(DRBTQ_<dr_)     break;  }
            for(int j=0;j<gDBHiggs_->size();j++)                                                                               
            {  double DR1_=fabs(Ajet_.DeltaR(gDBHiggs_->at(j).vec_)); if(DRBHiggs_>DR1_) DRBHiggs_=DR1_; if(DRBHiggs_<dr_)  break;  }

            if(DRBH_>dr_)
            {
               for(int j=0;j<gDCHad_->size();j++)
               {  double DR1_=fabs(Ajet_.DeltaR(gDCHad_->at(j).vec_)); if(DRCH_>DR1_) DRCH_=DR1_;   if(DRCH_<dr_) break;  }
               for(int j=0;j<gDCQ_->size();j++)
               {  double DR1_=fabs(Ajet_.DeltaR(gDCQ_->at(j).vec_));   if(DRCQ_>DR1_) DRCQ_=DR1_;   if(DRCQ_<dr_) break;  }
               for(int j=0;j<gDCTQ_->size();j++)
               {  double DR1_=fabs(Ajet_.DeltaR(gDCTQ_->at(j).vec_));  if(DRCTQ_>DR1_) DRCTQ_=DR1_; if(DRCTQ_<dr_) break;  }
               for(int j=0;j<gDCHiggs_->size();j++)
               {  double DR1_=fabs(Ajet_.DeltaR(gDCHiggs_->at(j).vec_)); if(DRCHiggs_>DR1_) DRCHiggs_=DR1_; if(DRCHiggs_<dr_) break;  }
            }
            jet_.bHDR_ = DRBQ_;
            jets_->push_back(jet_);

            njet++;
//            if(DR_<dr_) njetbg++;
            if(DRBH_<dr_)     njetBH++;
            if(DRBQ_<dr_)     njetBQ++;
            if(DRBTQ_<dr_)    njetBTQ++;
            if(DRBHiggs_<dr_) njetBHiggs++;

            if(DRCH_<dr_)     njetCH++;
            if(DRCQ_<dr_)     njetCQ++;
            if(DRCTQ_<dr_)    njetCTQ++;
            if(DRCHiggs_<dr_) njetCHiggs++;

            if(Jet_BTag[i]==1) nbjet++;
            if(Jet_PT[i]>50) njet50++;
         }
      }
      std::sort(jets_->begin(), jets_->end(), compByPtJet);
/////////
//check double-count about matching


/////////

      fevent_->nJet30_    = njet;
      fevent_->nbJet30T_  = nbjet; 
      fevent_->nJet30BH_  = njetBH;
      fevent_->nJet30BQ_  = njetBQ;
      fevent_->nJet30BTQ_ = njetBTQ;
      fevent_->nJet30BHiggs_  = njetBHiggs;
      fevent_->nJet30CH_  = njetCH;
      fevent_->nJet30CQ_  = njetCQ;
      fevent_->nJet30CTQ_ = njetCTQ;
      fevent_->nJet30CHiggs_  = njetCHiggs;
     
      if(njet>0) {  fevent_->jet1_pt_ =jets_->at(0).Pt();  fevent_->jet1_eta_=jets_->at(0).Eta();
                    fevent_->jet1_bDR_ = jets_->at(0).bHDR_;
                    fevent_->jet1_bTag_=jets_->at(0).CSV_; fevent_->jet1_flavor_=jets_->at(0).flavor_; }
      if(njet>1) {  fevent_->jet2_pt_ =jets_->at(1).Pt();  fevent_->jet2_eta_=jets_->at(1).Eta();
                    fevent_->jet2_bDR_ = jets_->at(1).bHDR_;
                    fevent_->jet2_bTag_=jets_->at(1).CSV_; fevent_->jet2_flavor_=jets_->at(1).flavor_; 
                    fevent_->M_j12_ = (jets_->at(0).vec_+jets_->at(1).vec_).M();
                 }
      if(njet>2) {  fevent_->jet3_pt_ =jets_->at(2).Pt();  fevent_->jet3_eta_=jets_->at(2).Eta();
                    fevent_->jet3_bDR_ = jets_->at(2).bHDR_;
                    fevent_->jet3_bTag_=jets_->at(2).CSV_; fevent_->jet3_flavor_=jets_->at(2).flavor_; }
      if(njet>3) {  fevent_->jet4_pt_ =jets_->at(3).Pt();  fevent_->jet4_eta_=jets_->at(3).Eta();
                    fevent_->jet4_bDR_ = jets_->at(3).bHDR_;
                    fevent_->jet4_bTag_=jets_->at(3).CSV_; fevent_->jet4_flavor_=jets_->at(3).flavor_; 
                    fevent_->M_j34_ = (jets_->at(2).vec_+jets_->at(3).vec_).M();
                 }


//      tree_->Fill(); continue; //for debug
//////////////////////////////
      if(gBQfirst_->size()>1)
      {
          int jgBQfirstJetIdx[20];
          for(int i=0;i<gBQfirst_->size();i++)
          {
            double DR_=999, idx=-1;
            for(int j=0;j<jets_->size();j++)
            {
                 double DR1_=fabs(gBQfirst_->at(i).vec_.DeltaR(jets_->at(j).vec_));
                 if(DR_>DR1_) { DR_=DR1_; idx=j;}
            }
            if(DR_<0.5) jgBQfirstJetIdx[i]=idx;
            else jgBQfirstJetIdx[i] = -1;
          }
          
          int    bjet_idx_fromT[2]={-1,-1};
          double bQ_DR[2]={999,999}; double bQ_M[2]={-1,-1};
          double bQ_DRjj[2]={999,999}; double bQ_Mjj[2]={-1,-1};
          double bQ_PTjj[4]={-1,-1,-1,-1}; double bQ_Etajj[4]={-999,-999,-999,-999};
          for(int i=0;i<gBQfirst_->size();i++)
          {
             if(i<gBQfirst_->size()-1)
             for(int j=i+1;j<gBQfirst_->size();j++)
             {
                if(abs(gBQfirst_->at(i).MotherPdgId())==6 && abs(gBQfirst_->at(j).MotherPdgId())==6 && bjet_idx_fromT[0]==-1 && bjet_idx_fromT[1]==-1 && fabs(gBQfirst_->at(i).vec_.DeltaR(gBQfirst_->at(j).vec_))>0.5)
                {
                   bQ_DR[0]=fabs(gBQfirst_->at(i).vec_.DeltaR(gBQfirst_->at(j).vec_));
                   bQ_M[0] = (gBQfirst_->at(i).vec_+gBQfirst_->at(j).vec_).M();
                   if(jgBQfirstJetIdx[i]>-1 && jgBQfirstJetIdx[j]>-1 && fabs(jets_->at(jgBQfirstJetIdx[i]).vec_.DeltaR(jets_->at(jgBQfirstJetIdx[j]).vec_))>0.5)
                   {
                     bQ_DRjj[0]=fabs(jets_->at(jgBQfirstJetIdx[i]).vec_.DeltaR(jets_->at(jgBQfirstJetIdx[j]).vec_));
                     bQ_Mjj[0] = (jets_->at(jgBQfirstJetIdx[i]).vec_+jets_->at(jgBQfirstJetIdx[j]).vec_).M();
                     double pt1 = jets_->at(jgBQfirstJetIdx[i]).Pt();
                     double pt2 = jets_->at(jgBQfirstJetIdx[j]).Pt();
                     double eta1 = jets_->at(jgBQfirstJetIdx[i]).Eta();
                     double eta2 = jets_->at(jgBQfirstJetIdx[j]).Eta();
                     bjet_idx_fromT[0]=jgBQfirstJetIdx[i]; bjet_idx_fromT[1]=jgBQfirstJetIdx[j];
                     if(pt1>pt2 ){ bQ_PTjj[0]=pt1; bQ_PTjj[1]=pt2; bQ_Etajj[0]=eta1; bQ_Etajj[1]=eta2;}
                     else        { bQ_PTjj[0]=pt2; bQ_PTjj[1]=pt1; bQ_Etajj[0]=eta2; bQ_Etajj[1]=eta1;}
                   }
                }
                if(abs(gBQfirst_->at(i).MotherPdgId())!=6 && abs(gBQfirst_->at(j).MotherPdgId())!=6 && bQ_Mjj[1]==-1 && !isttjj && fabs(gBQfirst_->at(i).vec_.DeltaR(gBQfirst_->at(j).vec_))>0.5)
                {
                   bQ_DR[1]=fabs(gBQfirst_->at(i).vec_.DeltaR(gBQfirst_->at(j).vec_));
                   bQ_M[1] = (gBQfirst_->at(i).vec_+gBQfirst_->at(j).vec_).M();
                   if(jgBQfirstJetIdx[i]>-1 && jgBQfirstJetIdx[j]>-1 && fabs(jets_->at(jgBQfirstJetIdx[i]).vec_.DeltaR(jets_->at(jgBQfirstJetIdx[j]).vec_))>0.5)
                   {
                     bQ_DRjj[1]=fabs(jets_->at(jgBQfirstJetIdx[i]).vec_.DeltaR(jets_->at(jgBQfirstJetIdx[j]).vec_));
                     bQ_Mjj[1] = (jets_->at(jgBQfirstJetIdx[i]).vec_+jets_->at(jgBQfirstJetIdx[j]).vec_).M();
                     double pt1 = jets_->at(jgBQfirstJetIdx[i]).Pt();
                     double pt2 = jets_->at(jgBQfirstJetIdx[j]).Pt();
                     double eta1 = jets_->at(jgBQfirstJetIdx[i]).Eta();
                     double eta2 = jets_->at(jgBQfirstJetIdx[j]).Eta();
                     if(pt1>pt2 ){ bQ_PTjj[2]=pt1; bQ_PTjj[3]=pt2; bQ_Etajj[2]=eta1; bQ_Etajj[3]=eta2;}
                     else        { bQ_PTjj[2]=pt2; bQ_PTjj[3]=pt1; bQ_Etajj[2]=eta2; bQ_Etajj[3]=eta1;}
                   }
                }
             }
          }
          if(isttjj && gQQfirst_->size()>1 && jets_->size()>3)// && bjet_idx_fromT[0]>-1 && bjet_idx_fromT[1]>-1)
          {
             //cout << "start gQQ...." << endl;
             std::sort(gQQfirst_->begin(),gQQfirst_->end(),compByPtGenParticle);
             int jgQQfirstJetIdx[200];
             for(int i=0;i<gQQfirst_->size();i++)
             {
               double DR_=999, idx=-1;
               for(int j=0;j<jets_->size();j++)
               if(bjet_idx_fromT[0]!=j && bjet_idx_fromT[1]!=j)
               {
                    double DR1_=fabs(gQQfirst_->at(i).vec_.DeltaR(jets_->at(j).vec_));
                    if(DR_>DR1_) { DR_=DR1_; idx=j;}
               }
               if(DR_<0.5) jgQQfirstJetIdx[i]=idx;
               else jgQQfirstJetIdx[i] = -1;
             }
             bool pass_=false;
             for(int i=0;i<gQQfirst_->size();i++)
             { //continue;
                if(i<gQQfirst_->size()-1)
                for(int j=i+1;j<gQQfirst_->size();j++)
                if(!pass_)
                if(jgQQfirstJetIdx[i]>-1 && jgQQfirstJetIdx[j]>-1 && fabs(gQQfirst_->at(i).vec_.DeltaR(gQQfirst_->at(j).vec_))>0.5 && fabs(jets_->at(jgQQfirstJetIdx[i]).vec_.DeltaR(jets_->at(jgQQfirstJetIdx[j]).vec_))>0.5)
                {
                    bQ_DR[1]=fabs(gQQfirst_->at(i).vec_.DeltaR(gQQfirst_->at(j).vec_));
                    bQ_M[1] = (gQQfirst_->at(i).vec_+gQQfirst_->at(j).vec_).M();
                    bQ_DRjj[1]=fabs(jets_->at(jgQQfirstJetIdx[i]).vec_.DeltaR(jets_->at(jgQQfirstJetIdx[j]).vec_));
                    bQ_Mjj[1] = (jets_->at(jgQQfirstJetIdx[i]).vec_+jets_->at(jgQQfirstJetIdx[j]).vec_).M();
                     double pt1 = jets_->at(jgQQfirstJetIdx[i]).Pt();
                     double pt2 = jets_->at(jgQQfirstJetIdx[j]).Pt();
                     double eta1 = jets_->at(jgQQfirstJetIdx[i]).Eta();
                     double eta2 = jets_->at(jgQQfirstJetIdx[j]).Eta();
                     if(pt1>pt2 ){ bQ_PTjj[2]=pt1; bQ_PTjj[3]=pt2; bQ_Etajj[2]=eta1; bQ_Etajj[3]=eta2;}
                     else        { bQ_PTjj[2]=pt2; bQ_PTjj[3]=pt1; bQ_Etajj[2]=eta2; bQ_Etajj[3]=eta1;}
                    pass_=true;
                }
             }
          }
          fevent_->jgBQ1st_DR1jjfromT_= bQ_DRjj[0];
          fevent_->jgBQ1st_DR2jjadd_= bQ_DRjj[1];
          fevent_->jgBQ1st_M1jjfromT_= bQ_Mjj[0];
          fevent_->jgBQ1st_M2jjadd_= bQ_Mjj[1];
          
          fevent_->jgBQ1st_PTj1jfromT_= bQ_PTjj[0];
          fevent_->jgBQ1st_PTj2jfromT_= bQ_PTjj[1];
          fevent_->jgBQ1st_PTj3jadd_  = bQ_PTjj[2];
          fevent_->jgBQ1st_PTj4jadd_  = bQ_PTjj[3];
          
          fevent_->jgBQ1st_Etaj1jfromT_= bQ_Etajj[0];
          fevent_->jgBQ1st_Etaj2jfromT_= bQ_Etajj[1];
          fevent_->jgBQ1st_Etaj3jadd_  = bQ_Etajj[2];
          fevent_->jgBQ1st_Etaj4jadd_  = bQ_Etajj[3];
      }




//////////////////////////////
//bBQfirst and genJet.
      if(gBQfirst_->size()>1)
      {
         int gBQfirstJetIdx[20];
         fevent_->NgBQ1st_  = gBQfirst_->size();
         for(int i=0;i<gBQfirst_->size();i++)
         {
           double DR_=999, idx=-1;
           for(int j=0;j<gjets_->size();j++)
           {
                double DR1_=fabs(gBQfirst_->at(i).vec_.DeltaR(gjets_->at(j).vec_));
                if(DR_>DR1_) { DR_=DR1_; idx=j;}
           }
           if(DR_<0.5) gBQfirstJetIdx[i]=idx;
           else gBQfirstJetIdx[i] = -1;
         }
//////////////
         int    bjet_idx_fromT[2]={-1,-1};
         double bQ_DR[2]={999,999}; double bQ_M[2]={-1,-1};
         double bQ_DRjj[2]={999,999}; double bQ_Mjj[2]={-1,-1};
         for(int i=0;i<gBQfirst_->size();i++)
         {
            if(i<gBQfirst_->size()-1)
            for(int j=i+1;j<gBQfirst_->size();j++)
            {
               if(abs(gBQfirst_->at(i).MotherPdgId())==6 && abs(gBQfirst_->at(j).MotherPdgId())==6 && bjet_idx_fromT[0]==-1 && bjet_idx_fromT[1]==-1 && fabs(gBQfirst_->at(i).vec_.DeltaR(gBQfirst_->at(j).vec_))>0.5)
               {
                  bQ_DR[0]=fabs(gBQfirst_->at(i).vec_.DeltaR(gBQfirst_->at(j).vec_));
                  bQ_M[0] = (gBQfirst_->at(i).vec_+gBQfirst_->at(j).vec_).M();
                  if(gBQfirstJetIdx[i]>-1 && gBQfirstJetIdx[j]>-1 && fabs(gjets_->at(gBQfirstJetIdx[i]).vec_.DeltaR(gjets_->at(gBQfirstJetIdx[j]).vec_))>0.5)
                  {
                    bQ_DRjj[0]=fabs(gjets_->at(gBQfirstJetIdx[i]).vec_.DeltaR(gjets_->at(gBQfirstJetIdx[j]).vec_));
                    bQ_Mjj[0] = (gjets_->at(gBQfirstJetIdx[i]).vec_+gjets_->at(gBQfirstJetIdx[j]).vec_).M();
                    bjet_idx_fromT[0]=gBQfirstJetIdx[i]; bjet_idx_fromT[1]=gBQfirstJetIdx[j];
                  }
               }
               if(abs(gBQfirst_->at(i).MotherPdgId())!=6 && abs(gBQfirst_->at(j).MotherPdgId())!=6 && bQ_Mjj[1]==-1 && !isttjj && fabs(gBQfirst_->at(i).vec_.DeltaR(gBQfirst_->at(j).vec_))>0.5)
               {
                  bQ_DR[1]=fabs(gBQfirst_->at(i).vec_.DeltaR(gBQfirst_->at(j).vec_));
                  bQ_M[1] = (gBQfirst_->at(i).vec_+gBQfirst_->at(j).vec_).M();
                  if(gBQfirstJetIdx[i]>-1 && gBQfirstJetIdx[j]>-1 && fabs(gjets_->at(gBQfirstJetIdx[i]).vec_.DeltaR(gjets_->at(gBQfirstJetIdx[j]).vec_))>0.5)
                  {
                    bQ_DRjj[1]=fabs(gjets_->at(gBQfirstJetIdx[i]).vec_.DeltaR(gjets_->at(gBQfirstJetIdx[j]).vec_));
                    bQ_Mjj[1] = (gjets_->at(gBQfirstJetIdx[i]).vec_+gjets_->at(gBQfirstJetIdx[j]).vec_).M();
                  }
               }
            }
         }
         if(isttjj && gQQfirst_->size()>1 && gjets_->size()>3)// && bjet_idx_fromT[0]>-1 && bjet_idx_fromT[1]>-1 && gQQfirst_->size()>1 && gQQfirst_->size()>1)
         {
             //cout << "start gQQ...." << endl;
             std::sort(gQQfirst_->begin(),gQQfirst_->end(),compByPtGenParticle);
             int gQQfirstJetIdx[200];
             for(int i=0;i<gQQfirst_->size();i++)
             {
               double DR_=999, idx=-1;
               for(int j=0;j<gjets_->size();j++)
               if(bjet_idx_fromT[0]!=j && bjet_idx_fromT[1]!=j)
               {
                    double DR1_=fabs(gQQfirst_->at(i).vec_.DeltaR(gjets_->at(j).vec_));
                    if(DR_>DR1_) { DR_=DR1_; idx=j;}
               }
               if(DR_<0.5) gQQfirstJetIdx[i]=idx;
               else gQQfirstJetIdx[i] = -1;
             }
             bool pass_=false;
             for(int i=0;i<gQQfirst_->size();i++)
             { //continue; // for debug
                if(i<gQQfirst_->size()-1)
                for(int j=i+1;j<gQQfirst_->size();j++)
                if(!pass_)
                if(gQQfirstJetIdx[i]>-1 && gQQfirstJetIdx[j]>-1 && fabs(gQQfirst_->at(i).vec_.DeltaR(gQQfirst_->at(j).vec_))>0.5 && fabs(gjets_->at(gQQfirstJetIdx[i]).vec_.DeltaR(gjets_->at(gQQfirstJetIdx[j]).vec_))>0.5)
                {
                    bQ_DR[1]=fabs(gQQfirst_->at(i).vec_.DeltaR(gQQfirst_->at(j).vec_));
                    bQ_M[1] = (gQQfirst_->at(i).vec_+gQQfirst_->at(j).vec_).M();
                    bQ_DRjj[1]=fabs(gjets_->at(gQQfirstJetIdx[i]).vec_.DeltaR(gjets_->at(gQQfirstJetIdx[j]).vec_));
                    bQ_Mjj[1] = (gjets_->at(gQQfirstJetIdx[i]).vec_+gjets_->at(gQQfirstJetIdx[j]).vec_).M();
                    pass_=true;
                }
             }
         }
         fevent_->gBQ1st_DR1fromT_= bQ_DR[0];
         fevent_->gBQ1st_DR2add_= bQ_DR[1];
         fevent_->gBQ1st_M1fromT_= bQ_M[0];
         fevent_->gBQ1st_M2add_= bQ_M[1];
         
         fevent_->gBQ1st_DR1jjfromT_= bQ_DRjj[0];
         fevent_->gBQ1st_DR2jjadd_= bQ_DRjj[1];
         fevent_->gBQ1st_M1jjfromT_= bQ_Mjj[0];
         fevent_->gBQ1st_M2jjadd_= bQ_Mjj[1];
         
         double DR_jj[2]={-999,-999 }, M_jj[2]={-1, -1};
         if(gjets_->size()>3)
         {
            DR_jj[0] = fabs( gjets_->at(0).vec_.DeltaR(gjets_->at(1).vec_) );
            DR_jj[1] = fabs( gjets_->at(2).vec_.DeltaR(gjets_->at(3).vec_) );
            M_jj[0] = (gjets_->at(0).vec_+gjets_->at(1).vec_).M();
            M_jj[1] = (gjets_->at(2).vec_+gjets_->at(3).vec_).M();
         }
         
         fevent_->gjet_DR1jj_= DR_jj[0];
         fevent_->gjet_DR2jj_= DR_jj[1];
         fevent_->gjet_M1jj_= M_jj[0];
         fevent_->gjet_M2jj_= M_jj[1];
      }

//////////////////////////////
      tree_->Fill();
   }

}

int Delphes::getLastIdX(int idx, int x)
{
   int idx_=idx;   
   int i=0;

   if(x==0)
   {while(i==0)
   {
      if(Particle_PID[Particle_D1[idx_]] != Particle_PID[idx_]) { i=1;  }
      else idx_=Particle_D1[idx_];
   }}
   else 
   {while(i==0)
   {
      if(Particle_PID[Particle_D2[idx_]] != Particle_PID[idx_]) { i=1;  }
      else idx_=Particle_D2[idx_];
   }}

   return idx_;
}
int Delphes::get1stIdX(int idx, int x)
{
   int idx_=idx;   
   int i=0;
   if(x==0)
   {while(i==0)
   {
      if(Particle_PID[Particle_M1[idx_]] != Particle_PID[idx_]) { i=1;  }
      else idx_=Particle_M1[idx_];
   }}
   else{
   while(i==0)
   {
      if(Particle_PID[Particle_M2[idx_]] != Particle_PID[idx_]) { i=1;  }
      else idx_=Particle_M2[idx_];
   }}

   return idx_;
}


int Delphes::isFromAny(int idx, int x, int id)
{
   int idx_=idx;
   int i=-1;//, j=0;

   if(x==0)
   {while(i==-1)
   {  //j++;
      int idx2_=Particle_M1[get1stIdX(idx_,0)];
      if(abs(Particle_PID[idx_])==id) i=2;
      if(idx<0) i=-2;
      if(idx_<idx2_) i=-2;
      idx_=idx2_;
   }}
   else
   {while(i==-1)
   {  //j++;
      int idx2_=Particle_M2[get1stIdX(idx_,0)];
      if(abs(Particle_PID[idx_])==id) i=2;
      if(idx<0) i=-2;
      if(idx_<idx2_) i=-2;
      idx_=idx2_;
   }}
   if(i==2) i=idx_;

   return i;
}
int Delphes::isFromTop(int idx, int x)
{
  return isFromAny(idx, x,6);
}
int Delphes::isFromBQ(int idx, int x)
{
  return isFromAny(idx, x,5);
}
int Delphes::isFromCQ(int idx, int x)
{
  return isFromAny(idx, x,4);
}
int Delphes::isFromHiggs(int idx, int x)
{
  return isFromAny(idx, x,25);
}

GenParticle Delphes::getGenParticle(int idx)
{
   int mid = Particle_PID[Particle_M1[get1stIdX(idx,0)]];
   GenParticle gp_(TLorentzVector( Particle_Px[idx],Particle_Py[idx],Particle_Pz[idx],Particle_E[idx]),Particle_PID[idx], Particle_Charge[idx], mid,idx);

   return gp_;
}

bool Delphes::HasAnyHadron(int PDGID, int id)
{
   // note:
   //    b quark: +-5
   //    meson code = 100i + 10j + 2s + 1, quark(i), anti-quark(-j)
   //    baryon code = 1000i + 100j + 10k + 2s + 1, quarks(ijk)

   if(PDGID < 0)
      PDGID = -PDGID;

   if(PDGID == id)
      return true;
   if((PDGID % 100) / 10 == id)
      return true;
   if((PDGID % 1000) / 100 == id)
      return true;
   if((PDGID % 10000) / 1000 == id)
      return true;

   return false;
}
bool Delphes::HasBHad(int PDGID )
{
  return HasAnyHadron( PDGID, 5);
}
bool Delphes::HasCHad(int PDGID )
{
  return HasAnyHadron( PDGID, 4);
}

int Delphes::isFromAnyHad(int idx, int x, int id)
{
   int idx_=idx;
   int i=-1;//, j=0;

   if(x==0)
   {while(i==-1)
   {  //j++;
      int idx2_=Particle_M1[get1stIdX(idx_,0)];
      if(HasAnyHadron(Particle_PID[idx_], id)) i=2;
      if(idx<0) i=-2;
      if(idx_<idx2_) i=-2;
      idx_=idx2_;
   }}
   else
   {while(i==-1)
   {  //j++;
      int idx2_=Particle_M2[get1stIdX(idx_,0)];
      if(HasAnyHadron(Particle_PID[idx_], id)) i=2;
      if(idx<0) i=-2;
      if(idx_<idx2_) i=-2;
      idx_=idx2_;
   }}

   return i;
}

int Delphes::isFromBHad(int idx, int x)
{
   return isFromAnyHad(idx, x, 5);
}
int Delphes::isFromCHad(int idx, int x)
{
   return isFromAnyHad(idx, x, 4);
}

/*
// done
  select dilepton in reco level
  plot leading and second lepton propeties
  #b hadron
  #b hadron and gen jet matching
 
 
// todo list
  the bjet is from top?
  the bjet is from b?
  double coutting?

  ovelap check as one jet within b and b~
  and in each level(b, t/h)

 !genjet and recojet matching

code range explanation (PHYTHIA8)
11 – 19 beam particles
21 – 29 particles of the hardest subprocess
31 – 39 particles of subsequent subprocesses in multiparton interactions
41 – 49 particles produced by initial-state-showers
51 – 59 particles produced by final-state-showers
61 – 69 particles produced by beam-remnant treatment
71 – 79 partons in preparation of hadronization process
81 – 89 primary hadrons produced by hadronization process
91 – 99 particles produced in decay process, or by Bose-Einstein effects

*/


