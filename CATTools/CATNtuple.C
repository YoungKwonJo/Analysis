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


void CATNtuple::Loop(bool isMC_)
{
   if (fChain == 0) return;
/////////
   TTree *tree_ = new TTree(Form("myresult"),"");
   TTree *tree2_ = new TTree(Form("myresult2"),"");
   FlatTree* fevent_ = new FlatTree();
   FlatTree* fevent2_ = new FlatTree();
   fevent_->book(tree_);
   fevent2_->book(tree2_);

   LeptonsP muons_;        muons_     = new Leptons;
   LeptonsP electrons_;    electrons_ = new Leptons;
   JetsP   jets_;         jets_      = new Jets;
   JetsP   jetsPuppi_;    jetsPuppi_ = new Jets;

   LeptonsP leptons_;       leptons_    = new Leptons;
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
      if(aaa%100000==0) cout << "event : " << aaa << endl;      
      //cout << "event : " << aaa << endl;      

      fevent_->run_   = run; 
      fevent_->event_ = event; 
      fevent_->lumi_  = lumi; 

//////////////////
      fevent_->met_     = (float) met_pt->at(0);
      fevent_->metphi_  = (float) met_phi->at(0);
      fevent_->metNoHFphi_  = (float)  metNoHF_phi->at(0);
      fevent_->metNoHF_     = (float)  metNoHF_pt->at(0);
      fevent_->metPfMvaphi_ = (float)  metPfMva_phi->at(0);
      fevent_->metPfMva_    = (float)  metPfMva_pt->at(0);
      fevent_->metPuppiphi_ = (float)  metPuppi_phi->at(0);
      fevent_->metPuppi_    = (float)  metPuppi_pt->at(0);

////////////////////
   fevent_->CSCTightHaloFilter_=                         CSCTightHaloFilter;                        
   fevent_->EcalDeadCellTriggerPrimitiveFilter_=         EcalDeadCellTriggerPrimitiveFilter;
   fevent_->HBHENoiseFilter_=                            HBHENoiseFilter;
   fevent_->eeBadScFilter_=                              eeBadScFilter;
   fevent_->goodVertices_=                               goodVertices;

   fevent_->HLTEle17Ele12CaloIdLTrackIdLIsoVLDZ_=             HLTEle17Ele12CaloIdLTrackIdLIsoVLDZ;
   fevent_->HLTEle17Ele12CaloIdLTrackIdLIsoVLDZold_=          HLTEle17Ele12CaloIdLTrackIdLIsoVLDZold;
   fevent_->HLTMu17TrkIsoVVLEle12CaloIdLTrackIdLIsoVL_=       HLTMu17TrkIsoVVLEle12CaloIdLTrackIdLIsoVL;
   fevent_->HLTMu17TrkIsoVVLEle12CaloIdLTrackIdLIsoVLold_=    HLTMu17TrkIsoVVLEle12CaloIdLTrackIdLIsoVLold;
   fevent_->HLTMu17TrkIsoVVLMu8TrkIsoVVLDZ_=                  HLTMu17TrkIsoVVLMu8TrkIsoVVLDZ;
   fevent_->HLTMu17TrkIsoVVLMu8TrkIsoVVLDZold_=               HLTMu17TrkIsoVVLMu8TrkIsoVVLDZold;
   fevent_->HLTMu17TrkIsoVVLTkMu8TrkIsoVVLDZ_=                HLTMu17TrkIsoVVLTkMu8TrkIsoVVLDZ;
   fevent_->HLTMu17TrkIsoVVLTkMu8TrkIsoVVLDZold_=             HLTMu17TrkIsoVVLTkMu8TrkIsoVVLDZold;
   fevent_->HLTMu8TrkIsoVVLEle17CaloIdLTrackIdLIsoVL_=        HLTMu8TrkIsoVVLEle17CaloIdLTrackIdLIsoVL;
   fevent_->HLTMu8TrkIsoVVLEle17CaloIdLTrackIdLIsoVLold_=     HLTMu8TrkIsoVVLEle17CaloIdLTrackIdLIsoVLold;

   fevent_->nGoodPV_=                                    nGoodPV;
   fevent_->nPV_=                                        nPV;

////////////////////
      leptons_->clear();
      muons_->clear();
      electrons_->clear();
      jets_->clear();
      jetsPuppi_->clear();
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
             double relIso03 = electrons_relIso03->at(i);
             int q = electrons_q->at(i);
             int MCmatched = false;
             if(isMC_) MCmatched = electrons_matched->at(i);
             int id=0;
             if(electrons_idLoose->at(i)==1) id=1;
             if(electrons_idMedium->at(i)==1) id=2;
             if(electrons_idTight->at(i)==1) id=3;


             Lepton el_(pt,eta,phi,mass, relIso03, q,id,q*11,MCmatched);
             if(electrons_idMedium->at(i)==1) leptons_->push_back(el_);
             if(electrons_idMedium->at(i)==1) electrons_->push_back(el_);
          }
      }
      std::sort(electrons_->begin(), electrons_->end(), compByPtLep);

      for(int i=0;i<muons_pt->size();i++)
      {
          if( muons_pt->at(i)>20.0 && fabs(muons_eta->at(i))<2.4 
              // && muons_isTight->at(i)==1 
              //&& muons_isPF->at(i)==1 && muons_isGlobal->at(i)==1 && 
              //fabs(muons_dxy->at(i))<0.2 && fabs(muons_dz->at(i))<0.5 &&
              //muons_normalizedChi2->at(i)<10 && muons_numberOfValidMuonHits->at(i)>0 &&
              //muons_numberOfValidPixelHits->at(i)>0 && muons_numberOfMatchedStations->at(i)>1 
            ) 
          {
             double pt = muons_pt->at(i);
             double eta = muons_eta->at(i);
             double phi = muons_phi->at(i);
             double mass = muons_m->at(i);
             double relIso04 = muons_relIso04->at(i);
             int q = muons_q->at(i);
             int MCmatched = false;
             if(isMC_) MCmatched = muons_matched->at(i);

             int id=0;
             if(muons_isLoose->at(i)==1) id=1;
             //if(muons_isMedium->at(i)==1) id=2;
             if(muons_isTight->at(i)==1) id=3;

             Lepton el_(pt,eta,phi,mass, relIso04, q,id,q*13,MCmatched);
             if(muons_isTight->at(i)==1) leptons_->push_back(el_);
             if(muons_isTight->at(i)==1) muons_->push_back(el_);
          }
      }
      std::sort(muons_->begin(), muons_->end(), compByPtLep);
      std::sort(leptons_->begin(), leptons_->end(), compByPtLep);

