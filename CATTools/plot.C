
void plot()
{
  bool log = true;
  //plot2("gentop_NJets20","# of Jet in GEN","Entries",15,0,15,log,0);
  //plot2("nJet30","# of Jet30","Entries",10,0,10,log,4);
  //plot2("nbJet30T","# of bTag CSVT","Entries",5,0,5,log,5);
  //plot2("MET","MET","Entries",30,0,150,log,3);
  //plot2("ZMass","invariant mass of dilepton","Entries",50,0,200,log,2);

  //S-1
  plot2("gentop_NJets20","# of Jet in GEN","Entries",15,0,15,log,-1);

 break;
  //S0
  plot2("lep1_pt","p_T of leading lepton","Entries",50,0,200,log,0);
  plot2("lep2_pt","p_T of second leading lepton","Entries",50,0,200,log,0);
  plot2("lep1_eta","#eta of leading lepton","Entries",50,-2.5,2.5,log,0);
  plot2("lep2_eta","#eta of second leading lepton","Entries",50,-2.5,2.5,log,0);
  plot2("lep1_relIso","relIso of leading lepton","Entries",50,0,200,log,0);
  plot2("lep2_relIso","relIso of second leading lepton","Entries",50,0,200,log,0);
 
  //S1
  plot2("ZMass","invariant mass of dilepton","Entries",50,0,200,log,1);
  plot2("lep1_pt","p_T of leading lepton","Entries",50,0,200,log,1);
  plot2("lep2_pt","p_T of second leading lepton","Entries",50,0,200,log,1);
  plot2("lep1_eta","#eta of leading lepton","Entries",50,-2.5,2.5,log,1);
  plot2("lep2_eta","#eta of second leading lepton","Entries",50,-2.5,2.5,log,1);

  //S2
  plot2("ZMass","invariant mass of dilepton","Entries",50,0,200,log,2);
  plot2("MET","MET","Entries",30,0,150,log,2);

  //S3
  plot2("MET","MET","Entries",30,0,150,log,3);
  plot2("nJet30","# of Jet30","Entries",10,0,10,log,3);

  //S4
  plot2("nJet30","# of Jet30","Entries",10,0,10,log,4);
  plot2("nbJet30T","# of bTag CSVT","Entries",5,0,5,log,4);
  plot2("nbJet30M","# of bTag CSVM","Entries",7,0,7,log,4);
  plot2("nbJet30L","# of bTag CSVL","Entries",7,0,7,log,4);

  plot2("jet1_pt","p_T of 1st jet","Entries",50,0,200,log,4);
  plot2("jet1_eta","#eta of 1st jet","Entries",25,-2.5,2.5,log,4);
  plot2("jet1_phi","#phi of 1st jet","Entries",25,-2.5,2.5,log,4);
  plot2("jet1_bTag","CSV of 1st jet","Entries",10,0,10,log,4);

  plot2("jet2_pt","p_T of 2nd jet","Entries",50,0,200,log,4);
  plot2("jet2_eta","#eta of 2nd jet","Entries",25,-2.5,2.5,log,4);
  plot2("jet2_phi","#phi of 2nd jet","Entries",25,-2.5,2.5,log,4);
  plot2("jet2_bTag","CSV of 2nd jet","Entries",10,0,10,log,4);

  plot2("jet3_pt","p_T of 3rd jet","Entries",50,0,200,log,4);
  plot2("jet3_eta","#eta of 3rd jet","Entries",25,-2.5,2.5,log,4);
  plot2("jet3_phi","#phi of 3rd jet","Entries",25,-2.5,2.5,log,4);
  plot2("jet3_bTag","CSV of 3rd jet","Entries",10,0,10,log,4);

  plot2("jet4_pt","p_T of 4th jet","Entries",50,0,200,log,4);
  plot2("jet4_eta","#eta of 4th jet","Entries",25,-2.5,2.5,log,4);
  plot2("jet4_phi","#phi of 4th jet","Entries",25,-2.5,2.5,log,4);
  plot2("jet4_bTag","CSV of 4th jet","Entries",10,0,10,log,4);

  //S51
  plot2("jet1_bTag","CSV of 1st jet","Entries",10,0,10,log,5);
  plot2("jet2_bTag","CSV of 2nd jet","Entries",10,0,10,log,5);
  plot2("jet3_bTag","CSV of 3rd jet","Entries",10,0,10,log,5);
  plot2("jet4_bTag","CSV of 4th jet","Entries",10,0,10,log,5);

   //S52
  plot2("jet1_bTag","CSV of 1st jet","Entries",10,0,10,log,6);
  plot2("jet2_bTag","CSV of 2nd jet","Entries",10,0,10,log,6);
  plot2("jet3_bTag","CSV of 3rd jet","Entries",10,0,10,log,6);
  plot2("jet4_bTag","CSV of 4th jet","Entries",10,0,10,log,6);

  //S53
  plot2("jet1_bTag","CSV of 1st jet","Entries",10,0,10,log,7);
  plot2("jet2_bTag","CSV of 2nd jet","Entries",10,0,10,log,7);
  plot2("jet3_bTag","CSV of 3rd jet","Entries",10,0,10,log,7);
  plot2("jet4_bTag","CSV of 4th jet","Entries",10,0,10,log,7);



}
void plot2(char *plotname, char* xtitle, char* ytitle, int nBins, double min, double max, bool logy, int cutN) 
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


  TCut stepcut = "1";  char *step = "nocut";
  if(cutN==0) { stepcut = S0;  step = "S0"; }
  if(cutN==1) { stepcut = S0+S1;  step = "S1"; }
  if(cutN==2) { stepcut = S0+S1+S2;  step = "S2"; }
  if(cutN==3) { stepcut = S0+S1+S2+S3;  step = "S3"; }
  if(cutN==4) { stepcut = S0+S1+S2+S3+S4;  step = "S4"; }
  if(cutN==5) { stepcut = S0+S1+S2+S3+S4+S51;  step = "S51"; }
  if(cutN==6) { stepcut = S0+S1+S2+S3+S4+S52;  step = "S52"; }
  if(cutN==7) { stepcut = S0+S1+S2+S3+S4+S53;  step = "S53"; }

