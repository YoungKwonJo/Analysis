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
   TH1F *hStepAll[v], *hStep[v];
   TH1F *hStepAllnw[v], *hStepnw[v];
   TH1F *hStepAll2[v], *hStep2[v];
   for(int j =0; j<v ; j++)
   {

      hStepAll[j]    = new TH1F(Form("hStep_all_%s%s_Sumw2", Name,ttNN[j]),Form("Step 1~5 all %s",ttNN[j]),u,0.5,u+0.5);
      hStepAllnw[j]  = new TH1F(Form("hStep_all_%s%s_nw",    Name,ttNN[j]),Form("Step 1~5 all %s",ttNN[j]),u+2,-0.5,u+1.5);
      hStepAll2[j]   = new TH1F(Form("hStep_all_%s%s",       Name,ttNN[j]),Form("Step 1~5 all %s",ttNN[j]),u,0.5,u+0.5);
      hStepAll[j]->Sumw2();

      hStep[j]    = new TH1F(Form("hStep_%s_%s%s_Sumw2", DecayMode,Name,ttNN[j]),Form("Step 1~5 %s %s%s",DecayMode,Name,ttNN[j]),u,0.5,u+0.5); 
      hStepnw[j]  = new TH1F(Form("hStep_%s_%s%s_nw",    DecayMode,Name,ttNN[j]),Form("Step 1~5 %s %s%s",DecayMode,Name,ttNN[j]),u+1,-0.5,u+0.5); 
      hStep2[j]   = new TH1F(Form("hStep_%s_%s%s",       DecayMode,Name,ttNN[j]),Form("Step 1~5 %s %s%s",DecayMode,Name,ttNN[j]),u,0.5,u+0.5); 
      hStep[j]->Sumw2();

      hStepAllnw[j]->Fill(u+1, totalEvents);
      hStepnw[j]   ->Fill(u+1, totalEvents);

   }

   TH1F *hZMass[u][v], *hrelIso1[u][v], *hrelIso2[u][v], *hPt1[u][v], *hPt2[u][v], *hEta1[u][v], *hEta2[u][v];
   TH1F  *hMET[u][v], *hnJet[u][v], *hnVertex[u][v]; 
   TH1F  *hjet1pt[u][v], *hjet1eta[u][v], *hjet1phi[u][v], *hjet1_bDisCSV[u][v];    
   TH1F  *hnbJet30_CSVT[u][v], *hnbJet30_CSVM[u][v];    
   TH1F  *haddjet1_bDisCSV[u][v],  *haddjet2_bDisCSV[u][v], *haddjet1_bDisCSV2[u][v],  *haddjet2_bDisCSV2[u][v]; 
   TH2F  *haddjet2D_bDisCSV[u][v], *haddjet2D_bDisCSV2[u][v];

   for(int i =0; i<u ; i++) for(int j =0; j<v ; j++)
   {
       hZMass[i][j]   = new TH1F(Form("hZMass_S%d_%s%s%s",   i+1,Name,ttNN[j],DecayMode), "dilepton mass   ", 40, 0, 250);
       hrelIso1[i][j] = new TH1F(Form("hrelIso1_S%d_%s%s%s", i+1,Name,ttNN[j],DecayMode), "rel Isolation 1 ", 40,0,0.4);
       hrelIso2[i][j] = new TH1F(Form("hrelIso2_S%d_%s%s%s", i+1,Name,ttNN[j],DecayMode), "rel Isolation 2 ", 40,0,0.4);
   
       hPt1[i][j]     = new TH1F(Form("hPt1_S%d_%s%s%s",   i+1,Name,ttNN[j],DecayMode), "leading lepton Pt ", 20,0,100);
       hPt2[i][j]     = new TH1F(Form("hPt2_S%d_%s%s%s",   i+1,Name,ttNN[j],DecayMode), "second lepton Pt  ", 20,0,100);
   
       hEta1[i][j]    = new TH1F(Form("hEta1_S%d_%s%s%s",  i+1,Name,ttNN[j],DecayMode), "leading lepton eta ", 35, -3.5, 3.5);
       hEta2[i][j]    = new TH1F(Form("hEta2_S%d_%s%s%s",  i+1,Name,ttNN[j],DecayMode), "second lepton eta  ", 35, -3.5, 3.5);

       hMET[i][j]               = new TH1F(Form( "hMET_S%d_%s%s%s",              i+1,Name,ttNN[j],DecayMode),            "MET     ", 18, 0, 180 );
       hnJet[i][j]              = new TH1F(Form("hnJet_S%d_%s%s%s",              i+1,Name,ttNN[j],DecayMode),            "nJet    ", 10, 0, 10  );
       hnVertex[i][j]           = new TH1F(Form("hnVertex_S%d_%s%s%s",           i+1,Name,ttNN[j],DecayMode),            "nVertex ", 30, 0, 30  );
                                                                                                    
       hjet1pt[i][j]            = new TH1F(Form( "hjet1pt_S%d_%s%s%s",           i+1,Name,ttNN[j],DecayMode),          "jet1pt    ", 19, 20, 400   );
       hjet1eta[i][j]           = new TH1F(Form("hjet1eta_S%d_%s%s%s",           i+1,Name,ttNN[j],DecayMode),          "jet1eta   ", 35, -3.5, 3.5 );
       hjet1phi[i][j]           = new TH1F(Form("hjet1phi_S%d_%s%s%s",           i+1,Name,ttNN[j],DecayMode),          "jet1phi   ", 35, -3.5, 3.5 );
       hjet1_bDisCSV[i][j]      = new TH1F(Form("hjet1_bDisCSV_S%d_%s%s%s",      i+1,Name,ttNN[j],DecayMode),     "jet1_bDisCSV   ", 20, 0.0, 1.0  );
                                                                                 
       hnbJet30_CSVT[i][j]      = new TH1F(Form("hnbJet30_CSVT_S%d_%s%s%s",      i+1,Name,ttNN[j],DecayMode),     "nbJet30_CSVT   ", 5, 0, 5 );
       hnbJet30_CSVM[i][j]      = new TH1F(Form("hnbJet30_CSVM_S%d_%s%s%s",      i+1,Name,ttNN[j],DecayMode),     "nbJet30_CSVM   ", 5, 0, 5 );
                                                                              
       haddjet1_bDisCSV[i][j]   = new TH1F(Form("haddjet1_bDisCSV_S%d_%s%s%s",   i+1,Name,ttNN[j],DecayMode),  "addjet1_bDisCSV   ", 10, 0.0, 1.0);
       haddjet2_bDisCSV[i][j]   = new TH1F(Form("haddjet2_bDisCSV_S%d_%s%s%s",   i+1,Name,ttNN[j],DecayMode),  "addjet2_bDisCSV   ", 10, 0.0, 1.0);

       haddjet2D_bDisCSV[i][j]  = new TH2F(Form("haddjet2D_bDisCSV_S%d_%s%s%s",  i+1,Name,ttNN[j],DecayMode), "addjet2D_bDisCSV   ", 10, 0.0, 1.0, 10, 0.0, 1.0);

       haddjet1_bDisCSV2[i][j]   = new TH1F(Form("haddjet1_bDisCSV_S%d_%s%s",   i+1,Name,ttNN[j]),  "addjet1_bDisCSV   ", 10, 0.0, 1.0);
       haddjet2_bDisCSV2[i][j]   = new TH1F(Form("haddjet2_bDisCSV_S%d_%s%s",   i+1,Name,ttNN[j]),  "addjet2_bDisCSV   ", 10, 0.0, 1.0);
       haddjet2D_bDisCSV2[i][j]  = new TH2F(Form("haddjet2D_bDisCSV_S%d_%s%s",  i+1,Name,ttNN[j]), "addjet2D_bDisCSV   ", 10, 0.0, 1.0, 10, 0.0, 1.0);
/*
       hZMass[i][j]            ->Sumw2();
       hrelIso1[i][j]          ->Sumw2();
       hrelIso2[i][j]          ->Sumw2();

       hPt1[i][j]              ->Sumw2();
       hPt2[i][j]              ->Sumw2();

       hEta1[i][j]             ->Sumw2();
       hEta2[i][j]             ->Sumw2();

       hMET[i][j]              ->Sumw2();
       hnJet[i][j]             ->Sumw2();
       hnVertex[i][j]          ->Sumw2();

       hjet1pt[i][j]           ->Sumw2();
       hjet1eta[i][j]          ->Sumw2();
       hjet1phi[i][j]          ->Sumw2();
       hjet1_bDisCSV[i][j]     ->Sumw2();

       hnbJet30_CSVT[i][j]     ->Sumw2();
       hnbJet30_CSVM[i][j]     ->Sumw2();

       haddjet1_bDisCSV[i][j]  ->Sumw2();
       haddjet2_bDisCSV[i][j]  ->Sumw2();

       haddjet2D_bDisCSV[i][j] ->Sumw2(); 

       haddjet1_bDisCSV2[i][j]  ->Sumw2();
       haddjet2_bDisCSV2[i][j]  ->Sumw2();

       haddjet2D_bDisCSV2[i][j] ->Sumw2(); 
*/

   }
