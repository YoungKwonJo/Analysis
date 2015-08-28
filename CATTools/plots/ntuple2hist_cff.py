from ROOT import *
import copy
from array import array
from math import sqrt

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

def h_all_maker(tree,mc, monitors, cuts, eventweight):
  h = []
  for cutname in cuts["cut"]:
    for i,ii in enumerate(monitors):
      mon = h1_set(mc['name'],monitors[i],cutname+cuts["channel"])
      h1 = h1_maker(tree,mon,cuts["cut"][cutname]+" && "+mc['selection'],0)
      h.append(copy.deepcopy(h1))
      cut = "("+cuts["cut"][cutname]+" && "+mc['selection'] +")*("+str(eventweight)+")"
      #cut = "("+cuts["cut"][cutname]+" && "+mc['selection'] +")"#*("+str(eventweight)+")"
      #print "____" + mc['name'] + "_____" + cut + "_____" 
      h1sumw2 = h1_maker(tree,mon,cut,1)
      h.append(copy.deepcopy(h1sumw2))
  return h

def h2_all_maker(tree,mc, monitors, cuts,eventweight):
  h = []
  for cutname in cuts["cut"]:
    for i,ii in enumerate(monitors):
      for j,jj in enumerate(monitors):
        if i<j:
          mon2 = h2_set(mc['name'],monitors[i],monitors[j],cutname+cuts["channel"])
          cut = "("+cuts["cut"][cutname]+" && "+mc['selection']+")*("+str(eventweight)+")"
          #cut = "("+cuts["cut"][cutname]+" && "+mc['selection']+")"#*("+str(eventweight)+")"
          h2 = h2_maker(tree,mon2,cut,0)
          h.append(copy.deepcopy(h2))
          h2sumw2 = h2_maker(tree,mon2,cut,1)
          h.append(copy.deepcopy(h2sumw2))
  return h

def cut_maker(cuts_):
  cuts  = {}
  for i,cut in enumerate(cuts_["cut"]):
    if i==0 :
      cuts["S%d"%i]=cut
    else:
      cuts["S%d"%i]= cuts["S%d"%(i-1)] + " && " + cut
  cutsN = {"channel":cuts_["channel"],"cut":cuts}
  #print cutsN
  return cutsN

def cut_maker2(cuts_):
  cuts  = {}
  for i,cut in enumerate(cuts_["cut"]):
      cuts["S%d"%i]=cut
  cutsN = {"channel":cuts_["channel"],"cut":cuts}
  return cuts


#def ntuple2hist(mcsamples,monitors,cuts):
def ntuple2hist(json,cuts):
  h = []
  mcsamples = json['mcsamples']
  mceventweight = json['mceventweight']
  monitors=json['monitors']
  datasamples = json['datasamples']
  for i,mc in enumerate(mcsamples):
    f = TFile.Open(mcsamples[i]['file'],"read")
    #tree = f.ntuple
    tree = f.myresult
    h= h+h_all_maker(tree,mcsamples[i],monitors,cuts,mceventweight)
    f.Close()
  for i,mc in enumerate(datasamples):
    f = TFile.Open(datasamples[i]['file'],"read")
    #tree = f.ntuple
    tree = f.myresult
    h= h+h_all_maker(tree,datasamples[i],monitors,cuts,1)
    f.Close()


  return h

#def ntuple2hist2d(mcsamples,monitors,cuts):
def ntuple2hist2d(json,cuts):
  h = []
  mcsamples = json['mcsamples']
  mceventweight = json['mceventweight']
  monitors=json['monitors']
  datasamples = json['datasamples']
  for i,mc in enumerate(mcsamples):
    f = TFile.Open(mcsamples[i]['file'],"read")
    #tree = f.ntuple
    tree = f.myresult
    h= h+h2_all_maker(tree,mcsamples[i],monitors,cuts,mceventweight)
    f.Close()

  for i,mc in enumerate(datasamples):
    f = TFile.Open(mcsamples[i]['file'],"read")
    #tree = f.ntuple
    tree = f.myresult
    h= h+h2_all_maker(tree,datasamples[i],monitors,cuts,1)
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
    h += ntuple2hist(json,cuts_)
  if len(json['monitors2'])>0 :
    h += ntuple2hist2d(json,cuts_)
  makeoutput(json['output'],h)

