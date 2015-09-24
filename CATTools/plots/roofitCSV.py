#! /usr/bin/env python

#from ROOT import TStyle, TF1, TFile, TCanvas, gDirectory, TTree, TH1F, TH2F, THStack, TLegend, gROOT,TGraphErrors
#from ROOT import RooRealVar,RooFormulaVar,RooDataHist,RooHistPdf,RooAddPdf,RooArgList,RooFit,RooMinuit,RooAbsData
import ROOT
from ROOT import *
from array import array
import copy


#ROOT.gROOT.Macro("rootlogon.C")
#h1_DYJets_MET_S4mm
#HN = "nBJet30M"
HN = "jetCSV4"
from mcsample_cfi import mcsamples,datasamples 
lumi = 15.478

#histograms = ["name":"name","hist": ]
histograms = {}
f= TFile.Open("hist_all.root")
#for name in mcnames:
for mc in mcsamples:
  name = mc['name']
  color = mc['color'] 
  h1 = f.Get("h1_"+name+"_"+HN+"_S4mm").Clone("h1_"+name+"_"+HN+"_S4LL")
  h2 = f.Get("h1_"+name+"_"+HN+"_S4ee")
  h3 = f.Get("h1_"+name+"_"+HN+"_S4em")
  if h1.Integral()>0 :  h1.Scale(mc['cx']*lumi)
  if h2.Integral()>0 :  h2.Scale(mc['cx']*lumi)
  if h3.Integral()>0 :  h3.Scale(mc['cx']*lumi)

  h1.Add(h2)
  h1.Add(h3)
  histograms[name]={"h1":copy.deepcopy(h1),"color":color,"exp":h1.Integral()}
  #print "FINAL "+name

#for datesmaples
for i in range(1):
  name_ = "DATA"
  color = mc['color'] 
  h1 = f.Get("h1_MuMu_"+HN+"_S4mm").Clone("h1_"+name_+"_"+HN+"_S4LL")
  h2 = f.Get("h1_ElEl_"+HN+"_S4ee")
  h3 = f.Get("h1_MuEl_"+HN+"_S4em")
  h1.Add(h2)
  h1.Add(h3)
  histograms[name_]={"h1":copy.deepcopy(h1),"color":kBlack,"exp":h1.Integral()}

print str(type(histograms))
print str(histograms["AMCttbb"]["color"])
print str(histograms["AMCttbb"]["exp"])
print ""
print str(histograms["DATA"]["color"])
print str(histograms["DATA"]["exp"])

signals1= ['AMCttbb', 'AMCttb', 'AMCtt2b']
signals2= ['AMCttcc', 'AMCttlf']#, 'AMCttot']
backgrounds1= ["AMCttot"]
backgrounds2= ['TTWlNu', 'TTWqq', 'TTZll', 'TTZqq', 'STbt', 'STt', 'STbtW', 'STtW', 'WJets', 'WW', 'WZ', 'ZZ', 'DYJets']
higgs= ['ttH2non', 'ttH2bb']

bkghist = histograms['AMCttot']["h1"].Clone("bkghist")
bkghist.Reset()

ttcclfhist = histograms['AMCttot']["h1"].Clone("ttcclfhist")
ttcclfhist.Reset()
for hh in signals2:
  h = histograms[hh]["h1"]
  ttcclfhist.Add(h)
histograms["AMCttcclf"]={"h1":copy.deepcopy(ttcclfhist),"color":kOrange,"exp":ttcclfhist.Integral()}

for hh in backgrounds2:
  h = histograms[hh]["h1"]
  bkghist.Add(h)
  #print "FINAL "+hh
histograms["bkg"]={"h1":copy.deepcopy(bkghist),"color":kGray,"exp":bkghist.Integral()}