////////////
   const float HFbinPt[] = {30.,40.,60.,100.,160.,10000};
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
////////////
   TLorentzVector muons[15], electrons[15], jets[30], genjets[50], genparticles[50], genjetsB[50], genjetsC[50];
//   doublesP jets_pt_,   jets_eta_, jets_phi_, jets_m_;
//   doublesP jets_bTag_, jets_partonflavor_;
 //   TLorentzVectorsP muons_ = new TLorentzVectors;
 //  TLorentzVectorsP electrons_ = new TLorentzVectors;
   LeptonsP muons_;
   LeptonsP electrons_;
   muons_ = new Leptons;
   electrons_ = new Leptons;
   JetsP jets_;
   jets_ = new Jets; 

//   jets_pt_  = new doubles;
//   jets_eta_ = new doubles;
//   jets_phi_ = new doubles;
//   jets_m_   = new doubles;
//   jets_bTag_ = new doubles;
//   jets_partonflavor_ = new doubles;

   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;

      muons_->clear();
      electrons_->clear();
      jets_->clear();
      //jets_m_->clear();
      //jets_bTag_->clear();
      //jets_partonflavor_->clear();

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

      int njet =0, nBtagT=0, nBtagM=0, nBtagL=0, jidx[4];
      double jidxV[4], csvweight=1., leptonweight=1.0;

      for(int i=0;i<4;i++){ jidx[i]=-100; jidxV[i]=-100.; }
      for(int i=0;i<jets_pt->size();i++ )
      {
         //std::cout << "jets"<< muons_pt->size()  <<" : " <<  jets_pt->at(i) << std::endl;
         jets[i].SetPtEtaPhiM( jets_pt->at(i),  jets_eta->at(i),  jets_phi->at(i),jets_m->at(i));

         bool overlapMu=false, overlapEl=false;  // jet cleaning..
//         for(int j=0;j<electrons_pt->size();j++ ) 
//         if(electrons_type->at(j)>100 && electrons_mva->at(j)>0.5 && electrons_pt->at(j)>20. && abs(electrons_eta->at(j))<2.4 && electrons_relIso->at(j)<0.15 ) 
         for(int j=0;j<electrons_->size();j++ ) 
         if( std::abs( jets[i].DeltaR(electrons_->at(j).vec_) )< 0.5 ) overlapEl=true;

//         for(int j=0;j<muons_pt->size();j++ )     
//         if(muons_type->at(j)>9 && muons_pt->at(j)>20. && abs(muons_eta->at(j))<2.4 && muons_relIso->at(j)<0.15)
         for(int j=0;j<muons_->size();j++ )     
         if( std::abs( jets[i].DeltaR(muons_->at(j).vec_) )< 0.5 )     overlapMu=true;

         if(jets_pt->at(i)>30 && abs(jets_eta->at(i))<2.5 )//&& !overlapEl && !overlapMu)
         {
            njet++;
            double x_ = jets_pt->at(i)*TMath::Cos(jets_phi->at(i));
            double y_ = jets_pt->at(i)*TMath::Sin(jets_phi->at(i));
            double z_ = jets_pt->at(i)*sinh(jets_eta->at(i));
            double e_ = TMath::Sqrt(x_*x_+y_*y_+z_*z_+jets_m->at(i)*jets_m->at(i));
            Jet jet_(TLorentzVector( x_,y_,z_,e_),jets_bTag->at(i),jets_partonflavor->at(i));
            jets_->push_back(jet_);

//            jets_pt_->push_back(jets_pt->at(i));
//            jets_eta_->push_back(jets_eta->at(i));
            //jets_phi_->push_back(jets_phi->at(i));
            //jets_m_->push_back(jets_m->at(i));
//            jets_bTag_->push_back(jets_bTag->at(i));
//            jets_partonflavor_->push_back(jets_partonflavor->at(i));

            if(jets_bTag->at(i)>0.898) nBtagT++; //CSVT 0.898 , CSVM 0.679,  , CSVL 0.244 
            if(jets_bTag->at(i)>0.679) nBtagM++; //CSVT 0.898 , CSVM 0.679,  , CSVL 0.244 
            if(jets_bTag->at(i)>0.244) nBtagL++; //CSVT 0.898 , CSVM 0.679,  , CSVL 0.244 
            
            if(jidxV[0]<jets_bTag->at(i))
            {
                jidx[3]=jidx[2]; jidxV[3]=jidxV[2];  
                jidx[2]=jidx[1]; jidxV[2]=jidxV[1];  
                jidx[1]=jidx[0]; jidxV[1]=jidxV[0]; 
                jidx[0]=i;       jidxV[0]=jets_bTag->at(i); 
            }
            else if(jidxV[1]<jets_bTag->at(i))
            {
                jidx[3]=jidx[2]; jidxV[3]=jidxV[2];
                jidx[2]=jidx[1]; jidxV[2]=jidxV[1];
                jidx[1]=i;       jidxV[1]=jets_bTag->at(i);
            }
            else if(jidxV[2]<jets_bTag->at(i))
            {
                jidx[3]=jidx[2]; jidxV[3]=jidxV[2];
                jidx[2]=i;       jidxV[2]=jets_bTag->at(i);
            }
            else if(jidxV[3]<jets_bTag->at(i))
            {
                jidx[3]=i;       jidxV[3]=jets_bTag->at(i);
            }
         }

      }
