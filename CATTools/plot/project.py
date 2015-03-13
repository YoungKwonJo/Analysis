#!/usr/local/bin/python
import sys,os

aaa = ["0,0","1,0","2,0","3,0","4,0","4,1","4,2","4,3","4,4","5,0","6,0","7,0"]
#aaa = ["0,0","1,0","2,0","3,0","4,0","4,1","4,2"]
#aaa = ["4,0","4,1","4,2"]
bbb="nohup root -b -q project.C\\("
ccc="\\) >& ./log/log"
ddd="txt & "

#for i in range(0,8):
for i,val in enumerate(aaa):
  cmd=bbb+"%s"%val
  #isMC = true 
  cmd=cmd+ccc
  cmd=cmd+"%d"%i
  cmd=cmd+ddd
  print cmd
  os.system(cmd)  
