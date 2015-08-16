
from urllib import urlopen
import csv
gdocbase = "https://docs.google.com/spreadsheets/d/1rWM3AlFKO8IJVaeoQkWZYWwSvicQ1QCXYSzH74QyZqE"
print "Retrieving dataset info from google doc..."
print "Source URL =", gdocbase
csvRD = list(csv.reader(urlopen(gdocbase + "/pub?gid=0&single=true&output=csv").readlines()))
csvMC = list(csv.reader(urlopen(gdocbase + "/pub?gid=1289302456&single=true&output=csv").readlines()))

ds=[]
nameIdx = csvRD[0].index("Name")
titleIdx = csvRD[0].index("Title")
pathIdx = csvRD[0].index("Path")
lumiIdx = csvRD[0].index("Integrated luminosity (pb-1)")
for l in csvRD[1:]:
    if len(l) == 0 or len(l[0]) == 0: continue
    ds.append({'title':l[titleIdx],
               'name':l[nameIdx],
               'lumi':float(l[lumiIdx]),
               'path':l[pathIdx]})

nameIdx = csvMC[0].index("Name")
titleIdx = csvMC[0].index("Title")
pathIdx = csvMC[0].index("Path")
xsecIdx = csvMC[0].index("Cross section (pb)")
nevtIdx = csvMC[0].index("NEvent")
for l in csvMC[1:]:
    if len(l) == 0 or len(l[0]) == 0: continue
    ds.append({'title':l[titleIdx],
               'name':l[nameIdx],
               'xsec':float(l[xsecIdx]),
               'nevt':int(l[nevtIdx]),
               'path':l[pathIdx]})

#print ds
import os,commands

lcgls="lcg-ls -v -b -T srmv2 -D srmv2 --vo cms srm://cms-se.sdfarm.kr:8443/srm/v2/server?SFN=/xrootd"
www ="samples = [\n"
for i,mc in enumerate(ds) :
  bbb = (lcgls + mc['path'] + "/0000/" + " | grep -c catTuple ")
  #print bbb
  ddd = commands.getoutput(bbb)
  eee = "{\n\"name\": \""  + mc['name'] +"\", \n"
  eee+= "\"path\": \""  + mc['path'] +"\", \n"
  #print mc.keys()
  if 'xsec' in mc.keys():  eee+= "\"xsec\":" + str(mc['xsec'])+", \n"
  eee+= "\"entries\": "     + ddd + " \n},\n"

  www+=eee
www+="]"

vvv="""
def my_readFiles(sample):
  aaa = []
  for i in range(1,sample['entries']+1) :
    bbb= "root://cms-xrdr.sdfarm.kr:1094///xrd" + mcsample['path'] + "/0000/catTuple_"
    bbb+="%d" % (i)
    bbb+=".root"
    print bbb
    aaa.append(bbb)

  readFiles = cms.untracked.vstring()
  readFiles.extend(aaa);

  return readFiles
"""

f = open("samples_cfi.py", "w")
f.write("import FWCore.ParameterSet.Config as cms\n\n")
f.write(www) 
f.write("\n\n"+vvv)

