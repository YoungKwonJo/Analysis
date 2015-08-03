#define CATNtuple_cxx
#include "CATNtuple.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

#include <TLorentzVector.h>
#include <TH1F.h>
#include <TH2F.h>
#include <iostream>

#include "Jet.h"
#include "Lepton.h"
#include "FlatTree.h"

typedef std::vector<Lepton> Leptons;
typedef Leptons* LeptonsP;
bool compByPtLep(Lepton a, Lepton b)
{
   return a.Pt() > b.Pt();
};

typedef std::vector<Jet> Jets;
typedef Jets* JetsP;
bool compByPtJet(Jet a, Jet b)
{
   return a.Pt() > b.Pt();
};
bool compByCSVJet(Jet a, Jet b)
{
   return a.CSV() > b.CSV();
};


void CATNtuple::Loop()
{
   if (fChain == 0) return;
///////////

   TTree *tree_ = new TTree(Form("myresult"),"");
   FlatTree* fevent_ = new FlatTree();
   fevent_->book(tree_);

   LeptonsP muons_;        muons_     = new Leptons;
   LeptonsP electrons_;    electrons_ = new Leptons;
   JetsP   jets_;         jets_      = new Jets;

   LeptonsP muonsl_;        muonsl_     = new Leptons;
   LeptonsP electronsl_;    electronsl_ = new Leptons;
///////////
   int aaa=0;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) 
   {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
/////
      fevent_->clear();
 
      aaa++;
      //if(aaa>500) break;
      if(aaa%10000) cout << "event : " << aaa << endl;      
      //cout << "event : " << aaa << endl;      

      /////
      fevent_->met_     = met_pt->at(0);
      fevent_->metphi_  = met_phi->at(0);

      fevent_->event_   = event; 
      fevent_->lumi_   = lumi; 

//      fevent_->HLTDoubleMu_   = HLTDoubleMu; 
//      fevent_->HLTDoubleEl_   = HLTDoubleEl;
//      fevent_->HLTMuEl_   = HLTMuEl;
      //reconstructed level information
      muons_->clear();
      electrons_->clear();
      jets_->clear();
      ////////

      for(int i=0;i<electrons_pt->size();i++)
      {
          if( electrons_pt->at(i)>20.0 && fabs(electrons_eta->at(i))<2.4 &&
              //electrons_idMedium->at(i)==1 &&
              electrons_isPassConversionVeto->at(i)==1 &&
              !(fabs(electrons_scEta->at(i))>1.4442 && fabs(electrons_scEta->at(i))<1.5660) 
            ) 
          {
             double pt = electrons_pt->at(i);
             double eta = electrons_eta->at(i);
             double phi = electrons_phi->at(i);
             double mass = electrons_m->at(i);
             double relIso03 = electrons_relIso03->at(i);
             double q = electrons_q->at(i);

             Lepton el_(pt,eta,phi,mass, relIso03, q);
             //electrons_->push_back(el_);
             if(electrons_idMedium->at(i)==1) electrons_->push_back(el_);
             if(electrons_idLoose->at(i)==1 && relIso03<0.12) electronsl_->push_back(el_);
          }
      }
      std::sort(electrons_->begin(), electrons_->end(), compByPtLep);

      for(int i=0;i<muons_pt->size();i++)
      {
          if( muons_pt->at(i)>20.0 && fabs(muons_eta->at(i))<2.4 &&
              //muons_isTight->at(i)==1 && 
              muons_isPF->at(i)==1 && muons_isGlobal->at(i)==1 && 
              fabs(muons_dxy->at(i))<0.2 && fabs(muons_dz->at(i))<0.5 &&
              muons_normalizedChi2->at(i)<10 && muons_numberOfValidMuonHits->at(i)>0 &&
              muons_numberOfValidPixelHits->at(i)>0 && muons_numberOfMatchedStations->at(i)>1 
              //&&  muons_relIso04->at(i)<0.12   
            ) 
          {
             double pt = muons_pt->at(i);
             double eta = muons_eta->at(i);
             double phi = muons_phi->at(i);
             double mass = muons_m->at(i);
             double relIso04 = muons_relIso04->at(i);
             double q = muons_q->at(i);

             Lepton el_(pt,eta,phi,mass, relIso04, q);
             if(muons_isTight->at(i)==1) muons_->push_back(el_);
             if(muons_isLoose->at(i)==1 && relIso04<0.12) muonsl_->push_back(el_);
             //muons_->push_back(el_);
          }
      }
      std::sort(muons_->begin(), muons_->end(), compByPtLep);

      for(int i=0;i<jets_pt->size();i++)
      {
          if( jets_pt->at(i)>30.0 && fabs(jets_eta->at(i))<2.4 
            ) 
          {
             double pt = jets_pt->at(i);
             double eta = jets_eta->at(i);
             double phi = jets_phi->at(i);
             double mass = jets_m->at(i);
             double CSVInclV2 = jets_CSVInclV2->at(i);
             Jet jet_(pt,eta,phi,mass, CSVInclV2);
             //jets_->push_back(jet_);
             bool isFill=true;
             for(int j=0;j<muonsl_->size();j++ )     if(fabs(muons_    ->at(j).vec_.DeltaR(jet_.vec_))<0.4 ) isFill=false;
             for(int j=0;j<electrons_->size();j++ )  if(fabs(electrons_->at(j).vec_.DeltaR(jet_.vec_))<0.4 ) isFill=false;

             if(isFill) jets_->push_back(jet_);
          }
      }
      std::sort(jets_->begin(), jets_->end(), compByCSVJet);
////////
      int Nmu=0, Nel=0;
      for(int i=0;i<muons_->size();i++ )     if(muons_->at(i).Iso_<0.12)     Nmu++;
      for(int i=0;i<electrons_->size();i++ ) if(electrons_->at(i).Iso_<0.12) Nel++;
      fevent_->Nmu_=Nmu;
      fevent_->Nel_=Nel;

     //continue;
     // dilepton selection
      TLorentzVector Zmm, Zee, Zem;
      int mm_id1, mm_id2, ee_id1, ee_id2, em_id1, em_id2;
      bool ZmmS=false, ZeeS=false, ZemS=false;
      //for MuMu
      if(muons_->size()>1)
      for(int i=0;i<muons_->size()-1;i++ ) if(ZmmS==false)
      for(int j=i+1;j<muons_->size();j++ ) if(ZmmS==false)
      {
         Zmm = ((muons_->at(i).vec_)+(muons_->at(j).vec_));
         bool iso = ((muons_->at(i).Iso_<0.12) && (muons_->at(j).Iso_<0.12));
         bool opp = (muons_->at(i).Q_*muons_->at(j).Q_<0) && (Zmm.M()>20.);
         if(iso && opp) {   mm_id1=i; mm_id2=j; ZmmS=true; break; }
      }
      if(!ZmmS && muons_->size()>1)
      {
          Zmm = ((muons_->at(0).vec_)+(muons_->at(1).vec_));
          mm_id1=0; mm_id2=1;
          ZmmS=true;
      }
      if(ZmmS)
      {
         fevent_->mm_mu1_pt_ = muons_->at(mm_id1).Pt();
         fevent_->mm_mu1_eta_= muons_->at(mm_id1).Eta();
         fevent_->mm_mu1_phi_= muons_->at(mm_id1).Phi();
         fevent_->mm_mu1_q_  = muons_->at(mm_id1).Q_;
         fevent_->mm_mu1_iso_= muons_->at(mm_id1).Iso_;
         fevent_->mm_mu2_pt_ = muons_->at(mm_id2).Pt();
         fevent_->mm_mu2_eta_= muons_->at(mm_id2).Eta();
         fevent_->mm_mu2_phi_= muons_->at(mm_id2).Phi();
         fevent_->mm_mu2_q_  = muons_->at(mm_id2).Q_;
         fevent_->mm_mu2_iso_= muons_->at(mm_id2).Iso_;
         fevent_->mm_zmass_  = Zmm.M();
      }

      //for ElEl
      if(electrons_->size()>0)
      for(int i=0;i<electrons_->size()-1;i++ ) if(ZeeS==false)
      for(int j=i+1;j<electrons_->size();j++ ) if(ZeeS==false)
      {
         Zee = ((electrons_->at(i).vec_)+(electrons_->at(j).vec_));
         bool iso = ((electrons_->at(i).Iso_<0.12) && (electrons_->at(j).Iso_<0.12));
         bool opp = (electrons_->at(i).Q_*electrons_->at(j).Q_<0) && (Zee.M()>20.);
         if(iso && opp) {   ee_id1=i; ee_id2=j; ZeeS=true; break; }
      }
      if(!ZeeS && electrons_->size()>1)
      {
          Zee = ((electrons_->at(0).vec_)+(electrons_->at(1).vec_));    
          ee_id1=0; ee_id2=1;
          ZeeS=true;
      } 
      if(ZeeS)
      {
         fevent_->ee_el1_pt_ = electrons_->at(ee_id1).Pt();
         fevent_->ee_el1_eta_= electrons_->at(ee_id1).Eta();
         fevent_->ee_el1_phi_= electrons_->at(ee_id1).Phi();
         fevent_->ee_el1_q_  = electrons_->at(ee_id1).Q_;
         fevent_->ee_el1_iso_= electrons_->at(ee_id1).Iso_;
         fevent_->ee_el2_pt_ = electrons_->at(ee_id2).Pt();
         fevent_->ee_el2_eta_= electrons_->at(ee_id2).Eta();
         fevent_->ee_el2_phi_= electrons_->at(ee_id2).Phi();
         fevent_->ee_el2_q_  = electrons_->at(ee_id2).Q_;
         fevent_->ee_el2_iso_= electrons_->at(ee_id2).Iso_;
         fevent_->ee_zmass_  = Zee.M();
      }
      //for MuEl
      if(electrons_->size()>0 && muons_->size()>0)
      for(int i=0;i<muons_->size();i++ )     if(ZemS==false)
      for(int j=0;j<electrons_->size();j++ ) if(ZemS==false )
      {
         Zem = ((muons_->at(i).vec_)+(electrons_->at(j).vec_));
         bool iso = ((muons_->at(i).Iso_<0.12) && (electrons_->at(j).Iso_<0.12));
         bool opp = (muons_->at(i).Q_*electrons_->at(j).Q_<0) && (Zem.M()>20.);
         if(iso && opp) {   em_id1=i; em_id2=j; ZemS=true; break; }
      }
      if(!ZemS && muons_->size()>0 && electrons_->size()>0 )
      {
          Zem = ((muons_->at(0).vec_)+(electrons_->at(0).vec_));
          em_id1=0; em_id2=0;
          ZemS=true;
      }
      if(ZemS)
      {
         fevent_->em_mu1_pt_ = muons_->at(em_id1).Pt();
         fevent_->em_mu1_eta_= muons_->at(em_id1).Eta();
         fevent_->em_mu1_phi_= muons_->at(em_id1).Phi();
         fevent_->em_mu1_q_  = muons_->at(em_id1).Q_;
         fevent_->em_mu1_iso_= muons_->at(em_id1).Iso_;
         fevent_->em_el2_pt_ = electrons_->at(em_id2).Pt();
         fevent_->em_el2_eta_= electrons_->at(em_id2).Eta();
         fevent_->em_el2_phi_= electrons_->at(em_id2).Phi();
         fevent_->em_el2_q_  = electrons_->at(em_id2).Q_;
         fevent_->em_el2_iso_= electrons_->at(em_id2).Iso_;
         fevent_->em_zmass_  = Zem.M();
      }
//////////

      int nBJetT=0, nBJetM=0, nBJetL=0, nJet=0;
      for(int i=0;i<jets_->size();i++)
      {
         if(jets_->at(i).CSV()>0.970) nBJetT++; // CSVT 0.970
         if(jets_->at(i).CSV()>0.890) nBJetM++; // CSVM 0.890 
         if(jets_->at(i).CSV()>0.605) nBJetL++; // CSVL 0.605 
         nJet++;
         fevent_->jet_pt_ ->push_back( jets_->at(i).Pt() );   
         fevent_->jet_eta_->push_back( jets_->at(i).Eta() );   
         fevent_->jet_phi_->push_back( jets_->at(i).Phi() );   
         fevent_->jet_csv_->push_back( jets_->at(i).CSV() );   
      } 
      fevent_->nJet_=nJet;
      fevent_->nBJetT_=nBJetT;
      fevent_->nBJetM_=nBJetM;
      fevent_->nBJetL_=nBJetL;

//////
      fevent_->isMM_ = ((int) (genTtbarLeptonDecay%100)==2); 
      fevent_->isEE_ = ((int) (genTtbarLeptonDecay%10000)==200);
      fevent_->isEM_ = ((int) (genTtbarLeptonDecay%10000)==101);

      int category =0; // 0:tt+lf, 1:tt+cc, 2:tt+bb, 3:tt+2b, 4:tt+b  
      if(genTtbarId%100 == 0)                   category=0;
      else if( ((int)(genTtbarId%100)/10) == 4) category=1;
      else if( ((int)(genTtbarId%100)) == 51)   category=4;
      else if( ((int)(genTtbarId%100)) == 52)   category=3;
      else if( ((int)(genTtbarId%100)) == 53)   category=2;
      else if( ((int)(genTtbarId%100)) == 54)   category=2;
      else if( ((int)(genTtbarId%100)) == 55)   category=2;
      fevent_->Category_ =  category;
      fevent_->NgenJet_ = NgenJet;
/////
      tree_->Fill();

/////

   }
}
