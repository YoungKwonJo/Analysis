
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

mm_cuts ={
"channel": "mm",
"cut": [
   "(1)",
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
