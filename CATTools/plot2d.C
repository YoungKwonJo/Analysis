#include<TCanvas.h>
#include<TH1F.h>
#include<TLegend.h>
#include<TPaveText.h>
#include <iostream>
#include <string>

//void plot2(const char *plotname, const char* xtitle, const char* ytitle, int nBins, double min, double max, bool logy, int cutN);
//TH1F* tH1FPlot(const char* mcname, const char* plotname, const char* step, const char* decay, int nBins, double min, double max, Color_t color, const char* title, const char* xtitle, const char* ytitle);
//TLegend* myTLegend(bool logy, double ymax, double xmin, double xmax );
//TPaveText* myTPaveText(double nume, double denom);
using namespace std;

void plot2d()
{
  bool log = true;
  //plot2("gentop_NJets20","# of Jet in GEN","Entries",15,0,15,log,0);
  plot2("gentop_NJets20:nJet30", "# of Jet30","# of GenJet20",10,0,10,10,0,10,-1);
//break;
  plot2("gentop_NJets20:nJet30", "# of Jet30","# of GenJet20",10,0,10,10,0,10,4);
  plot2("gentop_NJets20:nJet30", "# of Jet30","# of GenJet20",10,0,10,10,0,10,7);

  plot2("gentop_NJets30:nJet30", "# of Jet30","# of GenJet30",10,0,10,10,0,10,-1);
  plot2("gentop_NJets30:nJet30", "# of Jet30","# of GenJet30",10,0,10,10,0,10,4);
  plot2("gentop_NJets30:nJet30", "# of Jet30","# of GenJet30",10,0,10,10,0,10,7);


  plot2("gentop_NbJets30:nbJet30T", "# of bJet30 CSVT","# of GenbJet30",10,0,10,10,0,10,-1);
  plot2("gentop_NbJets30:nbJet30T", "# of bJet30 CSVT","# of GenbJet30",10,0,10,10,0,10,4);
  plot2("gentop_NbJets30:nbJet30T", "# of bJet30 CSVT","# of GenbJet30",10,0,10,10,0,10,7);

  plot2("gentop_NbJets30:nbJet30M", "# of bJet30 CSVM","# of GenbJet30",10,0,10,10,0,10,-1);
  plot2("gentop_NbJets30:nbJet30M", "# of bJet30 CSVM","# of GenbJet30",10,0,10,10,0,10,4);
  plot2("gentop_NbJets30:nbJet30M", "# of bJet30 CSVM","# of GenbJet30",10,0,10,10,0,10,7);

  plot2("gentop_NbJets30:nbJet30L", "# of bJet30 CSVL","# of GenbJet30",10,0,10,10,0,10,-1);
  plot2("gentop_NbJets30:nbJet30L", "# of bJet30 CSVL","# of GenbJet30",10,0,10,10,0,10,4);
  plot2("gentop_NbJets30:nbJet30L", "# of bJet30 CSVL","# of GenbJet30",10,0,10,10,0,10,7);


  plot2("gentop_NbJets20:nbJet30T", "# of bJet30 CSVT","# of GenbJet20",10,0,10,10,0,10,-1);
  plot2("gentop_NbJets20:nbJet30T", "# of bJet30 CSVT","# of GenbJet20",10,0,10,10,0,10,4);
  plot2("gentop_NbJets20:nbJet30T", "# of bJet30 CSVT","# of GenbJet20",10,0,10,10,0,10,7);

  plot2("gentop_NbJets20:nbJet30M", "# of bJet30 CSVM","# of GenbJet20",10,0,10,10,0,10,-1);
  plot2("gentop_NbJets20:nbJet30M", "# of bJet30 CSVM","# of GenbJet20",10,0,10,10,0,10,4);
  plot2("gentop_NbJets20:nbJet30M", "# of bJet30 CSVM","# of GenbJet20",10,0,10,10,0,10,7);

  plot2("gentop_NbJets20:nbJet30L", "# of bJet30 CSVL","# of GenbJet20",10,0,10,10,0,10,-1);
  plot2("gentop_NbJets20:nbJet30L", "# of bJet30 CSVL","# of GenbJet20",10,0,10,10,0,10,4);
  plot2("gentop_NbJets20:nbJet30L", "# of bJet30 CSVL","# of GenbJet20",10,0,10,10,0,10,7);


/*
  //break;
  //S0
  plot2("lep1_pt","p_T of leading lepton","Entries",40,0,200,log,0);
  //break;
  plot2("lep2_pt","p_T of second leading lepton","Entries",40,0,200,log,0);
  plot2("lep1_eta","#eta of leading lepton","Entries",20,-2.5,2.5,log,0);
  plot2("lep2_eta","#eta of second leading lepton","Entries",20,-2.5,2.5,log,0);
  plot2("lep1_relIso","Iso40_{rel} of leading lepton","Entries",50,0,5,log,0);
  plot2("lep2_relIso","Iso40_{rel} of second leading lepton","Entries",50,0,5,log,0);
 
  //S1
  plot2("ZMass","invariant mass of dilepton","Entries",40,0,200,log,1);
  plot2("lep1_pt","p_T of leading lepton","Entries",40,0,200,log,1);
  plot2("lep2_pt","p_T of second leading lepton","Entries",40,0,200,log,1);
  plot2("lep1_eta","#eta of leading lepton","Entries",20,-2.5,2.5,log,1);
  plot2("lep2_eta","#eta of second leading lepton","Entries",20,-2.5,2.5,log,1);

  //S2
  plot2("ZMass","invariant mass of dilepton","Entries",40,0,200,log,2);
  plot2("MET","MET","Entries",30,0,150,log,2);

  //S3
  plot2("MET","MET","Entries",30,0,150,log,3);
  plot2("nJet30","# of Jet30","Entries",10,0,10,log,3);

  //S4
  plot2("nJet30","# of Jet30","Entries",10,0,10,log,4);
  plot2("nbJet30T","# of bTag CSVT","Entries",5,0,5,log,4);
  plot2("nbJet30M","# of bTag CSVM","Entries",7,0,7,log,4);
  plot2("nbJet30L","# of bTag CSVL","Entries",7,0,7,log,4);

  plot2("jet1_pt","p_T of 1st jet","Entries",40,0,200,log,4);
  plot2("jet1_eta","#eta of 1st jet","Entries",10,-2.5,2.5,log,4);
  plot2("jet1_phi","#phi of 1st jet","Entries",14,-3.5,3.5,log,4);
  plot2("jet1_bTag","CSV of 1st jet","Entries",10,0,10,log,4);

  plot2("jet2_pt","p_T of 2nd jet","Entries",40,0,200,log,4);
  plot2("jet2_eta","#eta of 2nd jet","Entries",10,-2.5,2.5,log,4);
  plot2("jet2_phi","#phi of 2nd jet","Entries",14,-3.5,3.5,log,4);
  plot2("jet2_bTag","CSV of 2nd jet","Entries",10,0,10,log,4);

  plot2("jet3_pt","p_T of 3rd jet","Entries",50,0,200,log,4);
  plot2("jet3_eta","#eta of 3rd jet","Entries",10,-2.5,2.5,log,4);
  plot2("jet3_phi","#phi of 3rd jet","Entries",14,-3.2,3.5,log,4);
  plot2("jet3_bTag","CSV of 3rd jet","Entries",10,0,1,log,4);

  plot2("jet4_pt","p_T of 4th jet","Entries",50,0,200,log,4);
  plot2("jet4_eta","#eta of 4th jet","Entries",25,-2.5,2.5,log,4);
  plot2("jet4_phi","#phi of 4th jet","Entries",14,-3.5,3.5,log,4);
  plot2("jet4_bTag","CSV of 4th jet","Entries",10,0,1,log,4);

  //S51
  plot2("jet1_bTag","CSV of 1st jet","Entries",10,0,1,log,5);
  plot2("jet2_bTag","CSV of 2nd jet","Entries",10,0,1,log,5);
  plot2("jet3_bTag","CSV of 3rd jet","Entries",10,0,1,log,5);
  plot2("jet4_bTag","CSV of 4th jet","Entries",10,0,1,log,5);

   //S52
  plot2("jet1_bTag","CSV of 1st jet","Entries",10,0,1,log,6);
  plot2("jet2_bTag","CSV of 2nd jet","Entries",10,0,1,log,6);
  plot2("jet3_bTag","CSV of 3rd jet","Entries",10,0,1,log,6);
  plot2("jet4_bTag","CSV of 4th jet","Entries",10,0,1,log,6);

  //S53
  plot2("jet1_bTag","CSV of 1st jet","Entries",10,0,1,log,7);
  plot2("jet2_bTag","CSV of 2nd jet","Entries",10,0,1,log,7);
  plot2("jet3_bTag","CSV of 3rd jet","Entries",10,0,1,log,7);
  plot2("jet4_bTag","CSV of 4th jet","Entries",10,0,1,log,7);
*/


}
void plot2(const char *plotname, const char* xtitle, const char* ytitle, int nBins, double min, double max, int nBinsy, double ymin, double ymax, int cutN) 
{
  //char *plotname = "gentop_NJets20", *xtitle = "# of Jet in GEN", *ytitle = "Entries"; int nBins = 15; double min =0, max=15; bool logy = true;
  //char *plotname = "jet3_bTag", *xtitle = "CSV of 3rd jet", *ytitle = "Entries"; int nBins = 10; double min =0, max=10; bool logy = true;
  //char *plotname = "nJet30", *xtitle = "# of Jet30 ", *ytitle = "Entries"; int nBins = 10; double min =0, max=10; bool logy = true;
  //char *plotname = "nbJet30T", *xtitle = "# of bTag CSVT ", *ytitle = "Entries"; int nBins = 5; double min =0, max=5; bool logy = true;
  //char *plotname = "MET", *xtitle = "MET ", *ytitle = "Entries"; int nBins = 30; double min =0, max=150; bool logy = true;
  //char *plotname = "ZMass", *xtitle = "dilepton invariant mass ", *ytitle = "Entries"; int nBins = 50; double min =0, max=200; bool logy = true;
  //char *plotname = "lep1_pt", *xtitle = "p_T of leading lepton ", *ytitle = "Entries"; int nBins = 50; double min =0, max=200; bool logy = true;
  //char *plotname = "lep2_pt", *xtitle = "p_T of second leading lepton ", *ytitle = "Entries"; int nBins = 50; double min =0, max=200; bool logy = true;
  //char *plotname = "lep2_eta", *xtitle = "#eta of second leading lepton ", *ytitle = "Entries"; int nBins = 50; double min =-2.5, max=2.5; bool logy = true;

///////////////////////
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

//////////////////////////////////////
  gStyle->SetOptStat(0); //remove statistics box
  gROOT->ProcessLine(".L ./tdrstyle.C");
  defaultStyle();
  gStyle->SetCanvasDefH(610);
  gStyle->SetCanvasDefW(900);

  //File f("result_9.root"); 
  //TTree *atree = dynamic_cast<TTree *>(f.Get( Form("ntupleMuMu") ));  

  TChain * chain = new TChain("ntupleMuMu");
  for(int i=0;i<10;i++) chain->Add(Form("../mini/result_%d.root",i));
  TChain * chain2 = new TChain("ntupleElEl");
  for(int i=0;i<10;i++) chain2->Add(Form("../mini/result_%d.root",i));
  TChain * chain3 = new TChain("ntupleMuEl");
  for(int i=0;i<10;i++) chain3->Add(Form("../mini/result_%d.root",i));

  TTree * atree = chain;
  TTree * atree2 = chain2;
  TTree * atree3 = chain3;

  TCut visible = "(gentop_NJets20>=4)&&(gentop_NbJets20>=2)&&(gentop_lep1_pt>20)&&(abs(gentop_lep1_eta)<2.4)&&(gentop_lep2_pt>20)&&(abs(gentop_lep2_eta)<2.4)";
  TCut ttbb = visible && "gentop_NbJets20>=4";
  TCut ttbj = visible && "gentop_NbJets20>=3 && !(gentop_NbJets20>=4)";
  TCut ttcc = visible && "gentop_NcJets20>=2 && !(gentop_NbJets20>=3)";
  TCut ttLF = visible && !ttbb && !ttbj && !ttcc;
  TCut ttOth = !visible;

  const char* mcsample[] = {"t#bar{t}b#bar{b}","t#bar{t}bj",
    "t#bar{t}c#bar{c}", "t#bar{t}LF","t#bar{t} other", "t#bar{t}(all)"
  };
  const char* mcname[] = {"ttbb","ttbj",
    "ttcc", "ttLF","ttother", "ttbarall"
  };
  const Color_t color[] = {kRed,kBlue,kGreen,kViolet,kOrange};
  const char* decay[] = {"MuMu","ElEl","MuEl","LL"};

  TH2F *h1[6][4], *h2[6][4];
  TProfile *tpf[6][4], *tpf2[6][4];
  TCut sigcut[5] = {ttbb, ttbj,ttcc,ttLF,ttOth};
  double entries[6][4], ymax[4];
  std::string plotname_ = plotname;
  std::string prn_ (":");
  std::string afn_ ("_");
  
  char* plotname2 =replace( plotname_, prn_, afn_).c_str();
  for(int j=0;j<4;j++)for(int i=0;i<6;i++)
  {

      h1[i][j] = tH2FPlot(mcname[i],plotname2,step,decay[j],nBins,min,max,nBinsy,ymin,ymax,plotname2,xtitle,ytitle);
  }
  cout << "finished to define the histograms." << endl;

  //break;
  for(int j=0;j<3;j++)
  {
     for(int i=0;i<5;i++)
     {
         if(j==0) chain->Project(Form("h_%s_%s_%s_MuMu",mcname[i],plotname2,step),plotname,sigcut[i]+stepcut);
         if(j==1) chain2->Project(Form("h_%s_%s_%s_ElEl",mcname[i],plotname2,step),plotname,sigcut[i]+stepcut);
         if(j==2) chain3->Project(Form("h_%s_%s_%s_MuEl",mcname[i],plotname2,step),plotname,sigcut[i]+stepcut_em);
     
         //h1[i][j]->AddBinContent(nBins, h1[i][j]->GetBinContent(nBins+1));
         //h1[i][j]->Sumw2(); 
         h1[i][3]->Add(h1[i][j]);
         h1[5][j]->Add(h1[i][j]);
         h1[5][3]->Add(h1[i][j]);
     }
     cout << "finished for "<< decay[j] << endl;
  }
  cout << "finished to make histograms from tree." << endl;
  //break;
  /*for(int j=0;j<4;j++)for(int i=0;i<5;i++)
  {
      h1[i][j]->Sumw2(); 
      //entries[i][j]=h1[i][j]->Integral();
      //if(i==0)                                ymax[j]=h1[i][j]->GetMaximum();
      //else if(ymax[j]<h1[i][j]->GetMaximum()) ymax[j]=h1[i][j]->GetMaximum();
  }*/

  /*cout << "starting to calculate the ratio of ttbb/ttjj " << endl;
  double denom[4], nume[4];
  for(int j=0;j<4;j++) 
  {
     denom[j] = entries[0][j]+entries[1][j]+entries[2][j]+entries[3][j];
     nume[j]  = entries[0][j];
  }*/

  cout << "openning a canvas" << endl;
  TCanvas *c1[4], *c2[4]; 
  {
     //TLegend* leg[4];
     //TPaveText* pt[4];
     for(int j=0;j<4;j++)
     {
        c1[j] = new TCanvas(Form("c1%d",j),Form("c1%d",j),1200,900);
        c1[j]->Divide(3,2);
        c2[j] = new TCanvas(Form("c2%d",j),Form("c2%d",j),1200,900);
        c2[j]->Divide(3,2);
 
        for(int i=0;i<6;i++)
        {
           c1[j]->cd(i+1);
           h1[i][j]->Draw("colz");
           tpf[i][j] = h1[i][j]->ProfileX();
           tpf[i][j]->Draw("same");

           c2[j]->cd(i+1);
           h2[i][j]=(TH2F*) exchange(h1[i][j]);
           tpf2[i][j] = h2[i][j]->ProfileX();
           tpf2[i][j]->SetLineColor(kGray);
           h2[i][j]->Draw("colz");
           tpf2[i][j]->Draw("same");
           //pt[j] = myTPaveText(mcname[i]);
           //pt[j]->Draw();
        }
        c1[j]->Print(Form("plots/TCanvas_%s_%s_%s.eps",plotname2,step,decay[j]));
        c2[j]->Print(Form("plots/TCanvas_%s_%s_%s_IN.eps",plotname2,step,decay[j]));
     }
  }
}
TH2F* exchange(TH2F* h2)
{
  TH2F *h1 = new TH2F(Form("h2%s",h2->GetName()),h2->GetTitle(),
                        h2->GetNbinsY(), h2->GetYaxis()->GetXmin(),h2->GetYaxis()->GetXmax(),
                        h2->GetNbinsX(), h2->GetXaxis()->GetXmin(),h2->GetXaxis()->GetXmax());
  h1->GetYaxis()->SetTitle(h2->GetXaxis()->GetTitle());
  h1->GetXaxis()->SetTitle(h2->GetYaxis()->GetTitle());
  for(int i=0;i<h1->GetNbinsY();i++)
  for(int j=0;j<h1->GetNbinsX();j++)
  {
     h1->SetBinContent(i+1,j+1,h2->GetBinContent(j+1,i+1));  
  }
  return h1;

}

