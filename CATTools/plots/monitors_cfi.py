
monitors = {
"Mon1" : [
  { "name":"ZMassMM",      "unit":"Dilepton mass (GeV/c^{2}) ",    "var":"mm_zmass",  "xbin_set":[60,0,300]  },
  { "name":"ZMassEE",      "unit":"Dilepton mass (GeV/c^{2}) ",    "var":"ee_zmass",  "xbin_set":[60,0,300]  },
  { "name":"ZMassEM",      "unit":"Dilepton mass (GeV/c^{2}) ",    "var":"em_zmass",  "xbin_set":[60,0,300]  },
],
"Mon2" : [
  { "name":"MET",          "unit":"Missing E_{T} (GeV) ",          "var":"met",      "xbin_set":[60,0,300]     },
  { "name":"METPHI",      "unit":"Missing E_{T} #phi ",           "var":"metphi",   "xbin_set":[40,-4,4]      },
  { "name":"nBJetL",       "unit":"b-Jet multiplicity loose ",     "var":"nBJetL",   "xbin_set":[8,0,8]      },
  { "name":"nBJetM",       "unit":"b-Jet multiplicity medium ",    "var":"nBJetM",   "xbin_set":[8,0,8]      },
  { "name":"NJet",        "unit":"Jet multiplicity ",            "var":"nJet",         "xbin_set":[10,0,10]    },
  { "name":"nBJetT",      "unit":"b-Jet multiplicity tight ",    "var":"nBJetT",       "xbin_set":[8,0,8]      },
],
"Mon3" : [
  { "name":"lep1PtMM",     "unit":"Leading lepton p_{T} (GeV/c) ", "var":"mm_mu1_pt", "xbin_set":[40,0,200] },
  { "name":"lep1PtEE",     "unit":"Leading lepton p_{T} (GeV/c) ", "var":"ee_el1_pt", "xbin_set":[40,0,200] },
  { "name":"lep1PtEM",     "unit":"Leading lepton p_{T} (GeV/c) ", "var":"em_mu1_pt", "xbin_set":[40,0,200] },

  { "name":"lep2PtMM",     "unit":"sceond  lepton p_{T} (GeV/c) ", "var":"mm_mu2_pt", "xbin_set":[40,0,200] },
  { "name":"lep2PtEE",     "unit":"sceond  lepton p_{T} (GeV/c) ", "var":"ee_el2_pt", "xbin_set":[40,0,200] },
  { "name":"lep2PtEM",     "unit":"sceond  lepton p_{T} (GeV/c) ", "var":"em_el2_pt", "xbin_set":[40,0,200] },
],
"Mon4" : [
  { "name":"lep1EtaMM",    "unit":"Leading lepton #eta ",          "var":"mm_mu1_eta", "xbin_set":[30,-3,3] },
  { "name":"lep1EtaEE",    "unit":"Leading lepton #eta ",          "var":"ee_el1_eta", "xbin_set":[30,-3,3] },
  { "name":"lep1EtaEM",    "unit":"Leading lepton #eta ",          "var":"em_mu1_eta", "xbin_set":[30,-3,3] },

  { "name":"lep2EtaMM",    "unit":"sceond  lepton #eta ",          "var":"mm_mu2_eta", "xbin_set":[30,-3,3] },
  { "name":"lep2EtaEE",    "unit":"sceond  lepton #eta ",          "var":"ee_el2_eta", "xbin_set":[30,-3,3] },
  { "name":"lep2EtaEM",    "unit":"sceond  lepton #eta ",          "var":"em_el2_eta", "xbin_set":[30,-3,3] },
],
"Mon5" : [
  { "name":"lep1PhiMM",    "unit":"Leading lepton #phi ",          "var":"mm_mu1_phi", "xbin_set":[40,-4,4] },
  { "name":"lep1PhiEE",    "unit":"Leading lepton #phi ",          "var":"ee_el1_phi", "xbin_set":[40,-4,4] },
  { "name":"lep1PhiEM",    "unit":"Leading lepton #phi ",          "var":"em_mu1_phi", "xbin_set":[40,-4,4] },

  { "name":"lep2PhiMM",    "unit":"sceond  lepton #phi ",          "var":"mm_mu2_phi", "xbin_set":[40,-4,4] },
  { "name":"lep2PhiEE",    "unit":"sceond  lepton #phi ",          "var":"ee_el2_phi", "xbin_set":[40,-4,4] },
  { "name":"lep2PhiEM",    "unit":"sceond  lepton #phi ",          "var":"em_el2_phi", "xbin_set":[40,-4,4] },
],
"Mon6" : [
  { "name":"lep1IsoMM",    "unit":"Leading lepton Iso_{rel} ",     "var":"mm_mu1_iso", "xbin_set":[20,0,1] },
  { "name":"lep1IsoEE",    "unit":"Leading lepton Iso_{rel} ",     "var":"ee_el1_iso", "xbin_set":[20,0,1] },
  { "name":"lep1IsoEM",    "unit":"Leading lepton Iso_{rel} ",     "var":"em_mu1_iso", "xbin_set":[20,0,1] },

  { "name":"lep2IsoMM",    "unit":"sceond  lepton Iso_{rel} ",     "var":"mm_mu2_iso", "xbin_set":[20,0,1] },
  { "name":"lep2IsoEE",    "unit":"sceond  lepton Iso_{rel} ",     "var":"ee_el2_iso", "xbin_set":[20,0,1] },
  { "name":"lep2IsoEM",    "unit":"sceond  lepton Iso_{rel} ",     "var":"em_el2_iso", "xbin_set":[20,0,1] },
],
"Mon7" : [
  { "name":"jet1Pt",      "unit":"p_T of 1st leading Jet ",      "var":"jet_pt[0]",    "xbin_set":[40,0,400]   },
  { "name":"jet2Pt",      "unit":"p_T of 2nd leading Jet ",      "var":"jet_pt[1]",    "xbin_set":[40,0,400]   },
  { "name":"jet3Pt",      "unit":"p_T of 3rd leading Jet ",      "var":"jet_pt[2]",    "xbin_set":[40,0,400]   },
  { "name":"jet4Pt",      "unit":"p_T of 4th leading Jet ",      "var":"jet_pt[3]",    "xbin_set":[40,0,400]   },
],
"Mon8" : [
  { "name":"jet1Eta",      "unit":"#eta of 1st leading Jet ",      "var":"jet_eta[0]",    "xbin_set":[30,-3,3]   },
  { "name":"jet2Eta",      "unit":"#eta of 2nd leading Jet ",      "var":"jet_eta[1]",    "xbin_set":[30,-3,3]   },
  { "name":"jet3Eta",      "unit":"#eta of 3rd leading Jet ",      "var":"jet_eta[2]",    "xbin_set":[30,-3,3]   },
  { "name":"jet4Eta",      "unit":"#eta of 4th leading Jet ",      "var":"jet_eta[3]",    "xbin_set":[30,-3,3]   },
],
"Mon9" : [
  { "name":"jet1Phi",      "unit":"#phi of 1st leading Jet ",      "var":"jet_phi[0]",    "xbin_set":[40,-4,4]   },
  { "name":"jet2Phi",      "unit":"#phi of 2nd leading Jet ",      "var":"jet_phi[1]",    "xbin_set":[40,-4,4]   },
  { "name":"jet3Phi",      "unit":"#phi of 3rd leading Jet ",      "var":"jet_phi[2]",    "xbin_set":[40,-4,4]   },
  { "name":"jet4Phi",      "unit":"#phi of 4th leading Jet ",      "var":"jet_phi[3]",    "xbin_set":[40,-4,4]   },
],
"Mon10": [
  { "name":"jet1CSV",     "unit":"CSV2 of 1st leading Jet ",     "var":"jet_csv[0]",   "xbin_set":[20,0,1]     },
  { "name":"jet2CSV",     "unit":"CSV2 of 2nd leading Jet ",     "var":"jet_csv[1]",   "xbin_set":[20,0,1]     },
  { "name":"jet3CSV",     "unit":"CSV2 of 3rd leading Jet ",     "var":"jet_csv[2]",   "xbin_set":[20,0,1]     },
  { "name":"jet4CSV",     "unit":"CSV2 of 4th leading Jet ",     "var":"jet_csv[3]",   "xbin_set":[20,0,1]     },
]
}

monitors2d = {
"Mon11" : [
  { "name":"jet1CSV",     "unit":"CSV2 of 1st leading Jet ",     "var":"jet_csv[0]",   "xbin_set":[20,0,1]     },
  { "name":"jet2CSV",     "unit":"CSV2 of 2nd leading Jet ",     "var":"jet_csv[1]",   "xbin_set":[20,0,1]     },
  { "name":"jet3CSV",     "unit":"CSV2 of 3rd leading Jet ",     "var":"jet_csv[2]",   "xbin_set":[20,0,1]     },
  { "name":"jet4CSV",     "unit":"CSV2 of 4th leading Jet ",     "var":"jet_csv[3]",   "xbin_set":[20,0,1]     },
]
}
