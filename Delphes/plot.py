#!/usr/bin/env python

import sys,os


# root -l ploterNew.C+\(0,0,true\)

for i in range(1,45) :
#  """
  for j in range(1,6) :
    cmd = "root -b -q ploterNew.C+\\(%d"% i
    cmd = cmd+",%d"% j
    cmd = cmd+",true\\)"
    print cmd
    os.system(cmd)
#  """ 

for i in range(1,45) :
  """
  for j in range(1,6) :
    cmd = "root -b -q ploterNew.C+\\(%d"% i
    cmd = cmd+",%d"% j
    cmd = cmd+",false\\)"
    print cmd
    os.system(cmd)
  """

for i in range(1,44) :
  """
  for j in range(1,6) :
    cmd = "root -b -q ploterNew_lj.C+\\(%d"% i
    cmd = cmd+",%d"% j
    cmd = cmd+",true\\)"
    print cmd
    os.system(cmd)
  """ 

for i in range(1,44) :
  """
  for j in range(1,6) :
    cmd = "root -b -q ploterNew_lj.C+\\(%d"% i
    cmd = cmd+",%d"% j
    cmd = cmd+",false\\)"
    print cmd
    os.system(cmd)
  """
