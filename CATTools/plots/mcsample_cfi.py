
from ROOT import *

loc = "../"
ttbarMG5 = "TTJets_MG5"
ttbarAMC = "TTJets_aMC"
ttbarPOW = "TT_powheg"
ttcx=815.96

def mAND(aaa,bbb):
  return "(" +aaa+ " && "+bbb+")"
def mAND2(aaa):
  bbb=""
  for i,ii in enumerate(aaa):
    if i==0 : 
      bbb+= ii
    else : 
      bbb=mAND(ii,bbb)
  return bbb


ll = " ((isMM ==1 || isEE==1 || isEM==1) && NgenJet>=4 )"
ttbb = mAND(" (Category==2) ", ll)
ttb  = mAND(" (Category==4) ", ll)
tt2b = mAND(" (Category==3) ", ll)
ttcc = mAND(" (Category==1) ", ll)
ttlf = mAND(" (Category==0) ", ll)

def op_(aaa):
  return "!(" + aaa + ")"

ttotheslist = [op_(ttbb), op_(ttb), op_(tt2b), op_(ttcc),op_(ttlf) ]
#ttothers = "(" + op_(ttbb) + " && " + op_(ttb) + " && " + op_(tt2b) + " && " + op_(ttcc) + " && " + op_(ttlf) + ")"
ttothers = mAND2(ttotheslist)