def makehist2(json):
  cuts_  = cut_maker2(json['cuts']) #print "cut : %s" % cuts
  h=[]
  if len(json['monitors'])>0 :
    h += ntuple2hist(json,cuts_)
  if len(json['monitors2'])>0 :
    h += ntuple2hist2d(json,cuts_)
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
    if type(h1) is not TH1F :
      return
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
  scale=0.
  for i,mc in enumerate(mcsamples):
    histname = "h1_"+mc['name']+"_"+mon+"_"+step+"_Sumw2"
    #histname = "h1_"+mc['name']+"_"+mon+"_"+step+""
    h1 = f.Get(histname)
    if type(h1) is not TH1F :
      return 
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
    h1 = f.Get(histname)
    if type(h1) is not TH2F :  
      return
    h1.SetTitle("")
    h1.SetLineColor(mc['color'])
    h1.Draw("colz")
    #pt = make_banner(0.15,0.73, 0.5, 0.89)
    #pts.append(copy.deepcopy(pt))
    #pts[i].Draw()
    leg = make_legend(0.5,0.91, 0.75,0.99)
    leg.AddEntry(h1, ("%s : "%mc['label']) + ("%.0f"%h1.Integral()), "l");
    legs.append(copy.deepcopy(leg))
    legs[i].Draw()
  output = "plots/TH2_"+mon+"_"+step+".eps"
  c1.Print(output)
  f.Close()
  c1.Close()


