import os

for i in range(0,14): 
  #ddd = "cmsRun run_ntupleMaker_cfg.py " + ("%d"%i) + " >& /tmp/log" + ("%d"%i) + ".txt & "
  ddd = "nohup cmsRun run_ntupleMaker_cfg.py " + ("%d"%i) + " >& /dev/null  & "
  os.system(ddd)



