//void roo2Dfit_20GeV_con(int iVari=0,TString weight="csvweight",double R_nomal=0.0226025, double R2_nomal= 0.0665925, double k_nomal= 0.941078,
//                        double N_ttjj_nomal= 1737.29, double N_ttbb_nomal= 100.995, double N_ttb_nomal= 181.145,
// bool separatettb=true){
void roo2Dfit(){

double R_nomal=0.0226025; double R2_nomal= 0.0665925; double k_nomal= 0.941078;
double N_ttjj_nomal= 1737.29; double N_ttbb_nomal= 100.995; double N_ttb_nomal= 181.145;
bool separatettb=true;

  gSystem->Load("libRooFit") ;
  using namespace RooFit ;

  TFile* f = new TFile(Form("result.root"));

//haddjet1_bDisCSV_S5_
//haddjet2_bDisCSV_S5_
//haddjet2D_bDisCSV_S5_
//TTbb, TT1b, TTcc, TTLF
//DY_, TT_, ST_, Wj_, VV_

  TH1* x_data       = (TH1*) f->Get("haddjet1_bDisCSV_S5_data_"       );
  TH1* y_data       = (TH1*) f->Get("haddjet2_bDisCSV_S5_data_"       );
  TH2* xy_data      = (TH2*) f->Get("haddjet2D_bDisCSV_S5_data_"      );


  TH1* x_DY         = (TH1*) f->Get("haddjet1_bDisCSV_S5_DY_"         );
  TH1* y_DY         = (TH1*) f->Get("haddjet2_bDisCSV_S5_DY_"         );
  TH2* xy_DY        = (TH2*) f->Get("haddjet2D_bDisCSV_S5_DY_"        );
  TH1* x_ttbb       = (TH1*) f->Get("haddjet1_bDisCSV_S5_TTbb"       );
  TH1* y_ttbb       = (TH1*) f->Get("haddjet2_bDisCSV_S5_TTbb"       );
  TH2* xy_ttbb      = (TH2*) f->Get("haddjet2D_bDisCSV_S5_TTbb"      );
  TH1* x_ttb        = (TH1*) f->Get("haddjet1_bDisCSV_S5_TT1b"        );
  TH1* y_ttb        = (TH1*) f->Get("haddjet2_bDisCSV_S5_TT1b"        );
  TH2* xy_ttb       = (TH2*) f->Get("haddjet2D_bDisCSV_S5_TT1b"       );
  TH1* x_ttcc       = (TH1*) f->Get("haddjet1_bDisCSV_S5_TTcc"       );
  TH1* y_ttcc       = (TH1*) f->Get("haddjet2_bDisCSV_S5_TTcc"       );
  TH2* xy_ttcc      = (TH2*) f->Get("haddjet2D_bDisCSV_S5_TTcc"      );
  TH1* x_ttLF       = (TH1*) f->Get("haddjet1_bDisCSV_S5_TTLF"       );
  TH1* y_ttLF       = (TH1*) f->Get("haddjet2_bDisCSV_S5_TTLF"       );
  TH2* xy_ttLF      = (TH2*) f->Get("haddjet2D_bDisCSV_S5_TTLF"      );
  TH1* x_ttOthers   = (TH1*) f->Get("haddjet1_bDisCSV_S5_TT_"   );
  TH1* y_ttOthers   = (TH1*) f->Get("haddjet2_bDisCSV_S5_TT_"   );
  TH2* xy_ttOthers  = (TH2*) f->Get("haddjet2D_bDisCSV_S5_TT_"  );
  TH1* x_bkg        = (TH1*) f->Get("haddjet1_bDisCSV_S5_VV_"        );
  TH1* y_bkg        = (TH1*) f->Get("haddjet2_bDisCSV_S5_VV_"        );
  TH2* xy_bkg       = (TH2*) f->Get("haddjet2D_bDisCSV_S5_VV_"       );

  TH1* x_bkg2        = (TH1*) f->Get("haddjet1_bDisCSV_S5_Wj_"        );
  TH1* y_bkg2        = (TH1*) f->Get("haddjet2_bDisCSV_S5_Wj_"        );
  TH2* xy_bkg2       = (TH2*) f->Get("haddjet2D_bDisCSV_S5_Wj_"       );
  x_bkg->Add(x_bkg2);
  y_bkg->Add(y_bkg2);
  xy_bkg->Add(xy_bkg2);

  TH1* x_singleTop  = (TH1*) f->Get("haddjet1_bDisCSV_S5_ST_"  );
  TH1* y_singleTop  = (TH1*) f->Get("haddjet2_bDisCSV_S5_ST_"  );
  TH2* xy_singleTop = (TH2*) f->Get("haddjet2D_bDisCSV_S5_ST_" );

/////////
/*
  TH1* x_data1       = (TH1*) f->Get("haddjet1_bDisCSV_S5_TTLF"       );
  TH1* y_data1       = (TH1*) f->Get("haddjet2_bDisCSV_S5_TTLF"       );
  TH2* xy_data1      = (TH2*) f->Get("haddjet2D_bDisCSV_S5_TTLF"      );
 
  TH1* x_data       = (TH1*) x_data1->Clone();
  TH1* y_data       = (TH1*) y_data1->Clone();
  TH2* xy_data      = (TH2*) xy_data1->Clone();
  x_data->Add(x_ttbb);  x_data->Add(x_ttb);  x_data->Add(x_ttcc); x_data->Add(x_ttOthers);  x_data->Add(x_singleTop); x_data->Add(x_bkg);
  y_data->Add(y_ttbb);  y_data->Add(y_ttb);  y_data->Add(y_ttcc); y_data->Add(y_ttOthers);  y_data->Add(y_singleTop); y_data->Add(y_bkg);
  xy_data->Add(xy_ttbb);  xy_data->Add(xy_ttb);  xy_data->Add(xy_ttcc); xy_data->Add(xy_ttOthers); xy_data->Add(xy_singleTop); xy_data->Add(xy_bkg);
*/
//////////

  //TH1* x_QCD = (TH1*) f->Get("x_QCD_");
  //TH1* y_QCD = (TH1*) f->Get("x_QCD_");
  //TH2* xy_QCD = (TH2*) f->Get("xy_QCD_");
  //TH1* x_tth = (TH1*) f->Get("x_tth_");
  //TH1* y_tth = (TH1*) f->Get("x_tth_");
  //TH2* xy_tth = (TH2*) f->Get("xy_tth_");
/*
 // bool separatettb = true;
  if( !separatettb ) xy_ttLF->Add(xy_ttb);
  TString Vari[]={"","DYup","DYdw","ttccUp","ttccDw","singleTopUp","singleTopDw","QCDup","QCDdw"};

  if(iVari==1) { xy_DY->Scale(1.5); }
  if(iVari==2) { xy_DY->Scale(0.5); }
  if(iVari==3) { xy_ttcc->Scale(1.5); }
  if(iVari==4) { xy_ttcc->Scale(0.5); }
  if(iVari==5) { xy_singleTop->Scale(1.5); }
  if(iVari==6) { xy_singleTop->Scale(0.5); }
  if(iVari==7) { xy_QCD->Scale(1.5); }
  if(iVari==8) { xy_QCD->Scale(0.5); }
*/

  xy_ttLF->Add(xy_ttcc);
  TH2F * xy_mcbkg = new TH2F("x_mcbkg","x_mcbkg",10,0.0,1.0,10,0.0,1.0);
  TH2F * xy_databkg = new TH2F("x_databkg","x_databkg",10,0.0,1.0,10,0.0,1.0);
  xy_mcbkg->Add(xy_bkg);
  xy_mcbkg->Add(xy_ttOthers);
  // to include single top
  xy_mcbkg->Add(xy_singleTop);
  // combine data-driven backgrounds
  xy_databkg->Add(xy_DY);
//  xy_databkg->Add(xy_QCD);

  double nVisible = xy_ttbb->Integral() + xy_ttLF->Integral() + xy_ttb->Integral();
  double nTtLF = xy_ttLF->Integral();
  double nTtb = xy_ttb->Integral();
  double nTtbb = xy_ttbb->Integral();
  double rttb = nTtb/nVisible;
  double rttbb = nTtbb/nVisible;
  double nOthers = xy_ttOthers->Integral();
  double nTtbar = nVisible + nOthers;
  double nSingleTop = xy_singleTop->Integral();
  double nMCBkg = xy_mcbkg->Integral();
  double nDataBkg = xy_databkg->Integral();
  double nDY  = xy_DY->Integral();
//  double nQCD = xy_QCD->Integral();
//  double nTth = xy_tth->Integral();
  //double eR = 0.382948 (old without taula);
  double eR = 0.3888;
  double eR2 = 0.638661;
  //basic
  RooRealVar x("x","x",0,1) ;
  RooRealVar y("y","y",0,1) ;
  RooRealVar initR("R","R",0.016,0.016,0.016);
  RooRealVar initR2("initR2","initR2",0.048, 0.048, 0.048);
  RooRealVar RttbbReco("RttbbReco","RttbbReco",rttbb, rttbb, rttbb);
  RooRealVar RttbReco("RttbReco","RttbReco",rttb, rttb, rttb);

  //taking into account in fit
  //RooRealVar R("R","R",0.016,0.,1.);
  //RooRealVar effR("effR","acceptance ratio for ttbb",eR,eR,eR);
  //RooFormulaVar fsig("fsig","fraction of signal ttbb","R/effR",RooArgList(R,effR));

  //RooRealVar R2("R2","R2",0.048,0.,1.);
  //RooRealVar effR2("effR2","acceptance ratio for ttb",eR2,eR2,eR2);
  //RooFormulaVar fsig2("fsig2","fraction of signal ttb","R2/effR2",RooArgList(R2,effR2));
  //taking into account correlation with ttbb
  //RooFormulaVar fsig2("fsig2","fsig2","@0/@1*@2/@3",RooArgList(fsig, RttbbReco, initR2, effR2) );

   cout << "rttbb : " << rttbb << endl;

  //reconstruction level and later multiply by the efficiency ratio
/*  RooRealVar fsig("fsig","fsig",rttbb,0.025,0.09);
  //RooRealVar fsig2("fsig2","fsig2",rttb,0.045,0.15);
  //taking into account correlation with ttbb
  RooFormulaVar fsig2("fsig2","fsig2","@0/@1*@2",RooArgList(fsig, RttbbReco, RttbReco) );


  RooRealVar k("k","normalization factor", 1.0, 0.92, 1.14) ;
*/
  RooRealVar fsig("fsig","fsig",rttbb,0.0,1.0);
  RooFormulaVar fsig2("fsig2","fsig2","@0/@1*@2",RooArgList(fsig, RttbbReco, RttbReco) );
  RooRealVar k("k","normalization factor", 1.0, 0.9, 1.2) ;

  RooRealVar nttjj("nttjj","number of nttjj events", nVisible, nVisible, nVisible) ;
  RooFormulaVar knttjj("knttjj","number of ttjj events after fitting","k*nttjj",RooArgList(k,nttjj));
  RooRealVar nmcbkg("nmcbkg","number of mc background events", nMCBkg, nMCBkg, nMCBkg) ;
  RooFormulaVar knmcbkg("knmcbkg","number of mc background events after fitting","k*nmcbkg",RooArgList(k,nmcbkg) );

  //tth
  //RooRealVar ntth("ntth","number of mc tth events", nTth, nTth, nTth) ;

  //ttbar and single top separate
  RooRealVar nttbar("nttbar","number of ttbar events", nTtbar , nTtbar, nTtbar) ;
  RooFormulaVar kttbar("kttbar","number of ttbar events after fitting","k*nttbar",RooArgList(k,nttbar) );
  RooRealVar s("s","normalization factor", 1.0, 0.0, 2.0) ;
  RooRealVar nsingleTop("nsingleTop","number of single top events", nSingleTop , nSingleTop, nSingleTop) ;
  RooFormulaVar snsingleTop("snsingleTop","number of single top events after fitting","k*nsingleTop",RooArgList(s,nsingleTop) );

  //data-driven background
  RooRealVar ndatabkg("ndatabkg","number of data-driven events", nDataBkg , nDataBkg, nDataBkg) ;

  //histograms
  RooDataHist data("data","data set with (x,y)", RooArgList(x,y), xy_data);
  RooDataHist ttbb("ttbb","ttbb set with (x,y)", RooArgList(x,y), xy_ttbb);
  RooDataHist ttb("ttb","ttb set with (x,y)", RooArgList(x,y), xy_ttb);
  RooDataHist ttLF("ttLF","ttLF set with (x,y)", RooArgList(x,y), xy_ttLF);
  RooDataHist ttOthers("ttOthers","ttOthers set with (x,y)", RooArgList(x,y), xy_ttOthers);
  RooDataHist singleTop("singleTop","singleTop set with (x,y)", RooArgList(x,y), xy_singleTop);
  RooDataHist mcbkg("mcbkg","bkg set with (x,y)", RooArgList(x,y), xy_mcbkg);
  RooDataHist databkg("databkg","bkg set with (x,y)", RooArgList(x,y), xy_databkg);
//  RooDataHist tth("tth","tth set with (x,y)", RooArgList(x,y), xy_tth);

  //pdf
  RooHistPdf ttbbpdf("ttbbpdf","ttbbpdf", RooArgList(x,y), ttbb);
  RooHistPdf ttbpdf("ttbpdf","ttbpdf", RooArgList(x,y), ttb);
  RooHistPdf ttLFpdf("ttLFpdf","ttLFpdf", RooArgList(x,y), ttLF);
  RooHistPdf ttOtherspdf("ttOtherspdf","ttOtherspdf", RooArgList(x,y), ttOthers);
  RooHistPdf singleToppdf("singleToppdf","singleToppdf", RooArgList(x,y), singleTop);
  RooHistPdf mcbkgpdf("mcbkgpdf","mcbkgpdf", RooArgList(x,y), mcbkg);
  RooHistPdf databkgpdf("databkgpdf","databkgpdf", RooArgList(x,y), databkg);
//  RooHistPdf tthpdf("tthpdf","tthpdf", RooArgList(x,y), tth);

  if(separatettb){
    //RooAddPdf ttLFmodel("ttLF", "R*ttb+(1-R)*ttLF",RooArgList( ttbpdf, ttLFpdf), RooArgList(fttb));
    //RooAddPdf model("model", "R*sig+(1-R)*bkg",RooArgList( ttbbpdf, ttLFmodel), RooArgList(fsig));
    RooAddPdf model("model", "R*sig+Rb*ttb+(1-R-Rb)*bkg",RooArgList( ttbbpdf, ttbpdf, ttLFpdf), RooArgList(fsig,fsig2));
    RooAddPdf model2("model2","k*nttjj*(R*sig+(1-R)*bkg)+k*nmcbkg*bkgpdf",RooArgList( model, mcbkgpdf), RooArgList(knttjj, knmcbkg) );
    RooAddPdf model3("model3","k*nttjj*(R*sig+(1-R)*bkg)+k*nmcbkg*bkgpdf+ndatabkg*databkgpdf",RooArgList( model, mcbkgpdf, databkgpdf), RooArgList(knttjj, knmcbkg, ndatabkg) ) ;
    //tth
    //RooAddPdf modeltth("modeltth","k*nttjj*(R*sig+(1-R)*bkg)+k*nmcbkg*bkgpdf+ndatabkg*databkgpdf+ntth*tthpdf",RooArgList( model, mcbkgpdf, databkgpdf,tthpdf), RooArgList(knttjj, knmcbkg, ndatabkg,ntth) ) ;
    //separate single top
    //RooAddPdf model4("model4","k*nttjj*(R*sig+(1-R)*bkg)+k*nmcbkg*bkgpdf+s*nsingeTop*singleToppdf+ndatabkg*databkgpdf",RooArgList( model, mcbkgpdf, singleToppdf, databkgpdf), RooArgList(knttjj, knmcbkg, snsingleTop, ndatabkg) ) ;

    model3.fitTo(data);
    //modeltth.fitTo(data);
  }else{
    RooAddPdf model("model", "R*sig+(1-R)*bkg",RooArgList( ttbbpdf, ttLFpdf), RooArgList(fsig));
    RooAddPdf model2("model2","k*nttjj*(R*sig+(1-R)*bkg)+k*nmcbkg*bkgpdf",RooArgList( model, mcbkgpdf), RooArgList(knttjj, knmcbkg) );
    RooAddPdf model3("model3","k*nttjj*(R*sig+(1-R)*bkg)+k*nmcbkg*bkgpdf+ndatabkg*databkgpdf",RooArgList( model, mcbkgpdf, databkgpdf), RooArgList(knttjj, knmcbkg, ndatabkg) ) ;
//    model3.fitTo(data);
  }

  double recoR = fsig.getVal();
  double recoRerror = fsig.getError();
  double genR = recoR*eR;
  double genRerror = recoR*eR*recoRerror/recoR;
  double kVal = k.getVal();
  double kValerror = k.getError();

  double recoR2 = fsig2.getVal();
  double recoRerror2 = 0;//fsig2.getError();
  double genR2 = recoR2*eR2;
  double genRerror2 = 0;//recoR2*eR2*recoRerror2/recoR2;

  // genR= efficiency ratio(ttjj/ttbb) * recoR
  cout << "FINAL  " << endl;
//  cout << "FINAL : " << weight << Vari[iVari] << " RESULT" << endl;
  cout << "FINAL : Rreco= " << recoR <<  " +- " << recoRerror << endl;
  cout << "FINAL : R= "     << genR <<  " +- "  << genRerror << " (stat. "<< (genRerror/genR*100) << " %)"<< endl;

  if(fabs(genR-R_nomal)/R_nomal*100>0.001) cout << "FINAL : sys = "  << fabs(genR-R_nomal)/R_nomal*100 << " % "<< endl;
  cout << "FINAL : k= "     << kVal <<  " +- "  << kValerror << endl;
  if(fabs(kVal-k_nomal)/k_nomal*100>0.001) cout << "FINAL : sys = "  << fabs(kVal-k_nomal)/k_nomal*100 << " % "<< endl;

  cout << "FINAL : R2reco= " << recoR2 << endl;
  cout << "FINAL : R2= "     << genR2 <<  endl;//" (stat. "<< (genRerror2/genR2*100) << " %)"<< endl;

  if(fabs(genR2-R2_nomal)/R2_nomal*100>0.001) cout << "FINAL : sys = "  << fabs(genR2-R2_nomal)/R2_nomal*100 << " % "<< endl;
//  cout << "FINAL : R/R2= "   << genR/genR2 << endl;

  double ttbbSF = (kVal*recoR)*(nVisible/nTtbb);
  double ttjjSF = (kVal)*(1-recoR-recoR*nTtb/nTtbb)*(nVisible/(nVisible-nTtbb-nTtb));

  cout << "FINAL : "  << " N_{ttjj}= " << nVisible*kVal ; if(fabs(nVisible*kVal-N_ttjj_nomal)/N_ttjj_nomal*100>0.001) cout << ", (sys= " << fabs(nVisible*kVal-N_ttjj_nomal)/N_ttjj_nomal*100 <<" %)" <<endl; else cout << endl;
  cout << "FINAL : "  << " N_{ttbb}= " << kVal*nVisible*recoR ; if(fabs(kVal*nVisible*recoR-N_ttbb_nomal)/N_ttbb_nomal*100>0.001) cout << ", (sys= " << fabs(kVal*nVisible*recoR-N_ttbb_nomal)/N_ttbb_nomal*100 <<" %)" <<endl; else cout<< endl;
  cout << "FINAL : "  << " N_{ttb}= " << kVal*nVisible*recoR2 ; if(fabs(kVal*nVisible*recoR2-N_ttb_nomal)/N_ttb_nomal*100>0.001) cout << ", (sys= " << fabs(kVal*nVisible*recoR2-N_ttb_nomal)/N_ttb_nomal*100 <<" %)" <<endl; else cout<<endl;

// cout << "FINAL : "  << " N_{tth}= " << nTth << endl;


// ", Rttbb= " << recoR << ", Rttb= "<< recoR2 << endl;

//  RooRealVar fsig("fsig","fsig",rttbb,0.025,0.09);
//  RooRealVar fsig2("fsig2","fsig2",rttb,0.045,0.15)
//  RooAbsReal* nllF = model3.createNLL(data);
//  TH1* hh = model3.createHistogram("fsig,fsig2") ;

//  TCanvas* cRF = new TCanvas("RF", "RF", 500, 500);
//  hh->Draw("colz");

/////////////
  RooAbsReal* nll = model3.createNLL(data);
  RooPlot* RFrame = fsig.frame();
  nll.plotOn(RFrame,ShiftToZero()) ;
  TCanvas* cR = new TCanvas("R", "R", 500, 500);
  double r1=0.5;

  RFrame->SetMaximum(4.);RFrame->SetMinimum(0);
  RFrame->GetXaxis()->SetTitle("R");
  RFrame->SetTitle("");
  RFrame->Draw();

  TLine *line = new TLine(RFrame->GetXaxis()->GetXmin() ,r1,RFrame->GetXaxis()->GetXmax(),r1);
  line->SetLineColor(kRed);
  line->Draw();

  TLine *lineTbb = new TLine(rttbb,RFrame->GetMaximum(),rttbb,0);
  lineTbb->SetLineStyle(2);
  lineTbb->Draw();

//  TLine *lineTbb2 = new TLine(0.0652239,RFrame->GetMaximum(),0.0652239,0);
//  lineTbb2->SetLineStyle(3);
//  lineTbb2->Draw();

  TLegend *l1 = new TLegend(0.59,0.76,0.89,0.88);
  l1->AddEntry(lineTbb,"prefit","l");
//  l1->AddEntry(lineTbb2,"no-constraint","l");
  l1->SetTextSize(0.04);
  l1->SetFillColor(0);
  l1->SetLineColor(0);
  l1->Draw();

  cR->Print("NLL_output_R_20GeV_constraint.eps");

/*
  RooAbsReal* nll2 = model3.createNLL(data);
  RooPlot* RFrame2 = fsig2.frame();
  nll2.plotOn(RFrame2,ShiftToZero()) ;
  TCanvas* cR2 = new TCanvas("R2", "R2", 500, 500);
  double r2=0.5;

  RFrame2->SetMaximum(1.);RFrame2->SetMinimum(0);
  RFrame2->Draw();
  TLine *line = new TLine(RFrame2->GetXaxis()->GetXmin() ,r2,RFrame2->GetXaxis()->GetXmax(),r2);
  line->SetLineColor(kRed);
  line->Draw();
  cR2->Print("NLL_output_R2.eps");
 */

  RooAbsReal* nllk = model3.createNLL(data);
  RooPlot* kFrame = k.frame();
  kFrame->GetXaxis()->SetTitle("k");
  kFrame->SetTitle("");
  nllk.plotOn(kFrame,ShiftToZero()) ;
  TCanvas* ck = new TCanvas("k", "k", 500, 500);

  double k1=0.5;

  kFrame->SetMaximum(4.);kFrame->SetMinimum(0);
  kFrame->Draw();

  TLine *linek = new TLine(kFrame->GetXaxis()->GetXmin() ,k1,kFrame->GetXaxis()->GetXmax(),k1);
  linek->SetLineColor(kRed);
  linek->Draw();
  TLine *lineTbbk = new TLine(1,kFrame->GetMaximum(),1,0);
  lineTbbk->SetLineStyle(2);
  lineTbbk->Draw();

//  TLine *lineTbb2k = new TLine(1.06906,kFrame->GetMaximum(),1.06906,0);
//  lineTbb2k->SetLineStyle(3);
//  lineTbb2k->Draw();

  TLegend *l1 = new TLegend(0.59,0.76,0.89,0.88);
  l1->AddEntry(lineTbbk,"prefit","l");
//  l1->AddEntry(lineTbb2k,"no-constraint","l");
  l1->SetTextSize(0.04);
  l1->SetFillColor(0);
  l1->SetLineColor(0);
  l1->Draw();

   ck->Print("NLL_output_k_20GeV_constraint.eps");

}
