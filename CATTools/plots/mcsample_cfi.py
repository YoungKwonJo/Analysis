
from ROOT import *

#loc = "../"
loc = "/xrootd/store/user/youngjo/Cattools/v7-4-3/result/"
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

def GW(sel="1"):
  return "(("+sel+")*(genWeight/abs(genWeight)))"

ttotheslist = [op_(ttbb), op_(ttb), op_(tt2b), op_(ttcc),op_(ttlf) ]
#ttothers = "(" + op_(ttbb) + " && " + op_(ttb) + " && " + op_(tt2b) + " && " + op_(ttcc) + " && " + op_(ttlf) + ")"
ttothers = mAND2(ttotheslist)

CS = [kRed, kRed-7, kRed+2, kMagenta,kMagenta+2,kOrange ]
BCS = [kBlue,kGray,kGreen+2,kViolet,kCyan]

mcsamples=[

#{"name":"MG5ttbb",  "selection": GW(ttbb),     "file": loc + "result_"+ttbarMG5+".root", "cx":ttcx, "color": CS[0],      "label":"t#bar{t}+b#bar{b}      " },
#{"name":"MG5ttb",   "selection": GW(ttb),      "file": loc + "result_"+ttbarMG5+".root", "cx":ttcx, "color": CS[1],   "label":"t#bar{t}+b        "      },
#{"name":"MG5tt2b",  "selection": GW(tt2b),     "file": loc + "result_"+ttbarMG5+".root", "cx":ttcx, "color": CS[2],     "label":"t#bar{t}+2b      "       },
#{"name":"MG5ttcc",  "selection": GW(ttcc),     "file": loc + "result_"+ttbarMG5+".root", "cx":ttcx, "color": CS[3],   "label":"t#bar{t}+c#bar{c}      " },
#{"name":"MG5ttlf",  "selection": GW(ttlf),     "file": loc + "result_"+ttbarMG5+".root", "cx":ttcx, "color": CS[4],  "label":"t#bar{t}+lf       "      },
#{"name":"MG5ttot",  "selection": GW(ttothers), "file": loc + "result_"+ttbarMG5+".root", "cx":ttcx, "color": CS[5],   "label":"t#bar{t} others"         },

#{"name":"AMCttbb",  "selection": GW(ttbb),     "file": loc + "result_"+ttbarAMC+".root", "cx":ttcx, "color": CS[0],      "label":"t#bar{t}+b#bar{b}      " },
#{"name":"AMCttb",   "selection": GW(ttb),      "file": loc + "result_"+ttbarAMC+".root", "cx":ttcx, "color": CS[1],   "label":"t#bar{t}+b        "      },
#{"name":"AMCtt2b",  "selection": GW(tt2b),     "file": loc + "result_"+ttbarAMC+".root", "cx":ttcx, "color": CS[2],     "label":"t#bar{t}+2b      "       },
#{"name":"AMCttcc",  "selection": GW(ttcc),     "file": loc + "result_"+ttbarAMC+".root", "cx":ttcx, "color": CS[3],   "label":"t#bar{t}+c#bar{c}      " },
#{"name":"AMCttlf",  "selection": GW(ttlf),     "file": loc + "result_"+ttbarAMC+".root", "cx":ttcx, "color": CS[4],  "label":"t#bar{t}+lf       "      },
#{"name":"AMCttot",  "selection": GW(ttothers), "file": loc + "result_"+ttbarAMC+".root", "cx":ttcx, "color": CS[5],   "label":"t#bar{t} others"         },

{"name":"POWttbb",  "selection": GW(ttbb),     "file": loc + "result_"+ttbarPOW+".root", "cx":ttcx, "color": CS[0],  "label":"t#bar{t}+b#bar{b}      " },
{"name":"POWttb",   "selection": GW(ttb),      "file": loc + "result_"+ttbarPOW+".root", "cx":ttcx, "color": CS[1],  "label":"t#bar{t}+b        "      },
{"name":"POWtt2b",  "selection": GW(tt2b),     "file": loc + "result_"+ttbarPOW+".root", "cx":ttcx, "color": CS[2],  "label":"t#bar{t}+2b      "       },
{"name":"POWttcc",  "selection": GW(ttcc),     "file": loc + "result_"+ttbarPOW+".root", "cx":ttcx, "color": CS[3],  "label":"t#bar{t}+c#bar{c}      " },
{"name":"POWttlf",  "selection": GW(ttlf),     "file": loc + "result_"+ttbarPOW+".root", "cx":ttcx, "color": CS[4],  "label":"t#bar{t}+lf        "      },
{"name":"POWttot",  "selection": GW(ttothers), "file": loc + "result_"+ttbarPOW+".root", "cx":ttcx, "color": CS[5],  "label":"t#bar{t} others"         },

{"name":"TTWlNu", "selection": GW(), "file": loc + "result_ttWJetsToLNu.root",  "cx":1.152,  "color": BCS[0],   "label":"t#bar{t}W          "    },
{"name":"TTWqq",  "selection": GW(), "file": loc + "result_ttWJetsToQQ.root",   "cx":1.152,  "color": BCS[0],   "label":"t#bar{t}W          "    },
{"name":"TTZll",  "selection": GW(), "file": loc + "result_ttZToLLNuNu.root",   "cx":2.232,  "color": BCS[0],   "label":"t#bar{t}Z          "    },
{"name":"TTZqq",  "selection": GW(), "file": loc + "result_ttZToQQ.root",       "cx":2.232,  "color": BCS[0],   "label":"t#bar{t}Z          "    },

{"name":"STbt",   "selection": GW(), "file": loc + "result_SingleTbar_t.root",  "cx":80.95,  "color": BCS[1],   "label":"SingleTop"    },
{"name":"STt",    "selection": GW(), "file": loc + "result_SingleTop_t.root",   "cx":136.02, "color": BCS[1],   "label":"SingleTop"    },
{"name":"STbtW",  "selection": GW(), "file": loc + "result_SingleTbar_tW.root", "cx":35.6,   "color": BCS[1],   "label":"SingleTop"      },
{"name":"STtW",   "selection": GW(), "file": loc + "result_SingleTop_tW.root",  "cx":35.6,   "color": BCS[1],   "label":"SingleTop"      },
{"name":"WJets",  "selection": GW(), "file": loc + "result_WJets.root",         "cx":61526.7,"color": BCS[1],   "label":"WJets      "       },
{"name":"WW",     "selection": GW(), "file": loc + "result_WW.root",            "cx":110.8,  "color": BCS[1],   "label":"VV            "    },
{"name":"WZ",     "selection": GW(), "file": loc + "result_WZ.root",            "cx":66.1,   "color": BCS[1],   "label":"VV            "   },
{"name":"ZZ",     "selection": GW(), "file": loc + "result_ZZ.root",            "cx":15.4,   "color": BCS[1],   "label":"VV            "   },

{"name":"DYJets", "selection": GW(), "file": loc + "result_DYJets.root",        "cx":6025.2, "color": BCS[1], "label":"DYJets    "      },
{"name":"DYJets10", "selection": GW(), "file": loc + "result_DYJets_10to50.root","cx":18271.92, "color": BCS[1], "label":"DYJets    "      },

#{"name":"DYRin", "selection": GW("(ll_zmass-91.2<=15)"), "file": loc + "result_DYJets.root",        "cx":6025.2, "color": BCS[1], "label":"DYJets    "      },
#{"name":"DYRout", "selection": GW("(ll_zmass-91.2>15)"), "file": loc + "result_DYJets.root","cx":18271.92, "color": BCS[1], "label":"DYJets    "      },
#{"name":"DYRout", "selection": GW(), "file": loc + "result_DYJets_10to50.root","cx":18271.92, "color": BCS[1], "label":"DYJets    "      },


{"name":"ttH2non", "selection": GW(), "file": loc + "result_ttH_nonbb.root",  "cx":0.5058,   "color": BCS[2],   "label":"t#bar{t}H         " ,"isStack":False   },
{"name":"ttH2bb",  "selection": GW(), "file": loc + "result_ttH_bb.root",     "cx":0.5058,   "color": BCS[2],   "label":"t#bar{t}H         " ,"isStack":False   },
]

