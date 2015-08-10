import FWCore.ParameterSet.Config as cms

kisti = "root://cms-xrdr.sdfarm.kr:1094///xrd"
mcsamples =[
{
"name": "zjet_amcatnloFXFX_pythia8",
"location": "/store/group/CAT/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/v7-3-1_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A-v2/",
"subfolder": "150724_094819",
"entries": 491
},
{
"name": "ttjets_madgraph_pythia8",
"location": "/store/group/CAT/TTJets_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/v7-3-1_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A-v1/",
"subfolder": "150724_094848",
"entries": 150
},
{
"name": "ttjets_amcatnloFXFX_pythia8",
"location": "/store/group/CAT/TTJets_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/v7-3-1_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A-v1/",
"subfolder": "150724_094914",
"entries": 123
},
{
"name": "TT_powheg_pythia8",
"location": "/store/group/CAT/TT_TuneCUETP8M1_13TeV-powheg-pythia8/v7-3-1_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A-v4/",
"subfolder": "150724_094945",
"entries": 447
},
{
"name": "WW_pythia8",
"location": "/store/group/CAT/WW_TuneCUETP8M1_13TeV-pythia8/v7-3-1_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A-v1/",
"subfolder": "150724_095009",
"entries": 47
},
{
"name": "WZ_pythia8",
"location": "/store/group/CAT/WZ_TuneCUETP8M1_13TeV-pythia8/v7-3-1_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A-v2/",
"subfolder": "150724_095037",
"entries": 41
},
{
"name": "ZZ_pythia8",
"location": "/store/group/CAT/ZZ_TuneCUETP8M1_13TeV-pythia8/v7-3-1_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A-v2/",
"subfolder": "150724_095106",
"entries": 35
},
{
"name": "ST_tW_antitop_powheg_pythia8",
"location": "/store/group/CAT/ST_tW_antitop_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1/v7-3-1_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A-v2/",
"subfolder": "150724_095133",
"entries": 22
},
{
"name": "ST_tW_top_powheg_pythia8",
"location": "/store/group/CAT/ST_tW_top_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1/v7-3-1_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A-v1/",
"subfolder": "150724_095202",
"entries": 31
},
{
"name": "ST_t_antitop_powheg_pythia8",
"location": "/store/group/CAT/ST_t-channel_antitop_4f_leptonDecays_13TeV-powheg-pythia8_TuneCUETP8M1/v7-3-1_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A-v1/",
"subfolder": "150724_095228",
"entries": 20
},
{
"name": "ST_t_top_powheg_pythia8",
"location": "/store/group/CAT/ST_t-channel_top_4f_leptonDecays_13TeV-powheg-pythia8_TuneCUETP8M1/v7-3-1_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A-v1/",
"subfolder": "150724_095255",
"entries": 26
},
{
"name": "WJetsToLNu_amcatnloFXFX_pythia8",
"location": "/store/group/CAT/WJetsToLNu_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/v7-3-1_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A-v1/",
"subfolder": "150724_095324",
"entries": 634
},
{
"name": "TT_powheg_scaledown_pythia8",
"location": "/store/group/CAT/TT_TuneCUETP8M1_13TeV-powheg-scaledown-pythia8/v7-3-1_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A-v1/",
"subfolder": "150724_095353",
"entries": 55
},
{
"name": "TT_powheg_scaleup_pythia8",
"location": "/store/group/CAT/TT_TuneCUETP8M1_13TeV-powheg-scaleup-pythia8/v7-3-1_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A-v3/",
"subfolder": "150724_095419",
"entries": 64
}
]

datasamples =[
{
 "name": "DoubleMuon_Run2015B",
"location": "/store/group/CAT/DoubleMuon/v7-3-1_Run2015B-PromptReco-v1/",
"subfolder": "150724_094546",
"entries": 117
},
{
 "name": "DoubleEG_Run2015B",
"location": "/store/group/CAT/DoubleEG/v7-3-1_Run2015B-PromptReco-v1/",
"subfolder": "150724_094516",
"entries": 117
},
{
 "name": "DoubleMuon_Run2015B",
"location": "/store/group/CAT/MuonEG/v7-3-1_Run2015B-PromptReco-v1/",
"subfolder": "150724_094612",
"entries": 117
},
]

def my_readFiles(mcsample):
  aaa = []
  for i in range(1,mcsample['entries']+1) :
    bbb= "root://cms-xrdr.sdfarm.kr:1094///xrd" + mcsample['location'] + mcsample['subfolder'] + "/0000/catTuple_"
    bbb+="%d" % (i)
    bbb+=".root"
    print bbb
    aaa.append(bbb)

  readFiles = cms.untracked.vstring()
  readFiles.extend(aaa);

  return readFiles

