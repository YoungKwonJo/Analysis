#!/usr/bin/env python

import sys,os

Sample=["v20140911_ttbb_test_events_PYTHIA8_0.root",
"v20140911_ttbb_test_cut_bq_events_PYTHIA8_0.root",
"v20140911_ttbb_woSPIN_test_events_PYTHIA8_0.root",
"v20140911_ttbb_woSPIN_test_cut_bq_events_PYTHIA8_0.root",
"v20140911_tth_test_events_PYTHIA8_0.root",
"v20140911_tth_test_cut_bq_events_PYTHIA8_0.root",
"v20140911_tth_woSPIN_test_events_PYTHIA8_0.root",
"v20140911_ttjj_woSPIN_test_events_PYTHIA8_0.root",
"v20140911_tth_woSPIN_test_cut_bq_events_PYTHIA8_0.root",
"v20140917_ttjj_SPIN_LO.root"]

Sample2 = [
  "ttbb_test","ttbb_test_cut_bq",
  "ttbb_woSPIN_test","ttbb_woSPIN_test_cut_bq",
  "tth_test","tth_test_cut_bq",
  "tth_woSPIN_test","tth_woSPIN_test_cut_bq",
  "ttjj_woSPIN_test","ttjj_SPIN_LO" 
]
isttjj = [
    "false","false",
    "false","false",
    "false","false",
    "false","false",
    "true","true"
]
pythia6 = [
    "false","false",
    "false","false",
    "false","false",
    "false","false",
    "false","true"
]


for i in range(len(Sample)) :
    cmd = "root -b -q run.C\\(\\\"%s\\\""% Sample[i]
    cmd = cmd+",\\\"%s\\\""% Sample2[i]
#    cmd = cmd+",\\\"MuMu\\\""
    cmd = cmd+",%s"% isttjj[i]
    cmd = cmd+",%s\\)"% pythia6[i]
    print cmd
    os.system(cmd)


