import os
from samples_cfi import samples

for i,mc in enumerate(samples): 
  #ddd = "cmsRun run_ntupleMaker_cfg.py " + ("%d"%i) + " >& /tmp/log" + ("%d"%i) + ".txt & "
  if 'xsec' in mc.keys(): ddd = "nohup cmsRun run_ntupleMaker_cfg.py " + ("%d"%i) + " >& /dev/null  & "
  else: ddd = "nohup cmsRun run_ntupleMakerRD_cfg.py " + ("%d"%i) + " >& /dev/null  & "
  print ddd
  #os.system(ddd)

