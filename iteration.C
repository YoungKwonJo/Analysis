TH1F* weightMerge(const TH1F* SF1, const TH1F* SF2, const TH1F* SF3);
TH1F* weightMerge(const TH1F* SF1, const TH1F* SF2);
TH1F* weight(const TH1F* hMCsub2, const TH1F* SF);
TH1F* ratio(const TH1F* hdata2, const TH1F* hMC2, const TH1F* hMCsub2, const TH1F* ratio, const int i);
TH1F* ratio(const TH1F* hdata2, const TH1F* hMC2, const TH1F* hMCsub2, const int i);
TH1F* check(const TH1F* data);
void iteration()
{
    gROOT->SetStyle("Plain");
    gStyle->SetOptStat(0); //remove statistics box

  TFile *f = new TFile("./result.root");

  TString outDirName = "./bbb";
  gSystem->Exec("mkdir "+outDirName);

  TH1F *HFMCb[4], *HFMCnb[4], *HFdata[4];
  TH1F *LFMCHF[3][3], *LFMCLF[3][3], *LFdata[3][3];  
  TCanvas *cHF[4], *cLF[3][3];
  THStack *sHF[4], *sLF[3][3];
  for(int i=0;i<4;i++)
  {
    HFMCb[i]  = (TH1F*) f->Get(Form("hHF_CSVbF_Pt%d_MC", i));
    HFMCnb[i] = (TH1F*) f->Get(Form("hHF_CSVnbF_Pt%d_MC",i));
    HFdata[i] = (TH1F*) f->Get(Form("hHF_CSV_Pt%d_data", i));
    HFMCnb[i]->SetFillColor(kGreen);  HFMCb[i]->SetFillColor(kRed);
    HFdata[i]->GetXaxis()->SetTitle("CSV");
    HFdata[i]->GetYaxis()->SetTitle("Events");

    cHF[i] = new TCanvas(Form("cHF%d",i),"",500,500);
    HFdata[i]->Sumw2();
    HFdata[i]->SetLineColor(kBlack);
    HFdata[i]->SetMaximum(HFdata[i]->GetMaximum()*1.5);
    HFdata[i]->Draw();
    sHF[i] = new THStack();
    sHF[i]->Add(HFMCb[i]);
    sHF[i]->Add(HFMCnb[i]);
    sHF[i]->Draw("same");
    HFdata[i]->Draw("same");
    TString name = HFdata[i]->GetName();
    name.ReplaceAll("data","");
    cHF[i]->Print(Form("./%s/%s.eps",outDirName.Data(),name.Data()));
  }
  for(int i=0;i<3;i++) for(int j=0;j<3;j++)
  {
    LFMCHF[i][j] = (TH1F*) f->Get(Form("hLF_CSVHF_Pt%d_Eta%d_MC", i,j));
    LFMCLF[i][j] = (TH1F*) f->Get(Form("hLF_CSVLF_Pt%d_Eta%d_MC", i,j));
    LFdata[i][j] = (TH1F*) f->Get(Form("hLF_CSV_Pt%d_Eta%d_data", i,j));
    LFMCLF[i][j]->SetFillColor(kGreen);
    LFMCHF[i][j]->SetFillColor(kRed);
    LFdata[i][j]->GetXaxis()->SetTitle("CSV");
    LFdata[i][j]->GetYaxis()->SetTitle("Events");

    cLF[i][j] = new TCanvas(Form("cLF%d%d",i,j),"",500,500);
    LFdata[i][j]->Sumw2();
    LFdata[i][j]->SetLineColor(kBlack);
    LFdata[i][j]->SetMaximum(LFdata[i][j]->GetMaximum()*1.5);
    LFdata[i][j]->Draw();
    sLF[i][j] = new THStack();
    sLF[i][j]->Add(LFMCHF[i][j]);
    sLF[i][j]->Add(LFMCLF[i][j]);
    sLF[i][j]->Draw("same");
    LFdata[i][j]->Draw("same");
    TString name = LFdata[i][j]->GetName();
    name.ReplaceAll("data","");
    cLF[i][j]->Print(Form("./%s/%s.eps",outDirName.Data(),name.Data()));
  }

  const int ll=4;
  TH1F *LFratio[3][3][ll], *HFratio[4][ll], *LFratioM[3][ll], *HFratioM[ll];
  for(int i=0;i<2;i++)
  {
     for(int l=0;l<ll;l++)
     {
       if(l==0) HFratio[i][l]= (TH1F*) ratio(HFdata[i],HFMCb[i] , HFMCnb[i],l);
       else     HFratio[i][l]= (TH1F*) ratio(HFdata[i],HFMCb[i] , HFMCnb[i],LFratioM[i][l-1],l);
       for(int j=0;j<3;j++)
       {
          LFratio[i][j][l] = (TH1F*) ratio(LFdata[i][j],LFMCLF[i][j], LFMCHF[i][j], HFratio[i][l],l);
       }
       LFratioM[i][l]=(TH1F*) weightMerge(LFratio[i][0][l],LFratio[i][1][l],LFratio[i][2][l]);
     }
  }

  for(int l=0;l<ll;l++)
  {
     for(int i=2;i<4;i++)
     {
       if(l==0) HFratio[i][l]= (TH1F*) ratio(HFdata[i],HFMCb[i] , HFMCnb[i],l);
       else     HFratio[i][l]= (TH1F*) ratio(HFdata[i],HFMCb[i] , HFMCnb[i],LFratioM[2][l-1],l);
     }
     HFratioM[l]=(TH1F*) weightMerge(HFratio[2][l],HFratio[3][l]);
    
     for(int j=0;j<3;j++)
     {
          LFratio[2][j][l] = (TH1F*) ratio(LFdata[2][j],LFMCLF[2][j], LFMCHF[2][j], HFratioM[l],l);
     }
     LFratioM[2][l]=(TH1F*) weightMerge(LFratio[2][0][l],LFratio[2][1][l],LFratio[2][2][l]);
  }
 
  TCanvas *cLPHF[4], *cLPLF[3][3];
  TF1 *FitHF[4], *FitLF[3][3];
  TH1D *hFitHF[4], *hFitLF[3][3];
  TH1D *hFitHF2[4], *hFitLF2[3][3];

  for(int l=0;l<ll;l++)
  for(int i=0;i<4;i++)
  {
     if(l==0) { cLPHF[i] = new TCanvas(Form("cLPHF%d",i),"",500,500);}

     HFratio[i][l]->SetLineColor(l+1);
     HFratio[i][l]->GetXaxis()->SetTitle("CSV");
     HFratio[i][l]->GetYaxis()->SetTitle("SF");
     if(l==ll-1) HFratio[i][l]->SetLineWidth(3);

     HFratio[i][l]->SetMaximum(3.6); HFratio[i][l]->SetMinimum(0.001);
     if(l==0) { cLPHF[i]->cd(); HFratio[i][l]->Draw();}
     else     { cLPHF[i]->cd(); HFratio[i][l]->Draw("same");}  

     if(l==ll-1) 
     {
         FitHF[i] = new TF1(Form("fit%d",i),"pol6"); FitHF[i]->SetLineColor(kGreen); 
         HFratio[i][l]->Fit(FitHF[i]); 
         hFitHF[i] = (TH1D*) FitHF[i]->GetHistogram()->Clone(Form("%sNew",HFratio[i][l]->GetName()));
         hFitHF2[i] = (TH1D*) check2(hFitHF[i]);
         hFitHF2[i]->SetLineColor(kRed);
         hFitHF2[i]->Draw("same");

         TString name = hFitHF2[i]->GetName();
         name.ReplaceAll("New","");
         cLPHF[i]->Print(Form("./%s/fit_%s.eps",outDirName.Data(),name.Data()));
     }
  }

  for(int l=0;l<ll;l++)
  for(int i=0;i<3;i++)
  for(int j=0;j<3;j++)
  {
     if(l==0) { cLPLF[i][j] = new TCanvas(Form("cLPLF%d%d",i,j),"",500,500); }

     LFratio[i][j][l]->SetLineColor(l+1);
     LFratio[i][j][l]->GetXaxis()->SetTitle("CSV");
     LFratio[i][j][l]->GetYaxis()->SetTitle("SF");
     if(l==ll-1) LFratio[i][j][l]->SetLineWidth(3);

     LFratio[i][j][l]->SetMaximum(3.6); LFratio[i][j][l]->SetMinimum(0.001);
     if(l==0) { cLPLF[i][j]->cd(); LFratio[i][j][l]->Draw();      }
     else     { cLPLF[i][j]->cd(); LFratio[i][j][l]->Draw("same");}  

     if(l==ll-1) 
     {
         FitLF[i][j] = new TF1(Form("fit%d%d",i,j),"pol6"); FitLF[i][j]->SetLineColor(kGreen); 
         LFratio[i][j][l]->Fit(FitLF[i][j]); 
         hFitLF[i][j] = (TH1D*)  FitLF[i][j]->GetHistogram()->Clone(Form("%sNew",LFratio[i][j][l]->GetName()));
         //hFitLF[i][j] = (TH1D*)  FitLF[i][j]->GetHistogram();
         hFitLF2[i][j] = (TH1D*) check2(hFitLF[i][j]);
         hFitLF2[i][j]->SetLineColor(kRed);
         hFitLF2[i][j]->Draw("same");

         TString name = hFitLF2[i][j]->GetName();
         name.ReplaceAll("New","");
         cLPLF[i][j]->Print(Form("./%s/fit_%s.eps",outDirName.Data(),name.Data()));
     }
  }

}

