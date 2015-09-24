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

#loc="root://cms-xrdr.sdfarm.kr:1094///xrd/store/user/youngjo/Cattools/v734_v1"
loc="root://cms-xrdr.sdfarm.kr:1094///xrd/store/user/youngjo/Cattools/v741genWeightNew"
inputFileHF="data/csv_rwt_hf_IT_FlatSF_2015_07_27.root"
inputFileLF="data/csv_rwt_lf_IT_FlatSF_2015_07_27.root"
f_CSVwgt_HF = TFile.Open(inputFileHF)
f_CSVwgt_LF = TFile.Open(inputFileLF)


#loc="file:/cms/home/youngjo/CMSSW/CATTools/v20150911_25ns_v741/cat74/src/CATTools/CommonTools/test/ttbb/"
def makeresult(name,isMC):
  link = loc+"/ntuple_" + name + ".root"
  print link
  f = TFile.Open(link)
  atree = f.Get("ntuple/event")

  t = CATNtuple(atree)
  t.fillCSVhistos(f_CSVwgt_HF,f_CSVwgt_LF)

  output = "result_" + name + ".root"
  fout = TFile(output,"RECREATE")
  t.Loop(isMC)
  htotevents = f.Get("ntuple/hNEvent")
  htotevents.Write()
  fout.Write()
  f.Close()

#makeresult("TTJets_MG5",True)

for i,ii in enumerate(samples):
  makeresult(ii['name'],ii.has_key('xsec'))
