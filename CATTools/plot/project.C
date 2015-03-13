#include <TCanvas.h>
#include <TH1F.h>
#include <TLegend.h>
#include <TPaveText.h>
#include "SampleSet.h"
#include "HistSet.h"
#include "CutSet.h"
#include "Project.h"
#include <vector>

using namespace std;

void project(int iii, int jjj)
{
  std::vector<TH1F*> result ;
  result = projectlist(iii, jjj);

  TFile fout(Form("hist_S%d%d_output.root",iii,jjj), "RECREATE");
  for(unsigned int i =0;i<result.size();i++) result.at(i)->Write();
  fout.Write();
  fout.Close();

}
std::vector<TH1F*> projectlist(int iii, int jjj)
{
  gROOT->ProcessLine(".L SampleSet.h+g");
  gROOT->ProcessLine(".L HistSet.h+g");
  gROOT->ProcessLine(".L CutSet.h+g");
  gROOT->ProcessLine(".L Project.h+g");
  gROOT->ProcessLine(".L ProjectRun.h+g");

  gStyle->SetOptStat(0); //remove statistics box
  gROOT->ProcessLine(".L ./tdrstyle.C");
  defaultStyle();
//  gStyle->SetCanvasDefH(610);  gStyle->SetCanvasDefW(900);
////////

  bool log = true;
  std::vector<TH1F*> result ;
  ProjectRun *pp = new ProjectRun();
  ProjectRun *pp2 = new ProjectRun();
  if(iii==0)
  {
     //result =pp->proj2h1(result,"gentop_NJets20","# of Jet in GEN","Entries",15,0,15,log,0);
     //result =pp->proj2h1(result,"nJet30","# of Jet30","Entries",10,0,10,log,4);
     //result =pp->proj2h1(result,"nbJet30T","# of bTag CSVT","Entries",5,0,5,log,5);
     //result =pp->proj2h1(result,"MET","MET","Entries",30,0,150,log,3);
     //result =pp->proj2h1(result,"ZMass","invariant mass of dilepton","Entries",50,0,200,log,2);
     //S-1
     //result = pp->proj2h1(result,"gentop_NJets20","# of Jet in GEN","Entries",15,0,15,log,-1);
     //result.insert(result.end(),result1[0].begin(),result1[0].end());
   
     //return result;
   
     //break;
     //S0
      result = pp->proj2h1(result,"lep1_pt","p_T of leading lepton","Entries",40,0,200,log,0);
     //return result;
     //break;
      result = pp->proj2h1(result,"lep2_pt","p_T of second leading lepton","Entries",40,0,200,log,0);
      result = pp->proj2h1(result,"lep1_eta","#eta of leading lepton","Entries",35,-3.5,3.5,log,0);
      result = pp->proj2h1(result,"lep2_eta","#eta of second leading lepton","Entries",35,-3.5,3.5,log,0);
      result = pp->proj2h1(result,"lep1_relIso","Iso30_{rel} of leading lepton","Entries",50,0,5,log,0);
      result = pp->proj2h1(result,"lep2_relIso","Iso30_{rel} of second leading lepton","Entries",50,0,5,log,0);
   }
   if(iii==1)
   {
      //S1
      result = pp->proj2h1(result,"ZMass","invariant mass of dilepton","Entries",40,0,200,log,1);
      result = pp->proj2h1(result,"lep1_pt","p_T of leading lepton","Entries",40,0,200,log,1);
      result = pp->proj2h1(result,"lep2_pt","p_T of second leading lepton","Entries",40,0,200,log,1);
      result = pp->proj2h1(result,"lep1_eta","#eta of leading lepton","Entries",35,-3.5,3.5,log,1);
      result = pp->proj2h1(result,"lep2_eta","#eta of second leading lepton","Entries",35,-3.5,3.5,log,1);
   }
   if(iii==2)
   {
      //S2
      result = pp->proj2h1(result,"ZMass","invariant mass of dilepton","Entries",40,0,200,log,2);
      result = pp->proj2h1(result,"MET","MET","Entries",30,0,150,log,2);
   }
   if(iii==3)
   {
      //S3
      result = pp->proj2h1(result,"MET","MET","Entries",30,0,150,log,3);
      result = pp->proj2h1(result,"nJet30","# of Jet30","Entries",10,0,10,log,3);
   }
   if(iii==4)
   {
      //S4
      if(jjj==0)
      {
         result = pp->proj2h1(result,"nJet30","# of Jet30","Entries",10,0,10,log,4);
         result = pp->proj2h1(result,"nbJet30T","# of bTag CSVT","Entries",5,0,5,log,4);
         result = pp->proj2h1(result,"nbJet30M","# of bTag CSVM","Entries",7,0,7,log,4);
         result = pp->proj2h1(result,"nbJet30L","# of bTag CSVL","Entries",7,0,7,log,4);
      }
      if(jjj==1)
      {         
         result = pp->proj2h1(result,"jet1_pt","p_T of 1st jet","Entries",40,0,200,log,4);
         result = pp->proj2h1(result,"jet2_pt","p_T of 2nd jet","Entries",40,0,200,log,4);
         result = pp2->proj2h1(result,"jet3_pt","p_T of 3rd jet","Entries",50,0,200,log,4);
         result = pp2->proj2h1(result,"jet4_pt","p_T of 4th jet","Entries",50,0,200,log,4);
      }
      if(jjj==2)
      {
         result = pp->proj2h1(result,"jet1_eta","#eta of 1st jet","Entries",10,-3.5,3.5,log,4);
         result = pp->proj2h1(result,"jet2_eta","#eta of 2nd jet","Entries",10,-3.5,3.5,log,4);
         result = pp2->proj2h1(result,"jet3_eta","#eta of 3rd jet","Entries",10,-3.5,3.5,log,4);
         result = pp2->proj2h1(result,"jet4_eta","#eta of 4th jet","Entries",25,-3.5,3.5,log,4);
      }
      if(jjj==3)
      {  
         result = pp->proj2h1(result,"jet1_phi","#phi of 1st jet","Entries",18,-4.5,4.5,log,4);
         result = pp2->proj2h1(result,"jet2_phi","#phi of 2nd jet","Entries",18,-4.5,4.5,log,4);
         result = pp2->proj2h1(result,"jet3_phi","#phi of 3rd jet","Entries",18,-4.5,4.5,log,4);
         result = pp2->proj2h1(result,"jet4_phi","#phi of 4th jet","Entries",18,-4.5,4.5,log,4);
      }
      if(jjj==4)
      {
         result = pp->proj2h1(result,"jet1_bTag","CSV of 1st jet","Entries",10,0,1,log,4);
         result = pp2->proj2h1(result,"jet2_bTag","CSV of 2nd jet","Entries",10,0,1,log,4);
         result = pp2->proj2h1(result,"jet3_bTag","CSV of 3rd jet","Entries",10,0,1,log,4);
         result = pp2->proj2h1(result,"jet4_bTag","CSV of 4th jet","Entries",10,0,1,log,4);
      }
   }
   if(iii==5)
   {
      //S51
      result = pp->proj2h1(result,"jet1_bTag","CSV of 1st jet","Entries",10,0,1,log,5);
      result = pp->proj2h1(result,"jet2_bTag","CSV of 2nd jet","Entries",10,0,1,log,5);
      result = pp->proj2h1(result,"jet3_bTag","CSV of 3rd jet","Entries",10,0,1,log,5);
      result = pp->proj2h1(result,"jet4_bTag","CSV of 4th jet","Entries",10,0,1,log,5);
   }
   if(iii==6)
   {
      //S52
      result = pp->proj2h1(result,"jet1_bTag","CSV of 1st jet","Entries",10,0,1,log,6);
      result = pp->proj2h1(result,"jet2_bTag","CSV of 2nd jet","Entries",10,0,1,log,6);
      result = pp->proj2h1(result,"jet3_bTag","CSV of 3rd jet","Entries",10,0,1,log,6);
      result = pp->proj2h1(result,"jet4_bTag","CSV of 4th jet","Entries",10,0,1,log,6);
   }
   if(iii==7)
   {
      //S53
      result = pp->proj2h1(result,"jet1_bTag","CSV of 1st jet","Entries",10,0,1,log,7);
      result = pp->proj2h1(result,"jet2_bTag","CSV of 2nd jet","Entries",10,0,1,log,7);
      result = pp->proj2h1(result,"jet3_bTag","CSV of 3rd jet","Entries",10,0,1,log,7);
      result = pp->proj2h1(result,"jet4_bTag","CSV of 4th jet","Entries",10,0,1,log,7);
   }
  return result;
}

