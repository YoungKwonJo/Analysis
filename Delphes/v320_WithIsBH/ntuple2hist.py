

from ntuple2hist_cff import *
#import sys 

json = {
"mcsamples" : [

{"name":"ttbb", "selection": "1", "file":"result_ttbb.root", "cx":1.  },
{"name":"ttjj", "selection": "1", "file":"result_ttjj.root", "cx":1.  },
{"name":"tth",  "selection": "1", "file":"result_TTH.root" , "cx":1.  }

],
"monitors" : [

 { "name":"DRgjetBH", "unit":"DR between genjet and B hadron", "var":"DR_gjet_BH",  "xbin_set":[40,0,2]       },
 { "name":"DPTgjetBH","unit":"pT_genjet - pT_BH",              "var":"DPT_gjet_BH", "xbin_set":[200,-200,200] },
 { "name":"Ptgjet",   "unit":"pT ",                            "var":"Pt_gjet",     "xbin_set":[40,0,200]    },
 { "name":"Etagjet",  "unit":"\eta ",                          "var":"Eta_gjet",    "xbin_set":[10,-5,5]    },
 { "name":"BHgjet",   "unit":"# of bH of jet ",                "var":"BH_gjet",     "xbin_set":[10,0,10]    },

# { "name":"Ngenjet20","unit":"# of gen-jet ",                  "var":"Ngenjet20",   "xbin_set":[15,0,15]    },
# { "name":"Ngenjet20BH","unit":"# of gen-bjet ",               "var":"Ngenjet20_BH","xbin_set":[15,0,15]    }

],
"cuts" : [

  "(BH_gjet>0)",
  "(BH_gjet>0) && Pt_gjet>20 && abs(Eta_gjet)<2.5",
  "(BH_gjet>0) && Pt_gjet>20 && abs(Eta_gjet)<2.5 && BH_gjet==1",
  "(BH_gjet>0) && Pt_gjet>20 && abs(Eta_gjet)<2.5 && BH_gjet==2",
  "(BH_gjet>0) && Pt_gjet>20 && abs(Eta_gjet)<2.5 && BH_gjet==3",
  "(BH_gjet>0) && Pt_gjet>20 && abs(Eta_gjet)<2.5 && BH_gjet==4"
 
],
"output" : "hist_all.root"
}

#makehist(json)
makehist2(json)

