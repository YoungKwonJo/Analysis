import FWCore.ParameterSet.Config as cms
import os

process = cms.Process("Ana")

process.load("FWCore.MessageLogger.MessageLogger_cfi")
#process.load("Configuration.StandardSequences.Services_cff")
#process.load("SimGeneral.HepPDTESSource.pythiapdt_cfi")

process.options = cms.untracked.PSet( wantSummary = cms.untracked.bool(True) )
#process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(100) )
#process.MessageLogger.cerr.FwkReport.reportEvery = 10000

process.source = cms.Source("PoolSource",
      fileNames = cms.untracked.vstring(
#'/store/user/youn/cat710_phy14_ttbar_2025_aod/catTuple_972.root'
'file:catTuple.root'
#          '/store/user/jlee/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/Phys14DR-PU20bx25_PHYS14_25_V1-v1/141219_091640/0000/catTuple_1.root',
#          '/store/user/jlee/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/Phys14DR-PU20bx25_PHYS14_25_V1-v1/141219_091640/0000/catTuple_2.root',
#          '/store/user/jlee/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/Phys14DR-PU20bx25_PHYS14_25_V1-v1/141219_091640/0000/catTuple_3.root',
#          '/store/user/jlee/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/Phys14DR-PU20bx25_PHYS14_25_V1-v1/141219_091640/0000/catTuple_4.root',
#          '/store/user/jlee/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/Phys14DR-PU20bx25_PHYS14_25_V1-v1/141219_091640/0000/catTuple_5.root',
      )
)

