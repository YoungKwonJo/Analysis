#include "TFile.h"
#include "TChain.h"
#include "TTree.h"

#include "TCanvas.h"
#include "TPad.h"
#include "TLegend.h"
#include "TH2F.h"
#include "THStack.h"
#include "TGraph.h"

#include <iostream>
#include <fstream>
#include <set>
#include <algorithm>
#include <sstream>
#include <iomanip>

class MonitorPlot2
{
 public:
  explicit MonitorPlot2(const string name_, const string varexp_, const string title_,
                       const int xBins_, const double xmin_, const double xmax_,
                       const int yBins_, const double ymin_, const double ymax_)
  {
    name   = name_;    varexp = varexp_;    title  = title_;
    xBins  = xBins_;    xmin   = xmin_;    xmax   = xmax_;
    yBins  = yBins_;    ymin   = ymin_;    ymax   = ymax_;
  }
  ~MonitorPlot2(){}
  string name;  string varexp;  string title;
  int xBins;    double xmin;    double xmax;
  int yBins;    double ymin;    double ymax;
};

TH2F* plot2(MonitorPlot2 mplot,TString fname, TTree* tree, TCut selection)
{
  const string name = mplot.name;
  const string varexp = mplot.varexp;
  const string title = mplot.title;
  const int xBins = mplot.xBins;
  const double xMin = mplot.xmin;
  const double xMax = mplot.xmax;  
  const int yBins = mplot.yBins;
  const double yMin = mplot.ymin;
  const double yMax = mplot.ymax;  

    TString HistName = Form("h%s_%s", name.c_str(), fname.Data());
    cout << " histName" << HistName.Data() << endl;
    TH2F *h = new TH2F(HistName, title.c_str(), xBins, xMin,xMax, yBins, yMin,yMax);
    tree->Project(HistName, varexp.c_str(), selection);
    //h->AddBinContent(nBins, h->GetBinContent(nBins+1));

    return h;
}


