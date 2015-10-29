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
   TTree *tree3_ = new TTree(Form("myresult3"),"");
   TTree *tree4_ = new TTree(Form("myresult4"),"");
   FlatTree* fevent_ = new FlatTree();
   FlatTree* fevent2_ = new FlatTree();
   FlatTree* fevent3_ = new FlatTree();
   FlatTree* fevent4_ = new FlatTree();
   fevent_->book(tree_);
   fevent2_->book(tree2_);
   fevent3_->book(tree3_);
   fevent4_->book(tree4_);

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

   fevent_->filterRECO_      =  filterRECO;
   fevent_->filterTrigELEL_  =  filterTrigELEL;
   fevent_->filterTrigMUEL_  =  filterTrigMUEL;
   fevent_->filterTrigMUMU_  =  filterTrigMUMU;
   fevent_->partonTopChannel_=  partonTopChannel;

   fevent_->nGoodPV_ =  nGoodPV;
   fevent_->nPV_     =  nPV;

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
             if(electrons_mvaTight->at(i)==1) id=1;
             //if(electrons_idMedium->at(i)==1) id=2;
             //if(electrons_idTight->at(i)==1) id=3;


             Lepton el_(pt,eta,phi,mass, relIso03, q,id,q*11,MCmatched);
             if(electrons_mvaTight->at(i)==1) leptons_->push_back(el_);
             if(electrons_mvaTight->at(i)==1) electrons_->push_back(el_);
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
         if(isMC_)
         {
            float lep1weight=1.,lep2weight=1.;
            if(abs(fevent_->ll_lep1_pdgid_)==13) lep1weight= SF_muon( fevent_->ll_lep1_pt_, fevent_->ll_lep1_eta_); 
            if(abs(fevent_->ll_lep1_pdgid_)==11) lep1weight= SF_electron( fevent_->ll_lep1_pt_, fevent_->ll_lep1_eta_);
            if(abs(fevent_->ll_lep2_pdgid_)==13) lep2weight= SF_muon( fevent_->ll_lep2_pt_, fevent_->ll_lep2_eta_); 
            if(abs(fevent_->ll_lep2_pdgid_)==11) lep2weight= SF_electron( fevent_->ll_lep2_pt_, fevent_->ll_lep2_eta_);
            
            fevent_->leptonweight_ = lep1weight*lep2weight;
         }
      }
