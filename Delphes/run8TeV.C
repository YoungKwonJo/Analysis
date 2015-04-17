void run8TeV( char *str, char *str2, bool isttjj=false, bool pythia6){

    //gROOT->ProcessLine(".L TtFullLepKinSolver.C+g");
    gROOT->ProcessLine(".L FlatTree.h+g");
    gROOT->ProcessLine(".L Lepton.h+g");
    gROOT->ProcessLine(".L mJet.h+g");
//    gROOT->ProcessLine(".L CSVWeight.h+g");
    gROOT->ProcessLine(".L Delphes.C+g");
    //TFile f(Form("../data/events_PYTHIA8_v20140813_%s.root",str));
    TFile f(Form("/cms/data/xrd/store/user/youngjo/Madgraph/DATA/v20150416_8TeV/%s",str));
    //TFile f(Form("/cms/home/youngjo/newMadgraph/Madgraph/MG5_aMC_v2_1_2/LO_ttjj/Events/run_02/%s",str));
    TTree *atree = dynamic_cast<TTree *>(f.Get( Form("Delphes") ));

    if (atree != 0)
    {
        Delphes t(atree);
 
        TFile fout(Form("result_8TeV_%s.root", str2), "RECREATE");
        
        t.Loop(isttjj,pythia6);
        fout.Write();
        fout.Close();
    }
    f.Close();
}
