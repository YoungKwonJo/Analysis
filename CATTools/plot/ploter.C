#include <TCanvas.h>
#include <TH1F.h>
#include <TLegend.h>
#include <TFile.h>
#include <TPaveText.h>
#include "SampleSet.h"
#include "HistSet.h"
#include "CutSet.h"
#include "Project.h"
#include "ProjectRun.h"
#include <vector>

using namespace std;

void ploter(int cut, int ii) 
{
/*
  gROOT->ProcessLine(".L SampleSet.h+g");
  gROOT->ProcessLine(".L HistSet.h+g");
  gROOT->ProcessLine(".L CutSet.h+g");
  gROOT->ProcessLine(".L Project.h+g");
  gROOT->ProcessLine(".L ProjectRun.h+g");
*/
  gStyle->SetOptStat(0); //remove statistics box
  gROOT->ProcessLine(".L ./tdrstyle.C");
  defaultStyle();
//  gStyle->SetCanvasDefH(610);  gStyle->SetCanvasDefW(900);
////////

  bool logy = true; double lumi = 1000;// 1 /fb
  ProjectRun *pp = new ProjectRun();
  //ProjectRun *pp2 = new ProjectRun();
  std::vector<SampleSet>* samples = pp.samples;

  char* histlist[] ={ "gentop_NJets20" // 0
       ,"lep1_pt","lep2_pt","lep1_eta","lep2_eta","lep1_relIso","lep2_relIso" // 1~6
       ,"ZMass", "MET", "nJet30"  // 7~9
       ,"nbJet30T", "nbJet30M", "nbJet30L" // 10~12
       ,"jet1_pt",  "jet1_eta", "jet1_phi", "jet1_bTag"  // 13~16 
       ,"jet2_pt",  "jet2_eta", "jet2_phi", "jet2_bTag"  // 17~20
       ,"jet3_pt",  "jet3_eta", "jet3_phi", "jet3_bTag"  // 21~24
       ,"jet4_pt",  "jet4_eta", "jet4_phi", "jet4_bTag"  // 25~28
   };
     //S-1 "gentop_NJets20"
     //S0 "lep1_pt", "lep2_pt",""lep1_eta", "lep2_eta","lep1_relIso","lep2_relIso",
     //S1 "ZMass",  "lep1_pt", "lep2_pt", "lep1_eta", "lep2_eta",
     //S2 "ZMass", "MET",  
     //S3 "MET",   "nJet30",
     //S4
     //"nJet30",  "nbJet30T", "nbJet30M", "nbJet30L",
     //"jet1_pt",  "jet1_eta", "jet1_phi", "jet1_bTag",
     //"jet2_pt",  "jet2_eta", "jet2_phi", "jet2_bTag",
     //"jet3_pt",  "jet3_eta", "jet3_phi", "jet3_bTag",
     //"jet4_pt",  "jet4_eta", "jet4_phi", "jet4_bTag",
     //S51 "jet1_bTag", "jet2_bTag", "jet3_bTag", "jet4_bTag",
     //S52 "jet1_bTag", "jet2_bTag", "jet3_bTag", "jet4_bTag",
     //S53 "jet1_bTag", "jet2_bTag", "jet3_bTag", "jet4_bTag",

   char* decays[] = { "MuMu", "ElEl", "MuEl", "LL"};
   char* decays2[] = { "#mu#mu", "ee", "e#mu", "dilepton"};
   char* cutlist[] ={"nocut","S0","S1","S2","S3","S4","S51","S52","S53"};
   TFile *file = TFile::Open("./hist_output.root");
   TH1F *h1[20], *h2[20], *h3[20], *h4[20];
 
   double ymax[4], ymin[4]; 
   //std::vector<TH1F*> h1, h2, h3, h4;
   THStack* hStack[4];
   for(unsigned int j=0;j<4;j++)
      hStack[j]= new THStack(TString("ths_")+decays[j],"");

   for(unsigned int i=0;i<samples.size();i++)
   {
       TString histname = Form("h_%s_%s_%s",samples.at(i).name_.c_str(),cutlist[cut+1],histlist[ii]);
                             //h_wj_S53_jet4_bTag_MuEl
       cout << "histname: " << histname  << endl;
       h1[i] = (TH1F*) file->Get(Form("%s_MuMu",histname.Data()));
       h2[i] = (TH1F*) file->Get(Form("%s_ElEl",histname.Data()));
       h3[i] = (TH1F*) file->Get(Form("%s_MuEl",histname.Data()));
       h4[i] = (TH1F*) file->Get(Form("%s_LL"  ,histname.Data()));

       //h1[i]->SetLineColor(samples.at(i).color_); h2[i]->SetLineColor(samples.at(i).color_);
       //h3[i]->SetLineColor(samples.at(i).color_); h4[i]->SetLineColor(samples.at(i).color_);

       h1[i]->SetFillColor(samples.at(i).color_); h2[i]->SetFillColor(samples.at(i).color_);
       h3[i]->SetFillColor(samples.at(i).color_); h4[i]->SetFillColor(samples.at(i).color_);
       h1[i]->Scale(lumi); h2[i]->Scale(lumi); h3[i]->Scale(lumi); h4[i]->Scale(lumi);
       hStack[0]->Add(h1[i]);
       hStack[1]->Add(h2[i]);
       hStack[2]->Add(h3[i]);
       hStack[3]->Add(h4[i]);

       if(i==0) ymax[0]=h1[i]->GetMaximum(); else if(ymax[0]<h1[i]->GetMaximum()) ymax[0]=h1[i]->GetMaximum();
       if(i==0) ymax[1]=h2[i]->GetMaximum(); else if(ymax[1]<h2[i]->GetMaximum()) ymax[1]=h2[i]->GetMaximum();
       if(i==0) ymax[2]=h3[i]->GetMaximum(); else if(ymax[2]<h3[i]->GetMaximum()) ymax[2]=h3[i]->GetMaximum();
       if(i==0) ymax[3]=h4[i]->GetMaximum(); else if(ymax[3]<h4[i]->GetMaximum()) ymax[3]=h4[i]->GetMaximum();

       if(i==0) ymin[0]=h1[i]->GetMinimum(); else if(ymin[0]>h1[i]->GetMinimum()) ymin[0]=h1[i]->GetMinimum();
       if(i==0) ymin[1]=h2[i]->GetMinimum(); else if(ymin[1]>h2[i]->GetMinimum()) ymin[1]=h2[i]->GetMinimum();
       if(i==0) ymin[2]=h3[i]->GetMinimum(); else if(ymin[2]>h3[i]->GetMinimum()) ymin[2]=h3[i]->GetMinimum();
       if(i==0) ymin[3]=h4[i]->GetMinimum(); else if(ymin[3]>h4[i]->GetMinimum()) ymin[3]=h4[i]->GetMinimum();
   }

   TLegend *leg[4];
   double xmin, xmax;
   xmin = h1[0]->GetXaxis()->GetXmin();
   xmax = h1[0]->GetXaxis()->GetXmax();
   for(unsigned int j=0;j<4;j++)   
   {
      leg[j] = myTLegend(logy, ymax[j], xmin, xmax );
      for(unsigned int i=0;i<samples.size()-1;i++)
      {
         TString label = Form("%s",samples.at(i).label_.c_str());
         if(j==0) leg[j]->AddEntry(h1[i], label, "f");
         if(j==1) leg[j]->AddEntry(h2[i], label, "f");
         if(j==2) leg[j]->AddEntry(h3[i], label, "f");
         if(j==3) leg[j]->AddEntry(h4[i], label, "f");
      } 
   }

   bool all = true;
   TCanvas *c1;
   if(!all)
   {
      c1 = new TCanvas("c1","c1",500,500);
      if(logy) c1->SetLogy();
      if(logy){ h1[0]->SetMaximum(ymax[0]*300);  hStack[0]->SetMaximum(ymax[0]*300);}
      else    { h1[0]->SetMaximum(ymax[0]);      hStack[0]->SetMaximum(ymax[0]);    }
      
      if(logy && ymin[0]>0) { h1[0]->SetMinimum(ymin[0]); hStack[0]->SetMinimum(ymin[0]);}
      else if(logy)         { h1[0]->SetMinimum(0.001);   hStack[0]->SetMinimum(0.001);  }
      
      h1[0]->GetYaxis()->SetTitle("Events");
      h1[0]->Draw();
      hStack[0]->Draw("same");
      leg[0]->Draw();
      getHeader(lumi,"#mu#mu")->Draw();
      c1->Print(Form("MuMu%s%s.eps",cutlist[cut+1],histlist[ii]));
   }
   else {
      c1 = new TCanvas("c1","c1",800,800);
      c1->Divide(2,2);
      for(unsigned int i=0;i<4;i++)
      {
          if(logy) c1->cd(i+1)->SetLogy();
          if(logy){
               if(i==0) h1[0]->SetMaximum(ymax[0]*300); 
               if(i==1) h2[0]->SetMaximum(ymax[1]*300); 
               if(i==2) h3[0]->SetMaximum(ymax[2]*300); 
               if(i==3) h4[0]->SetMaximum(ymax[3]*300); 
               hStack[i]->SetMaximum(ymax[i]*300);
          }
          else    {
               if(i==0) h1[0]->SetMaximum(ymax[0]);
               if(i==1) h2[0]->SetMaximum(ymax[1]);
               if(i==2) h3[0]->SetMaximum(ymax[2]);
               if(i==3) h4[0]->SetMaximum(ymax[3]);
               hStack[i]->SetMaximum(ymax[i]);    
          }
          
          if(logy && ymin[i]>0) { 
               if(i==0) h1[0]->SetMinimum(ymin[0]);
               if(i==1) h2[0]->SetMinimum(ymin[1]);
               if(i==2) h3[0]->SetMinimum(ymin[2]);
               if(i==3) h4[0]->SetMinimum(ymin[3]);
               hStack[i]->SetMinimum(ymin[i]);
          }
          else if(logy) {
               if(i==0) h1[0]->SetMinimum(0.001);
               if(i==1) h2[0]->SetMinimum(0.001);
               if(i==2) h3[0]->SetMinimum(0.001);
               if(i==3) h4[0]->SetMinimum(0.001);
               hStack[i]->SetMinimum(0.001); 
          }
          if(i==0){ h1[0]->GetYaxis()->SetTitle("Events"); h1[0]->Draw(); }
          if(i==1){ h2[0]->GetYaxis()->SetTitle("Events"); h2[0]->Draw(); }
          if(i==2){ h3[0]->GetYaxis()->SetTitle("Events"); h3[0]->Draw(); }
          if(i==3){ h4[0]->GetYaxis()->SetTitle("Events"); h4[0]->Draw(); }

          hStack[i]->Draw("same");
          leg[i]->Draw();
          getHeader(lumi,decays2[i])->Draw();       
      }
      c1->Print(Form("./plots/%s%s.eps",cutlist[cut+1],histlist[ii]));
   }

}
TLegend* myTLegend(bool logy, double ymax, double xmin, double xmax )
{
  double weighty=1.; if(logy) weighty=0.007;
//  double xmax = h1[4]->GetXaxis()->GetXmax();
//  double ymax = h1[4]->GetMaximum();

  double legxmin=(xmax-xmin)*0.68, legxmax=(xmax-xmin)*0.98, legymin=ymax*1.01*weighty, legymax=ymax*1.15;
  if(logy) { legxmin=(xmax-xmin)*0.68, legxmax=(xmax-xmin)*0.98, legymin=ymax*weighty*5, legymax=ymax*100; }

  TLegend* leg = new TLegend(legxmin,legymin, legxmax,legymax, NULL,"");
  leg->SetBorderSize(1); leg->SetTextFont(62);  leg->SetTextSize(0.04);
  leg->SetLineColor(0);  leg->SetLineStyle(1);  leg->SetLineWidth(1);  leg->SetFillColor(0);
  leg->SetFillStyle(1001);
  return leg;
}
TPaveText* myTPaveText(double nume, double denom)
{
  TPaveText* pt = new TPaveText(0.18,0.75,0.18,0.87,"brNDC");
  pt->SetBorderSize(1);   pt->SetTextFont(42);
  pt->SetTextSize(0.04);  pt->SetLineColor(0);
  pt->SetLineStyle(1);    pt->SetLineWidth(1);
  pt->SetFillColor(0);    pt->SetFillStyle(1001);
  pt->SetTextAlign(12);
  //pt->AddText("CMS Preliminary");
  pt->AddText(Form("ttbb/ttjj = %.5f",nume/denom));
  return pt;
}
TPaveText* getHeader(double lumi, TString channelName)
{
  TPaveText* pt = new TPaveText(0.18,0.75,0.18,0.88,"brNDC");

  pt->SetBorderSize(1);
  pt->SetTextFont(42);
  pt->SetTextSize(0.04);
  pt->SetLineColor(0);
  pt->SetLineStyle(1);
  pt->SetLineWidth(1);
  pt->SetFillColor(0);
  pt->SetFillStyle(1001);
  pt->SetTextAlign(12);
  pt->AddText("CMS Preliminary");
  pt->AddText(Form("%.1f fb^{-1} at  #sqrt{s} = 13 TeV", lumi/1000));
  if ( channelName != "" ) pt->AddText(channelName);

  return pt;
}