////////////////////////////////////
//PFJET
//get_csv_wgt( std::vector<double> jetPts, std::vector<double> jetEtas, std::vector<double> jetCSVs, std::vector<int> jetFlavors, int iSys, double &csvWgtHF, double &csvWgtLF, double &csvWgtCF )
      if(isMC_)
      {
          double csvWgtHF, csvWgtLF, csvWgtCF;
          fevent_->CSV_Center_      =get_csv_wgt(jets_pt,jets_eta,jets_CSVInclV2,jets_partonFlavour, 0,csvWgtHF, csvWgtLF, csvWgtCF);
          fevent_->JES_Up_          =get_csv_wgt(jets_pt,jets_eta,jets_CSVInclV2,jets_partonFlavour, 7,csvWgtHF, csvWgtLF, csvWgtCF);
          fevent_->JES_Down_        =get_csv_wgt(jets_pt,jets_eta,jets_CSVInclV2,jets_partonFlavour, 8,csvWgtHF, csvWgtLF, csvWgtCF);
          fevent_->LF_Up_           =get_csv_wgt(jets_pt,jets_eta,jets_CSVInclV2,jets_partonFlavour, 9,csvWgtHF, csvWgtLF, csvWgtCF);
          fevent_->LF_Down_         =get_csv_wgt(jets_pt,jets_eta,jets_CSVInclV2,jets_partonFlavour,10,csvWgtHF, csvWgtLF, csvWgtCF);
          fevent_->HF_Up_           =get_csv_wgt(jets_pt,jets_eta,jets_CSVInclV2,jets_partonFlavour,11,csvWgtHF, csvWgtLF, csvWgtCF);
          fevent_->HF_Down_         =get_csv_wgt(jets_pt,jets_eta,jets_CSVInclV2,jets_partonFlavour,12,csvWgtHF, csvWgtLF, csvWgtCF);
          fevent_->HF_Stats1_Up_    =get_csv_wgt(jets_pt,jets_eta,jets_CSVInclV2,jets_partonFlavour,13,csvWgtHF, csvWgtLF, csvWgtCF);
          fevent_->HF_Stats1_Down_  =get_csv_wgt(jets_pt,jets_eta,jets_CSVInclV2,jets_partonFlavour,14,csvWgtHF, csvWgtLF, csvWgtCF);
          fevent_->HF_Stats2_Up_    =get_csv_wgt(jets_pt,jets_eta,jets_CSVInclV2,jets_partonFlavour,15,csvWgtHF, csvWgtLF, csvWgtCF);
          fevent_->HF_Stats2_Down_  =get_csv_wgt(jets_pt,jets_eta,jets_CSVInclV2,jets_partonFlavour,16,csvWgtHF, csvWgtLF, csvWgtCF);
          fevent_->LF_Stats1_Up_    =get_csv_wgt(jets_pt,jets_eta,jets_CSVInclV2,jets_partonFlavour,17,csvWgtHF, csvWgtLF, csvWgtCF);
          fevent_->LF_Stats1_Down_  =get_csv_wgt(jets_pt,jets_eta,jets_CSVInclV2,jets_partonFlavour,18,csvWgtHF, csvWgtLF, csvWgtCF);
          fevent_->LF_Stats2_Up_    =get_csv_wgt(jets_pt,jets_eta,jets_CSVInclV2,jets_partonFlavour,19,csvWgtHF, csvWgtLF, csvWgtCF);
          fevent_->LF_Stats2_Down_  =get_csv_wgt(jets_pt,jets_eta,jets_CSVInclV2,jets_partonFlavour,20,csvWgtHF, csvWgtLF, csvWgtCF);
          fevent_->Charm_Err1_Up_   =get_csv_wgt(jets_pt,jets_eta,jets_CSVInclV2,jets_partonFlavour,21,csvWgtHF, csvWgtLF, csvWgtCF);
          fevent_->Charm_Err1_Down_ =get_csv_wgt(jets_pt,jets_eta,jets_CSVInclV2,jets_partonFlavour,22,csvWgtHF, csvWgtLF, csvWgtCF);
          fevent_->Charm_Err2_Up_   =get_csv_wgt(jets_pt,jets_eta,jets_CSVInclV2,jets_partonFlavour,23,csvWgtHF, csvWgtLF, csvWgtCF);
          fevent_->Charm_Err2_Down_ =get_csv_wgt(jets_pt,jets_eta,jets_CSVInclV2,jets_partonFlavour,24,csvWgtHF, csvWgtLF, csvWgtCF);
      }

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
         fevent_->genWeightId1_    = (float) genWeightId1;
         fevent_->genWeightId2_    = (float) genWeightId2;
         fevent_->genWeightQ_      = (float) genWeightQ  ;
         fevent_->genWeightX1_     = (float) genWeightX1 ;
         fevent_->genWeightX2_     =(float) genWeightX2 ;
         fevent_->puWeight_        =(float) puWeight    ; 

         fevent_->genWeight_        =(float) genWeight/fabs(genWeight)    ; 
         fevent_->lheWeight_        =(float) lheWeight/fabs(lheWeight)    ; 
      }
