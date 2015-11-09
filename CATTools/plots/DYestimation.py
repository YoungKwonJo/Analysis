import sys 

from ntuple2hist_cff import *
from mcsample_cfi import * 
from monitors_cfi import *
from cut_cfi import *

from ROOT import *

#######################################################
DY_mcsamples=[
{"name":"DYRin",   "selection": GW("(abs(ll_zmass-91.2)<=15)"), "file": loc + "result_DYJets.root",       "cx":6025.2,  "color": BCS[1], "label":"DYJets    "      },
{"name":"DYRout",  "selection": GW("(abs(ll_zmass-91.2)>15)"),  "file": loc + "result_DYJets.root",       "cx":6025.2,  "color": BCS[1], "label":"DYJets    "      },
{"name":"DYRout2", "selection": GW(),                      "file": loc + "result_DYJets_10to50.root","cx":18271.92,"color": BCS[1], "label":"DYJets    "      },
]

datasamplesMM=[
{"name":"mm1Rin",  "selection": "(abs(ll_zmass-91.2)<=15)", "file": loc + "result_DoubleMuon_Run2015C226p1.root",  "color":kBlack,  "label":"DATA " },
{"name":"mm1Rout", "selection": "(abs(ll_zmass-91.2)>15)",  "file": loc + "result_DoubleMuon_Run2015C226p1.root",  "color":kBlack,  "label":"DATA " },
{"name":"mm2Rin",  "selection": "(abs(ll_zmass-91.2)<=15)", "file": loc + "result_DoubleMuon_Run2015D226p1.root",  "color":kBlack,  "label":"DATA " },
{"name":"mm2Rout", "selection": "(abs(ll_zmass-91.2)>15)",  "file": loc + "result_DoubleMuon_Run2015D226p1.root",  "color":kBlack,  "label":"DATA " },
]
datasamplesEE=[
{"name":"ee1Rin",  "selection": "(abs(ll_zmass-91.2)<=15)", "file": loc + "result_DoubleEG_Run2015C226p1.root",    "color":kBlack,  "label":"DATA " },
{"name":"ee1Rout", "selection": "(abs(ll_zmass-91.2)>15)",  "file": loc + "result_DoubleEG_Run2015C226p1.root",    "color":kBlack,  "label":"DATA " },
{"name":"ee2Rin",  "selection": "(abs(ll_zmass-91.2)<=15)", "file": loc + "result_DoubleEG_Run2015D226p1.root",    "color":kBlack,  "label":"DATA " },
{"name":"ee2Rout", "selection": "(abs(ll_zmass-91.2)>15)",  "file": loc + "result_DoubleEG_Run2015D226p1.root",    "color":kBlack,  "label":"DATA " },
]
datasamplesEM=[
{"name":"em1Rin",  "selection": "(abs(ll_zmass-91.2)<=15)", "file": loc + "result_MuonEG_Run2015C226p1.root",      "color":kBlack,  "label":"DATA " },
{"name":"em1Rout", "selection": "(abs(ll_zmass-91.2)>15)",  "file": loc + "result_MuonEG_Run2015C226p1.root",      "color":kBlack,  "label":"DATA " },
{"name":"em2Rin",  "selection": "(abs(ll_zmass-91.2)<=15)", "file": loc + "result_MuonEG_Run2015D226p1.root",      "color":kBlack,  "label":"DATA " },
{"name":"em2Rout", "selection": "(abs(ll_zmass-91.2)>15)",  "file": loc + "result_MuonEG_Run2015D226p1.root",      "color":kBlack,  "label":"DATA " },
]

mon1=[
  { "name":"ZMass",      "unit":"Dilepton mass (GeV/c^{2}) ",    "var":"ll_zmass",  "xbin_set":[60,0,300]  },
]
mon2=[]
#######################################################
import copy
mm_cutsDY = copy.deepcopy(mm_cuts)
mm_cutsDY["cut"][4]= "(1)"

ee_cutsDY = copy.deepcopy(ee_cuts)
ee_cutsDY["cut"][4]= "(1)"

em_cutsDY = copy.deepcopy(em_cuts)
em_cutsDY["cut"][4]= "(1)"
#######################################################

#mceventweight="puWeight"
mceventweight="1"

jsonMM = {
"mcsamples" : DY_mcsamples,
"mceventweight": mceventweight,
"datasamples" : datasamplesMM,
"monitors" : mon1,
#"monitors" : monitors["Mon1"],
"monitors2" : mon2,
#"monitors2" : [],
"cuts" : mm_cutsDY, 
"cutsQCD" : mm_cutsQCD, 
"output" : "hist_DYmon" +mm_cuts["channel"]+ ".root"
}

makehist(jsonMM)
#makehist2(json)

jsonEE = {
"mcsamples" : DY_mcsamples,
"mceventweight": mceventweight,
"datasamples" : datasamplesEE,
"monitors" : mon1,
#"monitors" : monitors["Mon1"],
"monitors2" : mon2,
#"monitors2" : [],
"cuts" : ee_cutsDY,
"cutsQCD" : ee_cutsQCD, 
"output" : "hist_DYmon" +ee_cuts["channel"]+ ".root"
}
makehist(jsonEE)

jsonEM = {
"mcsamples" : DY_mcsamples,
"mceventweight": mceventweight,
"datasamples" : datasamplesEM,
"monitors" : mon1,
#"monitors" : monitors["Mon1"],
"monitors2" : mon2,
#"monitors2" : [],
"cuts" : em_cutsDY,
"cutsQCD" : em_cutsQCD, 
"output" : "hist_DYmon" +em_cuts["channel"]+ ".root"
}
makehist(jsonEM)

