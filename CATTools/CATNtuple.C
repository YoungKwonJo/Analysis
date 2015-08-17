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
/////////
   TTree *tree_ = new TTree(Form("myresult"),"");
   FlatTree* fevent_ = new FlatTree();
   fevent_->book(tree_);

   LeptonsP muons_;        muons_     = new Leptons;
   LeptonsP electrons_;    electrons_ = new Leptons;
   JetsP   jets_;         jets_      = new Jets;
   JetsP   jetsPuppi_;    jetsPuppi_ = new Jets;

   LeptonsP muonsl_;        muonsl_     = new Leptons;
   LeptonsP electronsl_;    electronsl_ = new Leptons;

///////////
   int aaa=0;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
//////////////////////
      fevent_->clear();
 
      aaa++;
      //if(aaa>500) break;
      if(aaa%10000==0) cout << "event : " << aaa << endl;      
      //cout << "event : " << aaa << endl;      

      /////
      fevent_->met_     = met_pt->at(0);
      fevent_->metphi_  = met_phi->at(0);
      fevent_->metNoHFphi_  =  metNoHF_phi->at(0);
      fevent_->metNoHF_     =  metNoHF_pt->at(0);
      fevent_->metPfMvaphi_ =  metPfMva_phi->at(0);
      fevent_->metPfMva_    =  metPfMva_pt->at(0);
      fevent_->metPuppiphi_ =  metPuppi_phi->at(0);
      fevent_->metPuppi_    =  metPuppi_pt->at(0);

      fevent_->event_   = event; 
      fevent_->lumi_   = lumi; 

////////////////////
   fevent_->CSCTightHaloFilter_=                         CSCTightHaloFilter;                        
   fevent_->EcalDeadCellTriggerPrimitiveFilter_=         EcalDeadCellTriggerPrimitiveFilter;
   fevent_->HBHENoiseFilter_=                            HBHENoiseFilter;
   fevent_->eeBadScFilter_=                              eeBadScFilter;
   fevent_->goodVertices_=                               goodVertices;
   fevent_->HLTDoubleEle33CaloIdLGsfTrkIdVL_=            HLTDoubleEle33CaloIdLGsfTrkIdVL;
   fevent_->HLTEle12CaloIdLTrackIdLIsoVL_=               HLTEle12CaloIdLTrackIdLIsoVL;
   fevent_->HLTEle16Ele12Ele8CaloIdLTrackIdL_=           HLTEle16Ele12Ele8CaloIdLTrackIdL;
   fevent_->HLTEle17CaloIdLTrackIdLIsoVL_=               HLTEle17CaloIdLTrackIdLIsoVL;
   fevent_->HLTEle17Ele12CaloIdLTrackIdLIsoVLDZ_=        HLTEle17Ele12CaloIdLTrackIdLIsoVLDZ;
   fevent_->HLTEle23Ele12CaloIdLTrackIdLIsoVL_=          HLTEle23Ele12CaloIdLTrackIdLIsoVL;
   fevent_->HLTEle23Ele12CaloIdLTrackIdLIsoVLDZ_=        HLTEle23Ele12CaloIdLTrackIdLIsoVLDZ;
   fevent_->HLTEle27eta2p1WPLooseGsfTriCentralPFJet30_=  HLTEle27eta2p1WPLooseGsfTriCentralPFJet30;
   fevent_->HLTMu17Mu8DZ_=                               HLTMu17Mu8DZ;
   fevent_->HLTMu17TkMu8DZ_=                             HLTMu17TkMu8DZ;
   fevent_->HLTMu17TrkIsoVVLEle12CaloIdLTrackIdLIsoVL_=  HLTMu17TrkIsoVVLEle12CaloIdLTrackIdLIsoVL;
   fevent_->HLTMu17TrkIsoVVLMu8TrkIsoVVL_=               HLTMu17TrkIsoVVLMu8TrkIsoVVL;
   fevent_->HLTMu17TrkIsoVVLMu8TrkIsoVVLDZ_=             HLTMu17TrkIsoVVLMu8TrkIsoVVLDZ;
   fevent_->HLTMu17TrkIsoVVLTkMu8TrkIsoVVL_=             HLTMu17TrkIsoVVLTkMu8TrkIsoVVL;
   fevent_->HLTMu8TrkIsoVVLEle17CaloIdLTrackIdLIsoVL_=   HLTMu8TrkIsoVVLEle17CaloIdLTrackIdLIsoVL;
                                                                                                     
   fevent_->nGoodPV_=                                    nGoodPV;
   fevent_->nPV_=                                        nPV;
   fevent_->nTrueInteraction_=                           nTrueInteraction;
 
