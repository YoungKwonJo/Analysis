#ifndef CSVWeight_H
#define CSVWeight_H

#include <iostream>
#include <vector>
#include <map>
#include <exception>
#include <cmath> 
#include <iomanip>
#include <algorithm>
#include "TVector.h"
#include "TLorentzVector.h"
#include "TMath.h"
#include "TRandom3.h"
#include "TFile.h"
#include "TH1.h"
#include "TH2.h"
#include "TH1D.h"
#include "TH2D.h"

#include "Jet.h"

typedef std::vector<Jet> Jets;
typedef Jets* JetsP;

bool compByPtJet(Jet a, Jet b)
{
   return a.Pt() > b.Pt();
};

bool compByCSVJet(Jet a, Jet b)
{
   return a.CSV_ > b.CSV_;
};


//typedef vector<cmg::PFJet>::const_iterator JI;

namespace sysType{ enum sysType{ NA, JERup, JERdown, JESup, JESdown, hfSFup, hfSFdown, lfSFdown, lfSFup, TESup, TESdown, CSVLFup, CSVLFdown, CSVHFup, CSVHFdown, CSVHFStats1up, CSVHFStats1down, CSVLFStats1up, CSVLFStats1down, CSVHFStats2up, CSVHFStats2down, CSVLFStats2up, CSVLFStats2down, CSVup, CSVdown, CSVup2, CSVdown2, CSVCErr1up, CSVCErr1down, CSVCErr2up, CSVCErr2down,bOrigin, HFStats3up, HFStats3dw }; }

using namespace std;

class CSVWeight
{
   public: 

