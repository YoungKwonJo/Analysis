
from ROOT import *

loc = "../"
#ttbar = "TTJets_MG5"
#ttbar = "TTJets_aMC"
ttbar = "TT_powheg"
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

{"name":"ttbb",  "selection": ttbb,     "file": loc + "result_"+ttbar+".root", "cx":ttcx, "color": kRed,     "lineWidth": 4, "label":"t#bar{t}+b#bar{b}      " },
{"name":"ttb",   "selection": ttb,      "file": loc + "result_"+ttbar+".root", "cx":ttcx, "color": kOrange,  "lineWidth": 4, "label":"t#bar{t}+b        "      },
{"name":"tt2b",  "selection": tt2b,     "file": loc + "result_"+ttbar+".root", "cx":ttcx, "color": kCyan,    "lineWidth": 4, "label":"t#bar{t}+2b      "       },
{"name":"ttcc",  "selection": ttcc,     "file": loc + "result_"+ttbar+".root", "cx":ttcx, "color": kBlue-3,  "lineWidth": 4, "label":"t#bar{t}+c#bar{c}      " },
{"name":"ttlf",  "selection": ttlf,     "file": loc + "result_"+ttbar+".root", "cx":ttcx, "color": kGreen-3, "lineWidth": 4, "label":"t#bar{t}+lf       "      },
{"name":"ttot",  "selection": ttothers, "file": loc + "result_"+ttbar+".root", "cx":ttcx, "color": kViolet,    "lineWidth": 4, "label":"t#bar{t} others"         },

{"name":"STbt",   "selection": "(1)", "file": loc + "result_SingleTbar_t.root",  "cx":80.95,  "color": kGray, "lineWidth": 4, "label":"SingleTop"    },
{"name":"STt",    "selection": "(1)", "file": loc + "result_SingleTop_t.root",   "cx":136.02, "color": kGray, "lineWidth": 4, "label":"SingleTop"    },
{"name":"STbtW",  "selection": "(1)", "file": loc + "result_SingleTbar_tW.root", "cx":35.6,   "color": kGray, "lineWidth": 4, "label":"SingleTop"      },
{"name":"STtW",   "selection": "(1)", "file": loc + "result_SingleTop_tW.root",  "cx":35.6,   "color": kGray, "lineWidth": 4, "label":"SingleTop"      },
{"name":"WJets",  "selection": "(1)", "file": loc + "result_WJets.root",         "cx":61526.7,"color": kGray, "lineWidth": 4, "label":"WJets      "       },
{"name":"WW",     "selection": "(1)", "file": loc + "result_WW.root",            "cx":110.8,  "color": kGray, "lineWidth": 4, "label":"WW          "    },
{"name":"WZ",     "selection": "(1)", "file": loc + "result_WZ.root",            "cx":66.1,   "color": kGray, "lineWidth": 4, "label":"WZ           "   },
{"name":"ZZ",     "selection": "(1)", "file": loc + "result_ZZ.root",            "cx":15.4,   "color": kGray, "lineWidth": 4, "label":"ZZ            "   },
{"name":"DYJets", "selection": "(1)", "file": loc + "result_DYJets.root",        "cx":6025.2, "color": kGray, "lineWidth": 4, "label":"DYJets    "      },

#]
#datasamples=[

{"name":"MuMu", "selection": "(1)", "file": loc + "result_DoubleMuon.root", "color":kBlack, "lineWidth": 4, "label":"DATA     " },
#{"name":"ElEl", "selection": "(1)", "file": loc + "result_DoubleEG.root",   "color":kBlack, "lineWidth": 4, "label":"DATA     " },
#{"name":"MuEl", "selection": "(1)", "file": loc + "result_MuonEG.root",     "color":kBlack, "lineWidth": 4, "label":"DATA     " },

]
