
from ROOT import *

loc = "/Volumes/MYSD/CATTools/ttbb_20150730/plots/"

mcsamples=[

{"name":"ttbb",  "selection": "(Category==2)", "file": loc + "result_ttbar.root", "cx":1., "color": kRed,     "lineWidth": 2, "label":"t#bar{t}+b#bar{b}"    },
{"name":"ttb",   "selection": "(Category==4)", "file": loc + "result_ttbar.root", "cx":1., "color": kOrange,  "lineWidth": 2, "label":"t#bar{t}+b"           },
{"name":"tt2b",  "selection": "(Category==3)", "file": loc + "result_ttbar.root", "cx":1., "color": kCyan,    "lineWidth": 2, "label":"t#bar{t}+2b"          },
{"name":"ttcc",  "selection": "(Category==1)", "file": loc + "result_ttbar.root", "cx":1., "color": kBlue-3,  "lineWidth": 2, "label":"t#bar{t}+c#bar{c}"    },
{"name":"ttlf",  "selection": "(Category==0)", "file": loc + "result_ttbar.root", "cx":1., "color": kGreen-3, "lineWidth": 2, "label":"t#bar{t}+lf"          }

]

