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


void cutflowNewRun(int ppp=0)
{
  int pp=0;
  MonitorPlot nJet = MonitorPlot("nJet", "nJet30", "# of b-tagged Jets;# of b-tagged Jets;", 1, 0, 100);
/*
ttbb_2 : 23046.7
tth_2 : 1609.24
ttjj_1 : 2.33684e+07
ttbb_4 : 464162
tth_4 : 46527.9
*/

   const string path ="/cms/home/youngjo/Madgraph/Analysis/new20GeV_v13";
   Sample ttbb_2  = Sample(path+"/result_ttbb_cut_bq.root","ntuple","ttbb_2","t#bar{t}b#bar{b}",kRed ,1,2,true, 4.729e+00*0.04553956,23046.7); // xsec unit : pb
   Sample tth_2   = Sample(path+"/result_tth_cut_bq.root", "ntuple","tth_2" ,"t#bar{t}H "       ,kGreen-7 ,1,2,true,3.234e-01*0.04553956,1609.24); // xsec unit : pb
   Sample ttjj_2  = Sample(path+"/result_ttjj_SPIN_LO.root","ntuple","ttjj_2","t#bar{t}jj LO "    ,kBlue+1,1,2,true,20.935801482312659,1.); // xsec unit : pb

//   Sample ttjj_1 = Sample(path+"/result_ttjj_woSPIN.root","ntuple","ttjj_1","t#bar{t}jj "    ,kBlue+1,1,2,true,2.238e+02,2.33684e+07); // xsec unit : pb
//   Sample ttjj_3 = Sample(path+"/result_ttjj_LO.root","ntuple","ttjj_3","t#bar{t}jj LO "    ,kBlue+1,1,2,true,423.55676178935778,1.); // xsec unit : pb

   Sample ttbb_4 = Sample(path+"/result_ttbb_woSPIN_cut_bq.root","ntuple","ttbb_4","t#bar{t} + b#bar{b}",kRed ,1,2,true, 4.729e+00,464162); // xsec unit : pb
   Sample tth_4  = Sample(path+"/result_tth_woSPIN.root", "ntuple","tth_4" ,"t#bar{t} + H "       ,kGreen-7 ,1,2,true,4.455e-01,46527.9); // xsec unit : pb
   Sample ttjj_4 = Sample(path+"/result_ttjj_LO2.root","ntuple","ttjj_3","t#bar{t}jj LO "    ,kBlue+1,1,2,true,424.14756200450773,1.);

  Sample MC[] = {ttbb_2, tth_2,ttjj_2};

// Cut Steps as Event selection  
  Cut cuts = Cut();
  cuts.addCut("1","1"); //S0
  cuts.addCut("leptonic>1","1"); // S1 : dileptonic in generate level
//  cuts.addCut("nJet30>3","1");
  cuts.addCut("lep1_pt>20 && lep2_pt>20 && abs(lep1_eta)<2.4 && abs(lep2_eta)<2.4","1"); // S2
  cuts.addCut("nJet30>3","1");   //S3
  cuts.addCut("nbJet30T>=2","1"); //S4
  cuts.addCut("nbJet30T>=3","1"); //S4
//  cuts.addCut("nbJet30T>=4","1"); //S4

////////////                 
 MonitorPlot MyPlots[] = {
     nJet
   };

  int mcN=(sizeof(MC)/sizeof(*MC));
  int cutN = cuts.Entries();
  if(ppp>cutN) ppp=0;

  TH1F*  h[mcN];
  gStyle->SetOptStat(0); //remove statistics box
  gROOT->ProcessLine(".L ./tdrstyle.C");  defaultStyle();
  gStyle->SetCanvasDefH(500);  gStyle->SetCanvasDefW(500);
  gStyle->SetPadGridX(true);   gStyle->SetPadGridY(true);  gStyle->SetGridColor(kGray+1);
  gStyle->SetTitleW(1);  gStyle->SetTitleH(0);

  char *hname[] = {"ttbb","tth","ttjj"};
  const double ttbb_cx = 4.729*0.04553956;
  const double tth_cx  = 0.3234*0.04553956;
  const double ttjj_cx = 20.935801482312659;
  double cxxx[] = { ttbb_cx, tth_cx, ttjj_cx};
/////////////////////
  double lumi= 10000; // 10 /fb
    cout << "\n Selection, S"<< (ppp) << endl;
  for(int i=0;i<mcN;i++)
  {
    //h[i] = plot(MyPlots[pp],MC[i].name,MC[i].chain,cuts.useCut(ppp));  
    h[i] = plot(MyPlots[pp],MC[i].name,MC[i].chain,cuts.useCut2(ppp));  
    h[i]->Sumw2();
    cout <<"unweight, "<< hname[i] << ", " << h[i]->GetBinContent(1) << " , " << h[i]->GetBinError(1) << endl;;
    if((MC[i].sumweight)>2.) h[i]->Scale(MC[i].xsec*lumi/MC[i].sumweight);
    else
                   h[i]->Scale(MC[i].xsec/MC[i].nEvents*lumi);
    cout <<"weight, "<< hname[i] << ", " << h[i]->GetBinContent(1) << " , " << h[i]->GetBinError(1) << ", cx," << cxxx[i] << endl;;
  }

}

void cutflowNew()
{
   cutflowNewRun(0);
   cutflowNewRun(1);
   cutflowNewRun(2);
   cutflowNewRun(3);
   cutflowNewRun(4);
   cutflowNewRun(5);

}

