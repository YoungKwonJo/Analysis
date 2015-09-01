
from mcsample_cfi import *

ll_lep1    = "((ll_lep1_pt>20) && (abs(ll_lep1_eta)<2.4)) "
ll_lep2    = "((ll_lep2_pt>20) && (abs(ll_lep2_eta)<2.4))"
#mm_mu1    = "((mm_mu1_pt>20) && (abs(mm_mu1_eta)<2.4)) "
#mm_mu2    = "((mm_mu2_pt>20) && (abs(mm_mu2_eta)<2.4))"
#ee_el1    = "((ee_el1_pt>20) && (abs(ee_el1_eta)<2.4))"
#ee_el2    = "((ee_el2_pt>20) && (abs(ee_el2_eta)<2.4))"
#em_mu1    = "((em_mu1_pt>20) && (abs(em_mu1_eta)<2.4))"
#em_el2    = "((em_el2_pt>20) && (abs(em_el2_eta)<2.4))"

ll_Iso12 = "((abs(ll_lep1_iso)<0.12) && (abs(ll_lep2_iso)<0.12))"
#mm_Iso12 = "((abs(mm_mu1_iso)<0.12) && (abs(mm_mu2_iso)<0.12))"
#ee_Iso12 = "((abs(ee_el1_iso)<0.12) && (abs(ee_el2_iso)<0.12))"
#em_Iso12 = "((abs(em_mu1_iso)<0.12) && (abs(em_el2_iso)<0.12))"

ll_NonIso12 = "((abs(ll_lep1_iso)>0.2) && (abs(ll_lep2_iso)>0.2))"
#mm_NonIso12 = "((abs(mm_mu1_iso)>0.2) && (abs(mm_mu2_iso)>0.2))"
#ee_NonIso12 = "((abs(ee_el1_iso)>0.2) && (abs(ee_el2_iso)>0.2))"
#em_NonIso12 = "((abs(em_mu1_iso)>0.2) && (abs(em_el2_iso)>0.2))"

ll_op = "( ll_lep1_q*ll_lep2_q<0)"
#mm_op = "( mm_mu1_q*mm_mu2_q<0)"
#ee_op = "( ee_el1_q*ee_el2_q<0)"
#em_op = "( em_mu1_q*em_el2_q<0)"

ll_lepIso = "(" + ll_lep1 + " && "+ll_lep2 + " && " + ll_op + " && (ll_zmass>20) " + " && " + ll_Iso12  +") "
#mm_lepIso = "(" + mm_mu1 + " && "+mm_mu2 + " && " + mm_op + " && (mm_zmass>20) " + " && " + mm_Iso12  +") "
#ee_lepIso = "(" + ee_el1 + " && "+ee_el2 + " && " + ee_op + " && (ee_zmass>20) " + " && " + ee_Iso12  +") "
#em_lepIso = "(" + em_mu1 + " && "+em_el2 + " && " + em_op + " && (em_zmass>20) " + " && " + em_Iso12  +") "

ll_lepNonIso = "(" + ll_lep1 + " && "+ll_lep2 + " && " + ll_op + " && (ll_zmass>20) " + " && " + ll_NonIso12  +") "
#mm_lepNonIso = "(" + mm_mu1 + " && "+mm_mu2 + " && " + mm_op + " && (mm_zmass>20) " + " && " + mm_NonIso12  +") "
#ee_lepNonIso = "(" + ee_el1 + " && "+ee_el2 + " && " + ee_op + " && (ee_zmass>20) " + " && " + ee_NonIso12  +") "
#em_lepNonIso = "(" + em_mu1 + " && "+em_el2 + " && " + em_op + " && (em_zmass>20) " + " && " + em_NonIso12  +") "mm

ll_zmass = "( abs(91.2-ll_zmass)>15 )"
#mm_zmass = "( abs(91.2-mm_zmass)>15 )"
#ee_zmass = "( abs(91.2-ee_zmass)>15 )"
em_zmass = "(1)"# "( abs(91.2-em_zmass)>15 )"
##########
mm="(abs(ll_lep1_pdgid)==13&&abs(ll_lep2_pdgid)==13)"
ee="(abs(ll_lep1_pdgid)==11&&abs(ll_lep2_pdgid)==11)"
em="((abs(ll_lep1_pdgid)==11&&abs(ll_lep2_pdgid)==13) || (abs(ll_lep1_pdgid)==13&&abs(ll_lep2_pdgid)==11))"

