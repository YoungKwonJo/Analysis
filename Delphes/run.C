void run( char *str){

    //gROOT->ProcessLine(".L TtFullLepKinSolver.C+g");
    gROOT->ProcessLine(".L FlatTree.h+g");
    gROOT->ProcessLine(".L Lepton.h+g");
    gROOT->ProcessLine(".L mJet.h+g");
//    gROOT->ProcessLine(".L CSVWeight.h+g");
    gROOT->ProcessLine(".L Delphes.C+g");
    //TFile f(Form("../data/events_PYTHIA8_v20140813_%s.root",str));
    TFile f(Form("./events_PYTHIA8_v20140813_%s.root",str));
    TTree *atree = dynamic_cast<TTree *>(f.Get( Form("Delphes") ));

    if (atree != 0)
    {
        Delphes t(atree);
 
        TFile fout(Form("result_%s.root", str), "RECREATE");
        
        t.Loop();
        fout.Write();
        fout.Close();
    }
    f.Close();
}
