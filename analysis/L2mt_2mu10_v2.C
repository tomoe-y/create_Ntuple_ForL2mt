#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <cmath>
#include <stdio.h>
#include "TChain.h"
#include "TFile.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TCanvas.h"
#include "TVector2.h"
#include "TVector3.h"
#include "TLorentzVector.h"

void L2mt_2mu10_v2(){
    TChain* chain = new TChain("analysis");

    //v5 -> include isPassed
    //chain->Add("/gpfs/fs8001/toyamash/L2mt/user.toyamash.data23_13p6TeV.00453733.physics_Main.merge.AOD.f1357_m2179.Run3-22.0.107-00-01.5_NTUP_ANALYSIS/user.toyamash.34655580.ANALYSIS._000001.root");
    //chain->Add("/gpfs/fs8001/toyamash/L2mt/user.toyamash.data23_13p6TeV.00453733.physics_Main.merge.AOD.f1357_m2179.Run3-22.0.107-00-01.5_NTUP_ANALYSIS/*.root");
    //chain->Add("/gpfs/fs8001/toyamash/L2mt/user.toyamash.data23_13p6TeV.00453353.physics_Main.merge.AOD.f1357_m2179.Run3-22.0.107-00-01.5_NTUP_ANALYSIS/*.root");
    //chain->Add("/gpfs/fs8001/toyamash/L2mt/user.toyamash.data23_13p6TeV.00453530.physics_Main.merge.AOD.f1357_m2179.Run3-22.0.107-00-01.5_NTUP_ANALYSIS/*.root");
    //chain->Add("/gpfs/fs8001/toyamash/L2mt/user.toyamash.data23_13p6TeV.00453556.physics_Main.merge.AOD.f1357_m2179.Run3-22.0.107-00-01.5_NTUP_ANALYSIS/*.root");
    //chain->Add("/gpfs/fs8001/toyamash/L2mt/user.toyamash.data23_13p6TeV.00453617.physics_Main.merge.AOD.f1357_m2179.Run3-22.0.107-00-01.5_NTUP_ANALYSIS/*.root");
    //chain->Add("/gpfs/fs8001/toyamash/L2mt/user.toyamash.data23_13p6TeV.00453644.physics_Main.merge.AOD.f1357_m2179.Run3-22.0.107-00-01.5_NTUP_ANALYSIS/*.root");
    //chain->Add("/gpfs/fs8001/toyamash/L2mt/user.toyamash.data23_13p6TeV.00453657.physics_Main.merge.AOD.f1357_m2179.Run3-22.0.107-00-01.5_NTUP_ANALYSIS/*.root");
    //chain->Add("/gpfs/fs8001/toyamash/L2mt/user.toyamash.data23_13p6TeV.00453713.physics_Main.merge.AOD.f1357_m2179.Run3-22.0.107-00-01.5_NTUP_ANALYSIS/*.root");
    //chain->Add("/gpfs/fs8001/toyamash/L2mt/user.toyamash.data23_13p6TeV.00453754.physics_Main.merge.AOD.f1357_m2179.Run3-22.0.107-00-01.5_NTUP_ANALYSIS/*.root");
    //chain->Add("/gpfs/fs8001/toyamash/L2mt/user.toyamash.data23_13p6TeV.00453816.physics_Main.merge.AOD.f1360_m2179.Run3-22.0.107-00-01.5_NTUP_ANALYSIS/*.root");

    //chain->Add("/gpfs/fs8001/toyamash/L2mt/20230908/user.toyamash.data23_13p6TeV.00451587.physics_Main.merge.AOD.r14858_p5785.Run3-22.0.107-00-01.5_NTUP_ANALYSIS/*.root");
    //chain->Add("/gpfs/fs8001/toyamash/L2mt/20230908/user.toyamash.data23_13p6TeV.00451618.physics_Main.merge.AOD.r14858_p5785.Run3-22.0.107-00-01.5_NTUP_ANALYSIS/*.root");
    //chain->Add("/gpfs/fs8001/toyamash/L2mt/20230908/user.toyamash.data23_13p6TeV.00451735.physics_Main.merge.AOD.r14858_p5785.Run3-22.0.107-00-01.5_NTUP_ANALYSIS/*.root");
    //chain->Add("/gpfs/fs8001/toyamash/L2mt/20230908/user.toyamash.data23_13p6TeV.00451794.physics_Main.merge.AOD.r14858_p5785.Run3-22.0.107-00-01.5_NTUP_ANALYSIS/*.root");
    //chain->Add("/gpfs/fs8001/toyamash/L2mt/20230908/user.toyamash.data23_13p6TeV.00451804.physics_Main.merge.AOD.r14858_p5785.Run3-22.0.107-00-01.5_NTUP_ANALYSIS/*.root");
    //chain->Add("/gpfs/fs8001/toyamash/L2mt/20230908/user.toyamash.data23_13p6TeV.00451866.physics_Main.merge.AOD.r14858_p5785.Run3-22.0.107-00-01.5_NTUP_ANALYSIS/*.root");
    //chain->Add("/gpfs/fs8001/toyamash/L2mt/20230908/user.toyamash.data23_13p6TeV.00451896.physics_Main.merge.AOD.r14858_p5785.Run3-22.0.107-00-01.5_NTUP_ANALYSIS/*.root");
    //chain->Add("/gpfs/fs8001/toyamash/L2mt/20230908/user.toyamash.data23_13p6TeV.00452028.physics_Main.merge.AOD.r14858_p5785.Run3-22.0.107-00-01.5_NTUP_ANALYSIS/*.root");
    //chain->Add("/gpfs/fs8001/toyamash/L2mt/20230908/user.toyamash.data23_13p6TeV.00452163.physics_Main.merge.AOD.r14858_p5785.Run3-22.0.107-00-01.5_NTUP_ANALYSIS/*.root");
    //chain->Add("/gpfs/fs8001/toyamash/L2mt/20230908/user.toyamash.data23_13p6TeV.00452202.physics_Main.merge.AOD.r14858_p5785.Run3-22.0.107-00-01.5_NTUP_ANALYSIS/*.root");
    //chain->Add("/gpfs/fs8001/toyamash/L2mt/20230908/user.toyamash.data23_13p6TeV.00452624.physics_Main.merge.AOD.r14858_p5785.Run3-22.0.107-00-01.5_NTUP_ANALYSIS/*.root");

    chain->Add("/gpfs/fs8001/toyamash/L2mt0915/user.toyamash.data23_13p6TeV.00451735.physics_Main.merge.AOD.r14858_p5785.Run3-22.0.107-00-01.10_NTUP_ANALYSIS/*.root");
    chain->Add("/gpfs/fs8001/toyamash/L2mt0915/user.toyamash.data23_13p6TeV.00451794.physics_Main.merge.AOD.r14858_p5785.Run3-22.0.107-00-01.10_NTUP_ANALYSIS/*.root");
    chain->Add("/gpfs/fs8001/toyamash/L2mt0915/user.toyamash.data23_13p6TeV.00451804.physics_Main.merge.AOD.r14858_p5785.Run3-22.0.107-00-01.10_NTUP_ANALYSIS/*.root");
    chain->Add("/gpfs/fs8001/toyamash/L2mt0915/user.toyamash.data23_13p6TeV.00452163.physics_Main.merge.AOD.r14858_p5785.Run3-22.0.107-00-01.10_NTUP_ANALYSIS/*.root");
    chain->Add("/gpfs/fs8001/toyamash/L2mt0915/user.toyamash.data23_13p6TeV.00453530.physics_Main.merge.AOD.f1357_m2179.Run3-22.0.107-00-01.10_NTUP_ANALYSIS/*.root");
    chain->Add("/gpfs/fs8001/toyamash/L2mt0915/user.toyamash.data23_13p6TeV.00453556.physics_Main.merge.AOD.f1357_m2179.Run3-22.0.107-00-01.10_NTUP_ANALYSIS/*.root");
    chain->Add("/gpfs/fs8001/toyamash/L2mt0915/user.toyamash.data23_13p6TeV.00453644.physics_Main.merge.AOD.f1357_m2179.Run3-22.0.107-00-01.10_NTUP_ANALYSIS/*.root");
    chain->Add("/gpfs/fs8001/toyamash/L2mt0915/user.toyamash.data23_13p6TeV.00453657.physics_Main.merge.AOD.f1357_m2179.Run3-22.0.107-00-01.10_NTUP_ANALYSIS/*.root");
    chain->Add("/gpfs/fs8001/toyamash/L2mt0915/user.toyamash.data23_13p6TeV.00453713.physics_Main.merge.AOD.f1357_m2179.Run3-22.0.107-00-01.10_NTUP_ANALYSIS/*.root");
    chain->Add("/gpfs/fs8001/toyamash/L2mt0915/user.toyamash.data23_13p6TeV.00453733.physics_Main.merge.AOD.f1357_m2179.Run3-22.0.107-00-01.10_NTUP_ANALYSIS/*.root");
    chain->Add("/gpfs/fs8001/toyamash/L2mt0915/user.toyamash.data23_13p6TeV.00453754.physics_Main.merge.AOD.f1357_m2179.Run3-22.0.107-00-01.10_NTUP_ANALYSIS/*.root");

    //MC
    //chain->Add("/gpfs/fs8001/toyamash/L2mt/user.toyamash.valid1.801164.P8B_A14_CTEQ6L1_bb_Jpsi1S_mu6mu4.MC.e8514_e8528_s4111_s4114_r14781_tid33979104_00.MC.5_NTUP_ANALYSIS/*.root");
    //chain->Add("/gpfs/fs8001/toyamash/L2mt/user.toyamash.mc23_13p6TeV.801164.P8B_A14_CTEQ6L1_bb_Jpsi1S_mu6mu4.e8542_e8528_s4159_s4114_r14799_r14811.MC.8_NTUP_ANALYSIS/*.root");

    chain->SetBranchStatus("*", 0);
    chain->SetBranchStatus("RunNumber", 1);
    chain->SetBranchStatus("LumiBlock", 1);
    chain->SetBranchStatus("EventNumber", 1);
    chain->SetBranchStatus("pass_HLT_mu10_l2mt_L1MU10BOM", 1);
    chain->SetBranchStatus("pass_HLT_2mu10_l2mt_L1MU10BOM", 1);
    chain->SetBranchStatus("muon_e", 1);
    chain->SetBranchStatus("muon_pt", 1);
    chain->SetBranchStatus("muon_eta", 1);
    chain->SetBranchStatus("muon_phi", 1);
    chain->SetBranchStatus("muon_charge", 1);
    chain->SetBranchStatus("muon_quality", 1);
    chain->SetBranchStatus("muon_muonType", 1);
    chain->SetBranchStatus("muon_author", 1);
    chain->SetBranchStatus("muon_seg_chamberIndex", 1);
    chain->SetBranchStatus("muon_seg_x", 1);
    chain->SetBranchStatus("muon_seg_y", 1);
    chain->SetBranchStatus("muon_seg_z", 1);
    chain->SetBranchStatus("muon_seg_px", 1);
    chain->SetBranchStatus("muon_seg_py", 1);
    chain->SetBranchStatus("muon_seg_pz", 1);
    chain->SetBranchStatus("trig_L1_mu_eta", 1);
    chain->SetBranchStatus("trig_L1_mu_phi", 1);
    chain->SetBranchStatus("trig_L1_mu_thrNumber", 1);
    chain->SetBranchStatus("trig_L1_mu_RoINumber", 1);
    chain->SetBranchStatus("trig_L1_mu_sectorAddress", 1);
    chain->SetBranchStatus("trig_L1_mu_source", 1);
    chain->SetBranchStatus("trig_L1_mu_hemisphere", 1);
    chain->SetBranchStatus("trig_L1_mu_firstCandidate", 1);
    chain->SetBranchStatus("trig_L1_mu_moreCandInRPCPad", 1);
    chain->SetBranchStatus("trig_L1_mu_moreCandInSector", 1);
    chain->SetBranchStatus("l1_eta", 1);
    chain->SetBranchStatus("l1_phi", 1);
    chain->SetBranchStatus("l1_BOM", 1);
    chain->SetBranchStatus("l1_roiNum", 1);
    chain->SetBranchStatus("l1_thrNum", 1);
    chain->SetBranchStatus("l2mt_e", 1);
    chain->SetBranchStatus("l2mt_pt", 1);
    chain->SetBranchStatus("l2mt_eta", 1);
    chain->SetBranchStatus("l2mt_phi", 1);
    chain->SetBranchStatus("l2mt_etaMS", 1);
    chain->SetBranchStatus("l2mt_phiMS", 1);
    chain->SetBranchStatus("l2mt_pass", 1);
    chain->SetBranchStatus("l2mt_superPointR", 1);
    chain->SetBranchStatus("l2mt_superPointZ", 1);
    chain->SetBranchStatus("l2mt_superPointSlope", 1);
    chain->SetBranchStatus("l2mt_superPointIntercept", 1);
    chain->SetBranchStatus("l2mt_superPointChi2", 1);
    chain->SetBranchStatus("l2mt_stgcClusterLayer", 1);
    chain->SetBranchStatus("l2mt_stgcClusterIsOutlier", 1);
    chain->SetBranchStatus("l2mt_stgcClusterEta", 1);
    chain->SetBranchStatus("l2mt_stgcClusterPhi", 1);
    chain->SetBranchStatus("l2mt_stgcClusterR", 1);
    chain->SetBranchStatus("l2mt_stgcClusterZ", 1);
    chain->SetBranchStatus("l2mt_stgcClusterResidualR", 1);
    chain->SetBranchStatus("l2mt_stgcClusterResidualPhi", 1);
    chain->SetBranchStatus("l2mt_stgcClusterStationEta", 1);
    chain->SetBranchStatus("l2mt_stgcClusterStationPhi", 1);
    chain->SetBranchStatus("l2mt_stgcClusterStationName", 1);
    chain->SetBranchStatus("l2mt_mmClusterLayer", 1);
    chain->SetBranchStatus("l2mt_mmClusterIsOutlier", 1);
    chain->SetBranchStatus("l2mt_mmClusterEta", 1);
    chain->SetBranchStatus("l2mt_mmClusterPhi", 1);
    chain->SetBranchStatus("l2mt_mmClusterR", 1);
    chain->SetBranchStatus("l2mt_mmClusterZ", 1);
    chain->SetBranchStatus("l2mt_mmClusterResidualR", 1);
    chain->SetBranchStatus("l2mt_mmClusterResidualPhi", 1);
    chain->SetBranchStatus("l2mt_mmClusterStationEta", 1);
    chain->SetBranchStatus("l2mt_mmClusterStationPhi", 1);
    chain->SetBranchStatus("l2mt_mmClusterStationName", 1);
    chain->SetBranchStatus("l2cb_e", 1);
    chain->SetBranchStatus("l2cb_pt", 1);
    chain->SetBranchStatus("l2cb_eta", 1);
    chain->SetBranchStatus("l2cb_phi", 1);
    chain->SetBranchStatus("l2cb_pass", 1);
    chain->SetBranchStatus("trigger_info_chain", 1);
    chain->SetBranchStatus("trigger_info_typeVec", 1);
    chain->SetBranchStatus("trigger_info_ptVec", 1);
    chain->SetBranchStatus("trigger_info_etaVec", 1);
    chain->SetBranchStatus("trigger_info_phiVec", 1);

    // Declaration of leaf types
    UInt_t          RunNumber = 0;
    UInt_t          LumiBlock = 0;
    ULong64_t       EventNumber = 0;
    bool pass_HLT_mu10_l2mt_L1MU10BOM = false;
    bool pass_HLT_2mu10_l2mt_L1MU10BOM = false;
    vector<float>   *muon_e = 0;
    vector<float>   *muon_pt = 0;
    vector<float>   *muon_eta = 0;
    vector<float>   *muon_phi = 0;
    vector<float>   *muon_charge = 0;
    vector<int>     *muon_quality = 0;
    vector<int>     *muon_muonType = 0;
    vector<int>     *muon_author = 0;
    vector<vector<int> > *muon_seg_chamberIndex = 0;
    vector<vector<float> > *muon_seg_x = 0;
    vector<vector<float> > *muon_seg_y = 0;
    vector<vector<float> > *muon_seg_z = 0;
    vector<vector<float> > *muon_seg_px = 0;
    vector<vector<float> > *muon_seg_py = 0;
    vector<vector<float> > *muon_seg_pz = 0;
    vector<float> *trig_L1_mu_eta = 0;
    vector<float> *trig_L1_mu_phi = 0;
    vector<short> *trig_L1_mu_thrNumber = 0;
    vector<short> *trig_L1_mu_RoINumber = 0;
    vector<short> *trig_L1_mu_sectorAddress = 0;
    vector<short> *trig_L1_mu_source = 0;
    vector<short> *trig_L1_mu_hemisphere = 0;
    vector<short> *trig_L1_mu_firstCandidate = 0;
    vector<short> *trig_L1_mu_moreCandInRPCPad = 0;
    vector<short> *trig_L1_mu_moreCandInSector = 0;
    vector<short> *trig_L1_mu_charge = 0;
    vector<float>   *l1_eta = 0;
    vector<float>   *l1_phi = 0;
    vector<int>   *l1_roiNum = 0;
    vector<int>   *l1_thrNum = 0;
    vector<int>   *l1_BOM = 0;
    vector<float>   *l2mt_e = 0;
    vector<float>   *l2mt_pt = 0;
    vector<float>   *l2mt_eta = 0;
    vector<float>   *l2mt_phi = 0;
    vector<float>   *l2mt_etaMS = 0;
    vector<float>   *l2mt_phiMS = 0;
    vector<bool>    *l2mt_pass = 0;
    vector<vector<float> > *l2mt_superPointR = 0;
    vector<vector<float> > *l2mt_superPointZ = 0;
    vector<vector<float> > *l2mt_superPointSlope = 0;
    vector<vector<float> > *l2mt_superPointIntercept = 0;
    vector<vector<float> > *l2mt_superPointChi2 = 0;
    vector<vector<unsigned int> > *l2mt_stgcClusterLayer = 0;
    vector<vector<int> > *l2mt_stgcClusterIsOutlier = 0;
    vector<vector<int> > *l2mt_stgcClusterType = 0;
    vector<vector<float> > *l2mt_stgcClusterEta = 0;
    vector<vector<float> > *l2mt_stgcClusterPhi = 0;
    vector<vector<float> > *l2mt_stgcClusterR = 0;
    vector<vector<float> > *l2mt_stgcClusterZ = 0;
    vector<vector<float> > *l2mt_stgcClusterResidualR = 0;
    vector<vector<float> > *l2mt_stgcClusterResidualPhi = 0;
    vector<vector<int> > *l2mt_stgcClusterStationEta = 0;
    vector<vector<int> > *l2mt_stgcClusterStationPhi = 0;
    vector<vector<int> > *l2mt_stgcClusterStationName = 0;
    vector<vector<unsigned int> > *l2mt_mmClusterLayer = 0;
    vector<vector<int> > *l2mt_mmClusterIsOutlier = 0;
    vector<vector<float> > *l2mt_mmClusterEta = 0;
    vector<vector<float> > *l2mt_mmClusterPhi = 0;
    vector<vector<float> > *l2mt_mmClusterR = 0;
    vector<vector<float> > *l2mt_mmClusterZ = 0;
    vector<vector<float> > *l2mt_mmClusterResidualR = 0;
    vector<vector<float> > *l2mt_mmClusterResidualPhi = 0;
    vector<vector<int> > *l2mt_mmClusterStationEta = 0;
    vector<vector<int> > *l2mt_mmClusterStationPhi = 0;
    vector<vector<int> > *l2mt_mmClusterStationName = 0;
    vector<float>   *l2cb_e = 0;
    vector<float>   *l2cb_pt = 0;
    vector<float>   *l2cb_eta = 0;
    vector<float>   *l2cb_phi = 0;
    vector<bool>    *l2cb_pass = 0;
    vector<string>         *trigger_info_chain = 0;
    vector<vector<int> >   *trigger_info_typeVec = 0;
    vector<vector<float> > *trigger_info_ptVec = 0;
    vector<vector<float> > *trigger_info_etaVec = 0;
    vector<vector<float> > *trigger_info_phiVec = 0;

    chain->SetBranchAddress("RunNumber", &RunNumber);
    chain->SetBranchAddress("LumiBlock", &LumiBlock);
    chain->SetBranchAddress("EventNumber", &EventNumber);
    chain->SetBranchAddress("pass_HLT_mu10_l2mt_L1MU10BOM", &pass_HLT_mu10_l2mt_L1MU10BOM);
    chain->SetBranchAddress("pass_HLT_2mu10_l2mt_L1MU10BOM", &pass_HLT_2mu10_l2mt_L1MU10BOM);
    chain->SetBranchAddress("muon_e", &muon_e);
    chain->SetBranchAddress("muon_pt", &muon_pt);
    chain->SetBranchAddress("muon_eta", &muon_eta);
    chain->SetBranchAddress("muon_phi", &muon_phi);
    chain->SetBranchAddress("muon_charge", &muon_charge);
    chain->SetBranchAddress("muon_quality", &muon_quality);
    chain->SetBranchAddress("muon_muonType", &muon_muonType);
    chain->SetBranchAddress("muon_author", &muon_author);
    chain->SetBranchAddress("muon_seg_chamberIndex", &muon_seg_chamberIndex);
    chain->SetBranchAddress("muon_seg_x", &muon_seg_x);
    chain->SetBranchAddress("muon_seg_y", &muon_seg_y);
    chain->SetBranchAddress("muon_seg_z", &muon_seg_z);
    chain->SetBranchAddress("muon_seg_px", &muon_seg_px);
    chain->SetBranchAddress("muon_seg_py", &muon_seg_py);
    chain->SetBranchAddress("muon_seg_pz", &muon_seg_pz);
    chain->SetBranchAddress("trig_L1_mu_eta", &trig_L1_mu_eta);
    chain->SetBranchAddress("trig_L1_mu_phi", &trig_L1_mu_phi);
    chain->SetBranchAddress("trig_L1_mu_thrNumber", &trig_L1_mu_thrNumber);
    chain->SetBranchAddress("trig_L1_mu_RoINumber", &trig_L1_mu_RoINumber);
    chain->SetBranchAddress("trig_L1_mu_sectorAddress", &trig_L1_mu_sectorAddress);
    chain->SetBranchAddress("trig_L1_mu_source", &trig_L1_mu_source);
    chain->SetBranchAddress("trig_L1_mu_hemisphere", &trig_L1_mu_hemisphere);
    chain->SetBranchAddress("trig_L1_mu_firstCandidate", &trig_L1_mu_firstCandidate);
    chain->SetBranchAddress("trig_L1_mu_moreCandInRPCPad", &trig_L1_mu_moreCandInRPCPad);
    chain->SetBranchAddress("trig_L1_mu_moreCandInSector", &trig_L1_mu_moreCandInSector);
    chain->SetBranchAddress("l1_eta", &l1_eta);
    chain->SetBranchAddress("l1_phi", &l1_phi);
    chain->SetBranchAddress("l1_roiNum", &l1_roiNum);
    chain->SetBranchAddress("l1_thrNum", &l1_thrNum);
    chain->SetBranchAddress("l1_BOM", &l1_BOM);
    chain->SetBranchAddress("l2mt_e", &l2mt_e);
    chain->SetBranchAddress("l2mt_pt", &l2mt_pt);
    chain->SetBranchAddress("l2mt_eta", &l2mt_eta);
    chain->SetBranchAddress("l2mt_phi", &l2mt_phi);
    chain->SetBranchAddress("l2mt_etaMS", &l2mt_etaMS);
    chain->SetBranchAddress("l2mt_phiMS", &l2mt_phiMS);
    chain->SetBranchAddress("l2mt_pass", &l2mt_pass);
    chain->SetBranchAddress("l2mt_superPointR", &l2mt_superPointR);
    chain->SetBranchAddress("l2mt_superPointZ", &l2mt_superPointZ);
    chain->SetBranchAddress("l2mt_superPointSlope", &l2mt_superPointSlope);
    chain->SetBranchAddress("l2mt_superPointIntercept", &l2mt_superPointIntercept);
    chain->SetBranchAddress("l2mt_superPointChi2", &l2mt_superPointChi2);
    chain->SetBranchAddress("l2mt_stgcClusterLayer", &l2mt_stgcClusterLayer);
    chain->SetBranchAddress("l2mt_stgcClusterIsOutlier", &l2mt_stgcClusterIsOutlier);
    chain->SetBranchAddress("l2mt_stgcClusterType", &l2mt_stgcClusterType);
    chain->SetBranchAddress("l2mt_stgcClusterEta", &l2mt_stgcClusterEta);
    chain->SetBranchAddress("l2mt_stgcClusterPhi", &l2mt_stgcClusterPhi);
    chain->SetBranchAddress("l2mt_stgcClusterR", &l2mt_stgcClusterR);
    chain->SetBranchAddress("l2mt_stgcClusterZ", &l2mt_stgcClusterZ);
    chain->SetBranchAddress("l2mt_stgcClusterResidualR", &l2mt_stgcClusterResidualR);
    chain->SetBranchAddress("l2mt_stgcClusterResidualPhi", &l2mt_stgcClusterResidualPhi);
    chain->SetBranchAddress("l2mt_stgcClusterStationEta", &l2mt_stgcClusterStationEta);
    chain->SetBranchAddress("l2mt_stgcClusterStationPhi", &l2mt_stgcClusterStationPhi);
    chain->SetBranchAddress("l2mt_stgcClusterStationName", &l2mt_stgcClusterStationName);
    chain->SetBranchAddress("l2mt_mmClusterLayer", &l2mt_mmClusterLayer);
    chain->SetBranchAddress("l2mt_mmClusterIsOutlier", &l2mt_mmClusterIsOutlier);
    chain->SetBranchAddress("l2mt_mmClusterEta", &l2mt_mmClusterEta);
    chain->SetBranchAddress("l2mt_mmClusterPhi", &l2mt_mmClusterPhi);
    chain->SetBranchAddress("l2mt_mmClusterR", &l2mt_mmClusterR);
    chain->SetBranchAddress("l2mt_mmClusterZ", &l2mt_mmClusterZ);
    chain->SetBranchAddress("l2mt_mmClusterResidualR", &l2mt_mmClusterResidualR);
    chain->SetBranchAddress("l2mt_mmClusterResidualPhi", &l2mt_mmClusterResidualPhi);
    chain->SetBranchAddress("l2mt_mmClusterStationEta", &l2mt_mmClusterStationEta);
    chain->SetBranchAddress("l2mt_mmClusterStationPhi", &l2mt_mmClusterStationPhi);
    chain->SetBranchAddress("l2mt_mmClusterStationName", &l2mt_mmClusterStationName);
    chain->SetBranchAddress("l2cb_e", &l2cb_e);
    chain->SetBranchAddress("l2cb_pt", &l2cb_pt);
    chain->SetBranchAddress("l2cb_eta", &l2cb_eta);
    chain->SetBranchAddress("l2cb_phi", &l2cb_phi);
    chain->SetBranchAddress("trigger_info_chain", &trigger_info_chain);
    chain->SetBranchAddress("trigger_info_typeVec", &trigger_info_typeVec);
    chain->SetBranchAddress("trigger_info_ptVec", &trigger_info_ptVec);
    chain->SetBranchAddress("trigger_info_etaVec", &trigger_info_etaVec);
    chain->SetBranchAddress("trigger_info_phiVec", &trigger_info_phiVec);

    TH1D *max_pt_hist = new TH1D("max_pt_hist", "max_pt_hist", 50, 0, 100);
    TH1D *min_pt_hist = new TH1D("min_pt_hist", "min_pt_hist", 50, 0, 100);

    TH1D *dimuon_mass_hist = new TH1D("dimuon_mass_hist", "dimuon_mass_hist", 100, 0, 10);
    TH1D *dimuon_deltaR_hist = new TH1D("dimuon_deltaR_hist", "dimuon_deltaR_hist", 20, 0, 1);
    TH1D *dimuon_deltaPhi_hist = new TH1D("dimuon_deltaPhi_hist", "dimuon_deltaPhi_hist", 10, -1, 1);
    TH1D *dimuon_pt_hist = new TH1D("dimuon_pt_hist", "dimuon_pt_hist", 50, 0, 100);

    TH1D *dimuon_mass_barrel_hist = new TH1D("dimuon_mass_barrel_hist", "dimuon_mass_barrel_hist", 100, 0, 10);
    TH1D *dimuon_deltaR_barrel_hist = new TH1D("dimuon_deltaR_barrel_hist", "dimuon_deltaR_barrel_hist", 20, 0, 1);
    TH1D *dimuon_deltaPhi_barrel_hist = new TH1D("dimuon_deltaPhi_barrel_hist", "dimuon_deltaPhi_barrel_hist", 10, -1, 1);
    TH1D *dimuon_pt_barrel_hist = new TH1D("dimuon_pt_barrel_hist", "dimuon_pt_barrel_hist", 50, 0, 100);

    TH1D *dimuon_mass_mu10_hist = new TH1D("dimuon_mass_mu10_hist", "dimuon_mass_mu10_hist", 100, 0, 10);
    TH1D *dimuon_deltaR_mu10_hist = new TH1D("dimuon_deltaR_mu10_hist", "dimuon_deltaR_mu10_hist", 20, 0, 1);
    TH1D *dimuon_deltaPhi_mu10_hist = new TH1D("dimuon_deltaPhi_mu10_hist", "dimuon_deltaPhi_mu10_hist", 10, -1, 1);
    TH1D *dimuon_pt_mu10_hist = new TH1D("dimuon_pt_mu10_hist", "dimuon_pt_mu10_hist", 50, 0, 100);

    TH1D *dimuon_mass_2mu10_hist = new TH1D("dimuon_mass_2mu10_hist", "dimuon_mass_2mu10_hist", 100, 0, 10);
    TH1D *dimuon_deltaR_2mu10_hist = new TH1D("dimuon_deltaR_2mu10_hist", "dimuon_deltaR_2mu10_hist", 20, 0, 1);
    TH1D *dimuon_deltaPhi_2mu10_hist = new TH1D("dimuon_deltaPhi_2mu10_hist", "dimuon_deltaPhi_2mu10_hist", 10, -1, 1);
    TH1D *dimuon_pt_2mu10_hist = new TH1D("dimuon_pt_2mu10_hist", "dimuon_pt_2mu10_hist", 50, 0, 100);

    TH1D *dimuon_mass_offline2mu10_mu10L2mt_hist = new TH1D("dimuon_mass_offline2mu10_mu10L2mt_hist", "dimuon_mass_offline2mu10_mu10L2mt_hist", 100, 0, 10);
    TH1D *dimuon_deltaR_offline2mu10_mu10L2mt_hist = new TH1D("dimuon_deltaR_offline2mu10_mu10L2mt_hist", "dimuon_deltaR_offline2mu10_mu10L2mt_hist", 20, 0, 1);
    TH1D *dimuon_deltaPhi_offline2mu10_mu10L2mt_hist = new TH1D("dimuon_deltaPhi_offline2mu10_mu10L2mt_hist", "dimuon_deltaPhi_offline2mu10_mu10L2mt_hist", 10, -1, 1);
    TH1D *dimuon_pt_offline2mu10_mu10L2mt_hist = new TH1D("dimuon_pt_offline2mu10_mu10L2mt_hist", "dimuon_pt_offline2mu10_mu10L2mt_hist", 50, 0, 100);

    TH1D *dimuon_mass_offline2mu10_2mu10L2mt_hist = new TH1D("dimuon_mass_offline2mu10_2mu10L2mt_hist", "dimuon_mass_offline2mu10_2mu10L2mt_hist", 100, 0, 10);
    TH1D *dimuon_deltaR_offline2mu10_2mu10L2mt_hist = new TH1D("dimuon_deltaR_offline2mu10_2mu10L2mt_hist", "dimuon_deltaR_offline2mu10_2mu10L2mt_hist", 20, 0, 1);
    TH1D *dimuon_deltaPhi_offline2mu10_2mu10L2mt_hist = new TH1D("dimuon_deltaPhi_offline2mu10_2mu10L2mt_hist", "dimuon_deltaPhi_offline2mu10_2mu10L2mt_hist", 10, -1, 1);
    TH1D *dimuon_pt_offline2mu10_2mu10L2mt_hist = new TH1D("dimuon_pt_offline2mu10_2mu10L2mt_hist", "dimuon_pt_offline2mu10_2mu10L2mt_hist", 50, 0, 100);

    TH1D *pair_mass_hist = new TH1D("pair_mass_hist", "pair_mass_hist", 100, 0, 10);
    TH1D *cut_pair_mass_hist = new TH1D("cut_pair_mass_hist", "cut_pair_mass_hist", 100, 0, 10);
    TH1D *pair_deltaR_hist = new TH1D("pair_deltaR_hist", "pair_deltaR_hist", 10, 0, 0.5);
    TH1D *cut_pair_deltaR_hist = new TH1D("cut_pair_deltaR_hist", "cut_pair_deltaR_hist", 10, 0, 0.5);
    TH1D *pair_ext_deltaR_hist = new TH1D("pair_ext_deltaR_hist", "pair_ext_deltaR_hist", 10, 0, 0.5);
    TH1D *cut_pair_ext_deltaR_hist = new TH1D("cut_pair_ext_deltaR_hist", "cut_pair_ext_deltaR_hist", 10, 0, 0.5);
    TH1D *pair_deltaPhi_hist = new TH1D("pair_deltaPhi_hist", "pair_deltaPhi_hist", 10, -1, 1);
    TH1D *cut_pair_deltaPhi_hist = new TH1D("cut_pair_deltaPhi_hist", "cut_pair_deltaPhi_hist", 10, -1, 1);
    TH1D *pair_ext_deltaPhi_hist = new TH1D("pair_ext_deltaPhi_hist", "pair_ext_deltaPhi_hist", 10, -1, 1);
    TH1D *cut_pair_ext_deltaPhi_hist = new TH1D("cut_pair_ext_deltaPhi_hist", "cut_pair_ext_deltaPhi_hist", 10, -1, 1);
    TH1D *pair_pt_hist = new TH1D("pair_pt_hist", "pair_pt_hist", 50, 0, 100);
    TH1D *cut_pair_pt_hist = new TH1D("cut_pair_pt_hist", "cut_pair_pt_hist", 50, 0, 100);

    TH1D *pair_mass_Jpsi_hist = new TH1D("pair_mass_Jpsi_hist", "pair_mass_Jpsi_hist", 100, 0, 10);
    TH1D *cut_pair_mass_Jpsi_hist = new TH1D("cut_pair_mass_Jpsi_hist", "cut_pair_mass_Jpsi_hist", 100, 0, 10);
    TH1D *pair_deltaR_Jpsi_hist = new TH1D("pair_deltaR_Jpsi_hist", "pair_deltaR_Jpsi_hist", 10, 0, 0.5);
    TH1D *cut_pair_deltaR_Jpsi_hist = new TH1D("cut_pair_deltaR_Jpsi_hist", "cut_pair_deltaR_Jpsi_hist", 10, 0, 0.5);
    TH1D *pair_ext_deltaR_Jpsi_hist = new TH1D("pair_ext_deltaR_Jpsi_hist", "pair_ext_deltaR_Jpsi_hist", 10, 0, 0.5);
    TH1D *cut_pair_ext_deltaR_Jpsi_hist = new TH1D("cut_pair_ext_deltaR_Jpsi_hist", "cut_pair_ext_deltaR_Jpsi_hist", 10, 0, 0.5);
    TH1D *pair_deltaPhi_Jpsi_hist = new TH1D("pair_deltaPhi_Jpsi_hist", "pair_deltaPhi_Jpsi_hist", 10, -1, 1);
    TH1D *cut_pair_deltaPhi_Jpsi_hist = new TH1D("cut_pair_deltaPhi_Jpsi_hist", "cut_pair_deltaPhi_Jpsi_hist", 10, -1, 1);
    TH1D *pair_ext_deltaPhi_Jpsi_hist = new TH1D("pair_ext_deltaPhi_Jpsi_hist", "pair_ext_deltaPhi_Jpsi_hist", 10, -1, 1);
    TH1D *cut_pair_ext_deltaPhi_Jpsi_hist = new TH1D("cut_pair_ext_deltaPhi_Jpsi_hist", "cut_pair_ext_deltaPhi_Jpsi_hist", 10, -1, 1);
    TH1D *pair_pt_Jpsi_hist = new TH1D("pair_pt_Jpsi_hist", "pair_pt_Jpsi_hist", 50, 0, 100);
    TH1D *cut_pair_pt_Jpsi_hist = new TH1D("cut_pair_pt_Jpsi_hist", "cut_pair_pt_Jpsi_hist", 50, 0, 100);

    TH1D *numberOfOffline_hist = new TH1D("numberOfOffline_hist", "numberOfOffline_hist", 11, 0, 11);
    TH1D *numberOfOffline_mu10L2mt_hist = new TH1D("numberOfOffline_mu10L2mt_hist", "numberOfOffline_mu10L2mt_hist", 11, 0, 11);
    TH1D *numberOfOffline_mu10L2mt_2mu10L2mt_hist = new TH1D("numberOfOffline_mu10L2mt_2mu10L2mt_hist", "numberOfOffline_mu10L2mt_2mu10L2mt_hist", 11, 0, 11);
    TH1D *numberOfOffline_2mu10L2mt_hist = new TH1D("numberOfOffline_2mu10L2mt_hist", "numberOfOffline_2mu10L2mt_hist", 11, 0, 11);

    TH1D *numberOfOfflineWith10GeV_hist = new TH1D("numberOfOfflineWith10GeV_hist", "numberOfOfflineWith10GeV_hist", 6, 0, 6);

    TH1D *pair_mass_2mu10L2mt_hist = new TH1D("pair_mass_2mu10L2mt_hist", "pair_mass_2mu10L2mt_hist", 100, 0, 10);
    TH1D *pair_deltaR_2mu10L2mt_hist = new TH1D("pair_deltaR_2mu10L2mt_hist", "pair_deltaR_2mu10L2mt_hist", 10, 0, 0.5);
    TH1D *pair_ext_deltaR_2mu10L2mt_hist = new TH1D("pair_ext_deltaR_2mu10L2mt_hist", "pair_ext_deltaR_2mu10L2mt_hist", 10, 0, 0.5);
    TH1D *pair_deltaPhi_2mu10L2mt_hist = new TH1D("pair_deltaPhi_2mu10L2mt_hist", "pair_deltaPhi_2mu10L2mt_hist", 10, -1, 1);
    TH1D *pair_ext_deltaPhi_2mu10L2mt_hist = new TH1D("pair_ext_deltaPhi_2mu10L2mt_hist", "pair_ext_deltaPhi_2mu10L2mt_hist", 10, -1, 1);
    TH1D *pair_pt_2mu10L2mt_hist = new TH1D("pair_pt_2mu10L2mt_hist", "pair_pt_2mu10L2mt_hist", 50, 0, 100);

    TH1D *offlinePtWithmu10L2mt_hist = new TH1D("offlinePtWithmu10L2mt_hist", "offlinePtWithmu10L2mt_hist", 50, 0, 100);
    TH1D *offlineEtaWithmu10L2mt_hist = new TH1D("offlineEtaWithmu10L2mt_hist", "offlineEtaWithmu10L2mt_hist", 120, -3, 3);
    TH1D *offlinePhiWithmu10L2mt_hist = new TH1D("offlinePhiWithmu10L2mt_hist", "offlinePhiWithmu10L2mt_hist", 120, -3, 3);

    TH1D *offlinePtWithmu10L2mt2mu10L2mt_hist = new TH1D("offlinePtWithmu10L2mt2mu10L2mt_hist", "offlinePtWithmu10L2mt2mu10L2mt_hist", 50, 0, 100);
    TH1D *offlineEtaWithmu10L2mt2mu10L2mt_hist = new TH1D("offlineEtaWithmu10L2mt2mu10L2mt_hsit", "offlineEtaWithmu10L2mt2mu10L2mt_hist", 120, -3, 3);
    TH1D *offlinePhiWithmu10L2mt2mu10L2mt_hist = new TH1D("offlinePhiWithmu10L2mt2mu10L2mt_hist", "offlinePhiWithmu10L2mt2mu10L2mt_hist", 120, -3, 3);

    TH1D *offlinePtWith2mu10L2mt_hist = new TH1D("offlinePtWith2mu10L2mt_hist", "offlinePtWith2mu10L2mt_hist", 50, 0, 100);
    TH1D *offlineEtaWith2mu10L2mt_hist = new TH1D("offlineEtaWith2mu10L2mt_hist", "offlineEtaWith2mu10L2mt_hist", 120, -3, 3);
    TH1D *offlinePhiWith2mu10L2mt_hist = new TH1D("offlinePhiWith2mu10L2mt_hist", "offlinePhiWith2mu10L2mt_hist", 120, -3, 3);


    //TFile hist_file("img0906/hist0906_2mu10.root", "RECREATE");
    TFile hist_file("img0915/hist0915_dimuon.root", "RECREATE");

    Long64_t nentries = chain->GetEntries();

    cout << nentries << endl;

    int n_l2mt2muons = 0;
    int n_l2mt1muons = 0;

    int muonsMatchWithSameRoi = 0;
    int MatchWithSameRoi = 0;

    int countSingleMuonMatchROI = 0;
    int count1L2mtMatchROI = 0;

    for(int jentry = 0; jentry < nentries; jentry++){
        //cout << jentry << endl;

        if(jentry % 5000000 == 0){
            cout << jentry << endl;
        }
        int numOfOffline = 0;
        vector<pair<int, int>> mu_pair_number;
        
        chain->GetEntry(jentry);

        numberOfOffline_hist->Fill(muon_pt->size());
        
        if(pass_HLT_mu10_l2mt_L1MU10BOM == 1){
            numberOfOffline_mu10L2mt_hist->Fill(muon_pt->size());
            for(int i_off = 0; i_off < muon_pt->size(); i_off++){
                offlinePtWithmu10L2mt_hist->Fill(muon_pt->at(i_off));
                offlineEtaWithmu10L2mt_hist->Fill(muon_eta->at(i_off));
                offlinePhiWithmu10L2mt_hist->Fill(muon_phi->at(i_off));
            }
            if(pass_HLT_2mu10_l2mt_L1MU10BOM == 1){
                numberOfOffline_mu10L2mt_2mu10L2mt_hist->Fill(muon_pt->size());
                for(int j_off = 0; j_off < muon_pt->size(); j_off++){
                    offlinePtWithmu10L2mt2mu10L2mt_hist->Fill(muon_pt->at(j_off));
                    offlineEtaWithmu10L2mt2mu10L2mt_hist->Fill(muon_eta->at(j_off));
                    offlinePhiWithmu10L2mt2mu10L2mt_hist->Fill(muon_phi->at(j_off));
                }
            }
        }
        
        if(pass_HLT_2mu10_l2mt_L1MU10BOM == 1){
            numberOfOffline_2mu10L2mt_hist->Fill(muon_pt->size());
            for(int k_off = 0; k_off < muon_pt->size(); k_off++){
                offlinePtWith2mu10L2mt_hist->Fill(muon_pt->at(k_off));
                offlineEtaWith2mu10L2mt_hist->Fill(muon_eta->at(k_off));
                offlinePhiWith2mu10L2mt_hist->Fill(muon_phi->at(k_off));
            }
        }

        int numberOfOfflineWith10GeV = 0;

        for(int k_offline = 0; k_offline < muon_pt->size(); k_offline++){
            if(muon_pt->at(k_offline) > 10){
                numberOfOfflineWith10GeV++;
            }
        }

        numberOfOfflineWith10GeV_hist->Fill(numberOfOfflineWith10GeV);

        int numberOfOfflineWithBarrel = 0;
        
        for(int l_offline = 0; l_offline < muon_pt->size(); l_offline++){
            if(muon_pt->at(l_offline) > 10){
                numberOfOfflineWithBarrel++;
            }
        }
        
        numberOfOfflineWith10GeV_hist->Fill(numberOfOfflineWithBarrel);

        // offline muon pair
        for(int i_offline = 0; i_offline < muon_pt->size(); i_offline++){

            // pt cut (10GeV) & barrel only
            bool flag_mu1_pt = muon_pt->at(i_offline) > 10;
            bool flag_mu1_eta = abs(muon_eta->at(i_offline)) < 1.05;
            
            if(flag_mu1_eta == false) continue;

            TLorentzVector mu1;
            mu1.SetPtEtaPhiE(muon_pt->at(i_offline), muon_eta->at(i_offline), muon_phi->at(i_offline), muon_e->at(i_offline));

            for(int j_offline = i_offline + 1; j_offline < muon_pt->size(); j_offline++){
                //pt cut(10GeV) & barrel only
                bool flag_mu2_pt = muon_pt->at(j_offline) > 10;
                bool flag_mu2_eta = abs(muon_eta->at(j_offline)) < 1.05;

                if(flag_mu2_eta == false) continue;
                
                TLorentzVector mu2;
                mu2.SetPtEtaPhiE(muon_pt->at(j_offline), muon_eta->at(j_offline), muon_phi->at(j_offline), muon_e->at(j_offline));
                
                TLorentzVector mu_pair = mu1 + mu2;
                float dimuon_mass = mu_pair.M();
                float dimuon_deltaR = mu2.DeltaR(mu1);
                float dimuon_deltaPhi = mu2.DeltaPhi(mu1);

                dimuon_mass_hist->Fill(dimuon_mass);
                dimuon_deltaR_hist->Fill(dimuon_deltaR);
                dimuon_deltaPhi_hist->Fill(dimuon_deltaPhi);
                dimuon_pt_hist->Fill(mu1.Pt());
                dimuon_pt_hist->Fill(mu2.Pt());

                if(flag_mu1_eta == true && flag_mu2_eta == true){

                    dimuon_mass_barrel_hist->Fill(dimuon_mass);
                    dimuon_deltaR_barrel_hist->Fill(dimuon_deltaR);
                    dimuon_deltaPhi_barrel_hist->Fill(dimuon_deltaPhi);
                    dimuon_pt_barrel_hist->Fill(mu1.Pt());
                    dimuon_pt_barrel_hist->Fill(mu2.Pt());

                    float max_pt = 0;
                    float min_pt = 0;
                    int min_pt_muon_num = 0;
                    int max_pt_muon_num = 0;

                    if(muon_pt->at(i_offline) < muon_pt->at(j_offline)){
                        max_pt = muon_pt->at(j_offline);
                        min_pt = muon_pt->at(i_offline);
                        max_pt_muon_num = j_offline;
                        min_pt_muon_num = i_offline;
                    }

                    else{
                        max_pt = muon_pt->at(i_offline);
                        min_pt = muon_pt->at(j_offline);
                        max_pt_muon_num = i_offline;
                        min_pt_muon_num = j_offline;
                    }

                    bool flag_max_pt = max_pt > 10;
                    bool flag_min_pt = min_pt > 10;

                    max_pt_hist->Fill(max_pt);
                    min_pt_hist->Fill(min_pt);

                    if(flag_max_pt == true){
                        dimuon_mass_mu10_hist->Fill(dimuon_mass);
                        dimuon_deltaR_mu10_hist->Fill(dimuon_deltaR);
                        dimuon_deltaPhi_mu10_hist->Fill(dimuon_deltaPhi);
                        dimuon_pt_mu10_hist->Fill(mu1.Pt());
                        dimuon_pt_mu10_hist->Fill(mu2.Pt());
                        if(flag_min_pt == true){
                            dimuon_mass_2mu10_hist->Fill(dimuon_mass);
                            dimuon_deltaR_2mu10_hist->Fill(dimuon_deltaR);
                            dimuon_deltaPhi_2mu10_hist->Fill(dimuon_deltaPhi);
                            dimuon_pt_2mu10_hist->Fill(mu1.Pt());
                            dimuon_pt_2mu10_hist->Fill(mu2.Pt());

                            mu_pair_number.push_back(make_pair(i_offline, j_offline));
                            numOfOffline = 2;
                        }
                    }
                    if(flag_max_pt == true && flag_min_pt == true && pass_HLT_mu10_l2mt_L1MU10BOM == 1){
                        dimuon_mass_offline2mu10_mu10L2mt_hist->Fill(dimuon_mass);
                        dimuon_deltaR_offline2mu10_mu10L2mt_hist->Fill(dimuon_deltaR);
                        dimuon_deltaPhi_offline2mu10_mu10L2mt_hist->Fill(dimuon_deltaPhi);
                        dimuon_pt_offline2mu10_mu10L2mt_hist->Fill(mu1.Pt());
                        dimuon_pt_offline2mu10_mu10L2mt_hist->Fill(mu2.Pt());
                        if(pass_HLT_2mu10_l2mt_L1MU10BOM == 1){
                            dimuon_mass_offline2mu10_2mu10L2mt_hist->Fill(dimuon_mass);
                            dimuon_deltaR_offline2mu10_2mu10L2mt_hist->Fill(dimuon_deltaR);
                            dimuon_deltaPhi_offline2mu10_2mu10L2mt_hist->Fill(dimuon_deltaPhi);
                            dimuon_pt_offline2mu10_2mu10L2mt_hist->Fill(mu1.Pt());
                            dimuon_pt_offline2mu10_2mu10L2mt_hist->Fill(mu2.Pt());
                        }
                    }
                }
            }
        }

        if(numOfOffline == 2 && pass_HLT_mu10_l2mt_L1MU10BOM == 1){
            
            for(int i_mupair = 0; i_mupair < mu_pair_number.size(); i_mupair++){
                int offline1 = mu_pair_number.at(i_mupair).first;
                int offline2 = mu_pair_number.at(i_mupair).second;

                float mu1_seg_theta = 999;
                float mu1_seg_phi = 999;
                float mu1_seg_eta = 999;

                float mu2_seg_theta = 999;
                float mu2_seg_phi = 999;
                float mu2_seg_eta = 999;

                for(int i_chamber = 0; i_chamber < muon_seg_chamberIndex->at(offline1).size(); i_chamber++){
                    if(muon_seg_chamberIndex->at(offline1).at(i_chamber) == 2 || muon_seg_chamberIndex->at(offline1).at(i_chamber) == 3){
                        //mu1_seg_theta = std::atan2(std::sqrt(muon_seg_x->at(offline1).at(i_chamber) * muon_seg_x->at(offline1).at(i_chamber) + muon_seg_y->at(offline1).at(i_chamber) * muon_seg_y->at(offline1).at(i_chamber)), muon_seg_z->at(offline1).at(i_chamber));
                        //mu1_seg_phi = std::atan2(muon_seg_y->at(offline1).at(i_chamber) , muon_seg_x->at(offline1).at(i_chamber));
                        //mu1_seg_eta = -1*log(tan(mu1_seg_theta / 2));
                        TVector3 seg_muon1(muon_seg_x->at(offline1).at(i_chamber), muon_seg_y->at(offline1).at(i_chamber), muon_seg_z->at(offline1).at(i_chamber));
                        mu1_seg_phi = seg_muon1.Phi();
                        mu1_seg_eta = seg_muon1.Eta();
                    }
                }
                
                for(int j_chamber = 0; j_chamber < muon_seg_chamberIndex->at(offline2).size(); j_chamber++){
                    if(muon_seg_chamberIndex->at(offline2).at(j_chamber) == 2 || muon_seg_chamberIndex->at(offline2).at(j_chamber) == 3){
                        //mu2_seg_theta = std::atan2(std::sqrt(muon_seg_x->at(offline2).at(j_chamber) * muon_seg_x->at(offline2).at(j_chamber) + muon_seg_y->at(offline2).at(j_chamber) * muon_seg_y->at(offline2).at(j_chamber)), muon_seg_z->at(offline2).at(j_chamber));
                        //mu2_seg_phi = std::atan2(muon_seg_y->at(offline2).at(j_chamber) , muon_seg_x->at(offline2).at(j_chamber));
                        //mu2_seg_eta = -1*log(tan(mu2_seg_theta / 2));
                        TVector3 seg_muon2(muon_seg_x->at(offline2).at(j_chamber), muon_seg_y->at(offline2).at(j_chamber), muon_seg_z->at(offline2).at(j_chamber));
                        mu2_seg_phi = seg_muon2.Phi();
                        mu2_seg_eta = seg_muon2.Eta();
                    }
                }

                if(mu1_seg_phi > 900 || mu2_seg_phi > 900) continue;
                
                TLorentzVector muon1;
                muon1.SetPtEtaPhiE(muon_pt->at(offline1), muon_eta->at(offline1), muon_phi->at(offline1), muon_e->at(offline1));
                TLorentzVector muon2;
                muon2.SetPtEtaPhiE(muon_pt->at(offline2), muon_eta->at(offline2), muon_phi->at(offline2), muon_e->at(offline2));

                TLorentzVector ext_mu1;
                ext_mu1.SetPtEtaPhiE(muon_pt->at(offline1), mu1_seg_eta, mu1_seg_phi, muon_e->at(offline1));
                TLorentzVector ext_mu2;
                ext_mu2.SetPtEtaPhiE(muon_pt->at(offline2), mu2_seg_eta, mu2_seg_phi, muon_e->at(offline2));

                TLorentzVector offline_pair = muon1 + muon2;
                float pair_mass = offline_pair.M();
                float pair_deltaR = muon2.DeltaR(muon1);
                float pair_deltaPhi = muon2.DeltaPhi(muon1);

                TLorentzVector ext_mu_pair = ext_mu1 + ext_mu2;
                float pair_ext_mass = ext_mu_pair.M();
                float pair_ext_deltaR = ext_mu2.DeltaR(ext_mu1);
                float pair_ext_deltaPhi = ext_mu2.DeltaPhi(ext_mu1);

                pair_mass_hist->Fill(pair_mass);
                pair_deltaR_hist->Fill(pair_deltaR);
                pair_deltaPhi_hist->Fill(pair_deltaPhi);
                pair_pt_hist->Fill(muon1.Pt());
                pair_pt_hist->Fill(muon2.Pt());

                pair_ext_deltaR_hist->Fill(pair_ext_deltaR);
                pair_ext_deltaPhi_hist->Fill(pair_ext_deltaPhi);

                if(pass_HLT_2mu10_l2mt_L1MU10BOM == 1){
                    cut_pair_mass_hist->Fill(pair_mass);
                    cut_pair_deltaR_hist->Fill(pair_deltaR);
                    cut_pair_deltaPhi_hist->Fill(pair_deltaPhi);
                    cut_pair_pt_hist->Fill(muon1.Pt());
                    cut_pair_pt_hist->Fill(muon2.Pt());

                    cut_pair_ext_deltaR_hist->Fill(pair_ext_deltaR);
                    cut_pair_ext_deltaPhi_hist->Fill(pair_ext_deltaPhi);
                }

                //j/psi mass cut
                bool flag_pair_mass = false;
                if(pair_mass > 2.7 && 3.5 > pair_mass){
                    flag_pair_mass = true;
                }
                
                if(flag_pair_mass == true){
                    pair_mass_Jpsi_hist->Fill(pair_mass);
                    pair_deltaR_Jpsi_hist->Fill(pair_deltaR);
                    pair_deltaPhi_Jpsi_hist->Fill(pair_deltaPhi);
                    pair_pt_Jpsi_hist->Fill(muon1.Pt());
                    pair_pt_Jpsi_hist->Fill(muon2.Pt());

                    pair_ext_deltaR_Jpsi_hist->Fill(pair_ext_deltaR);
                    pair_ext_deltaPhi_Jpsi_hist->Fill(pair_ext_deltaPhi);

                    if(pass_HLT_2mu10_l2mt_L1MU10BOM == 1){
                        cut_pair_mass_Jpsi_hist->Fill(pair_mass);
                        cut_pair_deltaR_Jpsi_hist->Fill(pair_deltaR);
                        cut_pair_deltaPhi_Jpsi_hist->Fill(pair_deltaPhi);
                        cut_pair_pt_Jpsi_hist->Fill(muon1.Pt());
                        cut_pair_pt_Jpsi_hist->Fill(muon2.Pt());

                        cut_pair_ext_deltaR_Jpsi_hist->Fill(pair_ext_deltaR);
                        cut_pair_ext_deltaPhi_Jpsi_hist->Fill(pair_ext_deltaPhi);
                    }
                }
            }
        }


        if(numOfOffline == 2 && pass_HLT_2mu10_l2mt_L1MU10BOM == 1){

            for(int i_mupair = 0; i_mupair < mu_pair_number.size(); i_mupair++){
                int offline1 = mu_pair_number.at(i_mupair).first;
                int offline2 = mu_pair_number.at(i_mupair).second;

                float mu1_seg_theta = 999;
                float mu1_seg_phi = 999;
                float mu1_seg_eta = 999;

                float mu2_seg_theta = 999;
                float mu2_seg_phi = 999;
                float mu2_seg_eta = 999;

                for(int i_chamber = 0; i_chamber < muon_seg_chamberIndex->at(offline1).size(); i_chamber++){
                    if(muon_seg_chamberIndex->at(offline1).at(i_chamber) == 2 || muon_seg_chamberIndex->at(offline1).at(i_chamber) == 3){
                        //mu1_seg_theta = std::atan2(std::sqrt(muon_seg_x->at(offline1).at(i_chamber) * muon_seg_x->at(offline1).at(i_chamber) + muon_seg_y->at(offline1).at(i_chamber) * muon_seg_y->at(offline1).at(i_chamber)), muon_seg_z->at(offline1).at(i_chamber));
                        //mu1_seg_phi = std::atan2(muon_seg_y->at(offline1).at(i_chamber) , muon_seg_x->at(offline1).at(i_chamber));
                        //mu1_seg_eta = -1*log(tan(mu1_seg_theta / 2));
                        TVector3 seg_muon1(muon_seg_x->at(offline1).at(i_chamber), muon_seg_y->at(offline1).at(i_chamber), muon_seg_z->at(offline1).at(i_chamber));
                        mu1_seg_phi = seg_muon1.Phi();
                        mu1_seg_eta = seg_muon1.Eta();
                    }
                }
                
                for(int j_chamber = 0; j_chamber < muon_seg_chamberIndex->at(offline2).size(); j_chamber++){
                    if(muon_seg_chamberIndex->at(offline2).at(j_chamber) == 2 || muon_seg_chamberIndex->at(offline2).at(j_chamber) == 3){
                        //mu2_seg_theta = std::atan2(std::sqrt(muon_seg_x->at(offline2).at(j_chamber) * muon_seg_x->at(offline2).at(j_chamber) + muon_seg_y->at(offline2).at(j_chamber) * muon_seg_y->at(offline2).at(j_chamber)), muon_seg_z->at(offline2).at(j_chamber));
                        //mu2_seg_phi = std::atan2(muon_seg_y->at(offline2).at(j_chamber) , muon_seg_x->at(offline2).at(j_chamber));
                        //mu2_seg_eta = -1*log(tan(mu2_seg_theta / 2));
                        TVector3 seg_muon2(muon_seg_x->at(offline2).at(j_chamber), muon_seg_y->at(offline2).at(j_chamber), muon_seg_z->at(offline2).at(j_chamber));
                        mu2_seg_phi = seg_muon2.Phi();
                        mu2_seg_eta = seg_muon2.Eta();
                    }
                }

                if(mu1_seg_phi > 900 || mu2_seg_phi > 900) continue;
                
                TLorentzVector muon1;
                muon1.SetPtEtaPhiE(muon_pt->at(offline1), muon_eta->at(offline1), muon_phi->at(offline1), muon_e->at(offline1));
                TLorentzVector muon2;
                muon2.SetPtEtaPhiE(muon_pt->at(offline2), muon_eta->at(offline2), muon_phi->at(offline2), muon_e->at(offline2));

                TLorentzVector ext_mu1;
                ext_mu1.SetPtEtaPhiE(muon_pt->at(offline1), mu1_seg_eta, mu1_seg_phi, muon_e->at(offline1));
                TLorentzVector ext_mu2;
                ext_mu2.SetPtEtaPhiE(muon_pt->at(offline2), mu2_seg_eta, mu2_seg_phi, muon_e->at(offline2));

                TLorentzVector offline_pair = muon1 + muon2;
                float pair_mass = offline_pair.M();
                float pair_deltaR = muon2.DeltaR(muon1);
                float pair_deltaPhi = muon2.DeltaPhi(muon1);

                TLorentzVector ext_mu_pair = ext_mu1 + ext_mu2;
                float pair_ext_mass = ext_mu_pair.M();
                float pair_ext_deltaR = ext_mu2.DeltaR(ext_mu1);
                float pair_ext_deltaPhi = ext_mu2.DeltaPhi(ext_mu1);

                pair_mass_2mu10L2mt_hist->Fill(pair_mass);
                pair_deltaR_2mu10L2mt_hist->Fill(pair_deltaR);
                pair_deltaPhi_2mu10L2mt_hist->Fill(pair_deltaPhi);
                pair_pt_2mu10L2mt_hist->Fill(muon1.Pt());
                pair_pt_2mu10L2mt_hist->Fill(muon2.Pt());

                pair_ext_deltaR_2mu10L2mt_hist->Fill(pair_ext_deltaR);
                pair_ext_deltaPhi_2mu10L2mt_hist->Fill(pair_ext_deltaPhi);
            }
        }
    }

    hist_file.cd();

    numberOfOffline_hist->Write();
    numberOfOffline_mu10L2mt_hist->Write();
    numberOfOffline_mu10L2mt_2mu10L2mt_hist->Write();
    numberOfOffline_2mu10L2mt_hist->Write();
    numberOfOfflineWith10GeV_hist->Write();

    max_pt_hist->Write();
    min_pt_hist->Write();

    dimuon_mass_hist->Write();
    dimuon_deltaR_hist->Write();
    dimuon_deltaPhi_hist->Write();
    dimuon_pt_hist->Write();

    dimuon_mass_barrel_hist->Write();
    dimuon_deltaR_barrel_hist->Write();
    dimuon_deltaPhi_barrel_hist->Write();
    dimuon_pt_barrel_hist->Write();
    dimuon_pt_barrel_hist->Write();


    dimuon_mass_mu10_hist->Write();
    dimuon_deltaR_mu10_hist->Write();
    dimuon_deltaPhi_mu10_hist->Write();
    dimuon_pt_mu10_hist->Write();
    
    dimuon_mass_2mu10_hist->Write();
    dimuon_deltaR_2mu10_hist->Write();
    dimuon_deltaPhi_2mu10_hist->Write();
    dimuon_pt_2mu10_hist->Write();

    dimuon_mass_offline2mu10_mu10L2mt_hist->Write();
    dimuon_deltaR_offline2mu10_mu10L2mt_hist->Write();
    dimuon_deltaPhi_offline2mu10_mu10L2mt_hist->Write();
    dimuon_pt_offline2mu10_mu10L2mt_hist->Write();
    dimuon_mass_offline2mu10_2mu10L2mt_hist->Write();
    dimuon_deltaR_offline2mu10_2mu10L2mt_hist->Write();
    dimuon_deltaPhi_offline2mu10_2mu10L2mt_hist->Write();
    dimuon_pt_offline2mu10_2mu10L2mt_hist->Write();

    pair_mass_hist->Write();
    pair_deltaR_hist->Write();
    pair_deltaPhi_hist->Write();
    pair_ext_deltaR_hist->Write();
    pair_ext_deltaPhi_hist->Write();
    pair_pt_hist->Write();
    cut_pair_mass_hist->Write();
    cut_pair_deltaR_hist->Write();
    cut_pair_deltaPhi_hist->Write();
    cut_pair_ext_deltaR_hist->Write();
    cut_pair_ext_deltaPhi_hist->Write();
    cut_pair_pt_hist->Write();
    pair_mass_Jpsi_hist->Write();
    pair_deltaR_Jpsi_hist->Write();
    pair_deltaPhi_Jpsi_hist->Write();
    pair_ext_deltaR_Jpsi_hist->Write();
    pair_ext_deltaPhi_Jpsi_hist->Write();
    pair_pt_Jpsi_hist->Write();
    cut_pair_mass_Jpsi_hist->Write();
    cut_pair_deltaR_Jpsi_hist->Write();
    cut_pair_deltaPhi_Jpsi_hist->Write();
    cut_pair_ext_deltaR_Jpsi_hist->Write();
    cut_pair_ext_deltaPhi_Jpsi_hist->Write();
    cut_pair_pt_Jpsi_hist->Write();

    pair_mass_2mu10L2mt_hist->Write();
    pair_deltaR_2mu10L2mt_hist->Write();
    pair_ext_deltaR_2mu10L2mt_hist->Write();
    pair_deltaPhi_2mu10L2mt_hist->Write();
    pair_ext_deltaPhi_2mu10L2mt_hist->Write();
    pair_pt_2mu10L2mt_hist->Write();
    
    hist_file.Close();
}
