from ROOT import *
import sys

#if len(sys.argv) is 1:
#  print "Please, add the name as like followings."
#  print "> python  test.py [name] \n"
#  sys.exit()

#input = sys.argv[1]

gROOT.ProcessLine(".L FlatTree.h+");
gROOT.ProcessLine(".L Lepton.h+");
gROOT.ProcessLine(".L Jet.h+");
gROOT.ProcessLine(".L CATNtuple.C+");

#f = TFile("ntuple.root")
#f = TFile("../mcsamples/ntuple_ttjets_madgraph_pythia8.root")
f = TFile("../ntuple_ttjets_madgraph_pythia8.root")
atree = f.Get("ntuple/event")

t = CATNtuple(atree)

output = "result_ttbar.root"
fout = TFile(output,"RECREATE")
t.Loop()
fout.Write()
