
#from mcsample_cfi import *

ll_lep1    = "((ll_lep1_pt>20) && (abs(ll_lep1_eta)<2.4)) "
ll_lep2    = "((ll_lep2_pt>20) && (abs(ll_lep2_eta)<2.4))"
ll_Iso     = "((abs(ll_lep1_iso)<0.12) && (abs(ll_lep2_iso)<0.12))"
ll_NonIso  = "((abs(ll_lep1_iso)>0.2) && (abs(ll_lep2_iso)>0.2) && (abs(ll_lep1_iso)<0.4) && (abs(ll_lep2_iso)<0.4) )"
ll_os      = "( ll_lep1_q*ll_lep2_q<0)"
ll_ss      = "( ll_lep1_q*ll_lep2_q>0)"
ll_lep     = "(" + ll_lep1 + " && "+ll_lep2 + " && (ll_zmass>20) "+") "

ll_IsoOS    = "(" + ll_lep + " && " + ll_Iso     +" && " + ll_os +")"
ll_NonIsoOS = "(" + ll_lep + " && " + ll_NonIso  +" && " + ll_os +")"

ll_IsoSS    = "(" + ll_lep + " && " + ll_Iso     +" && " + ll_ss +")"
ll_NonIsoSS = "(" + ll_lep + " && " + ll_NonIso  +" && " + ll_ss +")"

zveto    = "( abs(91.2-ll_zmass)>15 )"
zvetoNon = "( abs(91.2-ll_zmass)<=15 )"

mm= "(abs(ll_lep1_pdgid)==13&&abs(ll_lep2_pdgid)==13)"
ee= "(abs(ll_lep1_pdgid)==11&&abs(ll_lep2_pdgid)==11)"
em= "((abs(ll_lep1_pdgid)==11&&abs(ll_lep2_pdgid)==13) || (abs(ll_lep1_pdgid)==13&&abs(ll_lep2_pdgid)==11))"

preselection = "(filterRECO==1)" 
mm_trigger   = "(filterTrigMUMU==1)"
ee_trigger   = "(filterTrigELEL==1)"
em_trigger   = "(filterTrigMUEL==1)"

samecut = [ ll_IsoOS, "(nJet30>=4 ) ",  "nBJet30M>=2", "nBJet30T>=2" ]
mmeecut = [  zveto , "(metNoHF>40)" ]
mm_cuts ={
"channel": "mm",
"cut": [
   "(1)",
#   preselection,
   mm_trigger,
   "("+ll_lep+"&&"+mm+")",
   samecut[0],mmeecut[0],mmeecut[1],
   samecut[1],samecut[2],samecut[3] 
]
}
ee_cuts = {
"channel": "ee",
"cut": [
   "(1)",
#   preselection,
   ee_trigger,
   "("+ll_lep+"&&"+ee+")",
   samecut[0],mmeecut[0],mmeecut[1], 
   samecut[1],samecut[2],samecut[3] 
]
}
em_cuts = {
"channel": "em",
"cut":[
   "(1)",
#   preselection,
   em_trigger,
   "("+ll_lep+"&&"+em+")",
   samecut[0],"(1)","(1) ",
   samecut[1],samecut[2],samecut[3] 
]
}

##########
import copy

mm_cutsQCD = copy.deepcopy(mm_cuts)
mm_cutsQCD["cut"][3]= ll_NonIsoOS

ee_cutsQCD = copy.deepcopy(ee_cuts)
ee_cutsQCD["cut"][3]= ll_NonIsoOS

em_cutsQCD = copy.deepcopy(em_cuts)
em_cutsQCD["cut"][3]= ll_NonIsoOS


