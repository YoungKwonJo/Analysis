#!/usr/local/bin/python
import sys,os

aaa= ["dy","tbw","tw","wj"]#,"ttbar_0","ttbar_1","ttbar_2","ttbar_3","ttbar_4","ttbar_5","ttbar_6","ttbar_7"]
#aaa= ["tbw","tw","wj","ttbar_0","ttbar_1","ttbar_2","ttbar_3","ttbar_4","ttbar_5","ttbar_6","ttbar_7"]
aaa=aaa+["ttbar_nonu_0","ttbar_nonu_1","ttbar_nonu_2","ttbar_nonu_3","ttbar_nonu_4","ttbar_nonu_5","ttbar_nonu_6","ttbar_nonu_7","ttbar_nonu_8","ttbar_nonu_9"]
bbb="root -b -q run.C\\("
ccc="\\)"

for i in aaa:
  cmd=bbb+"\\\"%s\\\""%i
  #isMC = true 
  cmd=cmd+",true"+ccc
  print cmd
  os.system(cmd)  
