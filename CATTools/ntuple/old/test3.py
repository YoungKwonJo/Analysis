import os,commands


lcgls="lcg-ls -v -b -T srmv2 -D srmv2 --vo cms srm://cms-se.sdfarm.kr:8443/srm/v2/server?SFN=/xrootd"
subfolder="150724_094848/0000/"

mcsamples = [
{
"name"     :"DoubleMuon_Run2015B",
"location" :"/store/group/CAT/DoubleMuon/v7-3-1_Run2015B-PromptReco-v1/",
"subfolder":"150724_094546",
},
{
"name"     :"DoubleEG_Run2015B",
"location" :"/store/group/CAT/DoubleEG/v7-3-1_Run2015B-PromptReco-v1/",
"subfolder":"150724_094516",
},
{
"name"     :"DoubleMuon_Run2015B",
"location" :"/store/group/CAT/MuonEG/v7-3-1_Run2015B-PromptReco-v1/",
"subfolder":"150724_094612",
},
]


#bbb="group/CAT/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/v7-3-1_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A-v2/150724_094819/0000"
#ccc=(aaa + bbb + " | grep -c catTuple")
#os.system(ccc)
#ddd = commands.getoutput(ccc) 
#print ddd

www =""
for i,mc in enumerate(mcsamples) :
  bbb = (lcgls + mc['location'] + mc['subfolder'] + "/0000/" + " | grep -c catTuple ")
  #print bbb
  ddd = commands.getoutput(bbb)
  eee = "{\n \"name\": \""  + mc['name'] +"\", \n" 
  eee+= "\"location\": \""  + mc['location'] +"\", \n"
  eee+= "\"subfolder\": \"" + mc['subfolder'] +"\", \n"
  eee+= "\"entries\": "     + ddd + " \n},\n"

  www+=eee

print www