mcsamples=[

{"name":"MG5ttbb",  "selection": ttbb,     "file": loc + "result_"+ttbarMG5+".root", "cx":ttcx, "color": kRed,      "label":"t#bar{t}+b#bar{b}      " },
{"name":"MG5ttb",   "selection": ttb,      "file": loc + "result_"+ttbarMG5+".root", "cx":ttcx, "color": kOrange,   "label":"t#bar{t}+b        "      },
{"name":"MG5tt2b",  "selection": tt2b,     "file": loc + "result_"+ttbarMG5+".root", "cx":ttcx, "color": kCyan,     "label":"t#bar{t}+2b      "       },
{"name":"MG5ttcc",  "selection": ttcc,     "file": loc + "result_"+ttbarMG5+".root", "cx":ttcx, "color": kBlue-3,   "label":"t#bar{t}+c#bar{c}      " },
{"name":"MG5ttlf",  "selection": ttlf,     "file": loc + "result_"+ttbarMG5+".root", "cx":ttcx, "color": kGreen-3,  "label":"t#bar{t}+lf       "      },
{"name":"MG5ttot",  "selection": ttothers, "file": loc + "result_"+ttbarMG5+".root", "cx":ttcx, "color": kViolet,   "label":"t#bar{t} others"         },

{"name":"AMCttbb",  "selection": ttbb,     "file": loc + "result_"+ttbarAMC+".root", "cx":ttcx, "color": kRed,      "label":"t#bar{t}+b#bar{b}      " },
{"name":"AMCttb",   "selection": ttb,      "file": loc + "result_"+ttbarAMC+".root", "cx":ttcx, "color": kOrange,   "label":"t#bar{t}+b        "      },
{"name":"AMCtt2b",  "selection": tt2b,     "file": loc + "result_"+ttbarAMC+".root", "cx":ttcx, "color": kCyan,     "label":"t#bar{t}+2b      "       },
{"name":"AMCttcc",  "selection": ttcc,     "file": loc + "result_"+ttbarAMC+".root", "cx":ttcx, "color": kBlue-3,   "label":"t#bar{t}+c#bar{c}      " },
{"name":"AMCttlf",  "selection": ttlf,     "file": loc + "result_"+ttbarAMC+".root", "cx":ttcx, "color": kGreen-3,  "label":"t#bar{t}+lf       "      },
{"name":"AMCttot",  "selection": ttothers, "file": loc + "result_"+ttbarAMC+".root", "cx":ttcx, "color": kViolet,   "label":"t#bar{t} others"         },

{"name":"POWttbb",  "selection": ttbb,     "file": loc + "result_"+ttbarPOW+".root", "cx":ttcx, "color": kRed,      "label":"t#bar{t}+b#bar{b}      " },
{"name":"POWttb",   "selection": ttb,      "file": loc + "result_"+ttbarPOW+".root", "cx":ttcx, "color": kOrange,   "label":"t#bar{t}+b        "      },
{"name":"POWtt2b",  "selection": tt2b,     "file": loc + "result_"+ttbarPOW+".root", "cx":ttcx, "color": kCyan,     "label":"t#bar{t}+2b      "       },
{"name":"POWttcc",  "selection": ttcc,     "file": loc + "result_"+ttbarPOW+".root", "cx":ttcx, "color": kBlue-3,   "label":"t#bar{t}+c#bar{c}      " },
{"name":"POWttlf",  "selection": ttlf,     "file": loc + "result_"+ttbarPOW+".root", "cx":ttcx, "color": kGreen-3,  "label":"t#bar{t}+lf       "      },
{"name":"POWttot",  "selection": ttothers, "file": loc + "result_"+ttbarPOW+".root", "cx":ttcx, "color": kViolet,   "label":"t#bar{t} others"         },

{"name":"STbt",   "selection": "(1)", "file": loc + "result_SingleTbar_t.root",  "cx":80.95,  "color": kGray,   "label":"SingleTop"    },
{"name":"STt",    "selection": "(1)", "file": loc + "result_SingleTop_t.root",   "cx":136.02, "color": kGray,   "label":"SingleTop"    },
{"name":"STbtW",  "selection": "(1)", "file": loc + "result_SingleTbar_tW.root", "cx":35.6,   "color": kGray,   "label":"SingleTop"      },
{"name":"STtW",   "selection": "(1)", "file": loc + "result_SingleTop_tW.root",  "cx":35.6,   "color": kGray,   "label":"SingleTop"      },
{"name":"WJets",  "selection": "(1)", "file": loc + "result_WJets.root",         "cx":61526.7,"color": kGray,   "label":"WJets      "       },
{"name":"WW",     "selection": "(1)", "file": loc + "result_WW.root",            "cx":110.8,  "color": kGray,   "label":"WW          "    },
{"name":"WZ",     "selection": "(1)", "file": loc + "result_WZ.root",            "cx":66.1,   "color": kGray,   "label":"WZ           "   },
{"name":"ZZ",     "selection": "(1)", "file": loc + "result_ZZ.root",            "cx":15.4,   "color": kGray,   "label":"ZZ            "   },
{"name":"DYJets", "selection": "(1)", "file": loc + "result_DYJets.root",        "cx":6025.2, "color": kGray+5, "label":"DYJets    "      },

]
qcdsamples=[

{"name":"MuMuQCD", "selection": "(1)", "file": loc + "result_DoubleMuon2.root", "color":kBlack,  "label":"QCD      " },
{"name":"ElElQCD", "selection": "(1)", "file": loc + "result_DoubleEG2.root",   "color":kBlack,  "label":"QCD      " },
{"name":"MuElQCD", "selection": "(1)", "file": loc + "result_MuonEG2.root",     "color":kBlack,  "label":"QCD      " },
]
datasamples=[

{"name":"MuMu", "selection": "(run>251603)", "file": loc + "result_DoubleMuon.root", "color":kBlack,   "label":"DATA     " },
{"name":"MuMu", "selection": "(run<251604)", "file": loc + "result_DoubleMuon2.root", "color":kBlack,  "label":"DATA     " },
{"name":"ElEl", "selection": "(run>251603)", "file": loc + "result_DoubleEG.root",   "color":kBlack,   "label":"DATA     " },
{"name":"ElEl", "selection": "(run<251604)", "file": loc + "result_DoubleEG2.root",   "color":kBlack,  "label":"DATA     " },
{"name":"MuEl", "selection": "(run>251602)", "file": loc + "result_MuonEG.root",     "color":kBlack,   "label":"DATA     " },
{"name":"MuEl", "selection": "(run<251604)", "file": loc + "result_MuonEG2.root",     "color":kBlack,  "label":"DATA     " },

]