//////////////////////////////////////
  gStyle->SetOptStat(0); //remove statistics box
  gROOT->ProcessLine(".L ./tdrstyle.C");
  defaultStyle();
  gStyle->SetCanvasDefH(610);
  gStyle->SetCanvasDefW(900);

  //File f("result_9.root"); 
  //TTree *atree = dynamic_cast<TTree *>(f.Get( Form("ntupleMuMu") ));  

  TChain * chain = new TChain("ntupleMuMu");
  chain->Add("mini_1.root");
  chain->Add("mini_2.root");
  chain->Add("mini_3.root");
  chain->Add("mini_4.root");
  chain->Add("mini_5.root");
  chain->Add("mini_6.root");
  chain->Add("mini_7.root");
  chain->Add("mini_8.root");
  chain->Add("mini_9.root");
  TTree * atree = chain;

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

  TH1F *h1[5];
  TCut cut[5] = {ttbb, ttbj,ttcc,ttLF,ttOth};
  double entries[5]; 
  for(int i=0;i<5;i++)
  {
      //h1[i] = new TH1F(Form("h_%s",mcname[i]),Form("%s of %s",plotname,mcsample[i]),nBins,min,max);
      h1[i] = new TH1F(Form("h_%s_%s_%s",mcname[i],plotname,step),Form("%s ",plotname),nBins,min,max);
      chain->Project(Form("h_%s_%s_%s",mcname[i],plotname,step),plotname,cut[i]+stepcut);
      h1[i]->AddBinContent(nBins, h1[i]->GetBinContent(nBins+1));
      h1[i]->SetLineColor(color[i]);      
      h1[i]->GetXaxis()->SetTitle(xtitle);
      h1[i]->GetYaxis()->SetTitle(ytitle);
      h1[i]->Sumw2();
      entries[i]=h1[i]->Integral();
  }
  double denom = entries[0]+entries[1]+entries[2]+entries[3];
  double nume = entries[0];

  TCanvas *c1 = new TCanvas("c1","c1",500,500);
  if(logy) c1->SetLogy();
  if(logy) h1[4]->SetMaximum( h1[4]->GetMaximum()*200 );
  else     h1[4]->SetMaximum( h1[4]->GetMaximum()*1.5 );
  h1[4]->SetMinimum(0.5);
  h1[4]->Draw();
  for(int i=0;i<5;i++)
  {
     h1[i]->Draw("same");
  }
  h1[0]->Draw("same");
  double weighty=1.; if(logy) weighty=0.007;
  double xmax = h1[4]->GetXaxis()->GetXmax();
  double ymax = h1[4]->GetMaximum();
  double legxmin=xmax*0.50, legxmax=xmax*0.97, legymin=ymax*1.01*weighty, legymax=ymax*1.15;
  if(logy) { legxmin=xmax*0.50, legxmax=xmax*1.1, legymin=ymax*weighty, legymax=ymax*1.15; }

  TLegend* leg;
  leg = new TLegend(legxmin,legymin, legxmax,legymax, NULL,"");
  leg->SetBorderSize(1); leg->SetTextFont(62);  leg->SetTextSize(0.04);
  leg->SetLineColor(0);  leg->SetLineStyle(1);  leg->SetLineWidth(1);  leg->SetFillColor(0);
  leg->SetFillStyle(1001);

  for(int i=4;i>-1;i--)
  {
    leg->AddEntry(h1[i], Form("%s : %.0f",mcsample[i],entries[i]), "l");
  }
  leg->Draw();
  TPaveText* pt = new TPaveText(0.18,0.75,0.18,0.87,"brNDC");
  pt->SetBorderSize(1);   pt->SetTextFont(42);
  pt->SetTextSize(0.04);  pt->SetLineColor(0);
  pt->SetLineStyle(1);    pt->SetLineWidth(1);
  pt->SetFillColor(0);    pt->SetFillStyle(1001);
  pt->SetTextAlign(12);
  //pt->AddText("CMS Preliminary");
  pt->AddText(Form("ttbb/ttjj = %.5f",nume/denom));
  pt->Draw();

  c1->Print(Form("plots/MuMu_%s_%s.eps",plotname,step));
}
