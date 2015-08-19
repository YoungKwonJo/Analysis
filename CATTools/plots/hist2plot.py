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
"file": "hist_mon1.root",
#"file": "hist_all2.root",
"mcsamples" : mcsamples,
#"cuts" : ["S0","S1","S2","S3","S4","S5"],
#"cuts" : ["S0","S1","S2","S3"],
"cuts" : ["S0","S1","S2","S3","S4","S5","S6"],
#"cuts" : ["S6"],

#"monitors" : monitors["jetMon3"]
"monitors" : mon,
"monitors2" : mon2
}

#########
#TH1F
singleplotStack(json['file'],"MET","S0mm",json['mcsamples'])
singleplotStack(json['file'],"MET","S1mm",json['mcsamples'])
singleplotStack(json['file'],"MET","S2mm",json['mcsamples'])
singleplotStack(json['file'],"ZMassMM","S0mm",json['mcsamples'])
singleplotStack(json['file'],"ZMassMM","S1mm",json['mcsamples'])
singleplotStack(json['file'],"ZMassMM","S2mm",json['mcsamples'])
######
#for step in json['cuts']:
#  for mon in json['monitors']:
#    singleplot(json['file'],mon['name'],step,json['mcsamples'])
#    singleplotlinear(json['file'],mon['name'],step,json['mcsamples'])


#########
#TH2F
#for step in json['cuts']:
#  for ii,mon in enumerate(json['monitors2']):
#    for i,mon1 in enumerate(mon):
#      for j,mon2 in enumerate(mon):
#        if i<j :
#          mon_ = mon1['name']+"_"+mon2['name']
#          plotTH2F(json['file'],mon_,step,json['mcsamples'])

