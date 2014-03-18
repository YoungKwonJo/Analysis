void run( char *str,const  char *sstr,  double cx,  int isZ,const  int v,const  char* DecayMode,  bool isMC){

    gROOT->ProcessLine(".L Lepton.h+g");
    gROOT->ProcessLine(".L Jet.h+g");
    gROOT->ProcessLine(".L CSVWeight.h+g");
    gROOT->ProcessLine(".L Event.C+g");
//    TFile f(Form("/Volumes/youngjoMac/CMS/BigSize/KrAFT_20140224/%s.root",str));
    TFile f(Form("/afs/cern.ch/work/y/youngjo/public/For8Tev/KrAFT_20140224/%s.root",str));
    TTree *atree = dynamic_cast<TTree *>(f.Get( Form("%s/event",DecayMode) ));
    TH1F *hevents = dynamic_cast<TH1F *>(f.Get( Form("%s/hEventCounter",DecayMode) ));
    int nEvents = hevents->GetBinContent(1);
    double weight =1., lumi=19789.;
    if(isMC) weight=lumi*cx/nEvents;

    if (atree != 0)
    {
        Event t(atree);
//        TDirectory* dir = fout.GetDirectory(Form("MuMu"));
//        dir->ls();    
 
        TFile fout(Form("result_%s_%s.root",DecayMode,str), "RECREATE");
        t.Loop(sstr, weight, isZ, v, DecayMode, isMC, nEvents);
        if(!strcmp(DecayMode,"MuMu") && !strcmp(str, "TTJets_FullLeptMGDecays_8TeV-madgraph-tauola"))
        {
           TDirectory* dir = fout.mkdir("ttbar2bFilter");
           const TString histNames[] ={"h_multiplicity_bQuarks", "h_multiplicity_bGenJets", "h_multiplicity_bQuarks20", "h_multiplicity_bQuarks20DILVIS", "h_multiplicity_bQuarks20DILVISTTBB", "h_multiplicity_bGenJets20", "h_multiplicity_bGenJets40", "h_multiplicity_bGenJets20DILVIS", "h_multiplicity_bGenJets20DILVISTTBB", "h_multiplicity_addbGenJets20", "h_multiplicity_addbGenJets40", "h_multiplicity_GenJets", "h_multiplicity_GenJets10", "h_multiplicity_GenJets15", "h_multiplicity_GenJets20", "h_multiplicity_GenJets25", "h_multiplicity_GenJets30", "h_multiplicity_GenJetsDIL", "h_multiplicity_GenJets10DIL", "h_multiplicity_GenJets15DIL", "h_multiplicity_GenJets20DIL", "h_multiplicity_GenJets25DIL", "h_multiplicity_GenJets30DIL", "h_multiplicity_GenJetsDILVIS", "h_multiplicity_GenJets10DILVIS", "h_multiplicity_GenJets15DILVIS", "h_multiplicity_GenJets20DILVIS", "h_multiplicity_GenJets25DILVIS", "h_multiplicity_GenJets30DILVIS", "h_multiplicity_GenJetsDILVISTTBB", "h_multiplicity_GenJets10DILVISTTBB", "h_multiplicity_GenJets15DILVISTTBB", "h_multiplicity_GenJets20DILVISTTBB", "h_multiplicity_GenJets25DILVISTTBB", "h_multiplicity_GenJets30DILVISTTBB", "h_multiplicity_GenJetsDILVISTTCC", "h_multiplicity_GenJets10DILVISTTCC", "h_multiplicity_GenJets15DILVISTTCC", "h_multiplicity_GenJets20DILVISTTCC", "h_multiplicity_GenJets25DILVISTTCC", "h_multiplicity_GenJets30DILVISTTCC", "h_nEvents",  "h_nEvents_40GeV", "h_nEvents_parton", "h_nEvents_addjets", "h_nEvents_40GeV_addjets", "h_nEvents_inclusive", "h_nEvents_parton_inclusive"};
           //const int ii = (sizeof(histNames) / sizeof(histNames[0]));

           TH1F* hh[48]; 
           for(int i=0;i<48;i++)
           {
             hh[i] = (TH1F*) f.Get(Form("ttbar2bFilter/%s",histNames[i].Data()));
             dir->Add(hh[i]);
           }
        }
        fout.Write();
        fout.Close();
    }
    f.Close();
}
