#include "TROOT.h"
#include "TSystem.h"

#include "TCut.h"
#include "TFile.h"
#include "TChain.h"
#include "TTree.h"

#include "TCanvas.h"
#include "TPad.h"
#include "TLegend.h"
#include "TH1F.h"
#include "THStack.h"
#include "TGraph.h"

#include <iostream>
#include <fstream>
#include <set>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include "tdrstyle.C"
//#include "plot.h"
#include "plot2.h"

void ploter2()
{

  MonitorPlot2 nJetvgnJet = MonitorPlot2("nJetvgnJet", "gnJet30:nJet30","Gen. vs. Reco.;Reco. Jet Multiplicity;Gen. Jet Multiplicity", 13, 0, 13, 13, 0, 13 );

  TFile* f[5];  TTree* tree[5];  TH2F*  h[5];
  int mcN=5;
  TString fname[5] = {"ttbb_loop_sm","ttbb_loop_sm_cut_bq","tth_loop_sm","tth_loop_sm_cut_bq","ttjj_loop_sm"};
  TString label[5] = {"t#bar{t} + b#bar{b}","t#bar{t} + b#bar{b} w/ cut","t#bar{t} + H","t#bar{t} + H w/ cut","t#bar{t} + jj"};
/*  const Color_t color[] = {
    kRed,kRed-7,kBlue,kBlue-7
  };
  const int     style[] = {
    1,  2,  1, 2
  };*/

  gStyle->SetOptStat(0); //remove statistics box
  gROOT->ProcessLine(".L ./tdrstyle.C");
  defaultStyle();
  gStyle->SetCanvasDefH(610);
  gStyle->SetCanvasDefW(900);
  //gStyle->SetPadGridX(true);
  //gStyle->SetPadGridY(true);
  //gStyle->SetGridColor(kGray+1);
/////////
  TCut dileptonic = "(leptonic>0)"; 
  TCut reco_njet4 = "nJet30>3";
  //TCut selction  = "lep1_pt>20 && lep2_pt>20 && abs(lep1_eta)<2.5 && abs(lep2_eta)<2.5" && dileptonic && reco_njet4; 
  TCut selction  = "lep1_pt>20 && lep2_pt>20 && abs(lep1_eta)<2.5 && abs(lep2_eta)<2.5" && dileptonic ;//&& reco_njet4; 
  for(int i=0;i<mcN;i++)
  {
    cout <<"opening file : "<< fname[i].Data() ;
    f[i] = new TFile(Form("./result_%s.root",fname[i].Data()));
    cout <<", getting the tree. ";
    tree[i] = (TTree*) f[i]->Get(Form("ntuple"));
    h[i] = plot2(nJetvgnJet,fname[i],tree[i],selction);  
  }
//////
  //bool logy = false;
  TCanvas *c1 = new TCanvas();
  c1->Divide(3,2);
  //if(logy) c1->SetLogy();

//////
  double weighty=1.; //if(logy) weighty=0.01;
  double xmax = h[0]->GetXaxis()->GetXmax();
  double ymax = h[0]->GetYaxis()->GetXmax();
  double legxmin=xmax*0.60, legxmax=xmax*0.97, legymin=ymax*1.01*weighty, legymax=ymax*1.15;
  TLegend* leg[5];

  for(int i=0;i<mcN;i++)
  {
    c1->cd(i+1);
    h[i]->Draw("colz");  
    leg[i] = new TLegend(legxmin,legymin, legxmax,legymax, NULL,"");
    leg[i]->SetBorderSize(1);  leg[i]->SetTextFont(62);  leg[i]->SetTextSize(0.04);
    leg[i]->SetLineColor(0);  leg[i]->SetLineStyle(1);  leg[i]->SetLineWidth(1);  leg[i]->SetFillColor(0);
    leg[i]->SetFillStyle(1001);

    leg[i]->AddEntry(h[i], label[i], "");
    leg[i]->Draw();
  }

  c1->Print("GenJetVSRecoJet.eps");
}


