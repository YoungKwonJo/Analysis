from ROOT import *
import copy
from array import array
from math import sqrt

################
#log = False
log = True
useReturn =False

def h1_maker(tree, mon, cut):
  h1 =  TH1F( mon['name'], mon['title'], mon['xbin_set'][0],mon['xbin_set'][1],mon['xbin_set'][2])
  h1.GetXaxis().SetTitle(mon['x_name'])
  h1.GetYaxis().SetTitle(mon['y_name'])
  h1.Sumw2()
  tree.Project(mon['name'],mon['var'],cut)
  return h1  

def h1_set(name,monitor,cutname):
  mon = {  "name" : "h1_"+name+"_"+monitor['name']+"_"+cutname, "title" : name+" "+monitor['var'],
           "var" : monitor['var'],            "xbin_set" : monitor['xbin_set'],
           "x_name": monitor['unit'], "y_name": "Entries"
        }
  return mon

def h_all_maker(tree,mc, monitors, cuts, eventweight,Ntot):
  h = []
  for cutname in cuts["cut"]:
    for i,ii in enumerate(monitors):
      mon = h1_set(mc['name'],monitors[i],cutname+cuts["channel"])
      cut = "("+cuts["cut"][cutname]+" && "+mc['selection'] +")*("+str(eventweight)+"/"+str(Ntot)+")"
      h1 = h1_maker(tree,mon,cut)
      h.append(copy.deepcopy(h1))
  return h


######################
def h2_maker(tree, mon, cut):
  h2 =  TH2F( mon['name'], mon['title'], mon['xbin_set'][0],mon['xbin_set'][1],mon['xbin_set'][2], mon['ybin_set'][0],mon['ybin_set'][1],mon['ybin_set'][2])
  h2.GetXaxis().SetTitle(mon['x_name'])
  h2.GetYaxis().SetTitle(mon['y_name'])
  h2.Sumw2()
  tree.Project(mon['name'],mon['var'],cut)
  return h2  

def h2_set(name,monitor,monitor2,cutname):
  mon = {  "name" : "h2_"+name+"_"+monitor['name']+"_"+monitor2['name']+"_"+cutname, "title" : name+" "+monitor['var']+" vs "+monitor2['var'],
           "var" : monitor2['var']+":"+monitor['var'],         
           "xbin_set" : monitor['xbin_set'], "ybin_set" : monitor2['xbin_set'],
           "x_name": monitor['unit'], "y_name": monitor2['unit']
        }
  return mon

def h2_all_maker(tree,mc, monitors, cuts,eventweight,Ntot):
  h = []
  for cutname in cuts["cut"]:
    for i,ii in enumerate(monitors):
      for j,jj in enumerate(monitors):
        if i<j:
          mon2 = h2_set(mc['name'],monitors[i],monitors[j],cutname+cuts["channel"])
          cut = "("+cuts["cut"][cutname]+" && "+mc['selection']+")*("+str(eventweight)+"/"+str(Ntot)+")"
          h2 = h2_maker(tree,mon2,cut)
          h.append(copy.deepcopy(h2))
  return h

######################
######################
######################
######################
######################

def cut_maker(cuts_):
  cuts  = {}
  for i,cut in enumerate(cuts_["cut"]):
    if i==0 :
      cuts["S%d"%i]=cut
    else:
      cuts["S%d"%i]= cuts["S%d"%(i-1)] + " && " + cut
  cutsN = {"channel":cuts_["channel"],"cut":cuts}
  #if log : print cutsN
  return cutsN

def cut_maker2(cuts_):
  cuts  = {}
  for i,cut in enumerate(cuts_["cut"]):
      cuts["S%d"%i]=cut
  cutsN = {"channel":cuts_["channel"],"cut":cuts}
  return cuts
####################

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

    htot = f.Get("hNEvent")
    Ntot = htot.GetBinContent(1)
    if log : print "total:"+mc['file']+":"+str(round(Ntot))

    h= h+h_all_maker(tree,mcsamples[i],monitors,cuts,mceventweight,Ntot)
    f.Close()
  for i,mc in enumerate(datasamples):
    f = TFile.Open(datasamples[i]['file'],"read")
    #tree = f.ntuple
    tree = f.myresult
    htot = f.Get("hNEvent")
    Ntot = htot.GetBinContent(1)
    if log : print "total:"+mc['file']+":"+str(round(Ntot))

    h= h+h_all_maker(tree,datasamples[i],monitors,cuts,1,1)
    f.Close()

  return h

