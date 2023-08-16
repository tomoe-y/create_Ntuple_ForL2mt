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

void L2mt_analysis(){
    TChain* chain = new TChain("analysis");
    //login.icepp
    //chain->Add("/home/toyamash/L2MuonSA/create_Ntuple_ForL2mt/run/MyxAODAnalysis_forl2mt.output.root");
    //chain->Add("/gpfs/fs8001/toyamash/L2mt/user.toyamash.data23_13p6TeV.00454188.physics_Main.merge.AOD.f1360_m2179.Run3-22.0.105-00-01_NTUP_ANALYSIS.500635190/user.toyamash.34265966.ANALYSIS._000007.root");
    //chain->Add("/gpfs/fs8001/toyamash/L2mt/user.toyamash.data23_13p6TeV.00454188.physics_Main.merge.AOD.f1360_m2179.Run3-22.0.105-00-01_NTUP_ANALYSIS.500635190/*.root");
    //lxplus
    //chain->Add("/eos/user/t/toyamash/user.toyamash.data23_13p6TeV.00454188.physics_Main.merge.AOD.f1360_m2179.Run3-22.0.105-00-01_NTUP_ANALYSIS.500635190/*.root");
    chain->Add("/eos/user/t/toyamash/L2mt/user.toyamash.data23_13p6TeV.00453858.physics_Main.merge.AOD.f1360_m2179.Run3-22.0.107-00-01.2_NTUP_ANALYSIS/*.root");
    //chain->Add("/eos/user/t/toyamash/user.toyamash.data23_13p6TeV.00454188.physics_Main.merge.AOD.f1360_m2179.Run3-22.0.105-00-01_NTUP_ANALYSIS.500635190/user.toyamash.34265966.ANALYSIS._000007.root");

    chain->SetBranchStatus("*", 0);

    // Declaration of leaf types
    UInt_t          RunNumber;
    UInt_t          LumiBlock;
    ULong64_t       EventNumber;
    Float_t         mcEventWeight;
    Float_t         actualInteractionsPerCrossing;
    Float_t         averageInteractionsPerCrossing;
    vector<float>   *muon_e;
    vector<float>   *muon_pt;
    vector<float>   *muon_eta;
    vector<float>   *muon_phi;
    vector<float>   *muon_charge;
    vector<int>     *muon_quality;
    vector<bool>    *muon_isBadMuon_other;
    vector<int>     *muon_truthType;
    vector<int>     *muon_truthTypeMCTC;
    vector<int>     *muon_truthOriginMCTC;
    vector<int>     *muon_IFFtruthType;
    vector<int>     *muon_muonType;
    vector<int>     *muon_author;
    vector<float>   *truthmuon_e;
    vector<float>   *truthmuon_pt;
    vector<float>   *truthmuon_eta;
    vector<float>   *truthmuon_phi;
    vector<int>     *truthmuon_pdgId;
    vector<float>   *muon_mePt;
    vector<float>   *muon_idPt;
    vector<float>   *muon_cbPt;
    vector<float>   *muon_meP;
    vector<float>   *muon_idP;
    vector<float>   *muon_etaMS;
    vector<float>   *muon_phiMS;
    vector<int>     *muon_innerSmallHits;
    vector<int>     *muon_innerLargeHits;
    vector<int>     *muon_middleSmallHits;
    vector<int>     *muon_middleLargeHits;
    vector<int>     *muon_outerSmallHits;
    vector<int>     *muon_outerLargeHits;
    vector<int>     *muon_extendedSmallHits;
    vector<int>     *muon_extendedLargeHits;
    vector<unsigned char> *muon_phiLayer1STGCHits;
    vector<unsigned char> *muon_phiLayer2STGCHits;
    vector<unsigned char> *muon_etaLayer1STGCHits;
    vector<unsigned char> *muon_etaLayer2STGCHits;
    vector<unsigned char> *muon_phiLayer1STGCHoles;
    vector<unsigned char> *muon_phiLayer2STGCHoles;
    vector<unsigned char> *muon_etaLayer1STGCHoles;
    vector<unsigned char> *muon_etaLayer2STGCHoles;
    vector<unsigned char> *muon_MMHits;
    vector<unsigned char> *muon_MMHoles;
    vector<unsigned long> *muon_nSegments;
    vector<vector<float> > *muon_seg_chiSquared;
    vector<vector<float> > *muon_seg_numberDoF;
    vector<vector<int> > *muon_seg_sector;
    vector<vector<int> > *muon_seg_chamberIndex;
    vector<vector<int> > *muon_seg_nPrecisionHits;
    vector<vector<int> > *muon_seg_nPhiLayers;
    vector<vector<int> > *muon_seg_nTrigEtaLayers;
    vector<vector<float> > *muon_seg_x;
    vector<vector<float> > *muon_seg_y;
    vector<vector<float> > *muon_seg_z;
    vector<vector<float> > *muon_seg_px;
    vector<vector<float> > *muon_seg_py;
    vector<vector<float> > *muon_seg_pz;
    std::unique_ptr<std::vector<float>> trig_L1_mu_eta;
    std::unique_ptr<std::vector<float>> trig_L1_mu_phi;
    std::unique_ptr<std::vector<short>> trig_L1_mu_thrNumber;
    std::unique_ptr<std::vector<short>> trig_L1_mu_RoINumber;
    std::unique_ptr<std::vector<short>> trig_L1_mu_sectorAddress;
    std::unique_ptr<std::vector<short>> trig_L1_mu_source;
    std::unique_ptr<std::vector<short>> trig_L1_mu_hemisphere;
    std::unique_ptr<std::vector<short>> trig_L1_mu_firstCandidate;
    std::unique_ptr<std::vector<short>> trig_L1_mu_moreCandInRPCPad;
    std::unique_ptr<std::vector<short>> trig_L1_mu_moreCandInSector;
    std::unique_ptr<std::vector<short>> trig_L1_mu_charge;
    vector<float>   *l1_eta;
    vector<float>   *l1_phi;
    //vector<float>   *l1_dRoff;
    vector<int>   *l1_BOM;
    vector<float>   *l2mt_e;
    vector<float>   *l2mt_pt;
    vector<float>   *l2mt_eta;
    vector<float>   *l2mt_phi;
    vector<float>   *l2mt_etaMS;
    vector<float>   *l2mt_phiMS;
    vector<bool>    *l2mt_pass;
    vector<vector<float> > *l2mt_superPointR;
    vector<vector<float> > *l2mt_superPointZ;
    vector<vector<float> > *l2mt_superPointSlope;
    vector<vector<float> > *l2mt_superPointIntercept;
    vector<vector<float> > *l2mt_superPointChi2;
    vector<vector<unsigned int> > *l2mt_stgcClusterLayer;
    vector<vector<int> > *l2mt_stgcClusterIsOutlier;
    vector<vector<int> > *l2mt_stgcClusterType;
    vector<vector<float> > *l2mt_stgcClusterEta;
    vector<vector<float> > *l2mt_stgcClusterPhi;
    vector<vector<float> > *l2mt_stgcClusterR;
    vector<vector<float> > *l2mt_stgcClusterZ;
    vector<vector<float> > *l2mt_stgcClusterResidualR;
    vector<vector<float> > *l2mt_stgcClusterResidualPhi;
    vector<vector<int> > *l2mt_stgcClusterStationEta;
    vector<vector<int> > *l2mt_stgcClusterStationPhi;
    vector<vector<int> > *l2mt_stgcClusterStationName;
    vector<vector<unsigned int> > *l2mt_mmClusterLayer;
    vector<vector<int> > *l2mt_mmClusterIsOutlier;
    vector<vector<float> > *l2mt_mmClusterEta;
    vector<vector<float> > *l2mt_mmClusterPhi;
    vector<vector<float> > *l2mt_mmClusterR;
    vector<vector<float> > *l2mt_mmClusterZ;
    vector<vector<float> > *l2mt_mmClusterResidualR;
    vector<vector<float> > *l2mt_mmClusterResidualPhi;
    vector<vector<int> > *l2mt_mmClusterStationEta;
    vector<vector<int> > *l2mt_mmClusterStationPhi;
    vector<vector<int> > *l2mt_mmClusterStationName;
    vector<float>   *l2cb_e;
    vector<float>   *l2cb_pt;
    vector<float>   *l2cb_eta;
    vector<float>   *l2cb_phi;
    vector<bool>    *l2cb_pass;
    vector<string>         *trigger_info_chain;
    vector<vector<int> >   *trigger_info_typeVec;
    vector<vector<float> > *trigger_info_ptVec;
    vector<vector<float> > *trigger_info_etaVec;
    vector<vector<float> > *trigger_info_phiVec;

    vector<vector<float> > *l2mt_ptEndcapAlpha;
    vector<vector<float> > *l2mt_ptEndcapBeta;

    // List of branches
    TBranch        *b_RunNumber;   //!
    TBranch        *b_LumiBlock;   //!
    TBranch        *b_EventNumber;   //!
    TBranch        *b_mcEventWeight;   //!
    TBranch        *b_actualInteractionsPerCrossing;   //!
    TBranch        *b_averageInteractionsPerCrossing;   //!
    TBranch        *b_muon_e;   //!
    TBranch        *b_muon_pt;   //!
    TBranch        *b_muon_eta;   //!
    TBranch        *b_muon_phi;   //!
    TBranch        *b_muon_charge;   //!
    TBranch        *b_muon_quality;   //!
    TBranch        *b_muon_isBadMuon_other;   //!
    TBranch        *b_muon_truthType;   //!
    TBranch        *b_muon_truthTypeMCTC;   //!
    TBranch        *b_muon_truthOriginMCTC;   //!
    TBranch        *b_muon_IFFtruthType;   //!
    TBranch        *b_muon_muonType;   //!
    TBranch        *b_muon_author;   //!
    TBranch        *b_truthmuon_e;   //!
    TBranch        *b_truthmuon_pt;   //!
    TBranch        *b_truthmuon_eta;   //!
    TBranch        *b_truthmuon_phi;   //!
    TBranch        *b_truthmuon_pdgId;   //!
    TBranch        *b_muon_mePt;   //!
    TBranch        *b_muon_idPt;   //!
    TBranch        *b_muon_cbPt;   //!
    TBranch        *b_muon_meP;   //!
    TBranch        *b_muon_idP;   //!
    TBranch        *b_muon_etaMS;   //!
    TBranch        *b_muon_phiMS;   //!
    TBranch        *b_muon_innerSmallHits;   //!
    TBranch        *b_muon_innerLargeHits;   //!
    TBranch        *b_muon_middleSmallHits;   //!
    TBranch        *b_muon_middleLargeHits;   //!
    TBranch        *b_muon_outerSmallHits;   //!
    TBranch        *b_muon_outerLargeHits;   //!
    TBranch        *b_muon_extendedSmallHits;   //!
    TBranch        *b_muon_extendedLargeHits;   //!
    TBranch        *b_muon_phiLayer1STGCHits;   //!
    TBranch        *b_muon_phiLayer2STGCHits;   //!
    TBranch        *b_muon_etaLayer1STGCHits;   //!
    TBranch        *b_muon_etaLayer2STGCHits;   //!
    TBranch        *b_muon_phiLayer1STGCHoles;   //!
    TBranch        *b_muon_phiLayer2STGCHoles;   //!
    TBranch        *b_muon_etaLayer1STGCHoles;   //!
    TBranch        *b_muon_etaLayer2STGCHoles;   //!
    TBranch        *b_muon_MMHits;   //!
    TBranch        *b_muon_MMHoles;   //!
    TBranch        *b_muon_nSegments;   //!
    TBranch        *b_muon_seg_chiSquared;   //!
    TBranch        *b_muon_seg_numberDoF;   //!
    TBranch        *b_muon_seg_sector;   //!
    TBranch        *b_muon_seg_chamberIndex;   //!
    TBranch        *b_muon_seg_nPrecisionHits;   //!
    TBranch        *b_muon_seg_nPhiLayers;   //!
    TBranch        *b_muon_seg_nTrigEtaLayers;   //!
    TBranch        *b_muon_seg_x;   //!
    TBranch        *b_muon_seg_y;   //!
    TBranch        *b_muon_seg_z;   //!
    TBranch        *b_muon_seg_px;   //!
    TBranch        *b_muon_seg_py;   //!
    TBranch        *b_muon_seg_pz;   //!
    TBranch        *b_trig_L1_mu_eta;   //!
    TBranch        *b_trig_L1_mu_phi;   //!
    TBranch        *b_trig_L1_mu_thrNumber;   //!
    TBranch        *b_trig_L1_mu_RoINumber;   //!
    TBranch        *b_trig_L1_mu_sectorAddress;   //!
    TBranch        *b_trig_L1_mu_source;   //!
    TBranch        *b_trig_L1_mu_hemisphere;   //!
    TBranch        *b_trig_L1_mu_firstCandidate;   //!
    TBranch        *b_trig_L1_mu_moreCandInRPCPad;   //!
    TBranch        *b_trig_L1_mu_moreCandInSector;   //!
    TBranch        *b_trig_L1_mu_charge;   //!
    TBranch        *b_l1_eta;   //!
    TBranch        *b_l1_phi;   //!
    //TBranch        *b_l1_dRoff;   //!
    TBranch        *b_l1_BOM;   //!
    TBranch        *b_l2mt_e;   //!
    TBranch        *b_l2mt_pt;   //!
    TBranch        *b_l2mt_eta;   //!
    TBranch        *b_l2mt_phi;   //!
    TBranch        *b_l2mt_etaMS;   //!
    TBranch        *b_l2mt_phiMS;   //!
    TBranch        *b_l2mt_pass;   //!
    TBranch        *b_l2mt_superPointR;   //!
    TBranch        *b_l2mt_superPointZ;   //!
    TBranch        *b_l2mt_superPointSlope;   //!
    TBranch        *b_l2mt_superPointIntercept;   //!
    TBranch        *b_l2mt_superPointChi2;   //!
    TBranch        *b_l2mt_stgcClusterLayer;   //!
    TBranch        *b_l2mt_stgcClusterIsOutlier;   //!
    TBranch        *b_l2mt_stgcClusterType;   //!
    TBranch        *b_l2mt_stgcClusterEta;   //!
    TBranch        *b_l2mt_stgcClusterPhi;   //!
    TBranch        *b_l2mt_stgcClusterR;   //!
    TBranch        *b_l2mt_stgcClusterZ;   //!
    TBranch        *b_l2mt_stgcClusterResidualR;   //!
    TBranch        *b_l2mt_stgcClusterResidualPhi;   //!
    TBranch        *b_l2mt_stgcClusterStationEta;   //!
    TBranch        *b_l2mt_stgcClusterStationPhi;   //!
    TBranch        *b_l2mt_stgcClusterStationName;   //!
    TBranch        *b_l2mt_mmClusterLayer;   //!
    TBranch        *b_l2mt_mmClusterIsOutlier;   //!
    TBranch        *b_l2mt_mmClusterEta;   //!
    TBranch        *b_l2mt_mmClusterPhi;   //!
    TBranch        *b_l2mt_mmClusterR;   //!
    TBranch        *b_l2mt_mmClusterZ;   //!
    TBranch        *b_l2mt_mmClusterResidualR;   //!
    TBranch        *b_l2mt_mmClusterResidualPhi;   //!
    TBranch        *b_l2mt_mmClusterStationEta;   //!
    TBranch        *b_l2mt_mmClusterStationPhi;   //!
    TBranch        *b_l2mt_mmClusterStationName;   //!
    TBranch        *b_l2cb_e;   //!
    TBranch        *b_l2cb_pt;   //!
    TBranch        *b_l2cb_eta;   //!
    TBranch        *b_l2cb_phi;   //!
    TBranch        *b_l2cb_pass;   //!
    TBranch        *b_trigger_info_chain;   //!
    TBranch        *b_trigger_info_typeVec;   //!
    TBranch        *b_trigger_info_ptVec;   //!
    TBranch        *b_trigger_info_etaVec;   //!
    TBranch        *b_trigger_info_phiVec;   //!

    TBranch        *b_l2mt_ptEndcapAlpha;   //!
    TBranch        *b_l2mt_ptEndcapBeta;   //!

    // Set object pointer
    muon_e = 0;
    muon_pt = 0;
    muon_eta = 0;
    muon_phi = 0;
    muon_charge = 0;
    muon_quality = 0;
    muon_isBadMuon_other = 0;
    muon_truthType = 0;
    muon_truthTypeMCTC = 0;
    muon_truthOriginMCTC = 0;
    muon_IFFtruthType = 0;
    muon_muonType = 0;
    muon_author = 0;
    truthmuon_e = 0;
    truthmuon_pt = 0;
    truthmuon_eta = 0;
    truthmuon_phi = 0;
    truthmuon_pdgId = 0;
    muon_mePt = 0;
    muon_idPt = 0;
    muon_cbPt = 0;
    muon_meP = 0;
    muon_idP = 0;
    muon_etaMS = 0;
    muon_phiMS = 0;
    muon_innerSmallHits = 0;
    muon_innerLargeHits = 0;
    muon_middleSmallHits = 0;
    muon_middleLargeHits = 0;
    muon_outerSmallHits = 0;
    muon_outerLargeHits = 0;
    muon_extendedSmallHits = 0;
    muon_extendedLargeHits = 0;
    muon_phiLayer1STGCHits = 0;
    muon_phiLayer2STGCHits = 0;
    muon_etaLayer1STGCHits = 0;
    muon_etaLayer2STGCHits = 0;
    muon_phiLayer1STGCHoles = 0;
    muon_phiLayer2STGCHoles = 0;
    muon_etaLayer1STGCHoles = 0;
    muon_etaLayer2STGCHoles = 0;
    muon_MMHits = 0;
    muon_MMHoles = 0;
    muon_nSegments = 0;
    muon_seg_chiSquared = 0;
    muon_seg_numberDoF = 0;
    muon_seg_sector = 0;
    muon_seg_chamberIndex = 0;
    muon_seg_nPrecisionHits = 0;
    muon_seg_nPhiLayers = 0;
    muon_seg_nTrigEtaLayers = 0;
    muon_seg_x = 0;
    muon_seg_y = 0;
    muon_seg_z = 0;
    muon_seg_px = 0;
    muon_seg_py = 0;
    muon_seg_pz = 0;
    trig_L1_mu_eta = 0;
    trig_L1_mu_phi = 0;
    trig_L1_mu_thrNumber = 0;
    trig_L1_mu_RoINumber = 0;
    trig_L1_mu_sectorAddress = 0;
    trig_L1_mu_source = 0;
    trig_L1_mu_hemisphere = 0;
    trig_L1_mu_firstCandidate = 0;
    trig_L1_mu_moreCandInRPCPad = 0;
    trig_L1_mu_moreCandInSector = 0;
    trig_L1_mu_charge = 0;
    l1_eta = 0;
    l1_phi = 0;
    //l1_dRoff = 0;
    l1_BOM = 0;
    l2mt_e = 0;
    l2mt_pt = 0;
    l2mt_eta = 0;
    l2mt_phi = 0;
    l2mt_etaMS = 0;
    l2mt_phiMS = 0;
    l2mt_pass = 0;
    l2mt_superPointR = 0;
    l2mt_superPointZ = 0;
    l2mt_superPointSlope = 0;
    l2mt_superPointIntercept = 0;
    l2mt_superPointChi2 = 0;
    l2mt_stgcClusterLayer = 0;
    l2mt_stgcClusterIsOutlier = 0;
    l2mt_stgcClusterType = 0;
    l2mt_stgcClusterEta = 0;
    l2mt_stgcClusterPhi = 0;
    l2mt_stgcClusterR = 0;
    l2mt_stgcClusterZ = 0;
    l2mt_stgcClusterResidualR = 0;
    l2mt_stgcClusterResidualPhi = 0;
    l2mt_stgcClusterStationEta = 0;
    l2mt_stgcClusterStationPhi = 0;
    l2mt_stgcClusterStationName = 0;
    l2mt_mmClusterLayer = 0;
    l2mt_mmClusterIsOutlier = 0;
    l2mt_mmClusterEta = 0;
    l2mt_mmClusterPhi = 0;
    l2mt_mmClusterR = 0;
    l2mt_mmClusterZ = 0;
    l2mt_mmClusterResidualR = 0;
    l2mt_mmClusterResidualPhi = 0;
    l2mt_mmClusterStationEta = 0;
    l2mt_mmClusterStationPhi = 0;
    l2mt_mmClusterStationName = 0;
    l2cb_e = 0;
    l2cb_pt = 0;
    l2cb_eta = 0;
    l2cb_phi = 0;
    l2cb_pass = 0;
    l2mt_ptEndcapAlpha = 0;
    l2mt_ptEndcapBeta = 0;
    trigger_info_chain = 0;
    trigger_info_typeVec = 0;
    trigger_info_ptVec = 0;
    trigger_info_etaVec = 0;
    trigger_info_phiVec = 0;


    chain->SetBranchAddress("RunNumber", &RunNumber, &b_RunNumber);
    chain->SetBranchAddress("LumiBlock", &LumiBlock, &b_LumiBlock);
    chain->SetBranchAddress("EventNumber", &EventNumber, &b_EventNumber);
    chain->SetBranchAddress("mcEventWeight", &mcEventWeight, &b_mcEventWeight);
    chain->SetBranchAddress("actualInteractionsPerCrossing", &actualInteractionsPerCrossing, &b_actualInteractionsPerCrossing);
    chain->SetBranchAddress("averageInteractionsPerCrossing", &averageInteractionsPerCrossing, &b_averageInteractionsPerCrossing);
    chain->SetBranchAddress("muon_e", &muon_e, &b_muon_e);
    chain->SetBranchAddress("muon_pt", &muon_pt, &b_muon_pt);
    chain->SetBranchAddress("muon_eta", &muon_eta, &b_muon_eta);
    chain->SetBranchAddress("muon_phi", &muon_phi, &b_muon_phi);
    chain->SetBranchAddress("muon_charge", &muon_charge, &b_muon_charge);
    chain->SetBranchAddress("muon_quality", &muon_quality, &b_muon_quality);
    chain->SetBranchAddress("muon_isBadMuon_other", &muon_isBadMuon_other, &b_muon_isBadMuon_other);
    chain->SetBranchAddress("muon_truthType", &muon_truthType, &b_muon_truthType);
    chain->SetBranchAddress("muon_truthTypeMCTC", &muon_truthTypeMCTC, &b_muon_truthTypeMCTC);
    chain->SetBranchAddress("muon_truthOriginMCTC", &muon_truthOriginMCTC, &b_muon_truthOriginMCTC);
    chain->SetBranchAddress("muon_IFFtruthType", &muon_IFFtruthType, &b_muon_IFFtruthType);
    chain->SetBranchAddress("muon_muonType", &muon_muonType, &b_muon_muonType);
    chain->SetBranchAddress("muon_author", &muon_author, &b_muon_author);
    chain->SetBranchAddress("truthmuon_e", &truthmuon_e, &b_truthmuon_e);
    chain->SetBranchAddress("truthmuon_pt", &truthmuon_pt, &b_truthmuon_pt);
    chain->SetBranchAddress("truthmuon_eta", &truthmuon_eta, &b_truthmuon_eta);
    chain->SetBranchAddress("truthmuon_phi", &truthmuon_phi, &b_truthmuon_phi);
    chain->SetBranchAddress("truthmuon_pdgId", &truthmuon_pdgId, &b_truthmuon_pdgId);
    chain->SetBranchAddress("muon_mePt", &muon_mePt, &b_muon_mePt);
    chain->SetBranchAddress("muon_idPt", &muon_idPt, &b_muon_idPt);
    chain->SetBranchAddress("muon_cbPt", &muon_cbPt, &b_muon_cbPt);
    chain->SetBranchAddress("muon_meP", &muon_meP, &b_muon_meP);
    chain->SetBranchAddress("muon_idP", &muon_idP, &b_muon_idP);
    chain->SetBranchAddress("muon_etaMS", &muon_etaMS, &b_muon_etaMS);
    chain->SetBranchAddress("muon_phiMS", &muon_phiMS, &b_muon_phiMS);
    chain->SetBranchAddress("muon_innerSmallHits", &muon_innerSmallHits, &b_muon_innerSmallHits);
    chain->SetBranchAddress("muon_innerLargeHits", &muon_innerLargeHits, &b_muon_innerLargeHits);
    chain->SetBranchAddress("muon_middleSmallHits", &muon_middleSmallHits, &b_muon_middleSmallHits);
    chain->SetBranchAddress("muon_middleLargeHits", &muon_middleLargeHits, &b_muon_middleLargeHits);
    chain->SetBranchAddress("muon_outerSmallHits", &muon_outerSmallHits, &b_muon_outerSmallHits);
    chain->SetBranchAddress("muon_outerLargeHits", &muon_outerLargeHits, &b_muon_outerLargeHits);
    chain->SetBranchAddress("muon_extendedSmallHits", &muon_extendedSmallHits, &b_muon_extendedSmallHits);
    chain->SetBranchAddress("muon_extendedLargeHits", &muon_extendedLargeHits, &b_muon_extendedLargeHits);
    chain->SetBranchAddress("muon_phiLayer1STGCHits", &muon_phiLayer1STGCHits, &b_muon_phiLayer1STGCHits);
    chain->SetBranchAddress("muon_phiLayer2STGCHits", &muon_phiLayer2STGCHits, &b_muon_phiLayer2STGCHits);
    chain->SetBranchAddress("muon_etaLayer1STGCHits", &muon_etaLayer1STGCHits, &b_muon_etaLayer1STGCHits);
    chain->SetBranchAddress("muon_etaLayer2STGCHits", &muon_etaLayer2STGCHits, &b_muon_etaLayer2STGCHits);
    chain->SetBranchAddress("muon_phiLayer1STGCHoles", &muon_phiLayer1STGCHoles, &b_muon_phiLayer1STGCHoles);
    chain->SetBranchAddress("muon_phiLayer2STGCHoles", &muon_phiLayer2STGCHoles, &b_muon_phiLayer2STGCHoles);
    chain->SetBranchAddress("muon_etaLayer1STGCHoles", &muon_etaLayer1STGCHoles, &b_muon_etaLayer1STGCHoles);
    chain->SetBranchAddress("muon_etaLayer2STGCHoles", &muon_etaLayer2STGCHoles, &b_muon_etaLayer2STGCHoles);
    chain->SetBranchAddress("muon_MMHits", &muon_MMHits, &b_muon_MMHits);
    chain->SetBranchAddress("muon_MMHoles", &muon_MMHoles, &b_muon_MMHoles);
    chain->SetBranchAddress("muon_nSegments", &muon_nSegments, &b_muon_nSegments);
    chain->SetBranchAddress("muon_seg_chiSquared", &muon_seg_chiSquared, &b_muon_seg_chiSquared);
    chain->SetBranchAddress("muon_seg_numberDoF", &muon_seg_numberDoF, &b_muon_seg_numberDoF);
    chain->SetBranchAddress("muon_seg_sector", &muon_seg_sector, &b_muon_seg_sector);
    chain->SetBranchAddress("muon_seg_chamberIndex", &muon_seg_chamberIndex, &b_muon_seg_chamberIndex);
    chain->SetBranchAddress("muon_seg_nPrecisionHits", &muon_seg_nPrecisionHits, &b_muon_seg_nPrecisionHits);
    chain->SetBranchAddress("muon_seg_nPhiLayers", &muon_seg_nPhiLayers, &b_muon_seg_nPhiLayers);
    chain->SetBranchAddress("muon_seg_nTrigEtaLayers", &muon_seg_nTrigEtaLayers, &b_muon_seg_nTrigEtaLayers);
    chain->SetBranchAddress("muon_seg_x", &muon_seg_x, &b_muon_seg_x);
    chain->SetBranchAddress("muon_seg_y", &muon_seg_y, &b_muon_seg_y);
    chain->SetBranchAddress("muon_seg_z", &muon_seg_z, &b_muon_seg_z);
    chain->SetBranchAddress("muon_seg_px", &muon_seg_px, &b_muon_seg_px);
    chain->SetBranchAddress("muon_seg_py", &muon_seg_py, &b_muon_seg_py);
    chain->SetBranchAddress("muon_seg_pz", &muon_seg_pz, &b_muon_seg_pz);
    chain->SetBranchAddress("trig_L1_mu_eta", &trig_L1_mu_eta, &b_trig_L1_mu_eta);
    chain->SetBranchAddress("trig_L1_mu_phi", &trig_L1_mu_phi, &b_trig_L1_mu_phi);
    chain->SetBranchAddress("trig_L1_mu_thrNumber", &trig_L1_mu_thrNumber, &b_trig_L1_mu_thrNumber);
    chain->SetBranchAddress("trig_L1_mu_RoINumber", &trig_L1_mu_RoINumber, &b_trig_L1_mu_RoINumber);
    chain->SetBranchAddress("trig_L1_mu_sectorAddress", &trig_L1_mu_sectorAddress, &b_trig_L1_mu_sectorAddress);
    chain->SetBranchAddress("trig_L1_mu_source", &trig_L1_mu_source, &b_trig_L1_mu_source);
    chain->SetBranchAddress("trig_L1_mu_hemisphere", &trig_L1_mu_hemisphere, &b_trig_L1_mu_hemisphere);
    chain->SetBranchAddress("trig_L1_mu_firstCandidate", &trig_L1_mu_firstCandidate, &b_trig_L1_mu_firstCandidate);
    chain->SetBranchAddress("trig_L1_mu_moreCandInRPCPad", &trig_L1_mu_moreCandInRPCPad, &b_trig_L1_mu_moreCandInRPCPad);
    chain->SetBranchAddress("trig_L1_mu_moreCandInSector", &trig_L1_mu_moreCandInSector, &b_trig_L1_mu_moreCandInSector);
    chain->SetBranchAddress("l1_eta", &l1_eta, &b_l1_eta);
    chain->SetBranchAddress("l1_phi", &l1_phi, &b_l1_phi);
    //chain->SetBranchAddress("l1_dRoff", &l1_dRoff, &b_l1_dRoff);
    chain->SetBranchAddress("l1_BOM", &l1_BOM, &b_l1_BOM);
    chain->SetBranchAddress("l2mt_e", &l2mt_e, &b_l2mt_e);
    chain->SetBranchAddress("l2mt_pt", &l2mt_pt, &b_l2mt_pt);
    chain->SetBranchAddress("l2mt_eta", &l2mt_eta, &b_l2mt_eta);
    chain->SetBranchAddress("l2mt_phi", &l2mt_phi, &b_l2mt_phi);
    chain->SetBranchAddress("l2mt_etaMS", &l2mt_etaMS, &b_l2mt_etaMS);
    chain->SetBranchAddress("l2mt_phiMS", &l2mt_phiMS, &b_l2mt_phiMS);
    chain->SetBranchAddress("l2mt_pass", &l2mt_pass, &b_l2mt_pass);
    chain->SetBranchAddress("l2mt_superPointR", &l2mt_superPointR, &b_l2mt_superPointR);
    chain->SetBranchAddress("l2mt_superPointZ", &l2mt_superPointZ, &b_l2mt_superPointZ);
    chain->SetBranchAddress("l2mt_superPointSlope", &l2mt_superPointSlope, &b_l2mt_superPointSlope);
    chain->SetBranchAddress("l2mt_superPointIntercept", &l2mt_superPointIntercept, &b_l2mt_superPointIntercept);
    chain->SetBranchAddress("l2mt_superPointChi2", &l2mt_superPointChi2, &b_l2mt_superPointChi2);
    chain->SetBranchAddress("l2mt_stgcClusterLayer", &l2mt_stgcClusterLayer, &b_l2mt_stgcClusterLayer);
    chain->SetBranchAddress("l2mt_stgcClusterIsOutlier", &l2mt_stgcClusterIsOutlier, &b_l2mt_stgcClusterIsOutlier);
    chain->SetBranchAddress("l2mt_stgcClusterType", &l2mt_stgcClusterType, &b_l2mt_stgcClusterType);
    chain->SetBranchAddress("l2mt_stgcClusterEta", &l2mt_stgcClusterEta, &b_l2mt_stgcClusterEta);
    chain->SetBranchAddress("l2mt_stgcClusterPhi", &l2mt_stgcClusterPhi, &b_l2mt_stgcClusterPhi);
    chain->SetBranchAddress("l2mt_stgcClusterR", &l2mt_stgcClusterR, &b_l2mt_stgcClusterR);
    chain->SetBranchAddress("l2mt_stgcClusterZ", &l2mt_stgcClusterZ, &b_l2mt_stgcClusterZ);
    chain->SetBranchAddress("l2mt_stgcClusterResidualR", &l2mt_stgcClusterResidualR, &b_l2mt_stgcClusterResidualR);
    chain->SetBranchAddress("l2mt_stgcClusterResidualPhi", &l2mt_stgcClusterResidualPhi, &b_l2mt_stgcClusterResidualPhi);
    chain->SetBranchAddress("l2mt_stgcClusterStationEta", &l2mt_stgcClusterStationEta, &b_l2mt_stgcClusterStationEta);
    chain->SetBranchAddress("l2mt_stgcClusterStationPhi", &l2mt_stgcClusterStationPhi, &b_l2mt_stgcClusterStationPhi);
    chain->SetBranchAddress("l2mt_stgcClusterStationName", &l2mt_stgcClusterStationName, &b_l2mt_stgcClusterStationName);
    chain->SetBranchAddress("l2mt_mmClusterLayer", &l2mt_mmClusterLayer, &b_l2mt_mmClusterLayer);
    chain->SetBranchAddress("l2mt_mmClusterIsOutlier", &l2mt_mmClusterIsOutlier, &b_l2mt_mmClusterIsOutlier);
    chain->SetBranchAddress("l2mt_mmClusterEta", &l2mt_mmClusterEta, &b_l2mt_mmClusterEta);
    chain->SetBranchAddress("l2mt_mmClusterPhi", &l2mt_mmClusterPhi, &b_l2mt_mmClusterPhi);
    chain->SetBranchAddress("l2mt_mmClusterR", &l2mt_mmClusterR, &b_l2mt_mmClusterR);
    chain->SetBranchAddress("l2mt_mmClusterZ", &l2mt_mmClusterZ, &b_l2mt_mmClusterZ);
    chain->SetBranchAddress("l2mt_mmClusterResidualR", &l2mt_mmClusterResidualR, &b_l2mt_mmClusterResidualR);
    chain->SetBranchAddress("l2mt_mmClusterResidualPhi", &l2mt_mmClusterResidualPhi, &b_l2mt_mmClusterResidualPhi);
    chain->SetBranchAddress("l2mt_mmClusterStationEta", &l2mt_mmClusterStationEta, &b_l2mt_mmClusterStationEta);
    chain->SetBranchAddress("l2mt_mmClusterStationPhi", &l2mt_mmClusterStationPhi, &b_l2mt_mmClusterStationPhi);
    chain->SetBranchAddress("l2mt_mmClusterStationName", &l2mt_mmClusterStationName, &b_l2mt_mmClusterStationName);
    chain->SetBranchAddress("l2cb_e", &l2cb_e, &b_l2cb_e);
    chain->SetBranchAddress("l2cb_pt", &l2cb_pt, &b_l2cb_pt);
    chain->SetBranchAddress("l2cb_eta", &l2cb_eta, &b_l2cb_eta);
    chain->SetBranchAddress("l2cb_phi", &l2cb_phi, &b_l2cb_phi);
    chain->SetBranchAddress("trigger_info_chain", &trigger_info_chain, &b_trigger_info_chain);
    chain->SetBranchAddress("trigger_info_typeVec", &trigger_info_typeVec, &b_trigger_info_typeVec);
    chain->SetBranchAddress("trigger_info_ptVec", &trigger_info_ptVec, &b_trigger_info_ptVec);
    chain->SetBranchAddress("trigger_info_etaVec", &trigger_info_etaVec, &b_trigger_info_etaVec);
    chain->SetBranchAddress("trigger_info_phiVec", &trigger_info_phiVec, &b_trigger_info_phiVec);

    //chain->SetBranchAddress("l2mt_ptEndcapAlpha", &l2mt_ptEndcapAlpha, &b_l2mt_ptEndcapAlpha);
    //chain->SetBranchAddress("l2mt_ptEndcapBeta", &l2mt_ptEndcapBeta, &b_l2mt_ptEndcapBeta);

    TH1D *mass_hist = new TH1D("mass_hist", "mass_hist", 1000, 0, 100);
    TH1D *deltaR_hist = new TH1D("deltaR_hist", "deltaR_hist", 100, 0, 5);
    TH1D *deltaPhi_hist = new TH1D("deltaPhi_hist", "deltaPhi_hist", 100, -3.5, 3.5);
    
    TH1D *HLTmuons_hist = new TH1D("HLTmuons_hist", "HLTmuons_hist", 5, 0, 5);
    TH1D *HLTmuons_withl2mtpass_hist = new TH1D("HLTmuons_withl2mtpass_hist", "HLTmuons_withl2mtpass_hist", 5, 0, 5);
    TH1D *l2mtpass_withl1BOM_hist = new TH1D("l2mtpass_withl1BOM_hist", "l2mtpass_withl1BOM_hist", 2, 0, 2);
    TH1D *l1BOM_withl2mtpass_hist = new TH1D("l1BOM_withl2mtpass_hist", "l1BOM_withl2mtpass_hist", 2, 0, 2);

    TFile hist_file("img0815/hist0815.root", "RECREATE");

    Long64_t nentries = chain->GetEntries();

    cout << nentries << endl;

    int n_l2mt2muons = 0;
    int n_l2mt1muons = 0;

    for(int jentry = 0; jentry < nentries; jentry++){
        chain->GetEntry(jentry);

        int trig_chain = 0;
        bool flag_trigger= false;
        float deltaR_thr = 0.08;
        bool matching_offline_HLT = false;
        bool flag_BOM= false;
        int BOM_roi = 0;

        for(int i = 0; i < trigger_info_chain->size(); i++){
            if(trigger_info_chain->at(i) == "HLT_mu24_ivarmedium_L1MU14FCH"){
                trig_chain = i;
                flag_trigger = true;
            }
        }

        if(flag_trigger == false) continue;

        for(int i_offline = 0; i_offline < muon_pt->size(); i_offline++){
            TVector3 offline_muon;
            offline_muon.SetPtEtaPhi(muon_pt->at(i_offline), muon_eta->at(i_offline), muon_phi->at(i_offline));

            for(int i_HLTmuon = 0; i_HLTmuon < trigger_info_ptVec->at(trig_chain).size(); i_HLTmuon++){
                TVector3 hlt_muon;
                hlt_muon.SetPtEtaPhi(trigger_info_ptVec->at(trig_chain).at(i_HLTmuon), trigger_info_etaVec->at(trig_chain).at(i_HLTmuon), trigger_info_phiVec->at(trig_chain).at(i_HLTmuon));
                
                float offline_HLT_DeltaR = offline_muon.DeltaR(hlt_muon);

                if(offline_HLT_DeltaR < deltaR_thr) matching_offline_HLT = true;
            }
        }

        if(matching_offline_HLT == false) continue;

        for(int i_roi = 0; i_roi < trig_L1_mu_eta->size(); i_roi++){
            if(trig_L1_mu_moreCandInRPCPad->at(i_roi) == 1 && trig_L1_mu_source->at(i_roi) == 0){
                flag_BOM = true;
                BOM_roi = i_roi;
            }
        }

        if(muon_pt->size() >= 2 && flag_BOM == true){
            HLTmuons_hist->Fill(l2mt_eta->size());
            if(l2mt_pass->at(0) == 1){
                HLTmuons_withl2mtpass_hist->Fill(l2mt_eta->size());
            }
            for(int i_roi_L2mt; i_roi_L2mt < l2mt_pt->size(); i_roi_L2mt++){
                if(l1_BOM->at(i_roi_L2mt) == 1){
                    l2mtpass_withl1BOM_hist->Fill(l2mt_pass->at(i_roi_L2mt));
                }
                if(l2mt_pass->at(i_roi_L2mt) == 1){
                    l1BOM_withl2mtpass_hist->Fill(l1_BOM->at(i_roi_L2mt));
                }
            }
        }


/*
        vector<bool> l2mtmuon_isPassed;
        vector<float> l2mtmuon_energy;
        vector<float> l2mtmuon_pt;
        vector<float> l2mt_muon_eta;
        vector<float> l2mtmuon_phi;
        vector<int> l1BOM_flag;

        bool flag_BOM = false;
        int n_l2mt2muons = 0;
        int n_l2mt1muons = 0;
        
        for(int i = 0; i < muon_pt->size(); i++){
                        
            l1BOM_flag = l1_BOM->at(i);
            l2mtmuon_isPassed = l2mt_pass->at(i);
            l2mtmuon_energy = l2mt_e->at(i);
            l2mtmuon_pt = l2mt_pt->at(i);
            l2mt_muon_eta = l2mt_eta->at(i);
            l2mtmuon_phi = l2mt_phi->at(i);

            //if(l1_dRoff->at(i) > 50) continue;
            if(l2mtmuon_isPassed.size() == 0) continue;

            if(l2mtmuon_isPassed.at(0) == true){
                //cout << "passed l2mt trigger!" << endl;
                if(l2mt_muon_eta.size() == 2){

                    n_l2mt2muons++;

                    TLorentzVector mu1;
                    mu1.SetPtEtaPhiE(l2mtmuon_pt.at(0), l2mt_muon_eta.at(0), l2mtmuon_phi.at(0), l2mtmuon_energy.at(0));
                    TLorentzVector mu2;
                    mu2.SetPtEtaPhiE(l2mtmuon_pt.at(1), l2mt_muon_eta.at(1), l2mtmuon_phi.at(1), l2mtmuon_energy.at(1));

                    TLorentzVector mu_pair = mu1 + mu2;
                    float pair_mass = mu_pair.M();
                    float pair_deltaR = mu2.DeltaR(mu1);
                    float pair_deltaPhi = mu2.DeltaPhi(mu1);

                    mass_hist->Fill(pair_mass);
                    //pt_hist->Fill(mu_pt->at(k));
                    deltaR_hist->Fill(pair_deltaR);
                    deltaPhi_hist->Fill(pair_deltaPhi);

                }
                else{
                    n_l2mt1muons++;
                }
            }
*/
/*
            for(int j = 0; j < l2mt_eta->at(i).size(); j++){
                //if(l1BOM_flag)
                cout << "l1BOM flag : " << l1BOM_flag.at(j) << endl;
                cout << "l2mt pass : " << l2mtmuon_isPassed.at(j) << endl;
                cout << "l2mt online muon eta : " << l2mt_eta->at(i).at(j) << endl;
            }
*/            

            //mu select
            //bool flag_mu1_author = mu_author->at(j) != 6;
            //bool flag_mu1_Type = mu_muonType->at(j) == 0;
            //bool flag_m1_pt = mu_pt->at(j) > 10000;
/*
            TLorentzVector mu1;
            mu1.SetPtEtaPhiE(muon_pt->at(i), muon_eta->at(i), muon_phi->at(i), muon_e->at(i));
            
            for(int k = 0; k < muon_pt->size(); k++){
                if (i == k) continue;
                //charge cut
                int charge = muon_charge->at(i) * muon_charge->at(k);
                bool flag_charge = charge == -1;
                
                if (flag_charge){
                    TLorentzVector mu2;
                    mu2.SetPtEtaPhiE(muon_pt->at(k), muon_eta->at(k), muon_phi->at(k), muon_e->at(k));

                    TLorentzVector mu_pair = mu1 + mu2;
                    float pair_mass = mu_pair.M();
                    float pair_deltaR = mu2.DeltaR(mu1);
                    float pair_deltaPhi = mu2.DeltaPhi(mu1);

                    mass_hist->Fill(pair_mass);
                    //pt_hist->Fill(mu_pt->at(k));
                    deltaR_hist->Fill(pair_deltaR);
                    deltaPhi_hist->Fill(pair_deltaPhi);

                    for(int l = 0; l < l1_BOM->at(i).size; l++){
                        flag_BOM = true;
                    }
                    
                }
            }
        }
*/
    }
/*
    TCanvas *c_mass = new TCanvas("c_mass");
    mass_hist->Draw();
    TCanvas *c_deltaR = new TCanvas("c_deltaR");
    deltaR_hist->Draw();
    TCanvas *c_deltaPhi = new TCanvas("c_deltaPhi");
    deltaPhi_hist->Draw();
*/

    //cout << n_l2mt1muons << endl;
    //cout << n_l2mt2muons << endl;

    hist_file.cd();

    HLTmuons_hist->Write();
    HLTmuons_withl2mtpass_hist->Write();
    l2mtpass_withl1BOM_hist->Write();
    l1BOM_withl2mtpass_hist->Write();
    
    hist_file.Close();
}