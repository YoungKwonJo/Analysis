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
ii=int(arg)
if ii>len(monitors)+2 : sys.exit()

mon1=[]
if ii<len(monitors) :
  mon1 = [monitors[ii]]
  #print monitors[ii]

#print str(mon1)
#sys.exit()

mon2=[]
iii = ii-len(monitors)+1
for mon22 in monitors2d.keys():
  if mon22 == ("Mon"+str(iii)) :
    mon2+=monitors2d["Mon" +str(iii)]

#mceventweight="puWeight"
mceventweight="1"

jsonMM = {
"mcsamples" : mcsamples,
"mceventweight": mceventweight,
"datasamples" : datasamples,
"monitors" : mon1,
#"monitors" : monitors["Mon1"],
"monitors2" : mon2,
#"monitors2" : [],
"cuts" : mm_cuts, 
"cutsQCD" : mm_cutsQCD, 
"output" : "hist_mon" + arg +mm_cuts["channel"]+ ".root"
}

makehist(jsonMM)
#makehist2(json)

jsonEE = {
"mcsamples" : mcsamples,
"mceventweight": mceventweight,
"datasamples" : datasamples,
"monitors" : mon1,
#"monitors" : monitors["Mon1"],
"monitors2" : mon2,
#"monitors2" : [],
"cuts" : ee_cuts,
"cutsQCD" : ee_cutsQCD, 
"output" : "hist_mon" + arg +ee_cuts["channel"]+ ".root"
}
makehist(jsonEE)

jsonEM = {
"mcsamples" : mcsamples,
"mceventweight": mceventweight,
"datasamples" : datasamples,
"monitors" : mon1,
#"monitors" : monitors["Mon1"],
"monitors2" : mon2,
#"monitors2" : [],
"cuts" : em_cuts,
"cutsQCD" : em_cutsQCD, 
"output" : "hist_mon" + arg +em_cuts["channel"]+ ".root"
}
makehist(jsonEM)

