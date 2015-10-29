#!/usr/bin/env python
import sys, subprocess

def subFolders(cmd,path):
  l = set() 
  for x in subprocess.check_output(cmd+path, shell=True).strip().split('\n'):
    xx = x.split()
    if len(xx) == 0: continue
    if xx[0][0] not in ('d'): continue
    xpath = xx[-1]
    ii = xpath.find(path)
    if ii==0: xpath = xpath[len(path):]
    l.add(xpath)
  return l  

def subFiles(cmd,path):
  l = set() 
  for x in subprocess.check_output(cmd+path, shell=True).strip().split('\n'):
    xx = x.split()
    if len(xx) == 0: continue
    if xx[0][0] not in ('-'): continue
    xpath = xx[-1]
    ii = xpath.find(path+"/")
    if ii==0: xpath = xpath[len(path+"/"):]
    l.add(xpath)
  return l

def getSamples(cmd,path):
  l1=subFolders(cmd,path)
  samples = []
  for i in l1:
    l2=subFiles(cmd, path+i)
    sam = {}
    sam["name"] = i
    sam["files"] = l2
    samples.append(sam)
  
  return samples

path = "/xrd/store/user/youngjo/Cattools/v7-4-3/"
path2 = "/xrootd/store/user/youngjo/Cattools/v7-4-3/"
cmd ="xrd cms-xrdr.sdfarm.kr ls "
cmd2 ="ls -all "
#print cmd
#print cmd2

samples=getSamples(cmd,path)
#print str(samples)


