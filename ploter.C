#include "TFile.h"
#include "TH2F.h"
#include "TCanvas.h"
#include "THStack.h"
#include "TString.h"
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include "tdrstyle.C"

///////

 const char* ZMass[4] =           {"ZMass",            "Dilepton mass","Dilepton Mass (GeV/c^{2}","Events/5 GeV/c^{2}" };
 const char* ZMassFinal[4] =      {"ZMassFinal",       "Dilepton mass","Dilepton Mass (GeV/c^{2}","Events/40 GeV/c^{2}"};
                                                       
 const char* nJetlog[4] =         {"nJetlog",          "Jet Multiplicity","Jet Multiplicity","Events"      };
 const char* nVertexlog[4] =      {"nVertexlog",       "Vertex Multiplicity","Vertex Multiplicity","Events"};
 const char* nVertex[4] =         {"nVertex",          "Vertex Multiplicity","Vertex Multiplicity","Events"};
 const char* METlog[4] =          {"METlog",           "Missing E_{T}","Missing E_{T} (GeV)","Events"      };
 const char* nJet[4] =            {"nJet",             "Jet Multiplicity","Jet Multiplicity","Events"      };
 const char* MET[4] =             {"MET",              "Missing E_{T}","Missing E_{T} (GeV)","Events"      };
 const char* METQCD[4] =          {"METQCD",           "Missing E_{T}","Missing E_{T} (GeV)","Events"      };
                                                       
 const char* pt1[4] =             {"pt1",              "Leading lepton p_{T}","p_{T} (GeV/c)","Events/5 GeV/c"           };
 const char* pt2[4] =             {"pt2",              "Second leading lepton p_{T}","p_{T} (GeV/c)","Events/5 GeV/c"    };
 const char* eta1[4] =            {"eta1",             "Leading #eta","#eta","Events/0.2"                                };
 const char* eta2[4] =            {"eta2",             "Second leading lepton #eta","#eta","Events/0.2"                  };
                                                       
 const char* jet1pt30[4] =        {"jet1pt30",         "Leading jet p_{T}","p_{T} (GeV/c)","Events/10 GeV/c"       };
 const char* jet1eta30[4] =       {"jet1eta30",        "Leading #eta","#eta","Events/0.2"                          };
 const char* jet1phi30[4] =       {"jet1phi30",        "Leading #phi","#phi (Radian)","Events/0.2 rad."            };
                                                       
 const char* jet2pt30[4] =        {"jet2pt30",         "Second leading jet p_{T}","p_{T} (GeV/c)","Events/10 GeV/c"};
 const char* jet2eta30[4] =       {"jet2eta30",        "Second leading jet #eta","#eta","Events/0.2"               };
 const char* jet2phi30[4] =       {"jet2phi30",        "Second leading jet #phi","#phi (Radian)","Events/0.2 rad." };
                                                       
 const char* jet3pt30[4] =        {"jet3pt30",         "Third jet p_{T}","p_{T} (GeV/c)","Events/10 GeV/c"  };
 const char* jet3eta30[4] =       {"jet3eta30",        "Third jet #eta","#eta","Events/0.2"                 };
 const char* jet3phi30[4] =       {"jet3phi30",        "Third jet #phi","#phi (Radian)","Events/0.2 rad."   };
                                                       
 const char* jet4pt30[4] =        {"jet4pt30",         "Fourth jet p_{T}","p_{T} (GeV/c)","Events/10 GeV/c" };
 const char* jet4eta30[4] =       {"jet4eta30",        "Fourth jet #eta","#eta","Events/0.2"                };
 const char* jet4phi30[4] =       {"jet4phi30",        "Fourth jet #phi","#phi (Radian)","Events/0.2 rad."  };
                                                       
 const char* Iso03lep1[4] =       {"Iso03lep1",        "relIso03lep1","relIso","Events"};
 const char* Iso03lep2[4] =       {"Iso03lep2",        "relIso03lep2","relIso","Events"};
                                  
 const char* nbJet30_CSVL[4] =    {"nbJet30_CSVL",     "b-Jet Multiplicity","b-Jet Multiplicity (CSVL)","Events"};
 const char* nbJet30_CSVM[4] =    {"nbJet30_CSVM",     "b-Jet Multiplicity","b-Jet Multiplicity (CSVM)","Events"};
 const char* nbJet30_CSVT[4] =    {"nbJet30_CSVT",     "b-Jet Multiplicity","b-Jet Multiplicity (CSVT)","Events"};
 const char* nbJet30_JPM[4] =     {"nbJet30_JPM",      "b-Jet Multiplicity","b-Jet Multiplicity (JPM)","Events"};
 const char* nbJet30_JPT[4] =     {"nbJet30_JPT",      "b-Jet Multiplicity","b-Jet Multiplicity (JPT)","Events"};
                 
 const char* addjet1_bDisCSV[4] = {"addjet1_bDisCSV",  "b-Discriminator"," b-Discriminator (CSV)","Events/0.1"};
 const char* addjet2_bDisCSV[4] = {"addjet2_bDisCSV",  "b-Discriminator"," b-Discriminator (CSV)","Events/0.1"};

 const char* jet1_bDisCSV[4] =    {"jet1_bDisCSV",     "b-Discriminator"," b-Discriminator (CSV)","Events/0.1"};
 const char* jet2_bDisCSV[4] =    {"jet2_bDisCSV",     "b-Discriminator"," b-Discriminator (CSV)","Events/0.1"};

 const char* addjet1_bDisJP[4] =  {"addjet1_bDisJP",   "b-Discriminator"," b-Discriminator (JP)","Events"};
 const char* addjet2_bDisJP[4] =  {"addjet2_bDisJP",   "b-Discriminator"," b-Discriminator (JP)","Events"};
                 
 const char* addjet1_secvtxm[4] = {"addjet1_secvtxm",  "Secondary Vertex Mass","Secondary Vertex Mass (GeV)","Events"};
 const char* addjet2_secvtxm[4] = {"addjet2_secvtxm",  "Secondary Vertex Mass","Secondary Vertex Mass (GeV)","Events"};

