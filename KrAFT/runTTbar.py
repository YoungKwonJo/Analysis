#!/usr/bin/env python

import sys,os


#isTest = True
isTest = False

Sample = ["TTJets_FullLeptMGDecays_8TeV-madgraph-tauola"]#,"TTTo2L2Nu2B_8TeV-powheg-pythia6","TT_8TeV-mcatnlo"]

#ttbar for pp 8TeV
#245*Br :
#dilepton -> 27.2
#lepton+jet -> 108.8
#hadronic -> 108.8

sSample = ["TTm","TTp","TTat"] # WZ, ZZ
CX = [ 27.2, 27.2, 245]

isZ = [0,0,0]
v = [5,5,5]

for i in range(len(Sample)) :
    cmd = "root -b -q run.C\\(\\\"%s\\\""% Sample[i]
    cmd = cmd+",\\\"%s\\\""% sSample[i]
    cmd = cmd+",%f"% CX[i]
    cmd = cmd+",%d"% isZ[i]
    cmd = cmd+",%d"% v[i]
    cmd = cmd+",\\\"MuMu\\\""
    cmd = cmd+",true\\)"
    print cmd
    os.system(cmd)

if isTest==True:    sys.exit(0)

for i in range(len(Sample)) :
    cmd = "root -b -q run.C\\(\\\"%s\\\""% Sample[i]
    cmd = cmd+",\\\"%s\\\""% sSample[i]
    cmd = cmd+",%f"% CX[i]
    cmd = cmd+",%d"% isZ[i]
    cmd = cmd+",%d"% v[i]
    cmd = cmd+",\\\"ElEl\\\""
    cmd = cmd+",true\\)"
    print cmd
    os.system(cmd)

for i in range(len(Sample)) :
    cmd = "root -b -q run.C\\(\\\"%s\\\""% Sample[i]
    cmd = cmd+",\\\"%s\\\""% sSample[i]
    cmd = cmd+",%f"% CX[i]
    cmd = cmd+",%d"% isZ[i]
    cmd = cmd+",%d"% v[i]
    cmd = cmd+",\\\"MuEl\\\""
    cmd = cmd+",true\\)"
    print cmd
    os.system(cmd)

