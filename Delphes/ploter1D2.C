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

void ploter1D2()
{
  MonitorPlot ZMass = MonitorPlot("ZMass", "ZMass", "Dilepton mass;Dilepton Mass (GeV/c^{2});Events/5 GeV/c^{2}", 20, 0, 250);
  MonitorPlot nJet = MonitorPlot("nJet", "nJet30", "Jet Multiplicity;Jet Multiplicity;Events", 13, 0, 13);

  MonitorPlot pt1 = MonitorPlot("pt1", "lep1_pt", "Leading lepton p_{T};p_{T} (GeV/c);Events/5 GeV/c", 20, 0, 100);
  MonitorPlot pt2 = MonitorPlot("pt2", "lep2_pt", "Second leading lepton p_{T};p_{T} (GeV/c);Events/5 GeV/c", 20, 0, 100);
  MonitorPlot eta1 = MonitorPlot("eta1", "lep1_eta", "Leading #eta;#eta;Events/0.2", 35, -3.5, 3.5);
  MonitorPlot eta2 = MonitorPlot("eta2", "lep2_eta", "Second leading lepton #eta;#eta;Events/0.2", 35, -3.5, 3.5);

  MonitorPlot jet1pt30 = MonitorPlot("jet1pt30", "jet1_pt", "Leading jet p_{T};p_{T} (GeV/c);Events/10 GeV/c",48, 20, 500);
  MonitorPlot jet1eta30 = MonitorPlot("jet1eta30", "jet1_eta", "Leading #eta;#eta;Events/0.2", 35, -3.5, 3.5);
  MonitorPlot jet1phi30 = MonitorPlot("jet1phi30", "jet1_phi", "Leading #phi;#phi (Radian);Events/0.2 rad.", 35, -3.5, 3.5);

  MonitorPlot jet2pt30 = MonitorPlot("jet2pt30", "jet2_pt", "Second leading jet p_{T};p_{T} (GeV/c);Events/10 GeV/c",48, 20, 500);
  MonitorPlot jet2eta30 = MonitorPlot("jet2eta30", "jet2_eta", "Second leading jet #eta;#eta;Events/0.2", 35, -3.5, 3.5);
  MonitorPlot jet2phi30 = MonitorPlot("jet2phi30", "jet2_phi", "Second leading jet #phi;#phi (Radian);Events/0.2 rad.", 35, -3.5, 3.5);

  MonitorPlot jet3pt30 = MonitorPlot("jet3pt30", "jet3_pt", "Third jet p_{T};p_{T} (GeV/c);Events/10 GeV/c",48, 20, 500);
  MonitorPlot jet3eta30 = MonitorPlot("jet3eta30", "jet3_eta", "Third jet #eta;#eta;Events/0.2", 35, -3.5, 3.5);
  MonitorPlot jet3phi30 = MonitorPlot("jet3phi30", "jet3_phi", "Third jet #phi;#phi (Radian);Events/0.2 rad.", 35, -3.5, 3.5);

  MonitorPlot jet4pt30 = MonitorPlot("jet4pt30", "jet4_pt", "Fourth jet p_{T};p_{T} (GeV/c);Events/10 GeV/c",48, 20, 500);
  MonitorPlot jet4eta30 = MonitorPlot("jet4eta30", "jet4_eta", "Fourth jet #eta;#eta;Events/0.2", 35, -3.5, 3.5);
  MonitorPlot jet4phi30 = MonitorPlot("jet4phi30", "jet4_phi", "Fourth jet #phi;#phi (Radian);Events/0.2 rad.", 35, -3.5, 3.5);


  MonitorPlot nJetBH =     MonitorPlot("nJetBH",     "nJet30BH",   "Jet Multiplicity matching BHad;# of GenJet from b hadron;Events", 13, 0, 13);
  MonitorPlot nJetBQ =     MonitorPlot("nJetBQ",     "nJet30BQ",   "Jet Multiplicity matching BQad;# of GenJet from b quark;Events", 13, 0, 13);
  MonitorPlot nJetBTQ =    MonitorPlot("nJetBTQ",    "nJet30BTQ",  "Jet Multiplicity matching BTQad;# of GenJet from top quark;Events", 13, 0, 13);
  MonitorPlot nJetBHiggs = MonitorPlot("nJetBHiggs", "nJet30BHiggs", "Jet Multiplicity matching BHiggss;# of GenJet from higgs;Events", 13, 0, 13);

  MonitorPlot nJetCH =     MonitorPlot("nJetCH",     "nJet30CH",   "Jet Multiplicity matching CHad;# of GenJet from c hadron;Events", 13, 0, 13);
  MonitorPlot nJetCQ =     MonitorPlot("nJetCQ",     "nJet30CQ",   "Jet Multiplicity matching CQad;# of GenJet from c quark;Events", 13, 0, 13);
  MonitorPlot nJetCTQ =    MonitorPlot("nJetCTQ",    "nJet30CTQ",  "Jet Multiplicity matching CTQad;# of GenJet from top quark;Events", 13, 0, 13);
  MonitorPlot nJetCHiggs = MonitorPlot("nJetCHiggs", "nJet30CHiggs", "Jet Multiplicity matching CHiggss;# of GenJet from higgs;Events", 13, 0, 13);

  MonitorPlot gnJet =       MonitorPlot("gnJet",       "gnJet30",    "Jet Multiplicity;# of GenJet;Events", 13, 0, 13);
  MonitorPlot gnJetBH =     MonitorPlot("gnJetBH",     "gnJet30BH",  "Jet Multiplicity matching BHad;# of GenJet from b hadron;Events", 13, 0, 13);
  MonitorPlot gnJetBQ =     MonitorPlot("gnJetBQ",     "gnJet30BQ",  "Jet Multiplicity matching BQad;# of GenJet from b quark;Events", 13, 0, 13);
  MonitorPlot gnJetBTQ =    MonitorPlot("gnJetBTQ",    "gnJet30BTQ", "Jet Multiplicity matching BTQad;# of GenJet from top quark;Events", 13, 0, 13);
  MonitorPlot gnJetBHiggs = MonitorPlot("gnJetBHiggs", "gnJet30BHiggs", "Jet Multiplicity matching BHiggss;# of GenJet from higgs;Events", 13, 0, 13);
  MonitorPlot gnJetBTQHiggs = MonitorPlot("gnJetBTQHiggs", "gnJet30BTHiggs", "Jet Multiplicity matching BHiggss;# of GenJet from higgs and top;Events", 13, 0, 13);
  MonitorPlot gnJetBOverlap = MonitorPlot("gnJetBOverlap", "gnJetOverlap", "Jet Multiplicity matching BHiggss;# of GenJet from overlaped BB;Events", 13, 0, 13);
  MonitorPlot gnJetBNTQ     = MonitorPlot("gnJetBNTQ", "gnJetBNTQ", "Jet Multiplicity matching BHiggss;# of GenJet not from top;Events", 13, 0, 13);
  MonitorPlot gnJetBNTQOverlap = MonitorPlot("gnJetBNTQOverlap","gnJetBNTQOverlap","Jet Multiplicity matching BHiggss;# of GenJet(ovelaped BB) not from top;Events", 13, 0, 13);

  MonitorPlot gnJetCH =     MonitorPlot("gnJetCH",     "gnJet30CH",   "Jet Multiplicity matching CHad;# of GenJet from c hadron;Events", 13, 0, 13);
  MonitorPlot gnJetCQ =     MonitorPlot("gnJetCQ",     "gnJet30CQ",   "Jet Multiplicity matching CQad;# of GenJet from c quark;Events", 13, 0, 13);
  MonitorPlot gnJetCTQ =    MonitorPlot("gnJetCTQ",    "gnJet30CTQ",  "Jet Multiplicity matching CTQad;# of GenJet from top quark;Events", 13, 0, 13);
  MonitorPlot gnJetCHiggs = MonitorPlot("gnJetCHiggs", "gnJet30CHiggs", "Jet Multiplicity matching CHiggss;# of GenJet from higgs;Events", 13, 0, 13);

  MonitorPlot gnBQ =       MonitorPlot("gnBQ1st",       "NgBQ1st",    "# of b;# of b;Events", 13, 0, 13);
  MonitorPlot gBQ1st_M1fromT = MonitorPlot("gBQ1st_M1fromT", "gBQ1st_M1fromT", "Dijet mass from top; M_{bb^{from t}}  (GeV/c^{2});Events/10 GeV/c^{2}", 50, 0, 500);
  MonitorPlot gBQ1st_DR1fromT = MonitorPlot("gBQ1st_DR1fromT", "gBQ1st_DR1fromT", "Dijet DR from top;#Delta R_{bb^{from t}} ;Events ", 50, 0, 10);
  MonitorPlot gBQ1st_M2add = MonitorPlot("gBQ1st_M2add", "gBQ1st_M2add", "Dijet mass not from top;  M_{bb^{not from t}} (GeV/c^{2});Events/10 GeV/c^{2}", 50, 0, 500);
  MonitorPlot gBQ1st_DR2add = MonitorPlot("gBQ1st_DR2add", "gBQ1st_DR2add", "Dijet DR not from top; #Delta R_{bb^{not from t}} ;Events ", 50, 0, 10);

  int mcN=5;
  TFile* f[mcN];  TTree* tree[mcN]; 
  TH1F  *h[mcN], *h2[mcN], *h3[mcN], *h4[mcN], *hmcN[mcN], *h6[mcN], *h7[mcN], *h8[mcN], *h9[mcN];
  TString fname[5] = {"ttbb_test","ttbb_test_cut_bq","tth_test","tth_test_cut_bq","ttjj_woSPIN_test"};
  TString label[5] = {"t#bar{t} + b#bar{b}","t#bar{t} + b#bar{b} w/ cut","t#bar{t} + H","t#bar{t} + H w/ cut","t#bar{t} + jj w/o SPIN"};
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
  gStyle->SetCanvasDefH(610);
  gStyle->SetCanvasDefW(900);
//  gStyle->SetPadGridX(true);
//  gStyle->SetPadGridY(true);
//  gStyle->SetGridColor(kGray+1);
/////////
  TCut dileptonic = "(leptonic>1)"; 
  TCut reco_njet4 = "nJet30>3";
  TCut reco_sel  = "lep1_pt>20 && lep2_pt>20 && abs(lep1_eta)<2.5 && abs(lep2_eta)<2.5";// && dileptonic && reco_njet4; 
  TCut selection = dileptonic;// && reco_sel;

  for(int i=0;i<mcN;i++)
  {
    cout <<"opening file : "<< fname[i].Data() ;
    f[i] = new TFile(Form("./result_%s.root",fname[i].Data()));
    cout <<", getting the tree. ";
    tree[i] = (TTree*) f[i]->Get(Form("ntuple"));

    //h[i] = plot(gBQ1st_M1fromT,fname[i],tree[i],selection);  
    //h[i] = plot(gBQ1st_DR1fromT,fname[i],tree[i],selection);  
    //h[i] = plot(gBQ1st_M2add,fname[i],tree[i],selection);  
    h[i] = plot(gBQ1st_DR2add,fname[i],tree[i],selection);  
    //h[i] = plot(gnBQ,fname[i],tree[i],selection);  

  }
////////


  double ymax=0.1, ymax2=0.1, ymin=0.0001;
  for(int i=0;i<mcN;i++)
  {
    h[i]->GetYaxis()->SetTitle("Normalized to unity");  h[i]->SetTitle("");   h[i]->Scale(1/h[i]->Integral());   

    h[i]->SetLineWidth(width[i]);   h[i]->SetLineColor(color[i]);   h[i]->SetLineStyle(style[i]);

    if(ymax < h[i]->GetMaximum() ) ymax = h[i]->GetMaximum();

  }
  //if(ymax>0.4) ymax=0.4;
  h[0]->SetMaximum(ymax*1.2);  h[0]->SetMinimum(ymin);

  double xmax = h[0]->GetXaxis()->GetXmax();

////////
  const double xs=0.05, ys=0.05;
//  const double xo=0.0,  yo=0.0;
  h[0]->GetXaxis()->SetTitleSize(xs*1.1);
  h[0]->GetYaxis()->SetTitleSize(ys*1.1);
//  h[0]->GetXaxis()->SetTitleOffset(xo);
//  h[0]->GetYaxis()->SetTitleOffset(yo);

  h[0]->GetYaxis()->SetLabelSize(xs);
  h[0]->GetXaxis()->SetLabelSize(ys);
//  h[0]->GetXaxis()->SetLabelOffset(xo);
//  h[0]->GetYaxis()->SetLabelOffset(yo);

//////
  bool logy = false;
  TCanvas *c1 = new TCanvas();
//  if(logy) c1->SetLogy();

//////
  double weighty=1.; if(logy) weighty=0.01;
  double legxmin=xmax*0.60, legxmax=xmax*0.97, legymin=h[0]->GetMaximum()*0.65*weighty, legymax=h[0]->GetMaximum()*0.95;
  TLegend* leg = new TLegend(legxmin,legymin, legxmax,legymax, NULL,"");
  leg->SetBorderSize(1);  leg->SetTextFont(62);  leg->SetTextSize(0.04);  leg->SetLineColor(0);  leg->SetLineStyle(1);  leg->SetLineWidth(1);  leg->SetFillColor(0);  leg->SetFillStyle(1001);

  for(int i=0;i<mcN;i++)
  {
    if(i==0) h[i]->Draw();  
    else     h[i]->Draw("same");  
    leg->AddEntry(h[i], label[i], "l");
  }
  leg->Draw();

  //c1->Print("GenJet.eps");
}


