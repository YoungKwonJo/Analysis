#ifndef HistSet_h
#define HistSet_h

#include <vector>
#include <string>
#include <TLorentzVector.h>
#include <TH1F.h>
#include <TH2F.h>
#include <iostream>
//#include "SampleSet.h"
using namespace std;

class HistSet{
  public:
   explicit HistSet(char* plotname, char* variable, int nBins, double min, double max, const char* title, const char* xtitle, const char* ytitle)
   {
       plotname_=plotname; variable_=variable;
       title_=title; xtitle_=xtitle; ytitle_=ytitle;
       nBins_=nBins; min_=min; max_=max;
   }
   void print()
   {
     cout << "plotname:"<<plotname_ <<", variable:"<< variable_ <<", title:\""<< title_ <<"\", xtitle:\""<< xtitle_ <<"\", ytitle:\""<< ytitle_
          <<"\", bin:"<<nBins_<< ", min:" <<min_ << ", max:"<< max_  << endl;
   }
   ~HistSet(){}

   std::string plotname_, variable_, title_, xtitle_,ytitle_;
   int nBins_;
   double min_, max_;
  // TH1F *h1, h11;
  // TH2F *h2, h22;

};

#endif
