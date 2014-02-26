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

void Event::Loop(char *Name,double weight,int isZ,const int v)
{

   const int u=5;//, v=5;
   double wei=1.;
   bool S[u], G[v];

   //ttbar others
   TH1F *hZMass[u][v], *hrelIso1[u][v], *hrelIso2[u][v], *hPt1[u][v], *hPt2[u][v], *hEta1[u][v], *hEta2[u][v];
   TH1F  *hMET[u][v], *hnJet[u][v], *hnVertex[u][v]; 
   TH1F  *hjet1pt[u][v], *hjet1eta[u][v], *hjet1phi[u][v], *hjet1_bDisCSV[u][v];    
   TH1F  *hnbJet30_CSVT[u][v], *hnbJet30_CSVM[u][v];    
   TH1F  *haddjet1_bDisCSV[u][v],  *haddjet2_bDisCSV[u][v]; 
   TH2F  *haddjet2D_bDisCSV[u][v];
   const char *ttNN[5] ={"_","bb","1b","cc","LF"}

   for(int i =0; i<u ; i++) for(int j =0; j<v ; j++)
   {
       hZMass[i][j]   = new TH1F(Form("hZMass_S%d_%s%s",   i+1,Name,ttNN[j]), "dilepton mass   ", 40, 0, 250);
       hrelIso1[i][j] = new TH1F(Form("hrelIso1_S%d_%s%s", i+1,Name,ttNN[j]), "rel Isolation 1 ", 40,0,0.4);
       hrelIso2[i][j] = new TH1F(Form("hrelIso2_S%d_%s%s", i+1,Name,ttNN[j]), "rel Isolation 2 ", 40,0,0.4);
   
       hPt1[i][j]     = new TH1F(Form("hPt1_S%d_%s%s", i+1,Name,ttNN[j]), "leading lepton Pt ", 20,0,100);
       hPt2[i][j]     = new TH1F(Form("hPt2_S%d_%s%s", i+1,Name,ttNN[j]), "second lepton Pt  ", 20,0,100);
   
       hEta1[i][j]    = new TH1F(Form("hEta1_S%d_%s%s", i+1,Name,ttNN[j]), "leading lepton eta ", 35, -3.5, 3.5);
       hEta2[i][j]    = new TH1F(Form("hEta2_S%d_%s%s", i+1,Name,ttNN[j]), "second lepton eta  ", 35, -3.5, 3.5);

       hMET[i][j]               = new TH1F(Form("hMET_S%d_%s%s",               i+1,Name,ttNN[j]),            "MET     ", 18, 0, 180 );
       hnJet[i][j]              = new TH1F(Form("hnJet_S%d_%s%s",              i+1,Name,ttNN[j]),            "nJet    ", 10, 0, 10  );
       hnVertex[i][j]           = new TH1F(Form("hnVertex_S%d_%s%s",           i+1,Name,ttNN[j]),            "nVertex ", 30, 0, 30  );
                                                                                                    
       hjet1pt[i][j]            = new TH1F(Form("hjet1pt_S%d_%s%s",            i+1,Name,ttNN[j]),          "jet1pt    ", 19, 20, 400   );
       hjet1eta[i][j]           = new TH1F(Form("hjet1eta_S%d_%s%s",           i+1,Name,ttNN[j]),          "jet1eta   ", 35, -3.5, 3.5 );
       hjet1phi[i][j]           = new TH1F(Form("hjet1phi_S%d_%s%s",           i+1,Name,ttNN[j]),          "jet1phi   ", 35, -3.5, 3.5 );
       hjet1_bDisCSV[i][j]      = new TH1F(Form("hjet1_bDisCSV_S%d_%s%s",      i+1,Name,ttNN[j]),     "jet1_bDisCSV   ", 20, 0.0, 1.0  );
                                                                                 
       hnbJet30_CSVT[i][j]      = new TH1F(Form("hnbJet30_CSVT_S%d_%s%s",      i+1,Name,ttNN[j]),     "nbJet30_CSVT   ", 5, 0, 5 );
       hnbJet30_CSVM[i][j]      = new TH1F(Form("hnbJet30_CSVM_S%d_%s%s",      i+1,Name,ttNN[j]),     "nbJet30_CSVM   ", 5, 0, 5 );
                                                                              
       haddjet1_bDisCSV[i][j]   = new TH1F(Form("haddjet1_bDisCSV_S%d_%s%s",   i+1,Name,ttNN[j]),  "addjet1_bDisCSV   ", 10, 0.0, 1.0);
       haddjet2_bDisCSV[i][j]   = new TH1F(Form("haddjet2_bDisCSV_S%d_%s%s",   i+1,Name,ttNN[j]),  "addjet2_bDisCSV   ", 10, 0.0, 1.0);

       haddjet2D_bDisCSV[i][j]  = new TH2F(Form("haddjet2D_bDisCSV_S%d_%s%s",  i+1,Name,ttNN[j]), "addjet2D_bDisCSV   ", 10, 0.0, 1.0, 10, 0.0, 1.0);
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
      bool precut = (muons_pt->size()>1);
      wei = weight*csvweight;
      int GBHardon=0, GCHardon=0;

      if(v==5)
      {
          for(int i=0;i<genJets_decayFromBHadron->size();i++ )
          {
            if(genJets_decayFromBHadron->at(i)==1) GBHardon++;
            if(genJets_decayFromCHadron->at(i)==1) GCHardon++;
          }
          G[1] = (GBHardon>3);          // ttbar bb
          G[2] = !G[1] && (GBHardon>2); // ttbar 1b
          G[3] = !G[1] && !G[2] && (GBHardon>1) && (GCHardon>1); // ttbar cc
          G[4] = !G[1] && !G[2] && !G[3] && (GBHardon>1); // ttbar LF
          G[0] = !G[1] && !G[2] && !G[3] && !G[4];  // ttbar others
      }
      else { for(int j =0; j<v ; j++) G[j]=true;}

      if(precut)
      {
          TLorentzVector Z = ((muons[0])+(muons[1])); 
          if(isZ==2 && Z.M()<50) continue;
          if(isZ==1 && Z.M()>50) continue;

          //std::cout << "Zmass = " << Z.M() << endl;

          S[0] = (muons_Q->at(0)*muons_Q->at(1) && muons_relIso->at(0)<0.15 && muons_relIso->at(1)<0.15 && Z.M()>12. && muons_pt->at(0)>20. && muons_pt->at(1)>20.);
          S[1] = S[0] && (std::abs(91.2-Z.M())>15.0);
          S[2] = S[1] && (met_pt>30.);
          S[3] = S[2] && (njet>3);
          S[4] = S[3] && (nBtagT>1);
     
          for(int i =0; i<u ; i++)for(int j =0; j<v ; j++) if(S[i] && G[j])
          {
              hZMass[i][j]   ->Fill(Z.M()              , wei); 
              hrelIso1[i][j] ->Fill(muons_relIso->at(0), wei);
              hrelIso2[i][j] ->Fill(muons_relIso->at(1), wei);
              
              hPt1[i][j]     ->Fill(muons_pt->at(0)    , wei);
              hPt2[i][j]     ->Fill(muons_pt->at(1)    , wei);
              
              hEta1[i][j]    ->Fill(muons_pt->at(0)    , wei);
              hEta2[i][j]    ->Fill(muons_pt->at(1)    , wei);
              
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
              }
          } // cut loop
/////////////////
      } // precut
   } 
}
