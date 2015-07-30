import FWCore.ParameterSet.Config as cms
import os,sys

#cmsRun run_ntupleMaker_cfg.py 3 >& /tmp/log3.txt &

process = cms.Process("Ana")

process.load("FWCore.MessageLogger.MessageLogger_cfi")
#process.load("Configuration.StandardSequences.Services_cff")
#process.load("SimGeneral.HepPDTESSource.pythiapdt_cfi")

process.options = cms.untracked.PSet( wantSummary = cms.untracked.bool(True) )
#process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(100) )
#process.MessageLogger.cerr.FwkReport.reportEvery = 10000

input =sys.argv[2]
i = int(input)
from mcsample_cfi import mcsamples, my_readFiles 
readFiles=my_readFiles(mcsamples[i])
outputname=mcsamples[i]['name']

process.source = cms.Source("PoolSource",
fileNames = readFiles
#      fileNames = cms.untracked.vstring(
##          'file:catTuple.root',
#'root://cms-xrdr.sdfarm.kr:1094///xrd/store/group/CAT/TTJets_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/v7-3-1_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A-v1/150724_094848/0000/catTuple_1.root',
#      )
)
process.nEventsTotal = cms.EDProducer("EventCountProducer")

process.genTtbarLeptonDecay = cms.EDProducer("GenTtbarLeptonDecay",
    GenParticles = cms.InputTag("prunedGenParticles"),
    GenJets  = cms.InputTag("slimmedGenJets"),
    pt = cms.double(10),
    eta = cms.double(2.5)
)