def ntuple2histQCD(json,cutsQCD):
  h = []
  #mcsamples = json['mcsamples']
  mceventweight = json['mceventweight']
  monitors=json['monitors']
  #datasamples = json['datasamples']
  qcdsamples = json['qcdsamples']
  for i,mc in enumerate(qcdsamples):
    f = TFile.Open(qcdsamples[i]['file'],"read")
    #tree = f.ntuple
    tree = f.myresult
    htot = f.Get("hNEvent")
    Ntot = htot.GetBinContent(1)
    if log : print "total:"+mc['file']+":"+str(round(Ntot))

    h= h+h_all_maker(tree,qcdsamples[i],monitors,cutsQCD,1,1)
    f.Close()

  return h



################
def ntuple2hist2d(json,cuts):
  h = []
  mcsamples = json['mcsamples']
  mceventweight = json['mceventweight']
  monitors2=json['monitors2']
  datasamples = json['datasamples']
  for i,mc in enumerate(mcsamples):
    f = TFile.Open(mcsamples[i]['file'],"read")
    #tree = f.ntuple
    tree = f.myresult

    htot = f.Get("hNEvent")
    Ntot = htot.GetBinContent(1)
    #if log : print "mc:"+mc['name']+":"+str(round(Ntot))

    h= h+h2_all_maker(tree,mcsamples[i],monitors2,cuts,mceventweight,Ntot)
    f.Close()

  for i,mc in enumerate(datasamples):
    f = TFile.Open(mcsamples[i]['file'],"read")
    #tree = f.ntuple
    tree = f.myresult
    h= h+h2_all_maker(tree,datasamples[i],monitors2,cuts,1,1)
    f.Close()
  return h


def ntuple2hist2dQCD(json,cutsQCD):
  h = []
  #mcsamples = json['mcsamples']
  mceventweight = json['mceventweight']
  monitors2=json['monitors2']
  #datasamples = json['datasamples']
  qcdsamples = json['qcdsamples']
  for i,mc in enumerate(qcdsamples):
    f = TFile.Open(qcdsamples[i]['file'],"read")
    #tree = f.ntuple
    tree = f.myresult
    h= h+h2_all_maker(tree,qcdsamples[i],monitors2,cutsQCD,1,1)
    f.Close()
  return h


def makeoutput(outputname, h):
  fout = TFile(outputname,"RECREATE")
  for a in h:
    a.Write()
  fout.Write()
  fout.Close()

###############
def makehist(json):
  cuts_  = cut_maker(json['cuts']) 
  cutsQCD_  = cut_maker(json['cutsQCD']) 
  h=[]
  if len(json['monitors'])>0 :
    h += ntuple2hist(json,cuts_)
    #h += ntuple2histQCD(json,cutsQCD_)
  if len(json['monitors2'])>0 :
    h += ntuple2hist2d(json,cuts_)
    #h += ntuple2hist2dQCD(json,cutsQCD_)
  makeoutput(json['output'],h)

def makehist2(json):
  cuts_  = cut_maker2(json['cuts']) 
  cutsQCD_  = cut_maker(json['cutsQCD']) 
  h=[]
  if len(json['monitors'])>0 :
    h += ntuple2hist(json,cuts_)
    #h += ntuple2histQCD(json,cutsQCD_)
  if len(json['monitors2'])>0 :
    h += ntuple2hist2d(json,cuts_)
    #h += ntuple2hist2dQCD(json,cutQCD_)
  makeoutput(json['output'],h)


###################################################
###################################################
###################################################
###################################################
###################################################
###################################################
###################################################
###################################################
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
  #pt.AddText("madgraphMLM-pythia8")
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

#########################
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


#########################
#########################
#########################
#########################
#########################
#########################
#########################
#########################
def myCanvas(name):
  c1 = TCanvas( name, '', 500, 500 )
#  gStyle.SetOptFit(1)
#  gStyle.SetOptStat(0)
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

  return c1

def myPad1(name):
  pad1 = TPad(name, "",0,0.3,1,1)
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

  return pad1

def myPad2(name):
  if log :  print "pad2() step0"
  pad2 = TPad(name, "",0,0,1,0.3)
  if log :  print "pad2() step1"
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

  return pad2