//      GreaterByCSVJet jets(jets_);

      bool precut = false;
      if(!strcmp(DecayMode, "MuMu")) precut = (muons_->size()>1);
      if(!strcmp(DecayMode, "ElEl")) precut = (electrons_->size()>1);
      if(!strcmp(DecayMode, "MuEl")) precut = (muons_->size()>0 && electrons_->size()>0);

      for(int j =0; j<v ; j++) G[j]=true;

      if(isMC)
      {

          if(v==5)
          {
              
              bool visible = (nGenJet20 >= 4 && nGenbJet20 >=2 && genLep1_pt > 20 && genLep2_pt > 20 && abs( genLep1_eta ) < 2.4 && abs( genLep2_eta ) < 2.4);
              G[1] = visible && (nGenbJet20 >= 4);          // ttbar bb
              G[2] = visible && (nGenbJet20 >= 3) && !(nGenbJet20 >= 4); // ttbar 1b
              G[3] = visible && (nGencJet20 >= 2) && !(nGenbJet20 >= 4) && !(nGenbJet20 >= 3); // ttbar cc
              G[4] = visible && !(nGencJet20 >= 2) && !(nGenbJet20 >= 4) && !(nGenbJet20 >= 3); // ttbar LF
              G[0] = !visible;  // ttbar others
 
          }
          //////////////////////////
      }
      for(int j =0; j<v ; j++) if(G[j])
      {
              hStepAllnw[j]->Fill(0);
              hStepnw[j]   ->Fill(0);
      }

      //std::cout << "precut = " << precut << endl;
      if(precut)
      {
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
          }

