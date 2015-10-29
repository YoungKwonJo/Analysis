from multiprocessing import Pool
from ROOT import *
import sys



#path2 = "/xrootd/store/user/youngjo/Cattools/v7-4-3/"
#cmd2 ="ls -all "
#baseloc="file:"
path = "/xrd/store/user/youngjo/Cattools/v7-4-3/"
cmd ="xrd cms-xrdr.sdfarm.kr ls "
baseloc="root://cms-xrdr.sdfarm.kr:1094//"
f_CSVwgt={}


def makeresult(sample):
#  gROOT.ProcessLine(".L FlatTree.h+");
#  gROOT.ProcessLine(".L Lepton.h+");
#  gROOT.ProcessLine(".L Jet.h+");
#  gROOT.ProcessLine(".L CATNtuple.C+");

  import copy
  name = sample["name"]
  files = sample["files"]
  isMC = name.find("Run2015")==-1 

  htot = []
  for i,ii in enumerate(files):
    #print str(baseloc+path+name+"/"+ii)
    f = TFile.Open(baseloc+path+name+"/"+ii)
    htotevent = f.Get("ntuple/hNEvent")
    htot.append(copy.deepcopy(htotevent)) 
    f.Close()
  htotevents = htot[0]
  for i,ii in enumerate(htot): 
    if i>0 : htotevents.Add(ii)

  chain = TChain("ntuple/event");
  for i in files : chain.Add(baseloc+path+name+"/"+i);
  t = CATNtuple(chain)
  #t.fillCSVhistos(f_CSVwgt_HF,f_CSVwgt_LF)
  t.fillCSVhistos(f_CSVwgt["HF"],f_CSVwgt["LF"])

  output = "result_" + name + ".root"
  fout = TFile(output,"RECREATE")
  t.Loop(isMC)
  htotevents.Write()
  fout.Write()


if __name__ == '__main__':
  gROOT.ProcessLine(".L FlatTree.h+");
  gROOT.ProcessLine(".L Lepton.h+");
  gROOT.ProcessLine(".L Jet.h+");
  gROOT.ProcessLine(".L CATNtuple.C+");

  from samples import getSamples 
  samples = getSamples(cmd,path)
  inputFileHF="data/csv_rwt_hf_IT_FlatSF_2015_07_27.root"
  inputFileLF="data/csv_rwt_lf_IT_FlatSF_2015_07_27.root"
  f_CSVwgt_HF = TFile.Open(inputFileHF)
  f_CSVwgt_LF = TFile.Open(inputFileLF)
  f_CSVwgt["HF"]=f_CSVwgt_HF
  f_CSVwgt["LF"]=f_CSVwgt_LF
 
  #samples = init()
  #import time
  #time.sleep(4)

  pool = Pool(processes=4)      
  #pool.apply_async(f, samples[0])    
  pool.map(makeresult, samples)    

