#!/usr/bin/env python

import sys,os
 #[filename, name, isttjj, pythia6]
Sample=[
["LO_ttjj_8TeV_20150416_tag_1_pythia_events.root", "ttjj_LO", "true","true"  ],
["NLO_ttbb_8TeV_20150416_events_PYTHIA8.root",     "ttbb_NLO", "false","false"],
["NLO_tth_8TeV_20150416_events_PYTHIA8.root",      "tth_NLO",  "false","false"]  
]

for i in range(len(Sample)) :
    cmd = "root -b -q run8TeV.C\\(\\\"%s\\\""% Sample[i][0]
    cmd = cmd+",\\\"%s\\\""% Sample[i][1]
#    cmd = cmd+",\\\"MuMu\\\""
    cmd = cmd+",%s"% Sample[i][2]
    cmd = cmd+",%s\\)"% Sample[i][3]
    print cmd
    os.system(cmd)


