import os

for i in range(1,16): 
  ddd = "nohup python ntuple2hist.py " + ("%d"%i) + " >& log" + ("%d"%i) + ".txt  & "
  os.system(ddd)


