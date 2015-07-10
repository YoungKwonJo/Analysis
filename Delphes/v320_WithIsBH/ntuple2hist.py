
from ROOT import *
import copy

from ntuple2hist_cff import *

import sys 
#if len(sys.argv) is 1:
#  print "Please, add the name as like followings."
#  print "> python  test.py [name] \n"
#  sys.exit()
#input = sys.argv[1]
#gROOT.ProcessLine(".L FlatTree.h+");
#gROOT.ProcessLine(".L Delphes.C+");

mcs = [

{"name":"ttbb", "selection": "1", "file":"result_ttbb.root" },
{"name":"ttjj", "selection": "1", "file":"result_ttjj.root" },
{"name":"tth",  "selection": "1", "file":"result_TTH.root"  }

]

monitors = [

 { "name":"DRgjetBH", "unit":"DR between genjet and B hadron", "var":"DR_gjet_BH",  "xbin_set":[40,0,2]       },
 { "name":"DPTgjetBH","unit":"pT_genjet - pT_BH",              "var":"DPT_gjet_BH", "xbin_set":[200,-200,200] }

]

cuts_ = [

  "1",
  "(DR_gjet_BH<100)",
  "(DR_gjet_BH<10)",
  "(DR_gjet_BH<10)"

]

cuts  = cut_maker(cuts_)
#print "cut : %s" % cuts
#sys.exit()


h = []
for i,mc in enumerate(mcs):
  f = TFile.Open(mcs[i]['file'],"read")
  tree = f.ntuple
  h= h+h_all_maker(tree,mcs[i],monitors,cuts) 
  f.Close()


output = "hist_all.root" 
fout = TFile(output,"RECREATE")
for a in h:
  a.Write()
fout.Write()
fout.Close()

