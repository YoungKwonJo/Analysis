
from urllib import urlopen
import csv
#gdocbase = "https://docs.google.com/spreadsheets/d/1rWM3AlFKO8IJVaeoQkWZYWwSvicQ1QCXYSzH74QyZqE"
gdocbase = "https://docs.google.com/spreadsheets/d/17pa4b86STpzQA6jPJ1xCOqoovvrL6X0iiuSC8yHO5II"
print "Retrieving dataset info from google doc..."
print "Source URL =", gdocbase
#csvRD = list(csv.reader(urlopen(gdocbase + "/pub?gid=0&single=true&output=csv").readlines()))
csvRD = list(csv.reader(urlopen(gdocbase + "/pub?gid=133302812&single=true&output=csv").readlines()))
#csvMC = list(csv.reader(urlopen(gdocbase + "/pub?gid=1289302456&single=true&output=csv").readlines()))
csvMC = list(csv.reader(urlopen(gdocbase + "/pub?gid=694776205&single=true&output=csv").readlines()))

ds=[]
nameIdx = csvRD[0].index("Name")
titleIdx = csvRD[0].index("Title")
pathIdx = csvRD[0].index("Path")
#lumiIdx = csvRD[0].index("Integrated luminosity (pb-1)")
for l in csvRD[1:]:
    if len(l) == 0 or len(l[0]) == 0: continue
    ds.append({'title':l[titleIdx],
               'name':l[nameIdx],
#               'lumi':float(l[lumiIdx]),
               'path':l[pathIdx]})

nameIdx = csvMC[0].index("Name")
titleIdx = csvMC[0].index("Title")
pathIdx = csvMC[0].index("Path")
#path2Idx = csvMC[0].index("Path2")
xsecIdx = csvMC[0].index("Cross section (pb)")
#nevtIdx = csvMC[0].index("NEvent")
for l in csvMC[1:]:
    if len(l) == 0 or len(l[0]) == 0: continue
    ds.append({'title':l[titleIdx],
               'name':l[nameIdx],
               'xsec':float(l[xsecIdx]),
#               'nevt':int(l[nevtIdx]),
#               'path2':l[path2Idx],
               'path':l[pathIdx]})

#print ds
import os,commands

lcgls="lcg-ls -v -b -T srmv2 -D srmv2 --vo cms srm://cms-se.sdfarm.kr:8443/srm/v2/server?SFN=/xrootd"
cat = "/store/group/CAT/"
cat2 = "/store/"

def getEntries(lcgls_,Idx_):
  aaa = (lcgls_+" | grep -c \/00")
  aaa2= commands.getoutput(aaa)
  if int(aaa2)<=Idx_: return 0

  bbb = (lcgls_+"/000"+str(Idx_)+"/ | grep -c catTuple ")
  #print bbb
  ddd= commands.getoutput(bbb)
  ddd2= int(ddd)
  if ddd2==999: ddd2+=getEntries(lcgls_,Idx_+1)
  return ddd2

www ="samples = [\n"
for i,mc in enumerate(ds) :
  bbb = getEntries(lcgls +cat+ mc['path'],0)
  #print "path2 ; "+str(mc.has_key('path2'))
  eee = "{\n\"name\": \""  + mc['name'] +"\", \n"
  eee+= "\"path\": \""  +cat+ mc['path'] +"\", \n"
  #print mc.keys()
  if 'xsec' in mc.keys():  eee+= "\"xsec\":" + str(mc['xsec'])+", \n"
  eee+= "\"entries\": "     + str(bbb) + ",\n "
#  if mc.has_key('path2') and len(mc['path2'])>0: 
#    bbb2 = getEntries(lcgls +cat2+ mc['path2'],0)
#    eee+= "\"path2\": \""  +cat2+ mc['path2'] +"\", \n"
#    eee+= "\"entries2\": "     + str(bbb2) + ", \n "
  eee+="},\n"

  www+=eee
www+="]"

vvv="""
def my_readFiles(sample):
  aaa = []
  for i in range(1,sample['entries']+1) :
    ii = round(i/1000)
    bbb= "root://cms-xrdr.sdfarm.kr:1094///xrd" + sample['path'] + ("/000%d"%ii)+"/catTuple_"

    bbb+="%d" % (i)
    bbb+=".root"
    print bbb
    aaa.append(bbb)

  readFiles = cms.untracked.vstring()
  readFiles.extend(aaa);

  return readFiles
"""
vvv2="""
def my_2ndreadFiles(sample):
  aaa = []
  for i in range(1,sample['entries2']+1) :
    ii = round(i/1000)
    bbb= "root://cms-xrdr.sdfarm.kr:1094///xrd" + sample['path2'] + ("/000%d"%ii)+"/catTuple_GenTop_"

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

