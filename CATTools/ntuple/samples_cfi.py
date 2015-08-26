import FWCore.ParameterSet.Config as cms

samples = [
{
"name": "DYJets", 
"path": "/store/group/CAT/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/v7-3-6_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A-v2/150820_215635", 
"xsec":6025.2, 
"entries": 491 
},
{
"name": "TTJets_MG5", 
"path": "/store/group/CAT/TTJets_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/v7-3-6_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A-v1/150820_215713", 
"xsec":815.96, 
"entries": 150 
},
{
"name": "TTJets_aMC", 
"path": "/store/group/CAT/TTJets_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/v7-3-6_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A-v1/150820_215739", 
"xsec":815.96, 
"entries": 123 
},
{
"name": "TT_powheg", 
"path": "/store/group/CAT/TT_TuneCUETP8M1_13TeV-powheg-pythia8/v7-3-6_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A-v4/150820_215807", 
"xsec":815.96, 
"entries": 447 
},
{
"name": "WW", 
"path": "/store/group/CAT/WW_TuneCUETP8M1_13TeV-pythia8/v7-3-6_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A-v1/150820_215830", 
"xsec":110.8, 
"entries": 47 
},
{
"name": "WZ", 
"path": "/store/group/CAT/WZ_TuneCUETP8M1_13TeV-pythia8/v7-3-6_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A-v2/150820_215857", 
"xsec":66.1, 
"entries": 41 
},
{
"name": "ZZ", 
"path": "/store/group/CAT/ZZ_TuneCUETP8M1_13TeV-pythia8/v7-3-6_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A-v2/150820_215925", 
"xsec":15.4, 
"entries": 35 
},
{
"name": "SingleTbar_tW", 
"path": "/store/group/CAT/ST_tW_antitop_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1/v7-3-6_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A-v2/150821_101929", 
"xsec":35.6, 
"entries": 22 
},
{
"name": "SingleTop_tW", 
"path": "/store/group/CAT/ST_tW_top_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1/v7-3-6_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A-v1/150821_101953", 
"xsec":35.6, 
"entries": 31 
},
{
"name": "SingleTbar_t", 
"path": "/store/group/CAT/ST_t-channel_antitop_4f_leptonDecays_13TeV-powheg-pythia8_TuneCUETP8M1/v7-3-6_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A-v1/150820_220037", 
"xsec":80.95, 
"entries": 20 
},
{
"name": "SingleTop_t", 
"path": "/store/group/CAT/ST_t-channel_top_4f_leptonDecays_13TeV-powheg-pythia8_TuneCUETP8M1/v7-3-6_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A-v1/150820_220100", 
"xsec":136.02, 
"entries": 26 
},
{
"name": "WJets", 
"path": "/store/group/CAT/WJetsToLNu_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/v7-3-6_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A-v1/150820_220130", 
"xsec":61526.7, 
"entries": 633 
},
{
"name": "TT_powheg_scaledown", 
"path": "/store/group/CAT/TT_TuneCUETP8M1_13TeV-powheg-scaledown-pythia8/v7-3-6_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A-v1/150820_220153", 
"xsec":815.96, 
"entries": 55 
},
{
"name": "TT_powheg_scaleup", 
"path": "/store/group/CAT/TT_TuneCUETP8M1_13TeV-powheg-scaleup-pythia8/v7-3-6_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A-v3/150820_220216", 
"xsec":815.96, 
"entries": 64 
},
]


def my_readFiles(sample):
  aaa = []
  for i in range(1,sample['entries']+1) :
    bbb= "root://cms-xrdr.sdfarm.kr:1094///xrd" + sample['path'] + "/0000/catTuple_"
    bbb+="%d" % (i)
    bbb+=".root"
    print bbb
    aaa.append(bbb)

  readFiles = cms.untracked.vstring()
  readFiles.extend(aaa);

  return readFiles