//      fevent_->HLTDoubleMu_   = HLTDoubleMu; 
//      fevent_->HLTDoubleEl_   = HLTDoubleEl;
//      fevent_->HLTMuEl_   = HLTMuEl;
      //reconstructed level information
      muons_->clear();
      electrons_->clear();
      jets_->clear();
      jetsPuppi_->clear();

      muonsl_->clear();
      electronsl_->clear();
      ////////

      for(int i=0;i<electrons_pt->size();i++)
      {
          if( electrons_pt->at(i)>20.0 && fabs(electrons_eta->at(i))<2.4 &&
              //electrons_idMedium->at(i)==1 &&
              //electrons_isPassConversionVeto->at(i)==1 &&
              !(fabs(electrons_scEta->at(i))>1.4442 && fabs(electrons_scEta->at(i))<1.5660) 
            ) 
          {
             double pt = electrons_pt->at(i);
             double eta = electrons_eta->at(i);
             double phi = electrons_phi->at(i);
             double mass = electrons_m->at(i);
             double relIso04 = electrons_relIso04->at(i);
             double q = electrons_q->at(i);

             Lepton el_(pt,eta,phi,mass, relIso04, q);
             //electrons_->push_back(el_);
             if(electrons_idMedium->at(i)==1) electrons_->push_back(el_);
             if(electrons_idLoose->at(i)==1 && relIso04<0.12) electronsl_->push_back(el_);
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

/////////////////////
      int Nmu=0, Nel=0, NmuIso=0, NelIso=0;
      for(int i=0;i<muons_->size();i++ )     if(muons_->at(i).Iso_<0.12)     NmuIso++;
      for(int i=0;i<electrons_->size();i++ ) if(electrons_->at(i).Iso_<0.12) NelIso++;
      for(int i=0;i<muons_->size();i++ )      Nmu++;
      for(int i=0;i<electrons_->size();i++ )  Nel++;
      fevent_->Nmu_=Nmu;
      fevent_->Nel_=Nel;
      fevent_->NmuIso_=NmuIso;
      fevent_->NelIso_=NelIso;

///////////////////
     // dilepton selection
      //TLorentzVector Zmm, Zee, Zem;
      double ZmmPt=-1., ZeePt=-1., ZemPt=-1.;
      double mm_zmass=-1., ee_zmass=-1., em_zmass=-1.;
      int mm_id1, mm_id2, ee_id1, ee_id2, em_id1, em_id2;
      double mm_mu1_dr_el=100., mm_mu2_dr_el=100., ee_el1_dr_mu=100., ee_el2_dr_mu=100., em_mu1_dr_el=100., em_el2_dr_mu=100.;
      bool ZmmS=false, ZeeS=false, ZemS=false;
      //for MuMu
      if(muons_->size()>1)
      for(int i=0;i<muons_->size()-1;i++ ) //if(ZmmS==false)
      for(int j=i+1;j<muons_->size();j++ ) //if(ZmmS==false)
      {
         TLorentzVector Zmm_((muons_->at(i).vec_)+(muons_->at(j).vec_));

         double ZmmPt_ = Zmm_.Pt();
         double mm_zmass_ = Zmm_.M();
         if(ZmmPt_>ZmmPt) 
         {
             mm_zmass=mm_zmass_; ZmmPt=ZmmPt_;  mm_id1=i; mm_id2=j; ZmmS=true; 
             for(int k=0;k<electrons_->size();k++) 
             {
                double mm_mu1_dr_el_ = fabs(electrons_->at(k).vec_.DeltaR(muons_->at(i).vec_));
                if(mm_mu1_dr_el_<mm_mu1_dr_el) mm_mu1_dr_el=mm_mu1_dr_el_;
                double mm_mu2_dr_el_ = fabs(electrons_->at(k).vec_.DeltaR(muons_->at(j).vec_));
                if(mm_mu2_dr_el_<mm_mu2_dr_el) mm_mu2_dr_el=mm_mu2_dr_el_;
             }
         }
      }
      //for ElEl
      if(electrons_->size()>1)
      for(int i=0;i<electrons_->size()-1;i++ ) //if(ZeeS==false)
      for(int j=i+1;j<electrons_->size();j++ ) //if(ZeeS==false)
      {
         TLorentzVector Zee_((electrons_->at(i).vec_)+(electrons_->at(j).vec_));
         double ZeePt_ = Zee_.Pt();
         double ee_zmass_ = Zee_.M();

         if(ZeePt_>ZeePt) 
         {
            ee_zmass=ee_zmass_; ZeePt=ZeePt_; ee_id1=i; ee_id2=j; ZeeS=true; 
            for(int k=0;k<muons_->size();k++)
            {
               double ee_el1_dr_mu_ = fabs(muons_->at(k).vec_.DeltaR(electrons_->at(i).vec_));
               if(ee_el1_dr_mu_<ee_el1_dr_mu) ee_el1_dr_mu=ee_el1_dr_mu_;
               double ee_el2_dr_mu_ = fabs(muons_->at(k).vec_.DeltaR(electrons_->at(j).vec_));
               if(ee_el2_dr_mu_<ee_el2_dr_mu) ee_el2_dr_mu=ee_el2_dr_mu_;
            }
         }
      }
      //for MuEl
      if(electrons_->size()>0 && muons_->size()>0)
      for(int i=0;i<muons_->size();i++ )     //if(ZemS==false)
      for(int j=0;j<electrons_->size();j++ ) //if(ZemS==false )
      {
         TLorentzVector Zem_((muons_->at(i).vec_)+(electrons_->at(j).vec_));
         double ZemPt_ = Zem_.Pt();
         double em_zmass_ = Zem_.M();

         if(ZemPt_>ZemPt) 
         {
            em_zmass=em_zmass_; ZemPt=ZemPt_;   em_id1=i; em_id2=j; ZemS=true; 
            for(int k=0;k<electrons_->size();k++)
            {
               double em_mu1_dr_el_ = fabs(electrons_->at(k).vec_.DeltaR(muons_->at(i).vec_));
               if(em_mu1_dr_el_<em_mu1_dr_el) em_mu1_dr_el=em_mu1_dr_el_;
            }
            for(int k=0;k<muons_->size();k++)
            {
               double em_el2_dr_mu_ = fabs(muons_->at(k).vec_.DeltaR(electrons_->at(j).vec_));
               if(em_el2_dr_mu_<em_el2_dr_mu) em_el2_dr_mu=em_el2_dr_mu_;
            }
         }
      }
/////////////////////////////////////
     if(ZmmPt>ZeePt && ZmmPt>ZemPt) {  ZeeS=false; ZemS =false; }
     if(ZeePt>ZmmPt && ZeePt>ZemPt) {  ZmmS=false; ZemS =false; }
     if(ZemPt>ZmmPt && ZemPt>ZeePt) {  ZmmS=false; ZeeS =false; }

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
         fevent_->mm_zmass_  = mm_zmass;
         fevent_->mm_mu1_dr_el_ = mm_mu1_dr_el;
         fevent_->mm_mu2_dr_el_ = mm_mu2_dr_el;
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
         fevent_->ee_zmass_  = ee_zmass;
         fevent_->ee_el1_dr_mu_ = ee_el1_dr_mu;
         fevent_->ee_el2_dr_mu_ = ee_el2_dr_mu;
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
         fevent_->em_zmass_  = em_zmass;
         fevent_->em_mu1_dr_el_ = em_mu1_dr_el;
         fevent_->em_el2_dr_mu_ = em_el2_dr_mu;
      }

////////////////////////////////////
//PFJET
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
             double minDR=1000.;
             for(int j=0;j<muonsl_->size();j++ )
             {
                 double minDR_= fabs(muonsl_->at(j).vec_.DeltaR(jet_.vec_));
                 if(minDR_<minDR) minDR=minDR_;
             }
             for(int j=0;j<electronsl_->size();j++ )
             {
                 double minDR_= fabs(electronsl_->at(j).vec_.DeltaR(jet_.vec_));
                 if(minDR_<minDR) minDR=minDR_;
             }
             if(minDR==1000.) minDR=-999; 
             jet_.setDRl(minDR);

             //jets_->push_back(jet_);
             bool isFill=true;

             //////////// 1st option
             //for(int j=0;j<muonsl_->size();j++ )     if(fabs(muonsl_     ->at(j).vec_.DeltaR(jet_.vec_))<0.4 ) isFill=false;
             //for(int j=0;j<electronsl_->size();j++ )  if(fabs(electronsl_->at(j).vec_.DeltaR(jet_.vec_))<0.4 ) isFill=false;

             /////////// 2nd option
             if(ZmmS)// && !ZeeS && !ZemS) 
             //if(mm_zmass>20 && (muons_->at(mm_id1).Q_*muons_->at(mm_id2).Q_<0) )
             {
                 if(fabs(muons_->at(mm_id1).vec_.DeltaR(jet_.vec_))<0.4 && muons_->at(mm_id1).Iso_<0.12 ) isFill=false;
                 if(fabs(muons_->at(mm_id2).vec_.DeltaR(jet_.vec_))<0.4 && muons_->at(mm_id2).Iso_<0.12 ) isFill=false;
             }
             if(ZeeS)
             //if(ee_zmass>20 && (electrons_->at(ee_id1).Q_*electrons_->at(ee_id2).Q_<0) )
             {
                 //if( electrons_->at(ee_id1).Iso_<0.12 && electrons_->at(ee_id2).Iso_<0.12 )
                 {
                    if(fabs(electrons_->at(ee_id1).vec_.DeltaR(jet_.vec_))<0.4 ) isFill=false;
                    if(fabs(electrons_->at(ee_id2).vec_.DeltaR(jet_.vec_))<0.4 ) isFill=false;
                 }
             }
             if(ZemS)
             //if(em_zmass>20 && (muons_->at(em_id1).Q_*electrons_->at(em_id2).Q_<0) )
             {
                 //if( muons_->at(em_id1).Iso_<0.12 && electrons_->at(em_id2).Iso_<0.12 ) 
                 {
                    if(fabs(muons_    ->at(em_id1).vec_.DeltaR(jet_.vec_))<0.4) isFill=false;
                    if(fabs(electrons_->at(em_id2).vec_.DeltaR(jet_.vec_))<0.4) isFill=false;
                 }
             }

             if(isFill) jets_->push_back(jet_);
          }
      }
      std::sort(jets_->begin(), jets_->end(), compByCSVJet);

