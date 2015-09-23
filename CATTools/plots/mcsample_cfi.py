
from ROOT import *

loc = "../"
ttbarMG5 = "TTJets_MG5"
ttbarAMC = "TTJets_aMC"
ttbarPOW = "TT_powheg"
ttcx=832.0

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

CS = [kRed, kRed-7, kRed+2, kMagenta,kMagenta+2,kOrange ]
BCS = [kBlue,kGray,kGreen+2,kViolet,kCyan]

mcsamples=[

{"name":"MG5ttbb",  "selection": ttbb,     "file": loc + "result_"+ttbarMG5+".root", "cx":ttcx, "color": CS[0],      "label":"t#bar{t}+b#bar{b}      " },
{"name":"MG5ttb",   "selection": ttb,      "file": loc + "result_"+ttbarMG5+".root", "cx":ttcx, "color": CS[1],   "label":"t#bar{t}+b        "      },
{"name":"MG5tt2b",  "selection": tt2b,     "file": loc + "result_"+ttbarMG5+".root", "cx":ttcx, "color": CS[2],     "label":"t#bar{t}+2b      "       },
{"name":"MG5ttcc",  "selection": ttcc,     "file": loc + "result_"+ttbarMG5+".root", "cx":ttcx, "color": CS[3],   "label":"t#bar{t}+c#bar{c}      " },
{"name":"MG5ttlf",  "selection": ttlf,     "file": loc + "result_"+ttbarMG5+".root", "cx":ttcx, "color": CS[4],  "label":"t#bar{t}+lf       "      },
{"name":"MG5ttot",  "selection": ttothers, "file": loc + "result_"+ttbarMG5+".root", "cx":ttcx, "color": CS[5],   "label":"t#bar{t} others"         },

{"name":"AMCttbb",  "selection": ttbb,     "file": loc + "result_"+ttbarAMC+".root", "cx":ttcx, "color": CS[0],      "label":"t#bar{t}+b#bar{b}      " },
{"name":"AMCttb",   "selection": ttb,      "file": loc + "result_"+ttbarAMC+".root", "cx":ttcx, "color": CS[1],   "label":"t#bar{t}+b        "      },
{"name":"AMCtt2b",  "selection": tt2b,     "file": loc + "result_"+ttbarAMC+".root", "cx":ttcx, "color": CS[2],     "label":"t#bar{t}+2b      "       },
{"name":"AMCttcc",  "selection": ttcc,     "file": loc + "result_"+ttbarAMC+".root", "cx":ttcx, "color": CS[3],   "label":"t#bar{t}+c#bar{c}      " },
{"name":"AMCttlf",  "selection": ttlf,     "file": loc + "result_"+ttbarAMC+".root", "cx":ttcx, "color": CS[4],  "label":"t#bar{t}+lf       "      },
{"name":"AMCttot",  "selection": ttothers, "file": loc + "result_"+ttbarAMC+".root", "cx":ttcx, "color": CS[5],   "label":"t#bar{t} others"         },

{"name":"POWttbb",  "selection": ttbb,     "file": loc + "result_"+ttbarPOW+".root", "cx":ttcx, "color": CS[0],  "label":"t#bar{t}+b#bar{b}      " },
{"name":"POWttb",   "selection": ttb,      "file": loc + "result_"+ttbarPOW+".root", "cx":ttcx, "color": CS[1],  "label":"t#bar{t}+b        "      },
{"name":"POWtt2b",  "selection": tt2b,     "file": loc + "result_"+ttbarPOW+".root", "cx":ttcx, "color": CS[2],  "label":"t#bar{t}+2b      "       },
{"name":"POWttcc",  "selection": ttcc,     "file": loc + "result_"+ttbarPOW+".root", "cx":ttcx, "color": CS[3],  "label":"t#bar{t}+c#bar{c}      " },
{"name":"POWttlf",  "selection": ttlf,     "file": loc + "result_"+ttbarPOW+".root", "cx":ttcx, "color": CS[4],  "label":"t#bar{t}+lf        "      },
{"name":"POWttot",  "selection": ttothers, "file": loc + "result_"+ttbarPOW+".root", "cx":ttcx, "color": CS[5],  "label":"t#bar{t} others"         },

{"name":"TTWlNu", "selection": "(1)", "file": loc + "result_ttWJetsToLNu.root",  "cx":1.152,  "color": BCS[0],   "label":"t#bar{t}W          "    },
{"name":"TTWqq",  "selection": "(1)", "file": loc + "result_ttWJetsToQQ.root",   "cx":1.152,  "color": BCS[0],   "label":"t#bar{t}W          "    },
{"name":"TTZll",  "selection": "(1)", "file": loc + "result_ttZToLLNuNu.root",   "cx":2.232,  "color": BCS[0],   "label":"t#bar{t}Z          "    },
{"name":"TTZqq",  "selection": "(1)", "file": loc + "result_ttZToQQ.root",       "cx":2.232,  "color": BCS[0],   "label":"t#bar{t}Z          "    },

{"name":"STbt",   "selection": "(1)", "file": loc + "result_SingleTbar_t.root",  "cx":80.95,  "color": BCS[1],   "label":"SingleTop"    },
{"name":"STt",    "selection": "(1)", "file": loc + "result_SingleTop_t.root",   "cx":136.02, "color": BCS[1],   "label":"SingleTop"    },
{"name":"STbtW",  "selection": "(1)", "file": loc + "result_SingleTbar_tW.root", "cx":35.6,   "color": BCS[1],   "label":"SingleTop"      },
{"name":"STtW",   "selection": "(1)", "file": loc + "result_SingleTop_tW.root",  "cx":35.6,   "color": BCS[1],   "label":"SingleTop"      },
{"name":"WJets",  "selection": "(1)", "file": loc + "result_WJets.root",         "cx":61526.7,"color": BCS[1],   "label":"WJets      "       },
{"name":"WW",     "selection": "(1)", "file": loc + "result_WW.root",            "cx":110.8,  "color": BCS[1],   "label":"VV            "    },
{"name":"WZ",     "selection": "(1)", "file": loc + "result_WZ.root",            "cx":66.1,   "color": BCS[1],   "label":"VV            "   },
{"name":"ZZ",     "selection": "(1)", "file": loc + "result_ZZ.root",            "cx":15.4,   "color": BCS[1],   "label":"VV            "   },
{"name":"DYJets", "selection": "(1)", "file": loc + "result_DYJets.root",        "cx":6025.2, "color": BCS[1], "label":"DYJets    "      },

{"name":"ttH2non", "selection": "(1)", "file": loc + "result_ttH_nonbb.root",  "cx":0.5058,   "color": BCS[2],   "label":"t#bar{t}H         " ,"isStack":False   },
{"name":"ttH2bb",  "selection": "(1)", "file": loc + "result_ttH_bb.root",     "cx":0.5058,   "color": BCS[2],   "label":"t#bar{t}H         " ,"isStack":False   },
]
qcdsamples=[

{"name":"MuMuQCD", "selection": "(1)", "file": loc + "result_DoubleMuon2.root", "color":kBlack,  "label":"QCD      " },
{"name":"ElElQCD", "selection": "(1)", "file": loc + "result_DoubleEG2.root",   "color":kBlack,  "label":"QCD      " },
{"name":"MuElQCD", "selection": "(1)", "file": loc + "result_MuonEG2.root",     "color":kBlack,  "label":"QCD      " },
]
datasamples=[

{"name":"MuMu", "selection": "(1)", "file": loc + "result_DoubleMuon.root",  "color":kBlack,  "label":"DATA " },
{"name":"ElEl", "selection": "(1)", "file": loc + "result_DoubleEG.root",    "color":kBlack,  "label":"DATA " },
{"name":"MuEl", "selection": "(1)", "file": loc + "result_MuonEG.root",      "color":kBlack,  "label":"DATA " },

]