#int                                   "recoEventInfo"             "HLTDoubleMu"     "CAT"
process.ntuple = cms.EDAnalyzer("GenericNtupleMaker",
    failureMode = cms.untracked.string("error"), # choose one among keep/skip/error
    eventCounters = cms.vstring(), #"nEventsTotal", "nEventsClean", "nEventsPAT"),
    int = cms.PSet(
        nVertex   = cms.PSet(src = cms.InputTag("recoEventInfo","pvN")),
        HLTDoubleMu = cms.PSet(src = cms.InputTag("recoEventInfo","HLTDoubleMu")),
        HLTDoubleEl = cms.PSet(src = cms.InputTag("recoEventInfo","HLTDoubleEl")),
        HLTMuEl = cms.PSet(src = cms.InputTag("recoEventInfo","HLTMuEl")),
        HLTMuJet = cms.PSet(src = cms.InputTag("recoEventInfo","HLTMuJet")),
        HLTELJet = cms.PSet(src = cms.InputTag("recoEventInfo","HLTELJet")),
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
        muon = cms.PSet(
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
                dxy = cms.string("dxy"),
                dz = cms.string("dz"),
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
                idLoose = cms.string("electronID('eidLoose')"),
                idTight = cms.string("electronID('eidTight')"),
                #mva = cms.string("electronID('mvaTrigV0')"),
                relIso03 = cms.string("relIso(0.3)"),
                relIso04 = cms.string("relIso(0.4)"),
                scEta = cms.string("scEta"),
                dxy = cms.string("dxy"),
                dz = cms.string("dz"),
                q = cms.string("charge"),
                isGsfCtfScPixChargeConsistent = cms.string("isGsfCtfScPixChargeConsistent"),
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
                CSVInclV2 = cms.string("bDiscriminator('combinedInclusiveSecondaryVertexV2BJetTags')"),
                partonFlavour = cms.string("partonFlavour"),
                hadronFlavour = cms.string("hadronFlavour"),
            ),
            selections = cms.untracked.PSet(
                isLoose = cms.string("LooseId"),
                isPFId = cms.string("pileupJetId"),
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
        gentop = cms.PSet(
            src = cms.InputTag("catGenTops"),
            #index = cms.untracked.int32(0),
            exprs = cms.untracked.PSet(
                lepton1_pt      = cms.string("lepton1().Pt()"),
                lepton1_eta      = cms.string("lepton1().Eta()"),
                lepton2_pt      = cms.string("lepton2().Pt()"),
                lepton2_eta      = cms.string("lepton2().Eta()"),
                allHadronic      = cms.string("allHadronic"),
                semiLeptonic     = cms.string("semiLeptonic"),
                diLeptonicMuoMuo = cms.string("diLeptonicMuoMuo"),
                diLeptonicMuoEle = cms.string("diLeptonicMuoEle"),
                diLeptonicEleEle = cms.string("diLeptonicEleEle"),
                diLeptonicTauMuo = cms.string("diLeptonicTauMuo"),
                diLeptonicTauEle = cms.string("diLeptonicTauEle"),
                diLeptonicTauTau = cms.string("diLeptonicTauTau"),
                NbJets           = cms.string("NbJets(0)"),
                NbJets20         = cms.string("NbJets20(0)"),
                NbJets25         = cms.string("NbJets25(0)"),
                NbJets30         = cms.string("NbJets30(0)"),
                NbJets40         = cms.string("NbJets40(0)"),
                NaddbJets        = cms.string("NaddbJets(0)"),
                NaddbJets20      = cms.string("NaddbJets20(0)"),
                NaddbJets40      = cms.string("NaddbJets40(0)"),
                NcJets           = cms.string("NcJets(0)"),
                NcJets10         = cms.string("NcJets10(0)"),
                NcJets15         = cms.string("NcJets15(0)"),
                NcJets20         = cms.string("NcJets20(0)"),
                NcJets25         = cms.string("NcJets25(0)"),
                NcJets30         = cms.string("NcJets30(0)"),
                NcJets40         = cms.string("NcJets40(0)"),
                NJets            = cms.string("NJets"),
                NJets10          = cms.string("NJets10"),
                NJets20          = cms.string("NJets20"),
                NJets25          = cms.string("NJets25"),
                NJets30          = cms.string("NJets30"),
                NJets40          = cms.string("NJets40"),
                NaddJets20       = cms.string("NaddJets20"),
                NaddJets40       = cms.string("NaddJets40"),
                NbQuarksTop      = cms.string("NbQuarksTop"),
                NbQuarksNoTop    = cms.string("NbQuarksNoTop"),
                NbQuarks         = cms.string("NbQuarks"),
                NbQuarks20       = cms.string("NbQuarks20"),
                NbQuarks40       = cms.string("NbQuarks40"), 
                NaddbQuarks20    = cms.string("NaddbQuarks20"),
                NaddbQuarks40    = cms.string("NaddbQuarks40"),
                NcQuarks         = cms.string("NcQuarks"),
            ),
            selections = cms.untracked.PSet(),
        ),
        partonTop = cms.PSet(
            src = cms.InputTag("partonTop"),
            #index = cms.untracked.int32(0),
            exprs = cms.untracked.PSet(
                pt  = cms.string("pt"),
                eta = cms.string("eta"),
                phi = cms.string("phi"),
                m   = cms.string("mass"),
                pdgId = cms.string("pdgId"),
                q = cms.string("charge"),
                #status = cms.string("status"),
            ),
            selections = cms.untracked.PSet(),
        ),
        pseudoTopJet = cms.PSet(
            src = cms.InputTag("pseudoTop","jets"),
            #index = cms.untracked.int32(0),
            exprs = cms.untracked.PSet(
                pt  = cms.string("pt"),
                eta = cms.string("eta"),
                phi = cms.string("phi"),
                m   = cms.string("mass"),
                pdgId = cms.string("pdgId"),
                q = cms.string("charge"),
                #status = cms.string("status"),
            ),
            selections = cms.untracked.PSet(),
        ),
        pseudoTopLepton = cms.PSet(
            src = cms.InputTag("pseudoTop","leptons"),
            #index = cms.untracked.int32(0),
            exprs = cms.untracked.PSet(
                pt  = cms.string("pt"),
                eta = cms.string("eta"),
                phi = cms.string("phi"),
                m   = cms.string("mass"),
                pdgId = cms.string("pdgId"),
                q = cms.string("charge"),
                #status = cms.string("status"),
            ),
            selections = cms.untracked.PSet(),
        ),
        pseudoTopNu = cms.PSet(
            src = cms.InputTag("pseudoTop","neutrinos"),
            #index = cms.untracked.int32(0),
            exprs = cms.untracked.PSet(
                pt  = cms.string("pt"),
                eta = cms.string("eta"),
                phi = cms.string("phi"),
                #m   = cms.string("mass"),
                pdgId = cms.string("pdgId"),
                #q = cms.string("charge"),
                #status = cms.string("status"),
            ),
            selections = cms.untracked.PSet(),
        ),
        pseudoTop = cms.PSet(
            src = cms.InputTag("pseudoTop"),
            #index = cms.untracked.int32(0),
            exprs = cms.untracked.PSet(
                pt  = cms.string("pt"),
                eta = cms.string("eta"),
                phi = cms.string("phi"),
                m   = cms.string("mass"),
                pdgId = cms.string("pdgId"),
                q = cms.string("charge"),
                #status = cms.string("status"),
            ),
            selections = cms.untracked.PSet(),
        ),
    ),
)

process.TFileService = cms.Service("TFileService",
    fileName = cms.string("ntuple.root"),
)

process.p = cms.Path(
    process.ntuple
)

