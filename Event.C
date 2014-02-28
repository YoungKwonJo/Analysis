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

void Event::Loop(char *Name,double weight,int isZ,int v,char* DecayMode,bool isMC)
{

   const int u=5;//, v=5;
   double wei=1.;
   bool S[u], G[v];


   TH1F *hZMass[u][v], *hrelIso1[u][v], *hrelIso2[u][v], *hPt1[u][v], *hPt2[u][v], *hEta1[u][v], *hEta2[u][v];
   TH1F  *hMET[u][v], *hnJet[u][v], *hnVertex[u][v]; 
   TH1F  *hjet1pt[u][v], *hjet1eta[u][v], *hjet1phi[u][v], *hjet1_bDisCSV[u][v];    
   TH1F  *hnbJet30_CSVT[u][v], *hnbJet30_CSVM[u][v];    
   TH1F  *haddjet1_bDisCSV[u][v],  *haddjet2_bDisCSV[u][v], *haddjet1_bDisCSV2[u][v],  *haddjet2_bDisCSV2[u][v]; 
   TH2F  *haddjet2D_bDisCSV[u][v], *haddjet2D_bDisCSV2[u][v];
   const char *ttNN[5] ={"_","bb","1b","cc","LF"};

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
   TLorentzVector muons[15], electrons[15], jets[30];

   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;

      for(int i=0;i<electrons_pt->size();i++ )
      {
         //std::cout << "electron"<< electrons_pt->size()  <<" : " <<  electrons_pt->at(i) << std::endl;
         electrons[i].SetPtEtaPhiM( electrons_pt->at(i),  electrons_eta->at(i),  electrons_phi->at(i),0);
      }
      for(int i=0;i<muons_pt->size();i++ )
      {
         //std::cout << "muon "<< muons_pt->size()  <<" : " <<  muons_pt->at(i) << std::endl;
         muons[i].SetPtEtaPhiM( muons_pt->at(i),  muons_eta->at(i),  muons_phi->at(i),0);

      }
      int njet =0, nBtagT=0, nBtagM=0, jidx[4];
      double jidxV[4], csvweight=1.;
      for(int i=0;i<4;i++){ jidx[i]=-100; jidxV[i]=-100.; }
      for(int i=0;i<jets_pt->size();i++ )
      {
         //std::cout << "jets"<< muons_pt->size()  <<" : " <<  jets_pt->at(i) << std::endl;
         jets[i].SetPtEtaPhiM( jets_pt->at(i),  jets_eta->at(i),  jets_phi->at(i),jets_m->at(i));
         if(jets_pt->at(i)>30)
         {
            njet++;
            if(jets_bTag->at(i)>0.898) nBtagT++; //CSVT 0.898 , CSVM 0.679,  , CSVL 0.244 
            if(jets_bTag->at(i)>0.679) nBtagM++; //CSVT 0.898 , CSVM 0.679,  , CSVL 0.244 
            
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

      bool precut = false;
      if(!strcmp(DecayMode, "MuMu")) precut = (muons_pt->size()>1);
      if(!strcmp(DecayMode, "ElEl")) precut = (electrons_pt->size()>1);
      if(!strcmp(DecayMode, "MuEl")) precut = (muons_pt->size()>0 && electrons_pt->size()>0);

      for(int j =0; j<v ; j++) G[j]=true;

      int GBHardon=0, GCHardon=0, GLep=0;
      if(isMC)
      {
          wei = weight*csvweight*puWeight;
 
          if(v==5)
          {

              for(int i=0;i<genParticles_pdgId->size();i++ )
              {
                  if( (std::abs(genParticles_pdgId->at(i))==11 || std::abs(genParticles_pdgId->at(i))==13 ) && 
                      genParticles_pt->at(i)>20. &&  std::abs(genParticles_eta->at(i)) < 2.5 ) GLep++;
                  
              }
              for(int i=0;i<genJets_decayFromBHadron->size();i++ )
              {
                if(genJets_decayFromBHadron->at(i)==1 && genJets_pt->at(i)>20.) GBHardon++;
                else if(genJets_decayFromCHadron->at(i)==1 && genJets_pt->at(i)>20.) GCHardon++;
              }
              G[1] = (GBHardon>3 && GLep>1);          // ttbar bb
              G[2] = !G[1] && (GBHardon>2 && GLep>1); // ttbar 1b
              G[3] = !G[1] && !G[2] && (GBHardon>1) && (GCHardon>1) && (GLep>1); // ttbar cc
              G[4] = !G[1] && !G[2] && !G[3] && (GBHardon>1 && GLep>1); // ttbar LF
              G[0] = !G[1] && !G[2] && !G[3] && !G[4];  // ttbar others
          }
      }

      if(precut)
      {
          TLorentzVector Z;
          if(!strcmp(DecayMode, "MuMu")) Z = ((muons[0])+(muons[1]));
          if(!strcmp(DecayMode, "ElEl")) Z = ((electrons[0])+(electrons[1]));
          if(!strcmp(DecayMode, "MuEl")) Z = ((muons[0])+(electrons[0])); 

          if(isZ==2 && Z.M()<50) continue;
          if(isZ==1 && Z.M()>=50) continue;

          //std::cout << "Zmass = " << Z.M() << endl;

          if(!strcmp(DecayMode, "MuMu")) S[0] = (muons_Q->at(0)*muons_Q->at(1)<0 && muons_relIso->at(0)<0.15 && muons_relIso->at(1)<0.15 && Z.M()>12. && muons_pt->at(0)>20. && muons_pt->at(1)>20.);
          if(!strcmp(DecayMode, "ElEl")) S[0] = (electrons_Q->at(0)*electrons_Q->at(1)<0 && electrons_relIso->at(0)<0.15 && electrons_relIso->at(1)<0.15 && Z.M()>12. && electrons_pt->at(0)>20. && electrons_pt->at(1)>20.);
          if(!strcmp(DecayMode, "MuEl")) S[0] = (electrons_Q->at(0)*muons_Q->at(0)<0 && electrons_relIso->at(0)<0.15 && muons_relIso->at(0)<0.15 && Z.M()>12. && electrons_pt->at(0)>20. && muons_pt->at(0)>20.);

          S[1] = S[0] && (std::abs(91.2-Z.M())>15.0);
          if(strcmp(DecayMode, "MuEl")) S[2] = S[1] && (met_pt>30.); else S[2] = S[1];
          S[3] = S[2] && (njet>3);
          S[4] = S[3] && (nBtagT>1);
     
          for(int i =0; i<u ; i++)for(int j =0; j<v ; j++) if(S[i] && G[j])
          {
              hZMass[i][j]   ->Fill(Z.M()              , wei); 

              if(!strcmp(DecayMode, "MuMu"))
              {
                 hrelIso1[i][j] ->Fill(muons_relIso->at(0), wei);
                 hrelIso2[i][j] ->Fill(muons_relIso->at(1), wei);
                 hPt1[i][j]     ->Fill(muons_pt->at(0)    , wei);
                 hPt2[i][j]     ->Fill(muons_pt->at(1)    , wei);
                 hEta1[i][j]    ->Fill(muons_eta->at(0)    , wei);
                 hEta2[i][j]    ->Fill(muons_eta->at(1)    , wei);
              }
              if(!strcmp(DecayMode, "ElEl"))
              {
                 hrelIso1[i][j] ->Fill(electrons_relIso->at(0), wei);
                 hrelIso2[i][j] ->Fill(electrons_relIso->at(1), wei);
                 hPt1[i][j]     ->Fill(electrons_pt->at(0)    , wei);
                 hPt2[i][j]     ->Fill(electrons_pt->at(1)    , wei);
                 hEta1[i][j]    ->Fill(electrons_eta->at(0)    , wei);
                 hEta2[i][j]    ->Fill(electrons_eta->at(1)    , wei);
              }
              if(!strcmp(DecayMode, "MuEl"))
              {
                 hrelIso2[i][j] ->Fill(electrons_relIso->at(0), wei);
                 hrelIso1[i][j] ->Fill(muons_relIso->at(0)    , wei);
                 hPt2[i][j]     ->Fill(electrons_pt->at(0)    , wei);
                 hPt1[i][j]     ->Fill(muons_pt->at(0)        , wei);
                 hEta2[i][j]    ->Fill(electrons_eta->at(0)    , wei);
                 hEta1[i][j]    ->Fill(muons_eta->at(0)        , wei);
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