/////////////////////
      int Nmu=0, Nel=0, NmuIso=0, NelIso=0;
      for(int i=0;i<muons_->size();i++ )     if(muons_->at(i).Iso_<0.12)     NmuIso++;
      for(int i=0;i<electrons_->size();i++ ) if(electrons_->at(i).Iso_<0.12) NelIso++;
      for(int i=0;i<muons_->size();i++ )       Nmu++;
      for(int i=0;i<electrons_->size();i++ )   Nel++;
      fevent_->Nmu_=Nmu;
      fevent_->Nel_=Nel;
      fevent_->NmuIso_=NmuIso;
      fevent_->NelIso_=NelIso;

///////////////////
     // dilepton selection
      int leptons_N = leptons_->size();
      fevent_->lepton_N_= leptons_N;
      if(leptons_N>1)
      {
         fevent_->ll_lep1_pt_ = (float) leptons_->at(0).Pt();
         fevent_->ll_lep1_eta_= (float) leptons_->at(0).Eta();
         fevent_->ll_lep1_phi_= (float) leptons_->at(0).Phi();
         fevent_->ll_lep1_q_  =  leptons_->at(0).Q_;
         fevent_->ll_lep1_pdgid_  = leptons_->at(0).pdgid_;
         fevent_->ll_lep1_iso_= (float) leptons_->at(0).Iso_;
         fevent_->ll_lep2_pt_ = (float) leptons_->at(1).Pt();
         fevent_->ll_lep2_eta_= (float) leptons_->at(1).Eta();
         fevent_->ll_lep2_phi_= (float) leptons_->at(1).Phi();
         fevent_->ll_lep2_q_  = leptons_->at(1).Q_;
         fevent_->ll_lep2_pdgid_  = leptons_->at(1).pdgid_;
         fevent_->ll_lep2_iso_=(float) leptons_->at(1).Iso_;
         fevent_->ll_zmass_  =  (float) ((leptons_->at(0).vec_)+(leptons_->at(1).vec_)).M();
      
         if(abs(leptons_->at(0).pdgid_)==13 && abs(leptons_->at(1).pdgid_)==11)
         {
            fevent_->ll_lep1_pt_ = (float) leptons_->at(1).Pt();
            fevent_->ll_lep1_eta_= (float) leptons_->at(1).Eta();
            fevent_->ll_lep1_phi_= (float) leptons_->at(1).Phi();
            fevent_->ll_lep1_q_  = leptons_->at(1).Q_;
            fevent_->ll_lep1_pdgid_  = leptons_->at(1).pdgid_;
            fevent_->ll_lep1_iso_= (float) leptons_->at(1).Iso_;
            fevent_->ll_lep2_pt_ = (float) leptons_->at(0).Pt();
            fevent_->ll_lep2_eta_= (float) leptons_->at(0).Eta();
            fevent_->ll_lep2_phi_= (float) leptons_->at(0).Phi();
            fevent_->ll_lep2_q_  = leptons_->at(0).Q_;
            fevent_->ll_lep2_pdgid_  = leptons_->at(0).pdgid_;
            fevent_->ll_lep2_iso_= (float) leptons_->at(0).Iso_;
         }
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
             bool isFill=true;
             if(leptons_N>0&& fabs(leptons_->at(0).vec_.DeltaR(jet_.vec_))<0.4 ) isFill=false;
             if(leptons_N>1&& fabs(leptons_->at(1).vec_.DeltaR(jet_.vec_))<0.4 ) isFill=false;
 
             if(isFill) jets_->push_back(jet_);
          }
      }
      std::sort(jets_->begin(), jets_->end(), compByCSVJet);
      //std::sort(jets_->begin(), jets_->end(), compByPtJet);

