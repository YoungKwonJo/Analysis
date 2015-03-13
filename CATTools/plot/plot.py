#!/usr/local/bin/python
import sys,os

bbb="nohup root -b -q project2.C\\("
ccc="\\) >& log"
ddd="txt & "

for i in range(0,8):
  cmd=bbb+"%d"%i
  #isMC = true 
  cmd=cmd+ccc
  cmd=cmd+"%d"%i
  cmd=cmd+ddd
  print cmd
  os.system(cmd)  