TH2F* tH2FPlot(const char* mcname, const char* plotname, const char* step, const char* decay, int nBins, double min, double max, int nBinsy, double ymin, double ymax, const char* title, const char* xtitle, const char* ytitle)
{
      TH2F *h1 = new TH2F(Form("h_%s_%s_%s_%s",mcname,plotname,step,decay),Form("%s %s %s %s",title, step, decay, mcname),nBins,min,max, nBinsy, ymin, ymax);
    //  chain->Project(Form("h_%s_%s_%s",mcname[i],plotname,step),plotname,cut[i]+stepcut);
    //  h1[i]->AddBinContent(nBins, h1[i]->GetBinContent(nBins+1));
    //  h1->SetLineColor(color);      
      h1->GetXaxis()->SetTitle(xtitle);
      h1->GetYaxis()->SetTitle(ytitle);
      //h1->Sumw2();
      return h1;
}
string replace(string word, string target, string replacement){
    int len, loop=0;
    string nword="", let;
    len=word.length();
    len--;
    while(loop<=len){
        let=word.substr(loop, 1);
        if(let==target){
            nword=nword+replacement;
        }else{
            nword=nword+let;
        }
        loop++;
    }
    return nword;

}

TH1F* tH1FPlot(const char* mcname, const char* plotname, const char* step, const char* decay, int nBins, double min, double max, Color_t color, const char* title, const char* xtitle, const char* ytitle)
{
      TH1F *h1 = new TH1F(Form("h_%s_%s_%s_%s",mcname,plotname,step,decay),Form("%s %s %s",title, step, decay),nBins,min,max);
    //  chain->Project(Form("h_%s_%s_%s",mcname[i],plotname,step),plotname,cut[i]+stepcut);
    //  h1[i]->AddBinContent(nBins, h1[i]->GetBinContent(nBins+1));
      h1->SetLineColor(color);      
      h1->GetXaxis()->SetTitle(xtitle);
      h1->GetYaxis()->SetTitle(ytitle);
      //h1->Sumw2();
      return h1;
}
TLegend* myTLegend(bool logy, double ymax, double xmin, double xmax )
{
  double weighty=1.; if(logy) weighty=0.007;
//  double xmax = h1[4]->GetXaxis()->GetXmax();
//  double ymax = h1[4]->GetMaximum();

  double legxmin=(xmax-xmin)*0.450, legxmax=(xmax-xmin)*0.99, legymin=ymax*1.01*weighty, legymax=ymax*1.15;
  if(logy) { legxmin=(xmax-xmin)*0.450, legxmax=(xmax-xmin)*.99, legymin=ymax*weighty, legymax=ymax*1.25; }

  TLegend* leg = new TLegend(legxmin,legymin, legxmax,legymax, NULL,"");
  leg->SetBorderSize(1); leg->SetTextFont(62);  leg->SetTextSize(0.04);
  leg->SetLineColor(0);  leg->SetLineStyle(1);  leg->SetLineWidth(1);  leg->SetFillColor(0);
  leg->SetFillStyle(1001);
  return leg;
}
TPaveText* myTPaveText(char* mcsample)
{
  TPaveText* pt = new TPaveText(0.18,0.75,0.18,0.87,"brNDC");
  pt->SetBorderSize(1);   pt->SetTextFont(42);
  pt->SetTextSize(0.04);  pt->SetLineColor(0);
  pt->SetLineStyle(1);    pt->SetLineWidth(1);
  pt->SetFillColor(0);    pt->SetFillStyle(1001);
  pt->SetTextAlign(12);
  //pt->AddText("CMS Preliminary");
  pt->AddText(Form("%s", mcsample));
  return pt;
}
