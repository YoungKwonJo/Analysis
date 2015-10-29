import FWCore.ParameterSet.Config as cms
import os

process = cms.Process("Ana")
process.options = cms.untracked.PSet( wantSummary = cms.untracked.bool(True) )
process.options.allowUnscheduled = cms.untracked.bool(True)


process.load("FWCore.MessageLogger.MessageLogger_cfi")
#process.load("Configuration.StandardSequences.Services_cff")
#process.load("SimGeneral.HepPDTESSource.pythiapdt_cfi")

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )
process.MessageLogger.cerr.FwkReport.reportEvery = 10000

process.source = cms.Source("PoolSource", fileNames = cms.untracked.vstring())

#process.source.fileNames.append('root://cms-xrdr.sdfarm.kr:1094///xrd/store/group/CAT/TTJets_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/v7-4-3_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1/151009_203354/0000/catTuple_1.root')
#process.source.fileNames.append('root://cms-xrdr.sdfarm.kr:1094///xrd/store/group/CAT/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/v7-4-3_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v3/151009_203212/0000/catTuple_659.root')
#for i in range(15):
#    process.source.fileNames.append('root://cms-xrdr.sdfarm.kr:1094///xrd/store/group/CAT/DoubleMuon/v7-4-3_Run2015C-PromptReco-v1/151009_212602/0000/catTuple_'+str(i+1)+'.root')


process.nEventsTotal = cms.EDProducer("EventCountProducer")
process.genTtbarLeptonDecay = cms.EDProducer("GenTtbarLeptonDecay",
    GenParticles = cms.InputTag("prunedGenParticles"),
    GenJets  = cms.InputTag("slimmedGenJets"),
    pt = cms.double(20),
    eta = cms.double(2.4)
)
process.filterRECO = cms.EDFilter("CATTriggerBitCombiner",
    triggerResults = cms.InputTag("TriggerResults::PAT"),
    secondaryTriggerResults = cms.InputTag("TriggerResults::RECO"),
    triggerPrescales = cms.InputTag("patTrigger"),
    combineBy = cms.string("and"),
    triggersToMatch = cms.vstring(
        "CSCTightHaloFilter",
        "EcalDeadCellTriggerPrimitiveFilter",
        "HBHENoiseFilter",
        "eeBadScFilter",
        "goodVertices",
    ),
    doFilter = cms.bool(False),
)

process.filterTrigMUEL = cms.EDFilter("CATTriggerBitCombiner",
    triggerResults = cms.InputTag("TriggerResults::HLT"),
    triggerPrescales = cms.InputTag("patTrigger"),
    combineBy = cms.string("or"),
    triggersToMatch = cms.vstring(
        "HLT_Mu17_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v",
        "HLT_Mu8_TrkIsoVVL_Ele17_CaloIdL_TrackIdL_IsoVL_v",
    ),
    doFilter = cms.bool(False),
)

process.filterTrigELEL = process.filterTrigMUEL.clone(
    triggersToMatch = cms.vstring(
        "HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v",
        "HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v",
    ),
)

process.filterTrigMUMU = process.filterTrigMUEL.clone(
    triggersToMatch = cms.vstring(
#      "HLT_Mu17_Mu8_DZ_v",
#      "HLT_Mu17_TkMu8_DZ_v",
      "HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v",
      "HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_v",
      "HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_v",
    ),
)