//////////////
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
         fevent_->jet_drl_->push_back( jets_->at(i).DRl() );   
      } 
      fevent_->nJet_=nJet;
      fevent_->nBJetT_=nBJetT;
      fevent_->nBJetM_=nBJetM;
      fevent_->nBJetL_=nBJetL;

////////////////////////
////////////////////////////////////
//JETPUPPI
      for(int i=0;i<jetsPuppi_pt->size();i++)
      {
          if( jetsPuppi_pt->at(i)>30.0 && fabs(jetsPuppi_eta->at(i))<2.4 
            ) 
          {
             double pt = jetsPuppi_pt->at(i);
             double eta = jetsPuppi_eta->at(i);
             double phi = jetsPuppi_phi->at(i);
             double mass = jetsPuppi_m->at(i);
             double CSVInclV2 = jetsPuppi_CSVInclV2->at(i);
             Jet jet_(pt,eta,phi,mass, CSVInclV2);
             double minDR=1000.;
             for(int j=0;j<muonsl_->size();j++ )
             {
                 double minDR_= fabs(muonsl_->at(j).vec_.DeltaR(jet_.vec_));
                 if(minDR_<minDR) minDR=minDR_;
             }
             for(int j=0;j<electronsl_->size();j++ )
             {
                 double minDR_= fabs(electronsl_->at(j).vec_.DeltaR(jet_.vec_));
                 if(minDR_<minDR) minDR=minDR_;
             }
             if(minDR==1000.) minDR=-999; 
             jet_.setDRl(minDR);

             //jets_->push_back(jet_);
             bool isFill=true;

             //////////// 1st option
             //for(int j=0;j<muonsl_->size();j++ )     if(fabs(muonsl_     ->at(j).vec_.DeltaR(jet_.vec_))<0.4 ) isFill=false;
             //for(int j=0;j<electronsl_->size();j++ )  if(fabs(electronsl_->at(j).vec_.DeltaR(jet_.vec_))<0.4 ) isFill=false;

             /////////// 2nd option
             if(ZmmS)// && !ZeeS && !ZemS) 
             //if(mm_zmass>20 && (muons_->at(mm_id1).Q_*muons_->at(mm_id2).Q_<0) )
             {
                 if(fabs(muons_->at(mm_id1).vec_.DeltaR(jet_.vec_))<0.4 && muons_->at(mm_id1).Iso_<0.12 ) isFill=false;
                 if(fabs(muons_->at(mm_id2).vec_.DeltaR(jet_.vec_))<0.4 && muons_->at(mm_id2).Iso_<0.12 ) isFill=false;
             }
             if(ZeeS)
             //if(ee_zmass>20 && (electrons_->at(ee_id1).Q_*electrons_->at(ee_id2).Q_<0) )
             {
                 //if( electrons_->at(ee_id1).Iso_<0.12 && electrons_->at(ee_id2).Iso_<0.12 )
                 {
                    if(fabs(electrons_->at(ee_id1).vec_.DeltaR(jet_.vec_))<0.4 ) isFill=false;
                    if(fabs(electrons_->at(ee_id2).vec_.DeltaR(jet_.vec_))<0.4 ) isFill=false;
                 }
             }
             if(ZemS)
             //if(em_zmass>20 && (muons_->at(em_id1).Q_*electrons_->at(em_id2).Q_<0) )
             {
                 //if( muons_->at(em_id1).Iso_<0.12 && electrons_->at(em_id2).Iso_<0.12 ) 
                 {
                    if(fabs(muons_    ->at(em_id1).vec_.DeltaR(jet_.vec_))<0.4) isFill=false;
                    if(fabs(electrons_->at(em_id2).vec_.DeltaR(jet_.vec_))<0.4) isFill=false;
                 }
             }

             if(isFill) jetsPuppi_->push_back(jet_);
          }
      }
      std::sort(jetsPuppi_->begin(), jetsPuppi_->end(), compByCSVJet);

