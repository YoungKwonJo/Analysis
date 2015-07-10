#define Delphes_cxx
#include "Delphes.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

#include <TH1F.h>
#include "FlatTree.h"


void Delphes::Loop()
{

   TLorentzVector *jet=new TLorentzVector();
   int nbjet=0, njet=0;
   int nbjet20=0, njet20=0;
   double dr_bh_jet=0, dpt_bh_jet=0;
   TTree *tree_ = new TTree(Form("ntuple"),"");
   FlatTree* fevent_ = new FlatTree();
   fevent_->book(tree_);


   if (fChain == 0) return;
   Long64_t nentries = fChain->GetEntriesFast();

   int Testing=0;
   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;

      if(Testing>5000) break;
      Testing++;
//////////////////
      fevent_->clear();
      fevent_->event_   = Event_; 

/////////////////
//check letonic decay
      bool findtop=false, findtopb=false;
      int topN=0, wN=0, leptonic = 0;
      int muonic=0, electronic=0, taunic=0;
      for(int i=0;i<Particle_size;i++ )
      {
         // ttbar dileptonic check 
         if( (Particle_PID[i]==6 && findtop==false ) || (Particle_PID[i]==-6 && findtopb==false))
         {  
            int id1 = Particle_D1[getLastIdX(i,0)];
            int id2 = Particle_D2[getLastIdX(i,0)];
  
            int pdgidD1 = Particle_PID[id1];
            int pdgidD2 = Particle_PID[id2];
            int id11 = Particle_D1[getLastIdX(id1,0)];
            int id12 = Particle_D2[getLastIdX(id1,0)];
            int id21 = Particle_D1[getLastIdX(id2,0)];
            int id22 = Particle_D2[getLastIdX(id2,0)];
            int pdgidD11 = Particle_PID[id11];
            int pdgidD12 = Particle_PID[id12];
            int pdgidD21 = Particle_PID[id21];
            int pdgidD22 = Particle_PID[id22];
            //cout << "id1:"<< id1 <<", id2:"<<id2 << ", pdgidD1:" << pdgidD1 << ", pdgidD2:"<<pdgidD2 <<  ", id11:" << id11 << ", id21:"<< id21 << endl;
            topN++;
            if( (abs(pdgidD1)==24 && abs(pdgidD2)==5) || (abs(pdgidD1)==5 && abs(pdgidD2)==24) )
            {  wN++; 
               if(abs(pdgidD1)==24)
               {
                 if ( abs(pdgidD11) >10 && abs(pdgidD11)<17 && abs(pdgidD12) >10 && abs(pdgidD12)<17 )
                 {
                    if(abs(pdgidD11) >10 && abs(pdgidD11)<13) electronic++;
                    if(abs(pdgidD11) >12 && abs(pdgidD11)<15) muonic++;
                    if(abs(pdgidD11) >14 && abs(pdgidD11)<17) { 
                       taunic++;
                       int id111 = Particle_D1[getLastIdX(id11,0)];
                       int id112 = Particle_D2[getLastIdX(id11,0)];
                       int id121 = Particle_D1[getLastIdX(id12,0)];
                       int id122 = Particle_D2[getLastIdX(id12,0)];

                       int pdgidD111 = Particle_PID[id111];
                       int pdgidD112 = Particle_PID[id112];
                       int pdgidD121 = Particle_PID[id121];
                       int pdgidD122 = Particle_PID[id122];
                       if(abs(pdgidD111) >10 && abs(pdgidD111)<13) electronic++;
                       if(abs(pdgidD121) >10 && abs(pdgidD121)<13) electronic++;
                       if(abs(pdgidD111) >12 && abs(pdgidD111)<15) muonic++;
                       if(abs(pdgidD121) >12 && abs(pdgidD121)<15) muonic++;
                    }
                    //if(debug) cout << "t2w2l: id1: " << pdgidD11 << ", id2: "<< pdgidD21 << endl;
                    //leptonic++;
                 }
               } 
               if(abs(pdgidD2)==24)
               {
                 if ( abs(pdgidD21) >10 && abs(pdgidD21)<17 && abs(pdgidD22) >10 && abs(pdgidD22)<17 )
                 {
                    if(abs(pdgidD21) >10 && abs(pdgidD21)<13) electronic++;
                    if(abs(pdgidD21) >12 && abs(pdgidD21)<15) muonic++;
                    if(abs(pdgidD21) >14 && abs(pdgidD21)<17) {
                       taunic++;
                       int id211 = Particle_D1[getLastIdX(id21,0)];
                       int id212 = Particle_D2[getLastIdX(id21,0)];
                       int id221 = Particle_D1[getLastIdX(id22,0)];
                       int id222 = Particle_D2[getLastIdX(id22,0)];

                       int pdgidD211 = Particle_PID[id211];
                       int pdgidD212 = Particle_PID[id212];
                       int pdgidD221 = Particle_PID[id221];
                       int pdgidD222 = Particle_PID[id222];
                       if(abs(pdgidD211) >10 && abs(pdgidD211)<13) electronic++;
                       if(abs(pdgidD221) >10 && abs(pdgidD221)<13) electronic++;
                       if(abs(pdgidD211) >12 && abs(pdgidD211)<15) muonic++;
                       if(abs(pdgidD221) >12 && abs(pdgidD221)<15) muonic++;
                    }
                    //if(debug) cout << "t2w2l: id1: " << pdgidD21 << ", id2: "<< pdgidD21 << endl;
                    //leptonic++;
                 }
               }
            }
            if(Particle_PID[i]==6) findtop=true;
            if(Particle_PID[i]==-6) findtopb=true;
         }    
/////////////
        /* if( pythia6 && (Particle_PID[i]==24  || Particle_PID[i]==-24) && Particle_D1[i]!=-1 && (Particle_PID[Particle_D1[i]] != Particle_PID[i]) )
         {  wN++;
  
            int pdgidD1 = Particle_PID[i];
            //int pdgidD2 = Particle_PID[i];
            int id11 = Particle_D1[i];
            int id12 = Particle_D2[i];
            //int id21 = Particle_D1[i];
            //int id22 = Particle_D2[i];
            int pdgidD11 = Particle_PID[id11];
            int pdgidD12 = Particle_PID[id12];
            //int pdgidD21 = Particle_PID[id21];
            //int pdgidD22 = Particle_PID[id22];

            if(debug) cout << "status:"<<Particle_Status[i] <<", pdg:"<<pdgidD1 << ",D1 id11:" << id11 <<  ", id12:" << id12 << ", pdgidD12:"<< pdgidD12 << endl; 
            //if(abs(pdgidD1)==24)
            //{
              if ( abs(pdgidD11) >10 && abs(pdgidD11)<17 && abs(pdgidD12) >10 && abs(pdgidD12)<17 )
              {
                 if(abs(pdgidD11) >10 && abs(pdgidD11)<13) electronic++;
                 if(abs(pdgidD11) >12 && abs(pdgidD11)<15) muonic++;
                 if(abs(pdgidD11) >14 && abs(pdgidD11)<17) 
                 { 
                    taunic++;
                    int id111 = Particle_D1[getLastIdX(id11,0)];
                    int id112 = Particle_D2[getLastIdX(id11,0)];
                    int id121 = Particle_D1[getLastIdX(id12,0)];
                    int id122 = Particle_D2[getLastIdX(id12,0)];

                    int pdgidD111 = Particle_PID[id111];
                    int pdgidD112 = Particle_PID[id112];
                    int pdgidD121 = Particle_PID[id121];
                    int pdgidD122 = Particle_PID[id122];
                    if(abs(pdgidD111) >10 && abs(pdgidD111)<13) electronic++;
                    if(abs(pdgidD121) >10 && abs(pdgidD121)<13) electronic++;
                    if(abs(pdgidD111) >12 && abs(pdgidD111)<15) muonic++;
                    if(abs(pdgidD121) >12 && abs(pdgidD121)<15) muonic++;
                 }
                 if(debug) cout << "t2w2l: id1: " << pdgidD11 << ", id2: "<< pdgidD12 << endl;
                 //leptonic++;
              }
         }*/
 
///////////
      }
      //if(debug) cout << "topN: " << topN <<", wN:" << wN << endl;
      fevent_->topN_ = topN;
      fevent_->wN_ = wN;

      leptonic= (electronic+muonic);
      fevent_->leptonic_ = leptonic;
      fevent_->electronic_ = electronic;
      fevent_->muonic_ = muonic;
      fevent_->taunic_ = taunic;

      //cout << "leptonic: "<< leptonic <<", electronic: "<< electronic << ", muonic: "<< muonic << endl;

/////////////////     
      nbjet=0; njet=0;
      nbjet20=0; njet20=0;
      for(int i=0;i<GenJet_size;i++ )
      {
          jet->SetPtEtaPhiM(GenJet_PT[i],GenJet_Eta[i],GenJet_Phi[i],GenJet_Mass[i]);
          fevent_->Pt_gjet_->push_back(GenJet_PT[i]);
          fevent_->Eta_gjet_->push_back(GenJet_Eta[i]);
          fevent_->BH_gjet_->push_back(GenJet_IsBH[i]);

          njet++;
          if(GenJet_PT[i]>20 && fabs(GenJet_Eta[i])<2.5) njet20++;
          if(GenJet_IsBH[i]>0)  
          {
             dr_bh_jet=999.;
             if(GenJet_PT[i]>20 && fabs(GenJet_Eta[i])<2.5) nbjet20++;
             nbjet++;
             for(int j=0;j<BHadron_size;j++ ) 
             {
                TLorentzVector bhadron(BHadron_X[j],BHadron_Y[j],BHadron_Z[j],BHadron_T[j]);
                double dr_bh_jet_= fabs(jet->DeltaR(bhadron));
                if(dr_bh_jet_<dr_bh_jet){ dr_bh_jet=dr_bh_jet_; dpt_bh_jet= (GenJet_PT[i]-BHadron_PT[j]); }
             }
             if(dr_bh_jet<999.)
             {
                 //hDR_genjet_bh->Fill(dr_bh_jet);
                 //fevent_->DR_gjet_BH_->push_back(dr_bh_jet);
                 //fevent_->DPT_gjet_BH_->push_back(dpt_bh_jet);
             }
          }
          fevent_->DR_gjet_BH_->push_back(dr_bh_jet);
          fevent_->DPT_gjet_BH_->push_back(dpt_bh_jet);

      }     
      //hNJet_genjetbh->Fill(nbjet);
      fevent_->Ngenjet_    = njet;
      fevent_->Ngenjet_BH_ = nbjet;
      fevent_->Ngenjet20_    = njet20;
      fevent_->Ngenjet20_BH_ = nbjet20;

      tree_->Fill();


/////////////////////
   }
}
int Delphes::getLastIdX(int idx, int x)
{
   int idx_=idx;   
   int i=0;

   if(x==0)
   {while(i==0)
   {
      if(Particle_PID[Particle_D1[idx_]] != Particle_PID[idx_]) { i=1;  }
      else idx_=Particle_D1[idx_];
   }}
   else 
   {while(i==0)
   {
      if(Particle_PID[Particle_D2[idx_]] != Particle_PID[idx_]) { i=1;  }
      else idx_=Particle_D2[idx_];
   }}

   return idx_;
}