n_ttbb = histograms["AMCttbb"]["exp"]
n_ttb  = histograms["AMCttb"]["exp"]
n_tt2b = histograms["AMCtt2b"]["exp"]
n_ttcc = histograms["AMCttcc"]["exp"]
n_ttlf = histograms["AMCttlf"]["exp"]
n_ttcclf = histograms["AMCttcclf"]["exp"]
n_ttot = histograms["AMCttot"]["exp"]
n_bkg = histograms["bkg"]["exp"]
n_data = histograms["DATA"]["exp"]

n_ttjj = n_ttbb+n_ttb+n_tt2b+n_ttcc+n_ttlf
n_ttbar = n_ttjj+n_ttot

print "n_ttbb:"+str(n_ttbb)
print "n_ttb:"+str(n_ttb)
print "n_tt2b:"+str(n_tt2b)
print "n_ttcc:"+str(n_ttcc)
print "n_ttlf:"+str(n_ttlf)
print "n_ttot:"+str(n_ttot)
print "n_bkg:"+str(n_bkg)
print "n_data:"+str(n_data)


rttbb = n_ttbb/n_ttjj
rttb  = n_ttb/n_ttjj
rtt2b = n_tt2b/n_ttjj
rttcc = n_ttcc/n_ttjj

x=RooRealVar("x","x",bkghist.GetXaxis().GetXmin(),bkghist.GetXaxis().GetXmax()) 
RttbbReco=RooRealVar("RttbbReco","RttbbReco",rttbb,rttbb,rttbb);
RttbReco =RooRealVar("RttbReco", "RttbReco", rttb, rttb, rttb);
Rtt2bReco=RooRealVar("Rtt2bReco","Rtt2bReco",rtt2b,rtt2b,rtt2b);
RttccReco=RooRealVar("RttccReco","RttccReco",rttcc,rttcc,rttcc);

fsig   =RooRealVar(    "fsig",                "fsig",           rttbb, 0.0, 0.2) 
fsig2  =RooFormulaVar("fsig2",               "fsig2","@0/@1*@2",RooArgList(fsig,RttbbReco,RttbReco) )
fsig3  =RooFormulaVar("fsig3",               "fsig3","@0/@1*@2",RooArgList(fsig2,RttbbReco,RttbReco,Rtt2bReco) )
fsigcc =RooRealVar(  "fsigcc",              "fsigcc",           rttcc, 0.0, 0.5) 
k      =RooRealVar(       "k","normalization factor",           1, 0.5, 1.5) 

nttjj =RooRealVar(    "nttjj","number of ttjj events",                            n_ttjj , n_ttjj, n_ttjj)
knttjj=RooFormulaVar("knttjj","number of ttjj events after fitting","k*nttjj",    RooArgList(k,nttjj) )
nttot =RooRealVar(    "nttot","number of ttot events",                            n_ttot , n_ttot, n_ttot)
knttot=RooFormulaVar("knttot","number of ttot events after fitting","k*nttot",    RooArgList(k,nttot) )
nbkg  =RooRealVar(     "nbkg","number of background events",                      n_bkg , n_bkg, n_bkg)
knbkg=RooFormulaVar("knbkg","number of background events after fitting","k*nbkg", RooArgList(k,nbkg) )

nttcc  =RooRealVar(     "nttcc","number of ttcc events",                            n_ttcc , n_ttcc, n_ttcc)
#nttbar =RooRealVar(    "nttbar","number of ttbar events",                           n_ttbar , n_ttbar, n_ttbar)
#knttbar=RooFormulaVar("knttbar","number of ttbar events after fitting","k*nttbar",  RooArgList(k,nttbar) )

