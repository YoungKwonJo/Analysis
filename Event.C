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


void Event::Loop(char *Name,double weight,int isZ)
{

   const int u=5;

   bool S[u];
   TH1F *hZMass[u], *hrelIso1[u], *hrelIso2[u], *hPt1[u], *hPt2[u], *hEta1[u], *hEta2[u];
   TH1F  *hMET[u], *hnJet[u], *hnVertex[u]; 
   TH1F  *hjet1pt[u], *hjet1eta[u], *hjet1phi[u], *hjet1_bDisCSV[u];    

   TH1F  *hnbJet30_CSVT[u], *hnbJet30_CSVM[u];    
   TH1F  *haddjet1_bDisCSV[u],  *haddjet2_bDisCSV[u]; 
   TH2F  *haddjet2D_bDisCSV[u];

   
   for(int i =0; i<u ; i++)
   {
       hZMass[i]   = new TH1F(Form("hZMass_S%d_%s",   i+1,Name), "dilepton mass   ", 40, 0, 250);
       hrelIso1[i] = new TH1F(Form("hrelIso1_S%d_%s", i+1,Name), "rel Isolation 1 ", 40,0,0.4);
       hrelIso2[i] = new TH1F(Form("hrelIso2_S%d_%s", i+1,Name), "rel Isolation 2 ", 40,0,0.4);
   
       hPt1[i]     = new TH1F(Form("hPt1_S%d_%s", i+1,Name), "leading lepton Pt ", 20,0,100);
       hPt2[i]     = new TH1F(Form("hPt2_S%d_%s", i+1,Name), "second lepton Pt  ", 20,0,100);
   
       hEta1[i]    = new TH1F(Form("hEta1_S%d_%s", i+1,Name), "leading lepton eta ", 35, -3.5, 3.5);
       hEta2[i]    = new TH1F(Form("hEta2_S%d_%s", i+1,Name), "second lepton eta  ", 35, -3.5, 3.5);

       hMET[i]               = new TH1F(Form("hMET_S%d_%s",               i+1,Name),            "MET     ", 18, 0, 180 );
       hnJet[i]              = new TH1F(Form("hnJet_S%d_%s",              i+1,Name),            "nJet    ", 10, 0, 10  );
       hnVertex[i]           = new TH1F(Form("hnVertex_S%d_%s",           i+1,Name),            "nVertex ", 30, 0, 30  );
                                                                                                    
       hjet1pt[i]            = new TH1F(Form("hjet1pt_S%d_%s",            i+1,Name),          "jet1pt    ", 19, 20, 400   );
       hjet1eta[i]           = new TH1F(Form("hjet1eta_S%d_%s",           i+1,Name),          "jet1eta   ", 35, -3.5, 3.5 );
       hjet1phi[i]           = new TH1F(Form("hjet1phi_S%d_%s",           i+1,Name),          "jet1phi   ", 35, -3.5, 3.5 );
       hjet1_bDisCSV[i]      = new TH1F(Form("hjet1_bDisCSV_S%d_%s",      i+1,Name),     "jet1_bDisCSV   ", 20, 0.0, 1.0  );
                                                                                 
       hnbJet30_CSVT[i]      = new TH1F(Form("hnbJet30_CSVT_S%d_%s",      i+1,Name),     "nbJet30_CSVT   ", 5, 0, 5 );
       hnbJet30_CSVM[i]      = new TH1F(Form("hnbJet30_CSVM_S%d_%s",      i+1,Name),     "nbJet30_CSVM   ", 5, 0, 5 );
                                                                              
       haddjet1_bDisCSV[i]   = new TH1F(Form("haddjet1_bDisCSV_S%d_%s",   i+1,Name),  "addjet1_bDisCSV   ", 10, 0.0, 1.0);
       haddjet2_bDisCSV[i]   = new TH1F(Form("haddjet2_bDisCSV_S%d_%s",   i+1,Name),  "addjet2_bDisCSV   ", 10, 0.0, 1.0);

       haddjet2D_bDisCSV[i]  = new TH2F(Form("haddjet2D_bDisCSV_S%d_%s",  i+1,Name), "addjet2D_bDisCSV   ", 10, 0.0, 1.0, 10, 0.0, 1.0);
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
      double jidxV[4];
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
     
          for(int i =0; i<u ; i++) if(S[i])
          {
              hZMass[i]   ->Fill(Z.M()); 
              hrelIso1[i] ->Fill(muons_relIso->at(0));
              hrelIso2[i] ->Fill(muons_relIso->at(1));
          
              hPt1[i]     ->Fill(muons_pt->at(0));
              hPt2[i]     ->Fill(muons_pt->at(1));
          
              hEta1[i]    ->Fill(muons_pt->at(0));
              hEta2[i]    ->Fill(muons_pt->at(1));

              hMET[i]     ->Fill(met_pt);             
              hnJet[i]    ->Fill(njet);         
              hnVertex[i] ->Fill(nVertex);         
             
              if(S[3])
              {        
                  hjet1pt[i]       ->Fill(jets_pt  ->at( (jidx[0]) ) );    
                  hjet1eta[i]      ->Fill(jets_eta ->at(jidx[0]) );    
                  hjet1phi[i]      ->Fill(jets_phi ->at(jidx[0]) );    
                  hjet1_bDisCSV[i] ->Fill(jets_bTag->at(jidx[0]) );    
                                       
                  hnbJet30_CSVT[i] ->Fill(nBtagT);    
                  hnbJet30_CSVM[i] ->Fill(nBtagM);    
                                       
                  haddjet1_bDisCSV[i] ->Fill(jets_bTag->at(jidx[2])); 
                  haddjet2_bDisCSV[i] ->Fill(jets_bTag->at(jidx[3])); 
                                 
                  haddjet2D_bDisCSV[i] ->Fill(jets_bTag->at(jidx[2]),jets_bTag->at(jidx[3]));
              }

          } // cut loop
/////////////////
      } // precut
   } 
}