///////////////////////////
TH1F* weightMerge(const TH1F* SF1, const TH1F* SF2, const TH1F* SF3)
{
   int bin = SF1->GetNbinsX();
   TH1F *hSF = (TH1F *) SF1->Clone();
   hSF->Reset();
   for(int i=0;i<bin;i++)
   {
      double val1 = SF1->GetBinContent(i+1);
      double val2 = SF2->GetBinContent(i+1);
      double val3 = SF3->GetBinContent(i+1);


      hSF->SetBinContent(i+1, (val1+val2+val3)/3);
   }
   return (TH1F*) hSF;
}
TH1F* weightMerge(const TH1F* SF1, const TH1F* SF2)
{
   int bin = SF1->GetNbinsX();
   TH1F *hSF = (TH1F *) SF1->Clone();
   hSF->Reset();
   for(int i=0;i<bin;i++)
   {
      double val1 = SF1->GetBinContent(i+1);
      double val2 = SF2->GetBinContent(i+1);
      hSF->SetBinContent(i+1, (val1+val2)/2);
   }
   return (TH1F*) hSF;
}



TH1F* weight(const TH1F* hMCsub2, const TH1F* SF)
{
   int bin = hMCsub2->GetNbinsX();
   TH1F *hMCsub = (TH1F *) hMCsub2->Clone();
   for(int i=0;i<bin;i++)
   {
      double wei = SF->GetBinContent(i+1);
      //if(wei<=0.001) continue;
      //if(wei>2) wei =2.;

      hMCsub->SetBinContent(i+1,hMCsub->GetBinContent(i+1)*wei);
   }
   return (TH1F*) hMCsub;
}