process.ntuple = cms.EDAnalyzer("GenericNtupleMaker",
    failureMode = cms.untracked.string("error"), # choose one among keep/skip/error
    eventCounters = cms.vstring("nEventsTotal"), #"nEventsTotal", "nEventsClean", "nEventsPAT"),
    #pvLabel = cms.InputTag("offlineSlimmedPrimaryVertices"),
    int = cms.PSet(
        nVertex   = cms.PSet(src = cms.InputTag("recoEventInfo","pvN")),
        HLTDoubleMu = cms.PSet(src = cms.InputTag("recoEventInfo","HLTDoubleMu")),
        HLTDoubleEl = cms.PSet(src = cms.InputTag("recoEventInfo","HLTDoubleEl")),
        HLTMuEl = cms.PSet(src = cms.InputTag("recoEventInfo","HLTMuEl")),
        HLTSingleMu = cms.PSet(src = cms.InputTag("recoEventInfo","HLTSingleMu")),
        HLTSingleEl = cms.PSet(src = cms.InputTag("recoEventInfo","HLTSingleEl")),
        genTtbarId = cms.PSet(src = cms.InputTag("GenTtbarCategories","genTtbarId")),
        genTtbarLeptonDecay = cms.PSet(src = cms.InputTag("genTtbarLeptonDecay","genTtbarLeptonDecayId")),
        NgenJet = cms.PSet(src = cms.InputTag("genTtbarLeptonDecay","NgenJet")),
    ),
    double = cms.PSet(
        puWeight   = cms.PSet(src = cms.InputTag("pileupWeight")),
        puWeightUp = cms.PSet(src = cms.InputTag("pileupWeight", "up")),
        puWeightDn = cms.PSet(src = cms.InputTag("pileupWeight", "dn")),
        pvX   = cms.PSet(src = cms.InputTag("recoEventInfo","pvX")),
        pvY   = cms.PSet(src = cms.InputTag("recoEventInfo","pvY")),
        pvZ   = cms.PSet(src = cms.InputTag("recoEventInfo","pvZ")),
    ),
    doubles = cms.PSet(
        pdfWeight = cms.PSet(src = cms.InputTag("pdfWeight")),
    ),
    cands = cms.PSet(
        muons = cms.PSet(
            src = cms.InputTag("catMuons"),
            #index = cms.untracked.int32(0),
            exprs = cms.untracked.PSet(
                pt  = cms.string("pt"),
                eta = cms.string("eta"),
                phi = cms.string("phi"),
                m   = cms.string("mass"),
                #relIso = cms.string("relIso"),
                relIso03 = cms.string("relIso(0.3)"),
                relIso04 = cms.string("relIso(0.4)"),
                isTracker = cms.string("isTrackerMuon"),
                isGlobal = cms.string("isGlobalMuon"),
                isLoose = cms.string("isLooseMuon"),
                isTight = cms.string("isTightMuon"),
                isPF = cms.string("isPFMuon"),
                dxy = cms.string("dxy"),
                dz = cms.string("dz"),
                normalizedChi2 = cms.string("normalizedChi2"),
                numberOfValidMuonHits = cms.string("numberOfValidMuonHits"),
                numberOfValidPixelHits = cms.string("numberOfValidPixelHits"),
                trackerLayersWithMeasurement = cms.string("trackerLayersWithMeasurement"),
                numberOfMatchedStations = cms.string("numberOfMatchedStations"),
                q = cms.string("charge"),
            ),
            selections = cms.untracked.PSet(),
        ),
        electrons = cms.PSet(
            src = cms.InputTag("catElectrons"),
            #index = cms.untracked.int32(0),
            exprs = cms.untracked.PSet(
                pt  = cms.string("pt"),
                eta = cms.string("eta"),
                phi = cms.string("phi"),
                m   = cms.string("mass"),
                #relIso = cms.string("relIso"),
                idHEEP51 = cms.string("electronID('heepElectronID-HEEPV51')"),
                idLoose = cms.string("electronID('cutBasedElectronID-PHYS14-PU20bx25-V2-standalone-loose')"), 
                idMedium = cms.string("electronID('cutBasedElectronID-PHYS14-PU20bx25-V2-standalone-medium')"), 
                idTight = cms.string("electronID('cutBasedElectronID-PHYS14-PU20bx25-V2-standalone-tight')"), 
                idTeto = cms.string("electronID('cutBasedElectronID-PHYS14-PU20bx25-V2-standalone-veto')"),
                isPassConversionVeto = cms.string("passConversionVeto"),
                isPF = cms.string("isPF"),
                #mva = cms.string("electronID('mvaTrigV0')"),
                relIso03 = cms.string("relIso(0.3)"),
                relIso04 = cms.string("relIso(0.4)"),
                scEta = cms.string("scEta"),
               # dxy = cms.string("dxy"),
               # dz = cms.string("dz"),
                q = cms.string("charge"),
               # isGsfCtfScPixChargeConsistent = cms.string("isGsfCtfScPixChargeConsistent"),
            ),
            selections = cms.untracked.PSet(
                isPassBaseId = cms.string("passConversionVeto && isPF && gsfTrack.hitPattern.numberOfLostHits('MISSING_INNER_HITS') <= 0"),
            ),
        ),
        jets = cms.PSet(
            src = cms.InputTag("catJets"),
            exprs = cms.untracked.PSet(
                pt  = cms.string("pt"),
                eta = cms.string("eta"),
                phi = cms.string("phi"),
                m   = cms.string("mass"),
                vtxMass = cms.string("vtxMass"),
                CSVInclV2 = cms.string("bDiscriminator('pfCombinedInclusiveSecondaryVertexV2BJetTags')"), #com .. phys14, RunIISpring.. pfCom...
                partonFlavour = cms.string("partonFlavour"),
                hadronFlavour = cms.string("hadronFlavour"),
            ),
            selections = cms.untracked.PSet(
                #isLoose = cms.string("LooseId"),
                #isPFId = cms.string("pileupJetId"),
                isPFJETID = cms.string("neutralHadronEnergyFraction<0.99 && chargedEmEnergyFraction<0.99 && neutralEmEnergyFraction<0.99 && numberOfDaughters>1 && chargedHadronEnergyFraction>0.0 && chargedMultiplicity>0 "),
            ),
        ),
        met = cms.PSet(
            src = cms.InputTag("catMETs"),
            exprs = cms.untracked.PSet(
                pt  = cms.string("pt"),
                phi = cms.string("phi"),
            ),
            selections = cms.untracked.PSet(),
        ),
    ),
)

process.TFileService = cms.Service("TFileService",
    fileName = cms.string("ntuple_" + outputname + ".root"),
    #fileName = cms.string("ntuple.root"),
)

process.p = cms.Path(
    process.nEventsTotal*
    process.genTtbarLeptonDecay*
    process.ntuple
)

