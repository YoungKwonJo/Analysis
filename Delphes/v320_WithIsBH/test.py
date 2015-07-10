
from ROOT import *
import sys 

if len(sys.argv) is 1:
  print "Please, add the name as like followings."
  print "> python  test.py [name] \n"
  sys.exit()

input = sys.argv[1]

gROOT.ProcessLine(".L FlatTree.h+");
gROOT.ProcessLine(".L Delphes.C+");
 
xrdfolder="/cms/data/xrd/store/user/youngjo/Madgraph/DATA/v20140916_delphes320/"
names = {"ttbb":["v20140911_","_test_events_PYTHIA8_0_delphes_v320"],"ttjj":["","_DecayAll_20150406_events_PYTHIA8_delphes_v320"],"TTH":["v20140911_NLO_","_cut_bq_20150331_PYTHIA8_0_delphes_v320"]}

#"v20140911_ttbb_test_events_PYTHIA8_0_delphes_v320.root"
#v20140911_NLO_TTH_cut_bq_20150331_PYTHIA8_0_delphes_v320.root
#"ttjj_DecayAll_20150406_events_PYTHIA8_delphes_v320.root"
#>>> names = {"ttbb":["aaaa","bbbbb"],"ttjj":["aaaa","bbbbb"]}
#>>> names["ttbb"]
#['aaaa', 'bbbbb']
#>>> names["ttbb"][0]
#'aaaa'
#>>> names["ttbb"][1]
#'bbbbb'

f = TFile(xrdfolder+names[input][0]+input+names[input][1]+".root")
atree = f.Get("Delphes") 

t = Delphes(atree)

output = "result_%s.root" % input
fout = TFile(output,"RECREATE")
t.Loop()
fout.Write()

#fout.Close()

#f.Close()

