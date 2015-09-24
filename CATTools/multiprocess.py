from multiprocessing import Pool
from ROOT import *
import sys

##############
gROOT.ProcessLine(".L FlatTree.h+");
gROOT.ProcessLine(".L Lepton.h+");
gROOT.ProcessLine(".L Jet.h+");
gROOT.ProcessLine(".L CATNtuple.C+");

loc="root://cms-xrdr.sdfarm.kr:1094///xrd/store/user/youngjo/Cattools/v741genWeightNew"
#loc="file:/cms/home/youngjo/CMSSW/CATTools/v20150911_25ns_v741/cat74/src/CATTools/CommonTools/test/ttbb/"
inputFileHF="data/csv_rwt_hf_IT_FlatSF_2015_07_27.root"
inputFileLF="data/csv_rwt_lf_IT_FlatSF_2015_07_27.root"
f_CSVwgt_HF = TFile.Open(inputFileHF)
f_CSVwgt_LF = TFile.Open(inputFileLF)


#def makeresult(name,isMC):
def makeresult(ii):
  name = ii['name']
  isMC = ii.has_key('xsec')
  link = loc+"/ntuple_" + name + ".root"
  print link
  #time.sleep(1)
  #print link
  #ccc="""
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
  #"""

##############################
##############################
from samples_cfi import *

if __name__ == '__main__':
  pool = Pool(processes=4)      
  #pool.apply_async(f, samples[0])    
  pool.map(makeresult, samples)    