datasamples=[

{"name":"MuMu1", "selection": "(1)", "file": loc + "result_DoubleMuon_Run2015C226p1.root",  "color":kBlack,  "label":"DATA " },
{"name":"MuMu2", "selection": "(1)", "file": loc + "result_DoubleMuon_Run2015D226p1.root",  "color":kBlack,  "label":"DATA " },
{"name":"ElEl1", "selection": "(1)", "file": loc + "result_DoubleEG_Run2015C226p1.root",    "color":kBlack,  "label":"DATA " },
{"name":"ElEl2", "selection": "(1)", "file": loc + "result_DoubleEG_Run2015D226p1.root",    "color":kBlack,  "label":"DATA " },
{"name":"MuEl1", "selection": "(1)", "file": loc + "result_MuonEG_Run2015C226p1.root",      "color":kBlack,  "label":"DATA " },
{"name":"MuEl2", "selection": "(1)", "file": loc + "result_MuonEG_Run2015D226p1.root",      "color":kBlack,  "label":"DATA " },

#{"name":"mm1Rin", "selection": "(ll_zmass-91.2<=15)", "file": loc + "result_DoubleMuon_Run2015C226p1.root",  "color":kBlack,  "label":"DATA " },
#{"name":"mm1Rout", "selection": "(ll_zmass-91.2>15)", "file": loc + "result_DoubleMuon_Run2015C226p1.root",  "color":kBlack,  "label":"DATA " },
#{"name":"mm2Rin", "selection": "(ll_zmass-91.2<=15)", "file": loc + "result_DoubleMuon_Run2015D226p1.root",  "color":kBlack,  "label":"DATA " },
#{"name":"mm2Rout", "selection": "(ll_zmass-91.2>15)", "file": loc + "result_DoubleMuon_Run2015D226p1.root",  "color":kBlack,  "label":"DATA " },

#{"name":"ee1Rin", "selection": "(ll_zmass-91.2<=15)", "file": loc + "result_DoubleEG_Run2015C226p1.root",    "color":kBlack,  "label":"DATA " },
#{"name":"ee1Rout", "selection": "(ll_zmass-91.2>15)", "file": loc + "result_DoubleEG_Run2015C226p1.root",    "color":kBlack,  "label":"DATA " },
#{"name":"ee2Rin", "selection": "(ll_zmass-91.2<=15)", "file": loc + "result_DoubleEG_Run2015D226p1.root",    "color":kBlack,  "label":"DATA " },
#{"name":"ee2Rout", "selection": "(ll_zmass-91.2>15)", "file": loc + "result_DoubleEG_Run2015D226p1.root",    "color":kBlack,  "label":"DATA " },

#{"name":"em1Rin", "selection": "(ll_zmass-91.2<=15)", "file": loc + "result_MuonEG_Run2015C226p1.root",      "color":kBlack,  "label":"DATA " },
#{"name":"em1Rout", "selection": "(ll_zmass-91.2>15)", "file": loc + "result_MuonEG_Run2015C226p1.root",      "color":kBlack,  "label":"DATA " },
#{"name":"em2Rin", "selection": "(ll_zmass-91.2<=15)", "file": loc + "result_MuonEG_Run2015D226p1.root",      "color":kBlack,  "label":"DATA " },
#{"name":"em2Rout", "selection": "(ll_zmass-91.2>15)", "file": loc + "result_MuonEG_Run2015D226p1.root",      "color":kBlack,  "label":"DATA " },

]
