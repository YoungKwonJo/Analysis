
from ROOT import *

loc = "/Volumes/MYSD/CATTools/ttbb_20150730/plots/"

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

{"name":"ttbb",  "selection": ttbb, "file": loc + "result_ttbar.root", "cx":1., "color": kRed,     "lineWidth": 4, "label":"t#bar{t}+b#bar{b}      " },
{"name":"ttb",   "selection": ttb,  "file": loc + "result_ttbar.root", "cx":1., "color": kOrange,  "lineWidth": 4, "label":"t#bar{t}+b        "      },
{"name":"tt2b",  "selection": tt2b, "file": loc + "result_ttbar.root", "cx":1., "color": kCyan,    "lineWidth": 4, "label":"t#bar{t}+2b      "       },
{"name":"ttcc",  "selection": ttcc, "file": loc + "result_ttbar.root", "cx":1., "color": kBlue-3,  "lineWidth": 4, "label":"t#bar{t}+c#bar{c}      " },
{"name":"ttlf",  "selection": ttlf, "file": loc + "result_ttbar.root", "cx":1., "color": kGreen-3, "lineWidth": 4, "label":"t#bar{t}+lf       "  },
{"name":"ttot",  "selection": ttothers, "file": loc + "result_ttbar.root", "cx":1., "color": kGray, "lineWidth": 4, "label":"t#bar{t} others"    }

]

