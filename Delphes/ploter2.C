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

  TFile* f[4];  TTree* tree[4];  TH2F*  h[4];
  int mcN=4;
  TString fname[4] = {"ttbb_loop_sm","ttbb_loop_sm_cut_bq","tth_loop_sm","tth_loop_sm_cut_bq"};
  TString label[4] = {"t#bar{t} + b#bar{b}","t#bar{t} + b#bar{b} w/ cut","t#bar{t} + H","t#bar{t} + H w/ cut"};
/*  const Color_t color[] = {
    kRed,kRed-7,kBlue,kBlue-7
  };
  const int     style[] = {
    1,  2,  1, 2
  };*/

  gStyle->SetOptStat(0); //remove statistics box
  gROOT->ProcessLine(".L ./tdrstyle.C");
  defaultStyle();
  gStyle->SetCanvasDefH(800);
  gStyle->SetCanvasDefW(800);
  //gStyle->SetPadGridX(true);
  //gStyle->SetPadGridY(true);
  //gStyle->SetGridColor(kGray+1);
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
    h[i] = plot2(nJetvgnJet,fname[i],tree[i],selction);  
  }
//////
  //bool logy = false;
  TCanvas *c1 = new TCanvas();
  c1->Divide(2,2);
  //if(logy) c1->SetLogy();

//////
  double weighty=1.; //if(logy) weighty=0.01;
  double xmax = h[0]->GetXaxis()->GetXmax();
  double ymax = h[0]->GetYaxis()->GetXmax();
  double legxmin=xmax*0.60, legxmax=xmax*0.97, legymin=ymax*1.01*weighty, legymax=ymax*1.15;
  TLegend* leg[4];

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

}

/*  MonitorPlot ZMass = MonitorPlot("ZMass", "ZMass", "Dilepton mass;Dilepton Mass (GeV/c^{2});Events/5 GeV/c^{2}", 20, 0, 250);
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
*/
