#define CATNtuple_cxx
#include "CATNtuple.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TLorentzVector.h>
#include <TH1F.h>
#include <TH2F.h>
#include <iostream>
#include <TH1D.h>
#include <TH2D.h>

#include "Jet.h"
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

//typedef std::vector<GenParticle> GenParticles;
//typedef GenParticles* GenParticlesP;
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


void CATNtuple::Loop(char *DecayMode)
{
   if (fChain == 0) return;
   Long64_t nentries = fChain->GetEntriesFast();
///////
   TTree *tree_ = new TTree(Form("ntuple%s",DecayMode),"");
   FlatTree* fevent_ = new FlatTree(true);
   fevent_->book(tree_);

   LeptonsP muons_;        muons_     = new Leptons;
   LeptonsP electrons_;    electrons_ = new Leptons;
   JetsP   jets_;         jets_      = new Jets;
   TLorentzVector jets[60];


///////
   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
////////
      fevent_->clear();

      fevent_->MET_     = met_pt->at(0);
      fevent_->METPHI_  = met_phi->at(0);
      fevent_->event_   = event; 
      fevent_->lumi_   = lumi; 
      fevent_->run_   = run; 


      //reconstructed level information
      muons_->clear();
      electrons_->clear();
      jets_->clear();
      for(int i=0;i<electrons_pt->size();i++)
      {
          if(electrons_pt->at(i)>20.0 && fabs(electrons_eta->at(i))<2.5) 
          {
             double x_ = electrons_pt->at(i)*TMath::Cos(electrons_phi->at(i));
             double y_ = electrons_pt->at(i)*TMath::Sin(electrons_phi->at(i));
             double z_ = electrons_pt->at(i)*sinh(electrons_eta->at(i));
             double e_ = TMath::Sqrt(x_*x_+y_*y_+z_*z_+electrons_m->at(i)*electrons_m->at(i));
             Lepton el_(TLorentzVector( x_,y_,z_,e_), electrons_relIso04->at(i), electrons_q->at(i) );
             electrons_->push_back(el_);
          }
      }
      std::sort(electrons_->begin(), electrons_->end(), compByPtLep);
      for(int i=0;i<muon_pt->size();i++)
      {
          if(muon_pt->at(i)>20.0 && fabs(muon_eta->at(i))<2.4) 
          {
             double x_ = muon_pt->at(i)*TMath::Cos(muon_phi->at(i));
             double y_ = muon_pt->at(i)*TMath::Sin(muon_phi->at(i));
             double z_ = muon_pt->at(i)*sinh(muon_eta->at(i));
             double e_ = TMath::Sqrt(x_*x_+y_*y_+z_*z_+muon_m->at(i)*muon_m->at(i));
             Lepton mu_(TLorentzVector( x_,y_,z_,e_), muon_relIso04->at(i), muon_q->at(i) );
             muons_->push_back(mu_);
          }
      }
      std::sort(muons_->begin(), muons_->end(), compByPtLep);

      for(int i=0;i<jets_pt->size();i++)
      {
          jets[i].SetPtEtaPhiM( jets_pt->at(i),  jets_eta->at(i),  jets_phi->at(i),jets_m->at(i));
         
          bool overlapMu=false, overlapEl=false;  // jet cleaning..
          for(int j=0;j<electrons_->size();j++ ) 
          if( std::abs( jets[i].DeltaR(electrons_->at(j).vec_) )< 0.5 ) overlapEl=true;
         
          for(int j=0;j<muons_->size();j++ )     
          if( std::abs( jets[i].DeltaR(muons_->at(j).vec_) )< 0.5 )     overlapMu=true;

          if(jets_pt->at(i)>30.0 && fabs(jets_eta->at(i))<2.5 && !overlapEl && !overlapMu)
          {

             double x_ = jets_pt->at(i)*TMath::Cos(jets_phi->at(i));
             double y_ = jets_pt->at(i)*TMath::Sin(jets_phi->at(i));
             double z_ = jets_pt->at(i)*sinh(jets_eta->at(i));
             double e_ = TMath::Sqrt(x_*x_+y_*y_+z_*z_+jets_m->at(i)*jets_m->at(i));
             Jet mu_(TLorentzVector( x_,y_,z_,e_), jets_CSVInclV2->at(i), jets_partonFlavour->at(i),0);
             jets_->push_back(mu_);
          }
      }
      std::sort(jets_->begin(), jets_->end(), compByCSVJet);

      bool precut = false;
      if(!strcmp(DecayMode, "MuMu")) precut = (muons_->size()>1);
      if(!strcmp(DecayMode, "ElEl")) precut = (electrons_->size()>1);
      if(!strcmp(DecayMode, "MuEl")) precut = (muons_->size()>0 && electrons_->size()>0);

     // dilepton selection
      if(precut)
      {
          bool accept = false;
          TLorentzVector Z;
          int L1x=-1,L2x=-1;
          bool Zsel=false;
          if(!strcmp(DecayMode, "MuMu"))
          {
                for(int i=0;i<muons_->size()-1;i++ ) if(Zsel==false)
                for(int j=i+1;j<muons_->size();j++ ) if(Zsel==false)
                {
                   Z = ((muons_->at(i).vec_)+(muons_->at(j).vec_));
                   bool iso = ((muons_->at(i).Iso_<0.15) && (muons_->at(j).Iso_<0.15));
                   bool opp = (muons_->at(i).Q_*muons_->at(j).Q_<0) && (Z.M()>12.);
                   if(iso && opp) {   L1x=i; L2x=j; Zsel=true; break; }

                   //std::cout << "Zsel-loop,  Zmass="<< Z.M() << endl;
                }
          }
          if(!strcmp(DecayMode, "ElEl"))
          {
                for(int i=0;i<electrons_->size()-1;i++ ) if(Zsel==false)
                for(int j=i+1;j<electrons_->size();j++ ) if(Zsel==false)
                {
                   Z = ((electrons_->at(i).vec_)+(electrons_->at(j).vec_));
                   bool iso = ((electrons_->at(i).Iso_<0.15) && (electrons_->at(j).Iso_<0.15));
                   bool opp = (electrons_->at(i).Q_*electrons_->at(j).Q_<0) && (Z.M()>12.);
                   if(iso && opp) {   L1x=i; L2x=j; Zsel=true; break; }
                }
          }

          if(!strcmp(DecayMode, "MuEl"))
          {
                for(int i=0;i<muons_->size();i++ )     if(Zsel==false)
                for(int j=0;j<electrons_->size();j++ ) if(Zsel==false )
                {
                   Z = ((muons_->at(i).vec_)+(electrons_->at(j).vec_));
                   bool iso = ((muons_->at(i).Iso_<0.15) && (electrons_->at(j).Iso_<0.15));
                   bool opp = (muons_->at(i).Q_*electrons_->at(j).Q_<0) && (Z.M()>12.);
                   if(iso && opp) {   L1x=i; L2x=j; Zsel=true; break; }
                }
          }
          if( !Zsel && !strcmp(DecayMode, "MuMu"))
          {
              Z = ((muons_->at(0).vec_)+(muons_->at(1).vec_));
              L1x=0; L2x=1;
              Zsel=true;
              //std::cout << "!Zsel,  Zmass="<< Z.M() << endl;
          }
          if( !Zsel && !strcmp(DecayMode, "ElEl"))
          {
              Z = ((electrons_->at(0).vec_)+(electrons_->at(1).vec_));    
              L1x=0; L2x=1;
              Zsel=true;
          }   
          if( !Zsel && !strcmp(DecayMode, "MuEl"))
          {
              Z = ((muons_->at(0).vec_)+(electrons_->at(0).vec_));
              L1x=0; L2x=0;
              Zsel=true;
          }

          accept=true;
          //if(!strcmp(DecayMode, "MuMu"))
          //  std::cout << "opp : " << (muons_->at(L1x).Q_*muons_->at(L2x).Q_<0)<<", Iso1: "<< muons_->at(L1x).Iso_ << ", Pt1: " << muons_->at(L1x).Pt() << endl;

          if(!strcmp(DecayMode, "MuMu")) 
          {
               fevent_->lep1_pt_= muons_->at(L1x).Pt();
               fevent_->lep1_eta_= muons_->at(L1x).Eta();
               fevent_->lep1_relIso_= muons_->at(L1x).Iso_;
               fevent_->lep1_Q_= muons_->at(L1x).Q_;
               fevent_->lep2_pt_= muons_->at(L2x).Pt();
               fevent_->lep2_eta_= muons_->at(L2x).Eta();
               fevent_->lep2_relIso_= muons_->at(L2x).Iso_;
               fevent_->lep2_Q_= muons_->at(L2x).Q_;
          }
          if(!strcmp(DecayMode, "ElEl")){
               fevent_->lep1_pt_= electrons_->at(L1x).Pt();
               fevent_->lep1_eta_= electrons_->at(L1x).Eta();
               fevent_->lep1_relIso_= electrons_->at(L1x).Iso_;
               fevent_->lep1_Q_= electrons_->at(L1x).Q_;
               fevent_->lep2_pt_= electrons_->at(L2x).Pt();
               fevent_->lep2_eta_= electrons_->at(L2x).Eta();
               fevent_->lep2_relIso_= electrons_->at(L2x).Iso_;
               fevent_->lep2_Q_= electrons_->at(L2x).Q_;
          }
          if(!strcmp(DecayMode, "MuEl")) { 
               fevent_->lep1_pt_= muons_->at(L1x).Pt();
               fevent_->lep1_eta_= muons_->at(L1x).Eta();
               fevent_->lep1_relIso_= muons_->at(L1x).Iso_;
               fevent_->lep1_Q_= muons_->at(L1x).Q_;
               fevent_->lep2_pt_= electrons_->at(L2x).Pt();
               fevent_->lep2_eta_= electrons_->at(L2x).Eta();
               fevent_->lep2_relIso_= electrons_->at(L2x).Iso_;
               fevent_->lep2_Q_= electrons_->at(L2x).Q_;
          }
          fevent_->ZMass_   = Z.M();

          ////////////
          //jet selection 
          int njet = jets_->size(), njet50=0;
          int jpt1=-99, jeta1=-99, jphi1=-99, jbtg1=-99;
          int jpt2=-99, jeta2=-99, jphi2=-99, jbtg2=-99;
          int jpt3=-99, jeta3=-99, jphi3=-99, jbtg3=-99;
          int jpt4=-99, jeta4=-99, jphi4=-99, jbtg4=-99;
          int nBtagT=0, nBtagM=0, nBtagL=0;
          int nBtagT50=0, nBtagM50=0, nBtagL50=0;
          for(int i=0;i<jets_->size();i++)
          {
              if(jets_->at(i).Pt()>50) njet50++;
              if(jets_->at(i).CSV()>0.898) nBtagT++; // CSVT 0.898 
              if(jets_->at(i).CSV()>0.679) nBtagM++; // CSVM 0.679 
              if(jets_->at(i).CSV()>0.244) nBtagL++; // CSVL 0.244 
              if(jets_->at(i).CSV()>0.898 && jets_->at(i).Pt()>50) nBtagT50++; // CSVT 0.898
              if(jets_->at(i).CSV()>0.679 && jets_->at(i).Pt()>50) nBtagM50++; // CSVM 0.679
              if(jets_->at(i).CSV()>0.244 && jets_->at(i).Pt()>50) nBtagL50++; // CSVL 0.244    
              if(i==0) { jpt1=jets_->at(i).Pt();jeta1=jets_->at(i).Eta();jphi1=jets_->at(i).Phi(); jbtg1=jets_->at(i).CSV(); }
              if(i==2) { jpt2=jets_->at(i).Pt();jeta2=jets_->at(i).Eta();jphi2=jets_->at(i).Phi(); jbtg2=jets_->at(i).CSV(); }
              if(i==2) { jpt3=jets_->at(i).Pt();jeta3=jets_->at(i).Eta();jphi3=jets_->at(i).Phi(); jbtg3=jets_->at(i).CSV(); }
              if(i==3) { jpt4=jets_->at(i).Pt();jeta4=jets_->at(i).Eta();jphi4=jets_->at(i).Phi(); jbtg4=jets_->at(i).CSV(); }
          }
          fevent_->nJet30_  = njet;
          fevent_->nJet50_  = njet50;
          fevent_->nbJet30L_= nBtagL; 
          fevent_->nbJet30M_= nBtagM; 
          fevent_->nbJet30T_= nBtagT; 
          fevent_->nbJet50L_= nBtagL50;
          fevent_->nbJet50M_= nBtagM50;
          fevent_->nbJet50T_= nBtagT50;
          fevent_->jet1_pt_=jpt1; fevent_->jet1_eta_=jeta1; fevent_->jet1_phi_=jphi1; fevent_->jet1_bTag_=jbtg1;
          fevent_->jet2_pt_=jpt2; fevent_->jet2_eta_=jeta2; fevent_->jet2_phi_=jphi2; fevent_->jet2_bTag_=jbtg2;
          fevent_->jet3_pt_=jpt3; fevent_->jet3_eta_=jeta3; fevent_->jet3_phi_=jphi3; fevent_->jet3_bTag_=jbtg3;
          fevent_->jet4_pt_=jpt4; fevent_->jet4_eta_=jeta4; fevent_->jet4_phi_=jphi4; fevent_->jet4_bTag_=jbtg4;

      }//precut


      //generate information
      //gentop
      fevent_->gentop_lep1_pt_=gentop_lepton1_pt->at(0);
      fevent_->gentop_lep1_eta_=gentop_lepton1_eta->at(0);
      fevent_->gentop_lep2_pt_=gentop_lepton2_pt->at(0);
      fevent_->gentop_lep2_eta_=gentop_lepton2_eta->at(0);
 
      fevent_->gentop_NJets_   = gentop_NJets->at(0); 
      fevent_->gentop_NJets10_   = gentop_NJets10->at(0); 
      fevent_->gentop_NJets20_   = gentop_NJets20->at(0); 
      fevent_->gentop_NJets25_   = gentop_NJets25->at(0); 
      fevent_->gentop_NJets30_   = gentop_NJets30->at(0); 
      fevent_->gentop_NJets40_   = gentop_NJets40->at(0); 
      fevent_->gentop_NaddJets20_   = gentop_NaddJets20->at(0); 
      fevent_->gentop_NaddJets40_   = gentop_NaddJets40->at(0); 
      fevent_->gentop_NaddbJets_   = gentop_NaddbJets->at(0); 
      fevent_->gentop_NaddbJets20_   = gentop_NaddbJets20->at(0); 
      fevent_->gentop_NaddbJets40_   = gentop_NaddbJets40->at(0); 
      fevent_->gentop_NaddbQuarks20_   = gentop_NaddbQuarks20->at(0); 
      fevent_->gentop_NaddbQuarks40_   = gentop_NaddbQuarks40->at(0); 
      fevent_->gentop_NbJets_   = gentop_NbJets->at(0); 
      fevent_->gentop_NbJets20_   = gentop_NbJets20->at(0); 
      fevent_->gentop_NbJets25_   = gentop_NbJets25->at(0); 
      fevent_->gentop_NbJets30_   = gentop_NbJets30->at(0); 
      fevent_->gentop_NbJets40_   = gentop_NbJets40->at(0); 
      fevent_->gentop_NbQuarks_   = gentop_NbQuarks->at(0); 
      fevent_->gentop_NbQuarks20_   = gentop_NbQuarks20->at(0); 
      fevent_->gentop_NbQuarks40_   = gentop_NbQuarks40->at(0); 
      fevent_->gentop_NbQuarksNoTop_   = gentop_NbQuarksNoTop->at(0); 
      fevent_->gentop_NbQuarksTop_   = gentop_NbQuarksTop->at(0); 
      fevent_->gentop_NcJets_   = gentop_NcJets->at(0); 
      fevent_->gentop_NcJets10_   = gentop_NcJets10->at(0); 
      fevent_->gentop_NcJets15_   = gentop_NcJets15->at(0); 
      fevent_->gentop_NcJets20_   = gentop_NcJets20->at(0); 
      fevent_->gentop_NcJets25_   = gentop_NcJets25->at(0); 
      fevent_->gentop_NcJets30_   = gentop_NcJets30->at(0); 
      fevent_->gentop_NcJets40_   = gentop_NcJets40->at(0); 
      fevent_->gentop_NcQuarks_   = gentop_NcQuarks->at(0); 
      fevent_->gentop_allHadronic_   = gentop_allHadronic->at(0); 
      fevent_->gentop_diLeptonicEleEle_   = gentop_diLeptonicEleEle->at(0); 
      fevent_->gentop_diLeptonicMuoEle_   = gentop_diLeptonicMuoEle->at(0); 
      fevent_->gentop_diLeptonicMuoMuo_   = gentop_diLeptonicMuoMuo->at(0); 
      fevent_->gentop_diLeptonicTauEle_   = gentop_diLeptonicTauEle->at(0); 
      fevent_->gentop_diLeptonicTauMuo_   = gentop_diLeptonicTauMuo->at(0); 
      fevent_->gentop_diLeptonicTauTau_   = gentop_diLeptonicTauTau->at(0); 
      fevent_->gentop_semiLeptonic_   = gentop_semiLeptonic->at(0); 



////////
      tree_->Fill();
///////
   }
}
