
monitors = {
"Mon1" : [
  { "name":"MET",          "unit":"Missing E_{T} without HF (GeV)","var":"metNoHF",   "xbin_set":[60,0,300]  },
#  { "name":"ZMassMM",      "unit":"Dilepton mass (GeV/c^{2}) ",    "var":"mm_zmass",  "xbin_set":[60,0,300]  },
  { "name":"ZMass",        "unit":"Dilepton mass (GeV/c^{2}) ",    "var":"ll_zmass",  "xbin_set":[60,0,300]  },
],
"Mon2" : [
  { "name":"nGoodPV",      "unit":"# of good vertex ",             "var":"nGoodPV",   "xbin_set":[70,0,70]    },
  { "name":"nPV",          "unit":"# of vertex ",                  "var":"nPV",       "xbin_set":[70,0,70]    },
#  { "name":"ZMassEE",      "unit":"Dilepton mass (GeV/c^{2}) ",    "var":"ee_zmass",  "xbin_set":[60,0,300]  },
#  { "name":"ZMassEM",      "unit":"Dilepton mass (GeV/c^{2}) ",    "var":"em_zmass",  "xbin_set":[60,0,300]  },
],
"Mon3" : [
  { "name":"Stat",         "unit":"Stat ",                         "var":"met",       "xbin_set":[1,0,10000]  },
  { "name":"METPHI",       "unit":"Missing E_{T} without HF #phi", "var":"metNoHFphi","xbin_set":[40,-4,4]    },
],
"Mon4" : [
  { "name":"nBJetL",       "unit":"b-Jet multiplicity loose ",     "var":"nBJetL",    "xbin_set":[8,0,8]      },
  { "name":"nBJetM",       "unit":"b-Jet multiplicity medium ",    "var":"nBJetM",    "xbin_set":[8,0,8]      },
],
"Mon5" : [
  { "name":"NJet",         "unit":"Jet multiplicity ",             "var":"nJet",      "xbin_set":[10,0,10]    },
  { "name":"nBJetT",       "unit":"b-Jet multiplicity tight ",     "var":"nBJetT",    "xbin_set":[8,0,8]      },
],
"Mon6" : [
  { "name":"lep1Pt",       "unit":"Leading lepton p_{T} (GeV/c) ", "var":"ll_lep1_pt", "xbin_set":[40,0,200] },
#  { "name":"lep1PtMM",     "unit":"Leading lepton p_{T} (GeV/c) ", "var":"mm_mu1_pt", "xbin_set":[40,0,200] },
#  { "name":"lep1PtEE",     "unit":"Leading lepton p_{T} (GeV/c) ", "var":"ee_el1_pt", "xbin_set":[40,0,200] },
#  { "name":"lep1PtEM",     "unit":"Leading lepton p_{T} (GeV/c) ", "var":"em_mu1_pt", "xbin_set":[40,0,200] },

  { "name":"lep2Pt",       "unit":"Sceond  lepton p_{T} (GeV/c) ", "var":"ll_lep2_pt", "xbin_set":[40,0,200] },
#  { "name":"lep2PtMM",     "unit":"Sceond  lepton p_{T} (GeV/c) ", "var":"mm_mu2_pt", "xbin_set":[40,0,200] },
#  { "name":"lep2PtEE",     "unit":"Sceond  lepton p_{T} (GeV/c) ", "var":"ee_el2_pt", "xbin_set":[40,0,200] },
#  { "name":"lep2PtEM",     "unit":"Sceond  lepton p_{T} (GeV/c) ", "var":"em_el2_pt", "xbin_set":[40,0,200] },
],
"Mon7" : [
  { "name":"lep1Eta",      "unit":"Leading lepton #eta ",          "var":"ll_lep1_eta", "xbin_set":[30,-3,3] },
#  { "name":"lep1EtaMM",    "unit":"Leading lepton #eta ",          "var":"mm_mu1_eta", "xbin_set":[30,-3,3] },
#  { "name":"lep1EtaEE",    "unit":"Leading lepton #eta ",          "var":"ee_el1_eta", "xbin_set":[30,-3,3] },
#  { "name":"lep1EtaEM",    "unit":"Leading lepton #eta ",          "var":"em_mu1_eta", "xbin_set":[30,-3,3] },

  { "name":"lep2Eta",    "unit":"Sceond  lepton #eta ",          "var":"ll_lep2_eta", "xbin_set":[30,-3,3] },
#  { "name":"lep2EtaMM",    "unit":"Sceond  lepton #eta ",          "var":"mm_mu2_eta", "xbin_set":[30,-3,3] },
#  { "name":"lep2EtaEE",    "unit":"Sceond  lepton #eta ",          "var":"ee_el2_eta", "xbin_set":[30,-3,3] },
#  { "name":"lep2EtaEM",    "unit":"Sceond  lepton #eta ",          "var":"em_el2_eta", "xbin_set":[30,-3,3] },
],
"Mon8" : [
  { "name":"lep1Phi",      "unit":"Leading lepton #phi ",          "var":"ll_lep1_phi", "xbin_set":[40,-4,4] },
#  { "name":"lep1PhiMM",    "unit":"Leading lepton #phi ",          "var":"mm_mu1_phi", "xbin_set":[40,-4,4] },
#  { "name":"lep1PhiEE",    "unit":"Leading lepton #phi ",          "var":"ee_el1_phi", "xbin_set":[40,-4,4] },
#  { "name":"lep1PhiEM",    "unit":"Leading lepton #phi ",          "var":"em_mu1_phi", "xbin_set":[40,-4,4] },

  { "name":"lep2Phi",      "unit":"Sceond  lepton #phi ",          "var":"ll_lep2_phi", "xbin_set":[40,-4,4] },
#  { "name":"lep2PhiMM",    "unit":"Sceond  lepton #phi ",          "var":"mm_mu2_phi", "xbin_set":[40,-4,4] },
#  { "name":"lep2PhiEE",    "unit":"Sceond  lepton #phi ",          "var":"ee_el2_phi", "xbin_set":[40,-4,4] },
#  { "name":"lep2PhiEM",    "unit":"Sceond  lepton #phi ",          "var":"em_el2_phi", "xbin_set":[40,-4,4] },
],
"Mon9" : [
  { "name":"lep1Iso",      "unit":"Leading lepton Iso_{rel} ",     "var":"ll_lep1_iso", "xbin_set":[20,0,1] },
#  { "name":"lep1IsoMM",    "unit":"Leading lepton Iso_{rel} ",     "var":"mm_mu1_iso", "xbin_set":[20,0,1] },
#  { "name":"lep1IsoEE",    "unit":"Leading lepton Iso_{rel} ",     "var":"ee_el1_iso", "xbin_set":[20,0,1] },
#  { "name":"lep1IsoEM",    "unit":"Leading lepton Iso_{rel} ",     "var":"em_mu1_iso", "xbin_set":[20,0,1] },

  { "name":"lep2Iso",      "unit":"Sceond  lepton Iso_{rel} ",     "var":"ll_lep2_iso", "xbin_set":[20,0,1] },
#  { "name":"lep2IsoMM",    "unit":"Sceond  lepton Iso_{rel} ",     "var":"mm_mu2_iso", "xbin_set":[20,0,1] },
#  { "name":"lep2IsoEE",    "unit":"Sceond  lepton Iso_{rel} ",     "var":"ee_el2_iso", "xbin_set":[20,0,1] },
#  { "name":"lep2IsoEM",    "unit":"Sceond  lepton Iso_{rel} ",     "var":"em_el2_iso", "xbin_set":[20,0,1] },
],
"Mon10" : [
  { "name":"jet1Pt",      "unit":"p_T of 1st leading Jet ",      "var":"jet_pt[0]",    "xbin_set":[40,0,400]   },
  { "name":"jet2Pt",      "unit":"p_T of 2nd leading Jet ",      "var":"jet_pt[1]",    "xbin_set":[40,0,400]   },
],
"Mon11" : [
  { "name":"jet3Pt",      "unit":"p_T of 3rd leading Jet ",      "var":"jet_pt[2]",    "xbin_set":[40,0,400]   },
  { "name":"jet4Pt",      "unit":"p_T of 4th leading Jet ",      "var":"jet_pt[3]",    "xbin_set":[40,0,400]   },
],
"Mon12" : [
  { "name":"jet1Eta",      "unit":"#eta of 1st leading Jet ",      "var":"jet_eta[0]",    "xbin_set":[30,-3,3]   },
  { "name":"jet2Eta",      "unit":"#eta of 2nd leading Jet ",      "var":"jet_eta[1]",    "xbin_set":[30,-3,3]   },
],
"Mon13" : [
  { "name":"jet3Eta",      "unit":"#eta of 3rd leading Jet ",      "var":"jet_eta[2]",    "xbin_set":[30,-3,3]   },
  { "name":"jet4Eta",      "unit":"#eta of 4th leading Jet ",      "var":"jet_eta[3]",    "xbin_set":[30,-3,3]   },
],
"Mon14" : [
  { "name":"jet1Phi",      "unit":"#phi of 1st leading Jet ",      "var":"jet_phi[0]",    "xbin_set":[40,-4,4]   },
  { "name":"jet2Phi",      "unit":"#phi of 2nd leading Jet ",      "var":"jet_phi[1]",    "xbin_set":[40,-4,4]   },
],
"Mon15" : [
  { "name":"jet3Phi",      "unit":"#phi of 3rd leading Jet ",      "var":"jet_phi[2]",    "xbin_set":[40,-4,4]   },
  { "name":"jet4Phi",      "unit":"#phi of 4th leading Jet ",      "var":"jet_phi[3]",    "xbin_set":[40,-4,4]   },
],
"Mon16": [
  { "name":"jet1CSV",     "unit":"CSV2 of 1st leading Jet ",     "var":"jet_csv[0]",   "xbin_set":[20,0,1]     },
  { "name":"jet2CSV",     "unit":"CSV2 of 2nd leading Jet ",     "var":"jet_csv[1]",   "xbin_set":[20,0,1]     },
],
"Mon17" : [
  { "name":"jet3CSV",     "unit":"CSV2 of 3rd leading Jet ",     "var":"jet_csv[2]",   "xbin_set":[20,0,1]     },
  { "name":"jet4CSV",     "unit":"CSV2 of 4th leading Jet ",     "var":"jet_csv[3]",   "xbin_set":[20,0,1]     },
],
#"Mon11": [
#  { "name":"jet1DRl",     "unit":"DR_l of 1st leading Jet ",     "var":"jet_drl[0]",   "xbin_set":[20,0,4]     },
#  { "name":"jet2DRl",     "unit":"DR_l of 2nd leading Jet ",     "var":"jet_drl[1]",   "xbin_set":[20,0,4]     },
#  { "name":"jet3DRl",     "unit":"DR_l of 3rd leading Jet ",     "var":"jet_drl[2]",   "xbin_set":[20,0,4]     },
#  { "name":"jet4DRl",     "unit":"DR_l of 4th leading Jet ",     "var":"jet_drl[3]",   "xbin_set":[20,0,4]     },
#],
"Mon18": [
  { "name":"jetPP1CSV",   "unit":"CSV2 of 1st leading JetPuppi ",     "var":"jetPuppi_csv[0]",   "xbin_set":[20,0,1]     },
  { "name":"jetPP2CSV",   "unit":"CSV2 of 2nd leading JetPuppi ",     "var":"jetPuppi_csv[1]",   "xbin_set":[20,0,1]     },
],
"Mon19" : [
  { "name":"jetPP3CSV",   "unit":"CSV2 of 3rd leading JetPuppi ",     "var":"jetPuppi_csv[2]",   "xbin_set":[20,0,1]     },
  { "name":"jetPP4CSV",   "unit":"CSV2 of 4th leading JetPuppi ",     "var":"jetPuppi_csv[3]",   "xbin_set":[20,0,1]     },
],
"Mon20" : [
  { "name":"jetPP1Pt",      "unit":"p_T of 1st leading JetPuppi ",      "var":"jetPuppi_pt[0]",    "xbin_set":[40,0,400]   },
  { "name":"jetPP2Pt",      "unit":"p_T of 2nd leading JetPuppi ",      "var":"jetPuppi_pt[1]",    "xbin_set":[40,0,400]   },
],
"Mon21" : [
  { "name":"jetPP3Pt",      "unit":"p_T of 3rd leading JetPuppi ",      "var":"jetPuppi_pt[2]",    "xbin_set":[40,0,400]   },
  { "name":"jetPP4Pt",      "unit":"p_T of 4th leading JetPuppi ",      "var":"jetPuppi_pt[3]",    "xbin_set":[40,0,400]   },
],
"Mon22" : [
  { "name":"Nmu",         "unit":"number of muon ",              "var":"Nmu",          "xbin_set":[5,0,5]    },
  { "name":"NmuIso",      "unit":"number of muon ",              "var":"NmuIso",       "xbin_set":[5,0,5]    },
],
"Mon23" : [
  { "name":"Nel",         "unit":"number of electron ",          "var":"Nel",          "xbin_set":[5,0,5]    },
  { "name":"NelIso",      "unit":"number of electron ",          "var":"NelIso",       "xbin_set":[5,0,5]    },
],
}