process.ntuple = cms.EDAnalyzer("GenericNtupleMaker",
    failureMode = cms.untracked.string("error"), # choose one among keep/skip/error
    eventCounters = cms.vstring("nEventsTotal"), #"nEventsTotal", "nEventsClean", "nEventsPAT"),
    bool = cms.PSet(
    ),
    int = cms.PSet(
        nGoodPV           =   cms.PSet(src = cms.InputTag("catVertex"   , "nGoodPV"          )),
        nPV               =   cms.PSet(src = cms.InputTag("catVertex"   , "nPV"              )),
        filterTrigMUMU = cms.PSet(src = cms.InputTag("filterTrigMUMU")), 
        filterTrigELEL = cms.PSet(src = cms.InputTag("filterTrigELEL")), 
        filterTrigMUEL = cms.PSet(src = cms.InputTag("filterTrigMUEL")), 
        filterRECO = cms.PSet(src = cms.InputTag("filterRECO")), 
   ),
    ints = cms.PSet( ),
    strings = cms.PSet( ),
    float = cms.PSet( ),
    floats = cms.PSet( ),
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
                dxy = cms.string("dxy"),
                dz = cms.string("dz"),
                q = cms.string("charge"),
                isPF = cms.string("isPFMuon"),
                normalizedChi2 = cms.string("normalizedChi2"),
                numberOfValidMuonHits = cms.string("numberOfValidMuonHits"),
                numberOfValidPixelHits = cms.string("numberOfValidPixelHits"),
                trackerLayersWithMeasurement = cms.string("trackerLayersWithMeasurement"),
                numberOfMatchedStations = cms.string("numberOfMatchedStations"),
                matched = cms.string("mcMatched"),
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
                isPF   = cms.string("isPF"),
                passConversionVeto   = cms.string("passConversionVeto"),
                #MISSINGINNERHITS = cms.string("gsfTrack.hitPattern.numberOfLostHits('MISSING_INNER_HITS')"),
                #mva = cms.string("electronID('mvaTrigV0')"),
                #idHEEP51 = cms.string("electronID('heepElectronID-HEEPV51')"),
                #idLoose = cms.string("electronID('cutBasedElectronID-PHYS14-PU20bx25-V2-standalone-loose')"), 
                #idMedium = cms.string("electronID('cutBasedElectronID-PHYS14-PU20bx25-V2-standalone-medium')"), 
                #idTight = cms.string("electronID('cutBasedElectronID-PHYS14-PU20bx25-V2-standalone-tight')"), 
                #idVeto = cms.string("electronID('cutBasedElectronID-PHYS14-PU20bx25-V2-standalone-veto')"),
                idHEEPV60 = cms.string("electronID('heepElectronID-HEEPV60')"),
                idLoose = cms.string("electronID('cutBasedElectronID-Spring15-25ns-V1-standalone-loose')"),
                idMedium = cms.string("electronID('cutBasedElectronID-Spring15-25ns-V1-standalone-medium')"),
                idTight = cms.string("electronID('cutBasedElectronID-Spring15-25ns-V1-standalone-tight')"),
                idVeto = cms.string("electronID('cutBasedElectronID-Spring15-25ns-V1-standalone-veto')"),
                mvaNonTrigWp90 = cms.string("electronID('mvaEleID-Spring15-25ns-nonTrig-V1-wp90')"),
                mvaNonTrigWp80 = cms.string("electronID('mvaEleID-Spring15-25ns-nonTrig-V1-wp80')"),
                mvaTight  = cms.string("isTightMVA"),
                mvaMedium = cms.string("isMediumMVA"),
# 'heepElectronID-HEEPV60' 'cutBasedElectronID-Spring15-25ns-V1-standalone-loose' 'cutBasedElectronID-Spring15-25ns-V1-standalone-medium' 'cutBasedElectronID-Spring15-25ns-V1-standalone-tight' 'cutBasedElectronID-Spring15-25ns-V1-standalone-veto' 'mvaEleID-Spring15-25ns-nonTrig-V1-wp90' 'mvaEleID-Spring15-25ns-nonTrig-V1-wp80'
                relIso03 = cms.string("relIso(0.3)"),
                relIso04 = cms.string("relIso(0.4)"),
                chIso03 = cms.string("chargedHadronIso(0.3)"),
                nhIso03 = cms.string("neutralHadronIso(0.3)"),
                phIso03 = cms.string("photonIso(0.3)"),
                puChIso03 = cms.string("puChargedHadronIso(0.3)"),
                chIso04 = cms.string("chargedHadronIso(0.4)"),
                nhIso04 = cms.string("neutralHadronIso(0.4)"),
                phIso04 = cms.string("photonIso(0.4)"),
                puChIso04 = cms.string("puChargedHadronIso(0.4)"), 
                #rhoIso03 = cms.string("rho"),
                scEta = cms.string("scEta"),
                #dxy = cms.string("dxy"),
                #dz = cms.string("dz"),
                q = cms.string("charge"),
                matched = cms.string("mcMatched"),
                #isGsfCtfScPixChargeConsistent = cms.string("isGsfCtfScPixChargeConsistent"),
            ),
            selections = cms.untracked.PSet(),
            #    isPassBaseId = cms.string("passConversionVeto && isPF && gsfTrack.hitPattern.numberOfLostHits('MISSING_INNER_HITS') <= 0"),
            #),
        ),
        jets = cms.PSet(
            src = cms.InputTag("catJets"),
            exprs = cms.untracked.PSet(
                pt  = cms.string("pt"),
                eta = cms.string("eta"),
                phi = cms.string("phi"),
                m   = cms.string("mass"),

                shiftedEnDown = cms.string("shiftedEnDown"),
                shiftedEnUp   = cms.string("shiftedEnUp"),
                smearedRes    = cms.string("smearedRes"),
                smearedResDown= cms.string("smearedResDown"),
                smearedResUp  = cms.string("smearedResUp"),
                LooseId       = cms.string("LooseId"),
                TightId       = cms.string("TightId"),
                looseJetID    = cms.string("looseJetID"),
                tightJetID    = cms.string("tightJetID"),
                pileupJetId   = cms.string("pileupJetId"),   

                vtxMass = cms.string("vtxMass"),
                CSVInclV2 = cms.string("bDiscriminator('pfCombinedInclusiveSecondaryVertexV2BJetTags')"),
                #CSVInclV2 = cms.string("bDiscriminator('combinedInclusiveSecondaryVertexV2BJetTags')"),
                partonFlavour = cms.string("partonFlavour"),
                hadronFlavour = cms.string("hadronFlavour"),
            ),
            selections = cms.untracked.PSet(
                isLoose = cms.string("LooseId"),
                isPFId = cms.string("pileupJetId"),
#TTH
#                isPFJETID = cms.string("neutralHadronEnergyFraction<0.99 && chargedEmEnergyFraction<0.99 && neutralEmEnergyFraction<0.99 && numberOfDaughters>1 && chargedHadronEnergyFraction>0.0 && chargedMultiplicity>0 "),

            ),
        ),
        jetsPuppi = cms.PSet(
            src = cms.InputTag("catJetsPuppi"),
            exprs = cms.untracked.PSet(
                pt  = cms.string("pt"),
                eta = cms.string("eta"),
                phi = cms.string("phi"),
                m   = cms.string("mass"),

                shiftedEnDown = cms.string("shiftedEnDown"),
                shiftedEnUp   = cms.string("shiftedEnUp"),
                smearedRes    = cms.string("smearedRes"),
                smearedResDown= cms.string("smearedResDown"),
                smearedResUp  = cms.string("smearedResUp"),
                LooseId       = cms.string("LooseId"),
                TightId       = cms.string("TightId"),
                looseJetID    = cms.string("looseJetID"),
                tightJetID    = cms.string("tightJetID"),
                pileupJetId   = cms.string("pileupJetId"),   

                vtxMass = cms.string("vtxMass"),
                CSVInclV2 = cms.string("bDiscriminator('pfCombinedInclusiveSecondaryVertexV2BJetTags')"),
                #CSVInclV2 = cms.string("bDiscriminator('combinedInclusiveSecondaryVertexV2BJetTags')"),
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
        metNoHF = cms.PSet(
            src = cms.InputTag("catMETsNoHF"),
            exprs = cms.untracked.PSet(
                pt  = cms.string("pt"),
                phi = cms.string("phi"),
            ),
            selections = cms.untracked.PSet(),
        ),
        metPfMva = cms.PSet(
            src = cms.InputTag("catMETsPfMva"),
            exprs = cms.untracked.PSet(
                pt  = cms.string("pt"),
                phi = cms.string("phi"),
            ),
            selections = cms.untracked.PSet(),
        ),
        metPuppi = cms.PSet(
            src = cms.InputTag("catMETsPuppi"),
            exprs = cms.untracked.PSet(
                pt  = cms.string("pt"),
                phi = cms.string("phi"),
            ),
            selections = cms.untracked.PSet(),
        ),
    ),
)

