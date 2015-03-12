#ifndef SampleSet_h
#define SampleSet_h

//#include <vector>
#include <string>
//#include <sstream>
//#include <TLorentzVector.h>
//#include <TChain.h>
#include <TCut.h>
//#include <TH1F.h>
#include <iostream>
using namespace std;

class SampleSet{
  public:
   explicit SampleSet(){}
   //SampleSet(char* name, char* label, char* filelist, Color_t color, double norm, bool isMC, char* SD)
   SampleSet(const char* name, const char* label, vector<string> filelist, Color_t color, double norm, bool isMC, TCut SD)
   {
      name_=name; 
      label_ = label;
      filelist_ = filelist;
      norm_=norm;
      color_=color;
      isMC_=isMC;
      SD_=SD;
   }
   void print()
   {
     cout << "samplename:"<<name_ 
         // << ", filelist:\""<< filelist_ <<
          << "\", label:\""<< label_ <<"\", color:\""<< color_ <<"\", norm:\""<< norm_
          <<"\", isMC:"<<isMC_ << ", signal-selection:"<< SD_.GetTitle()<< endl;
   }
///////
   ~SampleSet(){}
   //string filelist_;
   vector<string> filelist_;
   //string SD_;
   TCut SD_;
   string name_;
   string label_;
   Color_t color_;
   double norm_;
   bool isMC_;
//   bool isSignal_;
};
#endif
