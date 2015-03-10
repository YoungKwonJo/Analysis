void run( char *str, bool isMC){
//void run(){

    //gROOT->ProcessLine(".L TtFullLepKinSolver.C+g");
    gROOT->ProcessLine(".L FlatTree.h+g");
    gROOT->ProcessLine(".L Lepton.h+g");
    gROOT->ProcessLine(".L Jet.h+g");
//    gROOT->ProcessLine(".L CSVWeight.h+g");
    gROOT->ProcessLine(".L CATNtuple.C+g");
    //TFile f(Form("../data/events_PYTHIA8_v20140813_%s.root",str));
    string location ="file:/cms/home/youngjo/CATools/nt_tag711/";
    string mcname = str;
    string tag = "tag711_aod";
    TFile f(Form("%s/ntuple_%s_%s.root",location.c_str(),mcname.c_str(),tag.c_str()));
    TTree *atree = dynamic_cast<TTree *>(f.Get( Form("ntuple/event") ));
 
    int aaa = mcname.find("ttbar");
    int leng = mcname.length();
    bool isSignal = ((aaa<leng) && (aaa>-1));
    cout << "isSignal : " << isSignal << ", "<< mcname <<", find: "<< mcname.find("ttbar") << " , length:"<< mcname.length()  << endl;
    //return;
    
    if (atree != 0)
    {
        CATNtuple t(atree);
 
        //TFile fout(Form("result_%s.root", str), "RECREATE");
        TFile fout(Form("%s/mini/result_%s_%s.root",location.c_str(),mcname.c_str(),tag.c_str()), "RECREATE");

        t.Loop("MuMu",isSignal,isMC);
        t.Loop("ElEl",isSignal,isMC);
        t.Loop("MuEl",isSignal,isMC);

        fout.Write();
        fout.Close();
    }
    cout << "finished"<< endl;
    f.Close();
}
