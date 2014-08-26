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

void ploter1D()
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

  
  TFile* f[5];  TTree* tree[5]; 
  TH1F  *h[5], *h2[5], *h3[5], *h4[5], *h5[5], *h6[5], *h7[5], *h8[5], *h9[5];
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
  gStyle->SetCanvasDefH(610);
  gStyle->SetCanvasDefW(1200);
//  gStyle->SetPadGridX(true);
//  gStyle->SetPadGridY(true);
//  gStyle->SetGridColor(kGray+1);
/////////
  TCut dileptonic = "(leptonic>0)"; 
  TCut reco_njet4 = "nJet30>-1";
  TCut selction  = "lep1_pt>20 && lep2_pt>20 && abs(lep1_eta)<2.5 && abs(lep2_eta)<2.5" && dileptonic && reco_njet4; 
  for(int i=0;i<mcN;i++)
  {
    cout <<"opening file : "<< fname[i].Data() ;
    f[i] = new TFile(Form("./result_%s.root",fname[i].Data()));
    cout <<", getting the tree. ";
    tree[i] = (TTree*) f[i]->Get(Form("ntuple"));
/*
    h[i] = plot(nJet,fname[i],tree[i],selction);  
    h2[i] = plot(nJetBH,fname[i],tree[i],selction);  
    h3[i] = plot(nJetBQ,fname[i],tree[i],selction);  
    h4[i] = plot(nJetBTQ,fname[i],tree[i],selction);  
    h5[i] = plot(nJetBHiggs,fname[i],tree[i],selction);  
*/
    h[i] = plot(gnJet,fname[i],tree[i],selction);  
    h2[i] = plot(gnJetBH,fname[i],tree[i],selction);  
    h3[i] = plot(gnJetBQ,fname[i],tree[i],selction);  
    h4[i] = plot(gnJetBTQ,fname[i],tree[i],selction);  
    h5[i] = plot(gnJetBHiggs,fname[i],tree[i],selction);  
    h6[i] = plot(gnJetBOverlap,fname[i],tree[i],selction);  
    h7[i] = plot(gnJetBTQHiggs,fname[i],tree[i],selction);  
    h8[i] = plot(gnJetBNTQ,fname[i],tree[i],selction);  
    h9[i] = plot(gnJetBNTQOverlap,fname[i],tree[i],selction);  

  }
////////


  double ymax=0.1, ymin=0.0001;
  for(int i=0;i<mcN;i++)
  {
    h[i]->GetYaxis()->SetTitle("Normalized to unity");  h[i]->SetTitle("");   h[i]->Scale(1/h[i]->Integral());   
    h2[i]->GetYaxis()->SetTitle("Normalized to unity"); h2[i]->SetTitle("");  h2[i]->Scale(1/h2[i]->Integral()); 
    h3[i]->GetYaxis()->SetTitle("Normalized to unity"); h3[i]->SetTitle("");  h3[i]->Scale(1/h3[i]->Integral()); 
    h4[i]->GetYaxis()->SetTitle("Normalized to unity"); h4[i]->SetTitle("");  h4[i]->Scale(1/h4[i]->Integral()); 
    h5[i]->GetYaxis()->SetTitle("Normalized to unity"); h5[i]->SetTitle("");  h5[i]->Scale(1/h5[i]->Integral()); 
    h6[i]->GetYaxis()->SetTitle("Normalized to unity"); h6[i]->SetTitle("");  h6[i]->Scale(1/h6[i]->Integral()); 
    h7[i]->GetYaxis()->SetTitle("Normalized to unity"); h7[i]->SetTitle("");  h7[i]->Scale(1/h7[i]->Integral()); 
    h8[i]->GetYaxis()->SetTitle("Normalized to unity"); h8[i]->SetTitle("");  h8[i]->Scale(1/h8[i]->Integral()); 
    h9[i]->GetYaxis()->SetTitle("Normalized to unity"); h9[i]->SetTitle("");  h9[i]->Scale(1/h9[i]->Integral()); 

    h[i]->SetLineWidth(width[i]);   h[i]->SetLineColor(color[i]);   h[i]->SetLineStyle(style[i]);
    h2[i]->SetLineWidth(width[i]);  h2[i]->SetLineColor(color[i]);  h2[i]->SetLineStyle(style[i]);
    h3[i]->SetLineWidth(width[i]);  h3[i]->SetLineColor(color[i]);  h3[i]->SetLineStyle(style[i]);
    h4[i]->SetLineWidth(width[i]);  h4[i]->SetLineColor(color[i]);  h4[i]->SetLineStyle(style[i]);
    h5[i]->SetLineWidth(width[i]);  h5[i]->SetLineColor(color[i]);  h5[i]->SetLineStyle(style[i]);
    h6[i]->SetLineWidth(width[i]);  h6[i]->SetLineColor(color[i]);  h6[i]->SetLineStyle(style[i]);
    h7[i]->SetLineWidth(width[i]);  h7[i]->SetLineColor(color[i]);  h7[i]->SetLineStyle(style[i]);
    h8[i]->SetLineWidth(width[i]);  h8[i]->SetLineColor(color[i]);  h8[i]->SetLineStyle(style[i]);
    h9[i]->SetLineWidth(width[i]);  h9[i]->SetLineColor(color[i]);  h9[i]->SetLineStyle(style[i]);


    if(ymax < h[i]->GetMaximum() ) ymax = h[i]->GetMaximum();
    if(ymax < h2[i]->GetMaximum() ) ymax = h2[i]->GetMaximum();
    if(ymax < h3[i]->GetMaximum() ) ymax = h3[i]->GetMaximum();
    if(ymax < h4[i]->GetMaximum() ) ymax = h4[i]->GetMaximum();
    if(ymax < h6[i]->GetMaximum() ) ymax = h6[i]->GetMaximum();
    if(ymax < h7[i]->GetMaximum() ) ymax = h7[i]->GetMaximum();
    if(ymax < h8[i]->GetMaximum() ) ymax = h8[i]->GetMaximum();
    if(ymax < h9[i]->GetMaximum() ) ymax = h9[i]->GetMaximum();
    if(i>1) if(ymax < h5[i]->GetMaximum() ) ymax = h5[i]->GetMaximum();
  }
  if(ymax>0.4) ymax=0.4;
  h[0]->SetMaximum(ymax*1.2);  h[0]->SetMinimum(ymin);
  h2[0]->SetMaximum(ymax*1.2);  h2[0]->SetMinimum(ymin);
  h3[0]->SetMaximum(ymax*1.2);  h3[0]->SetMinimum(ymin);
  h4[0]->SetMaximum(ymax*1.2);  h4[0]->SetMinimum(ymin);
  h6[0]->SetMaximum(ymax*1.2);  h6[0]->SetMinimum(ymin);
  h7[0]->SetMaximum(ymax*1.2);  h7[0]->SetMinimum(ymin);
  h8[0]->SetMaximum(ymax*1.2);  h8[0]->SetMinimum(ymin);
  h9[0]->SetMaximum(ymax*1.2);  h9[0]->SetMinimum(ymin);
  h5[2]->SetMaximum(ymax*1.2);  h5[2]->SetMinimum(ymin);

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
  c1->Divide(5,2);
