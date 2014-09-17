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

class MonitorPlot
{
 public:
  explicit MonitorPlot(const string name_, const string varexp_, const string title_,
                       const int xBins_, const double xmin_, const double xmax_, bool over_=true)
  {
    name   = name_;    varexp = varexp_;    title  = title_;
    xBins  = xBins_;    xmin   = xmin_;    xmax   = xmax_;
    over = over_;
  }
  ~MonitorPlot(){}
  string name;  string varexp;  string title;
  int xBins;    double xmin;    double xmax;
  bool over;
};

class Sample
{
 public:
  explicit Sample(const string fileName_, const string treeName_, const string name_, 
   const string label_,const Color_t color_,  const int style_, const double width_, 
   const bool isMC_=false,  const double xsec_=1)
  {
     name   = name_;    label = label_;
     color  = color_;   style = style_;   width = width_;
     isMC = isMC_;      xsec = xsec_;

     chain = new TChain(treeName_.c_str(), treeName_.c_str());
     TFile* f = TFile::Open(fileName_.c_str());
     if ( !f || !f->IsOpen() ) cout << "Cannot open file\n";
     else
     {
       chain->Add(fileName_.c_str());
     }
     
     nEvents = chain->GetEntries(); 
  }
  ~Sample(){}
  TChain* chain;
  string name;  string label;  Color_t color;  int style; double width;
  bool isMC; int nEvents; double  xsec; // xsec unit : pb 
};
class Cut
{
 public:
  explicit Cut(){  }
  ~Cut(){}

  void addCut(const string cut_, const string weight_) { cut.push_back(cut_.c_str()); weight.push_back(weight_.c_str()); }
  TCut useCut(int i) { return cut.at(i) && weight.at(i); }
  TCut useCut2(int i) 
  {
     TCut cut_;
     for(int j=0;j<cut.size();j++)
     if(j<=i){
        cut_+=cut.at(j);
     }
     return cut_ && weight.at(i);
  }
  int Entries() { return cut.size(); }
  std::vector<TCut> cut; 
  std::vector<TCut> weight; 
};


TH1F* plot(MonitorPlot mplot,TString fname, TTree* tree, TCut selection)
{
  const string name = mplot.name;
  const string varexp = mplot.varexp;
  const string title = mplot.title;
  const int nBins = mplot.xBins;
  const bool over = mplot.over;
  const double xMin = mplot.xmin;
  const double xMax = mplot.xmax;  

    TString HistName = Form("h%s_%s", name.c_str(), fname.Data());
    cout << " histName" << HistName.Data() << endl;
    TH1F *h = new TH1F(HistName, title.c_str(), nBins, xMin,xMax);
    tree->Project(HistName, varexp.c_str(), selection);
    if(over) h->AddBinContent(nBins, h->GetBinContent(nBins+1));

    if(nBins<10)
    {
       for ( int bin=1; bin<nBins; ++bin )
       {
         h->GetXaxis()->SetBinLabel(bin, Form("%d", int(xMin+bin-1)));
       }
       if(over) h->GetXaxis()->SetBinLabel(nBins, Form("#geq%d", int(xMin+nBins-1)));
    }
    return h;
}