//////////////
      int nBJet20T=0, nBJet20M=0, nBJet20L=0, nJet20=0;
      int nBJet30T=0, nBJet30M=0, nBJet30L=0, nJet30=0;
      for(int i=0;i<jets_->size();i++)
      {
         if(jets_->at(i).CSV()>0.970) nBJet20T++; // CSVT 0.970
         if(jets_->at(i).CSV()>0.890) nBJet20M++; // CSVM 0.890 
         if(jets_->at(i).CSV()>0.605) nBJet20L++; // CSVL 0.605 
         nJet20++;
         if(jets_->at(i).Pt()>30)
         {
           nJet30++;
           if(jets_->at(i).CSV()>0.970) nBJet30T++; // CSVT 0.970
           if(jets_->at(i).CSV()>0.890) nBJet30M++; // CSVM 0.890 
           if(jets_->at(i).CSV()>0.605) nBJet30L++; // CSVL 0.605 
         } 
         fevent_->jet_pt_ ->push_back( (float) jets_->at(i).Pt() );   
         fevent_->jet_eta_->push_back( (float) jets_->at(i).Eta() );   
         fevent_->jet_phi_->push_back( (float) jets_->at(i).Phi() );   
         fevent_->jet_csv_->push_back( (float) jets_->at(i).CSV() );   
      } 
      fevent_->nJet20_=nJet20;
      fevent_->nBJet20T_=nBJet20T;
      fevent_->nBJet20M_=nBJet20M;
      fevent_->nBJet20L_=nBJet20L;
      fevent_->nJet30_=nJet30;
      fevent_->nBJet30T_=nBJet30T;
      fevent_->nBJet30M_=nBJet30M;
      fevent_->nBJet30L_=nBJet30L;

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
             //jets_->push_back(jet_);
             bool isFill=true;

             if(leptons_N>0&& fabs(leptons_->at(0).vec_.DeltaR(jet_.vec_))<0.4 ) isFill=false;
             if(leptons_N>1&& fabs(leptons_->at(1).vec_.DeltaR(jet_.vec_))<0.4 ) isFill=false;

             if(isFill) jetsPuppi_->push_back(jet_);
          }
      }
      std::sort(jetsPuppi_->begin(), jetsPuppi_->end(), compByCSVJet);
      //std::sort(jetsPuppi_->begin(), jetsPuppi_->end(), compByPtJet);