//////////
      tree_->Fill();

      fevent2_->copy(fevent_);
      fevent3_->copy(fevent_);
      fevent4_->copy(fevent_);

      bool ll_lep1    = ((fevent_->ll_lep1_pt_>20) && (abs(fevent_->ll_lep1_eta_)<2.4));
      bool ll_lep2    = ((fevent_->ll_lep2_pt_>20) && (abs(fevent_->ll_lep2_eta_)<2.4));
      bool ll_Iso12   = ((fabs(fevent_->ll_lep1_iso_)<0.12) && (fabs(fevent_->ll_lep2_iso_)<0.12));
      bool ll_op      = ( fevent_->ll_lep1_q_*fevent_->ll_lep2_q_<0);
     
      bool ll_lepIso = ( ll_lep1  &&  ll_lep2  &&  ll_op  && (fevent_->ll_zmass_>20)  &&  ll_Iso12  ) ;
      bool ll_zmass = ( fabs(91.2-fevent_->ll_zmass_)>15 );
      bool em_zmass = true;
      bool metcut = fevent_->metNoHF_>40.;
      bool metPuppicut = fevent_->metPuppi_>40.;
      bool mm=(abs(fevent_->ll_lep1_pdgid_)==13&&abs(fevent_->ll_lep2_pdgid_)==13);
      bool ee=(abs(fevent_->ll_lep1_pdgid_)==11&&abs(fevent_->ll_lep2_pdgid_)==11);
      bool em=((abs(fevent_->ll_lep1_pdgid_)==11&&abs(fevent_->ll_lep2_pdgid_)==13) || (abs(fevent_->ll_lep1_pdgid_)==13&&abs(fevent_->ll_lep2_pdgid_)==11));

                         
      bool ee_trigger = (filterTrigELEL==1 ); 
      bool em_trigger = (filterTrigMUEL==1 );
      bool mm_trigger=  (filterTrigMUMU==1 );

      if( (mm_trigger && mm) || (ee_trigger && ee) || (em_trigger && em) && ll_lep1 && ll_lep2 )
      //if( (mm_trigger && mm) || (ee_trigger && ee) || (em_trigger && em) && ll_lepIso )
      {
          tree2_->Fill();
      }
      if(
         (   ( ((mm_trigger && mm) || (ee_trigger && ee) ) && ll_lepIso && ll_zmass && metcut) 
          || ( em_trigger && em && ll_lepIso)  
         )  
         && (nJet30 >=4)
      )
      {
          tree3_->Fill();
      }
      if(
         (   ( ((mm_trigger && mm) || (ee_trigger && ee) ) && ll_lepIso && ll_zmass && metPuppicut) 
          || ( em_trigger && em && ll_lepIso)  
         )  
         && (nJet30Puppi >=4)
      )
      {
          tree4_->Fill();
      }



///////////////////////
   }
}
float CATNtuple::SF_muon(float pt, float eta)
{
   if(pt<30 )
   {
     if(fabs(eta)<1) return 1.;
     else            return 1.;
   }
   else {
     if(fabs(eta)<1) return 1.;
     else            return 1.;
   }    
}
float CATNtuple::SF_electron(float pt, float eta)
{
   if(pt<30 )
   {
     if(fabs(eta)<1) return 1.;
     else            return 1.;
   }
   else {
     if(fabs(eta)<1) return 1.;
     else            return 1.;
   } 
}

