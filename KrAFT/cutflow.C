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
const char* bkgLabels[] = {    "t#bar{t}+bj             ",
  "t#bar{t}+cc             ", "t#bar{t}+LF             ","t#bar{t} others         ",
//"W #rightarrow l#nu", "Dibosons",
 "Single top              ", "Z/#gamma* #rightarrow ll"
//,"QCD"
};
const char* bkgLabels2[] = {    "$t\\bar{t}+bj$             ",
  "$t\\bar{t}+cc$             ", "$t\\bar{t}+LF$             ","$t\\bar{t} others$         ",
//"$W \\rightarrow l\\nu$", "Dibosons",
 "Single top                ", "$Z/\\gamma* \\rightarrow ll$"
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
const char* sigLabels[] = {"t#bar{t}+bb             "};//"t#bar{t}+H"};
const char* sigLabels2[] = {"$t\\bar{t}+bb$             "};//"t#bar{t}+H"};
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
  //TPaveText *pt = new TPaveText(0.21,0.70,0.21,0.86,"brNDC"); //for two rows
  TPaveText *pt = new TPaveText(0.21,0.647,0.21,0.86,"brNDC");  //for three rows

  pt->SetBorderSize(1);
  pt->SetTextFont(42);
  pt->SetTextSize(0.06);
  pt->SetLineColor(0);
  pt->SetLineStyle(1);
  pt->SetLineWidth(1);
  pt->SetFillColor(0);
  pt->SetFillStyle(1001);
  pt->SetTextAlign(12);
  //pt->AddText("CMS Preliminary");
  pt->AddText("Preliminary");
  pt->AddText(Form("%.1f fb^{-1} at  #sqrt{s} = 8 TeV", lumi));
  pt->AddText(Form("%s",channelName.Data()));

  return pt;
}
double round( double value, int pos )
{
      double temp;
      temp = value * pow( 10, pos );  
      temp = floor( temp + 0.5 );     
      temp *= pow( 10, -pos );        
      return temp;
} 


