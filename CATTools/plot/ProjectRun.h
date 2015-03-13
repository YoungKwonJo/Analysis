#ifndef ProjectRun_h
#define ProjectRun_h

#include <vector>
#include <string>
#include <TLorentzVector.h>
#include <TH1F.h>
#include <TChain.h>
#include <TFile.h>
#include <TH1F.h>
#include <TString.h>
#include <iostream>
#include <sstream>
#include <algorithm>
#include "SampleSet.h" 
#include "CutSet.h"
#include "HistSet.h"
#include "Project.h"

using namespace std;

class ProjectRun{
  public:
   explicit ProjectRun(){
     samples =sampleset();
   }
   ~ProjectRun(){}
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
////for ttbar signal definition
      TCut visible = "(gentop_NJets20>=4)&&(gentop_NbJets20>=2)&&(gentop_lep1_pt>20)&&(abs(gentop_lep1_eta)<2.4)&&(gentop_lep2_pt>20)&&(abs(gentop_lep2_eta)<2.4)";
      TCut ttbb = visible && "gentop_NbJets20>=4";
      TCut ttbj = visible && "gentop_NbJets20>=3 && !(gentop_NbJets20>=4)";
      TCut ttcc = visible && "gentop_NcJets20>=2 && !(gentop_NbJets20>=3)";
      TCut ttLF = visible && !ttbb && !ttbj && !ttcc;
      TCut ttOth = !visible;
      
      const char* sigsample[] = {"t#bar{t}b#bar{b}","t#bar{t}bj",
        "t#bar{t}c#bar{c}", "t#bar{t}LF","t#bar{t} other"
      };
      const char* signame[] = {"ttbb","ttbj",
        "ttcc", "ttLF","ttother"
      };
      //https://twiki.cern.ch/twiki/bin/viewauth/CMS/StandardModelCrossSectionsat13TeV
      //https://twiki.cern.ch/twiki/bin/view/LHCPhysics/TtbarNNLO
      //https://twiki.cern.ch/twiki/bin/viewauth/CMS/SingleTopSigma
      const double sigCX = 831.76;// ttbar mass : 172.5
      const double bkgCX[]={2008.4,20508.9,35.6,35.6
        // 118.7, 66.1, 31.8 // W+W-, W+/-Z (m_ll>12), Z/a* Z/a*(M_ll>12)
      };//
      const char* bkgsample[] = {"Z/#gamma* #rightarrow ll","W #rightarrow l#nu","Single top","Single top"
      //, "WW","WZ","ZZ"
      //, "multi jet"
      };
      const char* bkgname[] = {"dy","wj","tw","tbw"
      };
      TCut bkgcut ="1";
      
      const Color_t bkgcolor[] = {kAzure-2,kGreen-3,kGreen,kGreen
       //, kGray+4, kGray+4, kGray+4
       //, kYellow
      };
      const Color_t sigcolor[] = {kRed+3,kOrange,kOrange+2,kRed,kRed-7};
      TCut sigcut[] = {ttbb, ttbj,ttcc,ttLF,ttOth};
      
//////////
      const string loc = "../../mini/result_", tag="_tag711_aod.root";
      //string ttbarfilelist=loc+"ttbar_nonu_0"+tag;
      /*for(unsigned int i=1;i<10;i++){
         char ii = (char)(((int)'0')+i);;
         ttbarfilelist=ttbarfilelist+","+loc+"ttbar_nonu_"+ii+tag;
      }
      cout << ttbarfilelist << endl;
      */
      std::vector<string> ttbarfilelist;
      for(unsigned int i=0;i<10;i++){
         char ii = (char)(((int)'0')+i);;
         ttbarfilelist.push_back(loc+"ttbar_nonu_"+ii+tag);
      }
      std::vector<string> bkgfilelist;
      //string bkgFileList[] ={loc+"dy"+tag+",", loc+"wj"+tag+",", loc+"tw"+tag+",", loc+"tbw"+tag+","
      string bkgFileList[] ={loc+"dy"+tag, loc+"wj"+tag, loc+"tw"+tag, loc+"tbw"+tag
       //, loc+"ww"+tag,loc+"wz"+tag,loc+"zz"+tag
       //,loc+"qcd"+tag
      };
      
       std::vector<SampleSet>* samples;
       samples = new std::vector<SampleSet>;
       unsigned int sigcount = sizeof(sigcut)/sizeof(sigcut[0]);
       unsigned int bkgcount = sizeof(bkgFileList)/sizeof(bkgFileList[0]);
       for(unsigned i=0;i<bkgcount;i++) cout<< bkgFileList[i] << endl;
      
       for(unsigned i=0;i<sigcount;i++) samples->push_back( SampleSet(signame[i],sigsample[i],ttbarfilelist,sigcolor[i],sigCX,true,sigcut[i]));
       for(unsigned i=0;i<bkgcount;i++) 
       {
         bkgfilelist.clear(); bkgfilelist.push_back(bkgFileList[i]);
         samples->push_back( SampleSet(bkgname[i],bkgsample[i],bkgfilelist,bkgcolor[i],bkgCX[i],true,bkgcut));
       }
       return samples;
  
   }

   std::vector<TH1F*> proj2h1(std::vector<TH1F*> result_, const char *plotname, const char* xtitle, const char* ytitle, int nBins, double min, double max, bool logy, int cutN) 
   {
     HistSet histSet(plotname,plotname,nBins,min,max,plotname,xtitle,ytitle);
     histSet.print();
  
     cutSet = cutset(cutN);
     //CutSet *cutSet = cutset(cutN);
     //std::vector<SampleSet>* samples =sampleset();
  
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
     return result;
   }
   std::vector<SampleSet>* samples;
   CutSet *cutSet;
};

#endif