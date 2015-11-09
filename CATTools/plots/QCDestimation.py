import sys 

from ntuple2hist_cff import *
from mcsample_cfi import * 
from monitors_cfi import *
from cut_cfi import *

from ROOT import *

#######################################################
#sel = "NonIsoOS"
sel = "NonIsoSS"
#sel = "IsoOS"
#sel = "IsoSS"

mon1=[
  { "name":"lep1"+sel,      "unit":"Leading lepton Iso_{rel} ",     "var":"ll_lep1_iso", "xbin_set":[20,0,1] },
  { "name":"lep2"+sel,      "unit":"Sceond  lepton Iso_{rel} ",     "var":"ll_lep2_iso", "xbin_set":[20,0,1] },
]
mon2=[]
#######################################################
import copy
mm_cutsQCD2 = copy.deepcopy(mm_cuts)
if sel.find("NonIsoOS")>-1  : mm_cutsQCD2["cut"][2]= ll_NonIsoOS
elif sel.find("NonIsoSS")>-1: mm_cutsQCD2["cut"][2]= ll_NonIsoSS
elif sel.find("IsoOS")>-1   : mm_cutsQCD2["cut"][2]= ll_IsoOS
elif sel.find("IsoSS")>-1   : mm_cutsQCD2["cut"][2]= ll_IsoSS

ee_cutsQCD2 = copy.deepcopy(ee_cuts)
if sel.find("NonIsoOS")>-1  : ee_cutsQCD2["cut"][2]= ll_NonIsoOS
elif sel.find("NonIsoSS")>-1: ee_cutsQCD2["cut"][2]= ll_NonIsoSS
elif sel.find("IsoOS")>-1   : ee_cutsQCD2["cut"][2]= ll_IsoOS
elif sel.find("IsoSS")>-1   : ee_cutsQCD2["cut"][2]= ll_IsoSS

em_cutsQCD2 = copy.deepcopy(em_cuts)
if sel.find("NonIsoOS")>-1  : em_cutsQCD2["cut"][2]= ll_NonIsoOS
elif sel.find("NonIsoSS")>-1: em_cutsQCD2["cut"][2]= ll_NonIsoSS
elif sel.find("IsoOS")>-1   : em_cutsQCD2["cut"][2]= ll_IsoOS
elif sel.find("IsoSS")>-1   : em_cutsQCD2["cut"][2]= ll_IsoSS

#######################################################

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
"cuts" : mm_cutsQCD2, 
"cutsQCD" : mm_cutsQCD, 
"output" : "hist_QCDmon"+sel+mm_cuts["channel"]+ ".root"
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
"cuts" : ee_cutsQCD2,
"cutsQCD" : ee_cutsQCD, 
"output" : "hist_QCDmon"+sel+ee_cuts["channel"]+ ".root"
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
"cuts" : em_cutsQCD2,
"cutsQCD" : em_cutsQCD, 
"output" : "hist_QCDmon"+sel+em_cuts["channel"]+ ".root"
}
makehist(jsonEM)

