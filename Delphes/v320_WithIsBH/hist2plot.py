
from ROOT import *
import copy

from ntuple2hist_cff import *
#import sys 

json = {
"file": "hist_all.root",
"mcsamples" : [

{"name":"ttbb", "color": kRed,     "lineWidth": 2, "cx":1.  },
{"name":"ttjj", "color": kBlue-3,  "lineWidth": 2, "cx":1.  },
{"name":"tth",  "color": kGreen-3, "lineWidth": 2, "cx":1.  }

],
"cuts" : ["S0","S1","S2","S3","S4","S5"],

"monitors" : [

 { "name":"DRgjetBH", "unit":"DR between genjet and B hadron", "var":"DR_gjet_BH",  "xbin_set":[40,0,5]       },
 { "name":"DPTgjetBH","unit":"pT_genjet - pT_BH",              "var":"DPT_gjet_BH", "xbin_set":[200,-200,200] },
 { "name":"Ptgjet",   "unit":"pT ",                            "var":"Pt_gjet",     "xbin_set":[40,0,200]    },
 { "name":"Etagjet",  "unit":"\eta ",                          "var":"Eta_gjet",    "xbin_set":[10,-5,5]    },
 { "name":"BHgjet",   "unit":"# of bH of jet ",                "var":"BH_gjet",     "xbin_set":[10,0,10]    },

# { "name":"Ngenjet20","unit":"# of gen-jet ",                  "var":"Ngenjet20",   "xbin_set":[15,0,15]    },
# { "name":"Ngenjet20BH","unit":"# of gen-bjet ",               "var":"Ngenjet20_BH","xbin_set":[15,0,15]    }

]
}

#singleplot(json['file'],"DRgjetBH","S1",json['mcsamples'])

####
for step in json['cuts']:
  for mon in json['monitors']:
    singleplot(json['file'],mon['name'],step,json['mcsamples'])
