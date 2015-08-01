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
  mon = {  "name" : "h1_"+name+"_"+monitor['name']+"_"+cutname, "title" : name+" "+monitor['var'],
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
  mon = {  "name" : "h2_"+name+"_"+monitor['name']+"_"+monitor2['name']+"_"+cutname, "title" : name+" "+monitor['var']+" vs "+monitor2['var'],
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
      cut = cuts[cutname]+" && "+mc['selection']
      print "____" + mc['name'] + "_____" + cut + "_____" 
      h1sumw2 = h1_maker(tree,mon,cut,1)
      h.append(copy.deepcopy(h1sumw2))
  return h

def h2_all_maker(tree,mc, monitors, cuts):
  h = []
  for cutname in cuts:
    for i,ii in enumerate(monitors):
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
      cuts["S%d"%i]= cuts["S%d"%(i-1)] + " && " + cut
  print cuts
  return cuts

def cut_maker2(cuts_):
  cuts  = {}
  for i,cut in enumerate(cuts_):
      cuts["S%d"%i]=cut
  return cuts


def ntuple2hist(mcsamples,monitors,cuts):
  h = []
  for i,mc in enumerate(mcsamples):
    f = TFile.Open(mcsamples[i]['file'],"read")
    #tree = f.ntuple
    tree = f.myresult
    h= h+h_all_maker(tree,mcsamples[i],monitors,cuts)
    f.Close()
  return h

def ntuple2hist2d(mcsamples,monitors,cuts):
  h = []
  for i,mc in enumerate(mcsamples):
    f = TFile.Open(mcsamples[i]['file'],"read")
    #tree = f.ntuple
    tree = f.myresult
    h= h+h2_all_maker(tree,mcsamples[i],monitors,cuts)
    f.Close()
  return h
 
def makeoutput(outputname, h):
  fout = TFile(outputname,"RECREATE")
  for a in h:
    a.Write()
  fout.Write()
  fout.Close()

def makehist(json):
  cuts_  = cut_maker(json['cuts']) #print "cut : %s" % cuts
  h=[]
  if len(json['monitors'])>0 :
    h += ntuple2hist(json['mcsamples'],json['monitors'],cuts_)
  if len(json['monitors2'])>0 :
    h += ntuple2hist2d(json['mcsamples'],json['monitors2'],cuts_)
  makeoutput(json['output'],h)

def makehist2(json):
  cuts_  = cut_maker2(json['cuts']) #print "cut : %s" % cuts
  h=[]
  if len(json['monitors'])>0 :
    h += ntuple2hist(json['mcsamples'],json['monitors'],cuts_)
  if len(json['monitors2'])>0 :
    h += ntuple2hist2d(json['mcsamples'],json['monitors2'],cuts_)
  makeoutput(json['output'],h)


###################################################
def make_legend(xmin,ymin,xmax,ymax):
  #leg = TLegend(0.65,0.7, 0.89,0.89)
  leg = TLegend(xmin,ymin,xmax,ymax)
  leg.SetBorderSize(1)
  leg.SetTextFont(62)
  leg.SetTextSize(0.04)
  leg.SetLineStyle(1)
  leg.SetLineWidth(1)
  leg.SetLineColor(0)
  #leg.SetLineColor(1)
  leg.SetFillColor(0)
  #leg.SetFillColor(10)
  leg.SetFillStyle(1001)
  leg.SetMargin(0.15) #for size of the marker

  return leg

def make_banner(xmin,ymin,xmax,ymax):
  #pt = TPaveText(0.15,0.73, 0.5, 0.89,"brNDC");
  pt = TPaveText(xmin,ymin,xmax,ymax,"brNDC");
  pt.SetBorderSize(1)
  pt.SetTextFont(42)
  pt.SetTextSize(0.04)
  pt.SetLineColor(0)
  pt.SetLineStyle(1)
  pt.SetLineWidth(1)
  pt.SetFillColor(0)
  pt.SetFillStyle(1001)
  pt.SetTextAlign(12)
  pt.AddText("Work in progress")
  #pt.AddText("TTJets_madgraphMLM-pythia8")
  pt.AddText("madgraphMLM-pythia8")
  pt.AddText("#sqrt{s} = 13 TeV")
  pt.Draw()

  return pt

def make_banner2(xmin,ymin,xmax,ymax,bb,bb2):
  #pt = TPaveText(0.15,0.73, 0.5, 0.89,"brNDC");
  pt = TPaveText(xmin,ymin,xmax,ymax,"brNDC");
  pt.SetBorderSize(1)
  pt.SetTextFont(42)
  pt.SetTextSize(0.04)
  pt.SetLineColor(0)
  pt.SetLineStyle(1)
  pt.SetLineWidth(1)
  pt.SetFillColor(0)
  pt.SetFillStyle(1001)
  pt.SetTextAlign(12)
  pt.AddText("Work in progress")
  #pt.AddText("TTJets_madgraphMLM-pythia8")
  pt.AddText("madgraphMLM-pythia8")
  pt.AddText("#sqrt{s} = 13 TeV")
  pt.AddText( ("ttbb/ttjj : "+str("%.4f"%bb)+"")  )
  pt.AddText( ("(ttbb+ttb+tt2b)/ttjj : "+str("%.4f"%bb2)+" ") )
  pt.Draw()

  return pt

def singleplot(filename,mon,step,mcsamples):
  f = TFile.Open(filename,"read")
  c1 = TCanvas( 'c1', '', 500, 500 ) 
  leg = make_legend(0.57,0.64, 0.89,0.88)
  scale=0.
  jj = 0.
  bb = 0.
  b1 = 0.
  b2 = 0.
  for i,mc in enumerate(mcsamples):
    histname = "h1_"+mc['name']+"_"+mon+"_"+step+"_Sumw2"
    #histname = "h1_"+mc['name']+"_"+mon+"_"+step+""
    h1 = f.Get(histname)
    h1.AddBinContent(h1.GetNbinsX(),h1.GetBinContent(h1.GetNbinsX()+1))
    aa = mc['name']
    if ( (aa is "ttbb") or (aa is "ttb") or (aa is "tt2b") or (aa is "ttcc") or (aa is "ttlf") ):
      jj+=h1.Integral()
      #print jj
    if aa is "ttbb" :  bb+=h1.Integral()
    if aa is "ttb"  :  b1+=h1.Integral()
    if aa is "tt2b" :  b2+=h1.Integral()

    #if h1.Integral()>0 :
    #  h1.Scale(1./h1.Integral())
    if h1.GetMaximum()>scale:
      scale=h1.GetMaximum()

  for i,mc in enumerate(mcsamples):
    histname = "h1_"+mc['name']+"_"+mon+"_"+step+"_Sumw2"
    #histname = "h1_"+mc['name']+"_"+mon+"_"+step+""
    h1 = f.Get(histname);
    h1.SetTitle("")
    if i==0:
      h1.SetMaximum(scale*400)
      #h1.SetMinimum(0.001)
      h1.SetMinimum(0.5)
      h1.Draw()
    else:
      h1.Draw("same")
    h1.SetLineColor(mc['color'])
    h1.SetLineWidth(mc['lineWidth'])
    h1.SetStats(0)
    #lleng= len("%s"%mc['label'])
    #rleng= len(" %.0f"%h1.Integral())
    #lrleng = 22 - lleng - int(rleng/1.8)
    label = ("%s"%mc['label']) + (" %.0f"%h1.Integral()).rjust(8)
    leg.AddEntry(h1, label, "l");
  leg.Draw()
  c1.SetLogy()
  #pt = make_banner(0.15,0.73, 0.5, 0.89)
  bbb = 0.
  bbbb = 0.
  if jj>0:  bbb = bb/jj
  if jj>0:  bbbb = (bb+b1+bb)/jj
  pt = make_banner2(0.12,0.66, 0.5, 0.89, bbb,bbbb )
  pt.Draw()
  output = "plots/TH1_"+mon+"_"+step+".eps"
  c1.Print(output)
  f.Close()
  c1.Close()

def singleplotlinear(filename,mon,step,mcsamples):
  f = TFile.Open(filename,"read")
  c1 = TCanvas( 'c1', '', 500, 500 ) 
  leg = make_legend(0.57,0.64, 0.89,0.88)
  scale=0.;
  for i,mc in enumerate(mcsamples):
    histname = "h1_"+mc['name']+"_"+mon+"_"+step+"_Sumw2"
    #histname = "h1_"+mc['name']+"_"+mon+"_"+step+""
    h1 = f.Get(histname);
    h1.AddBinContent(h1.GetNbinsX(),h1.GetBinContent(h1.GetNbinsX()+1))
    #if h1.Integral()>0 :
    #  h1.Scale(1./h1.Integral())
    if h1.GetMaximum()>scale:
      scale=h1.GetMaximum()

  for i,mc in enumerate(mcsamples):
    histname = "h1_"+mc['name']+"_"+mon+"_"+step+"_Sumw2"
    #histname = "h1_"+mc['name']+"_"+mon+"_"+step+""
    h1 = f.Get(histname);
    h1.SetTitle("")
    if i==0:
      h1.SetMaximum(scale*1.5)
      h1.Draw()
    else:
      h1.Draw("same")
    h1.SetLineColor(mc['color'])
    h1.SetLineWidth(mc['lineWidth'])
    h1.SetStats(0)
    label = ("%s"%mc['label']) + (" %.0f"%h1.Integral()).rjust(8)
    leg.AddEntry(h1, label, "l");
  leg.Draw()
  #c1.SetLogy()
  pt = make_banner(0.12,0.66, 0.5, 0.89)
  pt.Draw()
  output = "plots/TH1_linear_"+mon+"_"+step+".eps"
  c1.Print(output)
  f.Close()
  c1.Close()




def plotTH2F(filename,mon,step,mcsamples):
  f = TFile.Open(filename,"read")
  n=len(mcsamples)
  gStyle.SetOptStat(0)
  c1 = TCanvas( 'c2', '', 500*3, 500*2 ) 
  c1.Divide(3,2)
  legs = []
  #pts  = []
  for i,mc in enumerate(mcsamples):
    c1.cd(i+1)
    histname = "h2_"+mc['name']+"_"+mon+"_"+step+"_Sumw2"
    h1 = f.Get(histname);
    h1.SetTitle("")
    h1.SetLineColor(mc['color'])
    h1.Draw("colz")
    #pt = make_banner(0.15,0.73, 0.5, 0.89)
    #pts.append(copy.deepcopy(pt))
    #pts[i].Draw()
    leg = make_legend(0.5,0.91, 0.75,0.99)
    leg.AddEntry(h1, mc['label'], "l");
    legs.append(copy.deepcopy(leg))
    legs[i].Draw()
  output = "plots/TH2_"+mon+"_"+step+".eps"
  c1.Print(output)
  f.Close()
  c1.Close()
