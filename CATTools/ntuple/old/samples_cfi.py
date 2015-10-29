import FWCore.ParameterSet.Config as cms

samples = [
{
"name": "DoubleEG", 
"path": "/store/group/CAT/DoubleEG/v7-4-1_Run2015C-PromptReco-v1/150910_131358", 
"entries": 298,
 },
{
"name": "DoubleMuon", 
"path": "/store/group/CAT/DoubleMuon/v7-4-1_Run2015C-PromptReco-v1/150910_131522", 
"entries": 187,
 },
{
"name": "MuonEG", 
"path": "/store/group/CAT/MuonEG/v7-4-1_Run2015C-PromptReco-v1/150910_151809", 
"entries": 82,
 },
{
"name": "DYJets", 
"path": "/store/group/CAT/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/v7-4-1_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v3/150910_121351", 
"xsec":6025.2, 
"entries": 671,
 },
{
"name": "TTJets_MG5", 
"path": "/store/group/CAT/TTJets_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/v7-4-1_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v2/150910_121520", 
"xsec":832.0, 
"entries": 325,
 },
{
"name": "TTJets_aMC", 
"path": "/store/group/CAT/TTJets_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/v7-4-1_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1/150910_121434", 
"xsec":832.0, 
"entries": 1052,
 },
{
"name": "TT_powheg", 
"path": "/store/group/CAT/TT_TuneCUETP8M1_13TeV-powheg-pythia8/v7-4-1_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v2/150910_121601", 
"xsec":832.0, 
"entries": 493,
 },
{
"name": "WW", 
"path": "/store/group/CAT/WW_TuneCUETP8M1_13TeV-pythia8/v7-4-1_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1/150910_121648", 
"xsec":110.8, 
"entries": 44,
 },
{
"name": "WZ", 
"path": "/store/group/CAT/WZ_TuneCUETP8M1_13TeV-pythia8/v7-4-1_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1/150910_121730", 
"xsec":66.1, 
"entries": 45,
 },
{
"name": "ZZ", 
"path": "/store/group/CAT/ZZ_TuneCUETP8M1_13TeV-pythia8/v7-4-1_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v3/150910_121823", 
"xsec":15.4, 
"entries": 36,
 },
{
"name": "SingleTbar_tW", 
"path": "/store/group/CAT/ST_tW_antitop_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1/v7-4-1_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1/150910_121906", 
"xsec":35.6, 
"entries": 32,
 },
{
"name": "SingleTop_tW", 
"path": "/store/group/CAT/ST_tW_top_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1/v7-4-1_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1/150910_121954", 
"xsec":35.6, 
"entries": 32,
 },
{
"name": "SingleTbar_t", 
"path": "/store/group/CAT/ST_t-channel_antitop_4f_leptonDecays_13TeV-powheg-pythia8_TuneCUETP8M1/v7-4-1_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1/150910_122038", 
"xsec":80.95, 
"entries": 47,
 },
{
"name": "SingleTop_t", 
"path": "/store/group/CAT/ST_t-channel_top_4f_leptonDecays_13TeV-powheg-pythia8_TuneCUETP8M1/v7-4-1_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1/150910_122122/", 
"xsec":136.02, 
"entries": 82,
 },
{
"name": "WJets", 
"path": "/store/group/CAT/WJetsToLNu_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/v7-4-1_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1/150910_122206", 
"xsec":61526.7, 
"entries": 569,
 },
{
"name": "TT_powheg_scaledown", 
"path": "/store/group/CAT/TT_TuneCUETP8M1_13TeV-powheg-scaledown-pythia8/v7-4-1_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1/150910_122251", 
"xsec":815.96, 
"entries": 289,
 },
{
"name": "TT_powheg_scaleup", 
"path": "/store/group/CAT/TT_TuneCUETP8M1_13TeV-powheg-scaleup-pythia8/v7-4-1_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1/150910_122332", 
"xsec":815.96, 
"entries": 306,
 },
{
"name": "TTWJetsToLNu", 
"path": "/store/group/CAT/TTWJetsToLNu_TuneCUETP8M1_13TeV-amcatnloFXFX-madspin-pythia8/v7-4-1_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1/150910_122630", 
"xsec":1.152, 
"entries": 18,
 },
{
"name": "TTWJetsToQQ", 
"path": "/store/group/CAT/TTWJetsToQQ_TuneCUETP8M1_13TeV-amcatnloFXFX-madspin-pythia8/v7-4-1_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1/150910_122545", 
"xsec":1.152, 
"entries": 35,
 },
{
"name": "TTZToLLNuNu", 
"path": "/store/group/CAT/TTZToLLNuNu_M-10_TuneCUETP8M1_13TeV-amcatnlo-pythia8/v7-4-1_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1/150910_122718", 
"xsec":2.232, 
"entries": 16,
 },
{
"name": "TTZToQQ", 
"path": "/store/group/CAT/TTZToQQ_TuneCUETP8M1_13TeV-amcatnlo-pythia8/v7-4-1_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1/150910_122803", 
"xsec":2.232, 
"entries": 32,
 },
{
"name": "ttHToNonbb", 
"path": "/store/group/CAT/ttHToNonbb_M125_13TeV_powheg_pythia8/v7-4-1_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v2/150910_122501", 
"xsec":0.5058, 
"entries": 93,
 },
{
"name": "ttHTobb", 
"path": "/store/group/CAT/ttHTobb_M125_13TeV_powheg_pythia8/v7-4-1_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1/150910_122419", 
"xsec":0.5058, 
"entries": 92,
 },
]


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
