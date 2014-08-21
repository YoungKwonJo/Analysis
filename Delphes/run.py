#!/usr/bin/env python

import sys,os

Sample = [
  "ttbb_loop_sm","ttbb_loop_sm_cut_bq",
  "tth_loop_sm","tth_loop_sm_cut_bq"
]


for i in range(len(Sample)) :
    cmd = "root -b -q run.C\\(\\\"%s\\\"\\)"% Sample[i]
#    cmd = cmd+",\\\"MuMu\\\""
#    cmd = cmd+",true\\)"
    print cmd
    os.system(cmd)


