#!/usr/bin/env python

import sys,os

Sample = ["DYJetsToLL_M-10To50filter_8TeV-madgraph","DYJetsToLL_M-50_TuneZ2Star_8TeV-madgraph-tarball"]#,
#"TTJets_FullLeptMGDecays_8TeV-madgraph-tauola","TTJets_HadronicMGDecays_8TeV-madgraph","TTJets_SemiLeptMGDecays_8TeV-madgraph-tauola",
#"T_tW-channel-DR_TuneZ2star_8TeV-powheg-tauola","Tbar_tW-channel-DR_TuneZ2star_8TeV-powheg-tauola",
#"WJetsToLNu_TuneZ2Star_8TeV-madgraph-tarball","WW_TuneZ2star_8TeV_pythia6_tauola",
#"WZ_TuneZ2star_8TeV_pythia6_tauola","ZZ_TuneZ2star_8TeV_pythia6_tauola"]

sSample = ["DY","DY",
           "TT2l","TThad","TT1l",
           "ST","ST", # "TtW","TbartW"
           "Wj","VV", # WW
           "VV","VV"] # WZ, ZZ
CX = [860.5,3503,
      27.2,108.8,108.8,
      11.1,11.1,
      37509,54.8,
      33.21,8.059]

isZ = [1,2,
       0,0,0,
       0,0,
       0,0,
       0,0]
v = [1,1,
       5,1,1,
       1,1,
       1,1,
       1,1]

for i in range(len(Sample)) :
    cmd = "root -l run.C\\(\\\"%s\\\""% Sample[i]
    cmd = cmd+",\\\"%s\\\""% sSample[i]
    cmd = cmd+",%f"% CX[i]
    cmd = cmd+",%d"% isZ[i]
    cmd = cmd+",%d"% v[i]
    cmd = cmd+",true\\)"
    print cmd
    os.system(cmd)

