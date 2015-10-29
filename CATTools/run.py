from ROOT import *
import sys




##########################################
#if len(sys.argv) is 1:
#  print "Please, add the name as like followings."
#  print "> python  test.py [name] \n"
#  sys.exit()

#input = sys.argv[1]

gROOT.ProcessLine(".L FlatTree.h+");
gROOT.ProcessLine(".L Lepton.h+");
gROOT.ProcessLine(".L Jet.h+");
gROOT.ProcessLine(".L CATNtuple.C+");

from samples import getSamples 
path = "/xrd/store/user/youngjo/Cattools/v7-4-3/"
cmd ="xrd cms-xrdr.sdfarm.kr ls "
#path2 = "/xrootd/store/user/youngjo/Cattools/v7-4-3/"
#cmd2 ="ls -all "+path2
samples = getSamples(cmd,path)

inputFileHF="data/csv_rwt_hf_IT_FlatSF_2015_07_27.root"
inputFileLF="data/csv_rwt_lf_IT_FlatSF_2015_07_27.root"
f_CSVwgt_HF = TFile.Open(inputFileHF)
f_CSVwgt_LF = TFile.Open(inputFileLF)

baseloc="root://cms-xrdr.sdfarm.kr:1094//"
#baseloc="file:"

def makeresult(name,files,isMC):
  import copy
  #link = loc+"/ntuple_" + name + ".root"
  #print link
  #f = TFile.Open(link)
  #atree = f.Get("ntuple/event")
  #fornew = """
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
  #"""
  #t = CATNtuple(atree)
  t.fillCSVhistos(f_CSVwgt_HF,f_CSVwgt_LF)

  output = "result_" + name + ".root"
  fout = TFile(output,"RECREATE")
  t.Loop(isMC)
  htotevents.Write()
  #htotevents = f.Get("ntuple/hNEvent")
  #htotevents.Write()
  fout.Write()
  #f.Close()

#makeresult("TTJets_MG5",True)

for i,ii in enumerate(samples):
  makeresult(ii['name'],ii['files'], ii['name'].find("Run2015")==-1 )