    explicit CSVWeight(){
        // CSV reweighting
       
       for( int iSys=0; iSys<9; iSys++ ){
          for( int iPt=0; iPt<5; iPt++ ) h_csv_wgt_hf[iSys][iPt] = NULL;
          for( int iPt=0; iPt<3; iPt++ ){
               for( int iEta=0; iEta<3; iEta++ )h_csv_wgt_lf[iSys][iPt][iEta] = NULL;
          }
       }
       for( int iSys=0; iSys<5; iSys++ )
       {
          for( int iPt=0; iPt<5; iPt++ ) c_csv_wgt_hf[iSys][iPt] = NULL;
       }

       f_CSVwgt_HF = NULL;
       f_CSVwgt_LF = NULL;

       SetUpCSVreweighting(); 
    }
    ~CSVWeight()
    {}

void SetUpCSVreweighting(){

//  f_CSVwgt_HF = TFile::Open ("csv_rwt_hf_ITv2.root");
//  f_CSVwgt_LF = TFile::Open ("csv_rwt_lf_IT.root");
  f_CSVwgt_HF = TFile::Open ("csv_rwt_hf.root");
  f_CSVwgt_LF = TFile::Open ("csv_rwt_lf.root");
  f_SF = TFile::Open ("SF.root");

///////////////////////
  // CSV reweighting
  for( int iSys=0; iSys<9; iSys++ ){
    TString syst_csv_suffix_hf = "final";
    TString syst_csv_suffix_c  = "final";
    TString syst_csv_suffix_lf = "final";
    
    switch( iSys ){
    case 0:
      // this is the nominal case
      break;
    case 1:
      // JESUp
      syst_csv_suffix_hf = "final_JESUp"; syst_csv_suffix_lf = "final_JESUp";
      syst_csv_suffix_c  = "final_cErr1Up";
      break;
    case 2:
      // JESDown
      syst_csv_suffix_hf = "final_JESDown"; syst_csv_suffix_lf = "final_JESDown";
      syst_csv_suffix_c  = "final_cErr1Down";
      break;
    case 3:
      // purity up
      syst_csv_suffix_hf = "final_LFUp"; syst_csv_suffix_lf = "final_HFUp";
      syst_csv_suffix_c  = "final_cErr2Up";
      break;
    case 4:
      // purity down
      syst_csv_suffix_hf = "final_LFDown"; syst_csv_suffix_lf = "final_HFDown";
      syst_csv_suffix_c  = "final_cErr2Down";
      break;
    case 5:
      // stats1 up
      syst_csv_suffix_hf = "final_Stats1Up"; syst_csv_suffix_lf = "final_Stats1Up";
      break;
    case 6:
      // stats1 down
      syst_csv_suffix_hf = "final_Stats1Down"; syst_csv_suffix_lf = "final_Stats1Down";
      break;
    case 7:
      // stats2 up
      syst_csv_suffix_hf = "final_Stats2Up"; syst_csv_suffix_lf = "final_Stats2Up";
      break;
    case 8:
      // stats2 down
      syst_csv_suffix_hf = "final_Stats2Down"; syst_csv_suffix_lf = "final_Stats2Down";
      break;
    }

    for( int iPt=0; iPt<5; iPt++ ) h_csv_wgt_hf[iSys][iPt] = (TH1D*)f_CSVwgt_HF->Get( Form("csv_ratio_Pt%i_Eta0_%s",iPt,syst_csv_suffix_hf.Data()) );
  
    if( iSys<5 ){
     for( int iPt=0; iPt<5; iPt++ ) c_csv_wgt_hf[iSys][iPt] = (TH1D*)f_CSVwgt_HF->Get( Form("c_csv_ratio_Pt%i_Eta0_%s",iPt,syst_csv_suffix_c.Data()) );
    }
    for( int iPt=0; iPt<3; iPt++ ){
      for( int iEta=0; iEta<3; iEta++ )h_csv_wgt_lf[iSys][iPt][iEta] = (TH1D*)f_CSVwgt_LF->Get( Form("csv_ratio_Pt%i_Eta%i_%s",iPt,iEta,syst_csv_suffix_lf.Data()) );
    }

  }
///////////
  for( int iPt=0; iPt<5; iPt++ ) h_csv_sf_hf[iPt] = (TH1D*)f_SF->Get( Form("hHF_CSV_Pt%d_IT3New",iPt) );

  for( int iPt=0; iPt<3; iPt++ ){
    for( int iEta=0; iEta<3; iEta++ )h_csv_sf_lf[iPt][iEta] = (TH1D*)f_SF->Get( Form("hLF_CSV_Pt%d_Eta%d_IT3New",iPt,iEta) );
  }

}
////////////////////////

/////////////////////////
//double GetCSVweight( vector<double>  &jets_pt, vector<double>  &jets_eta,  vector<double>  &jets_bTag,  vector<double>  &jets_partonflavor,const sysType::sysType iSysType)
double GetCSVweight(JetsP jets, const sysType::sysType iSysType)
{
  //if (isData) return 1.0;

  //CheckSetUp();
  // IMPORTANT! iJets is the *SELECTED* jet collection which you use for your analysis
  double bupdw = 1.0;
//  bool usAdEr = false;
  int iSysHF = 0;
  switch(iSysType){
  case sysType::JESup:             iSysHF=1; break;
  case sysType::JESdown:         iSysHF=2; break;
  case sysType::CSVLFup:         iSysHF=3; break;
  case sysType::CSVLFdown:       iSysHF=4; break;
  case sysType::CSVHFStats1up:     iSysHF=5; break;
  case sysType::CSVHFStats1down: iSysHF=6; break;
  case sysType::CSVHFStats2up:     iSysHF=7; break;
  case sysType::CSVHFStats2down: iSysHF=8; break;
  case sysType::CSVup:         iSysHF=4; break;
  case sysType::CSVdown:       iSysHF=3; break;
  case sysType::CSVup2:         iSysHF=3; break;
  case sysType::CSVdown2:       iSysHF=4; break;
//  case sysType::bOrigin:       iSysHF=1; usAdEr=true; break;
  case sysType::HFStats3up: iSysHF = 0; bupdw =1.2; break;
  case sysType::HFStats3dw:  iSysHF = 0; bupdw =0.8; break;
  default : iSysHF = 0; break;
  }

  int iSysC = 0;
  switch(iSysType){
  case sysType::CSVCErr1up:   iSysC=1; break;
  case sysType::CSVCErr1down: iSysC=2; break;
  case sysType::CSVCErr2up:   iSysC=3; break;
  case sysType::CSVCErr2down: iSysC=4; break;
  default : iSysC = 0; break;
  }

  int iSysLF = 0;
  switch(iSysType){
  case sysType::JESup:             iSysLF=1; break;
  case sysType::JESdown:         iSysLF=2; break;
  case sysType::CSVHFup:         iSysLF=3; break;
  case sysType::CSVHFdown:       iSysLF=4; break;
  case sysType::CSVLFStats1up:     iSysLF=5; break;
  case sysType::CSVLFStats1down: iSysLF=6; break;
  case sysType::CSVLFStats2up:     iSysLF=7; break;
  case sysType::CSVLFStats2down: iSysLF=8; break;
  case sysType::CSVup:         iSysLF=4; break;
  case sysType::CSVdown:       iSysLF=3; break;
  case sysType::CSVup2:         iSysLF=4; break;
  case sysType::CSVdown2:       iSysLF=3; break;
  default : iSysLF = 0; break;
  }

  double csvWgthf = 1.;
  double csvWgtC  = 1.;
  double csvWgtlf = 1.;

  for(int i=0;i<jets->size();i++ )
  {
 
    double csv = jets->at(i).CSV_;// iJet->bDiscriminator("combinedSecondaryVertexBJetTags");
    double jetPt = jets->at(i).Pt();// iJet->p4().pt();
    double jetAbsEta = fabs( jets->at(i).Eta());//iJet->p4().eta() );
    int flavor = abs(jets->at(i).flavor_ );//iJet->partonFlavour());
    int iPt = -1; int iEta = -1;
    if(jetPt<30. || jetAbsEta<0. || jetAbsEta > 2.5 ) continue;

    if (jetPt >=30 && jetPt<40) iPt = 0;
    else if (jetPt >=40 && jetPt<60) iPt = 1;
    else if (jetPt >=60 && jetPt<100) iPt = 2;
    else if (jetPt >=100 && jetPt<160) iPt = 3;
    else if (jetPt >=160 ) iPt = 4;

    if (jetAbsEta >=0 &&  jetAbsEta<0.8) iEta = 0;
    else if ( jetAbsEta>=0.8 && jetAbsEta<1.6) iEta = 1;
    else if ( jetAbsEta>=1.6 && jetAbsEta<2.5) iEta = 2;


//       printf(" iJet,\t flavor=%d,\t pt=%.1f,\t abseta=%.2f,\t csv=%.3f",  flavor, jetPt, jetAbsEta, csv );
    if ( (abs(flavor) == 5) ) { //|| abs(flavor) == 4) ) {
      int useCSVBin = (csv>=0.) ? h_csv_wgt_hf[iSysHF][iPt]->FindBin(csv) : 1;
      double iCSVWgtHF = h_csv_wgt_hf[iSysHF][iPt]->GetBinContent(useCSVBin);

      if( iCSVWgtHF!=0 )                      csvWgthf *= iCSVWgtHF*bupdw;

//       printf(",\t wgt=%.2f \n",iCSVWgtHF );
    }
    else if( abs(flavor) == 4 && iSysC<5){
      // do nothing
      int useCSVBin = (csv>=0.) ? c_csv_wgt_hf[iSysC][iPt]->FindBin(csv) : 1;
      double iCSVWgtC = c_csv_wgt_hf[iSysC][iPt]->GetBinContent(useCSVBin);
      if( iCSVWgtC!=0 ) csvWgtC *= iCSVWgtC;

//       printf(",\t wgt=%.2f \n", iCSVWgtC );
    }
    else {
      if (iPt >=2) iPt=2;       /// [30-40], [40-60] and [60-10000] only 3 Pt bins for lf
      int useCSVBin = (csv>=0.) ? h_csv_wgt_lf[iSysLF][iPt][iEta]->FindBin(csv) : 1;
      double iCSVWgtLF = h_csv_wgt_lf[iSysLF][iPt][iEta]->GetBinContent(useCSVBin);
      if( iCSVWgtLF!=0 ) csvWgtlf *= iCSVWgtLF;

    //   printf(",\t wgt=%.2f \n", iCSVWgtLF );
    }
  }

  double csvWgtTotal = csvWgthf * csvWgtC * csvWgtlf;


  return csvWgtTotal;
}
///////////
double GetCSVweight2( vector<double>  &jets_pt, vector<double>  &jets_eta,  vector<double>  &jets_bTag,  vector<double>  &jets_partonflavor){
  //if (isData) return 1.0;

  //CheckSetUp();
  // IMPORTANT! iJets is the *SELECTED* jet collection which you use for your analysis
  double bupdw = 1.0;
//  bool usAdEr = false;

  double csvWgthf = 1.;
  double csvWgtC  = 1.;
  double csvWgtlf = 1.;

  for(int i=0;i<jets_pt.size();i++ )
  {

    double csv = jets_bTag.at(i);// iJet->bDiscriminator("combinedSecondaryVertexBJetTags");

    double jetPt = jets_pt.at(i);// iJet->p4().pt();
    double jetAbsEta = fabs( jets_eta.at(i));//iJet->p4().eta() );
    int flavor = abs(jets_partonflavor.at(i) );//iJet->partonFlavour());
    int iPt = -1; int iEta = -1;
    if(jetPt<30. || jetAbsEta<0. || jetAbsEta > 2.5 || csv<-0.001) continue;

    if (jetPt >=30 && jetPt<40) iPt = 0;
    else if (jetPt >=40 && jetPt<60) iPt = 1;
    else if (jetPt >=60 && jetPt<100) iPt = 2;
    else if (jetPt >=100 && jetPt<160) iPt = 3;
    else if (jetPt >=160 ) iPt = 4;

    if (jetAbsEta >=0 &&  jetAbsEta<0.8) iEta = 0;
    else if ( jetAbsEta>=0.8 && jetAbsEta<1.6) iEta = 1;
    else if ( jetAbsEta>=1.6 && jetAbsEta<2.5) iEta = 2;


//       printf(" iJet,\t flavor=%d,\t pt=%.1f,\t abseta=%.2f,\t csv=%.3f",  flavor, jetPt, jetAbsEta, csv );
    if ( (abs(flavor) == 5)  ){// || abs(flavor) == 4 ) {
      int useCSVBin = (csv>=0.) ? h_csv_sf_hf[iPt]->FindBin(csv) : 1;
      double iCSVWgtHF = h_csv_sf_hf[iPt]->GetBinContent(useCSVBin);

      if( iCSVWgtHF!=0 )                      csvWgthf *= iCSVWgtHF*bupdw;

//       printf(",\t wgt=%.2f \n",iCSVWgtHF );
    }
    else if( abs(flavor) == 4 ){
      // do nothing
      
    }
    else {
      if (iPt >=2) iPt=2;       /// [30-40], [40-60] and [60-10000] only 3 Pt bins for lf
      int useCSVBin = (csv>=0.) ? h_csv_sf_lf[iPt][iEta]->FindBin(csv) : 1;
      double iCSVWgtLF = h_csv_sf_lf[iPt][iEta]->GetBinContent(useCSVBin);
      if( iCSVWgtLF!=0 ) csvWgtlf *= iCSVWgtLF;

    //   printf(",\t wgt=%.2f \n", iCSVWgtLF );
    }
  }

  double csvWgtTotal = csvWgthf * csvWgtC * csvWgtlf;


  return csvWgtTotal;
}

///////////

  private:
        // CSV reweighting
       TH1D* h_csv_wgt_hf[9][5];
       TH1D* c_csv_wgt_hf[9][5];
       TH1D* h_csv_wgt_lf[9][3][3];
       TFile* f_CSVwgt_HF;
       TFile* f_CSVwgt_LF;

       TH1D* h_csv_sf_hf[5];
//       TH1D* c_csv_sf_hf[5];
       TH1D* h_csv_sf_lf[3][3];
       TFile* f_SF;
};
#endif



