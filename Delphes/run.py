#!/usr/bin/env python

import sys,os
 #[filename, name, isttjj, pythia6]
Sample=[
["v20140911_ttbb_test_events_PYTHIA8_0.root",              "ttbb",              "false","false"],
["v20140911_ttbb_test_cut_bq_events_PYTHIA8_0.root",       "ttbb_cut_bq",       "false","false"],
["v20140911_ttbb_woSPIN_test_events_PYTHIA8_0.root",       "ttbb_woSPIN",       "false","false"],
["v20140911_ttbb_woSPIN_test_cut_bq_events_PYTHIA8_0.root","ttbb_woSPIN_cut_bq","false","false"],
["v20140911_tth_test_events_PYTHIA8_0.root",               "tth",               "false","false"],
["v20140911_tth_test_cut_bq_events_PYTHIA8_0.root",        "tth_cut_bq",        "false","false"],
["v20140911_tth_woSPIN_test_events_PYTHIA8_0.root",        "tth_woSPIN",        "false","false"],  
["v20140911_tth_woSPIN_test_cut_bq_events_PYTHIA8_0.root", "tth_woSPIN_cut_bq", "false","false"],
["NLO_TTH_cut_bq_20150331.root",                           "tth2_woSPIN_cut_bq","false","false"],
["v20140911_ttjj_woSPIN_test_events_PYTHIA8_0.root",       "ttjj_woSPIN",       "true", "false"],
["v20140917_ttjj_SPIN_LO.root",                            "ttjj_SPIN_LO",      "true", "true" ],
["ttjj_MG5_pythia6_LO_v20150410.root",                     "ttjj_LO",           "true", "true"],
["ttjj_LO_20150415_tag_1_pythia_events.root",              "ttjj_LO2",          "true", "true"]             
]


for i in range(len(Sample)) :
    cmd = "root -b -q run.C\\(\\\"%s\\\""% Sample[i][0]
    cmd = cmd+",\\\"%s\\\""% Sample[i][1]
#    cmd = cmd+",\\\"MuMu\\\""
    cmd = cmd+",%s"% Sample[i][2]
    cmd = cmd+",%s\\)"% Sample[i][3]
    print cmd
    os.system(cmd)


