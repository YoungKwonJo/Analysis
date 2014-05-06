#define Event_cxx
#include "Event.h"
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
#include "TtFullLepKinSolver.C"
#include "FlatNtuple.h"

  typedef std::vector<int> ints;
  typedef std::vector<unsigned int> uints;
  typedef std::vector<double> doubles;
  typedef ints* intsP;
  typedef uints* uintsP;
  typedef doubles* doublesP;

  typedef std::vector<Lepton> Leptons;
  typedef Leptons* LeptonsP;

  bool compByPtLep(Lepton a, Lepton b)
  {
     return a.Pt() > b.Pt();
  };


void Event::Loop(char *Name,double weight,int isZ,int v,char* DecayMode,bool isMC, int totalEvents)
{

   const int u=5;//, v=5;
   double wei=1.;
   bool S[u], G[v];

   const char *ttNN[5] ={"_","bb","1b","cc","LF"};

///////////////////////////
/*   const float HFbinPt[] = {30.,40.,60.,100.,160.,10000};
   const float LFbinPt[] = {30.,40.,60.,10000};
   const float LFbinEta[] = {0.,0.8,1.6,2.4};

   const float HFbin[] ={0., 0.122,  0.244, 0.331, 0.418,0.505, 0.592,0.679,0.7228,0.7666,0.8104,0.8542,0.898,0.9184,0.9388,0.9592,0.9796,1.}; 
   const float LFbin[] ={0., 0.0488,0.0976,0.1464,0.1952,0.244, 0.331,0.418, 0.505, 0.592, 0.679, 0.752,0.825, 0.898, 0.949,1.};
   const int HFNbin = sizeof(HFbin)/sizeof(float) -1;
   const int LFNbin = sizeof(LFbin)/sizeof(float) -1;

   TH1F *hHF_CSV[5], *hLF_CSV[3][3];
   TH1F *hHF_CSVbF[5], *hLF_CSVHF[3][3];
   TH1F *hHF_CSVnbF[5], *hLF_CSVLF[3][3];
   for(int i=0;i<5;i++)
   {
      hHF_CSVbF[i] = new TH1F(Form("hHF_CSVbF_Pt%d_MC",i), Form("HF CSV bF Pt Bin %d MC",i), HFNbin, HFbin);
      hHF_CSVnbF[i] = new TH1F(Form("hHF_CSVnbF_Pt%d_MC",i), Form("HF CSV nonbF Pt Bin %d MC",i), HFNbin, HFbin);
      hHF_CSV[i]   = new TH1F(Form("hHF_CSV_Pt%d_data",i), Form("HF CSV Pt Bin %d  data",i), HFNbin, HFbin);
   }
   for(int i=0;i<3;i++) for(int j=0;j<3;j++)
   {
      hLF_CSVHF[i][j] = new TH1F(Form("hLF_CSVHF_Pt%d_Eta%d_MC",i,j), Form("LF CSVHF Pt Bin %d Eta Bin %d MC",i,j), LFNbin, LFbin );
      hLF_CSVLF[i][j] = new TH1F(Form("hLF_CSVLF_Pt%d_Eta%d_MC",i,j), Form("LF CSVLF Pt Bin %d Eta Bin %d MC",i,j), LFNbin, LFbin );
      hLF_CSV[i][j]   = new TH1F(Form("hLF_CSV_Pt%d_Eta%d_data",i,j), Form("LF CSV Pt Bin %d Eta Bin %d data",i,j), LFNbin, LFbin );
   }
*/
 //////////////////////////

   TLorentzVector muons[15], electrons[15], jets[30], genjets[50], genparticles[50], genjetsB[50], genjetsC[50];

//kin solution////////
    TLorentzVector met;
    double tmassbegin_= 100;
    double tmassend_  = 300;
    double tmassstep_ = 1;
    double myints[] = {30.7137,56.2880,23.0744,59.1015,24.9145};
    std::vector<double> nupars_ (myints, myints + sizeof(myints) / sizeof(int) );
    TtFullLepKinSolver* solver = new TtFullLepKinSolver(tmassbegin_, tmassend_, tmassstep_, nupars_);

   TTree *tree_ = new TTree("ntuple","");
   FlatNtuple* fevent_ = new FlatNtuple(isMC);
   fevent_->book(tree_);

////////////////////////
   LeptonsP muons_;        muons_ = new Leptons;
   LeptonsP electrons_;    electrons_ = new Leptons;
   JetsP jets_;            jets_ = new Jets; 

   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   int Testing =0;

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;

      //Testing++; if(Testing>1500) break;

      fevent_->clear();

      fevent_->run_ = run;
      fevent_->lumi_ = lumi;
      fevent_->event_ = event;

      if(isMC)
      {
           fevent_->puweight_ = puWeight;
           fevent_->puweightUp_ = puWeightUp;
           fevent_->puweightDw_ = puWeightDn;
      }
      fevent_->nVertex_ = nVertex;

      muons_->clear();
      electrons_->clear();
      jets_->clear();

//////////////////////////
// reconstructed level
      met.SetPtEtaPhiM(met_pt, 0,met_phi,0);

      int nLep=0;
      for(int i=0;i<electrons_pt->size();i++ )
      {
         if(electrons_type->at(i)>100 && electrons_mva->at(i)>0.5 && electrons_pt->at(i)>20. && abs(electrons_eta->at(i))<2.4) 
         {
            nLep++;
            double x_ = electrons_pt->at(i)*TMath::Cos(electrons_phi->at(i));
            double y_ = electrons_pt->at(i)*TMath::Sin(electrons_phi->at(i));
            double z_ = electrons_pt->at(i)*sinh(electrons_eta->at(i));
            double e_ = TMath::Sqrt(x_*x_+y_*y_+z_*z_+electrons_m->at(i)*electrons_m->at(i));
            Lepton el_(TLorentzVector( x_,y_,z_,e_), electrons_relIso->at(i), electrons_Q->at(i));   
            electrons_->push_back(el_); 
         }
         //std::cout << "electron"<< electrons_pt->size()  <<" : " <<  electrons_pt->at(i) << std::endl;
//         electrons[i].SetPtEtaPhiM( electrons_pt->at(i),  electrons_eta->at(i),  electrons_phi->at(i),0);
      }
      std::sort(electrons_->begin(), electrons_->end(), compByPtLep);

      for(int i=0;i<muons_pt->size();i++ )
      {

         if(muons_type->at(i)>9 && muons_pt->at(i)>20. && abs(muons_eta->at(i))<2.4) 
         {
            nLep++; 
            double x_ = muons_pt->at(i)*TMath::Cos(muons_phi->at(i));
            double y_ = muons_pt->at(i)*TMath::Sin(muons_phi->at(i));
            double z_ = muons_pt->at(i)*sinh(muons_eta->at(i));
            double e_ = TMath::Sqrt(x_*x_+y_*y_+z_*z_+muons_m->at(i)*muons_m->at(i));
            Lepton mu_(TLorentzVector( x_,y_,z_,e_), muons_relIso->at(i), muons_Q->at(i));
            muons_->push_back(mu_); 
         }
         //std::cout << "muon "<< muons_pt->size()  <<" : " <<  muons_pt->at(i) << std::endl;
//         muons[i].SetPtEtaPhiM( muons_pt->at(i),  muons_eta->at(i),  muons_phi->at(i),0);
      }

      std::sort(muons_->begin(), muons_->end(), compByPtLep);

      int njet =0, nBtagT=0, nBtagM=0, nBtagL=0;//, jidx[4];
      double csvweight=1., leptonweight=1.0;

      for(int i=0;i<jets_pt->size();i++ )
      {
         //std::cout << "jets"<< muons_pt->size()  <<" : " <<  jets_pt->at(i) << std::endl;
         jets[i].SetPtEtaPhiM( jets_pt->at(i),  jets_eta->at(i),  jets_phi->at(i),jets_m->at(i));

         bool overlapMu=false, overlapEl=false;  // jet cleaning..
         for(int j=0;j<electrons_->size();j++ ) 
         if( std::abs( jets[i].DeltaR(electrons_->at(j).vec_) )< 0.5 ) overlapEl=true;

         for(int j=0;j<muons_->size();j++ )     
         if( std::abs( jets[i].DeltaR(muons_->at(j).vec_) )< 0.5 )     overlapMu=true;

         if(jets_pt->at(i)>30 && abs(jets_eta->at(i))<2.5 && !overlapEl && !overlapMu)
         {
            njet++;
            double x_ = jets_pt->at(i)*TMath::Cos(jets_phi->at(i));
            double y_ = jets_pt->at(i)*TMath::Sin(jets_phi->at(i));
            double z_ = jets_pt->at(i)*sinh(jets_eta->at(i));
            double e_ = TMath::Sqrt(x_*x_+y_*y_+z_*z_+jets_m->at(i)*jets_m->at(i));
            Jet jet_(TLorentzVector( x_,y_,z_,e_),jets_bTag->at(i),jets_partonflavor->at(i));
            jets_->push_back(jet_);

            if(jets_bTag->at(i)>0.898) nBtagT++; // CSVT 0.898 
            if(jets_bTag->at(i)>0.679) nBtagM++; // CSVM 0.679 
            if(jets_bTag->at(i)>0.244) nBtagL++; // CSVL 0.244 
            
         }

      }
      std::sort(jets_->begin(), jets_->end(), compByCSVJet);
//////////////////////
//generated level
      if(isMC)
      {
          int gnjet20=0, gnjet30=0, gnjet40=0 ;
          for(int i=0;i<genJets_pt->size();i++ )
          {
             if( abs(genJets_eta->at(i))<2.5 )
             {
                if(genJets_pt->at(i)>20 ) gnjet20++;
                if(genJets_pt->at(i)>30 ) gnjet30++;
                if(genJets_pt->at(i)>40 ) gnjet40++;
             }
          
          }
          fevent_->gNJet20_=gnjet20;
          fevent_->gNJet30_=gnjet30;
          fevent_->gNJet40_=gnjet40;
      } 
///////////////////////
       bool precut = false;
      if(!strcmp(DecayMode, "MuMu")) precut = (muons_->size()>1);
      if(!strcmp(DecayMode, "ElEl")) precut = (electrons_->size()>1);
      if(!strcmp(DecayMode, "MuEl")) precut = (muons_->size()>0 && electrons_->size()>0);

      for(int j =0; j<v ; j++) G[j]=true;

////////////////////
// for TTBB signal definition
      if(isMC)
      {

          if(v==5)
          {
              
              bool visible = (nGenJet20 >= 4 && nGenbJet20 >=2 && genLep1_pt > 20 && genLep2_pt > 20 && abs( genLep1_eta ) < 2.4 && abs( genLep2_eta ) < 2.4);
              G[1] = visible && (nGenbJet20 >= 4);                                              // ttbar bb
              G[2] = visible && (nGenbJet20 >= 3) && !(nGenbJet20 >= 4);                        // ttbar 1b
              G[3] = visible && (nGencJet20 >= 2) && !(nGenbJet20 >= 4) && !(nGenbJet20 >= 3);  // ttbar cc
              G[4] = visible && !(nGencJet20 >= 2) && !(nGenbJet20 >= 4) && !(nGenbJet20 >= 3); // ttbar LF
              G[0] = !visible;                                                                  // ttbar others
 
          }
          for(int j =v-1; j>-1 ; j--)
          {
             //if(j>1 && G[j])cout << "G["<<j<<"] = " << G[j] << endl;
             if(G[j]) fevent_->ttIndex_ = j; 
          }
      }
//////////////////////////

      //std::cout << "precut = " << precut << endl;
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

          //std::cout << "Zsel = " << Zsel << endl;
          if(!Zsel) continue;
          if(isMC)
          {
             double lep1weight=1., lep2weight=1.;
             if(!strcmp(DecayMode, "MuMu"))
             { 
                 lep1weight = SF(muons_->at(L1x).Pt(),abs(muons_->at(L1x).Eta()), Muon);
                 lep2weight = SF(muons_->at(L2x).Pt(),abs(muons_->at(L2x).Eta()), Muon);
             }
             if(!strcmp(DecayMode, "ElEl"))
             {
                 lep1weight = SF(electrons_->at(L1x).Pt(),abs(electrons_->at(L1x).Eta()), Electron);
                 lep2weight = SF(electrons_->at(L2x).Pt(),abs(electrons_->at(L2x).Eta()), Electron);
             }
             if(!strcmp(DecayMode, "MuEl"))
             {
                 lep1weight = SF(muons_->at(L1x).Pt(),    abs(muons_->at(L1x).Eta()),     Muon    );
                 lep2weight = SF(electrons_->at(L2x).Pt(),abs(electrons_->at(L2x).Eta()), Electron);
             }
             leptonweight=lep1weight*lep2weight;
             //for ttbb analysis ////////////
//             csvweight = csvWgt->GetCSVweight(*jets_pt_,*jets_eta_,*jets_bTag_,*jets_partonflavor_,sysType::NA);
             csvweight = csvWgt->GetCSVweight(jets_, sysType::NA);
             //csvweight = csvWgt->GetCSVweight2(*jets_pt_,*jets_eta_,*jets_bTag_,*jets_partonflavor_);
             wei = weight*csvweight*puWeight*leptonweight;

             fevent_->csvweight_= csvweight;
             fevent_->leptonweight_= leptonweight;
          }

///////////////////////
// estimation for heavy and light flavor jet in MC(ttbar or zjets)/DATA
/*          if(njet==2) //&& nLep==2)
          {
             bool zveto   = ( Z.M()<(65.5 +3*met_pt/8) || Z.M()>(108.-met_pt/4) || Z.M()<(79.-3.*met_pt/4) ||  Z.M()>(99.+met_pt/2) );
             bool zselcut = (std::abs(Z.M()-91.) < 10.);
             bool highMET = (met_pt > 50.);
             bool lowMET  = (met_pt < 30.);
             bool HFtag   = (jets_->at(0).CSV_>0.679);
             bool LFtag   = (jets_->at(njet-1).CSV_<0.244);

             bool LFcut = !zveto && zselcut && lowMET && LFtag;
             bool HFcut = zveto && highMET && HFtag;

             int HF_i = -1, LF_i=-1, LF_j=-1; 
             for(int i=0;i<5;i++) if(HFbinPt[i] < jets_->at(1).Pt()) HF_i=i;
             for(int i=0;i<3;i++) if(LFbinPt[i] < jets_->at(0).Pt()) LF_i=i;
             for(int i=0;i<3;i++) if(LFbinEta[i]< jets_->at(0).Pt()) LF_j=i;

             double weightSF = weight*puWeight;
             if(HFcut && jets_->at(njet-1).CSV_>-1 && HF_i>-1)
             {
                if(!isMC)  hHF_CSV[HF_i]->Fill( jets_->at(njet-1).CSV_);
                else 
                {
                    if(abs(jets_->at(njet-1).flavor_) ==5) 
                         hHF_CSVbF[HF_i]->Fill( jets_->at(njet-1).CSV_, weightSF);
                    else hHF_CSVnbF[HF_i]->Fill( jets_->at(njet-1).CSV_, weightSF);
                }        
                //std::cout <<"HF test CSV SF" << endl;
             }
             if(LFcut && jets_->at(0).CSV_>-1 && LF_i>-1 && LF_j>-1)
             {
                 if(!isMC) hLF_CSV[LF_i][LF_j]->Fill( jets_->at(0).CSV_);
                 else 
                 {
                     if( abs(jets_->at(0).flavor_) ==4 || abs(jets_->at(0).flavor_) ==5)
                          hLF_CSVHF[LF_i][LF_j]->Fill( jets_->at(0).CSV_,weightSF);
                     else hLF_CSVLF[LF_i][LF_j]->Fill( jets_->at(0).CSV_,weightSF);
                 }
                 //std::cout <<"LF test CSV SF" << endl;
             }
          }          
*/
///////////////////////

//continue; // code for debug

          //std::cout << "Zmass = " << Z.M() << endl;
          if(isZ==2 && Z.M()<50) continue;
          if(isZ==1 && Z.M()>=50) continue;

          accept=true;
          //if(!strcmp(DecayMode, "MuMu"))
          //  std::cout << "opp : " << (muons_->at(L1x).Q_*muons_->at(L2x).Q_<0)<<", Iso1: "<< muons_->at(L1x).Iso_ << ", Pt1: " << muons_->at(L1x).Pt() << endl;

          if(!strcmp(DecayMode, "MuMu")) 
               S[0] = (muons_->at(L1x).Q_*muons_->at(L2x).Q_<0 && muons_->at(L1x).Iso_<0.15 && muons_->at(L2x).Iso_<0.15 
                        && Z.M()>12. && muons_->at(L1x).Pt()>20. && muons_->at(L2x).Pt()>20. && abs(muons_->at(L1x).Eta())<2.4 && abs(muons_->at(L2x).Eta())<2.4);
          if(!strcmp(DecayMode, "ElEl")) 
               S[0] = (electrons_->at(L1x).Q_*electrons_->at(L2x).Q_<0 && electrons_->at(L1x).Iso_<0.15 && electrons_->at(L2x).Iso_<0.15 
                        && Z.M()>12. && electrons_->at(L1x).Pt()>20. && electrons_->at(L2x).Pt()>20. && abs(electrons_->at(L1x).Eta())<2.4 && abs(electrons_->at(L2x).Eta())<2.4);
          if(!strcmp(DecayMode, "MuEl")) 
               S[0] = (electrons_->at(L2x).Q_*muons_->at(L1x).Q_<0 && electrons_->at(L2x).Iso_<0.15 && muons_->at(L1x).Iso_<0.15 
                        && Z.M()>12. && electrons_->at(L2x).Pt()>20. && muons_->at(L1x).Pt()>20. && abs(electrons_->at(L2x).Eta())<2.4 && abs(muons_->at(L1x).Eta())<2.4);

          if(strcmp(DecayMode, "MuEl")) S[1] = S[0] && (std::abs(91.2-Z.M())>15.0); else S[1] = S[0];
          if(strcmp(DecayMode, "MuEl")) S[2] = S[1] && (met_pt>30.);                else S[2] = S[1];
          S[3] = S[2] && (njet>3);
          S[4] = S[3] && (nBtagT>1);
     
          for(int i=0;i<u;i++) if(S[i]) fevent_->cutSteps_=i;

          fevent_->MET_     = met_pt;
          fevent_->ZMass_   = Z.M();
          fevent_->nJet30_  = njet;
          fevent_->nJet50_  = -10;
          fevent_->nbJet30T_= nBtagT; 
          fevent_->nbJet50T_= -10;

          if(!strcmp(DecayMode, "MuMu"))
          {
              fevent_->lep1_pt_    = muons_->at(L1x).Pt();
              fevent_->lep1_eta_   = muons_->at(L1x).Eta();
              fevent_->lep1_relIso_= muons_->at(L1x).Iso_;
              fevent_->lep2_pt_    = muons_->at(L2x).Pt();
              fevent_->lep2_eta_   = muons_->at(L2x).Eta();
              fevent_->lep2_relIso_= muons_->at(L2x).Iso_;
          }
          if(!strcmp(DecayMode, "ElEl"))
          {
              fevent_->lep1_pt_    = electrons_->at(L1x).Pt();
              fevent_->lep1_eta_   = electrons_->at(L1x).Eta();
              fevent_->lep1_relIso_= electrons_->at(L1x).Iso_;
              fevent_->lep2_pt_    = electrons_->at(L2x).Pt();
              fevent_->lep2_eta_   = electrons_->at(L2x).Eta();
              fevent_->lep2_relIso_= electrons_->at(L2x).Iso_;
          }
          if(!strcmp(DecayMode, "MuEl"))
          {
              fevent_->lep1_pt_    = muons_->at(L1x).Pt();
              fevent_->lep1_eta_   = muons_->at(L1x).Eta();
              fevent_->lep1_relIso_= muons_->at(L1x).Iso_;
              fevent_->lep2_pt_    = electrons_->at(L2x).Pt();
              fevent_->lep2_eta_   = electrons_->at(L2x).Eta();
              fevent_->lep2_relIso_= electrons_->at(L2x).Iso_;
          }

          if(njet>0) {  fevent_->jet1_pt_ =jets_->at(0).Pt();  fevent_->jet1_eta_=jets_->at(0).Eta();   
                        fevent_->jet1_csv_=jets_->at(0).CSV_; fevent_->jet1_flavor_=jets_->at(0).flavor_; }
          if(njet>1) {  fevent_->jet2_pt_ =jets_->at(1).Pt();  fevent_->jet2_eta_=jets_->at(1).Eta();   
                        fevent_->jet2_csv_=jets_->at(1).CSV_; fevent_->jet2_flavor_=jets_->at(1).flavor_; }
          if(njet>2) {  fevent_->jet3_pt_ =jets_->at(2).Pt();  fevent_->jet3_eta_=jets_->at(2).Eta();   
                        fevent_->jet3_csv_=jets_->at(2).CSV_; fevent_->jet3_flavor_=jets_->at(2).flavor_; }
          if(njet>3) {  fevent_->jet4_pt_ =jets_->at(3).Pt();  fevent_->jet4_eta_=jets_->at(3).Eta();   
                        fevent_->jet4_csv_=jets_->at(3).CSV_; fevent_->jet4_flavor_=jets_->at(3).flavor_; }

///////////////////////////////////////////
// for kin solution 
          if(njet>1) 
          {        
              double xconstraint=0, yconstraint=0;
              if(!strcmp(DecayMode, "MuMu"))
              {
                  xconstraint = muons_->at(L1x).Px()+muons_->at(L2x).Px()+ jets_->at(0).Px() + jets_->at(1).Px() +met.Px();
                  yconstraint = muons_->at(L1x).Py()+muons_->at(L2x).Py()+ jets_->at(0).Py() + jets_->at(1).Py() +met.Py();
                  solver->SetConstraints(xconstraint, yconstraint);
                  TtFullLepKinSolver::NeutrinoSolution nuSol= solver->getNuSolution( muons_->at(L1x).vec_, muons_->at(L2x).vec_, jets_->at(0).vec_, jets_->at(1).vec_);
                  TtFullLepKinSolver::NeutrinoSolution nuSol2= solver->getNuSolution( muons_->at(L1x).vec_, muons_->at(L2x).vec_, jets_->at(1).vec_, jets_->at(0).vec_);

                  if(nuSol.weight > nuSol2.weight && nuSol.weight>0)
                  {
                    if(muons_->at(L1x).Q_>0 && muons_->at(L2x).Q_<0)
                    {
                      fevent_->tMass_     = (muons_->at(L1x).vec_+jets_->at(0).vec_+nuSol.neutrino).M();
                      fevent_->tbarMass_  = (muons_->at(L2x).vec_+jets_->at(1).vec_+nuSol.neutrinoBar).M();;
                      fevent_->kinweight_ = nuSol.weight;
                      fevent_->kinNuEt_   = nuSol.neutrino.Et();
                      fevent_->kinNubarEt_= nuSol.neutrinoBar.Et();
                    }
                    else
                    {
                     fevent_->tbarMass_  = (muons_->at(L1x).vec_+jets_->at(0).vec_+nuSol.neutrino).M();
                     fevent_->tMass_     = (muons_->at(L2x).vec_+jets_->at(1).vec_+nuSol.neutrinoBar).M();
                     fevent_->kinweight_ = nuSol.weight; 
                     fevent_->kinNubarEt_= nuSol.neutrino.Et();
                     fevent_->kinNuEt_   = nuSol.neutrinoBar.Et();
                    }             
                  }
                  else if(nuSol.weight < nuSol2.weight && nuSol2.weight>0)
                  {
                    if(muons_->at(L1x).Q_>0 && muons_->at(L2x).Q_<0)
                    {
                      fevent_->tMass_     = (muons_->at(L1x).vec_+jets_->at(1).vec_+nuSol2.neutrino).M();
                      fevent_->tbarMass_  = (muons_->at(L2x).vec_+jets_->at(0).vec_+nuSol2.neutrinoBar).M();;
                      fevent_->kinweight_ = nuSol2.weight;
                      fevent_->kinNuEt_   = nuSol2.neutrino.Et();
                      fevent_->kinNubarEt_= nuSol2.neutrinoBar.Et();
                    }
                    else
                    {
                     fevent_->tbarMass_  = (muons_->at(L1x).vec_+jets_->at(1).vec_+nuSol2.neutrino).M();
                     fevent_->tMass_     = (muons_->at(L2x).vec_+jets_->at(0).vec_+nuSol2.neutrinoBar).M();
                     fevent_->kinweight_ = nuSol2.weight; 
                     fevent_->kinNubarEt_= nuSol2.neutrino.Et();
                     fevent_->kinNuEt_   = nuSol2.neutrinoBar.Et();
                    }
                  }     
              }// close() for if(MuMu)
              if(!strcmp(DecayMode, "ElEl"))
              {
                  xconstraint = electrons_->at(L1x).Px()+electrons_->at(L2x).Px()+ jets_->at(0).Px() + jets_->at(1).Px() +met.Px();
                  yconstraint = electrons_->at(L1x).Py()+electrons_->at(L2x).Py()+ jets_->at(0).Py() + jets_->at(1).Py() +met.Py();
                  solver->SetConstraints(xconstraint, yconstraint);
                  TtFullLepKinSolver::NeutrinoSolution nuSol= solver->getNuSolution( electrons_->at(L1x).vec_, electrons_->at(L2x).vec_, jets_->at(0).vec_, jets_->at(1).vec_);
                  TtFullLepKinSolver::NeutrinoSolution nuSol2= solver->getNuSolution( electrons_->at(L1x).vec_, electrons_->at(L2x).vec_, jets_->at(1).vec_, jets_->at(0).vec_);

                  if(nuSol.weight > nuSol2.weight && nuSol.weight>0)
                  {
                    if(electrons_->at(L1x).Q_>0 && electrons_->at(L2x).Q_<0)
                    {
                      fevent_->tMass_     = (electrons_->at(L1x).vec_+jets_->at(0).vec_+nuSol.neutrino).M();
                      fevent_->tbarMass_  = (electrons_->at(L2x).vec_+jets_->at(1).vec_+nuSol.neutrinoBar).M();;
                      fevent_->kinweight_ = nuSol.weight;
                      fevent_->kinNuEt_   = nuSol.neutrino.Et();
                      fevent_->kinNubarEt_= nuSol.neutrinoBar.Et();
                    }
                    else
                    {
                     fevent_->tbarMass_  = (electrons_->at(L1x).vec_+jets_->at(0).vec_+nuSol.neutrino).M();
                     fevent_->tMass_     = (electrons_->at(L2x).vec_+jets_->at(1).vec_+nuSol.neutrinoBar).M();
                     fevent_->kinweight_ = nuSol.weight; 
                     fevent_->kinNubarEt_= nuSol.neutrino.Et();
                     fevent_->kinNuEt_   = nuSol.neutrinoBar.Et();
                    }             
                  }
                  else if(nuSol.weight < nuSol2.weight && nuSol2.weight>0)
                  {
                    if(electrons_->at(L1x).Q_>0 && electrons_->at(L2x).Q_<0)
                    {
                      fevent_->tMass_     = (electrons_->at(L1x).vec_+jets_->at(1).vec_+nuSol2.neutrino).M();
                      fevent_->tbarMass_  = (electrons_->at(L2x).vec_+jets_->at(0).vec_+nuSol2.neutrinoBar).M();;
                      fevent_->kinweight_ = nuSol2.weight;
                      fevent_->kinNuEt_   = nuSol2.neutrino.Et();
                      fevent_->kinNubarEt_= nuSol2.neutrinoBar.Et();
                    }
                    else
                    {
                     fevent_->tbarMass_  = (electrons_->at(L1x).vec_+jets_->at(1).vec_+nuSol2.neutrino).M();
                     fevent_->tMass_     = (electrons_->at(L2x).vec_+jets_->at(0).vec_+nuSol2.neutrinoBar).M();
                     fevent_->kinweight_ = nuSol2.weight; 
                     fevent_->kinNubarEt_= nuSol2.neutrino.Et();
                     fevent_->kinNuEt_   = nuSol2.neutrinoBar.Et();
                    }
                  }     
              }// close() for if(ElEl)
              if(!strcmp(DecayMode, "MuEl"))
              {
                  xconstraint = muons_->at(L1x).Px()+electrons_->at(L2x).Px()+ jets_->at(0).Px() + jets_->at(1).Px() +met.Px();
                  yconstraint = muons_->at(L1x).Py()+electrons_->at(L2x).Py()+ jets_->at(0).Py() + jets_->at(1).Py() +met.Py();
                  solver->SetConstraints(xconstraint, yconstraint);
                  TtFullLepKinSolver::NeutrinoSolution nuSol= solver->getNuSolution( muons_->at(L1x).vec_, electrons_->at(L2x).vec_, jets_->at(0).vec_, jets_->at(1).vec_);
                  TtFullLepKinSolver::NeutrinoSolution nuSol2= solver->getNuSolution( muons_->at(L1x).vec_, electrons_->at(L2x).vec_, jets_->at(1).vec_, jets_->at(0).vec_);

                  if(nuSol.weight > nuSol2.weight && nuSol.weight>0)
                  {
                    if(muons_->at(L1x).Q_>0 && electrons_->at(L2x).Q_<0)
                    {
                      fevent_->tMass_     = (muons_->at(L1x).vec_+jets_->at(0).vec_+nuSol.neutrino).M();
                      fevent_->tbarMass_  = (electrons_->at(L2x).vec_+jets_->at(1).vec_+nuSol.neutrinoBar).M();;
                      fevent_->kinweight_ = nuSol.weight;
                      fevent_->kinNuEt_   = nuSol.neutrino.Et();
                      fevent_->kinNubarEt_= nuSol.neutrinoBar.Et();
                    }
                    else
                    {
                     fevent_->tbarMass_  = (muons_->at(L1x).vec_+jets_->at(0).vec_+nuSol.neutrino).M();
                     fevent_->tMass_     = (electrons_->at(L2x).vec_+jets_->at(1).vec_+nuSol.neutrinoBar).M();
                     fevent_->kinweight_ = nuSol.weight; 
                     fevent_->kinNubarEt_= nuSol.neutrino.Et();
                     fevent_->kinNuEt_   = nuSol.neutrinoBar.Et();
                    }             
                  }
                  else if(nuSol.weight < nuSol2.weight && nuSol2.weight>0)
                  {
                    if(muons_->at(L1x).Q_>0 && electrons_->at(L2x).Q_<0)
                    {
                      fevent_->tMass_     = (muons_->at(L1x).vec_+jets_->at(1).vec_+nuSol2.neutrino).M();
                      fevent_->tbarMass_  = (electrons_->at(L2x).vec_+jets_->at(0).vec_+nuSol2.neutrinoBar).M();;
                      fevent_->kinweight_ = nuSol2.weight;
                      fevent_->kinNuEt_   = nuSol2.neutrino.Et();
                      fevent_->kinNubarEt_= nuSol2.neutrinoBar.Et();
                    }
                    else
                    {
                     fevent_->tbarMass_  = (muons_->at(L1x).vec_+jets_->at(1).vec_+nuSol2.neutrino).M();
                     fevent_->tMass_     = (electrons_->at(L2x).vec_+jets_->at(0).vec_+nuSol2.neutrinoBar).M();
                     fevent_->kinweight_ = nuSol2.weight; 
                     fevent_->kinNubarEt_= nuSol2.neutrino.Et();
                     fevent_->kinNuEt_   = nuSol2.neutrinoBar.Et();
                    }
                  }     
              }// close() for if(MuEl)

          } // for if(njet>1) 
// close() for kin solution
/////////////////////////////////////
          if(accept) tree_->Fill();
      } // precut
   } 
}
double Event::SF(double pt, double eta, LeptonType type)
{
    double scale = 1.0;
    if(type == Muon){
      if( pt < 30 ){
        if( fabs(eta) >= 0.0 && fabs(eta) < 0.9 ) scale = 0.980;  
        if( fabs(eta) >= 0.9 && fabs(eta) < 1.2 ) scale = 0.972;  
        if( fabs(eta) >= 1.2 && fabs(eta) < 2.1 ) scale = 0.996;
        if( fabs(eta) >= 2.1 && fabs(eta) < 2.5 ) scale = 1.019;
      }
      if( pt >= 30 && pt < 40 ){
        if( fabs(eta) >= 0.0 && fabs(eta) < 0.9 ) scale = 0.988;
        if( fabs(eta) >= 0.9 && fabs(eta) < 1.2 ) scale = 0.994;
        if( fabs(eta) >= 1.2 && fabs(eta) < 2.1 ) scale = 0.982;
        if( fabs(eta) >= 2.1 && fabs(eta) < 2.5 ) scale = 1.018;
      }
      if( pt >= 40 && pt < 50 ){
        if( fabs(eta) >= 0.0 && fabs(eta) < 0.9 ) scale = 0.982;
        if( fabs(eta) >= 0.9 && fabs(eta) < 1.2 ) scale = 0.979;
        if( fabs(eta) >= 1.2 && fabs(eta) < 2.1 ) scale = 0.986;
        if( fabs(eta) >= 2.1 && fabs(eta) < 2.5 ) scale = 1.000;
      }
      if( pt >= 50 ){
        if( fabs(eta) >= 0.0 && fabs(eta) < 0.9 ) scale = 0.992;
        if( fabs(eta) >= 0.9 && fabs(eta) < 1.2 ) scale = 0.988;
        if( fabs(eta) >= 1.2 && fabs(eta) < 2.1 ) scale = 1.000;
        if( fabs(eta) >= 2.1 && fabs(eta) < 2.5 ) scale = 1.024;
      }
    }else if(type == Electron){
      if( pt < 30 ){
        if( fabs(eta) >= 0.0 && fabs(eta) < 0.8 )   scale = 0.971;      
        if( fabs(eta) >= 0.8 && fabs(eta) < 1.479 ) scale = 0.962;      
        if( fabs(eta) >= 1.479 && fabs(eta) < 2.5 ) scale = 0.921;
      }
      if( pt >= 30 && pt < 40 ){
        if( fabs(eta) >= 0.0 && fabs(eta) < 0.8 )   scale = 0.942;
        if( fabs(eta) >= 0.8 && fabs(eta) < 1.479 ) scale = 0.956;
        if( fabs(eta) >= 1.479 && fabs(eta) < 2.5 ) scale = 0.921;
      }
      if( pt >= 40 && pt < 50 ){
        if( fabs(eta) >= 0.0 && fabs(eta) < 0.8 )   scale = 0.967;
        if( fabs(eta) >= 0.8 && fabs(eta) < 1.479 ) scale = 0.961;
        if( fabs(eta) >= 1.479 && fabs(eta) < 2.5 ) scale = 0.959;
      }
      if( pt >= 50 ){
        if( fabs(eta) >= 0.0 && fabs(eta) < 0.8 )   scale = 0.964;
        if( fabs(eta) >= 0.8 && fabs(eta) < 1.479 ) scale = 0.963;
        if( fabs(eta) >= 1.479 && fabs(eta) < 2.5 ) scale = 0.963;
      }
    }else{
      return scale = 1;
    }

    return scale;

}