/////////////////////////////
void cutflow()
{

   f=TFile::Open("./result.root");
   outDirName += "/ccc";
   gSystem->Exec("mkdir "+outDirName);
   gSystem->Exec("mkdir "+outDirName+"/log");
   gSystem->Exec("mkdir "+outDirName+"/linear");


   gROOT->ProcessLine(".L ./tdrstyle.C");
   defaultStyle();

    const int nBins=5;
    const bool isSS=true;
    string cuts[nBins]={"base","z-veto","MET","4jet","2bjet"};

   bool doLogY=true;
   const int nNN=nBkg+2, nD=nBkg+1;
   TH1F *h[nNN][4], *h2[4], *h3[4], *h4[nNN], *h11[nNN][4];

   double stat[nNN][4][5];
   double statError[nNN][4][5];

   THStack* hStack[4];
   TLegend* leg[4];
   const char *NN[4] = {"ElEl","MuMu","MuEl","all"};

   //for LL
   hStack[3] = new THStack(Form("h_%s",NN[3]),"");
   leg[3] = buildLegend( (double) nExclude*0.02);
   int nBins=0;

   for(int j=0;j<3;j++)
   {
        hStack[j] = new THStack(Form("h_%s",NN[j]),"");
        leg[j] = buildLegend( (double) nExclude*0.02);

        //for data
        h[nD][j] = (TH1F*)f->Get(Form("hStep_%s_data_", DecayMode[j] ));
        h[nD][j]->SetMarkerStyle(20);
        if(h[nD][j]->GetEntries() > 0) leg[j]->AddEntry(h[nD][j], "DATA", "p");
        for(int i=0;i<5;i++) 
        {
           stat[nD][j][i] = h[nD][j]->GetBinContent(i+1); 
           if(j==0) stat[nD][3][i] = h[nD][j]->GetBinContent(i+1); 
           else     stat[nD][3][i] = h[nD][j]->GetBinContent(i+1)+stat[nD][3][i]; 
        }

        //for signal
        h[nBkg][j] = (TH1F*)f->Get(Form("hStep_%s_%s",DecayMode[j],sigNames[0] ));
        h11[nBkg][j] = (TH1F*)f->Get(Form("hStep_%s_%s_Sumw2",DecayMode[j],sigNames[0] ));
        h[nBkg][j]->SetFillColor(color_sig);
        h[nBkg][j]->SetLineColor(kBlack);
        h[nBkg][j]->SetFillStyle(style_sig);
        for(int i=0;i<5;i++) 
        {
           stat[nBkg][j][i] = h11[nBkg][j]->GetBinContent(i+1);
           statError[nBkg][j][i] = h11[nBkg][j]->GetBinError(i+1);
           if(j==0) statError[nBkg][3][i] = statError[nBkg][j][i];
           else     statError[nBkg][3][i] = sqrt(statError[nBkg][j][i]*statError[nBkg][j][i] +statError[nBkg][3][i]*statError[nBkg][3][i] );

        }
 
        h2[j] = (TH1F*) h11[nBkg][j]->Clone(Form("bkg%s",NN[j]));
        if(j==0) h2[3] = (TH1F*) h11[nBkg][j]->Clone(Form("bkg%s",NN[3]));

        if(isSS) hStack[j]->Add(h[nBkg][j]);
        //if(h[nBkg][j]->GetEntries() > 0) leg[j]->AddEntry(h[nBkg][j], sigLabels[0], "f");

        //for LL
        if(j==0) h4[nD] = (TH1F*) h[nD][j]->Clone(Form("dataLL"));
        else     h4[nD]->Add(h[nD][j]);
        if(j==0) h4[nBkg] = (TH1F*) h[nBkg][j]->Clone(Form("%sLL",sigNames[0]));
        else     h4[nBkg]->Add(h[nBkg][j]);
   }

   //for LL
   hStack[3]->Add(h4[nBkg]);
   leg[3]->AddEntry(h4[nBkg+1], "DATA", "p");
   //leg[3]->AddEntry(h4[nBkg], sigLabels[0], "f");
   for(int i=0;i<5;i++) stat[nD][3][i] = h4[nD]->GetBinContent(i+1);
   for(int i=0;i<5;i++) stat[nBkg][3][i] = h4[nBkg]->GetBinContent(i+1);

   for(int i=0;i<nBkg;i++) 
   {
       for(int j=0;j<3;j++)
       {
            //for background
            h[i][j]= (TH1F*)f->Get(Form("hStep_%s_%s", DecayMode[j], bkgNames[i]));
            h11[i][j]= (TH1F*)f->Get(Form("hStep_%s_%s_Sumw2", DecayMode[j], bkgNames[i]));
            h[i][j]->SetFillColor(color[i]);
            h[i][j]->SetLineColor(kBlack);
            h[i][j]->SetFillStyle(style[i]);
       
            hStack[j]->Add(h[i][j]); 
            for(int k=0;k<5;k++)
            {
                stat[i][j][k] = h11[i][j]->GetBinContent(k+1);       
                statError[i][j][k] = h11[i][j]->GetBinError(k+1);       
                if(j==0) statError[i][3][k] = h11[i][j]->GetBinError(k+1);       
                else     statError[i][3][k] = sqrt(h11[i][j]->GetBinError(k+1)*h11[i][j]->GetBinError(k+1)+statError[i][3][k]*statError[i][3][k] );
            }

            h2[j]->Add(h[i][j]);
       
            //for LL
            h2[3]->Add(h[i][j]);
            if(j==0) h4[i] = (TH1F*) h[i][j]->Clone(Form("%sLL",bkgNames[i]));
            else     h4[i]->Add(h[i][j]);
       }
       //for LL
       hStack[3]->Add(h4[i]);
       for(int k=0;k<5;k++) stat[i][3][k] = h4[i]->GetBinContent(k+1);
   }
//////////
  
   for(int i=nBkg-1;i>=0;i--) 
   {
      for(int j=0;j<3;j++)
         leg[j]->AddEntry(h[i][j], bkgLabels[i], "f");
      leg[3]->AddEntry(h4[i], bkgLabels[i], "f");
   }
   for(int j=0;j<3;j++) if(h[nBkg][j]->GetEntries() > 0) leg[j]->AddEntry(h[nBkg][j], sigLabels[0], "f"); // signal label
   leg[3]->AddEntry(h4[nBkg], sigLabels[0], "f");// signal label for LL

///////////
   const char *Na[4] ={"ee","#mu#mu","e#mu","All"};
   TCanvas *c[4];
   TPad *pad1[4], *pad2[4];
   double LogMin[4];

   for(int i=0;i<4;i++)
   {
     c[i] = new TCanvas(Form("c%s",NN[i]),Form("c%s",NN[i]),1);
     pad1[i] = new TPad(Form("pad1%s",NN[i]),"",0,0.3,1,1);
     pad2[i] = new TPad(Form("pad2%s",NN[i]),"",0,0,1,0.3);
     pad1[i]->Divide(1,1,0,0); pad2[i]->Divide(1,1,0,0);
     pad1[i]->SetBottomMargin(0);
     pad2[i]->SetTopMargin(0.1);
     pad2[i]->SetBottomMargin(0.3);
     pad1[i]->Draw();   pad2[i]->Draw();
     pad1[i]->cd();

     h2[i]->SetTitle("");
     h2[i]->GetXaxis()->SetTitle( "Cut Steps" );
     h2[i]->GetYaxis()->SetTitle( "Events" );

     h2[i]->SetMaximum(h2[i]->GetMaximum()*1.5);
     LogMin[i]=5;
//     if( i<3 && h[nBkg][i]->GetMinimum()<0.5) LogMin[i]=0.05;
//     if( i==3 && h4[nBkg]->GetMinimum()<0.5) LogMin[i]=0.05;
     if ( doLogY ){ pad1[i]->SetLogy(); h2[i]->SetMinimum(LogMin[i]); h2[i]->SetMaximum(h2[i]->GetMaximum()*500); }

     h2[i]->GetYaxis()->SetTitleSize(0.065);
     h2[i]->GetYaxis()->SetLabelSize(0.05);

     h2[i]->Draw();

     getHeader(19.8, Form("%s channel",Na[i]))->Draw(); leg[i]->Draw(); 
     hStack[i]->Draw("same");
     if(i<3) { h[nBkg+1][i]->Sumw2(); h[nBkg+1][i]->Draw("same");  h[nBkg][i]->Draw("sameaxis"); }
     else    { h4[nBkg+1]->Sumw2();   h4[nBkg+1]->Draw("same");    h4[nBkg]->Draw("sameaxis"); }

     pad1[i]->Draw();
     pad1[i]->Update(); 
     pad2[i]->cd();

     if(i<3) h3[i] = (TH1F*) h[nBkg+1][i]->Clone(Form("new%s",NN[i])); ///
     else    h3[i] = (TH1F*) h4[nBkg+1]->Clone(Form("new%s",NN[i]));

     h3[i]->Sumw2();
     h3[i]->Divide(h2[i]);
     h3[i]->SetTitle("");
     h3[i]->GetYaxis()->SetTitle("Data/MC");
     h3[i]->SetNdivisions( 505, "Y" );
     h3[i]->SetMarkerStyle(20);
     h3[i]->SetMaximum(2);
     h3[i]->SetMinimum(0);
     h3[i]->GetXaxis()->SetTitleSize(0.14);
     h3[i]->GetYaxis()->SetTitleSize(0.14);
     h3[i]->GetYaxis()->SetTitleOffset(0.4);
     h3[i]->GetYaxis()->SetLabelSize(0.1);
     h3[i]->GetXaxis()->SetLabelSize(0.13);

     h3[i]->GetXaxis()->SetTitle("Cut Steps");
     for ( int bin=1; bin<nBins+1; ++bin )
     {
         h3[i]->GetXaxis()->SetBinLabel(bin, Form("%s",cuts[bin-1].c_str()));
     } 
     //h3[i]->Draw("ex0");
     
     h3[i]->Draw();
     TLine *line = new TLine(h3[i]->GetXaxis()->GetXmin() ,1,h3[i]->GetXaxis()->GetXmax(),1);
     line->SetLineColor(kRed);
     line->Draw();
     
     pad2[i]->Draw();
     pad2[i]->Update();
     
     if ( doLogY ) c[i]->Print(Form("%s/log/Cutflow_%s.eps", outDirName.Data(), NN[i]));
     else          c[i]->Print(Form("%s/linear/Cutflow_%s.eps", outDirName.Data(), NN[i]));
   }

   //double stat[nNN][4][5];
   double statSum[4][5];
   double statSumError[4][5];
   for(int j=0;j<4;j++)
   for(int k=0;k<5;k++){  statSum[j][k]=0.;  statSumError[j][k]=0.; }

   const char *Na2[4] ={"$ee$","$\\mu\\mu$","$e\\mu$","All"};
   cout << "\\begin{tabular}{cccccc} \\hline\\hline" << endl;
   for(int j=0;j<4;j++)
   {
      cout << Na2[j] << "                       & ";
      for(int k=0;k<5;k++) 
      {
         cout<< cuts[k] ; 
         if(k<4) cout << " ~&~ " ; 
         else    cout << " \\\\ \\hline"<< endl;
      }

      cout << sigLabels2[0] << " & " ;
      for(int k=0;k<5;k++)
      {
            statSum[j][k] = stat[nBkg][j][k]+statSum[j][k];
            statSumError[j][k] = sqrt(statError[nBkg][j][k]*statError[nBkg][j][k]+statSumError[j][k]*statSumError[j][k]);
            if(stat[nBkg][j][k]<1000.) cout << round(stat[nBkg][j][k],1);
            else                       cout << (int) stat[nBkg][j][k];

            if(k<4) cout << " & " ;
            else    cout << "$\\pm$ " <<  round(statError[nBkg][j][k],2) << " \\\\ \\hline "<< endl;
      }
      cout << endl;
      for(int i=0;i<nBkg;i++)
      {
         cout << bkgLabels2[i] << " & " ; 
         for(int k=0;k<5;k++) 
         {

            statSum[j][k] = stat[i][j][k]+statSum[j][k];
            statSumError[j][k] = sqrt(statError[i][j][k]*statError[i][j][k]+statSumError[j][k]*statSumError[j][k]);

            if(stat[i][j][k]<1000.) cout << round(stat[i][j][k],1);
            else                    cout << (int) stat[i][j][k];
            if(k<4) cout << " & " ;
            else if(statError[i][j][k]==0) cout << " \\\\ "<< endl;
            else    cout << "$\\pm$ " <<  round(statError[i][j][k],2) << " \\\\ "<< endl;
         }
      }
      cout << "\\hline" << endl << "MC Total                   & ";
      for(int k=0;k<5;k++)
      {
         if(statSum[j][k]<1000.) cout << round(statSum[j][k],1) ;
         else                    cout << (int) statSum[j][k] ;

         if(k<4) cout << " & " ;
         else    cout << "$\\pm$ " <<  round(statSumError[j][k],2) << " \\\\ \\hline"<< endl;
      }
      cout << "DATA                       & " ;
      for(int k=0;k<5;k++)
      {
            cout << (int) stat[nD][j][k];
            if(k<4) cout << " & " ;
            else    cout << " \\\\ \\hline \\hline"<< endl;
      }

      cout << endl;
   }
   cout << "\\end{tabular} " <<endl;

///////////////////
   cout << "\\begin{tabular}{ccccc} \\hline\\hline" << endl;
   cout << "                        ";
   for(int j=0;j<4;j++)
   {
     cout <<  " ~&~ " << Na2[j] ;
   }
   cout << "\\\\ \\hline" << endl;
   cout << sigLabels2[0] << " & " ;
   for(int j=0;j<4;j++)
   {
      if(stat[nBkg][j][4]<1000.) cout << round(stat[nBkg][j][4],1);
      else                       cout << (int) stat[nBkg][j][4];
      cout << "$\\pm$ " <<  round(statError[nBkg][j][4],2);
      if(j<3) cout << " &";
   }
   cout << "\\\\ \\hline" << endl;
   for(int i=0;i<nBkg;i++)
   {
      cout << bkgLabels2[i] << " & " ; 

      for(int j=0;j<4;j++)
      {
         if(stat[i][j][4]<1000.) cout << round(stat[i][j][4],1);
         else                    cout << (int) stat[i][j][4];

         if(statError[i][j][4]==0) ;
         else cout << "$\\pm$ " <<  round(statError[i][j][4],2) ;

         if(j<3) cout << " &";
      }
   cout << "\\\\ " << endl;
   }
   cout << "\\hline" << endl << "MC Total                   & ";

   for(int j=0;j<4;j++)
   {
      if(statSum[j][4]<1000.) cout << round(statSum[j][4],1) ;
     else                    cout << (int) statSum[j][4] ;
     cout << "$\\pm$ " <<  round(statSumError[j][4],2) ;
     if(j<3) cout << " &";
   }
   cout << "\\\\ \\hline" << endl;
   cout << "DATA                       & " ;

   for(int j=0;j<4;j++)
   {
       cout << (int) stat[nD][j][4];
       if(j<3) cout << " &";
   }
   cout << " \\\\ \\hline \\hline"<< endl;
   cout << "\\end{tabular} " <<endl;


//////////////////
}