////////
TFile *f;
TString outDirName = ".";
int nExclude = 3;// QCD

const int nBkg = 6;
const char* bkgNames[] = {"TT1b",
 "TTcc","TTLF","TT_",
//"Wj_", "VV_",
 "ST_", "DY_"
//,"hDataBkg_QCD"
};
const char* bkgLabels[] = {"t#bar{t}+b",
  "t#bar{t}+cc", "t#bar{t}+LF","t#bar{t} others",
//"W #rightarrow l#nu", "Dibosons",
 "Single top", "Z/#gamma* #rightarrow ll"
//,"QCD"
};
const Color_t color_sig = kRed+3;//kBlue+2;
const int style_sig = 1001;//3354;
const Color_t color[] = {kOrange,//kRed+1,
    kOrange+2,kRed,kRed-7,
//kGreen-3,kGray+4,
kGreen,kAzure-2
//,kYellow
};
const int     style[] = {1001,
1001,  1001,  1001,    1001,   1001,    
//1001,    1001
//,   1001
};

const int nSig = 1;
const char* sigNames[] = {"TTbb"};//"hMCSig_TTbarH125"};
const char* sigLabels[] = {"t#bar{t}+bb"};//"t#bar{t}+H"};
bool stackSig = true;
const char* DecayMode[] ={"ElEl","MuMu","MuEl"};

TLegend* buildLegend(double y)
{
  TLegend* leg = new TLegend(0.72,0.40+y,0.87,0.87,NULL,"brNDC");
  //TLegend* leg =  new TLegend(0.72,0.50,0.87,0.87,NULL,"brNDC");

  leg->SetBorderSize(1);
  leg->SetTextFont(62);
  leg->SetTextSize(0.051);
  leg->SetLineColor(0);
  leg->SetLineStyle(1);
  leg->SetLineWidth(1);
  leg->SetFillColor(0);
  leg->SetFillStyle(1001);

  return leg;
}

