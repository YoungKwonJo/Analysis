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
        t.Loop(sstr, weight, isZ, v, DecayMode, isMC);
        fout.Write();
        fout.Close();
    }
    f.Close();
}
