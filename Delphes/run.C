void run( char *str, bool isttjj=false){

    //gROOT->ProcessLine(".L TtFullLepKinSolver.C+g");
    gROOT->ProcessLine(".L FlatTree.h+g");
    gROOT->ProcessLine(".L Lepton.h+g");
    gROOT->ProcessLine(".L mJet.h+g");
//    gROOT->ProcessLine(".L CSVWeight.h+g");
    gROOT->ProcessLine(".L Delphes.C+g");
    //TFile f(Form("../data/events_PYTHIA8_v20140813_%s.root",str));
    TFile f(Form("/cms/data/xrd/store/user/youngjo/Madgraph/DATA/v20140916/v20140911_%s_events_PYTHIA8_0.root",str));
    TTree *atree = dynamic_cast<TTree *>(f.Get( Form("Delphes") ));

    if (atree != 0)
    {
        Delphes t(atree);
 
        TFile fout(Form("result_%s.root", str), "RECREATE");
        
        t.Loop(isttjj);
        fout.Write();
        fout.Close();
    }
    f.Close();
}
