import os,commands


lcgls="lcg-ls -v -b -T srmv2 -D srmv2 --vo cms srm://cms-se.sdfarm.kr:8443/srm/v2/server?SFN=/xrootd"
subfolder="150724_094848/0000/"

mcsamples = [
{
"name"     :"zjet_amcatnloFXFX_pythia8",
"location" :"/store/group/CAT/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/v7-3-1_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A-v2/",
"subfolder":"150724_094819",
},
{
"name"     :"ttjets_madgraph_pythia8",        
"location" :"/store/group/CAT/TTJets_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/v7-3-1_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A-v1/",
"subfolder":"150724_094848",
},
{
"name"     :"ttjets_amcatnloFXFX_pythia8",    
"location" :"/store/group/CAT/TTJets_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/v7-3-1_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A-v1/",
"subfolder":"150724_094914",
},
{
"name"     :"TT_powheg_pythia8",              
"location" :"/store/group/CAT/TT_TuneCUETP8M1_13TeV-powheg-pythia8/v7-3-1_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A-v4/",
"subfolder":"150724_094945",
},
{
"name"     :"WW_pythia8",                     
"location" :"/store/group/CAT/WW_TuneCUETP8M1_13TeV-pythia8/v7-3-1_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A-v1/",
"subfolder":"150724_095009",
},
{
"name"     :"WZ_pythia8",                     
"location" :"/store/group/CAT/WZ_TuneCUETP8M1_13TeV-pythia8/v7-3-1_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A-v2/",
"subfolder":"150724_095037",
},
{
"name"     :"ZZ_pythia8",                     
"location" :"/store/group/CAT/ZZ_TuneCUETP8M1_13TeV-pythia8/v7-3-1_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A-v2/",
"subfolder":"150724_095106",
},
{
"name"     :"ST_tW_antitop_powheg_pythia8",   
"location" :"/store/group/CAT/ST_tW_antitop_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1/v7-3-1_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A-v2/",
"subfolder":"150724_095133",
},
{
"name"     :"ST_tW_top_powheg_pythia8",       
"location" :"/store/group/CAT/ST_tW_top_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1/v7-3-1_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A-v1/",
"subfolder":"150724_095202",
},
{
"name"     :"ST_t_antitop_powheg_pythia8",    
"location" :"/store/group/CAT/ST_t-channel_antitop_4f_leptonDecays_13TeV-powheg-pythia8_TuneCUETP8M1/v7-3-1_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A-v1/",
"subfolder":"150724_095228",
},
{
"name"     :"ST_t_top_powheg_pythia8",        
"location" :"/store/group/CAT/ST_t-channel_top_4f_leptonDecays_13TeV-powheg-pythia8_TuneCUETP8M1/v7-3-1_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A-v1/",
"subfolder":"150724_095255",
},
{
"name"     :"WJetsToLNu_amcatnloFXFX_pythia8",
"location" :"/store/group/CAT/WJetsToLNu_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/v7-3-1_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A-v1/",
"subfolder":"150724_095324",
},
{
"name"     :"TT_powheg_scaledown_pythia8",    
"location" :"/store/group/CAT/TT_TuneCUETP8M1_13TeV-powheg-scaledown-pythia8/v7-3-1_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A-v1/",
"subfolder":"150724_095353",
},
{
"name"     :"TT_powheg_scaleup_pythia8",      
"location" :"/store/group/CAT/TT_TuneCUETP8M1_13TeV-powheg-scaleup-pythia8/v7-3-1_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A-v3/",
"subfolder":"150724_095419",
}
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
