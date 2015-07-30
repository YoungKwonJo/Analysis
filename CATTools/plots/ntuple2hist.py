import sys 

from ntuple2hist_cff import *
from mcsample_cfi import * 
from monitors_cfi import *

if len(sys.argv) is 1:
  print "Please, add the name as like followings."
  print "> python  ntuple2hist.py [1,2,3, or 4] \n"
  sys.exit()

i = sys.argv[1]


json = {
"mcsamples" : mcsamples,
"monitors" : monitors["jetMon" + i ],
"cuts" : [
   "1",
#   "(isMM ==1 || isEE==1 || isEM==1)",
#   "((mm_zmass>20 && isMM==1) || (ee_zmass>20 && isEE==1)||(em_zmass>20 && isEM==1))",
#   "(met>40 || (em_zmass>20 && isEM==1))",
#   "nJet>=4",
#   "nBJetT>=2" 
],
"output" : "hist_all1.root"
}

makehist(json)
#makehist2(json)