//////////////
      int nBJet20TPuppi=0, nBJet20MPuppi=0, nBJet20LPuppi=0, nJet20Puppi=0;
      int nBJet30TPuppi=0, nBJet30MPuppi=0, nBJet30LPuppi=0, nJet30Puppi=0;
      for(int i=0;i<jetsPuppi_->size();i++)
      {
         if(jetsPuppi_->at(i).CSV()>0.970) nBJet20T++; // CSVT 0.970
         if(jetsPuppi_->at(i).CSV()>0.890) nBJet20M++; // CSVM 0.890 
         if(jetsPuppi_->at(i).CSV()>0.605) nBJet20L++; // CSVL 0.605 
         nJet20Puppi++;
         if(jetsPuppi_->at(i).Pt()>30)
         {
            if(jetsPuppi_->at(i).CSV()>0.970) nBJet30T++; // CSVT 0.970
            if(jetsPuppi_->at(i).CSV()>0.890) nBJet30M++; // CSVM 0.890 
            if(jetsPuppi_->at(i).CSV()>0.605) nBJet30L++; // CSVL 0.605 
            nJet30Puppi++;
         }
         fevent_->jetPuppi_pt_ ->push_back( (float) jetsPuppi_->at(i).Pt() );   
         fevent_->jetPuppi_eta_->push_back( (float) jetsPuppi_->at(i).Eta() );   
         fevent_->jetPuppi_phi_->push_back( (float) jetsPuppi_->at(i).Phi() );   
         fevent_->jetPuppi_csv_->push_back( (float) jetsPuppi_->at(i).CSV() );   
      } 
      fevent_->nJet20Puppi_=nJet20Puppi;
      fevent_->nBJet20TPuppi_=nBJet20TPuppi;
      fevent_->nBJet20MPuppi_=nBJet20MPuppi;
      fevent_->nBJet20LPuppi_=nBJet20LPuppi;

      fevent_->nJet30Puppi_=nJet30Puppi;
      fevent_->nBJet30TPuppi_=nBJet30TPuppi;
      fevent_->nBJet30MPuppi_=nBJet30MPuppi;
      fevent_->nBJet30LPuppi_=nBJet30LPuppi;