///////////////////////
          if(njet==2) //&& nLep==2)
          {
             bool zveto   = ( Z.M()<(65.5 +3*met_pt/8) || Z.M()>(108.-met_pt/4) || Z.M()<(79.-3.*met_pt/4) ||  Z.M()>(99.+met_pt/2) );
             bool zselcut = (std::abs(Z.M()-91.) < 10.);
             bool highMET = (met_pt > 50.);
             bool lowMET  = (met_pt < 30.);
             bool HFtag   = (jidxV[0]>0.679);
             bool LFtag   = (jidxV[1]<0.244);

             bool LFcut = !zveto && zselcut && lowMET && LFtag;
             bool HFcut = zveto && highMET && HFtag;

             int HF_i = -1, LF_i=-1, LF_j=-1; 
             for(int i=0;i<5;i++) if(HFbinPt[i] < jets_pt->at(jidx[1])) HF_i=i;
             for(int i=0;i<3;i++) if(LFbinPt[i] < jets_pt->at(jidx[0])) LF_i=i;
             for(int i=0;i<3;i++) if(LFbinEta[i]< jets_eta->at(jidx[0])) LF_j=i;

             
             //if(jets_pt->at(jidx[1])>140 || jets_pt->at(jidx[0]) >140)
             //std::cout << "HF_i pt=" <<  jets_pt->at(jidx[1]) << ", LF_i pt="<< jets_pt->at(jidx[0]) 
             //          <<", HF_i=" << HF_i << ", LF_i="<< LF_i <<", LF_j="<<LF_j << endl;
             double weightSF = weight*puWeight;
             if(HFcut && jidxV[1]>-1 && HF_i>-1)
             {
                if(!isMC)  hHF_CSV[HF_i]->Fill( jidxV[1]);
                else 
                {
                    if(abs(jets_partonflavor->at(jidx[1])) ==5) 
                         hHF_CSVbF[HF_i]->Fill( jidxV[1], weightSF);
                    else hHF_CSVnbF[HF_i]->Fill( jidxV[1], weightSF);
                }        
                //std::cout <<"HF test CSV SF" << endl;
             }
             if(LFcut && jidxV[0]>-1 && LF_i>-1 && LF_j>-1)
             {
                 if(!isMC) hLF_CSV[LF_i][LF_j]->Fill( jidxV[0]);
                 else 
                 {
                     if( abs(jets_partonflavor->at(jidx[0])) ==4 || abs(jets_partonflavor->at(jidx[0])) ==5)
                          hLF_CSVHF[LF_i][LF_j]->Fill( jidxV[0],weightSF);
                     else hLF_CSVLF[LF_i][LF_j]->Fill( jidxV[0],weightSF);
                 }
                 //std::cout <<"LF test CSV SF" << endl;
             }
          }          