monitors2d = {
"Mon24" : [
  { "name":"jet1CSV",     "unit":"CSV2 of 1st leading Jet ",     "var":"jet_csv[0]",   "xbin_set":[20,0,1]     },
  { "name":"jet2CSV",     "unit":"CSV2 of 2nd leading Jet ",     "var":"jet_csv[1]",   "xbin_set":[20,0,1]     },
],
"Mon25" : [
  { "name":"jet3CSV",     "unit":"CSV2 of 3rd leading Jet ",     "var":"jet_csv[2]",   "xbin_set":[20,0,1]     },
  { "name":"jet4CSV",     "unit":"CSV2 of 4th leading Jet ",     "var":"jet_csv[3]",   "xbin_set":[20,0,1]     },
],
"Mon26" : [
  { "name":"NJet",        "unit":"Jet multiplicity ",             "var":"nJet",     "xbin_set":[10,0,10]    },
#  { "name":"nBJetL",      "unit":"b-Jet multiplicity loose ",     "var":"nBJetL",   "xbin_set":[8,0,8]      },
  { "name":"nBJetM",      "unit":"b-Jet multiplicity medium ",    "var":"nBJetM",   "xbin_set":[8,0,8]      },
  { "name":"nBJetT",      "unit":"b-Jet multiplicity tight ",     "var":"nBJetT",   "xbin_set":[8,0,8]      },
],
#"Mon27" : [
#  { "name":"NJet",        "unit":"Jet multiplicity ",            "var":"nJet",         "xbin_set":[10,0,10]    },
#  { "name":"genNJet",     "unit":"genJet multiplicity ",         "var":"NgenJet",      "xbin_set":[10,0,10]    },
#  { "name":"Category",    "unit":"Category ",                    "var":"Category",     "xbin_set":[5,0,5]      },
#],
#"Mon28" : [
##  { "name":"Nmu",         "unit":"number of muon ",              "var":"Nmu",          "xbin_set":[5,0,5]    },
#  { "name":"NmuIso",      "unit":"number of muon ",              "var":"NmuIso",       "xbin_set":[5,0,5]    },
##  { "name":"Nel",         "unit":"number of electron ",          "var":"Nel",          "xbin_set":[5,0,5]    },
#  { "name":"NelIso",      "unit":"number of electron ",          "var":"NelIso",       "xbin_set":[5,0,5]    },
#],
}
