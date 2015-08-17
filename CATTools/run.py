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

from samples_cfi import *

def makeresult(name):
  f = TFile("../ntuple_" + name + ".root")
  atree = f.Get("ntuple/event")

  t = CATNtuple(atree)

  output = "result_" + name + ".root"
  fout = TFile(output,"RECREATE")
  t.Loop()
  fout.Write()

makeresult("TTJets_MG5")

#for i,ii in enumerate(samples):
#  makeresult(ii['name'])