TH1F* ratio(const TH1F* hdata2, const TH1F* hMC2, const TH1F* hMCsub2, const TH1F* ratio, const int i)
{

   TH1F*hMCsub =(TH1F*) weight(hMCsub2,ratio);
   TH1F* hdata = (TH1F*) hdata2->Clone();
   TH1F* hMC = (TH1F*) hMC2->Clone();

   hdata->Add(hMCsub,-1);
   TH1F* hdata2 = check(hdata);

   TString name = hdata2->GetName();
   name.ReplaceAll("data",Form("IT%d",i));

   hdata2->Divide(hMC);   TH1F *temp = (TH1F*) hdata2->Clone(name);
   TString title = hdata2->GetTitle();
   title.ReplaceAll("data",Form("IT %d",i));
   temp->SetTitle(title);

   return (TH1F*) temp;
}
TH1F* ratio(const TH1F* hdata2, const TH1F* hMC2, const TH1F* hMCsub2, const int i)
{
   TH1F*hMCsub = (TH1F*) hMCsub2->Clone();
   TH1F* hdata = (TH1F*) hdata2->Clone();
   TH1F* hMC = (TH1F*) hMC2->Clone();

   hdata->Add(hMCsub,-1);
   TH1F* hdata2 = check(hdata);

   TString name = hdata2->GetName();
   name.ReplaceAll("data",Form("IT%d",i));

   hdata2->Divide(hMC); TH1F *temp = (TH1F*) hdata2->Clone(name);
   TString title = hdata2->GetTitle();
   title.ReplaceAll("data",Form("IT %d",i));
   temp->SetTitle(title);

   return (TH1F*) temp;
}
TH1F* check(const TH1F* data)
{
   int bin = data->GetNbinsX();
   TH1F *hdata = (TH1F *) data->Clone();
   hdata->Reset();
   for(int i=0;i<bin;i++)
   {
      double val = data->GetBinContent(i+1);
//      if(val<0) val = 0;
      hdata->SetBinContent(i+1,val);
   }
   return (TH1F*) hdata;
}
TH1D* check2(const TH1D* data)
{
   int bin = data->GetNbinsX();
   TH1D *hdata = (TH1D *) data->Clone();
   hdata->Reset();
//   int useCSVBin = data->FindBin(0.949);
//   double valT = data->GetBinContent(useCSVBin);
   for(int i=0;i<bin;i++)
   {
      double val = data->GetBinContent(i+1);
      if(val<3.5 && val >0.1) hdata->SetBinContent(i+1,val);
      else if(val>0.1)        hdata->SetBinContent(i+1,3.5);
      else                    hdata->SetBinContent(i+1,0.1);
      //if(useCSVBin-1>i) hdata->SetBinContent(i+1,valT);

   }
   return (TH1D*) hdata;
}


/*void FitPol6(const TH1F* hSF)
{
   TF1* function = new TF1("function","pol6");
   function->SetLineColor(kBlue);
   hSF->Fit(function);
   //hSF->SetMinimum(0.0);
   //hSF->SetMaximum(1.0);
   //hSF->GetXaxis()->SetTitle(xtitle);
   //hSF->GetYaxis()->SetTitle("Efficiency");
   //hSF->SetStats(0);
   TCanvas *cfit = new TCanvas("cfit","",500,500);
   hSF->Draw("AXIS");
   TH1F* hSF2 = hSF->Clone(); 
   (TVirtualFitter::GetFitter())->GetConfidenceIntervals(hSF2,0.68);
   hSF2->SetFillColor(kBlue);
   hSF2->SetFillStyle(3005);
   hSF2->SetStats(0);
   cfit->Close();

   return (TH1F*) hSF2;
}
*/