def singleplotStack(filename,mon,step,mcsamples):
  f = TFile.Open(filename,"read")
  c1 = TCanvas( 'c1', '', 500, 500 )
  gStyle.SetOptFit(1)
  gStyle.SetOptStat(0)
  c1.Range(0,0,1,1)
  c1.SetFillColor(0)
  c1.SetBorderMode(0)
  c1.SetBorderSize(2)
  c1.SetTickx(1)
  c1.SetTicky(1)
  c1.SetLeftMargin(0.15)
  c1.SetRightMargin(0.05)
  c1.SetBottomMargin(0.15)
  c1.SetFrameBorderMode(0)


  pad1 = TPad("pad1", "",0,0.3,1,1);
  pad1.Draw()
  pad1.cd()
  pad1.Range(-1.072875,-0.39794,5.364372,5.641005)
  pad1.SetFillColor(0)
  pad1.SetBorderMode(0)
  pad1.SetBorderSize(2)
  pad1.SetLogy()
  pad1.SetTickx(1)
  pad1.SetTicky(1)
  pad1.SetLeftMargin(0.1666667)
  pad1.SetRightMargin(0.05660377)
  pad1.SetBottomMargin(0)
  pad1.SetFrameBorderMode(0)
  pad1.SetFrameBorderMode(0)

  leg  = make_legend(0.67,0.64, 0.89,0.88)
  leg2 = make_legend(0.43,0.64, 0.62,0.88)
  scale=0.
  jj = 0.
  bb = 0.
  b1 = 0.
  b2 = 0.
  lumi = 40.028
  #lumi = 10.028
  minimum=1.
  hs = THStack("hs","")

  hmctotName = "h1_"+mcsamples[0]['name']+"_"+mon+"_"+step+"_Sumw2"
  #print "hmcTotal: "+hmctotName
  hmctot = f.Get(hmctotName).Clone("hmctot")
  hmctot.Reset()

  hdata = hmctot.Clone("hdata")

  for i,mc in enumerate(mcsamples):
    histnameS = "h1_"+mc['name']+"_"+mon+"_"+step+"_Sumw2"
    histname = "h1_"+mc['name']+"_"+mon+"_"+step+""
    channel = step[2:4]
    htotname = "h1_"+mc['name']+"_MET_S0"+channel+"_Sumw2"
    #print htotname
    #histname = "h1_"+mc['name']+"_"+mon+"_"+step+""
    h1 = f.Get(histname)
    h2 = f.Get(histnameS)
    htot = f.Get(htotname)
    if type(h1) is not TH1F :
      return
    #if h1.Integral()>0 and mc['label'].find("DATA")==-1: print mc.keys()
    h1.GetYaxis().SetTitle("Events")
    h2.GetYaxis().SetTitle("Events")

    Ntot = htot.Integral()
    h1.AddBinContent(h1.GetNbinsX(),h1.GetBinContent(h1.GetNbinsX()+1))
    h2.AddBinContent(h2.GetNbinsX(),h2.GetBinContent(h2.GetNbinsX()+1))
    aa = mc['name']

    isMC = mc['label'].find("DATA")==-1
    checkDataChannel = (channel=="mm" and mc['name']=="MuMu") or (channel=="ee" and mc['name']=="ElEl") or (channel=="em" and mc['name']=="MuEl") 

    if h1.Integral()>0 and isMC :  h1.Scale(mc['cx']/Ntot*lumi)
    if h2.Integral()>0 and isMC :  h2.Scale(mc['cx']/Ntot*lumi)
    #print mc['label']+":"+str(mc['label'].find("DATA")==-1)

    #h1list.append(copy.deepcopy(h1))
    #h2list.append(copy.deepcopy(h2))
    if isMC               : hmctot.Add( h2 )
    elif checkDataChannel : hdata.Add(h2)

    #if mc['label'].find("DATA")==-1: hmctot = merge(hmctot,h2)
    isJJ = ( (aa is "ttbb") or (aa is "ttb") or (aa is "tt2b") or (aa is "ttcc") or (aa is "ttlf") )
    if isJJ :  jj+=h1.Integral()
    #print jj
    if aa is "ttbb" :  bb+=h1.Integral()
    if aa is "ttb"  :  b1+=h1.Integral()
    if aa is "tt2b" :  b2+=h1.Integral()

    if h1.GetMaximum()>scale: scale=h1.GetMaximum()
    if h1.GetMinimum()>0 and minimum<h1.GetMinimum(): minimum=h1.GetMinimum()
  label2 =""
  Nlabel2=0.
  #mctotal=0.
  for i,mc in enumerate(mcsamples):
    histname = "h1_"+mc['name']+"_"+mon+"_"+step+""
    h1 = f.Get(histname);
    h1.SetTitle("")
    #if i==0:
    #  h1.SetMaximum(scale*400)
    #  h1.SetMinimum(0.5)
    h1.SetStats(0)
    channel = step[2:4]
    isMC = mc['label'].find("DATA")==-1
    checkDataChannel = (channel=="mm" and mc['name']=="MuMu") or (channel=="ee" and mc['name']=="ElEl") or (channel=="em" and mc['name']=="MuEl") 
    if isMC : 
      h1.SetFillColor(mc['color'])
      h1.SetLineColor(kBlack)
      hs.Add(h1)
    elif checkDataChannel :
      h1.SetMaximum(scale*400)
      #if minimum<1:  h1.SetMinimum(minimum*0.5)
      #else : h1.SetMinimum(0.5)
      h1.SetMinimum(0.005)

      h1.GetYaxis().SetNdivisions(505);
      #h1.GetYaxis().SetLabelFont(42);
      h1.GetYaxis().SetLabelOffset(0.007);
      h1.GetYaxis().SetLabelSize(0.05);
      h1.GetYaxis().SetTitleSize(0.05);
      h1.GetYaxis().SetTitleOffset(1.4);
      h1.Draw()

    #lleng= len("%s"%mc['label'])
    #rleng= len(" %.0f"%h1.Integral())
    #lrleng = 22 - lleng - int(rleng/1.8)
    isSameBefore= mc['label'] is not label2
    label = ("%s"%mc['label']) + (" %.0f"%(h1.Integral()+Nlabel2) ).rjust(7)
    if isMC and isSameBefore and i<6: leg.AddEntry(h1, label, "f")
    elif isMC and isSameBefore      : leg2.AddEntry(h1, label, "f")

    if isMC and not isSameBefore : Nlabel2+=h1.Integral()
    elif isMC : Nlabel2=h1.Integral()
    label2=mc['label']


  #print "dddd"+str(type(hmctot))+("bbbb: %f"%hmctot.Integral())
  labeltot = ("MC Total") + (" %.0f"%hmctot.Integral()).rjust(8)
  leg2.AddEntry(hmctot,labeltot,"")

