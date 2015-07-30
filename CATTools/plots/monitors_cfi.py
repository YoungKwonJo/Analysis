
monitors = {
"jetMon1" : [
  { "name":"NJet",        "unit":"Jet multiplicity ",            "var":"nJet",         "xbin_set":[10,0,10]    },
  { "name":"nBJetT",      "unit":"b-Jet multiplicity tight ",    "var":"nBJetT",       "xbin_set":[8,0,8]      },
  { "name":"jet1Pt",      "unit":"p_T of 1st leading Jet ",      "var":"jet_pt[0]",    "xbin_set":[40,0,400]   },
  { "name":"jet2Pt",      "unit":"p_T of 2nd leading Jet ",      "var":"jet_pt[1]",    "xbin_set":[40,0,400]   },
  { "name":"jet3Pt",      "unit":"p_T of 3rd leading Jet ",      "var":"jet_pt[2]",    "xbin_set":[40,0,400]   },
  { "name":"jet4Pt",      "unit":"p_T of 4th leading Jet ",      "var":"jet_pt[3]",    "xbin_set":[40,0,400]   },
],
"jetMon2" : [
  { "name":"jet1Eta",      "unit":"#eta of 1st leading Jet ",      "var":"jet_eta[0]",    "xbin_set":[30,-3,3]   },
  { "name":"jet2Eta",      "unit":"#eta of 2nd leading Jet ",      "var":"jet_eta[1]",    "xbin_set":[30,-3,3]   },
  { "name":"jet3Eta",      "unit":"#eta of 3rd leading Jet ",      "var":"jet_eta[2]",    "xbin_set":[30,-3,3]   },
  { "name":"jet4Eta",      "unit":"#eta of 4th leading Jet ",      "var":"jet_eta[3]",    "xbin_set":[30,-3,3]   },
],
"jetMon2" : [
  { "name":"jet1Phi",      "unit":"#phi of 1st leading Jet ",      "var":"jet_phi[0]",    "xbin_set":[40,-4,4]   },
  { "name":"jet2Phi",      "unit":"#phi of 2nd leading Jet ",      "var":"jet_phi[1]",    "xbin_set":[40,-4,4]   },
  { "name":"jet3Phi",      "unit":"#phi of 3rd leading Jet ",      "var":"jet_phi[2]",    "xbin_set":[40,-4,4]   },
  { "name":"jet4Phi",      "unit":"#phi of 4th leading Jet ",      "var":"jet_phi[3]",    "xbin_set":[40,-4,4]   },
],
"jetMon3": [
  { "name":"jet1CSV",     "unit":"CSV2 of 1st leading Jet ",     "var":"jet_csv[0]",   "xbin_set":[20,0,1]     },
  { "name":"jet2CSV",     "unit":"CSV2 of 2nd leading Jet ",     "var":"jet_csv[1]",   "xbin_set":[20,0,1]     },
  { "name":"jet3CSV",     "unit":"CSV2 of 3rd leading Jet ",     "var":"jet_csv[2]",   "xbin_set":[20,0,1]     },
  { "name":"jet4CSV",     "unit":"CSV2 of 4th leading Jet ",     "var":"jet_csv[3]",   "xbin_set":[20,0,1]     },
]
}
