import sys 

from ntuple2hist_cff import *
from mcsample_cfi import * 
from monitors_cfi import *
from cut_cfi import *

if len(sys.argv) is 1:
  print "Please, add the name as like followings."
  print "> python  ntuple2hist.py [1,2,3, or 4] \n"
  sys.exit()

arg = sys.argv[1]

mon = []
for i,ii in enumerate(monitors):
  #print monitors[ii]
  mon+=monitors[ii]

mon1=[]
for mon11 in monitors.keys():
  if mon11 == ("Mon" + arg) :
    mon1+=monitors["Mon" + arg ]

mon2=[]
for mon22 in monitors2d.keys():
  if mon22 == ("Mon" + arg) :
    mon2+=monitors2d["Mon" + arg ]

jsonMM = {
"mcsamples" : mcsamples,
#"datasamples" : datasamples,
"monitors" : mon1,
#"monitors" : monitors["Mon1"],
"monitors2" : mon2,
#"monitors2" : [],
"cuts" : mm_cuts, 
"output" : "hist_mon" + arg +mm_cuts["channel"]+ ".root"
}

makehist(jsonMM)
#makehist2(json)

jsonEE = {
"mcsamples" : mcsamples,
#"datasamples" : datasamples,
"monitors" : mon1,
#"monitors" : monitors["Mon1"],
"monitors2" : mon2,
#"monitors2" : [],
"cuts" : ee_cuts,
"output" : "hist_mon" + arg +ee_cuts["channel"]+ ".root"
}
makehist(jsonEE)

jsonEM = {
"mcsamples" : mcsamples,
#"datasamples" : datasamples,
"monitors" : mon1,
#"monitors" : monitors["Mon1"],
"monitors2" : mon2,
#"monitors2" : [],
"cuts" : em_cuts,
"output" : "hist_mon" + arg +em_cuts["channel"]+ ".root"
}
makehist(jsonEM)