///////////////////////

          //std::cout << "Zmass = " << Z.M() << endl;
          if(isZ==2 && Z.M()<50) continue;
          if(isZ==1 && Z.M()>=50) continue;


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
     
          for(int i =0; i<u ; i++)for(int j =0; j<v ; j++) if(S[i] && G[j])
          {
              //std::cout << "S"<<i<< "  pass" << endl;
              hZMass[i][j]   ->Fill(Z.M()              , wei); 
              hStepAll[j]->Fill(i+1,wei);
              hStepAllnw[j]->Fill(i+1);
              hStep[j]   ->Fill(i+1,wei);
              hStepnw[j]   ->Fill(i+1);
              hStepAll2[j]->Fill(i+1,wei);
              hStep2[j]   ->Fill(i+1,wei);

              if(!strcmp(DecayMode, "MuMu"))
              {
                 hrelIso1[i][j] ->Fill(muons_->at(L1x).Iso_    , wei);
                 hrelIso2[i][j] ->Fill(muons_->at(L2x).Iso_    , wei);
                 hPt1[i][j]     ->Fill(muons_->at(L1x).Pt()    , wei);
                 hPt2[i][j]     ->Fill(muons_->at(L2x).Pt()    , wei);
                 hEta1[i][j]    ->Fill(muons_->at(L1x).Eta()   , wei);
                 hEta2[i][j]    ->Fill(muons_->at(L2x).Eta()   , wei);
              }
              if(!strcmp(DecayMode, "ElEl"))
              {
                 hrelIso1[i][j] ->Fill(electrons_->at(L1x).Iso_    , wei);
                 hrelIso2[i][j] ->Fill(electrons_->at(L2x).Iso_    , wei);
                 hPt1[i][j]     ->Fill(electrons_->at(L1x).Pt()    , wei);
                 hPt2[i][j]     ->Fill(electrons_->at(L2x).Pt()    , wei);
                 hEta1[i][j]    ->Fill(electrons_->at(L1x).Eta()   , wei);
                 hEta2[i][j]    ->Fill(electrons_->at(L2x).Eta()   , wei);
              }
              if(!strcmp(DecayMode, "MuEl"))
              {
                 hrelIso1[i][j] ->Fill(muons_->at(L1x).Iso_    , wei);
                 hrelIso2[i][j] ->Fill(electrons_->at(L2x).Iso_    , wei);
                 hPt1[i][j]     ->Fill(muons_->at(L1x).Pt()    , wei);
                 hPt2[i][j]     ->Fill(electrons_->at(L2x).Pt()    , wei);
                 hEta1[i][j]    ->Fill(muons_->at(L1x).Eta()   , wei);
                 hEta2[i][j]    ->Fill(electrons_->at(L2x).Eta()   , wei);
              }
              
              hMET[i][j]     ->Fill(met_pt             , wei);             
              hnJet[i][j]    ->Fill(njet               , wei);         
              hnVertex[i][j] ->Fill(nVertex            , wei);         
             
              if(S[3])
              {        
                  hjet1pt[i][j]       ->Fill(jets_pt  ->at(jidx[0]) , wei);    
                  hjet1eta[i][j]      ->Fill(jets_eta ->at(jidx[0]) , wei);    
                  hjet1phi[i][j]      ->Fill(jets_phi ->at(jidx[0]) , wei);    
                  hjet1_bDisCSV[i][j] ->Fill(jets_bTag->at(jidx[0]) , wei);    
                                       
                  hnbJet30_CSVT[i][j] ->Fill(nBtagT , wei);    
                  hnbJet30_CSVM[i][j] ->Fill(nBtagM , wei);    
                                       
                  haddjet1_bDisCSV[i][j] ->Fill(jets_bTag->at(jidx[2]) , wei); 
                  haddjet2_bDisCSV[i][j] ->Fill(jets_bTag->at(jidx[3]) , wei); 
                                 
                  haddjet2D_bDisCSV[i][j] ->Fill(jets_bTag->at(jidx[2]),jets_bTag->at(jidx[3]) , wei);

                  haddjet1_bDisCSV2[i][j] ->Fill(jets_bTag->at(jidx[2]) , wei); 
                  haddjet2_bDisCSV2[i][j] ->Fill(jets_bTag->at(jidx[3]) , wei); 
                  haddjet2D_bDisCSV2[i][j] ->Fill(jets_bTag->at(jidx[2]),jets_bTag->at(jidx[3]) , wei);

              }
          } // cut loop

          
/////////////////
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