#################
def myDataHistSet(hdata):
  hdata.SetTitle("")
  hdata.SetStats(0)
  #hdata.SetMaximum(scale*400)
  #hdata.SetMinimum(0.005)
  hdata.GetYaxis().SetNdivisions(505);
  #hdata.GetYaxis().SetLabelFont(42);
  hdata.GetYaxis().SetLabelOffset(0.007);
  hdata.GetYaxis().SetLabelSize(0.05);
  hdata.GetYaxis().SetTitleSize(0.05);
  hdata.GetYaxis().SetTitleOffset(1.4);
  hdata.SetMarkerColor(kBlack)
  hdata.SetLineColor(kBlack)
  hdata.SetMarkerStyle(20)
  hdata.SetMarkerSize(1)
 
  return hdata

def myBottomDataPerMCSet(hdata):
  hdataMC = hdata.Clone("hdataMC")
  hdataMC.SetTitle("")
  hdataMC.SetMaximum(2.0)
  hdataMC.SetMinimum(0.0)
  hdataMC.GetXaxis().SetLabelOffset(0.007);
  hdataMC.GetXaxis().SetLabelSize(0.1);
  hdataMC.GetXaxis().SetTitleSize(0.14);
  hdataMC.GetXaxis().SetTitleOffset(1.1);
  #hdataMC.GetXaxis().SetTitleFont(42);
  hdataMC.GetYaxis().SetTitle("Data/MC");
  hdataMC.GetYaxis().SetNdivisions(505);
  #hdataMC.GetYaxis().SetLabelFont(42);
  hdataMC.GetYaxis().SetLabelOffset(0.007);
  hdataMC.GetYaxis().SetLabelSize(0.1);
  hdataMC.GetYaxis().SetTitleSize(0.14);
  hdataMC.GetYaxis().SetTitleOffset(0.4);
  #hdataMC.GetYaxis().SetTitleFont(42);
  hdataMC.SetMarkerColor(kBlack)
  hdataMC.SetLineColor(kBlack)
  hdataMC.SetMarkerStyle(20)
  hdataMC.SetMarkerSize(1)

  return hdataMC

def myHist2TGraphError(hist1):
  xx=[]
  xxer=[]
  yy=[]
  yyer=[]
  for i in range(0, hist1.GetNbinsX()+2 ):
    yy.append(  float(hist1.GetBinContent(i)))
    yyer.append(float(hist1.GetBinError(i)))
    xx.append(  float(hist1.GetBinCenter(i)))
    xxer.append(float(hist1.GetBinWidth(i)/2))

  x   = array("d",xx)
  xer = array("d",xxer)
  y   = array("d",yy)
  yer = array("d",yyer)
  gr = TGraphErrors(len(x), x,y,xer,yer)
  gr.SetFillColor(kBlack);
  gr.SetFillStyle(3144);

  return gr
#####################


#####################
def singleplotStack2(filename,mon,step,mcsamples,datasamples):
  f = TFile.Open(filename,"read")
  singleplotStack(f,mon,step,mcsamples,datasamples)
  f.Close()