//float CATNtuple::get_csv_wgt( std::vector<double> jetPts, std::vector<double> jetEtas, std::vector<double> jetCSVs, std::vector<int> jetFlavors, 
float CATNtuple::get_csv_wgt( std::vector<float>* jetPts, std::vector<float>* jetEtas, std::vector<float>* jetCSVs, std::vector<float>* jetFlavors, 
                                  int iSys, double &csvWgtHF, double &csvWgtLF, double &csvWgtCF ){
  int iSysHF = 0;
  switch(iSys){
  case 7:  iSysHF=1; break; //JESUp
  case 8:  iSysHF=2; break; //JESDown
  case 9:  iSysHF=3; break; //LFUp
  case 10: iSysHF=4; break; //LFDown
  case 13: iSysHF=5; break; //Stats1Up
  case 14: iSysHF=6; break; //Stats1Down
  case 15: iSysHF=7; break; //Stats2Up
  case 16: iSysHF=8; break; //Stats2Down
  default : iSysHF = 0; break; //NoSys
  }

  int iSysC = 0;
  switch(iSys){
  case 21: iSysC=1; break;
  case 22: iSysC=2; break;
  case 23: iSysC=3; break;
  case 24: iSysC=4; break;
  default : iSysC = 0; break;
  }

  int iSysLF = 0;
  switch(iSys){
  case 7:  iSysLF=1; break; //JESUp
  case 8:  iSysLF=2; break; //JESDown
  case 11: iSysLF=3; break; //HFUp
  case 12: iSysLF=4; break; //HFDown
  case 17: iSysLF=5; break; //Stats1Up
  case 18: iSysLF=6; break; //Stats1Down
  case 19: iSysLF=7; break; //Stats2Up
  case 20: iSysLF=8; break; //Stats2Down
  default : iSysLF = 0; break; //NoSys
  }

  double csvWgthf = 1.;
  double csvWgtC  = 1.;
  double csvWgtlf = 1.;

  for( int iJet=0; iJet<int(jetPts->size()); iJet++ ){

    double csv = jetCSVs->at(iJet);
    double jetPt = jetPts->at(iJet);
    double jetAbsEta = fabs(jetEtas->at(iJet));
    int flavor = (int) jetFlavors->at(iJet);

    int iPt = -1; int iEta = -1;
    if (jetPt >=19.99 && jetPt<30) iPt = 0;
    else if (jetPt >=30 && jetPt<40) iPt = 1;
    else if (jetPt >=40 && jetPt<60) iPt = 2;
    else if (jetPt >=60 && jetPt<100) iPt = 3;
    else if (jetPt >=100 && jetPt<160) iPt = 4;
    else if (jetPt >=160 && jetPt<10000) iPt = 5;
    else continue;

    if (jetAbsEta >=0 &&  jetAbsEta<0.8 ) iEta = 0;
    else if ( jetAbsEta>=0.8 && jetAbsEta<1.6 )  iEta = 1;
    else if ( jetAbsEta>=1.6 && jetAbsEta<2.41 ) iEta = 2;
    else continue;

    if (iPt < 0 || iEta < 0) std::cout << "Error, couldn't find Pt, Eta bins for this b-flavor jet, jetPt = " << jetPt << ", jetAbsEta = " << jetAbsEta << std::endl;

    if (abs(flavor) == 5 ){
      int useCSVBin = (csv>=0.) ? h_csv_wgt_hf[iSysHF][iPt]->FindBin(csv) : 1;
      double iCSVWgtHF = h_csv_wgt_hf[iSysHF][iPt]->GetBinContent(useCSVBin);
      if( iCSVWgtHF!=0 ) csvWgthf *= iCSVWgtHF;
    }
    else if( abs(flavor) == 4 ){
      int useCSVBin = (csv>=0.) ? c_csv_wgt_hf[iSysC][iPt]->FindBin(csv) : 1;
      double iCSVWgtC = c_csv_wgt_hf[iSysC][iPt]->GetBinContent(useCSVBin);
      if( iCSVWgtC!=0 ) csvWgtC *= iCSVWgtC;
    }
    else {
      if (iPt >=3) iPt=3;       /// [30-40], [40-60] and [60-10000] only 3 Pt bins for lf
      int useCSVBin = (csv>=0.) ? h_csv_wgt_lf[iSysLF][iPt][iEta]->FindBin(csv) : 1;
      double iCSVWgtLF = h_csv_wgt_lf[iSysLF][iPt][iEta]->GetBinContent(useCSVBin);
      if( iCSVWgtLF!=0 ) csvWgtlf *= iCSVWgtLF;
    }
  }

  double csvWgtTotal = csvWgthf * csvWgtC * csvWgtlf;

  csvWgtHF = csvWgthf;
  csvWgtLF = csvWgtlf;
  csvWgtCF = csvWgtC;

  return (float) csvWgtTotal;
}

