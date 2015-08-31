import sys 

from ntuple2hist_cff import *
from mcsample_cfi import * 
#from monitors_cfi import *
from cutQCD_cfi import *


mon =[]
mon1 = [
  { "name":"lep1IsoMM",    "unit":"Leading lepton Iso_{rel} ",     "var":"mm_mu1_iso", "xbin_set":[200,0,1] },
  { "name":"lep2IsoMM",    "unit":"Sceond  lepton Iso_{rel} ",     "var":"mm_mu2_iso", "xbin_set":[200,0,1] },
]
mon2 = [
  { "name":"lep1IsoEE",    "unit":"Leading lepton Iso_{rel} ",     "var":"ee_el1_iso", "xbin_set":[200,0,1] },
  { "name":"lep2IsoEE",    "unit":"Sceond  lepton Iso_{rel} ",     "var":"ee_el2_iso", "xbin_set":[200,0,1] },
]
mon3 = [
  { "name":"lep1IsoEM",    "unit":"Leading lepton Iso_{rel} ",     "var":"em_mu1_iso", "xbin_set":[200,0,1] },
  { "name":"lep2IsoEM",    "unit":"Sceond  lepton Iso_{rel} ",     "var":"em_el2_iso", "xbin_set":[200,0,1] },
]

#mceventweight="puWeight"
mceventweight="1"

jsonMM = {
"mcsamples" : mcsamples,
"mceventweight": mceventweight,
"datasamples" : datasamples,
"monitors" : mon,
#"monitors" : monitors["Mon1"],
"monitors2" : mon1,
#"monitors2" : [],
"cuts" : mm_cutsSs, 
"cutsQCD" : mm_cutsSs, 
"output" : "hist_Ss_QCDmm.root"
}

makehist(jsonMM)
#makehist2(json)

jsonEE = {
"mcsamples" : mcsamples,
"mceventweight": mceventweight,
"datasamples" : datasamples,
"monitors" : mon,
#"monitors" : monitors["Mon1"],
"monitors2" : mon2,
#"monitors2" : [],
"cuts" : ee_cutsSs,
"cutsQCD" : ee_cutsSs, 
"output" : "hist_Ss_QCDee.root"
}
makehist(jsonEE)

jsonEM = {
"mcsamples" : mcsamples,
"mceventweight": mceventweight,
"datasamples" : datasamples,
"monitors" : mon,
#"monitors" : monitors["Mon1"],
"monitors2" : mon3,
#"monitors2" : [],
"cuts" : em_cutsSs,
"cutsQCD" : em_cutsSs, 
"output" : "hist_Ss_QCDem.root"
}
makehist(jsonEM)

