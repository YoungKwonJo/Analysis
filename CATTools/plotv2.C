#include<TCanvas.h>
#include<TH1F.h>
#include<TLegend.h>
#include<TPaveText.h>

//void plot2(const char *plotname, const char* xtitle, const char* ytitle, int nBins, double min, double max, bool logy, int cutN);
//TH1F* tH1FPlot(const char* mcname, const char* plotname, const char* step, const char* decay, int nBins, double min, double max, Color_t color, const char* title, const char* xtitle, const char* ytitle);
//TLegend* myTLegend(bool logy, double ymax, double xmin, double xmax );
//TPaveText* myTPaveText(double nume, double denom);

void plotv2()
{
  bool log = true;
  //plot2("gentop_NJets20","# of Jet in GEN","Entries",15,0,15,log,0);
  //plot2("nJet30","# of Jet30","Entries",10,0,10,log,4);
  //plot2("nbJet30T","# of bTag CSVT","Entries",5,0,5,log,5);
  //plot2("MET","MET","Entries",30,0,150,log,3);
  //plot2("ZMass","invariant mass of dilepton","Entries",50,0,200,log,2);

  //S-1
  plot2("gentop_NJets20","# of Jet in GEN","Entries",15,0,15,log,-1);

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
  plot2("jet3_bTag","CSV of 3rd jet","Entries",10,0,10,log,4);

  plot2("jet4_pt","p_T of 4th jet","Entries",50,0,200,log,4);
  plot2("jet4_eta","#eta of 4th jet","Entries",25,-2.5,2.5,log,4);
  plot2("jet4_phi","#phi of 4th jet","Entries",14,-3.5,3.5,log,4);
  plot2("jet4_bTag","CSV of 4th jet","Entries",10,0,10,log,4);

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



}
void plot2(const char *plotname, const char* xtitle, const char* ytitle, int nBins, double min, double max, bool logy, int cutN) 
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
    "t#bar{t}c#bar{c}", "t#bar{t}LF","t#bar{t} other"
  };
  const char* mcname[] = {"ttbb","ttbj",
    "ttcc", "ttLF","ttother"
  };
  const Color_t color[] = {kRed,kBlue,kGreen,kViolet,kOrange};
  const char* decay[] = {"MuMu","ElEl","MuEl","LL"};

  TH1F *h1[5][4];
  TCut sigcut[5] = {ttbb, ttbj,ttcc,ttLF,ttOth};
  double entries[5][4], ymax[4]; 
  for(int j=0;j<4;j++)for(int i=0;i<5;i++)
  {

      h1[i][j] = tH1FPlot(mcname[i],plotname,step,decay[j],nBins,min,max,color[i],plotname,xtitle,ytitle);
  }
  cout << "finished to define the histograms." << endl;

  for(int j=0;j<3;j++)
  {
     for(int i=0;i<5;i++)
     {
         if(j==0) chain->Project(Form("h_%s_%s_%s_MuMu",mcname[i],plotname,step),plotname,sigcut[i]+stepcut);
         if(j==1) chain2->Project(Form("h_%s_%s_%s_ElEl",mcname[i],plotname,step),plotname,sigcut[i]+stepcut);
         if(j==2) chain3->Project(Form("h_%s_%s_%s_MuEl",mcname[i],plotname,step),plotname,sigcut[i]+stepcut_em);
     
         h1[i][j]->AddBinContent(nBins, h1[i][j]->GetBinContent(nBins+1));
         //h1[i][j]->Sumw2(); 
         h1[i][3]->Add(h1[i][j]);
     }
     cout << "finished for "<< decay[j] << endl;
  }
  cout << "finished to make histograms from tree." << endl;

  for(int j=0;j<4;j++)for(int i=0;i<5;i++)
  {
      h1[i][j]->Sumw2(); 
      entries[i][j]=h1[i][j]->Integral();
      if(i==0)                                ymax[j]=h1[i][j]->GetMaximum();
      else if(ymax[j]<h1[i][j]->GetMaximum()) ymax[j]=h1[i][j]->GetMaximum();
  }

  cout << "starting to calculate the ratio of ttbb/ttjj " << endl;
  double denom[4], nume[4];
  for(int j=0;j<4;j++) 
  {
     denom[j] = entries[0][j]+entries[1][j]+entries[2][j]+entries[3][j];
     nume[j]  = entries[0][j];
  }

  cout << "openning a canvas" << endl;
  if(cutN>-1){
     TCanvas *c1 = new TCanvas("c1","c1",1000,1000);
     c1->Divide(2,2);
     TLegend* leg[4];
     TPaveText* pt[4];
     for(int j=0;j<4;j++)
     {
        if(logy) c1->cd(j+1)->SetLogy();
        else     c1->cd(j+1);
        if(logy) h1[4][j]->SetMaximum( ymax[j]*200 );
        else     h1[4][j]->SetMaximum( ymax[j]*1.5 );
        h1[4][j]->SetMinimum(0.5);
        h1[4][j]->Draw();
        for(int i=0;i<5;i++)
        {
           h1[i][j]->Draw("same");
        }
        h1[0][j]->Draw("same");
        double ymax_ = h1[4][j]->GetMaximum();
        leg[j] = myTLegend(logy,ymax_,min,max);
     
        for(int i=4;i>-1;i--)
        {
          leg[j]->AddEntry(h1[i][j], Form("%s : %.0f",mcsample[i],entries[i][j]), "l");
        }
        leg[j]->Draw();
        pt[j] = myTPaveText(nume[j],denom[j]);
        pt[j]->Draw();
     }
     c1->Print(Form("plots/TCanvas_%s_%s.eps",plotname,step));
  }
  else 
  {
     TCanvas *c1 = new TCanvas("c1","c1",500,500);
     if(logy) c1->SetLogy();
     TLegend* leg;
     TPaveText* pt;
     if(logy) h1[4][0]->SetMaximum( ymax[0]*200 );
     else     h1[4][0]->SetMaximum( ymax[0]*1.5 );
     h1[4][0]->SetMinimum(0.5);
     h1[4][0]->Draw();
     for(int i=0;i<5;i++)
     {
        h1[i][0]->Draw("same");
     }
     h1[0][0]->Draw("same");
     double ymax_ = h1[4][0]->GetMaximum();
     leg = myTLegend(logy,ymax_,min,max);

     for(int i=4;i>-1;i--)
     {
       leg->AddEntry(h1[i][0], Form("%s : %.0f",mcsample[i],entries[i][0]), "l");
     }
     leg->Draw();
     pt = myTPaveText(nume[0],denom[0]);
     pt->Draw();
     c1->Print(Form("plots/TCanvas_%s_%s.eps",plotname,step));
  }
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
TPaveText* myTPaveText(double nume, double denom)
{
  TPaveText* pt = new TPaveText(0.18,0.75,0.18,0.87,"brNDC");
  pt->SetBorderSize(1);   pt->SetTextFont(42);
  pt->SetTextSize(0.04);  pt->SetLineColor(0);
  pt->SetLineStyle(1);    pt->SetLineWidth(1);
  pt->SetFillColor(0);    pt->SetFillStyle(1001);
  pt->SetTextAlign(12);
  //pt->AddText("CMS Preliminary");
  pt->AddText(Form("ttbb/ttjj = %.5f",nume/denom));
  return pt;
}
