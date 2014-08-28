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
#include "TPaveText.h"

#include <iostream>
#include <fstream>
#include <set>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include "tdrstyle.C"
#include "plot.h"
//#include "plot2.h"

void ploterNew(int pp=0, int ppp=0, bool norm = false)//,bool logy = false)
{

  MonitorPlot ZMass = MonitorPlot("ZMass", "ZMass"   , "Dilepton mass;Dilepton Mass (GeV/c^{2});Events/10 GeV/c^{2}", 30, 0, 300);
  MonitorPlot nJet = MonitorPlot("nJet"  , "nJet30"  , "Jet Multiplicity;Jet Multiplicity;Events", 13, 0, 13);
  MonitorPlot nbJet = MonitorPlot("nbJet", "nbJet30T", "# of b-tagged Jets;# of b-tagged Jets;Events", 5, 0, 5);
  MonitorPlot MET   = MonitorPlot("MET"  ,  "MET"    , "Missing E_{T};Missing E_{T} (GeV);Events",20,0,200);

  MonitorPlot pt1 = MonitorPlot("pt1", "lep1_pt", "Leading lepton p_{T};p_{T}^{lep1} (GeV/c);Events/10 GeV/c", 20, 0, 200);
  MonitorPlot pt2 = MonitorPlot("pt2", "lep2_pt", "Second leading lepton p_{T};p_{T}^{lep2} (GeV/c);Events/10 GeV/c", 20, 0, 200);
  MonitorPlot eta1 = MonitorPlot("eta1", "lep1_eta", "Leading #eta;#eta^{lep1};Events/0.2", 35, -3.5, 3.5);
  MonitorPlot eta2 = MonitorPlot("eta2", "lep2_eta", "Second leading lepton #eta^{lep2};#eta;Events/0.2", 35, -3.5, 3.5);

  MonitorPlot jet1pt30 = MonitorPlot("jet1pt30", "jet1_pt", "Leading Jet p_{T}; p_{T}^{jet1} (GeV/c);Events/20 GeV/c",25, 30, 530);
  MonitorPlot jet2pt30 = MonitorPlot("jet2pt30", "jet2_pt", "Second leading Jet p_{T}; p_{T}^{jet2} (GeV/c);Events/20 GeV/c",25, 30, 530);
  MonitorPlot jet3pt30 = MonitorPlot("jet3pt30", "jet3_pt", "Third Jet p_{T}; p_{T}^{jet3} (GeV/c);Events/20 GeV/c",25, 30, 530);
  MonitorPlot jet4pt30 = MonitorPlot("jet4pt30", "jet4_pt", "Fourth Jet p_{T}; p_{T}^{jet4} (GeV/c);Events/20 GeV/c",25, 30, 530);

  MonitorPlot jet1eta30 = MonitorPlot("jet1eta30", "jet1_eta", "Leading #eta;#eta^{jet1};Events/0.2", 20, -3.5, 3.5);
  MonitorPlot jet2eta30 = MonitorPlot("jet2eta30", "jet2_eta", "Second leading Jet #eta;#eta^{jet2};Events/0.2", 35, -3.5, 3.5);
  MonitorPlot jet3eta30 = MonitorPlot("jet3eta30", "jet3_eta", "Third Jet #eta;#eta^{jet3};Events/0.2", 35, -3.5, 3.5);
  MonitorPlot jet4eta30 = MonitorPlot("jet4eta30", "jet4_eta", "Fourth Jet #eta;#eta^{jet4};Events/0.2", 35, -3.5, 3.5);

  MonitorPlot jet1phi30 = MonitorPlot("jet1phi30", "jet1_phi", "Leading #phi;#phi^{jet1} (Radian);Events/0.2 rad.", 35, -3.5, 3.5);
  MonitorPlot jet2phi30 = MonitorPlot("jet2phi30", "jet2_phi", "Second leading Jet #phi;#phi^{jet2} (Radian);Events/0.2 rad.", 35, -3.5, 3.5);
  MonitorPlot jet3phi30 = MonitorPlot("jet3phi30", "jet3_phi", "Third Jet#phi;#phi^{jet3} (Radian);Events/0.2 rad.", 35, -3.5, 3.5);
  MonitorPlot jet4phi30 = MonitorPlot("jet4phi30", "jet4_phi", "Fourth Jet #phi;#phi^{jet4} (Radian);Events/0.2 rad.", 35, -3.5, 3.5);

  MonitorPlot nLepG = MonitorPlot("nLepG", "leptonic", "# of lepton in gen;# of lepton^{GEN};Events", 3, 0, 3);
  MonitorPlot nMuG = MonitorPlot("nMuG", "muonic", "# of muon in gen;# of #mu^{GEN};Events", 3, 0, 3);
  MonitorPlot nElG = MonitorPlot("nElG", "electronic", "# of electron in gen;# of e^{GEN};Events", 3, 0, 3);



  //Sample(string fileName_, string treeName_, string name_,string label_,Color_t color_,  int style_, double width_, bool isMC_=false,  double xsec_=1)
  Sample ttbb_1 = Sample("result_ttbb_loop_sm.root",       "ntuple","ttbb_1","t#bar{t} + b#bar{b}"       ,kRed   ,1,3,true, 1.588e+01); // xsec unit : pb
  Sample ttbb_2 = Sample("result_ttbb_loop_sm_cut_bq.root","ntuple","ttbb_2","t#bar{t} + b#bar{b} w/ cut",kRed-4 ,2,1,true, 4.686e+00); // xsec unit : pb
  Sample tth_1  = Sample("result_tth_loop_sm.root",        "ntuple","tth_1" ,"t#bar{t} + H"              ,kBlue  ,1,3,true, 4.642e-01); // xsec unit : pb
  Sample tth_2  = Sample("result_tth_loop_sm_cut_bq.root", "ntuple","tth_2" ,"t#bar{t} + H w/ cut"      ,kBlue-7 ,2,1,true, 3.669e-01); // xsec unit : pb
  Sample ttjj_1 = Sample("result_ttjj_loop_sm.root",       "ntuple","ttjj_1","t#bar{t} + jj"            ,kGreen+2,1,3,true, 2.238e+02); // xsec unit : pb

// Cut Steps as Event selection  
  Cut cuts = Cut();
  cuts.addCut("1","1"); //S0
  cuts.addCut("leptonic>1","1"); // S1 : dileptonic in generate level
  cuts.addCut("lep1_pt>20 && lep2_pt>20 && abs(lep1_eta)<2.5 && abs(lep2_eta)<2.5","1"); // S2
  cuts.addCut("nJet30>3","1");   //S3
  cuts.addCut("nbJet30T>2","1"); //S4

////////////                 
  MonitorPlot MyPlots[] = {nLepG,nMuG,nElG,           // 0, 1, 2
                           ZMass, nJet, nbJet, MET,   // 3, 4, 5, 6
                           pt1, pt2,                  // 7,8
                           eta1, eta2,                // 9,10
                           //phi1, phi2,                // 
                           jet1pt30,jet2pt30,jet3pt30, jet4pt30,     // 11, 12, 13, 14
                           jet1eta30,jet2eta30,jet3eta30, jet4eta30, // 15, 16, 17, 18
                           jet1phi30,jet2phi30,jet3phi30, jet4phi30 // 19, 20, 21, 22
                          };
  Sample MC[] = {ttbb_1, ttbb_2, tth_1, tth_2, ttjj_1};
  int mcN=(sizeof(MC)/sizeof(*MC));
  int cutN = cuts.Entries();
  if(ppp>cutN) ppp=0;

  TH1F*  h[mcN];
  gStyle->SetOptStat(0); //remove statistics box
  gROOT->ProcessLine(".L ./tdrstyle.C");  defaultStyle();
  gStyle->SetCanvasDefH(500);  gStyle->SetCanvasDefW(500);
  gStyle->SetPadGridX(true);   gStyle->SetPadGridY(true);  gStyle->SetGridColor(kGray+1);
  gStyle->SetTitleW(1);  gStyle->SetTitleH(0);

/////////////////////
  double lumi= 30000; // 30 /fb
  for(int i=0;i<mcN;i++)
  {
    //h[i] = plot(MyPlots[pp],MC[i].name,MC[i].chain,cuts.useCut(ppp));  
    h[i] = plot(MyPlots[pp],MC[i].name,MC[i].chain,cuts.useCut2(ppp));  
    if(!norm) h[i]->Sumw2();
    h[i]->Scale(MC[i].xsec/MC[i].nEvents*lumi);
  }

////////////////////
  double ymax=0.01, ymin=0.001;
  //bool norm = false;
  bool logy = false;
  if(!norm) {logy = true;}
  if(logy) { ymin=1; }
  for(int i=0;i<mcN;i++)
  {
    //h[i]->SetTitle("");
    h[i]->SetTitle(cuts.useCut2(ppp) ); h[i]->SetTitle(Form("Cut: %s", h[i]->GetTitle()) );
    if(norm) { h[i]->Scale(1/h[i]->Integral()); h[i]->GetYaxis()->SetTitle("Normalized to unity"); }
    if(ymax < h[i]->GetMaximum() ) ymax = h[i]->GetMaximum();
    if(ymin > h[i]->GetMinimum() && h[i]->GetMinimum()!=0) ymin = h[i]->GetMinimum();
 
    h[i]->SetLineColor(MC[i].color);    h[i]->SetLineWidth(MC[i].width);    h[i]->SetLineStyle(MC[i].style);
  }
  if(ymin>0.01) ymin=ymin*0.1;
  h[0]->SetMaximum(ymax); h[0]->SetMinimum(ymin);
  double xmax = h[0]->GetXaxis()->GetXmax();
  double xmin = h[0]->GetXaxis()->GetXmin();
  int xbins = h[0]->GetNbinsX();

  bool canMvleg=false;
  if( h[2]->Integral(1,xbins/2)==0)              canMvleg=true;
  if( h[2]->GetBinContent((h[2]->GetMinimumBin()))>1000 ) canMvleg=true;

///////////////////
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
  TCanvas *c1 = new TCanvas();
  double yscale = 1.6;
  if(logy){  c1->SetLogy(); yscale=5000; }
  h[0]->SetMaximum(h[0]->GetMaximum()*yscale);

// add legend
  double legxmin=0.6, legxmax=0.93, legymin=0.6, legymax=0.89;
  if(canMvleg) { legxmin=0.25, legxmax=0.55, legymin=0.2, legymax=0.49; h[0]->SetMinimum(ymin*0.1); }
  TLegend* leg = new TLegend(legxmin,legymin, legxmax,legymax);
  leg->SetBorderSize(1);  leg->SetTextFont(62);  leg->SetTextSize(0.04);
  leg->SetLineColor(0);  leg->SetLineStyle(1);  leg->SetLineWidth(1);  leg->SetFillColor(0);
  leg->SetFillStyle(1001);

  for(int i=0;i<mcN;i++)
  {
    if(i==0) h[i]->Draw();  
    else     h[i]->Draw("same");  
    leg->AddEntry(h[i], MC[i].label.c_str(), "l");
  }
  leg->Draw();

// add header
  double headxmin=0.04*(xmax-xmin)+xmin, headxmax=0.55*(xmax-xmin)+xmin;
//  double yscale2=1.;
  double headymin=0.8*(ymax*yscale-ymin)+ymin, headymax=0.99*(ymax*yscale-ymin)+ymin;
  //double headymin=0.2;//*(ymax*yscale-ymin)+ymin;
  //double headymax=0.3;//*(ymax*yscale-ymin)+ymin;
  if(logy) { headymin=headymin*0.01; headymax=headymax*0.5; }
//  if(norm) { headymin=headymin*0.01; headymax=headymax*0.1; }
  cout  << "ymin:" << headymin << ", ymax:" << headymax << endl;

  TPaveText* pt = new TPaveText(headxmin,headymin, headxmax, headymax);//,"brNDC");
  pt->SetBorderSize(1);  pt->SetTextFont(42);  pt->SetTextSize(0.04);
  pt->SetLineColor(0);   pt->SetLineStyle(1);  pt->SetLineWidth(1);
  pt->SetFillColor(0);   pt->SetFillStyle(1001);  pt->SetTextAlign(12);
  pt->AddText("Work in progress");
  pt->AddText("aMC@NLO & Delphes");
  if(norm) pt->AddText(Form("#sqrt{s} = 13 TeV"));
  else     pt->AddText(Form("%.0f fb^{-1} at #sqrt{s} = 13 TeV", lumi/1000));
  pt->Draw();

  if(norm) c1->Print(Form("./plots/Norm_%s_S%d.eps",MyPlots[pp].name.c_str(),ppp));
  else     c1->Print(Form("./plots/Log_%s_S%d.eps",MyPlots[pp].name.c_str(),ppp));
}


