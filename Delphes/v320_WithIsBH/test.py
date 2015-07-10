
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
name1 = "v20140911_"
name3 = "_test_events_PYTHIA8_0_delphes_v320.root"
#"v20140911_ttbb_test_events_PYTHIA8_0_delphes_v320.root"

f = TFile(xrdfolder+name1+input+name3)
atree = f.Get("Delphes") 

t = Delphes(atree)

output = "result_%s.root" % input
fout = TFile(output,"RECREATE")
t.Loop()
fout.Write()

#fout.Close()

#f.Close()

