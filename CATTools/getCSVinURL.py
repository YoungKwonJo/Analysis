
from urllib import urlopen
import csv
gdocbase = "https://docs.google.com/spreadsheets/d/1rWM3AlFKO8IJVaeoQkWZYWwSvicQ1QCXYSzH74QyZqE"
#gdocbase = "https://docs.google.com/spreadsheets/d/17pa4b86STpzQA6jPJ1xCOqoovvrL6X0iiuSC8yHO5II"
print "Retrieving dataset info from google doc..."
print "Source URL =", gdocbase
#csvRD = list(csv.reader(urlopen(gdocbase + "/pub?gid=133302812&single=true&output=csv").readlines()))
#csvMC = list(csv.reader(urlopen(gdocbase + "/pub?gid=1289302456&single=true&output=csv").readlines()))
#csvMC = list(csv.reader(urlopen(gdocbase + "/pub?gid=694776205&single=true&output=csv").readlines()))
csvMC = list(csv.reader(urlopen(gdocbase + "/pub?gid=212761185&single=true&output=csv").readlines()))

ds=[]
nameIdx = csvMC[0].index("Name")
titleIdx = csvMC[0].index("Title")
pathIdx = csvMC[0].index("Path")
xsecIdx = csvMC[0].index("Cross section (pb)")
for l in csvMC[1:]:
    if len(l) == 0 or len(l[0]) == 0: continue
    ds.append({'title':l[titleIdx],
               'name':l[nameIdx],
               'xsec':float(l[xsecIdx]),
               'path':l[pathIdx]})

#print ds
www ="samples = [\n"
for i,mc in enumerate(ds) :
  if not (mc['name'].find("QCD")>-1 or mc['name'].find("SingleMuon")>-1 or mc['name'].find("SingleElectron")>-1) :
    eee = "{\"name\": \""  + mc['name'] +"\", "
    if mc['title'].find("Run2015C")==-1:  eee+= "\"xsec\":" + str(mc['xsec'])+", "
    eee+="},\n"
    www+=eee
www+="]"

f = open("samples_cfi.py", "w")
#f.write("import FWCore.ParameterSet.Config as cms\n\n")
f.write(www) 
f.write("\n\n")