def singleplotStack(f,mon,step,mcsamples,datasamples):
  #f = TFile.Open(filename,"read")
  canvasname = mon+step
  c1 = myCanvas(canvasname)
  #c1 = TCanvas( 'c1', '', 500, 500 )
  if log : print mon+step
  gStyle.SetOptFit(1)
  gStyle.SetOptStat(0)

  #pad1 = TPad("pad1", "",0,0.3,1,1);
  pad1 = myPad1(canvasname+"pad1") 
  pad1.Draw()
  pad1.cd()

  leg  = make_legend(0.67,0.64, 0.89,0.88)
  leg2 = make_legend(0.43,0.64, 0.62,0.88)
  jj = 0.
  bb = 0.
  b1 = 0.
  b2 = 0.
  lumi = 40.028
  #lumi = 10.028
  hs = THStack("hs","")

  hmctotName = "h1_"+mcsamples[0]['name']+"_"+mon+"_"+step
  #if log : print "hmcTotal: "+hmctotName
  hmctot = f.Get(hmctotName).Clone("hmctot")
  hmctot.Reset()
  hdata = hmctot.Clone("hdata")


  label2 =""
  Nlabel2=0.
  #if log : print mcsamples
  #hMCHist  = []
  #mcLegend = []
  for i,mc in enumerate(mcsamples):
    isMC = mc['label'].find("DATA")==-1
    if not isMC: continue

    histnameS = "h1_"+mc['name']+"_"+mon+"_"+step
    channel = step[2:4]
    h2 = f.Get(histnameS)
    if type(h2) is not TH1F :
      return

    #htot = f.Get("hNEvent")
    h2.GetYaxis().SetTitle("Events")
    #Ntot = htot.GetBinContent(1)

    h2.AddBinContent(h2.GetNbinsX(),h2.GetBinContent(h2.GetNbinsX()+1))
    #if h2.Integral()>0 :  h2.Scale(mc['cx']/Ntot*lumi)
    if h2.Integral()>0 :  h2.Scale(mc['cx']*lumi)

    ###############
    aa = mc['name']
    isJJ = ( (aa is "ttbb") or (aa is "ttb") or (aa is "tt2b") or (aa is "ttcc") or (aa is "ttlf") )
    if isJJ :  jj+=h2.Integral()
    #if log : print jj
    if aa is "ttbb" :  bb+=h2.Integral()
    if aa is "ttb"  :  b1+=h2.Integral()
    if aa is "tt2b" :  b2+=h2.Integral()
    ###############

    h2.SetFillColor(mc['color'])
    h2.SetLineColor(kBlack)
    hmctot.Add( h2 )
    hs.Add(h2)

    selEvet=h2.Integral() 
    selEnts=h2.GetEntries()
    if log : print "mc:"+mc['file']+":"+str(round(selEvet))+", "+str(selEnts)
    #lleng= len("%s"%mc['label'])
    #rleng= len(" %.0f"%h1.Integral())
    #lrleng = 22 - lleng - int(rleng/1.8)
    isSameBefore= mc['label'] is not label2
    label = ("%s"%mc['label']) + (" %.0f"%(h2.Integral()+Nlabel2) ).rjust(7)
    if  isSameBefore and i<6: leg.AddEntry(h2, label, "f")
    elif isSameBefore       : leg2.AddEntry(h2, label, "f")

    if  not isSameBefore : Nlabel2+=h2.Integral()
    else                 : Nlabel2=h2.Integral()
    label2=mc['label']
    #hMCHist.append(copy.deepcopy(h2))
    #mcLegent.append()


  hdata.Reset()
  for i,mc in enumerate(datasamples):
    histnameS = "h1_"+mc['name']+"_"+mon+"_"+step
    channel = step[2:4]
    h1 = f.Get(histnameS)
    if type(h1) is not TH1F :
      return
    h1.GetYaxis().SetTitle("Events")

    h1.AddBinContent(h1.GetNbinsX(),h1.GetBinContent(h1.GetNbinsX()+1))
    selEvet=h1.Integral() 
    selEnts=h1.GetEntries()
 
    aa = mc['name']
    checkDataChannel = (channel=="mm" and mc['name']=="MuMu") or (channel=="ee" and mc['name']=="ElEl") or (channel=="em" and mc['name']=="MuEl")
    checkZMass = ( channel=="mm" and mon=="ZMassMM") or (channel=="ee" and mon=="ZMassEE") or (channel=="em" and mon=="ZMassEM") or (not ( mon=="ZMassMM" or  mon=="ZMassEE" or mon=="ZMassEM"))
    if checkDataChannel and checkZMass: 
      hdata.Add(h1)
      if log : print "data:"+mc['file']+": "+str(round(selEvet))+", "+str(selEnts)
      #if not (round(selEvet) == round(selEnts)) : return 
################################
  scale = hmctot.GetMaximum()
  minimum = 0.00005

  h1data = hdata.Clone("h1data")
  h2data = myDataHistSet(h1data)

  h2data.SetMaximum(scale*400)
  h2data.SetMinimum(minimum)
  #if log :  print "dddd"+str(type(hmctot))+("bbbb: %f"%hmctot.Integral())
  labeltot = ("MC Total") + (" %.0f"%hmctot.Integral()).rjust(8)
  leg2.AddEntry(hmctot,labeltot,"")
  labeldata = ("DATA") + (" %.0f"%h2data.Integral()).rjust(8)
  leg.AddEntry(h2data,labeldata,"p")

#########################################
  h2data.GetYaxis().SetTitle("Events")
  h2data.Draw()
  hs.Draw("same,hist")
  gr = myHist2TGraphError(hmctot)
  gr.Draw("same,2")
  h2data.Draw("same")