//////////////
      int nBJetTPuppi=0, nBJetMPuppi=0, nBJetLPuppi=0, nJetPuppi=0;
      for(int i=0;i<jetsPuppi_->size();i++)
      {
         if(jetsPuppi_->at(i).CSV()>0.970) nBJetT++; // CSVT 0.970
         if(jetsPuppi_->at(i).CSV()>0.890) nBJetM++; // CSVM 0.890 
         if(jetsPuppi_->at(i).CSV()>0.605) nBJetL++; // CSVL 0.605 
         nJetPuppi++;
         fevent_->jetPuppi_pt_ ->push_back( jetsPuppi_->at(i).Pt() );   
         fevent_->jetPuppi_eta_->push_back( jetsPuppi_->at(i).Eta() );   
         fevent_->jetPuppi_phi_->push_back( jetsPuppi_->at(i).Phi() );   
         fevent_->jetPuppi_csv_->push_back( jetsPuppi_->at(i).CSV() );   
         fevent_->jetPuppi_drl_->push_back( jetsPuppi_->at(i).DRl() );   
      } 
      fevent_->nJetPuppi_=nJetPuppi;
      fevent_->nBJetTPuppi_=nBJetTPuppi;
      fevent_->nBJetMPuppi_=nBJetMPuppi;
      fevent_->nBJetLPuppi_=nBJetLPuppi;

////////////////////////



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

//////////
      tree_->Fill();




///////////////////////
   }
}
