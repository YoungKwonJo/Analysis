from ROOT import *
import copy

from ntuple2hist_cff import *
from mcsample_cfi import *
from monitors_cfi import *

#import sys 

json = {
"file": "hist_all1.root",
#"file": "hist_all2.root",
"mcsamples" : mcsamples,
#"cuts" : ["S0","S1","S2","S3","S4","S5"],
#"cuts" : ["S0","S1","S2","S3"],
"cuts" : ["S0","S1","S2","S3"],
#"cuts" : ["S3","S4","S5"],

"monitors" : monitors["jetMon3"]

}
#########
#TH1F
#singleplot(json['file'],"DRgjetBH","S1",json['mcsamples'])
######
for step in json['cuts']:
  for mon in json['monitors']:
    singleplot(json['file'],mon['name'],step,json['mcsamples'])
    singleplotlinear(json['file'],mon['name'],step,json['mcsamples'])


#########
#TH2F
#for step in json['cuts']:
#  for i,mon in enumerate(json['monitors']):
#    for j,mon2 in enumerate(json['monitors']):
#      if i<j :
#        mon_ = mon['name']+"_"+mon2['name']
#        plotTH2F(json['file'],mon_,step,json['mcsamples'])
