//original code
//https://github.com/kopfa/TTbar2b/blob/master/test/acceptanceR.C

double FrTTDIL = 0;
double FrTTDILVIS = 0;
double FrTTJJ = 0;
double FrTTBB = 0;
double FrTTB = 0;
double FrTTCC = 0;

double FrTTDILVIS_parton = 0;
double FrTTJJ_parton = 0;
double FrTTBB_parton = 0;
double total         = 0;

void acceptanceR(){
//void getFraction(const TString & path){

  TFile* f = new TFile(Form("resultTTJets_FullLeptMGDecays_8TeV-madgraph-tauola.root"));
  cout << "resultTTJets_FullLeptMGDecays_8TeV-madgraph-tauola.root" << endl;
  TH1* h_event = (TH1F*) f->Get("hStep_all_TT__nw");
  total = h_event->GetBinContent(7)/3;

  TH1* h_nGenJet = (TH1F*) f->Get("ttbar2bFilter/h_multiplicity_GenJets");
  TH1* h_nGenJetDIL = (TH1F*) f->Get("ttbar2bFilter/h_multiplicity_GenJetsDIL");
  TH1* h_nGenJetDILVIS = (TH1F*) f->Get("ttbar2bFilter/h_multiplicity_GenJetsDILVIS");
  TH1* h_nGenJet20DILVIS = (TH1F*) f->Get("ttbar2bFilter/h_multiplicity_GenJets20DILVIS");
  TH1* h_nGenJet20DILVISTTBB = (TH1F*) f->Get("ttbar2bFilter/h_multiplicity_GenJets20DILVISTTBB");
  TH1* h_nGenJet20DILVISTTCC = (TH1F*) f->Get("ttbar2bFilter/h_multiplicity_GenJets20DILVISTTCC");
  TH1* h_nEvents = (TH1F*) f->Get("ttbar2bFilter/h_nEvents");
  TH1* h_nEvents_40GeV = (TH1F*) f->Get("ttbar2bFilter/h_nEvents_40GeV");

  double nTT = h_nGenJet->GetEntries();
  double nTTDIL = h_nGenJetDIL->GetEntries();
  //double nTTDILVIS = h_nGenJetDILVIS->GetEntries();
  //double nTTBBDILVIS = h_nGenJet20DILVISTTBB->GetEntries();
  //double nTTCCDILVIS = h_nGenJet20DILVISTTCC->GetEntries();
  //double nTTJJ = nTTDILVIS - h_nGenJet20DILVIS->Integral(1,4);
  //double nTTBB = nTTBBDILVIS - h_nGenJet20DILVISTTBB->Integral(1,4);
  //double nTTCC = nTTCCDILVIS - h_nGenJet20DILVISTTCC->Integral(1,4);

  double nTTDILVIS = h_nEvents_40GeV->GetBinContent(3);
  double nTTJJ = h_nEvents_40GeV->GetBinContent(4);
  double nTTBB = h_nEvents_40GeV->GetBinContent(5);
  double nTTB = h_nEvents_40GeV->GetBinContent(7);
  double nTTCC = h_nEvents_40GeV->GetBinContent(6); 

  //double nTTDILVIS = h_nEvents->GetBinContent(3);
  //double nTTJJ = h_nEvents->GetBinContent(4);
  //double nTTBB = h_nEvents->GetBinContent(5);
  //double nTTB = h_nEvents->GetBinContent(7);
  //double nTTCC = h_nEvents->GetBinContent(6);

  cout << "nTT= " << nTT << " nTTDIL= " << nTTDIL << " nTTJJ= " << nTTJJ << " nTTBB= " << nTTBB << " " << " nTTB= " << nTTB << endl;

  double Br = 0.049382761;

  FrTTDIL = nTTDIL/nTT;
  FrTTDILVIS = nTTDILVIS/nTTDIL;
  FrTTJJ = nTTJJ/nTTDILVIS;
  FrTTBB = nTTBB/nTTJJ;
  FrTTB  = nTTB/nTTJJ;
  FrTTCC = nTTCC/nTTJJ;
 
  cout << "Ratio (nTTDIL/nTT)   = " << FrTTDIL << endl;
  cout << "Ratio (nTTDILVIS/nTTDIL)   = " << FrTTDILVIS << endl;
  cout << "Ratio (nTTJJ/nTTDILVIS)   = " << FrTTJJ << endl;
  cout << "Ratio (nTTBB/nTTJJ) = " << FrTTBB << endl;
  cout << "Ratio (nTTB/nTTJJ) = " << FrTTB << endl;

/*
}

void acceptanceR(){

  //getFraction();

  //acceptance("TTbarMcatnlo");
  //acceptance("TTbarTuneZ2");
  acceptance("TTbarFullLepMGDecays");
  //acceptance("TTbarPowheg");
  //acceptance("TTbar_matchingdown");
  //acceptance("TTbar_matchingup");
  //acceptance("TTbar_scaledown");
  //acceptance("TTbar_scaleup");


}

void acceptance(const TString & path){
  cout << path.Data() << endl;

  getFraction(path);

  TFile* f = new TFile(Form("/afs/cern.ch/work/t/tjkim/public/store/ttbb/paper/8TeV/ntuple/v3/vallot_%s.root",path.Data()));
  //TFile* f = new TFile(Form("/afs/cern.ch/work/y/youngjo/public/For8Tev/v20130622_tthUpDw/vallot_%s.root",path.Data()));
  //TFile* f = new TFile(Form("/afs/cern.ch/work/y/youngjo/public/For8Tev/v20130613_HFupdw/vallot_%s.root",path.Data()));

  TTree* t_mm = (TTree*) f->Get("MuMu/tree");
  TTree* t_ee = (TTree*) f->Get("ElEl/tree");
  TTree* t_em = (TTree*) f->Get("MuEl/tree");

  TH1* h_event_mm = (TH1F*) f->Get("MuMu/EventSummary");
  double total = h_event_mm->GetBinContent(1);
*/
   const char *ttNN[4] ={"bb","1b","cc","LF"};
   TH1* h_[4];
   for(int i=0;i<4;i++)
   {
      h_[i]= (TH1F*) f->Get(Form("hStep_all_TT%s_nw",ttNN[i]));
   }

  for(int j=1;j<6;j++)
  {
  int Step=j;
  cout << "CUT: S" << Step << endl;

  //TCut vis = "nGenJet20 >= 4 && nGenbJet20 >=2 && genLep1_pt > 20 && genLep2_pt > 20 && abs( genLep1_eta ) < 2.4 && abs( genLep2_eta ) < 2.4" ;
  //TCut ttbb = "nGenbJet20 >= 4";
  //TCut ttb = "nGenbJet20 == 3";
  //TCut ttcc = "nGencJet20 >= 2";

  //TCut vis = "nGenJet40 >= 4 && nGenbJet40 >=2 && genLep1_pt > 20 && genLep2_pt > 20 && abs( genLep1_eta ) < 2.4 && abs( genLep2_eta ) < 2.4" ;
  //TCut ttbb = "nGenbJet40 >= 4";
  //TCut ttb = "nGenbJet40 == 3";
  //TCut ttcc = "nGencJet40 >= 2";

  //TCut vis_parton = "ttbarGen.NJets20() >= 4 && ttbarGen.NbQuarks20() >=2 && ttbarGen.lepton1().pt() > 20 && ttbarGen.lepton2().pt() > 20 && abs(ttbarGen.lepton1().eta()) < 2.5 && abs(ttbarGen.lepton2().eta()) < 2.5" ;
  //TCut ttbb_parton = "ttbarGen.NbQuarks20() >= 4";

  double numTTJJ = h_[0]->GetBinContent(Step+1)+h_[1]->GetBinContent(Step+1)+h_[2]->GetBinContent(Step+1)+h_[3]->GetBinContent(Step+1);
  double preTTJJ = h_[0]->GetBinContent(2)+h_[1]->GetBinContent(2)+h_[2]->GetBinContent(2)+h_[3]->GetBinContent(2); 
  double denTTJJ = total * FrTTDIL * FrTTDILVIS * FrTTJJ;
  double acceptancePreTTJJ =preTTJJ/denTTJJ;
  double acceptancePosTTJJ =numTTJJ/preTTJJ;
  double acceptanceTTJJ =numTTJJ/denTTJJ;

  double numTTBB = h_[0]->GetBinContent(Step+1); 
  double numTTB =  h_[1]->GetBinContent(Step+1); 
  double preTTBB = h_[0]->GetBinContent(2); 
  double denTTBB = total * FrTTDIL * FrTTDILVIS * FrTTJJ * FrTTBB;
  double denTTB  = total * FrTTDIL * FrTTDILVIS * FrTTJJ * FrTTB;
  double acceptancePreTTBB = preTTBB / denTTBB; 
  double acceptancePosTTBB = numTTBB / preTTBB; 
  double acceptanceTTBB = numTTBB / denTTBB; 
  double acceptanceTTB = numTTB / denTTB; 

  double numTTCC = h_[2]->GetBinContent(Step+1); 
  double denTTCC = total * FrTTDIL * FrTTDILVIS * FrTTJJ * FrTTCC;
  double acceptanceTTCC = numTTCC / denTTCC;

  cout << "total= " << total << " den(TTJJ)= " << denTTJJ << " den(TTBB)= " << denTTBB << endl;

  double AccRatio_ttbb = acceptanceTTJJ/acceptanceTTBB;
  double AccRatio_ttb  = acceptanceTTJJ/acceptanceTTB;
  double recoR_ttbb =  numTTBB/numTTJJ;
  double recoR_ttb =  numTTB/numTTJJ;

  //cout << "Ratio (nTTDIL/nTT)   = " << FrTTDIL << endl;
  //cout << "Ratio (nTTDILVIS/nTTDIL)   = " << FrTTDILVIS << endl;
  //cout << "Ratio (nTTJJ/nTTDILVIS)   = " << FrTTJJ << endl;
  //cout << "Ratio (nTTBB/nTTJJ) = " << FrTTBB << endl;
  cout << "Ratio (in reco nTTBB/nTTJJ) = " << recoR_ttbb << " Ratio (in reco nTTB/nTTJJ) = " << recoR_ttb << endl;
  //cout << "acceptance preselection (ttjj)   = " << acceptancePreTTJJ << endl;
  //cout << "acceptance preselection (ttbb)   = " << acceptancePreTTBB << endl;
  //cout << "acceptance postselection (ttjj)   = " << acceptancePosTTJJ << "(" << numTTJJ << "/" << preTTJJ << ")" << endl;
  //cout << "acceptance postselection (ttbb)   = " << acceptancePosTTBB << "(" << numTTBB << "/" << preTTBB << ")" << endl;
  cout << "acceptance (ttjj)   = " << acceptanceTTJJ << "(" << numTTJJ << "/" << denTTJJ << ")" << endl;
  cout << "acceptance (ttbb)   = " << acceptanceTTBB << "(" << numTTBB << "/" << denTTBB << ")" << endl;
  cout << "acceptance (ttb)   = "  << acceptanceTTB  << "(" << numTTB  << "/" << denTTB  << ")" << endl;
  cout << "acceptance (ttcc)   = " << acceptanceTTCC << "(" << numTTCC << "/" << denTTCC << ")" << endl;
  cout << "Ratio (Attjj/Attbb) = " << AccRatio_ttbb << " Ratio (Attjj/Attb) = " << AccRatio_ttb << endl;
  }
}
