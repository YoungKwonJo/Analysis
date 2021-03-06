
from ROOT import *
import copy

from ntuple2hist_cff import *
#import sys 

json = {
"file": "hist_all4.root",
#"file": "hist_all2.root",
"mcsamples" : [

{"name":"ttbb", "color": kRed,     "lineWidth": 2, "cx":1.  },
{"name":"ttjj", "color": kBlue-3,  "lineWidth": 2, "cx":1.  },
{"name":"tth",  "color": kGreen-3, "lineWidth": 2, "cx":1.  }

],
#"cuts" : ["S0","S1","S2","S3","S4","S5"],
#"cuts" : ["S0","S1"],
"cuts" : ["S1"],

"monitors" : [

# { "name":"DRgjetBH", "unit":"DR between genjet and B hadron", "var":"DR_gjet_BH",  "xbin_set":[40,0,5]       },
# { "name":"DPTgjetBH","unit":"pT_genjet - pT_BH",              "var":"DPT_gjet_BH", "xbin_set":[200,-200,200] },
# { "name":"Ptgjet",   "unit":"pT ",                            "var":"Pt_gjet",     "xbin_set":[40,0,200]    },
# { "name":"Etagjet",  "unit":"\eta ",                          "var":"Eta_gjet",    "xbin_set":[10,-5,5]    },
# { "name":"BHgjet",   "unit":"# of bH of jet ",                "var":"BH_gjet",     "xbin_set":[10,0,10]    },

  { "name":"Ngenjet20","unit":"# of gen-jet ",                  "var":"Ngenjet20",   "xbin_set":[15,0,15]    },
  { "name":"Ngenjet20BH","unit":"# of gen-bjet ",               "var":"Ngenjet20_BH","xbin_set":[15,0,15]    },
  { "name":"drbhbh","unit":"DR of B-Hadrons ",                  "var":"dr_bh_bh","xbin_set":[100,0,10]       },
  { "name":"Nbhbh","unit":"# of B-Hadrons ",                    "var":"N_bh_bh","xbin_set":[10,0,10]         }

]
}
#########
#TH1F
#singleplot(json['file'],"DRgjetBH","S1",json['mcsamples'])
######
for step in json['cuts']:
  for mon in json['monitors']:
    singleplot(json['file'],mon['name'],step,json['mcsamples'])


#########
#TH2F
for step in json['cuts']:
  for i,mon in enumerate(json['monitors']):
    for j,mon2 in enumerate(json['monitors']):
      if i<j :
        mon_ = mon['name']+"_"+mon2['name']
        plotTH2F(json['file'],mon_,step,json['mcsamples'])


