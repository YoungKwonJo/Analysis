from ROOT import *
import copy

def h1_maker(tree, mon, cut,doSumw2):
  aa=['','_Sumw2']
  h1 =  TH1F( mon['name']+aa[doSumw2], mon['title'], mon['xbin_set'][0],mon['xbin_set'][1],mon['xbin_set'][2])
  h1.GetXaxis().SetTitle(mon['x_name'])
  h1.GetYaxis().SetTitle(mon['y_name'])
  if doSumw2>0:
    h1.Sumw2()
  tree.Project(mon['name']+aa[doSumw2],mon['var'],cut)
  return h1  

def h1_set(name,monitor,cutname):
  mon = {  "name" : "h1_"+name+monitor['name']+"_"+cutname, "title" : name+" "+monitor['var'],
           "var" : monitor['var'],            "xbin_set" : monitor['xbin_set'],
           "x_name": monitor['unit'], "y_name": "Entries"
        }
  return mon

def h2_maker(tree, mon, cut,doSumw2):
  aa=['','_Sumw2']
  h2 =  TH2F( mon['name']+aa[doSumw2], mon['title'], mon['xbin_set'][0],mon['xbin_set'][1],mon['xbin_set'][2], mon['ybin_set'][0],mon['ybin_set'][1],mon['ybin_set'][2])
  h2.GetXaxis().SetTitle(mon['x_name'])
  h2.GetYaxis().SetTitle(mon['y_name'])
  if doSumw2>0:
    h2.Sumw2()
  tree.Project(mon['name']+aa[doSumw2],mon['var'],cut)
  return h2  

def h2_set(name,monitor,monitor2,cutname):
  mon = {  "name" : "h2_"+name+monitor['name']+"_"+monitor2['name']+"_"+cutname, "title" : name+" "+monitor['var']+" vs "+monitor2['var'],
           "var" : monitor2['var']+":"+monitor['var'],         
           "xbin_set" : monitor['xbin_set'], "ybin_set" : monitor2['xbin_set'],
           "x_name": monitor['unit'], "y_name": monitor2['unit']
        }
  return mon

def h_all_maker(tree,mc, monitors, cuts):
  h = []
  for cutname in cuts:
    for i,ii in enumerate(monitors):
      mon = h1_set(mc['name'],monitors[i],cutname)
      h1 = h1_maker(tree,mon,cuts[cutname]+" && "+mc['selection'],0)
      h.append(copy.deepcopy(h1))
      h1sumw2 = h1_maker(tree,mon,cuts[cutname]+" && "+mc['selection'],1)
      h.append(copy.deepcopy(h1sumw2))
      for j,jj in enumerate(monitors):
        if i<j:
          mon2 = h2_set(mc['name'],monitors[i],monitors[j],cutname)
          h2 = h2_maker(tree,mon2,cuts[cutname]+" && "+mc['selection'],0)
          h.append(copy.deepcopy(h2))
          h2sumw2 = h2_maker(tree,mon2,cuts[cutname]+" && "+mc['selection'],1)
          h.append(copy.deepcopy(h2sumw2))
  return h

def cut_maker(cuts_):
  cuts  = {}
  for i,cut in enumerate(cuts_):
    if i==0 :
      cuts["S%d"%i]=cut
    else:
      cuts["S%d"%i]= cut+" && "+cuts["S%d"%(i-1)]
  return cuts
