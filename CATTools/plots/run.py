import os

#for i in range(1,19): 
for i in range(1,13): 
  ddd = "nohup python ntuple2hist.py " + ("%d"%i) + " >& log" + ("%d"%i) + ".txt  & "
  os.system(ddd)


