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

void project()
{
  std::vector<TH1F*> result ;
  result = projectlist();

  TFile fout(Form("hist_output.root"), "RECREATE");
  for(unsigned int i =0;i<result.size();i++) result.at(i)->Write();
  fout.Write();
  fout.Close();

}
std::vector<TH1F*> projectlist()
{
  bool log = true;
  std::vector<TH1F*> result ;
  //result =proj2h1(result,"gentop_NJets20","# of Jet in GEN","Entries",15,0,15,log,0);
  //result =proj2h1(result,"nJet30","# of Jet30","Entries",10,0,10,log,4);
  //result =proj2h1(result,"nbJet30T","# of bTag CSVT","Entries",5,0,5,log,5);
  //result =proj2h1(result,"MET","MET","Entries",30,0,150,log,3);
  //result =proj2h1(result,"ZMass","invariant mass of dilepton","Entries",50,0,200,log,2);
  //S-1
  result = proj2h1(result,"gentop_NJets20","# of Jet in GEN","Entries",15,0,15,log,-1);
  //result.insert(result.end(),result1[0].begin(),result1[0].end());

  //return result;

  //break;
  //S0
   result = proj2h1(result,"lep1_pt","p_T of leading lepton","Entries",40,0,200,log,0);
  return result;
  //break;
   result = proj2h1(result,"lep2_pt","p_T of second leading lepton","Entries",40,0,200,log,0);
   result = proj2h1(result,"lep1_eta","#eta of leading lepton","Entries",20,-2.5,2.5,log,0);
   result = proj2h1(result,"lep2_eta","#eta of second leading lepton","Entries",20,-2.5,2.5,log,0);
   result = proj2h1(result,"lep1_relIso","Iso40_{rel} of leading lepton","Entries",50,0,5,log,0);
   result = proj2h1(result,"lep2_relIso","Iso40_{rel} of second leading lepton","Entries",50,0,5,log,0);
 
  //S1
   result = proj2h1(result,"ZMass","invariant mass of dilepton","Entries",40,0,200,log,1);
   result = proj2h1(result,"lep1_pt","p_T of leading lepton","Entries",40,0,200,log,1);
   result = proj2h1(result,"lep2_pt","p_T of second leading lepton","Entries",40,0,200,log,1);
   result = proj2h1(result,"lep1_eta","#eta of leading lepton","Entries",20,-2.5,2.5,log,1);
   result = proj2h1(result,"lep2_eta","#eta of second leading lepton","Entries",20,-2.5,2.5,log,1);

  //S2
   result = proj2h1(result,"ZMass","invariant mass of dilepton","Entries",40,0,200,log,2);
   result = proj2h1(result,"MET","MET","Entries",30,0,150,log,2);

  //S3
   result = proj2h1(result,"MET","MET","Entries",30,0,150,log,3);
   result = proj2h1(result,"nJet30","# of Jet30","Entries",10,0,10,log,3);

  //S4
   result = proj2h1(result,"nJet30","# of Jet30","Entries",10,0,10,log,4);
   result = proj2h1(result,"nbJet30T","# of bTag CSVT","Entries",5,0,5,log,4);
   result = proj2h1(result,"nbJet30M","# of bTag CSVM","Entries",7,0,7,log,4);
   result = proj2h1(result,"nbJet30L","# of bTag CSVL","Entries",7,0,7,log,4);

   result = proj2h1(result,"jet1_pt","p_T of 1st jet","Entries",40,0,200,log,4);
   result = proj2h1(result,"jet1_eta","#eta of 1st jet","Entries",10,-2.5,2.5,log,4);
   result = proj2h1(result,"jet1_phi","#phi of 1st jet","Entries",14,-3.5,3.5,log,4);
   result = proj2h1(result,"jet1_bTag","CSV of 1st jet","Entries",10,0,10,log,4);

   result = proj2h1(result,"jet2_pt","p_T of 2nd jet","Entries",40,0,200,log,4);
   result = proj2h1(result,"jet2_eta","#eta of 2nd jet","Entries",10,-2.5,2.5,log,4);
   result = proj2h1(result,"jet2_phi","#phi of 2nd jet","Entries",14,-3.5,3.5,log,4);
   result = proj2h1(result,"jet2_bTag","CSV of 2nd jet","Entries",10,0,10,log,4);

   result = proj2h1(result,"jet3_pt","p_T of 3rd jet","Entries",50,0,200,log,4);
   result = proj2h1(result,"jet3_eta","#eta of 3rd jet","Entries",10,-2.5,2.5,log,4);
   result = proj2h1(result,"jet3_phi","#phi of 3rd jet","Entries",14,-3.2,3.5,log,4);
   result = proj2h1(result,"jet3_bTag","CSV of 3rd jet","Entries",10,0,10,log,4);

   result = proj2h1(result,"jet4_pt","p_T of 4th jet","Entries",50,0,200,log,4);
   result = proj2h1(result,"jet4_eta","#eta of 4th jet","Entries",25,-2.5,2.5,log,4);
   result = proj2h1(result,"jet4_phi","#phi of 4th jet","Entries",14,-3.5,3.5,log,4);
   result = proj2h1(result,"jet4_bTag","CSV of 4th jet","Entries",10,0,10,log,4);

  //S51
   result = proj2h1(result,"jet1_bTag","CSV of 1st jet","Entries",10,0,1,log,5);
   result = proj2h1(result,"jet2_bTag","CSV of 2nd jet","Entries",10,0,1,log,5);
   result = proj2h1(result,"jet3_bTag","CSV of 3rd jet","Entries",10,0,1,log,5);
   result = proj2h1(result,"jet4_bTag","CSV of 4th jet","Entries",10,0,1,log,5);

   //S52
   result = proj2h1(result,"jet1_bTag","CSV of 1st jet","Entries",10,0,1,log,6);
   result = proj2h1(result,"jet2_bTag","CSV of 2nd jet","Entries",10,0,1,log,6);
   result = proj2h1(result,"jet3_bTag","CSV of 3rd jet","Entries",10,0,1,log,6);
   result = proj2h1(result,"jet4_bTag","CSV of 4th jet","Entries",10,0,1,log,6);

  //S53
   result = proj2h1(result,"jet1_bTag","CSV of 1st jet","Entries",10,0,1,log,7);
   result = proj2h1(result,"jet2_bTag","CSV of 2nd jet","Entries",10,0,1,log,7);
   result = proj2h1(result,"jet3_bTag","CSV of 3rd jet","Entries",10,0,1,log,7);
   result = proj2h1(result,"jet4_bTag","CSV of 4th jet","Entries",10,0,1,log,7);

}
CutSet* cutset(int cutN)
{
  TCut S0 = "lep1_pt>20. && abs(lep1_eta)<2.5 && lep2_pt>20. && abs(lep2_eta)<2.5";
  TCut S1 = "lep1_relIso<0.15 &&  lep2_relIso<0.15 && ZMass>12 && lep1_Q*lep2_Q<0 ";
  TCut S2 = "abs(ZMass-91)>15";
  TCut S3 = "MET>30";
  TCut S4 = "nJet30>=4";
  TCut S51 = "nbJet30L>=2";
  TCut S52 = "nbJet30M>=2";
  TCut S53 = "nbJet30T>=2";
  TCut stepcut = "1", stepcut_em="1";  char *step = "nocut";

  if(cutN==0) { stepcut = S0;  step = "S0";                 stepcut_em=stepcut;  }
  if(cutN==1) { stepcut = S0+S1;  step = "S1";              stepcut_em=stepcut;  }
  if(cutN==2) { stepcut = S0+S1+S2;  step = "S2";           stepcut_em=S0+S1;    }
  if(cutN==3) { stepcut = S0+S1+S2+S3;  step = "S3";        stepcut_em=S0+S1;    }
  if(cutN==4) { stepcut = S0+S1+S2+S3+S4;  step = "S4";     stepcut_em=S0+S1+S4; }
  if(cutN==5) { stepcut = S0+S1+S2+S3+S4+S51;  step = "S51";stepcut_em=S0+S1+S4+S51; }
  if(cutN==6) { stepcut = S0+S1+S2+S3+S4+S52;  step = "S52";stepcut_em=S0+S1+S4+S52; }
  if(cutN==7) { stepcut = S0+S1+S2+S3+S4+S53;  step = "S53";stepcut_em=S0+S1+S4+S53; }

  CutSet *cutSet = new CutSet(step, stepcut, stepcut_em, "1");
  cutSet->print();
  return cutSet;
}
std::vector<SampleSet>* sampleset()
{
//for ttbar signal definition
  TCut visible = "(gentop_NJets20>=4)&&(gentop_NbJets20>=2)&&(gentop_lep1_pt>20)&&(abs(gentop_lep1_eta)<2.4)&&(gentop_lep2_pt>20)&&(abs(gentop_lep2_eta)<2.4)";
  TCut ttbb = visible && "gentop_NbJets20>=4";
  TCut ttbj = visible && "gentop_NbJets20>=3 && !(gentop_NbJets20>=4)";
  TCut ttcc = visible && "gentop_NcJets20>=2 && !(gentop_NbJets20>=3)";
  TCut ttLF = visible && !ttbb && !ttbj && !ttcc;
  TCut ttOth = !visible;

  const char* mcsample[] = {"t#bar{t}b#bar{b}","t#bar{t}bj",
    "t#bar{t}c#bar{c}", "t#bar{t}LF","t#bar{t} other"
  };
  const char* mcname[] = {"ttbb","ttbj",
    "ttcc", "ttLF","ttother"
  };
  const Color_t color[] = {kRed,kBlue,kGreen,kViolet,kOrange};
  TCut sigcut[] = {ttbb, ttbj,ttcc,ttLF,ttOth};

  const string loc = "./result_", tag="_tag711_aod.root";
  string ttbarfilelist=loc+"ttbar_nonu_0"+tag;
  string bkgFileList[] ={loc+"wj"+tag, loc+"dy"+tag, loc+"tw"+tag, loc+"tbw"+tag};
  //for(unsigned int i=1;i<8;i++)
  //  ttbarfilelist=ttbarfilelist+",../../mini/result_ttbar_"+i+"_tag711_aod.root";
///////////////

   std::vector<SampleSet>* samples;
   samples = new std::vector<SampleSet>;
   unsigned int sigcount = sizeof(sigcut)/sizeof(sigcut[0]);
   for(unsigned i=0;i<sigcount;i++) samples->push_back( SampleSet(mcname[i],mcsample[i],ttbarfilelist.c_str(),color[i],true,1.,sigcut[i]));

   return samples;
}

