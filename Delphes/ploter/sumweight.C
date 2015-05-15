
void sumweight() {
   string aaa[] = {"result_ttbb_cut_bq.root","result_tth_cut_bq.root","result_ttjj_woSPIN.root","result_ttbb_woSPIN_cut_bq.root","result_tth_woSPIN.root"};
   string bbb[] = {"ttbb_2","tth_2","ttjj_1","ttbb_4","tth_4"};

   /*
   Sample ttbb_2  = Sample(path+"/result_ttbb_cut_bq.root","ntuple","ttbb_2","t#bar{t}b#bar{b}",kRed ,1,2,true, 4.729e+00*0.04553956,); // xsec unit : pb
   Sample tth_2   = Sample(path+"/result_tth_cut_bq.root", "ntuple","tth_2" ,"t#bar{t}H "       ,kGreen-7 ,1,2,true,3.234e-01*0.04553956,); // xsec unit : pb
   Sample ttjj_2  = Sample(path+"/result_ttjj_SPIN_LO.root","ntuple","ttjj_2","t#bar{t}jj LO "    ,kBlue+1,1,2,true,20.935801482312659,1); // xsec unit : pb
//   Sample ttjj_1 = Sample(path+"/result_ttjj_woSPIN.root","ntuple","ttjj_1","t#bar{t}jj "    ,kBlue+1,1,2,true,2.238e+02,); // xsec unit : pb
//   Sample ttjj_3 = Sample(path+"/result_ttjj_LO.root","ntuple","ttjj_3","t#bar{t}jj LO "    ,kBlue+1,1,2,true,423.55676178935778,1); // xsec unit : pb
   Sample ttbb_4 = Sample(path+"/result_ttbb_woSPIN_cut_bq.root","ntuple","ttbb_4","t#bar{t} + b#bar{b}",kRed ,1,2,true, 4.729e+00,); // xsec unit : pb
   Sample tth_4  = Sample(path+"/result_tth_woSPIN.root", "ntuple","tth_4" ,"t#bar{t} + H "       ,kGreen-7 ,1,2,true,4.455e-01,); // xsec unit : pb
   Sample ttjj_4 = Sample(path+"/result_ttjj_LO2.root","ntuple","ttjj_3","t#bar{t}jj LO "    ,kBlue+1,1,2,true,424.14756200450773,1);
   */
   double ccc[5];
   for(int i=0;i<5;i++)
   {
      ccc[i] = sumweight2(aaa[i]);
      cout << bbb[i] <<" : " << ccc[i] << endl; 
   }
         
}
double sumweight2(string str_)
{

   const string path ="/cms/home/youngjo/Madgraph/Analysis/new20GeV_v13/";
   TFile f((path+str_).c_str());
   TH1F *hSumWeight = (TH1F*) f.Get("hSumWeight");
   return hSumWeight->GetBinContent(1);
}