process.TFileService = cms.Service("TFileService",
    #fileName = cms.string("ntuple_" + outputname + ".root"),
    fileName = cms.string("ntuple.root"),
)
#process.out = cms.OutputModule("PoolOutputModule",
#    fileName = cms.untracked.string('catTuple.root'),
#    outputCommands = cms.untracked.vstring(
#   'drop *',
#   'keep *_*_*_CAT',
#   'keep *_*_*_Ana',
#    )
#)
#process.outpath = cms.EndPath(process.out)

process.p = cms.Path(
    process.nEventsTotal*
#    process.genTtbarLeptonDecay*
#    process.partonTop*
    process.ntuple
)




########################################################
#process.load("CATTools.CatProducer.mcTruthTop.mcTruthTop_cff")
def updateSetup(process):
    #lumiFile = 'Cert_246908-257599_13TeV_PromptReco_Collisions15_25ns_JSON.txt'
    lumiFile = 'Cert_246908-258750_13TeV_PromptReco_Collisions15_25ns_JSON.txt'
   
    runOnMC = True
    for i in process.source.fileNames:
        if 'Run2015' in i:
            runOnMC=False
   
    isTTbar=False
    for i in process.source.fileNames:
        if '/TT' in i or '/tt' in i:
            isTTbar=True
   
    if not runOnMC:
        from FWCore.PythonUtilities.LumiList import LumiList
        #lumiList = LumiList(os.environ["CMSSW_BASE"]+'/src/CATTools/CatProducer/prod/LumiMask/'+lumiFile)    
        lumiList = LumiList(os.environ["CMSSW_BASE"]+'/src/CATTools/CommonTools/test/ttbb/'+lumiFile)    
        process.source.lumisToProcess = lumiList.getVLuminosityBlockRange()  
   
   
    if runOnMC:
        setattr(process.ntuple.int,   "nTrueInteraction",    cms.InputTag("pileupWeight", "nTrueInteraction"))
        setattr(process.ntuple.int,   "genWeightId1",        cms.InputTag("genWeight", "id1"))
        setattr(process.ntuple.int,   "genWeightId2",        cms.InputTag("genWeight", "id2"))
        setattr(process.ntuple.float, "puWeight",            cms.InputTag("pileupWeight", ""))
        setattr(process.ntuple.float, "puWeightUp",          cms.InputTag("pileupWeight", "up"))
        setattr(process.ntuple.float, "puWeightDn",          cms.InputTag("pileupWeight", "dn"))
        setattr(process.ntuple.float, "genWeightQ",          cms.InputTag("genWeight", "Q"))
        setattr(process.ntuple.float, "genWeightX1",         cms.InputTag("genWeight", "x1"))
        setattr(process.ntuple.float, "genWeightX2",         cms.InputTag("genWeight", "x2"))
        setattr(process.ntuple.float, "genWeight",           cms.InputTag("genWeight", "genWeight"))
        setattr(process.ntuple.float, "lheWeight",           cms.InputTag("genWeight", "lheWeight"))
        setattr(process.ntuple.floats, "pdfWeight",          cms.InputTag("genWeight", "pdfWeights"))
   
    if runOnMC and isTTbar:
        process.partonTop = cms.EDProducer("PartonTopProducer",
            genParticles = cms.InputTag("prunedGenParticles"),
            jetMinPt = cms.double(20),
            jetMaxEta = cms.double(2.5),
            jetConeSize = cms.double(0.4),
        )
        setattr(process.ntuple.int,   "partonTopChannel",    cms.InputTag("partonTop", "channel"))
        setattr(process.ntuple.int,   "genTtbarId",          cms.InputTag("GenTtbarCategories", "genTtbarId"))
        setattr(process.ntuple.int,   "genTtbarLeptonDecay", cms.InputTag("genTtbarLeptonDecay", "genTtbarLeptonDecayId"))
        setattr(process.ntuple.int,   "NgenJet",             cms.InputTag("genTtbarLeptonDecay", "NgenJet"))
      
        #process.ntuple.cands.gentop = cms.PSet(
        #    src = cms.InputTag("catGenTops"),
        #    #index = cms.untracked.int32(0),
        #    exprs = cms.untracked.PSet(
        #        lepton1_pt      = cms.string("lepton1().Pt()"),
        #        lepton1_eta      = cms.string("lepton1().Eta()"),
        #        lepton1_phi      = cms.string("lepton1().Phi()"),
        #        lepton2_pt      = cms.string("lepton2().Pt()"),
        #        lepton2_eta      = cms.string("lepton2().Eta()"),
        #        lepton2_phi      = cms.string("lepton2().Phi()"),
        #        allHadronic      = cms.string("allHadronic"),
        #        semiLeptonic     = cms.string("semiLeptonic"),
        #        diLeptonicMuoMuo = cms.string("diLeptonicMuoMuo"),
        #        diLeptonicMuoEle = cms.string("diLeptonicMuoEle"),
        #        diLeptonicEleEle = cms.string("diLeptonicEleEle"),
        #        diLeptonicTauMuo = cms.string("diLeptonicTauMuo"),
        #        diLeptonicTauEle = cms.string("diLeptonicTauEle"),
        #        diLeptonicTauTau = cms.string("diLeptonicTauTau"),
        #        NbJets1           = cms.string("NbJets(1)"),
        #        NbJets201         = cms.string("NbJets20(1)"),
        #        NbJets251         = cms.string("NbJets25(1)"),
        #        NbJets301         = cms.string("NbJets30(1)"),
        #        NbJets401         = cms.string("NbJets40(1)"),
        #        NaddbJets1        = cms.string("NaddbJets(1)"),
        #        NaddbJets201      = cms.string("NaddbJets20(1)"),
        #        NaddbJets401      = cms.string("NaddbJets40(1)"),
        #        NcJets1           = cms.string("NcJets(1)"),
        #        NcJets101         = cms.string("NcJets10(1)"),
        #        NcJets151         = cms.string("NcJets15(1)"),
        #        NcJets201         = cms.string("NcJets20(1)"),
        #        NcJets251         = cms.string("NcJets25(1)"),
        #        NcJets301         = cms.string("NcJets30(1)"),
        #        NcJets401         = cms.string("NcJets40(1)"),
        #        NbJets           = cms.string("NbJets(0)"),
        #        NbJets20         = cms.string("NbJets20(0)"),
        #        NbJets25         = cms.string("NbJets25(0)"),
        #        NbJets30         = cms.string("NbJets30(0)"),
        #        NbJets40         = cms.string("NbJets40(0)"),
        #        NaddbJets        = cms.string("NaddbJets(0)"),
        #        NaddbJets20      = cms.string("NaddbJets20(0)"),
        #        NaddbJets40      = cms.string("NaddbJets40(0)"),
        #        NcJets           = cms.string("NcJets(0)"),
        #        NcJets10         = cms.string("NcJets10(0)"),
        #        NcJets15         = cms.string("NcJets15(0)"),
        #        NcJets20         = cms.string("NcJets20(0)"),
        #        NcJets25         = cms.string("NcJets25(0)"),
        #        NcJets30         = cms.string("NcJets30(0)"),
        #        NcJets40         = cms.string("NcJets40(0)"),
        #        NJets            = cms.string("NJets"),
        #        NJets10          = cms.string("NJets10"),
        #        NJets20          = cms.string("NJets20"),
        #        NJets25          = cms.string("NJets25"),
        #        NJets30          = cms.string("NJets30"),
        #        NJets40          = cms.string("NJets40"),
        #        NaddJets20       = cms.string("NaddJets20"),
        #        NaddJets40       = cms.string("NaddJets40"),
        #        NbQuarksTop      = cms.string("NbQuarksTop"),
        #        NbQuarksNoTop    = cms.string("NbQuarksNoTop"),
        #        NbQuarks         = cms.string("NbQuarks"),
        #        NbQuarks20       = cms.string("NbQuarks20"),
        #        NbQuarks40       = cms.string("NbQuarks40"), 
        #        NaddbQuarks20    = cms.string("NaddbQuarks20"),
        #        NaddbQuarks40    = cms.string("NaddbQuarks40"),
        #        NcQuarks         = cms.string("NcQuarks"),
        #    ),
        #    selections = cms.untracked.PSet(),
        #)
        process.ntuple.slimmedGenJets = cms.PSet(
                src = cms.InputTag("slimmedGenJets",""),
                #index = cms.untracked.int32(0),
                exprs = cms.untracked.PSet(
                    pt  = cms.string("pt"),
                    eta = cms.string("eta"),
                    phi = cms.string("phi"),
                    m   = cms.string("mass"),
                    #pdgId = cms.string("pdgId"),
                    #q = cms.string("charge"),
                    #status = cms.string("status"),
                ),
                selections = cms.untracked.PSet(),
            )
        process.ntuple.cands.partonTop = cms.PSet(
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
            )
        process.ntuple.cands.pseudoTopJet = cms.PSet(
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
            )
        process.ntuple.cands.pseudoTopLepton = cms.PSet(
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
            )
        process.ntuple.cands.pseudoTopNu = cms.PSet(
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
            )
        process.ntuple.cands.pseudoTop = cms.PSet(
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
            )

########################################

#updateSetup(process)