std::vector<TH1F*> proj2h1(std::vector<TH1F*> result_, const char *plotname, const char* xtitle, const char* ytitle, int nBins, double min, double max, bool logy, int cutN) 
{
  gROOT->ProcessLine(".L SampleSet.h+g");
  gROOT->ProcessLine(".L HistSet.h+g");
  gROOT->ProcessLine(".L CutSet.h+g");
  gROOT->ProcessLine(".L Project.h+g");

  gStyle->SetOptStat(0); //remove statistics box
  gROOT->ProcessLine(".L ./tdrstyle.C");
  defaultStyle();
//  gStyle->SetCanvasDefH(610);  gStyle->SetCanvasDefW(900);
  HistSet histSet(plotname,plotname,nBins,min,max,plotname,xtitle,ytitle);
  histSet.print();

  CutSet *cutSet = cutset(cutN);
  std::vector<SampleSet>* samples =sampleset();

  std::vector<TH1F*> result;
  result.insert(result.end(),result_.begin(),result_.end());
  for(unsigned int i=0;i<samples->size();i++)
  {
     Project *a = new Project(samples->at(i), histSet, *cutSet); 
     result.push_back(a->h1);
     result.push_back(a->h2);
     result.push_back(a->h3);
     result.push_back(a->h4);
     result.push_back(a->h11);
     result.push_back(a->h22);
     result.push_back(a->h33);
     result.push_back(a->h44);
  }
//////////////////////////
  return result;

}