#  h2data.Draw("sameaxis")


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
###########################################
  if log :  print "pad1 step"
  #pad2 = TPad("pad2", "",0,0,1,0.3)
  pad2 = myPad2(canvasname+"pad2")

  if log :  print "pad2 step1"
  pad2.Draw()
  pad2.cd()
  hdata.Divide(hmctot)

  #if log : print "divide start"+str(hdata.Integral())
  hdataMC = myBottomDataPerMCSet(hdata)

  #if log : print "divide end"
  hdataMC.Draw()

  pad2.Modified()
  c1.cd()
  c1.Modified()
  c1.cd()

  output = "plots/TH1_"+mon+"_"+step+".eps"
  c1.Print(output)

  #f.Close()
  #c1.Close()
  if useReturn : return c1,pad1,pad2,hs,gr,h2data,hdataMC,leg,leg2
  else : c1.Close() 
    
############################################
############################################
##################################################
##################################################
############################################
############################################
def singleplotStackLL2(filename,mon,step,mcsamples,datasamples):
  f = TFile.Open(filename,"read")
  singleplotStackLL(f,mon,step,mcsamples,datasamples)
  f.Close()

def singleplotStackLL(f,mon,step,mcsamples,datasamples):
  #f = TFile.Open(filename,"read")
  canvasname = mon+step
  c1 = myCanvas(canvasname)
  #c1 = TCanvas( 'c1', '', 500, 500 )
  if log : print mon+step
  gStyle.SetOptFit(1)
  gStyle.SetOptStat(0)

  #pad1 = TPad("pad1", "",0,0.3,1,1);
  pad1 = myPad1(canvasname+"pad1") 
  pad1.Draw()
  pad1.cd()

  leg  = make_legend(0.67,0.64, 0.89,0.88)
  leg2 = make_legend(0.43,0.64, 0.62,0.88)
  jj = 0.
  bb = 0.
  b1 = 0.
  b2 = 0.
  lumi = 40.028
  #lumi = 10.028
  hs = THStack("hs","")

  hmctotName = "h1_"+mcsamples[0]['name']+"_"+mon+"_"+step
  #if log : print "hmcTotal: "+hmctotName
  hmctot = f.Get(hmctotName).Clone("hmctot")
  hmctot.Reset()
  hdata = hmctot.Clone("hdata")


  label2 =""
  Nlabel2=0.
  #if log : print mcsamples
  #hMCHist  = []
  #mcLegend = []
  for i,mc in enumerate(mcsamples):
    isMC = mc['label'].find("DATA")==-1
    if not isMC: continue

    histnameSmm = "h1_"+mc['name']+"_"+mon+"_"+step+"mm"
    histnameSee = "h1_"+mc['name']+"_"+mon+"_"+step+"ee"
    histnameSem = "h1_"+mc['name']+"_"+mon+"_"+step+"em"
    #channel = step[2:4]
    h2ll = f.Get(histnameSmm)
    h2ee = f.Get(histnameSee)
    h2em = f.Get(histnameSem)
    if type(h2mm) is not TH1F :
      return

    h2ll.AddBinContent(h2mm.GetNbinsX(),h2mm.GetBinContent(h2mm.GetNbinsX()+1))
    h2ee.AddBinContent(h2ee.GetNbinsX(),h2ee.GetBinContent(h2ee.GetNbinsX()+1))
    h2em.AddBinContent(h2em.GetNbinsX(),h2em.GetBinContent(h2em.GetNbinsX()+1))
    #if h2.Integral()>0 :  h2.Scale(mc['cx']/Ntot*lumi)
    h2ll.Add(h2ee)
    h2ll.Add(h2em)

    if h2ll.Integral()>0 :  h2ll.Scale(mc['cx']*lumi)

    ###############
    aa = mc['name']
    isJJ = ( (aa is "ttbb") or (aa is "ttb") or (aa is "tt2b") or (aa is "ttcc") or (aa is "ttlf") )
    if isJJ :  
      jj+=h2ll.Integral()
    #if log : print jj
    if aa is "ttbb" :
      bb+=h2ll.Integral()
    if aa is "ttb"  :
      b1+=h2ll.Integral()
    if aa is "tt2b" :
      b2+=h2ll.Integral()
    ###############
    h2ll.SetFillColor(mc['color'])
    h2ll.SetLineColor(kBlack)
    hmctot.Add( h2ll )
    hs.Add( h2ll )

    selEvet=h2ll.Integral() 
    selEnts=h2ll.GetEntries()
    if log : print "mc:"+mc['file']+":"+str(round(selEvet))+", "+str(selEnts)
    #lleng= len("%s"%mc['label'])
    #rleng= len(" %.0f"%h1.Integral())
    #lrleng = 22 - lleng - int(rleng/1.8)
    isSameBefore= mc['label'] is not label2
    label = ("%s"%mc['label']) + (" %.0f"%(h2ll.Integral()+Nlabel2) ).rjust(7)
    if  isSameBefore and i<6: leg.AddEntry(h2ll, label, "f")
    elif isSameBefore       : leg2.AddEntry(h2ll, label, "f")

    if  not isSameBefore : Nlabel2+=h2ll.Integral()
    else                 : Nlabel2=h2ll.Integral()
    label2=mc['label']
    #hMCHist.append(copy.deepcopy(h2))
    #mcLegent.append()


  hdata.Reset()
  for i,mc in enumerate(datasamples):
    histnameSmm = "h1_"+mc['name']+"_"+mon+"_"+step+"mm"
    histnameSee = "h1_"+mc['name']+"_"+mon+"_"+step+"ee"
    histnameSem = "h1_"+mc['name']+"_"+mon+"_"+step+"em"
    channel = step[2:4]
    h1ll = f.Get(histnameSmm)
    h1ee = f.Get(histnameSee)
    h1em = f.Get(histnameSem)
    if type(h1ll) is not TH1F :
      return
    h1lll.GetYaxis().SetTitle("Events")

    h1ll.AddBinContent(h1ll.GetNbinsX(),h1ll.GetBinContent(h1ll.GetNbinsX()+1))
    h1ee.AddBinContent(h1ee.GetNbinsX(),h1ee.GetBinContent(h1ee.GetNbinsX()+1))
    h1em.AddBinContent(h1em.GetNbinsX(),h1em.GetBinContent(h1em.GetNbinsX()+1))
    h1ll.Add(h1ee)
    h1ll.Add(h1em)

    selEvet=h1ll.Integral() 
    selEnts=h1ll.GetEntries()
 
    aa = mc['name']
    checkDataChannel = (channel=="mm" and mc['name']=="MuMu") or (channel=="ee" and mc['name']=="ElEl") or (channel=="em" and mc['name']=="MuEl")
    checkZMass = ( channel=="mm" and mon=="ZMassMM") or (channel=="ee" and mon=="ZMassEE") or (channel=="em" and mon=="ZMassEM") or (not ( mon=="ZMassMM" or  mon=="ZMassEE" or mon=="ZMassEM"))
    if checkDataChannel and checkZMass: 
      hdata.Add(h1ll)
      if log : print "data:"+mc['file']+": "+str(round(selEvet))+", "+str(selEnts)
      #if not (round(selEvet) == round(selEnts)) : return 
