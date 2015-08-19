
from mcsample_cfi import *

mm_mu1 = "((mm_mu1_pt>20) && (abs(mm_mu1_eta)<2.4) && (abs(mm_mu1_iso)<0.12))"
mm_mu2 = "((mm_mu2_pt>20) && (abs(mm_mu2_eta)<2.4) && (abs(mm_mu2_iso)<0.12))"
ee_el1 = "((ee_el1_pt>20) && (abs(ee_el1_eta)<2.4) && (abs(ee_el1_iso)<0.12))"
ee_el2 = "((ee_el2_pt>20) && (abs(ee_el2_eta)<2.4) && (abs(ee_el2_iso)<0.12))"
em_mu1 = "((em_mu1_pt>20) && (abs(em_mu1_eta)<2.4) && (abs(em_mu1_iso)<0.12))"
em_el2 = "((em_el2_pt>20) && (abs(em_el2_eta)<2.4) && (abs(em_el2_iso)<0.12))"
mm_op = "( mm_mu1_q*mm_mu2_q<0)"
ee_op = "( ee_el1_q*ee_el2_q<0)"
em_op = "( em_mu1_q*em_el2_q<0)"

mm_lep = "(" + mm_mu1 + " && "+mm_mu2 + " && " + mm_op + " && (mm_zmass>20))" # && Nmu==2 && Nel==0)"
ee_lep = "(" + ee_el1 + " && "+ee_el2 + " && " + ee_op + " && (ee_zmass>20))" # && Nel==2 && Nmu==0)"
em_lep = "(" + em_mu1 + " && "+em_el2 + " && " + em_op + " && (em_zmass>20))" # && Nmu==1 && Nel==1)"

mm_zmass = "( abs(91.2-mm_zmass)>15 )"
ee_zmass = "( abs(91.2-ee_zmass)>15 )"
em_zmass = "(1)"# "( abs(91.2-em_zmass)>15 )"
##########

preselection = "((CSCTightHaloFilter==1)" +"||"+ "(EcalDeadCellTriggerPrimitiveFilter==1)" +"||"+ "(HBHENoiseFilter==1)" +"||"+ "(eeBadScFilter==1)" +"||"+ "(goodVertices==1))" 
mm_trigger = "((HLTDoubleEle33CaloIdLGsfTrkIdVL==1)" +"||"+ "(HLTMu17Mu8DZ==1)" +"||"+ "(HLTMu17TkMu8DZ==1)" +"||"+ "(HLTMu17TrkIsoVVLMu8TrkIsoVVL==1)" +"||"+ "(HLTMu17TrkIsoVVLMu8TrkIsoVVLDZ==1)" +"||"+ "(HLTMu17TrkIsoVVLTkMu8TrkIsoVVL==1))"

ee_trigger = "((HLTEle16Ele12Ele8CaloIdLTrackIdL==1)" +"||"+ "(HLTEle17Ele12CaloIdLTrackIdLIsoVLDZ==1)" +"||"+ "(HLTEle23Ele12CaloIdLTrackIdLIsoVL==1)" +"||"+ "(HLTEle23Ele12CaloIdLTrackIdLIsoVLDZ==1))"


e_trigger= "((HLTEle27eta2p1WPLooseGsfTriCentralPFJet30==1)" +"||"+ "(HLTEle17CaloIdLTrackIdLIsoVL==1)" +"||"+ "(HLTEle12CaloIdLTrackIdLIsoVL==1))"
em_trigger=  "(HLTMu17TrkIsoVVLEle12CaloIdLTrackIdLIsoVL==1)" +"||"+  "(HLTMu8TrkIsoVVLEle17CaloIdLTrackIdLIsoVL==1)"


##########
mm_cuts ={
"channel": "mm",
"cut": [
   "(1)",
   preselection,
   mm_trigger,
   "(" + mm_lep + ")",
   "(" + mm_zmass + ")",
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
   "(" + ee_lep + ") ",
   "(" + ee_zmass + ") ",
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
   "(" + em_lep + ") ",
   "(1)",
   "(1) ",
   "nJet>=4 ",
   "nBJetM>=2", 
   "nBJetT>=2", 
]
}
