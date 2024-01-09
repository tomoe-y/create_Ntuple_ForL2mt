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

void dimuon(){
    TChain* chain = new TChain("analysis");

    //MC
    //chain->Add("/gpfs/fs8001/toyamash/L2mt/user.toyamash.valid1.801164.P8B_A14_CTEQ6L1_bb_Jpsi1S_mu6mu4.MC.e8514_e8528_s4111_s4114_r14781_tid33979104_00.MC.5_NTUP_ANALYSIS/*.root");
    chain->Add("/gpfs/fs8001/toyamash/L2mt/user.toyamash.mc23_13p6TeV.801164.P8B_A14_CTEQ6L1_bb_Jpsi1S_mu6mu4.e8542_e8528_s4159_s4114_r14799_r14811.MC_NTUP_ANALYSIS/*.root");

    chain->SetBranchStatus("*", 0);
    chain->SetBranchStatus("RunNumber", 1);
    chain->SetBranchStatus("LumiBlock", 1);
    chain->SetBranchStatus("EventNumber", 1);
    chain->SetBranchStatus("pass_HLT_mu10_l2mt_L1MU10BOM", 1);
    chain->SetBranchStatus("pass_HLT_2mu10_l2mt_L1MU10BOM", 1);
    chain->SetBranchStatus("pass_HLT_2mu14_L12MU8F", 1);
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
    bool pass_HLT_mu24_ivarmedium_L1MU14FCH = false;
    bool pass_HLT_2mu14_L12MU8F = false;
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
    chain->SetBranchAddress("pass_HLT_mu24_ivarmedium_L1MU14FCH", &pass_HLT_mu24_ivarmedium_L1MU14FCH);
    chain->SetBranchAddress("pass_HLT_2mu14_L12MU8F", &pass_HLT_2mu14_L12MU8F);
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

    TH1D *dimuon_mass_hist = new TH1D("dimuon_mass_hist", "dimuon_mass_hist", 100, 0, 10);
    TH1D *dimuon_deltaR_hist = new TH1D("dimuon_deltaR_hist", "dimuon_deltaR_hist", 20, 0, 1);
    TH1D *dimuon_deltaPhi_hist = new TH1D("dimuon_deltaPhi_hist", "dimuon_deltaPhi_hist", 10, -1, 1);

    TH1D *pair_mass_l2mt_hist = new TH1D("pair_mass_l2mt_hist", "pair_mass_l2mt_hist", 100, 0, 10);
    TH1D *cut_pair_mass_l2mt_hist = new TH1D("cut_pair_mass_l2mt_hist", "cut_pair_mass_l2mt_hist", 100, 0, 10);
    TH1D *pair_deltaR_l2mt_hist = new TH1D("pair_deltaR_l2mt_hist", "pair_deltaR_l2mt_hist", 10, 0, 0.5);
    TH1D *cut_pair_deltaR_l2mt_hist = new TH1D("cut_pair_deltaR_l2mt_hist", "cut_pair_deltaR_l2mt_hist", 10, 0, 0.5);
    TH1D *pair_ext_mass_l2mt_hist = new TH1D("pair_ext_mass_l2mt_hist", "pair_ext_mass_l2mt_hist", 100, 0, 10);
    TH1D *pair_ext_deltaR_l2mt_hist = new TH1D("pair_ext_deltaR_l2mt_hist", "pair_ext_deltaR_l2mt_hist", 10, 0, 0.5);
    TH1D *cut_pair_ext_mass_l2mt_hist = new TH1D("cut_pair_ext_mass_l2mt_hist", "cut_pair_ext_mass_l2mt_hist", 100, 0, 10);
    TH1D *cut_pair_ext_deltaR_l2mt_hist = new TH1D("cut_pair_ext_deltaR_l2mt_hist", "cut_pair_ext_deltaR_l2mt_hist", 10, 0, 0.5);
    TH1D *pair_deltaPhi_l2mt_hist = new TH1D("pair_deltaPhi_l2mt_hist", "pair_deltaPhi_l2mt_hist", 10, -1, 1);
    TH1D *cut_pair_deltaPhi_l2mt_hist = new TH1D("cut_pair_deltaPhi_l2mt_hist", "cut_pair_deltaPhi_l2mt_hist", 10, -1, 1);
    TH1D *pair_ext_deltaPhi_l2mt_hist = new TH1D("pair_ext_deltaPhi_l2mt_hist", "pair_ext_deltaPhi_l2mt_hist", 10, -1, 1);
    TH1D *cut_pair_ext_deltaPhi_l2mt_hist = new TH1D("cut_pair_ext_deltaPhi_l2mt_hist", "cut_pair_ext_deltaPhi_l2mt_hist", 10, -1, 1);
    TH1D *pair_pt_l2mt_hist = new TH1D("pair_pt_l2mt_hist", "pair_pt_l2mt_hist", 50, 0, 100);
    TH1D *cut_pair_pt_l2mt_hist = new TH1D("cut_pair_pt_l2mt_hist", "cut_pair_pt_l2mt_hist", 50, 0, 100);

    TH1D *pair_mass_Jpsi_l2mt_hist = new TH1D("pair_mass_Jpsi_l2mt_hist", "pair_mass_Jpsi_l2mt_hist", 100, 0, 10);
    TH1D *cut_pair_mass_Jpsi_l2mt_hist = new TH1D("cut_pair_mass_Jpsi_l2mt_hist", "cut_pair_mass_Jpsi_l2mt_hist", 100, 0, 10);
    TH1D *pair_deltaR_Jpsi_l2mt_hist = new TH1D("pair_deltaR_Jpsi_l2mt_hist", "pair_deltaR_Jpsi_l2mt_hist", 10, 0, 0.5);
    TH1D *cut_pair_deltaR_Jpsi_l2mt_hist = new TH1D("cut_pair_deltaR_Jpsi_l2mt_hist", "cut_pair_deltaR_Jpsi_l2mt_hist", 10, 0, 0.5);
    TH1D *pair_ext_mass_Jpsi_l2mt_hist = new TH1D("pair_ext_mass_Jpsi_l2mt_hist", "pair_ext_mass_Jpsi_l2mt_hist", 100, 0, 10);
    TH1D *pair_ext_deltaR_Jpsi_l2mt_hist = new TH1D("pair_ext_deltaR_Jpsi_l2mt_hist", "pair_ext_deltaR_Jpsi_l2mt_hist", 10, 0, 0.5);
    TH1D *cut_pair_ext_mass_Jpsi_l2mt_hist = new TH1D("cut_pair_ext_mass_Jpsi_l2mt_hist", "cut_pair_ext_mass_Jpsi_l2mt_hist", 100, 0, 10);
    TH1D *cut_pair_ext_deltaR_Jpsi_l2mt_hist = new TH1D("cut_pair_ext_deltaR_Jpsi_l2mt_hist", "cut_pair_ext_deltaR_Jpsi_l2mt_hist", 10, 0, 0.5);
    TH1D *pair_deltaPhi_Jpsi_l2mt_hist = new TH1D("pair_deltaPhi_Jpsi_l2mt_hist", "pair_deltaPhi_Jpsi_l2mt_hist", 10, -1, 1);
    TH1D *cut_pair_deltaPhi_Jpsi_l2mt_hist = new TH1D("cut_pair_deltaPhi_Jpsi_l2mt_hist", "cut_pair_deltaPhi_Jpsi_l2mt_hist", 10, -1, 1);
    TH1D *pair_ext_deltaPhi_Jpsi_l2mt_hist = new TH1D("pair_ext_deltaPhi_Jpsi_l2mt_hist", "pair_ext_deltaPhi_Jpsi_l2mt_hist", 10, -1, 1);
    TH1D *cut_pair_ext_deltaPhi_Jpsi_l2mt_hist = new TH1D("cut_pair_ext_deltaPhi_Jpsi_l2mt_hist", "cut_pair_ext_deltaPhi_Jpsi_l2mt_hist", 10, -1, 1);
    TH1D *pair_pt_Jpsi_l2mt_hist = new TH1D("pair_pt_Jpsi_l2mt_hist", "pair_pt_Jpsi_l2mt_hist", 50, 0, 100);
    TH1D *cut_pair_pt_Jpsi_l2mt_hist = new TH1D("cut_pair_pt_Jpsi_l2mt_hist", "cut_pair_pt_Jpsi_l2mt_hist", 50, 0, 100);

    TH1D *pair_mass_2mu14_hist = new TH1D("pair_mass_2mu14_hist", "pair_mass_2mu14_hist", 100, 0, 10);
    TH1D *cut_pair_mass_2mu14_hist = new TH1D("cut_pair_mass_2mu14_hist", "cut_pair_mass_2mu14_hist", 100, 0, 10);
    TH1D *pair_deltaR_2mu14_hist = new TH1D("pair_deltaR_2mu14_hist", "pair_deltaR_2mu14_hist", 10, 0, 0.5);
    TH1D *cut_pair_deltaR_2mu14_hist = new TH1D("cut_pair_deltaR_2mu14_hist", "cut_pair_deltaR_2mu14_hist", 10, 0, 0.5);
    TH1D *pair_ext_mass_2mu14_hist = new TH1D("pair_ext_mass_2mu14_hist", "pair_ext_mass_2mu14_hist", 100, 0, 10);
    TH1D *pair_ext_deltaR_2mu14_hist = new TH1D("pair_ext_deltaR_2mu14_hist", "pair_ext_deltaR_2mu14_hist", 10, 0, 0.5);
    TH1D *cut_pair_ext_mass_2mu14_hist = new TH1D("cut_pair_ext_mass_2mu14_hist", "cut_pair_ext_mass_2mu14_hist", 100, 0, 10);
    TH1D *cut_pair_ext_deltaR_2mu14_hist = new TH1D("cut_pair_ext_deltaR_2mu14_hist", "cut_pair_ext_deltaR_2mu14_hist", 10, 0, 0.5);
    TH1D *pair_deltaPhi_2mu14_hist = new TH1D("pair_deltaPhi_2mu14_hist", "pair_deltaPhi_2mu14_hist", 10, -1, 1);
    TH1D *cut_pair_deltaPhi_2mu14_hist = new TH1D("cut_pair_deltaPhi_2mu14_hist", "cut_pair_deltaPhi_2mu14_hist", 10, -1, 1);
    TH1D *pair_ext_deltaPhi_2mu14_hist = new TH1D("pair_ext_deltaPhi_2mu14_hist", "pair_ext_deltaPhi_2mu14_hist", 10, -1, 1);
    TH1D *cut_pair_ext_deltaPhi_2mu14_hist = new TH1D("cut_pair_ext_deltaPhi_2mu14_hist", "cut_pair_ext_deltaPhi_2mu14_hist", 10, -1, 1);
    TH1D *pair_pt_2mu14_hist = new TH1D("pair_pt_2mu14_hist", "pair_pt_2mu14_hist", 50, 0, 100);
    TH1D *cut_pair_pt_2mu14_hist = new TH1D("cut_pair_pt_2mu14_hist", "cut_pair_pt_2mu14_hist", 50, 0, 100);

    TH1D *pair_mass_Jpsi_2mu14_hist = new TH1D("pair_mass_Jpsi_2mu14_hist", "pair_mass_Jpsi_2mu14_hist", 100, 0, 10);
    TH1D *cut_pair_mass_Jpsi_2mu14_hist = new TH1D("cut_pair_mass_Jpsi_2mu14_hist", "cut_pair_mass_Jpsi_2mu14_hist", 100, 0, 10);
    TH1D *pair_deltaR_Jpsi_2mu14_hist = new TH1D("pair_deltaR_Jpsi_2mu14_hist", "pair_deltaR_Jpsi_2mu14_hist", 10, 0, 0.5);
    TH1D *cut_pair_deltaR_Jpsi_2mu14_hist = new TH1D("cut_pair_deltaR_Jpsi_2mu14_hist", "cut_pair_deltaR_Jpsi_2mu14_hist", 10, 0, 0.5);
    TH1D *pair_ext_mass_Jpsi_2mu14_hist = new TH1D("pair_ext_mass_Jpsi_2mu14_hist", "pair_ext_mass_Jpsi_2mu14_hist", 100, 0, 10);
    TH1D *pair_ext_deltaR_Jpsi_2mu14_hist = new TH1D("pair_ext_deltaR_Jpsi_2mu14_hist", "pair_ext_deltaR_Jpsi_2mu14_hist", 10, 0, 0.5);
    TH1D *cut_pair_ext_mass_Jpsi_2mu14_hist = new TH1D("cut_pair_ext_mass_Jpsi_2mu14_hist", "cut_pair_ext_mass_Jpsi_2mu14_hist", 100, 0, 10);
    TH1D *cut_pair_ext_deltaR_Jpsi_2mu14_hist = new TH1D("cut_pair_ext_deltaR_Jpsi_2mu14_hist", "cut_pair_ext_deltaR_Jpsi_2mu14_hist", 10, 0, 0.5);
    TH1D *pair_deltaPhi_Jpsi_2mu14_hist = new TH1D("pair_deltaPhi_Jpsi_2mu14_hist", "pair_deltaPhi_Jpsi_2mu14_hist", 10, -1, 1);
    TH1D *cut_pair_deltaPhi_Jpsi_2mu14_hist = new TH1D("cut_pair_deltaPhi_Jpsi_2mu14_hist", "cut_pair_deltaPhi_Jpsi_2mu14_hist", 10, -1, 1);
    TH1D *pair_ext_deltaPhi_Jpsi_2mu14_hist = new TH1D("pair_ext_deltaPhi_Jpsi_2mu14_hist", "pair_ext_deltaPhi_Jpsi_2mu14_hist", 10, -1, 1);
    TH1D *cut_pair_ext_deltaPhi_Jpsi_2mu14_hist = new TH1D("cut_pair_ext_deltaPhi_Jpsi_2mu14_hist", "cut_pair_ext_deltaPhi_Jpsi_2mu14_hist", 10, -1, 1);
    TH1D *pair_pt_Jpsi_2mu14_hist = new TH1D("pair_pt_Jpsi_2mu14_hist", "pair_pt_Jpsi_2mu14_hist", 50, 0, 100);
    TH1D *cut_pair_pt_Jpsi_2mu14_hist = new TH1D("cut_pair_pt_Jpsi_2mu14_hist", "cut_pair_pt_Jpsi_2mu14_hist", 50, 0, 100);

    TH1D *pair_mass_dimuon_hist = new TH1D("pair_mass_dimuon_hist", "pair_mass_dimuon_hist", 100, 0, 10);
    TH1D *cut_pair_mass_dimuon_hist = new TH1D("cut_pair_mass_dimuon_hist", "cut_pair_mass_dimuon_hist", 100, 0, 10);
    TH1D *pair_deltaR_dimuon_hist = new TH1D("pair_deltaR_dimuon_hist", "pair_deltaR_dimuon_hist", 10, 0, 0.5);
    TH1D *cut_pair_deltaR_dimuon_hist = new TH1D("cut_pair_deltaR_dimuon_hist", "cut_pair_deltaR_dimuon_hist", 10, 0, 0.5);
    TH1D *pair_ext_mass_dimuon_hist = new TH1D("pair_ext_mass_dimuon_hist", "pair_ext_mass_dimuon_hist", 100, 0, 10);
    TH1D *pair_ext_deltaR_dimuon_hist = new TH1D("pair_ext_deltaR_dimuon_hist", "pair_ext_deltaR_dimuon_hist", 10, 0, 0.5);
    TH1D *cut_pair_ext_mass_dimuon_hist = new TH1D("cut_pair_ext_mass_dimuon_hist", "cut_pair_ext_mass_dimuon_hist", 100, 0, 10);
    TH1D *cut_pair_ext_deltaR_dimuon_hist = new TH1D("cut_pair_ext_deltaR_dimuon_hist", "cut_pair_ext_deltaR_dimuon_hist", 10, 0, 0.5);
    TH1D *pair_deltaPhi_dimuon_hist = new TH1D("pair_deltaPhi_dimuon_hist", "pair_deltaPhi_dimuon_hist", 10, -1, 1);
    TH1D *cut_pair_deltaPhi_dimuon_hist = new TH1D("cut_pair_deltaPhi_dimuon_hist", "cut_pair_deltaPhi_dimuon_hist", 10, -1, 1);
    TH1D *pair_ext_deltaPhi_dimuon_hist = new TH1D("pair_ext_deltaPhi_dimuon_hist", "pair_ext_deltaPhi_dimuon_hist", 10, -1, 1);
    TH1D *cut_pair_ext_deltaPhi_dimuon_hist = new TH1D("cut_pair_ext_deltaPhi_dimuon_hist", "cut_pair_ext_deltaPhi_dimuon_hist", 10, -1, 1);
    TH1D *pair_pt_dimuon_hist = new TH1D("pair_pt_dimuon_hist", "pair_pt_dimuon_hist", 50, 0, 100);
    TH1D *cut_pair_pt_dimuon_hist = new TH1D("cut_pair_pt_dimuon_hist", "cut_pair_pt_dimuon_hist", 50, 0, 100);

    TH1D *pair_mass_Jpsi_dimuon_hist = new TH1D("pair_mass_Jpsi_dimuon_hist", "pair_mass_Jpsi_dimuon_hist", 100, 0, 10);
    TH1D *cut_pair_mass_Jpsi_dimuon_hist = new TH1D("cut_pair_mass_Jpsi_dimuon_hist", "cut_pair_mass_Jpsi_dimuon_hist", 100, 0, 10);
    TH1D *pair_deltaR_Jpsi_dimuon_hist = new TH1D("pair_deltaR_Jpsi_dimuon_hist", "pair_deltaR_Jpsi_dimuon_hist", 10, 0, 0.5);
    TH1D *cut_pair_deltaR_Jpsi_dimuon_hist = new TH1D("cut_pair_deltaR_Jpsi_dimuon_hist", "cut_pair_deltaR_Jpsi_dimuon_hist", 10, 0, 0.5);
    TH1D *pair_ext_mass_Jpsi_dimuon_hist = new TH1D("pair_ext_mass_Jpsi_dimuon_hist", "pair_ext_mass_Jpsi_dimuon_hist", 100, 0, 10);
    TH1D *pair_ext_deltaR_Jpsi_dimuon_hist = new TH1D("pair_ext_deltaR_Jpsi_dimuon_hist", "pair_ext_deltaR_Jpsi_dimuon_hist", 10, 0, 0.5);
    TH1D *cut_pair_ext_mass_Jpsi_dimuon_hist = new TH1D("cut_pair_ext_mass_Jpsi_dimuon_hist", "cut_pair_ext_mass_Jpsi_dimuon_hist", 100, 0, 10);
    TH1D *cut_pair_ext_deltaR_Jpsi_dimuon_hist = new TH1D("cut_pair_ext_deltaR_Jpsi_dimuon_hist", "cut_pair_ext_deltaR_Jpsi_dimuon_hist", 10, 0, 0.5);
    TH1D *pair_deltaPhi_Jpsi_dimuon_hist = new TH1D("pair_deltaPhi_Jpsi_dimuon_hist", "pair_deltaPhi_Jpsi_dimuon_hist", 10, -1, 1);
    TH1D *cut_pair_deltaPhi_Jpsi_dimuon_hist = new TH1D("cut_pair_deltaPhi_Jpsi_dimuon_hist", "cut_pair_deltaPhi_Jpsi_dimuon_hist", 10, -1, 1);
    TH1D *pair_ext_deltaPhi_Jpsi_dimuon_hist = new TH1D("pair_ext_deltaPhi_Jpsi_dimuon_hist", "pair_ext_deltaPhi_Jpsi_dimuon_hist", 10, -1, 1);
    TH1D *cut_pair_ext_deltaPhi_Jpsi_dimuon_hist = new TH1D("cut_pair_ext_deltaPhi_Jpsi_dimuon_hist", "cut_pair_ext_deltaPhi_Jpsi_dimuon_hist", 10, -1, 1);
    TH1D *pair_pt_Jpsi_dimuon_hist = new TH1D("pair_pt_Jpsi_dimuon_hist", "pair_pt_Jpsi_dimuon_hist", 50, 0, 100);
    TH1D *cut_pair_pt_Jpsi_dimuon_hist = new TH1D("cut_pair_pt_Jpsi_dimuon_hist", "cut_pair_pt_Jpsi_dimuon_hist", 50, 0, 100);


    //TFile hist_file("img0910/hist0910_dimuon_2mu14.root", "RECREATE");
    TFile hist_file("img0910/hist0910_dimuon_v5.root", "RECREATE");

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

        if(jentry % 1000000 == 0){
            cout << jentry << endl;
        }
        int numOfOffline = 0;
        vector<pair<int, int>> mu_pair_number;
        
        chain->GetEntry(jentry);
        
        for(int i_offline = 0; i_offline < muon_pt->size(); i_offline++){

            bool flag_mu1_pt10_barrel = false;

            // pt cut (10GeV) & barrel only
            if(muon_pt->at(i_offline) > 10 && abs(muon_eta->at(i_offline)) < 1.05){
                flag_mu1_pt10_barrel = true;
            }

            if(flag_mu1_pt10_barrel == false) continue;

            TLorentzVector mu1;
            mu1.SetPtEtaPhiE(muon_pt->at(i_offline), muon_eta->at(i_offline), muon_phi->at(i_offline), muon_e->at(i_offline));

            for(int j_offline = 0; j_offline < i_offline; j_offline++){
                //pt cut(10GeV) & barrel only
                bool flag_mu2_pt10_barrel = false;

                // pt cut (10GeV) & barrel only
                if(muon_pt->at(j_offline) > 10 && abs(muon_eta->at(j_offline)) < 1.05){
                    flag_mu2_pt10_barrel = true;
                }

                if(flag_mu2_pt10_barrel == false) continue;
                
                TLorentzVector mu2;
                mu2.SetPtEtaPhiE(muon_pt->at(j_offline), muon_eta->at(j_offline), muon_phi->at(j_offline), muon_e->at(j_offline));
                
                TLorentzVector mu_pair = mu1 + mu2;
                float dimuon_mass = mu_pair.M();
                float dimuon_deltaR = mu2.DeltaR(mu1);
                float dimuon_deltaPhi = mu2.DeltaPhi(mu1);

                dimuon_mass_hist->Fill(dimuon_mass);
                dimuon_deltaR_hist->Fill(dimuon_deltaR);
                dimuon_deltaPhi_hist->Fill(dimuon_deltaPhi);

                mu_pair_number.push_back(make_pair(i_offline, j_offline));
                numOfOffline = 2;
            }
        }

        if(numOfOffline == 2){
            
            for(int i_mupair = 0; i_mupair < mu_pair_number.size(); i_mupair++){
                int offline1 = mu_pair_number.at(i_mupair).first;
                int offline2 = mu_pair_number.at(i_mupair).second;

                bool flag1_mu10_barrel = false;
                bool flag1_mu14_barrel = false;
                bool flag2_mu10_barrel = false;
                bool flag2_mu14_barrel = false;

                // pt cut (10GeV) & barrel only
                if(muon_pt->at(offline1) > 10 && abs(muon_eta->at(offline1)) < 1.05){
                    flag1_mu10_barrel = true;
                }

                if(muon_pt->at(offline1) > 14 && abs(muon_eta->at(offline1)) < 1.05){
                    flag1_mu14_barrel = true;
                }

                if(muon_pt->at(offline2) > 10 && abs(muon_eta->at(offline2)) < 1.05){
                    flag2_mu10_barrel = true;
                }

                if(muon_pt->at(offline2) > 14 && abs(muon_eta->at(offline2)) < 1.05){
                    flag2_mu14_barrel = true;
                }

                float mu1_seg_x = 999;
                float mu1_seg_y = 999;
                float mu1_seg_z = 999;
                float mu1_seg_theta = 999;
                float mu1_seg_phi = 999;
                float mu1_seg_eta = 999;

                float mu2_seg_x = 999;
                float mu2_seg_y = 999;
                float mu2_seg_z = 999;
                float mu2_seg_theta = 999;
                float mu2_seg_phi = 999;
                float mu2_seg_eta = 999;

                for(int i_chamber = 0; i_chamber < muon_seg_chamberIndex->at(offline1).size(); i_chamber++){
                    if(muon_seg_chamberIndex->at(offline1).at(i_chamber) == 2 || muon_seg_chamberIndex->at(offline1).at(i_chamber) == 3){
                        //mu1_seg_theta = std::atan2(std::sqrt(muon_seg_x->at(offline1).at(i_chamber) * muon_seg_x->at(offline1).at(i_chamber) + muon_seg_y->at(offline1).at(i_chamber) * muon_seg_y->at(offline1).at(i_chamber)), muon_seg_z->at(offline1).at(i_chamber));
                        //mu1_seg_phi = std::atan2(muon_seg_y->at(offline1).at(i_chamber) , muon_seg_x->at(offline1).at(i_chamber));
                        //mu1_seg_eta = -1*log(tan(mu1_seg_theta / 2));
                        mu1_seg_x = muon_seg_x->at(offline1).at(i_chamber);
                        mu1_seg_y = muon_seg_y->at(offline1).at(i_chamber);
                        mu1_seg_z = muon_seg_z->at(offline1).at(i_chamber);
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
                        mu2_seg_x = muon_seg_x->at(offline2).at(j_chamber);
                        mu2_seg_y = muon_seg_y->at(offline2).at(j_chamber);
                        mu2_seg_z = muon_seg_z->at(offline2).at(j_chamber);

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

                
                //TLorentzVector ext_mu1;
                //ext_mu1.SetPtEtaPhiE(muon_pt->at(offline1), mu1_seg_eta, mu1_seg_phi, muon_e->at(offline1));
                //TLorentzVector ext_mu2;
                //ext_mu2.SetPtEtaPhiE(muon_pt->at(offline2), mu2_seg_eta, mu2_seg_phi, muon_e->at(offline2));

                TVector3 ext_mu1(mu1_seg_x, mu1_seg_y, mu1_seg_z);
                TVector3 ext_mu2(mu2_seg_x, mu2_seg_y, mu2_seg_z);

                TLorentzVector offline_pair = muon1 + muon2;
                float pair_mass = offline_pair.M();
                float pair_deltaR = muon2.DeltaR(muon1);
                float pair_deltaPhi = muon2.DeltaPhi(muon1);

                //TLorentzVector ext_mu_pair = ext_mu1 + ext_mu2;
                //float pair_ext_mass = ext_mu_pair.M();
                float pair_ext_mass = 0;
                float pair_ext_deltaR = ext_mu2.DeltaR(ext_mu1);
                float pair_ext_deltaPhi = ext_mu2.DeltaPhi(ext_mu1);

                //j/psi mass cut
                bool flag_pair_mass = false;
                if(pair_mass > 2.7 && 3.5 > pair_mass){
                    flag_pair_mass = true;
                }

                int charge = muon_charge->at(offline1) * muon_charge->at(offline2);

                // charge
                bool flag_charge = charge == -1;

                if(flag_charge == false) continue;

                if(flag1_mu10_barrel == true && flag2_mu10_barrel == true){
                    pair_mass_l2mt_hist->Fill(pair_mass);
                    pair_deltaR_l2mt_hist->Fill(pair_deltaR);
                    pair_deltaPhi_l2mt_hist->Fill(pair_deltaPhi);
                    pair_pt_l2mt_hist->Fill(muon1.Pt());
                    pair_pt_l2mt_hist->Fill(muon2.Pt());

                    pair_ext_mass_l2mt_hist->Fill(pair_ext_mass);
                    pair_ext_deltaR_l2mt_hist->Fill(pair_ext_deltaR);
                    pair_ext_deltaPhi_l2mt_hist->Fill(pair_ext_deltaPhi);

                    pair_mass_dimuon_hist->Fill(pair_mass);
                    pair_deltaR_dimuon_hist->Fill(pair_deltaR);
                    pair_deltaPhi_dimuon_hist->Fill(pair_deltaPhi);
                    pair_pt_dimuon_hist->Fill(muon1.Pt());
                    pair_pt_dimuon_hist->Fill(muon2.Pt());

                    pair_ext_mass_dimuon_hist->Fill(pair_ext_mass);
                    pair_ext_deltaR_dimuon_hist->Fill(pair_ext_deltaR);
                    pair_ext_deltaPhi_dimuon_hist->Fill(pair_ext_deltaPhi);

                    if(pass_HLT_2mu10_l2mt_L1MU10BOM == 1){
                        cut_pair_mass_l2mt_hist->Fill(pair_mass);
                        cut_pair_deltaR_l2mt_hist->Fill(pair_deltaR);
                        cut_pair_deltaPhi_l2mt_hist->Fill(pair_deltaPhi);
                        cut_pair_pt_l2mt_hist->Fill(muon1.Pt());
                        cut_pair_pt_l2mt_hist->Fill(muon2.Pt());

                        cut_pair_ext_mass_l2mt_hist->Fill(pair_ext_mass);
                        cut_pair_ext_deltaR_l2mt_hist->Fill(pair_ext_deltaR);
                        cut_pair_ext_deltaPhi_l2mt_hist->Fill(pair_ext_deltaPhi);

                        cut_pair_mass_dimuon_hist->Fill(pair_mass);
                        cut_pair_deltaR_dimuon_hist->Fill(pair_deltaR);
                        cut_pair_deltaPhi_dimuon_hist->Fill(pair_deltaPhi);
                        cut_pair_pt_dimuon_hist->Fill(muon1.Pt());
                        cut_pair_pt_dimuon_hist->Fill(muon2.Pt());

                        cut_pair_ext_mass_dimuon_hist->Fill(pair_ext_mass);
                        cut_pair_ext_deltaR_dimuon_hist->Fill(pair_ext_deltaR);
                        cut_pair_ext_deltaPhi_dimuon_hist->Fill(pair_ext_deltaPhi);
                    }
                    
                    // J/psi cut
                    if(flag_pair_mass == true){
                        pair_mass_Jpsi_l2mt_hist->Fill(pair_mass);
                        pair_deltaR_Jpsi_l2mt_hist->Fill(pair_deltaR);
                        pair_deltaPhi_Jpsi_l2mt_hist->Fill(pair_deltaPhi);
                        pair_pt_Jpsi_l2mt_hist->Fill(muon1.Pt());
                        pair_pt_Jpsi_l2mt_hist->Fill(muon2.Pt());

                        pair_ext_mass_Jpsi_l2mt_hist->Fill(pair_ext_mass);
                        pair_ext_deltaR_Jpsi_l2mt_hist->Fill(pair_ext_deltaR);
                        pair_ext_deltaPhi_Jpsi_l2mt_hist->Fill(pair_ext_deltaPhi);

                        pair_mass_Jpsi_dimuon_hist->Fill(pair_mass);
                        pair_deltaR_Jpsi_dimuon_hist->Fill(pair_deltaR);
                        pair_deltaPhi_Jpsi_dimuon_hist->Fill(pair_deltaPhi);
                        pair_pt_Jpsi_dimuon_hist->Fill(muon1.Pt());
                        pair_pt_Jpsi_dimuon_hist->Fill(muon2.Pt());

                        pair_ext_mass_Jpsi_dimuon_hist->Fill(pair_ext_mass);
                        pair_ext_deltaR_Jpsi_dimuon_hist->Fill(pair_ext_deltaR);
                        pair_ext_deltaPhi_Jpsi_dimuon_hist->Fill(pair_ext_deltaPhi);

                        if(pass_HLT_2mu10_l2mt_L1MU10BOM == 1){
                            cut_pair_mass_Jpsi_l2mt_hist->Fill(pair_mass);
                            cut_pair_deltaR_Jpsi_l2mt_hist->Fill(pair_deltaR);
                            cut_pair_deltaPhi_Jpsi_l2mt_hist->Fill(pair_deltaPhi);
                            cut_pair_pt_Jpsi_l2mt_hist->Fill(muon1.Pt());
                            cut_pair_pt_Jpsi_l2mt_hist->Fill(muon2.Pt());

                            cut_pair_ext_mass_Jpsi_l2mt_hist->Fill(pair_ext_mass);
                            cut_pair_ext_deltaR_Jpsi_l2mt_hist->Fill(pair_ext_deltaR);
                            cut_pair_ext_deltaPhi_Jpsi_l2mt_hist->Fill(pair_ext_deltaPhi);

                            cut_pair_mass_Jpsi_dimuon_hist->Fill(pair_mass);
                            cut_pair_deltaR_Jpsi_dimuon_hist->Fill(pair_deltaR);
                            cut_pair_deltaPhi_Jpsi_dimuon_hist->Fill(pair_deltaPhi);
                            cut_pair_pt_Jpsi_dimuon_hist->Fill(muon1.Pt());
                            cut_pair_pt_Jpsi_dimuon_hist->Fill(muon2.Pt());

                            cut_pair_ext_mass_Jpsi_dimuon_hist->Fill(pair_ext_mass);
                            cut_pair_ext_deltaR_Jpsi_dimuon_hist->Fill(pair_ext_deltaR);
                            cut_pair_ext_deltaPhi_Jpsi_dimuon_hist->Fill(pair_ext_deltaPhi);
                        }
                    }
                }

                if(flag1_mu14_barrel == true && flag2_mu14_barrel == true){
                    pair_mass_2mu14_hist->Fill(pair_mass);
                    pair_deltaR_2mu14_hist->Fill(pair_deltaR);
                    pair_deltaPhi_2mu14_hist->Fill(pair_deltaPhi);
                    pair_pt_2mu14_hist->Fill(muon1.Pt());
                    pair_pt_2mu14_hist->Fill(muon2.Pt());

                    pair_ext_mass_2mu14_hist->Fill(pair_ext_mass);
                    pair_ext_deltaR_2mu14_hist->Fill(pair_ext_deltaR);
                    pair_ext_deltaPhi_2mu14_hist->Fill(pair_ext_deltaPhi);

                    pair_mass_dimuon_hist->Fill(pair_mass);
                    pair_deltaR_dimuon_hist->Fill(pair_deltaR);
                    pair_deltaPhi_dimuon_hist->Fill(pair_deltaPhi);
                    pair_pt_dimuon_hist->Fill(muon1.Pt());
                    pair_pt_dimuon_hist->Fill(muon2.Pt());

                    pair_ext_mass_dimuon_hist->Fill(pair_ext_mass);
                    pair_ext_deltaR_dimuon_hist->Fill(pair_ext_deltaR);
                    pair_ext_deltaPhi_dimuon_hist->Fill(pair_ext_deltaPhi);

                    if(pass_HLT_2mu14_L12MU8F == 1){
                        cut_pair_mass_2mu14_hist->Fill(pair_mass);
                        cut_pair_deltaR_2mu14_hist->Fill(pair_deltaR);
                        cut_pair_deltaPhi_2mu14_hist->Fill(pair_deltaPhi);
                        cut_pair_pt_2mu14_hist->Fill(muon1.Pt());
                        cut_pair_pt_2mu14_hist->Fill(muon2.Pt());

                        cut_pair_ext_mass_2mu14_hist->Fill(pair_ext_mass);
                        cut_pair_ext_deltaR_2mu14_hist->Fill(pair_ext_deltaR);
                        cut_pair_ext_deltaPhi_2mu14_hist->Fill(pair_ext_deltaPhi);

                        cut_pair_mass_dimuon_hist->Fill(pair_mass);
                        cut_pair_deltaR_dimuon_hist->Fill(pair_deltaR);
                        cut_pair_deltaPhi_dimuon_hist->Fill(pair_deltaPhi);
                        cut_pair_pt_dimuon_hist->Fill(muon1.Pt());
                        cut_pair_pt_dimuon_hist->Fill(muon2.Pt());

                        cut_pair_ext_mass_dimuon_hist->Fill(pair_ext_mass);
                        cut_pair_ext_deltaR_dimuon_hist->Fill(pair_ext_deltaR);
                        cut_pair_ext_deltaPhi_dimuon_hist->Fill(pair_ext_deltaPhi);
                    }
                    
                    if(flag_pair_mass == true){
                        pair_mass_Jpsi_2mu14_hist->Fill(pair_mass);
                        pair_deltaR_Jpsi_2mu14_hist->Fill(pair_deltaR);
                        pair_deltaPhi_Jpsi_2mu14_hist->Fill(pair_deltaPhi);
                        pair_pt_Jpsi_2mu14_hist->Fill(muon1.Pt());
                        pair_pt_Jpsi_2mu14_hist->Fill(muon2.Pt());

                        pair_ext_mass_Jpsi_2mu14_hist->Fill(pair_ext_mass);
                        pair_ext_deltaR_Jpsi_2mu14_hist->Fill(pair_ext_deltaR);
                        pair_ext_deltaPhi_Jpsi_2mu14_hist->Fill(pair_ext_deltaPhi);

                        pair_mass_Jpsi_dimuon_hist->Fill(pair_mass);
                        pair_deltaR_Jpsi_dimuon_hist->Fill(pair_deltaR);
                        pair_deltaPhi_Jpsi_dimuon_hist->Fill(pair_deltaPhi);
                        pair_pt_Jpsi_dimuon_hist->Fill(muon1.Pt());
                        pair_pt_Jpsi_dimuon_hist->Fill(muon2.Pt());

                        pair_ext_mass_Jpsi_dimuon_hist->Fill(pair_ext_mass);
                        pair_ext_deltaR_Jpsi_dimuon_hist->Fill(pair_ext_deltaR);
                        pair_ext_deltaPhi_Jpsi_dimuon_hist->Fill(pair_ext_deltaPhi);

                        if(pass_HLT_2mu14_L12MU8F == 1){
                            cut_pair_mass_Jpsi_2mu14_hist->Fill(pair_mass);
                            cut_pair_deltaR_Jpsi_2mu14_hist->Fill(pair_deltaR);
                            cut_pair_deltaPhi_Jpsi_2mu14_hist->Fill(pair_deltaPhi);
                            cut_pair_pt_Jpsi_2mu14_hist->Fill(muon1.Pt());
                            cut_pair_pt_Jpsi_2mu14_hist->Fill(muon2.Pt());

                            cut_pair_ext_mass_Jpsi_2mu14_hist->Fill(pair_ext_mass);
                            cut_pair_ext_deltaR_Jpsi_2mu14_hist->Fill(pair_ext_deltaR);
                            cut_pair_ext_deltaPhi_Jpsi_2mu14_hist->Fill(pair_ext_deltaPhi);

                            cut_pair_mass_Jpsi_dimuon_hist->Fill(pair_mass);
                            cut_pair_deltaR_Jpsi_dimuon_hist->Fill(pair_deltaR);
                            cut_pair_deltaPhi_Jpsi_dimuon_hist->Fill(pair_deltaPhi);
                            cut_pair_pt_Jpsi_dimuon_hist->Fill(muon1.Pt());
                            cut_pair_pt_Jpsi_dimuon_hist->Fill(muon2.Pt());

                            cut_pair_ext_mass_Jpsi_dimuon_hist->Fill(pair_ext_mass);
                            cut_pair_ext_deltaR_Jpsi_dimuon_hist->Fill(pair_ext_deltaR);
                            cut_pair_ext_deltaPhi_Jpsi_dimuon_hist->Fill(pair_ext_deltaPhi);
                        }
                    }
                }
            }
        }
    }

    hist_file.cd();

    dimuon_mass_hist->Write();
    dimuon_deltaR_hist->Write();
    dimuon_deltaPhi_hist->Write();

    pair_mass_l2mt_hist->Write();
    pair_deltaR_l2mt_hist->Write();
    pair_deltaPhi_l2mt_hist->Write();
    pair_ext_mass_l2mt_hist->Write();
    pair_ext_deltaR_l2mt_hist->Write();
    pair_ext_deltaPhi_l2mt_hist->Write();
    pair_pt_l2mt_hist->Write();
    cut_pair_mass_l2mt_hist->Write();
    cut_pair_deltaR_l2mt_hist->Write();
    cut_pair_deltaPhi_l2mt_hist->Write();
    cut_pair_ext_mass_l2mt_hist->Write();
    cut_pair_ext_deltaR_l2mt_hist->Write();
    cut_pair_ext_deltaPhi_l2mt_hist->Write();
    cut_pair_pt_l2mt_hist->Write();
    pair_mass_Jpsi_l2mt_hist->Write();
    pair_deltaR_Jpsi_l2mt_hist->Write();
    pair_deltaPhi_Jpsi_l2mt_hist->Write();
    pair_ext_mass_Jpsi_l2mt_hist->Write();
    pair_ext_deltaR_Jpsi_l2mt_hist->Write();
    pair_ext_deltaPhi_Jpsi_l2mt_hist->Write();
    pair_pt_Jpsi_l2mt_hist->Write();
    cut_pair_mass_Jpsi_l2mt_hist->Write();
    cut_pair_deltaR_Jpsi_l2mt_hist->Write();
    cut_pair_deltaPhi_Jpsi_l2mt_hist->Write();
    cut_pair_ext_mass_Jpsi_l2mt_hist->Write();
    cut_pair_ext_deltaR_Jpsi_l2mt_hist->Write();
    cut_pair_ext_deltaPhi_Jpsi_l2mt_hist->Write();
    cut_pair_pt_Jpsi_l2mt_hist->Write();

    pair_mass_2mu14_hist->Write();
    pair_deltaR_2mu14_hist->Write();
    pair_deltaPhi_2mu14_hist->Write();
    pair_ext_mass_2mu14_hist->Write();
    pair_ext_deltaR_2mu14_hist->Write();
    pair_ext_deltaPhi_2mu14_hist->Write();
    pair_pt_2mu14_hist->Write();
    cut_pair_mass_2mu14_hist->Write();
    cut_pair_deltaR_2mu14_hist->Write();
    cut_pair_deltaPhi_2mu14_hist->Write();
    cut_pair_ext_mass_2mu14_hist->Write();
    cut_pair_ext_deltaR_2mu14_hist->Write();
    cut_pair_ext_deltaPhi_2mu14_hist->Write();
    cut_pair_pt_2mu14_hist->Write();
    pair_mass_Jpsi_2mu14_hist->Write();
    pair_deltaR_Jpsi_2mu14_hist->Write();
    pair_deltaPhi_Jpsi_2mu14_hist->Write();
    pair_ext_mass_Jpsi_2mu14_hist->Write();
    pair_ext_deltaR_Jpsi_2mu14_hist->Write();
    pair_ext_deltaPhi_Jpsi_2mu14_hist->Write();
    pair_pt_Jpsi_2mu14_hist->Write();
    cut_pair_mass_Jpsi_2mu14_hist->Write();
    cut_pair_deltaR_Jpsi_2mu14_hist->Write();
    cut_pair_deltaPhi_Jpsi_2mu14_hist->Write();
    cut_pair_ext_mass_Jpsi_2mu14_hist->Write();
    cut_pair_ext_deltaR_Jpsi_2mu14_hist->Write();
    cut_pair_ext_deltaPhi_Jpsi_2mu14_hist->Write();
    cut_pair_pt_Jpsi_2mu14_hist->Write();

    pair_mass_dimuon_hist->Write();
    pair_deltaR_dimuon_hist->Write();
    pair_deltaPhi_dimuon_hist->Write();
    pair_ext_mass_dimuon_hist->Write();
    pair_ext_deltaR_dimuon_hist->Write();
    pair_ext_deltaPhi_dimuon_hist->Write();
    pair_pt_dimuon_hist->Write();
    cut_pair_mass_dimuon_hist->Write();
    cut_pair_deltaR_dimuon_hist->Write();
    cut_pair_deltaPhi_dimuon_hist->Write();
    cut_pair_ext_mass_dimuon_hist->Write();
    cut_pair_ext_deltaR_dimuon_hist->Write();
    cut_pair_ext_deltaPhi_dimuon_hist->Write();
    cut_pair_pt_dimuon_hist->Write();
    pair_mass_Jpsi_dimuon_hist->Write();
    pair_deltaR_Jpsi_dimuon_hist->Write();
    pair_deltaPhi_Jpsi_dimuon_hist->Write();
    pair_ext_mass_Jpsi_dimuon_hist->Write();
    pair_ext_deltaR_Jpsi_dimuon_hist->Write();
    pair_ext_deltaPhi_Jpsi_dimuon_hist->Write();
    pair_pt_Jpsi_dimuon_hist->Write();
    cut_pair_mass_Jpsi_dimuon_hist->Write();
    cut_pair_deltaR_Jpsi_dimuon_hist->Write();
    cut_pair_deltaPhi_Jpsi_dimuon_hist->Write();
    cut_pair_ext_mass_Jpsi_dimuon_hist->Write();
    cut_pair_ext_deltaR_Jpsi_dimuon_hist->Write();
    cut_pair_ext_deltaPhi_Jpsi_dimuon_hist->Write();
    cut_pair_pt_Jpsi_dimuon_hist->Write();
    
    hist_file.Close();
}