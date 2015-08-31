from ROOT import *
import copy

from ntuple2hist_cff import *
from mcsample_cfi import *
from monitors_cfi import *

#import sys 

mon = []
for i,ii in enumerate(monitors):
  #print monitors[ii]
  mon+=monitors[ii]

mon2 = []
for i,ii in enumerate(monitors2d):
  #print monitors2d[ii]
  mon2.append(monitors2d[ii])

json = {
"file": "hist_all.root",
#"file": "hist_all2.root",
"mcsamples" : mcsamples,
"datasamples" : datasamples,
#"cuts" : ["S0","S1","S2","S3","S4","S5"],
#"cuts" : ["S0","S1","S2","S3"],
#"cuts" : ["S0","S1","S2","S3","S4","S5","S6"],
"cuts" : [
"S0mm","S1mm","S2mm","S3mm","S4mm","S5mm","S6mm",
"S0ee","S1ee","S2ee","S3ee","S4ee","S5ee","S6ee",
"S0em","S1em","S2em","S3em","S4em","S5em","S6em"
   ],
#"cuts" : ["S6"],

#"monitors" : monitors["jetMon3"]
"monitors" : mon,
"monitors2" : mon2
}

#########
#TH1F
f = json['file'] #TFile.Open(json['file'],"read")
#singleplotStack(f,"MET","S0mm",json['mcsamples'],json['datasamples'])

#singleplotStack(f,"MET","S1em",json['mcsamples'],json['datasamples'])
#singleplotStack(f,"MET","S1mm",json['mcsamples'],json['datasamples'])
#singleplotStack(f,"MET","S2em",json['mcsamples'],json['datasamples'])
#singleplotStack(f,"MET","S2mm",json['mcsamples'],json['datasamples'])
#singleplotStack(f,"ZMassEM","S2em",json['mcsamples'],json['datasamples'])
#singleplotStack(f,"ZMassMM","S2mm",json['mcsamples'],json['datasamples'])
#singleplotStack(f,"MET","S4em",json['mcsamples'],json['datasamples'])
#singleplotStack(f,"MET","S4mm",json['mcsamples'],json['datasamples'])

#singleplotStack(f,"ZMassMM","S0em",json['mcsamples'],json['datasamples'])
#singleplotStack(f,"ZMassMM","S1em",json['mcsamples'],json['datasamples'])
#singleplotStack(f,"ZMassMM","S2em",json['mcsamples'],json['datasamples'])
#singleplotStack(f,"ZMassMM","S3em",json['mcsamples'],json['datasamples'])
#singleplotStack(f,"ZMassMM","S4em",json['mcsamples'],json['datasamples'])
#singleplotStack(f,"ZMassMM","S5em",json['mcsamples'],json['datasamples'])

#singleplotStack(f,"nPV"    ,"S0em",json['mcsamples'],json['datasamples'])
#singleplotStack(f,"nGoodPV","S0em",json['mcsamples'],json['datasamples'])

#singleplotStack(f,"nPV"    ,"S1em",json['mcsamples'],json['datasamples'])
#singleplotStack(f,"nGoodPV","S1em",json['mcsamples'],json['datasamples'])

######
for step in json['cuts']:
  for mon in json['monitors']:
    singleplotStack2(f,mon['name'],step,json['mcsamples'],json['datasamples'])


#########
#TH2F
#for step in json['cuts']:
#  for ii,mon in enumerate(json['monitors2']):
#    for i,mon1 in enumerate(mon):
#      for j,mon2 in enumerate(mon):
#        if i<j :
#          mon_ = mon1['name']+"_"+mon2['name']
#          plotTH2F(f,mon_,step,json['mcsamples'],json['datasamples'])

