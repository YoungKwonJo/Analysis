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
                       const int xBins_, const double xmin_, const double xmax_)
  {
    name   = name_;    varexp = varexp_;    title  = title_;
    xBins  = xBins_;    xmin   = xmin_;    xmax   = xmax_;
  }
  ~MonitorPlot(){}
  string name;  string varexp;  string title;
  int xBins;    double xmin;    double xmax;
};

TH1F* plot(MonitorPlot mplot,TString fname, TTree* tree, TCut selection)
{
  const string name = mplot.name;
  const string varexp = mplot.varexp;
  const string title = mplot.title;
  const int nBins = mplot.xBins;
  const double xMin = mplot.xmin;
  const double xMax = mplot.xmax;  

    TString HistName = Form("h%s_%s", name.c_str(), fname.Data());
    cout << " histName" << HistName.Data() << endl;
    TH1F *h = new TH1F(HistName, title.c_str(), nBins, xMin,xMax);
    tree->Project(HistName, varexp.c_str(), selection);
    h->AddBinContent(nBins, h->GetBinContent(nBins+1));

    if(nBins<10)
    {
       for ( int bin=1; bin<nBins; ++bin )
       {
         h->GetXaxis()->SetBinLabel(bin, Form("%d", int(xMin+bin-1)));
       }
       h->GetXaxis()->SetBinLabel(nBins, Form("#geq%d", int(xMin+nBins-1)));
    }
    return h;
}


