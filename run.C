void run(char *str, char *sstr, double cx=1., int isZ=0,const int v,bool MC=true){
    gROOT->ProcessLine(".L Event.C+g");
    TFile f(Form("/Volumes/youngjoMac/CMS/BigSize/KrAFT_20140224/%s.root",str));
//    TFile f(Form("/afs/cern.ch/work/y/youngjo/public/For8Tev/KrAFT_20140224/%s.root",str));
    TTree *atree = dynamic_cast<TTree *>(f.Get("MuMu/event"));
    TH1F *hevents = dynamic_cast<TH1F *>(f.Get("MuMu/hEventCounter"));
    int nEvents = hevents->GetBinContent(1);
    double weight =1., lumi=19.789;
    if(MC) weight=lumi*cx/nEvents;

    if (atree != 0)
    {
        TFile fout(Form("result_%s.root",str), "RECREATE");
        Event t(atree);
        t.Loop(sstr, weight, isZ, v);
        fout.Write();
        fout.Close();
    }
    f.Close();
}
