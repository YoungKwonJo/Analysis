#ifndef Project_h
#define Project_h

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

using namespace std;

class Project{
  public:
   explicit Project(SampleSet& s, HistSet& h, CutSet& c)
   {
      TString nameMuMu = Form("h_%s_%s_%s_MuMu",s.name_.c_str(),c.step_.c_str(),h.plotname_.c_str());
      TString nameElEl = Form("h_%s_%s_%s_ElEl",s.name_.c_str(),c.step_.c_str(),h.plotname_.c_str());
      TString nameMuEl = Form("h_%s_%s_%s_MuEl",s.name_.c_str(),c.step_.c_str(),h.plotname_.c_str());
      TString nameLL =   Form("h_%s_%s_%s_LL"  ,s.name_.c_str(),c.step_.c_str(),h.plotname_.c_str());

      cout << "bin:" << h.nBins_<< ", "<< h.min_ << ", "<<h.max_ <<", name:"<< nameMuMu.Data() << endl;
      h1 = new TH1F(nameMuMu, Form("%s %s MuMu",h.title_.c_str(), c.step_.c_str()), h.nBins_,h.min_,h.max_);
      //h1->SetLineColor(color);      
      h1->GetXaxis()->SetTitle(h.xtitle_.c_str()); h1->GetYaxis()->SetTitle(h.ytitle_.c_str());
      h2 = new TH1F(nameElEl, Form("%s %s ElEl",h.title_.c_str(), c.step_.c_str()), h.nBins_,h.min_,h.max_);
      //h2->SetLineColor(color);      
      h2->GetXaxis()->SetTitle(h.xtitle_.c_str()); h2->GetYaxis()->SetTitle(h.ytitle_.c_str());
      h3 = new TH1F(nameMuEl,Form("%s %s MuEl",h.title_.c_str(), c.step_.c_str()),h.nBins_,h.min_,h.max_);
      //h3->SetLineColor(color);      
      h3->GetXaxis()->SetTitle(h.xtitle_.c_str()); h3->GetYaxis()->SetTitle(h.ytitle_.c_str());

      char *delim=",";
      //vector<string> filelist2=split(s.filelist_,*delim);
      TChain * chainMuMu_ = new TChain("ntupleMuMu");
      for(unsigned int i=0;i<s.filelist_.size();i++) chainMuMu_->Add(Form("%s",s.filelist_.at(i).c_str()));
      TChain * chainElEl_ = new TChain("ntupleElEl");
      for(unsigned int i=0;i<s.filelist_.size();i++) chainElEl_->Add(Form("%s",s.filelist_.at(i).c_str()));
      TChain * chainMuEl_ = new TChain("ntupleMuEl");
      for(unsigned int i=0;i<s.filelist_.size();i++) chainMuEl_->Add(Form("%s",s.filelist_.at(i).c_str()));
      TCut cut = s.SD_;
      //TCut cut = Form("%s",s.SD_.c_str());
      cout << "starting project ..." << endl; 
      chainMuMu_->Project(nameMuMu,h.variable_.c_str(),(cut*c.weight_*c.cut_));
      chainElEl_->Project(nameElEl,h.variable_.c_str(),(cut*c.weight_*c.cut_));
      chainMuEl_->Project(nameMuEl,h.variable_.c_str(),(cut*c.weight_*c.cut_em_) );

      h1->SetBinContent(h.nBins_,h1->GetBinContent(h.nBins_)+h1->GetBinContent(h.nBins_+1));
      h2->SetBinContent(h.nBins_,h2->GetBinContent(h.nBins_)+h2->GetBinContent(h.nBins_+1));
      h3->SetBinContent(h.nBins_,h3->GetBinContent(h.nBins_)+h3->GetBinContent(h.nBins_+1));

      h4 = (TH1F*) h1->Clone(nameLL); h4->SetTitle(Form("%s %s LL",h.title_.c_str(), c.step_.c_str()));
      h4->Add(h2); h4->Add(h3);
////////
      //TFile *file[50]; 
      TH1F *hNEvent[50];
      for(unsigned int i=0;i<s.filelist_.size();i++)
      {
         TFile *file = TFile::Open(s.filelist_.at(i).c_str());
         hNEvent[i]= (TH1F*) file->Get("hNEvent")->Clone(Form("hNEvent%d",i));
         if(i>0) hNEvent[0]->Add(hNEvent[i]);
         //file[i]->Close();
         cout << s.filelist_.at(i) << endl;
      }
      double Ntot = hNEvent[0]->GetBinContent(1);
      cout << "total events: "<< s.name_.c_str() << " : " << Ntot << endl;

////////     
      cout << "finished project." << endl;
      h11=(TH1F*) h1->Clone(Form("%s_sumw2",h1->GetName()));
      h22=(TH1F*) h2->Clone(Form("%s_sumw2",h2->GetName()));
      h33=(TH1F*) h3->Clone(Form("%s_sumw2",h3->GetName()));
      h44=(TH1F*) h4->Clone(Form("%s_sumw2",h4->GetName()));
      h11->Sumw2(); h22->Sumw2(); h33->Sumw2(); h44->Sumw2();
      double norm = s.norm_/Ntot; // cross section/total events 
      h1->Scale(norm);  h11->Scale(norm);
      h2->Scale(norm);  h22->Scale(norm);
      h3->Scale(norm);  h33->Scale(norm);
      h4->Scale(norm);  h44->Scale(norm);
   }
/////
   /*
   std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
      std::stringstream ss(s);
      std::string item;
      while (std::getline(ss, item, delim)) {
          elems.push_back(item);
      }
      return elems;
   }
   std::vector<std::string> split(const std::string &s, char delim) {
      std::vector<std::string> elems;
      split(s, delim, elems);
      return elems;
   }*/
/////
   ~Project(){}
   TH1F *h1, *h2, *h3, *h4;
   TH1F *h11, *h22, *h33, *h44;
};

#endif