################################
  scale = hmctot.GetMaximum()
  minimum = 0.00005

  h1data = hdata.Clone("h1data")
  h2data = myDataHistSet(h1data)

  h2data.SetMaximum(scale*400)
  h2data.SetMinimum(minimum)
  #if log :  print "dddd"+str(type(hmctot))+("bbbb: %f"%hmctot.Integral())
  labeltot = ("MC Total") + (" %.0f"%hmctot.Integral()).rjust(8)
  leg2.AddEntry(hmctot,labeltot,"")
  labeldata = ("DATA") + (" %.0f"%h2data.Integral()).rjust(8)
  leg.AddEntry(h2data,labeldata,"p")

#########################################
  h2data.GetYaxis().SetTitle("Events")
  h2data.Draw()
  hs.Draw("same,hist")
  gr = myHist2TGraphError(hmctot)
  gr.Draw("same,2")
  h2data.Draw("same")
#  h2data.Draw("sameaxis")


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
###########################################
  if log :  print "pad1 step"
  #pad2 = TPad("pad2", "",0,0,1,0.3)
  pad2 = myPad2(canvasname+"pad2")

  if log :  print "pad2 step1"
  pad2.Draw()
  pad2.cd()
  hdata.Divide(hmctot)

  #if log : print "divide start"+str(hdata.Integral())
  hdataMC = myBottomDataPerMCSet(hdata)

  #if log : print "divide end"
  hdataMC.Draw()

  pad2.Modified()
  c1.cd()
  c1.Modified()
  c1.cd()

  output = "plots/TH1_"+mon+"_"+step+"LL.eps"
  c1.Print(output)

  #f.Close()
  #c1.Close()
  if useReturn : return c1,pad1,pad2,hs,gr,h2data,hdataMC,leg,leg2
  else : c1.Close() 
    
############################################
