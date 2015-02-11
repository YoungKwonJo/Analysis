#!/usr/local/bin/python
import sys,os

aaa= [9]
bbb="root -b -q run.C\\(\\\""
ccc="\\\"\\)"

#for i in aaa:
for i in range(9,10):
  cmd=bbb+("%d"%i)+ccc
  print cmd
  os.system(cmd)  
