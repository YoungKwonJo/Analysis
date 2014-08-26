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
#include "plot.h"
//#include "plot2.h"

void ploter(int pp=0)
{
  MonitorPlot ZMass = MonitorPlot("ZMass", "ZMass", "Dilepton mass;Dilepton Mass (GeV/c^{2});Events/5 GeV/c^{2}", 20, 0, 250);
  MonitorPlot nJet = MonitorPlot("nJet", "nJet30", "Jet Multiplicity;Jet Multiplicity;Events", 13, 0, 13);

  MonitorPlot pt1 = MonitorPlot("pt1", "lep1_pt", "Leading lepton p_{T};p_{T} (GeV/c);Events/5 GeV/c", 20, 0, 100);
  MonitorPlot pt2 = MonitorPlot("pt2", "lep2_pt", "Second leading lepton p_{T};p_{T} (GeV/c);Events/5 GeV/c", 20, 0, 100);
  MonitorPlot eta1 = MonitorPlot("eta1", "lep1_eta", "Leading #eta;#eta;Events/0.2", 35, -3.5, 3.5);
  MonitorPlot eta2 = MonitorPlot("eta2", "lep2_eta", "Second leading lepton #eta;#eta;Events/0.2", 35, -3.5, 3.5);

  MonitorPlot jet1pt30 = MonitorPlot("jet1pt30", "jet1_pt", "Leading Jet p_{T}; p_{T}^{jet1} (GeV/c);Events/10 GeV/c",24, 20, 500);
  MonitorPlot jet1eta30 = MonitorPlot("jet1eta30", "jet1_eta", "Leading #eta;#eta^{jet1};Events/0.2", 35, -3.5, 3.5);
  MonitorPlot jet1phi30 = MonitorPlot("jet1phi30", "jet1_phi", "Leading #phi;#phi (Radian);Events/0.2 rad.", 35, -3.5, 3.5);

  MonitorPlot jet2pt30 = MonitorPlot("jet2pt30", "jet2_pt", "Second leading Jet p_{T}; p_{T}^{jet2} (GeV/c);Events/10 GeV/c",24, 20, 500);
  MonitorPlot jet2eta30 = MonitorPlot("jet2eta30", "jet2_eta", "Second leading Jet #eta;#eta;Events/0.2", 35, -3.5, 3.5);
  MonitorPlot jet2phi30 = MonitorPlot("jet2phi30", "jet2_phi", "Second leading Jet #phi;#phi (Radian);Events/0.2 rad.", 35, -3.5, 3.5);

  MonitorPlot jet3pt30 = MonitorPlot("jet3pt30", "jet3_pt", "Third Jet p_{T}; p_{T}^{jet3} (GeV/c);Events/10 GeV/c",24, 20, 500);
  MonitorPlot jet3eta30 = MonitorPlot("jet3eta30", "jet3_eta", "Third Jet #eta;#eta;Events/0.2", 35, -3.5, 3.5);
  MonitorPlot jet3phi30 = MonitorPlot("jet3phi30", "jet3_phi", "Third Jet#phi;#phi (Radian);Events/0.2 rad.", 35, -3.5, 3.5);

  MonitorPlot jet4pt30 = MonitorPlot("jet4pt30", "jet4_pt", "Fourth Jet p_{T}; p_{T}^{jet4} (GeV/c);Events/10 GeV/c",24, 20, 500);
  MonitorPlot jet4eta30 = MonitorPlot("jet4eta30", "jet4_eta", "Fourth Jet #eta;#eta;Events/0.2", 35, -3.5, 3.5);
  MonitorPlot jet4phi30 = MonitorPlot("jet4phi30", "jet4_phi", "Fourth Jet #phi;#phi (Radian);Events/0.2 rad.", 35, -3.5, 3.5);

  //MonitorPlot2 nJetvgnJet = MonitorPlot("nJetvgnJet", "nJet30:gnJet30","Gen. vs. Reco.;Reco. Jet Multiplicity;Gen. Jet Multiplicity", 13, 0, 13, 13, 0, 13 );
  MonitorPlot MyPlots[] = {jet1pt30, jet2pt30,jet1eta30};

  TFile* f[5];  TTree* tree[5];  TH1F*  h[5];
  int mcN=5;
  TString fname[5] = {"ttbb_loop_sm","ttbb_loop_sm_cut_bq","tth_loop_sm","tth_loop_sm_cut_bq","ttjj_loop_sm"};
  TString label[5] = {"t#bar{t} + b#bar{b}","t#bar{t} + b#bar{b} w/ cut","t#bar{t} + H","t#bar{t} + H w/ cut","t#bar{t} + jj"};
  const Color_t color[] = {
    kRed,kRed-4,kBlue,kBlue-7, kGreen+2
  };
  const int     style[] = {
    1,  2,  1, 2, 1
  };
  const double width[] = {
    3,1, 3,1, 3
  };

  gStyle->SetOptStat(0); //remove statistics box
  gROOT->ProcessLine(".L ./tdrstyle.C");
  defaultStyle();
  gStyle->SetCanvasDefH(500);
  gStyle->SetCanvasDefW(500);
  gStyle->SetPadGridX(true);
  gStyle->SetPadGridY(true);
  gStyle->SetGridColor(kGray+1);
/////////
  TCut dileptonic = "(leptonic>0)"; 
  TCut reco_njet4 = "nJet30>3";
  TCut reco_njet0 = "nJet30>-1";
  TCut selction  = "lep1_pt>20 && lep2_pt>20 && abs(lep1_eta)<2.5 && abs(lep2_eta)<2.5" && dileptonic && reco_njet0; 
  for(int i=0;i<mcN;i++)
  {
    cout <<"opening file : "<< fname[i].Data() ;
    f[i] = new TFile(Form("./result_%s.root",fname[i].Data()));
    cout <<", getting the tree. ";
    tree[i] = (TTree*) f[i]->Get(Form("ntuple"));
    //h[i] = plot(nJet,fname[i],tree[i],selction);  
    //h[i] = plot(jet1pt30,fname[i],tree[i],selction);  
    h[i] = plot(MyPlots[pp],fname[i],tree[i],selction);  
  }
////////


  double ymax=0.1, ymin=0.0001;
  for(int i=0;i<mcN;i++)
  {
    h[i]->GetYaxis()->SetTitle("Normalized to unity");
    h[i]->SetTitle("");
    h[i]->Scale(1/h[i]->Integral());
    h[i]->SetLineColor(color[i]);
    h[i]->SetLineWidth(width[i]);
    h[i]->SetLineStyle(style[i]);

    if(ymax < h[i]->GetMaximum() ) ymax = h[i]->GetMaximum();
  }
  h[0]->SetMaximum(ymax*1.5);
  h[0]->SetMinimum(ymin);
  double xmax = h[0]->GetXaxis()->GetXmax();
  double xmin = h[0]->GetXaxis()->GetXmin();

////////
  const double xs=0.05, ys=0.05;
  const double xo=1.2,  yo=0.0;
  h[0]->GetXaxis()->SetTitleSize(xs*1.1);
  h[0]->GetYaxis()->SetTitleSize(ys*1.1);
  h[0]->GetXaxis()->SetTitleOffset(xo);
//  h[0]->GetYaxis()->SetTitleOffset(yo);

  h[0]->GetYaxis()->SetLabelSize(xs);
  h[0]->GetXaxis()->SetLabelSize(ys);
//  h[0]->GetXaxis()->SetLabelOffset(xo);
//  h[0]->GetYaxis()->SetLabelOffset(yo);

//////
  bool logy = false;
  TCanvas *c1 = new TCanvas();
  if(logy) c1->SetLogy();

//////
  double weighty=1.; if(logy) weighty=0.01;
  double legxmin=(xmax+xmin)*0.60, legxmax=xmax*0.97, legymin=h[0]->GetMaximum()*0.65*weighty, legymax=h[0]->GetMaximum()*0.95;
  TLegend* leg = new TLegend(legxmin,legymin, legxmax,legymax, NULL,"");
  leg->SetBorderSize(1);  leg->SetTextFont(62);  leg->SetTextSize(0.04);
  leg->SetLineColor(0);  leg->SetLineStyle(1);  leg->SetLineWidth(1);  leg->SetFillColor(0);
  leg->SetFillStyle(1001);
//////

  for(int i=0;i<mcN;i++)
  {
    if(i==0) h[i]->Draw();  
    else     h[i]->Draw("same");  
    leg->AddEntry(h[i], label[i], "l");
  }
  leg->Draw();

}


