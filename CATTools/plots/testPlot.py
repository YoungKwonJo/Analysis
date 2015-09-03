import sys 

from ntuple2hist_cff import *
from mcsample_cfi import * 
from monitors_cfi import *
from cut_cfi import *

from ROOT import *
#mon = []
#for i,ii in enumerate(monitors):
#  #print monitors[ii]
#  mon+=monitors[ii]
#########
test_mcsamples=[

{"name":"DYJets", "selection": "(1)", "file": loc + "result_DYJets.root",        "cx":6025.2, "color": kBlue+5,  "label":"DYJets    "      },
]

test_cuts={
"channel": "mm",
"cut": [
   "(1)",
   "(" + ll_lepIso+"&&"+mm + ")",
   #"("+mm_op+")",
   #"(" + mm_lep + ")",
   #"(" + mm_zmass + ")",
]
}

mon1=[
#  { "name":"MET",          "unit":"Missing E_{T} (GeV) ",          "var":"met",      "xbin_set":[60,0,300]   },
  { "name":"ZMass",      "unit":"Dilepton mass (GeV/c^{2}) ",    "var":"ll_zmass",  "xbin_set":[60,0,300]  },
]
#for mon11 in monitors.keys():
#  if mon11 == ("Mon" + arg) :
#    mon1+=monitors["Mon" + arg ]

mon2=[]

#mceventweight="puWeight"
mceventweight="1"

json = {
"mcsamples" : test_mcsamples,
"mceventweight": mceventweight,
"datasamples" : datasamples,
"monitors" : mon1,
#"monitors" : monitors["Mon1"],
"monitors2" : mon2,
#"monitors2" : [],
"cuts" : test_cuts, 
"cutsQCD" : test_cuts, 
"output" : "hist_test.root"
}

#makehist(json)

#f = TFile.Open(json['output'],"read")
f = TFile.Open("hist_all.root","read")
c1 = singleplotStackLL(f,"ZMass","S0",json['mcsamples'],json['datasamples'])
c2 = singleplotStackLL(f,"ZMass","S1",json['mcsamples'],json['datasamples'])
#c3 = singleplotStack(f,"ZMassMM","S2mm",json['mcsamples'],json['datasamples'])

