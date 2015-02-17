void run( char *str){
//void run(){

    //gROOT->ProcessLine(".L TtFullLepKinSolver.C+g");
    gROOT->ProcessLine(".L FlatTree.h+g");
    gROOT->ProcessLine(".L Lepton.h+g");
    gROOT->ProcessLine(".L Jet.h+g");
//    gROOT->ProcessLine(".L CSVWeight.h+g");
    gROOT->ProcessLine(".L CATNtuple.C+g");
    //TFile f(Form("../data/events_PYTHIA8_v20140813_%s.root",str));
    TFile f(Form("file:/cms/home/youngjo/CATools/nt_tag710_phy14_ttbar_2025_aod/ntuple/ntuple_%s.root",str));
    TTree *atree = dynamic_cast<TTree *>(f.Get( Form("ntuple/event") ));

    if (atree != 0)
    {
        CATNtuple t(atree);
 
        //TFile fout(Form("result_%s.root", str), "RECREATE");
        TFile fout(Form("file:/cms/home/youngjo/CATools/nt_tag710_phy14_ttbar_2025_aod/ntuple/mini/result_%s.root",str), "RECREATE");
        
        t.Loop("MuMu");
        t.Loop("ElEl");
        t.Loop("MuEl");

        fout.Write();
        fout.Close();
    }
    cout << "finished"<< endl;
    f.Close();
}