#histogram
data    = RooDataHist("data",    "data set with (x)",   RooArgList(x), histograms["DATA"]["h1"])
ttbb    = RooDataHist("ttbb",    "ttbb set with (x)",   RooArgList(x), histograms["AMCttbb"]["h1"])
ttb     = RooDataHist("ttb",     "ttb  set with (x)",   RooArgList(x), histograms["AMCttb"]["h1"])
tt2b    = RooDataHist("tt2b",    "tt2b set with (x)",   RooArgList(x), histograms["AMCtt2b"]["h1"])
ttcc    = RooDataHist("ttcc",    "ttcc set with (x)",   RooArgList(x), histograms["AMCttcc"]["h1"])
ttlf    = RooDataHist("ttlf",    "ttlf set with (x)",   RooArgList(x), histograms["AMCttlf"]["h1"])
ttcclf  = RooDataHist("ttcclf",  "ttcclf set with (x)", RooArgList(x), histograms["AMCttcclf"]["h1"])
ttot    = RooDataHist("ttot",    "ttot set with (x)",   RooArgList(x), histograms["AMCttot"]["h1"])
bkg     = RooDataHist("bkg",     "bkg  set with (x)",   RooArgList(x), histograms["bkg"]["h1"])

#print "ttbar type: "+str(type(ttbar))
#print "rooArglist(x):"+str(type(RooArgList(x)))

#pdf
ttbbpdf      = RooHistPdf("ttbbpdf",     "ttbbpdf",      RooArgList(x), RooArgList(x), ttbb)
ttbpdf       = RooHistPdf("ttbpdf",      "ttbpdf",       RooArgList(x), RooArgList(x), ttb)
tt2bpdf      = RooHistPdf("tt2bpdf",     "tt2bpdf",      RooArgList(x), RooArgList(x), tt2b)
ttccpdf      = RooHistPdf("ttccpdf",     "ttccpdf",      RooArgList(x), RooArgList(x), ttcc)
ttlfpdf      = RooHistPdf("ttlfpdf",     "ttlfpdf",      RooArgList(x), RooArgList(x), ttlf)
ttcclfpdf    = RooHistPdf("ttcclfpdf",   "ttcclfpdf",    RooArgList(x), RooArgList(x), ttcclf)
ttotpdf      = RooHistPdf("ttotpdf",     "ttotpdf",      RooArgList(x), RooArgList(x), ttot)
bkgpdf       = RooHistPdf("bkgpdf",      "bkgpdf",       RooArgList(x), RooArgList(x), bkg)

#for separate ttcc
#model  = RooAddPdf("model",   "model",RooArgList( ttbbpdf, ttbpdf, tt2bpdf, ttccpdf, ttlfpdf), RooArgList(fsig,fsig2,fsigcc))
#for merge ttcc+ttlf
model  = RooAddPdf("model",   "model",RooArgList( ttbbpdf, ttbpdf, tt2bpdf, ttcclfpdf), RooArgList(fsig,fsig2,fsig3))
model2 = RooAddPdf("model2", "model2",RooArgList( model, ttotpdf, bkgpdf),              RooArgList(knttjj,knttot,knbkg))
model2.fitTo(data)
#model2.fitTo(ttlf)

recoR      = fsig.getVal()
recoRerror = fsig.getError()

kVal      = k.getVal()
kValerror = k.getError()
  
print "FINAL: ttbb Rreco = "+ str(recoR)+" +- "+str(recoRerror)
print "FINAL: k = "+str(kVal)+" +- "+str(kValerror) 

nll = model2.createNLL(data)
#nll = model2.createNLL(ttlf)
#RooMinuit(nk1).migrad() 
RFrame = fsig.frame()
nll.plotOn(RFrame,RooFit.ShiftToZero()) 
c1 = TCanvas("c1", "c1", 500, 500)
RFrame.SetMaximum(4.);RFrame.SetMinimum(0)
RFrame.GetXaxis().SetTitle("nttbb/nttjj")
RFrame.SetTitle("")
RFrame.Draw()


cR11 = TCanvas("R11", "R", 500, 500)
xframe = x.frame()
data.plotOn(xframe, RooFit.DataError(RooAbsData.SumW2) ) 
model2.paramOn(xframe, RooFit.Layout(0.65,0.9,0.9) )
model2.plotOn(xframe)
chi2 = xframe.chiSquare(2)
ndof = xframe.GetNbinsX()
print "chi2 = "+ str(chi2)
print "ndof = "+ str(ndof)
xframe.Draw()