////////////////////////

      if(isMC_)
      {
         fevent_->isMM_ = ((int) (genTtbarLeptonDecay%100)==2); 
         fevent_->isEE_ = ((int) (genTtbarLeptonDecay%10000)==200);
         fevent_->isEM_ = ((int) (genTtbarLeptonDecay%10000)==101);
         
         int category =0; // 0:tt+lf, 1:tt+cc, 2:tt+bb, 3:tt+2b, 4:tt+b  
         int categorytb =0;
         if(genTtbarId%100 == 0)                   category=0;
         else if( ((int)(genTtbarId%100)/10) == 4) category=1;
         else if( ((int)(genTtbarId%100)) == 51)   category=4;
         else if( ((int)(genTtbarId%100)) == 52)   category=3;
         else if( ((int)(genTtbarId%100)) == 53)   category=2;
         else if( ((int)(genTtbarId%100)) == 54)   category=2;
         else if( ((int)(genTtbarId%100)) == 55)   category=2;
         categorytb=(int)(genTtbarId/100);

         fevent_->Category_ =  category;
         fevent_->Categorytb_ =  categorytb;
         fevent_->NgenJet_ = NgenJet;

         fevent_->nTrueInteraction_= nTrueInteraction;
         fevent_->pdfWeightId1_    = (float) pdfWeightId1;
         fevent_->pdfWeightId2_    = (float) pdfWeightId2;
         fevent_->pdfWeightQ_      = (float) pdfWeightQ  ;
         fevent_->pdfWeightX1_     = (float) pdfWeightX1 ;
         fevent_->pdfWeightX2_     =(float) pdfWeightX2 ;
         fevent_->puWeight_        =(float) puWeight    ; 

         fevent_->genWeight_        =(float) genWeight/fabs(genWeight)    ; 
         fevent_->lheWeight_        =(float) lheWeight/fabs(lheWeight)    ; 
      }
//////////
      tree_->Fill();

      fevent2_->copy(fevent_);

      bool ll_lep1    = ((fevent_->ll_lep1_pt_>20) && (abs(fevent_->ll_lep1_eta_)<2.4));
      bool ll_lep2    = ((fevent_->ll_lep2_pt_>20) && (abs(fevent_->ll_lep2_eta_)<2.4));
      bool ll_Iso12   = ((fabs(fevent_->ll_lep1_iso_)<0.12) && (fabs(fevent_->ll_lep2_iso_)<0.12));
      bool ll_op      = ( fevent_->ll_lep1_q_*fevent_->ll_lep2_q_<0);
     
      bool ll_lepIso = ( ll_lep1  &&  ll_lep2  &&  ll_op  && (fevent_->ll_zmass_>20)  &&  ll_Iso12  ) ;
      bool ll_zmass = ( fabs(91.2-fevent_->ll_zmass_)>15 );
      bool em_zmass = true;
      bool metcut = fevent_->metNoHF_>40.;
      bool mm=(abs(fevent_->ll_lep1_pdgid_)==13&&abs(fevent_->ll_lep2_pdgid_)==13);
      bool ee=(abs(fevent_->ll_lep1_pdgid_)==11&&abs(fevent_->ll_lep2_pdgid_)==11);
      bool em=((abs(fevent_->ll_lep1_pdgid_)==11&&abs(fevent_->ll_lep2_pdgid_)==13) || (abs(fevent_->ll_lep1_pdgid_)==13&&abs(fevent_->ll_lep2_pdgid_)==11));

      bool mm_trigger = ( (fevent_->HLTMu17TrkIsoVVLMu8TrkIsoVVLDZ_==1) || (fevent_->HLTMu17TrkIsoVVLTkMu8TrkIsoVVLDZ_==1) );
      bool ee_trigger = ( (fevent_->HLTEle17Ele12CaloIdLTrackIdLIsoVLDZ_==1) );
      bool em_trigger=  ( (fevent_->HLTMu17TrkIsoVVLEle12CaloIdLTrackIdLIsoVL_==1) || (fevent_->HLTMu8TrkIsoVVLEle17CaloIdLTrackIdLIsoVL_==1) );

      if(
         (   ( ((mm_trigger && mm) || (ee_trigger && ee) ) && ll_lepIso && ll_zmass && metcut) 
          || ( em_trigger && em && ll_lepIso)  
         )  
         && (nJet30 >=4)
      )
      {
          tree2_->Fill();
      }

///////////////////////
   }
}
