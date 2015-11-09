
from mcsample_cfi import *

ll_lep1    = "((ll_lep1_pt>20) && (abs(ll_lep1_eta)<2.4)) "
ll_lep2    = "((ll_lep2_pt>20) && (abs(ll_lep2_eta)<2.4))"
ll_Iso12 = "((abs(ll_lep1_iso)<0.12) && (abs(ll_lep2_iso)<0.12))"
ll_NonIso12 = "((abs(ll_lep1_iso)>0.2) && (abs(ll_lep2_iso)>0.2))"
ll_op = "( ll_lep1_q*ll_lep2_q<0)"

ll_lep = "(" + ll_lep1 + " && "+ll_lep2 + " && (ll_zmass>20) "+") "
ll_lepIso = "(" + ll_lep1 + " && "+ll_lep2 + " && " + ll_op + " && (ll_zmass>20) " + " && " + ll_Iso12  +") "
ll_lepNonIso = "(" + ll_lep1 + " && "+ll_lep2 + " && " + ll_op + " && (ll_zmass>20) " + " && " + ll_NonIso12  +") "

ll_zmass = "( abs(91.2-ll_zmass)>15 )"
em_zmass = "(1)"# "( abs(91.2-em_zmass)>15 )"
##########
mm="(abs(ll_lep1_pdgid)==13&&abs(ll_lep2_pdgid)==13)"
ee="(abs(ll_lep1_pdgid)==11&&abs(ll_lep2_pdgid)==11)"
em="((abs(ll_lep1_pdgid)==11&&abs(ll_lep2_pdgid)==13) || (abs(ll_lep1_pdgid)==13&&abs(ll_lep2_pdgid)==11))"

preselection = "(filterRECO==1)" 

mm_trigger = "(filterTrigMUMU==1)"
ee_trigger = "(filterTrigELEL==1)"
em_trigger=  "(filterTrigMUEL==1)"

##########
#samecut = [ "(nJet30>=2 &&nJet20>=4 ) ",  "nBJet30M>=2", "nBJet30T>=2" ]
samecut = [ "(nJet30>=4 ) ",  "nBJet30M>=2", "nBJet30T>=2" ]
mm_cuts ={
"channel": "mm",
"cut": [
   "(1)",
#   preselection,
   mm_trigger,
   "("+ll_lep+"&&"+mm+")",
   "(" + ll_lepIso+"&&"+mm + ")",
   "(" + ll_zmass + ")",
   "(metNoHF>40)",
   samecut[0],samecut[1],samecut[2] 
]
}
ee_cuts = {
"channel": "ee",
"cut": [
   "(1)",
#   preselection,
   ee_trigger,
   "("+ll_lep+"&&"+ee+")",
   "(" + ll_lepIso+"&&"+ee+ ") ",
   "(" + ll_zmass + ") ",
   "(metNoHF>40) ",
   samecut[0],samecut[1],samecut[2] 
]
}
em_cuts = {
"channel": "em",
"cut":[
   "(1)",
#   preselection,
   em_trigger,
   "("+ll_lep+"&&"+em+")",
   "(" + ll_lepIso+"&&"+em+ ") ",
   "(1)",
   "(1) ",
   samecut[0],samecut[1],samecut[2] 
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
   "(metNoHF>40)", 
   samecut[0],samecut[1],samecut[2] 
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
   "(metNoHF>40) ",
   samecut[0],samecut[1],samecut[2] 
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
   samecut[0],samecut[1],samecut[2] 
]
}