TPaveText* getHeader(double lumi, TString channelName)
{
//  TPaveText *pt = new TPaveText(0.21,0.70,0.21,0.86,"brNDC");
  TPaveText *pt = new TPaveText(0.21,0.70,0.21,0.86,"brNDC");

  pt->SetBorderSize(1);
  pt->SetTextFont(42);
  pt->SetTextSize(0.06);
  pt->SetLineColor(0);
  pt->SetLineStyle(1);
  pt->SetLineWidth(1);
  pt->SetFillColor(0);
  pt->SetFillStyle(1001);
  pt->SetTextAlign(12);
  pt->AddText("CMS Preliminary");
  pt->AddText(Form("%.1f fb^{-1} at  #sqrt{s} = 8 TeV", lumi));
  pt->AddText("");

  return pt;
}


/////////////////////////////
void ploter()
{

   f=TFile::Open("./result.root");
   outDirName += "/aaa";
   gSystem->Exec("mkdir "+outDirName);
   gSystem->Exec("mkdir "+outDirName+"/log");
   gSystem->Exec("mkdir "+outDirName+"/linear");

   plot("S5",addjet1_bDisCSV,true,false);
 //  plot("S5",addjet2_bDisCSV);


}

void plot(const char* cutStep, const char* histNameTitle[4], bool isSS=true, bool doLogY=false)
{
   gROOT->ProcessLine(".L ./tdrstyle.C");
   defaultStyle();

   const char* histName = histNameTitle[0];
   const char* histTitle = histNameTitle[1];
   const char* xTitle = histNameTitle[2];
   const char* yTitle = histNameTitle[3];

   TH1F *h[nBkg+2][4], *h2[4];

   THStack* hStackEE = new THStack(TString("hEE_")+cutStep+"_"+histName, histTitle);
   THStack* hStackMM = new THStack(TString("hMM_")+cutStep+"_"+histName, histTitle);
   THStack* hStackME = new THStack(TString("hME_")+cutStep+"_"+histName, histTitle);

   TLegend* legEE = buildLegend( (double) nExclude*0.02);
   TLegend* legMM = buildLegend( (double) nExclude*0.02);
   TLegend* legME = buildLegend( (double) nExclude*0.02);

   for(int j=0;j<3;j++)
   {
        //for signal
        h[nBkg][j] = (TH1F*)f->Get(Form("h%s_%s_%s%s",histName, cutStep, sigNames[0],DecayMode[j] ));
        h[nBkg][j]->SetFillColor(color_sig);
        h[nBkg][j]->SetLineColor(kBlack);
        h[nBkg][j]->SetFillStyle(style_sig);

        if(j==0 && isSS) hStackEE->Add(h[nBkg][j]);
        if(j==1 && isSS) hStackMM->Add(h[nBkg][j]);
        if(j==2 && isSS) hStackME->Add(h[nBkg][j]);
        if(j==0 && h[nBkg][j]->GetEntries() > 0) legEE->AddEntry(h[nBkg][j], sigLabels[0], "f");
        if(j==1 && h[nBkg][j]->GetEntries() > 0) legMM->AddEntry(h[nBkg][j], sigLabels[0], "f");
        if(j==2 && h[nBkg][j]->GetEntries() > 0) legME->AddEntry(h[nBkg][j], sigLabels[0], "f");
        //for data 
        //h[nBkg+1][j]= (TH1F*)f->Get(Form("h%s_%s_data_%s",histName, cutStep, DecayMode[j] ));
   }

   for(int i=0;i<nBkg;i++) for(int j=0;j<3;j++)
   {
        //for background
        h[i][j]= (TH1F*)f->Get(Form("h%s_%s_%s%s",histName, cutStep, bkgNames[i], DecayMode[j] ));
        h[i][j]->SetFillColor(color[i]);
        h[i][j]->SetLineColor(kBlack);
        h[i][j]->SetFillStyle(style[i]);

        if(j==0) { hStackEE->Add(h[i][j]); if(i==0) h2[j] = (TH1F*) h[i][j]->Clone("bkgee"); }
        if(j==1) { hStackMM->Add(h[i][j]); if(i==0) h2[j] = (TH1F*) h[i][j]->Clone("bkgmm"); }
        if(j==2) { hStackME->Add(h[i][j]); if(i==0) h2[j] = (TH1F*) h[i][j]->Clone("bkgme"); }

        if(i!=0) h2[j]->Add(h[i][j]);

        if(j==0) legEE->AddEntry(h[i][j], bkgLabels[i], "f");
        if(j==1) legME->AddEntry(h[i][j], bkgLabels[i], "f");
        if(j==2) legMM->AddEntry(h[i][j], bkgLabels[i], "f");

   }
   h2[0]->SetTitle("");
   h2[0]->GetXaxis()->SetTitle( xTitle );
   h2[0]->GetYaxis()->SetTitle( yTitle );

   h2[0]->SetMaximum(h2[0]->GetMaximum()*1.5);

///////////
   TCanvas *cEE = new TCanvas("cEE","cEE",1);
   TPad *pad1EE = new TPad("pad1","",0,0.3,1,1);
   TPad *pad2EE = new TPad("pad2","",0,0,1,0.3);
   pad1EE->Divide(1,1,0,0); pad2EE->Divide(1,1,0,0);
   pad1EE->SetBottomMargin(0);
   pad2EE->SetTopMargin(0);
   pad2EE->SetBottomMargin(0.3);
   pad1EE->Draw();   pad2EE->Draw();
   pad1EE->cd();

   double LogMinEE=0.5;
   if(h[nBkg][0]->GetMinimum()<0.5) LogMinEE=0.05;
   if ( doLogY ){ pad1EE->SetLogy(); h2[0]->SetMinimum(LogMinEE); h2[0]->SetMaximum(h2[0]->GetMaximum()*50); }

   h2[0]->GetYaxis()->SetTitleSize(0.065);
   h2[0]->GetYaxis()->SetLabelSize(0.05);
   h2[0]->Draw();
   getHeader(19.6, "ee channel")->Draw(); legEE->Draw(); 
   hStackEE->Draw("same");

   pad1EE->Draw();
   pad1EE->Update(); //this will force the generation of the "stats" box
   pad2EE->cd();


   TH1F* h3 = (TH1F*) h2[0]->Clone("EE"); ///
   h3->Sumw2();
   h3->Divide(h2[0]);
   h3->SetTitle("");
   h3->GetYaxis()->SetTitle("Data/MC");
   h3->SetNdivisions( 505, "Y" );
   h3->SetMarkerStyle(20);
   h3->SetMaximum(2);
   h3->SetMinimum(0);
   h3->GetXaxis()->SetTitleSize(0.14);
   h3->GetYaxis()->SetTitleSize(0.14);
   h3->GetYaxis()->SetTitleOffset(0.4);
   h3->GetYaxis()->SetLabelSize(0.1);
   h3->GetXaxis()->SetLabelSize(0.13);

   h3->GetXaxis()->SetTitle(xTitle);
   h3->Draw("ex0");

   h3->Draw();
   TLine *line = new TLine(h3->GetXaxis()->GetXmin() ,1,h3->GetXaxis()->GetXmax(),1);
   line->SetLineColor(kRed);
   line->Draw();

   pad2EE->Draw();
   pad2EE->Update();

   cEE->Print(Form("%s/log/cEE_%s_%s.eps", outDirName.Data(), cutStep, histName));
}