########
  xx=[]
  xxer=[]
  yy=[]
  yyer=[]
  for i in range(0, hmctot.GetNbinsX()+2 ):
    yy.append(  float(hmctot.GetBinContent(i)))
    yyer.append(float(hmctot.GetBinError(i)))
    xx.append(  float(hmctot.GetBinCenter(i)))
    xxer.append(float(hmctot.GetBinWidth(i)/2))

  x   = array("d",xx)
  xer = array("d",xxer)
  y   = array("d",yy)
  yer = array("d",yyer)
  gr = TGraphErrors(len(x), x,y,xer,yer)
  gr.SetFillColor(kBlack);
  gr.SetFillStyle(3144);
 
  hs.SetMinimum(minimum)
  hs.SetMaximum(hs.GetMaximum()*10)

  hs.Draw("same")
  gr.Draw("same,2")
  #hmctot.Draw("same,E2")

  for i,mc in enumerate(mcsamples):
    histname = "h1_"+mc['name']+"_"+mon+"_"+step+"_Sumw2"
    h1 = f.Get(histname);
    channel = step[2:4]
    checkDataChannel = (channel=="mm" and mc['name']=="MuMu") or (channel=="ee" and mc['name']=="ElEl") or (channel=="em" and mc['name']=="MuEl") 
    if checkDataChannel:
      label = ("%s"%mc['label']) + (" %.0f"%h1.Integral()).rjust(8)
      leg.AddEntry(h1,label,"p")
      h1.SetMarkerColor(kBlack)
      h1.SetLineColor(kBlack)
      h1.SetMarkerStyle(20)
      h1.SetMarkerSize(1)
      h1.SetMaximum(scale*400)
      h1.Draw("same")
      h1.Draw("sameaxis")

  leg.Draw()
  leg2.Draw()
  pad1.SetLogy()
  #pt = make_banner(0.15,0.73, 0.5, 0.89)
  bbb = 0.
  bbbb = 0.
  if jj>0:  bbb = bb/jj
  if jj>0:  bbbb = (bb+b1+bb)/jj
  #pt = make_banner2(0.12,0.66, 0.5, 0.89, bbb,bbbb )
  #pt.Draw()
  pad1.Modified()
  c1.cd()

  pad2 = TPad("pad2", "",0,0,1,0.3)
  pad2.Draw()
  pad2.cd()
  pad2.Range(-1.072875,-1.321429,5.364372,2.25)
  pad2.SetFillColor(0)
  pad2.SetBorderMode(0)
  pad2.SetBorderSize(2)
  pad2.SetTickx(1)
  pad2.SetTicky(1)
  pad2.SetLeftMargin(0.1666667)
  pad2.SetRightMargin(0.05660377)
  pad2.SetTopMargin(0.07)
  pad2.SetBottomMargin(0.37)
  pad2.SetFrameBorderMode(0)
  pad2.SetFrameBorderMode(0)
##############
  hdata.Divide(hmctot)
  hdata.SetTitle("")
#  hdata.GetYaxis().SetTitle("Data/MC")
  hdata.SetMaximum(2.0)
  hdata.SetMinimum(0.0)
##
  #hdata.GetXaxis().SetBinLabel(2,"1");
  #hdata.GetXaxis().SetBinLabel(3,"2");
  #hdata.GetXaxis().SetBinLabel(4,"3");
  #hdata.GetXaxis().SetBinLabel(5,"#geq4");
  #hdata.GetXaxis().SetLabelFont(42);
  hdata.GetXaxis().SetLabelOffset(0.007);
  hdata.GetXaxis().SetLabelSize(0.1);
  hdata.GetXaxis().SetTitleSize(0.14);
  hdata.GetXaxis().SetTitleOffset(1.1);
  #hdata.GetXaxis().SetTitleFont(42);
  hdata.GetYaxis().SetTitle("Data/MC");
  hdata.GetYaxis().SetNdivisions(505);
  #hdata.GetYaxis().SetLabelFont(42);
  hdata.GetYaxis().SetLabelOffset(0.007);
  hdata.GetYaxis().SetLabelSize(0.1);
  hdata.GetYaxis().SetTitleSize(0.14);
  hdata.GetYaxis().SetTitleOffset(0.4);
  #hdata.GetYaxis().SetTitleFont(42);
  hdata.SetMarkerColor(kBlack)
  hdata.SetLineColor(kBlack)
  hdata.SetMarkerStyle(20)
  hdata.SetMarkerSize(1)
##
  hdata.Draw()

###############
  pad2.Modified()
  c1.cd()
  c1.Modified()
  c1.cd()

  output = "plots/TH1_"+mon+"_"+step+".eps"
  c1.Print(output)
  f.Close()
  c1.Close()

#################
def merge(h1,h2) :
  y1=[]
  y2=[]
  y1er=[]
  y2er=[]
  for i in range(1, h1.GetNbinsX()+1 ):
    y1.append(  float(h1.GetBinContent(i)))
    y2.append(  float(h2.GetBinContent(i)))
    y1er.append(float(h1.GetBinError(i)))
    y2er.append(float(h2.GetBinError(i)))

  h1.Reset()
  for i in range(1, h1.GetNbinsX()+1 ):
    h1.SetBinContent(i,y1[i-1]+y2[i-1])
    h1.SetBinError(i,sqrt(y1er[i-1]*y1er[i-1]+y2er[i-1]*y2er[i-1]))
  return h1