//  if(logy) c1->SetLogy();

//////
  double weighty=1.; if(logy) weighty=0.01;
  double legxmin=xmax*0.60, legxmax=xmax*0.97, legymin=h[0]->GetMaximum()*0.65*weighty, legymax=h[0]->GetMaximum()*0.95;
  TLegend* leg = new TLegend(legxmin,legymin, legxmax,legymax, NULL,"");
  leg->SetBorderSize(1);  leg->SetTextFont(62);  leg->SetTextSize(0.04);  leg->SetLineColor(0);  leg->SetLineStyle(1);  leg->SetLineWidth(1);  leg->SetFillColor(0);  leg->SetFillStyle(1001);

  TLegend* leg2 = new TLegend(legxmin,legymin, legxmax,legymax, NULL,"");
  leg2->SetBorderSize(1);  leg2->SetTextFont(62);  leg2->SetTextSize(0.04);  leg2->SetLineColor(0);  leg2->SetLineStyle(1);  leg2->SetLineWidth(1);  leg2->SetFillColor(0);  leg2->SetFillStyle(1001);

//////
  c1->cd(1);
  for(int i=0;i<mcN;i++)
  {
    if(i==0) h[i]->Draw();  
    else     h[i]->Draw("same");  
    leg->AddEntry(h[i], label[i], "l");
  }
  leg->Draw();

  c1->cd(2);
  for(int i=0;i<mcN;i++)
  {
    if(i==0) h2[i]->Draw();
    else     h2[i]->Draw("same");
//    leg->AddEntry(h[i], label[i], "l");
  }
  leg->Draw();

  c1->cd(3);
  for(int i=0;i<mcN;i++)
  {
    if(i==0) h3[i]->Draw();
    else     h3[i]->Draw("same");
//    leg->AddEntry(h[i], label[i], "l");
  }
  leg->Draw();

  c1->cd(4);
  for(int i=0;i<mcN;i++)
  {
    if(i==0) h4[i]->Draw();
    else     h4[i]->Draw("same");
//    leg->AddEntry(h[i], label[i], "l");
  }
  leg->Draw();

  c1->cd(5);
  for(int i=2;i<mcN-1;i++)
  {
    if(i==2) h5[i]->Draw();
    else     h5[i]->Draw("same");
    leg2->AddEntry(h5[i], label[i], "l");
  }
  leg2->Draw();

  c1->cd(6);
  for(int i=0;i<mcN;i++)
  {
    if(i==0) h6[i]->Draw();
    else     h6[i]->Draw("same");
//    leg->AddEntry(h[i], label[i], "l");
  }
  leg->Draw();

  c1->cd(7);
  for(int i=0;i<mcN;i++)
  {
    if(i==0) h7[i]->Draw();
    else     h7[i]->Draw("same");
//    leg->AddEntry(h[i], label[i], "l");
  }
  leg->Draw();

  c1->cd(8);
  for(int i=0;i<mcN;i++)
  {
    if(i==0) h8[i]->Draw();
    else     h8[i]->Draw("same");
//    leg->AddEntry(h[i], label[i], "l");
  }
  leg->Draw();

  c1->cd(9);
  for(int i=0;i<mcN;i++)
  {
    if(i==0) h9[i]->Draw();
    else     h9[i]->Draw("same");
//    leg->AddEntry(h[i], label[i], "l");
  }
  leg->Draw();


}


