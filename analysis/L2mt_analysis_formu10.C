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

void L2mt_analysis_formu10(){
    TChain* chain = new TChain("analysis");
    //login.icepp
    chain->Add("/gpfs/fs8001/toyamash/L2mt/user.toyamash.data23_13p6TeV.00453733.physics_Main.merge.AOD.f1357_m2179.Run3-22.0.107-00-01.5_NTUP_ANALYSIS/*.root");
    chain->Add("/gpfs/fs8001/toyamash/L2mt/user.toyamash.data23_13p6TeV.00453353.physics_Main.merge.AOD.f1357_m2179.Run3-22.0.107-00-01.5_NTUP_ANALYSIS/*.root");
    chain->Add("/gpfs/fs8001/toyamash/L2mt/user.toyamash.data23_13p6TeV.00453530.physics_Main.merge.AOD.f1357_m2179.Run3-22.0.107-00-01.5_NTUP_ANALYSIS/*.root");
    chain->Add("/gpfs/fs8001/toyamash/L2mt/user.toyamash.data23_13p6TeV.00453556.physics_Main.merge.AOD.f1357_m2179.Run3-22.0.107-00-01.5_NTUP_ANALYSIS/*.root");
    chain->Add("/gpfs/fs8001/toyamash/L2mt/user.toyamash.data23_13p6TeV.00453617.physics_Main.merge.AOD.f1357_m2179.Run3-22.0.107-00-01.5_NTUP_ANALYSIS/*.root");
    chain->Add("/gpfs/fs8001/toyamash/L2mt/user.toyamash.data23_13p6TeV.00453644.physics_Main.merge.AOD.f1357_m2179.Run3-22.0.107-00-01.5_NTUP_ANALYSIS/*.root");
    chain->Add("/gpfs/fs8001/toyamash/L2mt/user.toyamash.data23_13p6TeV.00453657.physics_Main.merge.AOD.f1357_m2179.Run3-22.0.107-00-01.5_NTUP_ANALYSIS/*.root");
    chain->Add("/gpfs/fs8001/toyamash/L2mt/user.toyamash.data23_13p6TeV.00453713.physics_Main.merge.AOD.f1357_m2179.Run3-22.0.107-00-01.5_NTUP_ANALYSIS/*.root");
    chain->Add("/gpfs/fs8001/toyamash/L2mt/user.toyamash.data23_13p6TeV.00453754.physics_Main.merge.AOD.f1357_m2179.Run3-22.0.107-00-01.5_NTUP_ANALYSIS/*.root");
    chain->Add("/gpfs/fs8001/toyamash/L2mt/user.toyamash.data23_13p6TeV.00453816.physics_Main.merge.AOD.f1360_m2179.Run3-22.0.107-00-01.5_NTUP_ANALYSIS/*.root");

    //lxplus
    //HLT_mu10_l2mt_L1MU10BOM
    //chain->Add("/eos/atlas/unpledged/group-tokyo/users/toyamash/mu10L2mt/user.toyamash.data23_13p6TeV.00453644.physics_Main.merge.AOD.f1357_m2179.Run3-22.0.107-00-01.3_NTUP_ANALYSIS/*.root");
    //chain->Add("/eos/atlas/unpledged/group-tokyo/users/toyamash/mu10L2mt/user.toyamash.data23_13p6TeV.00453353.physics_Main.merge.AOD.f1357_m2179.Run3-22.0.107-00-01.3_NTUP_ANALYSIS/*.root");
    //chain->Add("/eos/atlas/unpledged/group-tokyo/users/toyamash/mu10L2mt/user.toyamash.data23_13p6TeV.00453530.physics_Main.merge.AOD.f1357_m2179.Run3-22.0.107-00-01.3_NTUP_ANALYSIS/*.root");
    //chain->Add("/eos/atlas/unpledged/group-tokyo/users/toyamash/mu10L2mt/user.toyamash.data23_13p6TeV.00453556.physics_Main.merge.AOD.f1357_m2179.Run3-22.0.107-00-01.3_NTUP_ANALYSIS/*.root");
    //chain->Add("/eos/atlas/unpledged/group-tokyo/users/toyamash/mu10L2mt/user.toyamash.data23_13p6TeV.00453657.physics_Main.merge.AOD.f1357_m2179.Run3-22.0.107-00-01.3_NTUP_ANALYSIS/*.root");
    //chain->Add("/eos/atlas/unpledged/group-tokyo/users/toyamash/mu10L2mt/user.toyamash.data23_13p6TeV.00453713.physics_Main.merge.AOD.f1357_m2179.Run3-22.0.107-00-01.3_NTUP_ANALYSIS/*.root");
    //chain->Add("/eos/atlas/unpledged/group-tokyo/users/toyamash/mu10L2mt/user.toyamash.data23_13p6TeV.00453733.physics_Main.merge.AOD.f1357_m2179.Run3-22.0.107-00-01.3_NTUP_ANALYSIS/*.root");
    //chain->Add("/eos/atlas/unpledged/group-tokyo/users/toyamash/mu10L2mt/user.toyamash.data23_13p6TeV.00453816.physics_Main.merge.AOD.f1357_m2179.Run3-22.0.107-00-01.3_NTUP_ANALYSIS/*.root");
    //chain->Add("/eos/atlas/unpledged/group-tokyo/users/toyamash/mu10L2mt/user.toyamash.data23_13p6TeV.00453754.physics_Main.merge.AOD.f1357_m2179.Run3-22.0.107-00-01.3_NTUP_ANALYSIS/*.root");
    
    //MC Jpsi
    //chain->Add("/gpfs/fs8001/toyamash/L2mt/user.toyamash.valid1.801164.P8B_A14_CTEQ6L1_bb_Jpsi1S_mu6mu4.MC.e8514_e8528_s4111_s4114_r14781_tid33979104_00.MC.5_NTUP_ANALYSIS/*.root");

    //MC Zmumu
    //chain->Add("/gpfs/fs8001/toyamash/L2mt/user.toyamash.valid1.601190.PhPy8EG_AZNLO_Zmumu.MC.e8514_e8528_s4111_s4114_r14781_tid33979091_00.MC.6_NTUP_ANALYSIS/*.root");
    
    chain->SetBranchStatus("*", 0);
    chain->SetBranchStatus("RunNumber", 1);
    chain->SetBranchStatus("LumiBlock", 1);
    chain->SetBranchStatus("EventNumber", 1);
    chain->SetBranchStatus("pass_HLT_mu10_l2mt_L1MU10BOM", 1);
    chain->SetBranchStatus("muon_e", 1);
    chain->SetBranchStatus("muon_pt", 1);
    chain->SetBranchStatus("muon_eta", 1);
    chain->SetBranchStatus("muon_phi", 1);
    chain->SetBranchStatus("muon_charge", 1);
    chain->SetBranchStatus("muon_quality", 1);
    //chain->SetBranchStatus("muon_isBadMuon_other", 1);
    //chain->SetBranchStatus("muon_truthType", 1);
    //chain->SetBranchStatus("muon_truthTypeMCTC", 1);
    //chain->SetBranchStatus("muon_truthOriginMCTC", 1);
    //chain->SetBranchStatus("muon_IFFtruthType", 1);
    chain->SetBranchStatus("muon_muonType", 1);
    chain->SetBranchStatus("muon_author", 1);
    //chain->SetBranchStatus("truthmuon_e", 1);
    //chain->SetBranchStatus("truthmuon_pt", 1);
    //chain->SetBranchStatus("truthmuon_eta", 1);
    //chain->SetBranchStatus("truthmuon_phi", 1);
    //chain->SetBranchStatus("truthmuon_pdgId", 1);
    //chain->SetBranchStatus("muon_mePt", 1);
    //chain->SetBranchStatus("muon_idPt", 1);
    //chain->SetBranchStatus("muon_cbPt", 1);
    //chain->SetBranchStatus("muon_meP", 1);
    //chain->SetBranchStatus("muon_idP", 1);
    //chain->SetBranchStatus("muon_etaMS", 1);
    //chain->SetBranchStatus("muon_phiMS", 1);
    //chain->SetBranchStatus("muon_innerSmallHits", 1);
    //chain->SetBranchStatus("muon_innerLargeHits", 1);
    //chain->SetBranchStatus("muon_middleSmallHits", 1);
    //chain->SetBranchStatus("muon_middleLargeHits", 1);
    //chain->SetBranchStatus("muon_outerSmallHits", 1);
    //chain->SetBranchStatus("muon_outerLargeHits", 1);
    //chain->SetBranchStatus("muon_extendedSmallHits", 1);
    //chain->SetBranchStatus("muon_extendedLargeHits", 1);
    //chain->SetBranchStatus("muon_phiLayer1STGCHits", 1);
    //chain->SetBranchStatus("muon_phiLayer2STGCHits", 1);
    //chain->SetBranchStatus("muon_etaLayer1STGCHits", 1);
    //chain->SetBranchStatus("muon_etaLayer2STGCHits", 1);
    //chain->SetBranchStatus("muon_phiLayer1STGCHoles", 1);
    //chain->SetBranchStatus("muon_phiLayer2STGCHoles", 1);
    //chain->SetBranchStatus("muon_etaLayer1STGCHoles", 1);
    //chain->SetBranchStatus("muon_etaLayer2STGCHoles", 1);
    //chain->SetBranchStatus("muon_MMHits", 1);
    //chain->SetBranchStatus("muon_MMHoles", 1);
    //chain->SetBranchStatus("muon_nSegments", 1);
    //chain->SetBranchStatus("muon_seg_chiSquared", 1);
    //chain->SetBranchStatus("muon_seg_numberDoF", 1);
    //chain->SetBranchStatus("muon_seg_sector", 1);
    chain->SetBranchStatus("muon_seg_chamberIndex", 1);
    //chain->SetBranchStatus("muon_seg_nPrecisionHits", 1);
    //chain->SetBranchStatus("muon_seg_nPhiLayers", 1);
    //chain->SetBranchStatus("muon_seg_nTrigEtaLayers", 1);
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
    //Float_t         mcEventWeight;
    //Float_t         actualInteractionsPerCrossing;
    //Float_t         averageInteractionsPerCrossing;
    vector<float>   *muon_e = 0;
    vector<float>   *muon_pt = 0;
    vector<float>   *muon_eta = 0;
    vector<float>   *muon_phi = 0;
    vector<float>   *muon_charge = 0;
    vector<int>     *muon_quality = 0;
    //vector<bool>    *muon_isBadMuon_other;
    //vector<int>     *muon_truthType;
    //vector<int>     *muon_truthTypeMCTC;
    //vector<int>     *muon_truthOriginMCTC;
    //vector<int>     *muon_IFFtruthType;
    vector<int>     *muon_muonType = 0;
    vector<int>     *muon_author = 0;
    //vector<float>   *truthmuon_e;
    //vector<float>   *truthmuon_pt;
    //vector<float>   *truthmuon_eta;
    //vector<float>   *truthmuon_phi;
    //vector<int>     *truthmuon_pdgId;
    //vector<float>   *muon_mePt;
    //vector<float>   *muon_idPt;
    //vector<float>   *muon_cbPt;
    //vector<float>   *muon_meP;
    //vector<float>   *muon_idP;
    //vector<float>   *muon_etaMS;
    //vector<float>   *muon_phiMS;
    //vector<int>     *muon_innerSmallHits;
    //vector<int>     *muon_innerLargeHits;
    //vector<int>     *muon_middleSmallHits;
    //vector<int>     *muon_middleLargeHits;
    //vector<int>     *muon_outerSmallHits;
    //vector<int>     *muon_outerLargeHits;
    //vector<int>     *muon_extendedSmallHits;
    //vector<int>     *muon_extendedLargeHits;
    //vector<unsigned char> *muon_phiLayer1STGCHits;
    //vector<unsigned char> *muon_phiLayer2STGCHits;
    //vector<unsigned char> *muon_etaLayer1STGCHits;
    //vector<unsigned char> *muon_etaLayer2STGCHits;
    //vector<unsigned char> *muon_phiLayer1STGCHoles;
    //vector<unsigned char> *muon_phiLayer2STGCHoles;
    //vector<unsigned char> *muon_etaLayer1STGCHoles;
    //vector<unsigned char> *muon_etaLayer2STGCHoles;
    //vector<unsigned char> *muon_MMHits;
    //vector<unsigned char> *muon_MMHoles;
    //vector<unsigned long> *muon_nSegments;
    //vector<vector<float> > *muon_seg_chiSquared;
    //vector<vector<float> > *muon_seg_numberDoF;
    //vector<vector<int> > *muon_seg_sector;
    vector<vector<int> > *muon_seg_chamberIndex = 0;
    //vector<vector<int> > *muon_seg_nPrecisionHits;
    //vector<vector<int> > *muon_seg_nPhiLayers;
    //vector<vector<int> > *muon_seg_nTrigEtaLayers;
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

    //vector<vector<float> > *l2mt_ptEndcapAlpha;
    //vector<vector<float> > *l2mt_ptEndcapBeta;

    chain->SetBranchAddress("RunNumber", &RunNumber);
    chain->SetBranchAddress("LumiBlock", &LumiBlock);
    chain->SetBranchAddress("EventNumber", &EventNumber);
    chain->SetBranchAddress("pass_HLT_mu10_l2mt_L1MU10BOM", &pass_HLT_mu10_l2mt_L1MU10BOM);
    //chain->SetBranchAddress("mcEventWeight", &mcEventWeight);
    //chain->SetBranchAddress("actualInteractionsPerCrossing", &actualInteractionsPerCrossing);
    //chain->SetBranchAddress("averageInteractionsPerCrossing", &averageInteractionsPerCrossing);
    chain->SetBranchAddress("muon_e", &muon_e);
    chain->SetBranchAddress("muon_pt", &muon_pt);
    chain->SetBranchAddress("muon_eta", &muon_eta);
    chain->SetBranchAddress("muon_phi", &muon_phi);
    chain->SetBranchAddress("muon_charge", &muon_charge);
    chain->SetBranchAddress("muon_quality", &muon_quality);
    //chain->SetBranchAddress("muon_isBadMuon_other", &muon_isBadMuon_other);
    //chain->SetBranchAddress("muon_truthType", &muon_truthType);
    //chain->SetBranchAddress("muon_truthTypeMCTC", &muon_truthTypeMCTC);
    //chain->SetBranchAddress("muon_truthOriginMCTC", &muon_truthOriginMCTC);
    //chain->SetBranchAddress("muon_IFFtruthType", &muon_IFFtruthType);
    chain->SetBranchAddress("muon_muonType", &muon_muonType);
    chain->SetBranchAddress("muon_author", &muon_author);
    //chain->SetBranchAddress("truthmuon_e", &truthmuon_e);
    //chain->SetBranchAddress("truthmuon_pt", &truthmuon_pt);
    //chain->SetBranchAddress("truthmuon_eta", &truthmuon_eta);
    //chain->SetBranchAddress("truthmuon_phi", &truthmuon_phi);
    //chain->SetBranchAddress("truthmuon_pdgId", &truthmuon_pdgId);
    //chain->SetBranchAddress("muon_mePt", &muon_mePt);
    //chain->SetBranchAddress("muon_idPt", &muon_idPt);
    //chain->SetBranchAddress("muon_cbPt", &muon_cbPt);
    //chain->SetBranchAddress("muon_meP", &muon_meP);
    //chain->SetBranchAddress("muon_idP", &muon_idP);
    //chain->SetBranchAddress("muon_etaMS", &muon_etaMS);
    //chain->SetBranchAddress("muon_phiMS", &muon_phiMS);
    //chain->SetBranchAddress("muon_innerSmallHits", &muon_innerSmallHits);
    //chain->SetBranchAddress("muon_innerLargeHits", &muon_innerLargeHits);
    //chain->SetBranchAddress("muon_middleSmallHits", &muon_middleSmallHits);
    //chain->SetBranchAddress("muon_middleLargeHits", &muon_middleLargeHits);
    //chain->SetBranchAddress("muon_outerSmallHits", &muon_outerSmallHits);
    //chain->SetBranchAddress("muon_outerLargeHits", &muon_outerLargeHits);
    //chain->SetBranchAddress("muon_extendedSmallHits", &muon_extendedSmallHits);
    //chain->SetBranchAddress("muon_extendedLargeHits", &muon_extendedLargeHits);
    //chain->SetBranchAddress("muon_phiLayer1STGCHits", &muon_phiLayer1STGCHits);
    //chain->SetBranchAddress("muon_phiLayer2STGCHits", &muon_phiLayer2STGCHits);
    //chain->SetBranchAddress("muon_etaLayer1STGCHits", &muon_etaLayer1STGCHits);
    //chain->SetBranchAddress("muon_etaLayer2STGCHits", &muon_etaLayer2STGCHits);
    //chain->SetBranchAddress("muon_phiLayer1STGCHoles", &muon_phiLayer1STGCHoles);
    //chain->SetBranchAddress("muon_phiLayer2STGCHoles", &muon_phiLayer2STGCHoles);
    //chain->SetBranchAddress("muon_etaLayer1STGCHoles", &muon_etaLayer1STGCHoles);
    //chain->SetBranchAddress("muon_etaLayer2STGCHoles", &muon_etaLayer2STGCHoles);
    //chain->SetBranchAddress("muon_MMHits", &muon_MMHits);
    //chain->SetBranchAddress("muon_MMHoles", &muon_MMHoles);
    //chain->SetBranchAddress("muon_nSegments", &muon_nSegments);
    //chain->SetBranchAddress("muon_seg_chiSquared", &muon_seg_chiSquared);
    //chain->SetBranchAddress("muon_seg_numberDoF", &muon_seg_numberDoF);
    //chain->SetBranchAddress("muon_seg_sector", &muon_seg_sector);
    chain->SetBranchAddress("muon_seg_chamberIndex", &muon_seg_chamberIndex);
    //chain->SetBranchAddress("muon_seg_nPrecisionHits", &muon_seg_nPrecisionHits);
    //chain->SetBranchAddress("muon_seg_nPhiLayers", &muon_seg_nPhiLayers);
    //chain->SetBranchAddress("muon_seg_nTrigEtaLayers", &muon_seg_nTrigEtaLayers);
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

    //chain->SetBranchAddress("l2mt_ptEndcapAlpha", &l2mt_ptEndcapAlpha, &b_l2mt_ptEndcapAlpha);
    //chain->SetBranchAddress("l2mt_ptEndcapBeta", &l2mt_ptEndcapBeta, &b_l2mt_ptEndcapBeta);

    TH1D *offline1_L1_deltaR_hist = new TH1D("offline1_L1_deltaR_hist", "offline1_L1_deltaR_hist", 20, 0, 1);
    TH1D *match_offline1_L1_deltaR_hist = new TH1D("match_offline1_L1_deltaR_hist", "match_offline1_L1_deltaR_hist", 20, 0, 1);
    TH1D *offline2_L1_deltaR_hist = new TH1D("offline2_L1_deltaR_hist", "offline2_L1_deltaR_hist", 20, 0, 1);
    TH1D *match_offline2_L1_deltaR_hist = new TH1D("match_offline2_L1_deltaR_hist", "match_offline2_L1_deltaR_hist", 20, 0, 1);

    TH1D *pair_mass_hist_mu10 = new TH1D("pair_mass_hist_mu10", "pair_mass_hist_mu10", 100, 0, 30);
    TH1D *cut_pair_mass_hist_mu10 = new TH1D("cut_pair_mass_hist_mu10", "cut_pair_mass_hist_mu10", 100, 0, 30);
    TH1D *pair_deltaR_hist_mu10 = new TH1D("pair_deltaR_hist_mu10", "pair_deltaR_hist_mu10", 10, 0, 0.5);
    TH1D *cut_pair_deltaR_hist_mu10 = new TH1D("cut_pair_deltaR_hist_mu10", "cut_pair_deltaR_hist_mu10", 10, 0, 0.5);
    TH1D *pair_ext_deltaR_hist_mu10 = new TH1D("pair_ext_deltaR_hist_mu10", "pair_ext_deltaR_hist_mu10", 10, 0, 0.5);
    TH1D *cut_pair_ext_deltaR_hist_mu10 = new TH1D("cut_pair_ext_deltaR_hist_mu10", "cut_pair_ext_deltaR_hist_mu10", 10, 0, 0.5);
    TH1D *pair_deltaPhi_hist_mu10 = new TH1D("pair_deltaPhi_hist_mu10", "pair_deltaPhi_hist_mu10", 100, -1, 1);
    TH1D *cut_pair_deltaPhi_hist_mu10 = new TH1D("cut_pair_deltaPhi_hist_mu10", "cut_pair_deltaPhi_hist_mu10", 100, -1, 1);
    TH1D *pair_ext_deltaPhi_hist_mu10 = new TH1D("pair_ext_deltaPhi_hist_mu10", "pair_ext_deltaPhi_hist_mu10", 100, -1, 1);
    TH1D *cut_pair_ext_deltaPhi_hist_mu10 = new TH1D("cut_pair_ext_deltaPhi_hist_mu10", "cut_pair_ext_deltaPhi_hist_mu10", 100, -1, 1);
    TH1D *pair_pt_hist_mu10 = new TH1D("pair_pt_hist_mu10", "pair_pt_hist_mu10", 50, 0, 100);
    TH1D *cut_pair_pt_hist_mu10 = new TH1D("cut_pair_pt_hist_mu10", "cut_pair_pt_hist_mu10", 50, 0, 100);
    TH1D *min_pt_hist_mu10 = new TH1D("min_pt_hist_mu10", "min_pt_hist_mu10", 50, 0, 100);
    TH1D *max_pt_hist_mu10 = new TH1D("max_pt_hist_mu10", "max_pt_hist_mu10", 50, 0, 100);
    TH1D *cut_min_pt_hist_mu10 = new TH1D("cut_min_pt_hist_mu10", "cut_min_pt_hist_mu10", 50, 0, 100);
    TH1D *cut_max_pt_hist_mu10 = new TH1D("cut_max_pt_hist_mu10", "cut_max_pt_hist_mu10", 50, 0, 100);

    TH1D *pair_mass_hist_2mu10 = new TH1D("pair_mass_hist_2mu10", "pair_mass_hist_2mu10", 100, 0, 30);
    TH1D *cut_pair_mass_hist_2mu10 = new TH1D("cut_pair_mass_hist_2mu10", "cut_pair_mass_hist_2mu10", 100, 0, 30);
    TH1D *pair_deltaR_hist_2mu10 = new TH1D("pair_deltaR_hist_2mu10", "pair_deltaR_hist_2mu10", 10, 0, 0.5);
    TH1D *cut_pair_deltaR_hist_2mu10 = new TH1D("cut_pair_deltaR_hist_2mu10", "cut_pair_deltaR_hist_2mu10", 10, 0, 0.5);
    TH1D *pair_ext_deltaR_hist_2mu10 = new TH1D("pair_ext_deltaR_hist_2mu10", "pair_ext_deltaR_hist_2mu10", 10, 0, 0.5);
    TH1D *cut_pair_ext_deltaR_hist_2mu10 = new TH1D("cut_pair_ext_deltaR_hist_2mu10", "cut_pair_ext_deltaR_hist_2mu10", 10, 0, 0.5);
    TH1D *pair_deltaPhi_hist_2mu10 = new TH1D("pair_deltaPhi_hist_2mu10", "pair_deltaPhi_hist_2mu10", 100, -1, 1);
    TH1D *cut_pair_deltaPhi_hist_2mu10 = new TH1D("cut_pair_deltaPhi_hist_2mu10", "cut_pair_deltaPhi_hist_2mu10", 100, -1, 1);
    TH1D *pair_ext_deltaPhi_hist_2mu10 = new TH1D("pair_ext_deltaPhi_hist_2mu10", "pair_ext_deltaPhi_hist_2mu10", 100, -1, 1);
    TH1D *cut_pair_ext_deltaPhi_hist_2mu10 = new TH1D("cut_pair_ext_deltaPhi_hist_2mu10", "cut_pair_ext_deltaPhi_hist_2mu10", 100, -1, 1);
    TH1D *pair_pt_hist_2mu10 = new TH1D("pair_pt_hist_2mu10", "pair_pt_hist_2mu10", 50, 0, 100);
    TH1D *cut_pair_pt_hist_2mu10 = new TH1D("cut_pair_pt_hist_2mu10", "cut_pair_pt_hist_2mu10", 50, 0, 100);
    TH1D *min_pt_hist_2mu10 = new TH1D("min_pt_hist_2mu10", "min_pt_hist_2mu10", 50, 0, 100);
    TH1D *max_pt_hist_2mu10 = new TH1D("max_pt_hist_2mu10", "max_pt_hist_2mu10", 50, 0, 100);
    TH1D *cut_min_pt_hist_2mu10 = new TH1D("cut_min_pt_hist_2mu10", "cut_min_pt_hist_2mu10", 50, 0, 100);
    TH1D *cut_max_pt_hist_2mu10 = new TH1D("cut_max_pt_hist_2mu10", "cut_max_pt_hist_2mu10", 50, 0, 100);

    TH1D *singleMuonPt_hist = new TH1D("singleMuonPt_hist", "singleMuonPt_hist", 20, 0, 100);
    TH1D *cut_singleMuonPt_hist = new TH1D("cut_singleMuonPt_hist", "cut_singleMuonPt_hist", 20, 0, 100);
    TH1D *singleMuonEta_hist = new TH1D("singleMuonEta_hist", "singleMuonEta_hist", 30, -1.5, 1.5);
    TH1D *cut_singleMuonEta_hist = new TH1D("cut_singleMuonEta_hist", "cut_singleMuonEta_hist", 30, -1.5, 1.5);
    TH1D *singleMuonPhi_hist = new TH1D("singleMuonPhi_hist", "singleMuonPhi_hist", 30, -1.5, 1.5);
    TH1D *cut_singleMuonPhi_hist = new TH1D("cut_singleMuonPhi_hist", "cut_singleMuonPhi_hist", 30, -1.5, 1.5);
    
    TH1D *HLTmuons_hist = new TH1D("HLTmuons_hist", "HLTmuons_hist", 5, 0, 5);
    TH1D *HLTmuons_withl2mtpass_hist = new TH1D("HLTmuons_withl2mtpass_hist", "HLTmuons_withl2mtpass_hist", 5, 0, 5);
    TH1D *l2mtpass_withl1flag_hist = new TH1D("l2mtpass_withl1flag_hist", "l2mtpass_withl1flag_hist", 2, 0, 2);
    TH1D *l2mtpass_withl1BOM_hist = new TH1D("l2mtpass_withl1BOM_hist", "l2mtpass_withl1BOM_hist", 2, 0, 2);
    TH1D *l1BOM_withl2mtpass_hist = new TH1D("l1BOM_withl2mtpass_hist", "l1BOM_withl2mtpass_hist", 2, 0, 2);

    TH1D *l1thrNum_hist = new TH1D("l1thrNum_hist", "l1thrNum_hist", 7, 0, 7);

    TH1D *l2mtmuons_hist = new TH1D("l2mtmuons_hist", "l2mtmuons_hist", 8, 0, 8);

    TH1D *offline1_seg_deltaEta = new TH1D("offline1_seg_deltaEta", "offline1_seg_deltaEta", 60, -3, 3);
    TH1D *offline1_seg_deltaPhi = new TH1D("offline1_seg_deltaPhi", "offline1_seg_deltaPhi", 60, -3, 3);
    TH1D *offline2_seg_deltaEta = new TH1D("offline2_seg_deltaEta", "offline2_seg_deltaEta", 60, -3, 3);
    TH1D *offline2_seg_deltaPhi = new TH1D("offline2_seg_deltaPhi", "offline2_seg_deltaPhi", 60, -3, 3);

    //TFile hist_file("img0829/hist0829_ext_mu10L2mt_v2.root", "RECREATE");
    TFile hist_file("img0907/hist0907_mu10L2mt.root", "RECREATE");
    //TFile hist_file("img0905/hist0905_mu10L2mt_Zmumu.root", "RECREATE");

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

        if(jentry % 100000 == 0){
            cout << jentry << endl;
        }

        chain->GetEntry(jentry);

        int trig_chain = 0;
        bool flag_trigger= false;
        float deltaR_thr = 0.08;
        bool matching_offline_HLT = false;
        bool flag_BOM= false;
        vector<pair<int, int>> match_offlinepair; 

        for(int i_trigger = 0; i_trigger < trigger_info_chain->size(); i_trigger++){
            if(trigger_info_chain->at(i_trigger) == "HLT_mu24_ivarmedium_L1MU14FCH"){
                trig_chain = i_trigger;
                flag_trigger = true;
            }
        }

        if(flag_trigger == true){
            for(int i_offline = 0; i_offline < muon_pt->size(); i_offline++){
                TVector3 offline_muon;
                offline_muon.SetPtEtaPhi(muon_pt->at(i_offline), muon_eta->at(i_offline), muon_phi->at(i_offline));

                //offline muon matching with HLT_mu24_ivarmedium
                for(int i_HLTmuon = 0; i_HLTmuon < trigger_info_ptVec->at(trig_chain).size(); i_HLTmuon++){
                    TVector3 hlt_muon;
                    hlt_muon.SetPtEtaPhi(trigger_info_ptVec->at(trig_chain).at(i_HLTmuon), trigger_info_etaVec->at(trig_chain).at(i_HLTmuon), trigger_info_phiVec->at(trig_chain).at(i_HLTmuon));
                    
                    float offline_HLT_DeltaR = offline_muon.DeltaR(hlt_muon);

                    if(offline_HLT_DeltaR < deltaR_thr) matching_offline_HLT = true;
                }
                if(matching_offline_HLT == false) continue;

                //offline muon matching with BOM ROI
                for(int i_roi = 0; i_roi < trig_L1_mu_eta->size(); i_roi++){
                    if(trig_L1_mu_moreCandInRPCPad->at(i_roi) == 1 && trig_L1_mu_source->at(i_roi) == 0){ //BOM
                        
                        flag_BOM = true;
                    
                        int BOM_roi = trig_L1_mu_RoINumber->at(i_roi);
                        int numberOfL2mt = 0;
                        int l2mt_roiNum = 0;

                        for(int i_l2mt = 0; i_l2mt < l2mt_pt->size(); i_l2mt++){
                            if(l1_roiNum->at(i_l2mt) == BOM_roi){
                                l2mt_roiNum = i_l2mt;
                                numberOfL2mt++;
                            }
                        }

                        if(numberOfL2mt == 0) continue;

                        float L1_offline1_deltaEta = muon_eta->at(i_offline) - trig_L1_mu_eta->at(i_roi);
                        float L1_offline1_deltaPhi = TVector2::Phi_mpi_pi(muon_phi->at(i_offline) - trig_L1_mu_phi->at(i_roi));
                        
                        float L1_offline1_DeltaR = TMath::Sqrt(L1_offline1_deltaEta*L1_offline1_deltaEta + L1_offline1_deltaPhi*L1_offline1_deltaPhi);

                        float deltaR_L1_req_mu1 = 0.15;
                        
                        bool matching_offline1_ROI = L1_offline1_DeltaR < deltaR_L1_req_mu1;

                        if(matching_offline1_ROI == true){
                            countSingleMuonMatchROI++;
                            singleMuonPt_hist->Fill(muon_pt->at(i_offline));
                            singleMuonEta_hist->Fill(muon_eta->at(i_offline));
                            singleMuonPhi_hist->Fill(muon_phi->at(i_offline));
                            if(numberOfL2mt == 1){
                                count1L2mtMatchROI++;
                                cut_singleMuonPt_hist->Fill(muon_pt->at(i_offline));
                                cut_singleMuonEta_hist->Fill(muon_eta->at(i_offline));
                                cut_singleMuonPhi_hist->Fill(muon_phi->at(i_offline));
                            }
                        }
                    }
                }
            }
        }

        //mu10 2muon efficiency
        if(pass_HLT_mu10_l2mt_L1MU10BOM == false) continue;

        for(int i_roi = 0; i_roi < trig_L1_mu_eta->size(); i_roi++){
            if(trig_L1_mu_moreCandInRPCPad->at(i_roi) == 1 && trig_L1_mu_source->at(i_roi) == 0){ //BOM

                flag_BOM = true;

                int BOM_roi = trig_L1_mu_RoINumber->at(i_roi);
                int countOfL2mt = 0;
                int l2mt_roiNum = 0;

                for(int i_l2mt = 0; i_l2mt < l2mt_pt->size(); i_l2mt++){
                    if(l1_roiNum->at(i_l2mt) == BOM_roi && l2mt_pass->at(i_l2mt) == 1){
                        l2mt_roiNum = i_l2mt;
                        countOfL2mt++;
                    }
                }

                if(countOfL2mt == 0) continue;

                for(int i_offline = 0; i_offline < muon_pt->size(); i_offline++){

                    //pt cut(10GeV)
                    //if(muon_pt->at(i_offline) < 10) continue;

                    float mu1_seg_theta = 999;
                    float mu1_seg_phi = 999;
                    float mu1_seg_eta = 999;

                    for(int i_chamber = 0; i_chamber < muon_seg_chamberIndex->at(i_offline).size(); i_chamber++){
                        if(muon_seg_chamberIndex->at(i_offline).at(i_chamber) == 2 || muon_seg_chamberIndex->at(i_offline).at(i_chamber) == 3){
                            //mu1_seg_theta = std::atan2(std::sqrt(muon_seg_x->at(i_offline).at(i_chamber) * muon_seg_x->at(i_offline).at(i_chamber) + muon_seg_y->at(i_offline).at(i_chamber) * muon_seg_y->at(i_offline).at(i_chamber)), muon_seg_z->at(i_offline).at(i_chamber));
                            //mu1_seg_phi = std::atan2(muon_seg_y->at(i_offline).at(i_chamber) , muon_seg_x->at(i_offline).at(i_chamber));
                            //mu1_seg_eta = -1*log(tan(mu1_seg_theta / 2)); 
                            TVector3 seg_muon1(muon_seg_x->at(i_offline).at(i_chamber), muon_seg_y->at(i_offline).at(i_chamber), muon_seg_z->at(i_offline).at(i_chamber));
                            mu1_seg_phi = seg_muon1.Phi();
                            mu1_seg_eta = seg_muon1.Eta();

                        }
                    }

                    if(mu1_seg_eta > 900) continue;

                    TLorentzVector mu1;
                    mu1.SetPtEtaPhiE(muon_pt->at(i_offline), muon_eta->at(i_offline), muon_phi->at(i_offline), muon_e->at(i_offline));

                    TLorentzVector ext_mu1;
                    ext_mu1.SetPtEtaPhiE(muon_pt->at(i_offline), mu1_seg_eta, mu1_seg_phi, muon_e->at(i_offline));

                    //deltaR offline muon and L1 muon
                    float L1_offline1_deltaEta = mu1_seg_eta - trig_L1_mu_eta->at(i_roi);
                    float L1_offline1_deltaPhi = TVector2::Phi_mpi_pi(mu1_seg_phi - trig_L1_mu_phi->at(i_roi));
                    
                    float L1_offline1_DeltaR = TMath::Sqrt(L1_offline1_deltaEta*L1_offline1_deltaEta + L1_offline1_deltaPhi*L1_offline1_deltaPhi);

                    float L1_offline1_seg_deltaPhi = TVector2::Phi_mpi_pi(mu1_seg_phi - muon_phi->at(i_offline));
                    float L1_offline1_seg_deltaEta = mu1_seg_eta - muon_eta->at(i_offline);

                    offline1_seg_deltaPhi->Fill(L1_offline1_seg_deltaPhi);
                    offline1_seg_deltaEta->Fill(L1_offline1_seg_deltaEta);

                    float deltaR_L1_req_mu1 = 0.15;

                    offline1_L1_deltaR_hist->Fill(L1_offline1_DeltaR);
                    
                    bool matching_offline1_L2mtROI = L1_offline1_DeltaR < deltaR_L1_req_mu1;

                    if(matching_offline1_L2mtROI == true){
                        
                        match_offline1_L1_deltaR_hist->Fill(L1_offline1_DeltaR);

                        for (int j_offline = 0; j_offline < i_offline; j_offline++){
                            
                            if(i_offline == j_offline) continue;

                            float mu2_seg_theta = 999;
                            float mu2_seg_phi = 999;
                            float mu2_seg_eta = 999;
                            
                            for(int j_chamber = 0; j_chamber < muon_seg_chamberIndex->at(j_offline).size(); j_chamber++){
                                if(muon_seg_chamberIndex->at(j_offline).at(j_chamber) == 2 || muon_seg_chamberIndex->at(j_offline).at(j_chamber) == 3){
                                    //mu2_seg_theta = std::atan2(std::sqrt(muon_seg_x->at(j_offline).at(j_chamber) * muon_seg_x->at(j_offline).at(j_chamber) + muon_seg_y->at(j_offline).at(j_chamber) * muon_seg_y->at(j_offline).at(j_chamber)), muon_seg_z->at(j_offline).at(j_chamber));
                                    //mu2_seg_phi = std::atan2(muon_seg_y->at(j_offline).at(j_chamber) , muon_seg_x->at(j_offline).at(j_chamber));
                                    //mu2_seg_eta = -1*log(tan(mu2_seg_theta / 2));
                                    TVector3 seg_muon2(muon_seg_x->at(j_offline).at(j_chamber), muon_seg_y->at(j_offline).at(j_chamber), muon_seg_z->at(j_offline).at(j_chamber));
                                    mu2_seg_phi = seg_muon2.Phi();
                                    mu2_seg_eta = seg_muon2.Eta();
                                }
                            }

                            if(mu2_seg_phi > 900) continue;

                            TLorentzVector mu2;
                            mu2.SetPtEtaPhiE(muon_pt->at(j_offline), muon_eta->at(j_offline), muon_phi->at(j_offline), muon_e->at(j_offline));

                            TLorentzVector ext_mu2;
                            ext_mu2.SetPtEtaPhiE(muon_pt->at(j_offline), mu2_seg_eta, mu2_seg_phi, muon_e->at(j_offline));

                            //deltaR offline muon and L1 muon
                            float L1_offline2_deltaEta = mu2_seg_eta - trig_L1_mu_eta->at(i_roi);
                            float L1_offline2_deltaPhi = TVector2::Phi_mpi_pi(mu2_seg_phi - trig_L1_mu_phi->at(i_roi));

                            float L1_offline2_DeltaR = TMath::Sqrt(L1_offline2_deltaEta*L1_offline2_deltaEta + L1_offline2_deltaPhi*L1_offline2_deltaPhi);

                            float L1_offline2_seg_deltaPhi = TVector2::Phi_mpi_pi(mu2_seg_phi - muon_phi->at(j_offline));
                            float L1_offline2_seg_deltaEta = mu2_seg_eta - muon_eta->at(j_offline);

                            offline2_seg_deltaPhi->Fill(L1_offline2_seg_deltaPhi);
                            offline2_seg_deltaEta->Fill(L1_offline2_seg_deltaEta);

                            float deltaR_L1_req_mu2 = 0.15;

                            offline2_L1_deltaR_hist->Fill(L1_offline2_DeltaR);
                            
                            bool matching_offline2_L2mtROI = L1_offline2_DeltaR < deltaR_L1_req_mu2;
                            
                            if(matching_offline2_L2mtROI == true){

                                offline2_L1_deltaR_hist->Fill(L1_offline2_DeltaR);

                                float max_pt = 0;
                                float min_pt = 0;
                                int min_pt_muon_num = 0;
                                int max_pt_muon_num = 0;

                                if(muon_pt->at(i_offline) < muon_pt->at(j_offline)){
                                    max_pt = muon_pt->at(j_offline);
                                    min_pt = muon_pt->at(i_offline);
                                    min_pt_muon_num = i_offline;
                                    max_pt_muon_num = j_offline;
                                }

                                else{
                                    max_pt = muon_pt->at(i_offline);
                                    min_pt = muon_pt->at(j_offline);
                                    min_pt_muon_num = j_offline;
                                    max_pt_muon_num = i_offline;
                                }
                                
                                if(max_pt > 10){
                                    TLorentzVector ext_mu_pair = ext_mu1 + ext_mu2;
                                    TLorentzVector mu_pair = mu1 + mu2;
                                    float pair_mass = mu_pair.M();
                                    float pair_deltaR = mu2.DeltaR(mu1);
                                    float pair_deltaPhi = mu2.DeltaPhi(mu1);
                                    float pair_ext_deltaR = ext_mu2.DeltaR(ext_mu1);
                                    float pair_ext_deltaPhi = ext_mu2.DeltaPhi(ext_mu1);

                                    pair_mass_hist_mu10->Fill(pair_mass);
                                    pair_deltaR_hist_mu10->Fill(pair_deltaR);
                                    pair_ext_deltaR_hist_mu10->Fill(pair_ext_deltaR);
                                    pair_deltaPhi_hist_mu10->Fill(pair_deltaPhi);
                                    pair_ext_deltaPhi_hist_mu10->Fill(pair_ext_deltaPhi);
                                    pair_pt_hist_mu10->Fill(mu1.Pt());
                                    pair_pt_hist_mu10->Fill(mu2.Pt());
                                    min_pt_hist_mu10->Fill(muon_pt->at(min_pt_muon_num));
                                    max_pt_hist_mu10->Fill(muon_pt->at(max_pt_muon_num));

                                    //BOM_roi.push_back(trig_L1_mu_RoINumber->at(i_roi));
                                    //match_offlinepair.push_back(make_pair(i_offline, j_offline));

                                    //MatchWithSameRoi++;

                                    if(countOfL2mt == 2){
                                        cut_pair_mass_hist_mu10->Fill(pair_mass);
                                        cut_pair_deltaR_hist_mu10->Fill(pair_deltaR);
                                        cut_pair_ext_deltaR_hist_mu10->Fill(pair_ext_deltaR);
                                        cut_pair_deltaPhi_hist_mu10->Fill(pair_deltaPhi);
                                        cut_pair_ext_deltaPhi_hist_mu10->Fill(pair_deltaPhi);
                                        cut_pair_pt_hist_mu10->Fill(mu1.Pt());
                                        cut_pair_pt_hist_mu10->Fill(mu2.Pt());
                                        cut_min_pt_hist_mu10->Fill(muon_pt->at(min_pt_muon_num));
                                        cut_max_pt_hist_mu10->Fill(muon_pt->at(max_pt_muon_num));
                                    }

                                    if(min_pt > 10){
                                        pair_mass_hist_2mu10->Fill(pair_mass);
                                        pair_deltaR_hist_2mu10->Fill(pair_deltaR);
                                        pair_ext_deltaR_hist_2mu10->Fill(pair_ext_deltaR);
                                        pair_deltaPhi_hist_2mu10->Fill(pair_deltaPhi);
                                        pair_ext_deltaPhi_hist_2mu10->Fill(pair_ext_deltaPhi);
                                        pair_pt_hist_2mu10->Fill(mu1.Pt());
                                        pair_pt_hist_2mu10->Fill(mu2.Pt());
                                        min_pt_hist_2mu10->Fill(muon_pt->at(min_pt_muon_num));
                                        max_pt_hist_2mu10->Fill(muon_pt->at(max_pt_muon_num));

                                        //BOM_roi.push_back(trig_L1_mu_RoINumber->at(i_roi));
                                        //match_offlinepair.push_back(make_pair(i_offline, j_offline));

                                        //MatchWithSameRoi++;

                                        if(countOfL2mt == 2){
                                            cut_pair_mass_hist_2mu10->Fill(pair_mass);
                                            cut_pair_deltaR_hist_2mu10->Fill(pair_deltaR);
                                            cut_pair_ext_deltaR_hist_2mu10->Fill(pair_ext_deltaR);
                                            cut_pair_deltaPhi_hist_2mu10->Fill(pair_deltaPhi);
                                            cut_pair_ext_deltaPhi_hist_2mu10->Fill(pair_ext_deltaPhi);
                                            cut_pair_pt_hist_2mu10->Fill(mu1.Pt());
                                            cut_pair_pt_hist_2mu10->Fill(mu2.Pt());
                                            cut_min_pt_hist_2mu10->Fill(muon_pt->at(min_pt_muon_num));
                                            cut_max_pt_hist_2mu10->Fill(muon_pt->at(max_pt_muon_num));
                                        } 
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    cout << countSingleMuonMatchROI << endl;
    cout << count1L2mtMatchROI << endl;

    hist_file.cd();

    singleMuonPt_hist->Write();
    singleMuonEta_hist->Write();
    singleMuonPhi_hist->Write();
    cut_singleMuonPt_hist->Write();
    cut_singleMuonEta_hist->Write();
    cut_singleMuonPhi_hist->Write();
    offline1_seg_deltaEta->Write();
    offline1_seg_deltaPhi->Write();
    offline2_seg_deltaEta->Write();
    offline2_seg_deltaPhi->Write();
    offline1_L1_deltaR_hist->Write();
    match_offline1_L1_deltaR_hist->Write();
    offline2_L1_deltaR_hist->Write();
    match_offline2_L1_deltaR_hist->Write();
    pair_mass_hist_mu10->Write();
    pair_deltaR_hist_mu10->Write();
    pair_deltaPhi_hist_mu10->Write();
    pair_ext_deltaR_hist_mu10->Write();
    pair_ext_deltaPhi_hist_mu10->Write();
    pair_pt_hist_mu10->Write();
    min_pt_hist_mu10->Write();
    max_pt_hist_mu10->Write();
    cut_pair_mass_hist_mu10->Write();
    cut_pair_deltaR_hist_mu10->Write();
    cut_pair_deltaPhi_hist_mu10->Write();
    cut_pair_ext_deltaR_hist_mu10->Write();
    cut_pair_ext_deltaPhi_hist_mu10->Write();
    cut_pair_pt_hist_mu10->Write();
    cut_min_pt_hist_mu10->Write();
    cut_max_pt_hist_mu10->Write();
    pair_mass_hist_2mu10->Write();
    pair_deltaR_hist_2mu10->Write();
    pair_deltaPhi_hist_2mu10->Write();
    pair_ext_deltaR_hist_2mu10->Write();
    pair_ext_deltaPhi_hist_2mu10->Write();
    pair_pt_hist_2mu10->Write();
    min_pt_hist_2mu10->Write();
    max_pt_hist_2mu10->Write();
    cut_pair_mass_hist_2mu10->Write();
    cut_pair_deltaR_hist_2mu10->Write();
    cut_pair_deltaPhi_hist_2mu10->Write();
    cut_pair_ext_deltaR_hist_2mu10->Write();
    cut_pair_ext_deltaPhi_hist_2mu10->Write();
    cut_pair_pt_hist_2mu10->Write();
    cut_min_pt_hist_2mu10->Write();
    cut_max_pt_hist_2mu10->Write();
    l1thrNum_hist->Write();
    HLTmuons_hist->Write();
    l2mtmuons_hist->Write();
    HLTmuons_withl2mtpass_hist->Write();
    l2mtpass_withl1flag_hist->Write();
    l2mtpass_withl1BOM_hist->Write();
    l1BOM_withl2mtpass_hist->Write();
    
    hist_file.Close();
}
