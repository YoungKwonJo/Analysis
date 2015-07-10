
from ROOT import *
import sys 

if len(sys.argv) is 1:
  print "Please, add the name as like followings."
  print "> python  test.py [name] \n"
  sys.exit()

input = sys.argv[1]

gROOT.ProcessLine(".L FlatTree.h+");
gROOT.ProcessLine(".L Delphes.C+");

f = TFile("test18.root")
atree = f.Get("Delphes") 

t = Delphes(atree)

output = "result_%s.root" % input
fout = TFile(output,"RECREATE")
t.Loop()
fout.Write()
#fout.Close()

#f.Close()

