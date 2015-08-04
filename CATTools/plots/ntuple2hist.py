import sys 

from ntuple2hist_cff import *
from mcsample_cfi import * 
from monitors_cfi import *

if len(sys.argv) is 1:
  print "Please, add the name as like followings."
  print "> python  ntuple2hist.py [1,2,3, or 4] \n"
  sys.exit()

arg = sys.argv[1]
mm_mu1 = "((mm_mu1_pt>20) && (abs(mm_mu1_eta)<2.4) && (abs(mm_mu1_iso)<0.12))"
mm_mu2 = "((mm_mu2_pt>20) && (abs(mm_mu2_eta)<2.4) && (abs(mm_mu2_iso)<0.12))"
ee_el1 = "((ee_el1_pt>20) && (abs(ee_el1_eta)<2.4) && (abs(ee_el1_iso)<0.12))"
ee_el2 = "((ee_el2_pt>20) && (abs(ee_el2_eta)<2.4) && (abs(ee_el2_iso)<0.12))"
em_mu1 = "((em_mu1_pt>20) && (abs(em_mu1_eta)<2.4) && (abs(em_mu1_iso)<0.12))"
em_el2 = "((em_el2_pt>20) && (abs(em_el2_eta)<2.4) && (abs(em_el2_iso)<0.12))"

mm_lep = "(" + mm_mu1 + " && "+mm_mu2 + " && (mm_zmass>20) && Nmu==2 && Nel==0)"
ee_lep = "(" + ee_el1 + " && "+ee_el2 + " && (ee_zmass>20) && Nel==2 && Nmu==0)"
em_lep = "(" + em_mu1 + " && "+em_el2 + " && (em_zmass>20) && Nmu==1 && Nel==1)"

mm_zmass = "( abs(91.2-mm_zmass)>15 )"
ee_zmass = "( abs(91.2-ee_zmass)>15 )"
em_zmass = "(1)"# "( abs(91.2-em_zmass)>15 )"

mon = []
for i,ii in enumerate(monitors):
  #print monitors[ii]
  mon+=monitors[ii]

#monitors["jetMon1" ]+monitors["jetMon2" ]+monitors["jetMon3" ]+monitors["basicMon"]
mon1=[]
for mon11 in monitors.keys():
  if mon11 == ("Mon" + arg) :
    mon1+=monitors["Mon" + arg ]

mon2=[]
for mon22 in monitors2d.keys():
  if mon22 == ("Mon" + arg) :
    mon2+=monitors2d["Mon" + arg ]

json = {
"mcsamples" : mcsamples,
"monitors" : mon1,
"monitors2" : mon2,
#"monitors" : monitors["basicMon" ],
#"monitors" : monitors["jetMon3" ],
#"monitors" : mon,
"cuts" : [
   "1",
#   "(isMM ==1 || isEE==1 || isEM==1)",
#   "((mm_zmass>20 && isMM==1) || (ee_zmass>20 && isEE==1)||(em_zmass>20 && isEM==1))",
   "(" + mm_lep + " || " + ee_lep + " || " + em_lep + ") ",
   "(" + mAND(mm_lep,mm_zmass) + " || " + mAND(ee_lep,ee_zmass) + " || " + mAND(em_lep,em_zmass) + ") ",
   "(met>40 || !(" + mm_lep + " || " + ee_lep + ")) ",
   "nJet>=4 ",
   "nBJetM>=2", 
   "nBJetT>=2", 
],
"output" : "hist_mon" + arg + ".root"
}

makehist(json)
#makehist2(json)
