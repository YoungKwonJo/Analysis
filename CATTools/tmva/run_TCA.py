import os

samples = [
     "DYJets","DoubleEG","DoubleMuon","MuonEG","SingleTbar_t",
     "SingleTbar_tW","SingleTop_t","SingleTop_tW","TTJets_MG5","TTWJetsToLNu",
     "TTWJetsToQQ","TTZToLLNuNu","TTZToQQ","TT_powheg","TT_powheg_scaledown",
     "TT_powheg_scaleup","WJets","WW","WZ","ZZ","ttHToNonbb","ttHTobb"]

cmd1="nohup root -b -q TMVAClassificationApplication.C\\(\\\""
cmd2="\\\"\) >& log_"
cmd3=".txt "

os.system('date')

for i,aa in enumerate(samples):
  ddd=cmd1+aa+cmd2+aa+cmd3+" &"
  if i%12 is 0 : ddd=cmd1+aa+cmd2+aa+cmd3
  print ddd
  os.system(ddd)