preselection = "((CSCTightHaloFilter==1)" +"&&"+ "(EcalDeadCellTriggerPrimitiveFilter==1)" +"&&"+ "(HBHENoiseFilter==1)" +"&&"+ "(eeBadScFilter==1)" +"&&"+ "(goodVertices==1))" 
mm_trigger = "((HLTDoubleEle33CaloIdLGsfTrkIdVL==1)" +"||"+ "(HLTMu17Mu8DZ==1)" +"||"+ "(HLTMu17TkMu8DZ==1)" +"||"+ "(HLTMu17TrkIsoVVLMu8TrkIsoVVL==1)" +"||"+ "(HLTMu17TrkIsoVVLMu8TrkIsoVVLDZ==1)" +"||"+ "(HLTMu17TrkIsoVVLTkMu8TrkIsoVVL==1))"

ee_trigger = "((HLTEle16Ele12Ele8CaloIdLTrackIdL==1)" +"||"+ "(HLTEle17Ele12CaloIdLTrackIdLIsoVLDZ==1)" +"||"+ "(HLTEle23Ele12CaloIdLTrackIdLIsoVL==1)" +"||"+ "(HLTEle23Ele12CaloIdLTrackIdLIsoVLDZ==1))"


e_trigger= "((HLTEle27eta2p1WPLooseGsfTriCentralPFJet30==1)" +"||"+ "(HLTEle17CaloIdLTrackIdLIsoVL==1)" +"||"+ "(HLTEle12CaloIdLTrackIdLIsoVL==1))"
em_trigger=  "((HLTMu17TrkIsoVVLEle12CaloIdLTrackIdLIsoVL==1)" +"||"+  "(HLTMu8TrkIsoVVLEle17CaloIdLTrackIdLIsoVL==1))"

##########
mm_cuts ={
"channel": "mm",
"cut": [
   "(1)",
#   preselection,
#   mm_trigger,
   "(" + ll_lepIso+"&&"+mm + ")",
   "(" + ll_zmass + ")",
   "(met>40)", 
   "nJet>=4 ",
   "nBJetM>=2", 
   "nBJetT>=2", 
]
}
ee_cuts = {
"channel": "ee",
"cut": [
   "(1)",
#   preselection,
#   ee_trigger,
   "(" + ll_lepIso+"&&"+ee+ ") ",
   "(" + ll_zmass + ") ",
   "(met>40) ",
   "nJet>=4 ",
   "nBJetM>=2", 
   "nBJetT>=2", 
]
}
em_cuts = {
"channel": "em",
"cut":[
   "(1)",
#   preselection,
#   em_trigger,
   "(" + ll_lepIso+"&&"+em+ ") ",
   "(1)",
   "(1) ",
   "nJet>=4 ",
   "nBJetM>=2", 
   "nBJetT>=2", 
]
}

##########
mm_cutsQCD ={
"channel": "mm",
"cut": [
   "(1)",
#   preselection,
#   mm_trigger,
   "(" + ll_lepNonIso+"&&"+mm+ ")",
   "(" + ll_zmass + ")",
   "(met>40)", 
   "nJet>=4 ",
   "nBJetM>=2", 
   "nBJetT>=2", 
]
}
ee_cutsQCD = {
"channel": "ee",
"cut": [
   "(1)",
#   preselection,
#   ee_trigger,
   "(" + ll_lepNonIso+"&&"+ee+ ") ",
   "(" + ll_zmass + ") ",
   "(met>40) ",
   "nJet>=4 ",
   "nBJetM>=2", 
   "nBJetT>=2", 
]
}
em_cutsQCD = {
"channel": "em",
"cut":[
   "(1)",
#   preselection,
#   em_trigger,
   "(" + ll_lepNonIso+"&&"+em + ") ",
   "(1)",
   "(1) ",
   "nJet>=4 ",
   "nBJetM>=2", 
   "nBJetT>=2", 
]
}
